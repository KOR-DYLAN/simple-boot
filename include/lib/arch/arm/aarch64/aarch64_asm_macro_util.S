#ifndef AARCH64_ASM_MACRO_UTIL__S__
#define AARCH64_ASM_MACRO_UTIL__S__

/****************************************************************************** 
 * For Vector Table
 ******************************************************************************/
    /*
     * Declare the exception vector table, enforcing it is aligned on a 2KB boundary, as required by the ARMv8 architecture.
     * Use zero bytes as the fill value to be stored in the padding bytes so that it inserts illegal AArch64 instructions. 
     * This increases security, robustness and potentially facilitates debugging.
     */
    .macro vector_base  label, section_name=.vectors
    .section \section_name, "ax"
    .align 11, 0
    \label:
    .endm

    /*
     * Create an entry in the exception vector table, enforcing it is aligned on a 128-byte boundary, as required by the ARMv8 architecture.
     * Use zero bytes as the fill value to be stored in the padding bytes so that it inserts illegal AArch64 instructions. 
     * This increases security, robustness and potentially facilitates debugging.
     */
    .macro vector_entry  label, section_name=.vectors
    .cfi_sections .debug_frame
    .section \section_name, "ax"
    .align 7, 0
    .type \label, %function
    .cfi_startproc
    \label:
    .endm

    /*
     * Add the bytes until fill the full exception vector, whose size is always 32 instructions. 
     * If there are more than 32 instructions in the exception vector then an error is emitted.
     */
    .macro end_vector_entry label
    .cfi_endproc
    .fill    \label + (32 * 4) - .
    .endm

/****************************************************************************** 
 * For Register Read/Write
 ******************************************************************************/
    /*
     * Helper macro to generate the best mov/movk combinations according the value to be moved. 
     * The 16 bits from '_shift' are tested and if not zero, they are moved into '_reg' without affecting other bits.
     */
    .macro _mov_imm16 _reg, _val, _shift
        .if (\_val >> \_shift) & 0xffff
            .if (\_val & (1 << \_shift - 1))
                movk \_reg, (\_val >> \_shift) & 0xffff, LSL \_shift
            .else
                mov \_reg, \_val & (0xffff << \_shift)
            .endif
        .endif
    .endm

    /*
     * Helper macro to load arbitrary values into 32 or 64-bit registers which generates the best mov/movk combinations. 
     * Many base addresses are 64KB aligned the macro will eliminate updating bits 15:0 in that case
     */
    .macro mov_imm _reg, _val
        .if (\_val) == 0
            mov    \_reg, #0
        .else
            _mov_imm16    \_reg, (\_val), 0
            _mov_imm16    \_reg, (\_val), 16
            _mov_imm16    \_reg, (\_val), 32
            _mov_imm16    \_reg, (\_val), 48
        .endif
    .endm

    /*
     * Helper macro to read system register value into x0
     */
    .macro read reg:req
#if ENABLE_BTI
    bti j
#endif
    mrs x0, \reg
    ret
    .endm

    /*
     * Helper macro to write value from x1 to system register
     */
    .macro write reg:req
#if ENABLE_BTI
    bti j
#endif
    msr \reg, x1
    ret
    .endm

/****************************************************************************** 
 * For System Register Set/Clear
 ******************************************************************************/
    /*
    * Set a bit in a system register. Can set multiple bits but is limited by the
    *  way the ORR instruction encodes them.
    *
    * _reg:
    *    Register to write to
    *
    * _bit:
    *    Bit to set. Please use a descriptive #define
    *
    * _assert:
    *    Optionally whether to read back and assert that the bit has been
    *    written. Please disable with NO_ASSERT macro
    *
    * clobbers: x1
    */
    .macro sysreg_bit_set _reg:req, _bit:req, _assert=1
        mrs x1, \_reg
        orr x1, x1, #\_bit
        msr \_reg, x1
    .endm

    /*
    * Clear a bit in a system register. Can clear multiple bits but is limited by
    *  the way the BIC instrucion encodes them.
    *
    * see sysreg_bit_set for usage
    */
    .macro sysreg_bit_clear _reg:req, _bit:req
        mrs x1, \_reg
        bic x1, x1, #\_bit
        msr \_reg, x1
    .endm

/****************************************************************************** 
 * For System Register Definition
 ******************************************************************************/
    .macro rw_sysreg_func_def _sysreg_name
        .global read_\_sysreg_name
        .global write_\_sysreg_name
    func read_\_sysreg_name
        mrs x0, \_sysreg_name
    endfunc read_\_sysreg_name

    func write_\_sysreg_name
        msr \_sysreg_name, x0
    endfunc write_\_sysreg_name
    .endm

    .macro ro_sysreg_func_def _sysreg_name
        .global read_\_sysreg_name
        .global write_\_sysreg_name
    func read_\_sysreg_name
        mrs x0, \_sysreg_name
    endfunc read_\_sysreg_name
    .endm
    
    .macro wo_sysreg_func_def _sysreg_name
        .global read_\_sysreg_name
        .global write_\_sysreg_name
    func write_\_sysreg_name
        msr \_sysreg_name, x0
    endfunc write_\_sysreg_name
    .endm

#endif  /* !AARCH64_ASM_MACRO_UTIL__S__ */
