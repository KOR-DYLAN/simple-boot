#ifndef ASM_MACRO_UTILS__S__
#define ASM_MACRO_UTILS__S__

    /*
     * This macro is used to create a function label and place the code into a separate text section 
     * based on the function name to enable elimination of unused code during linking.
     * It also adds basic debug information to enable call stack printing most of the time. 
     * The optional _align parameter can be used to force a non-standard alignment (indicated in powers of 2). 
     * The default is _align=2 because both Aarch32 and Aarch64 instructions must be word aligned. 
     * Do *not* try to use a raw .align directive. 
     * Since func switches to a new section, this would not have the desired effect.
     */
    .macro func _name, _align=2
    /*
     * Add Call Frame Information entry in the .debug_frame section for debugger consumption. 
     * This enables callstack printing in debuggers.
     * This does not use any space in the final loaded binary, only in the ELF file.
     * Note that a function manipulating the CFA pointer location (i.e. the x29 frame pointer on AArch64) 
     * should declare it using the appropriate .cfi* directives, or be prepared to have a degraded debugging experience.
     */
    .cfi_sections .debug_frame
    .section .text.asm.\_name, "ax"
    .type \_name, %function
    /*
     * .cfi_startproc and .cfi_endproc are needed to output entries in
     * .debug_frame
     */
    .cfi_startproc
    .align \_align
    \_name:
#if ENABLE_BTI
    /* When Branch Target Identification is enabled, insert "bti jc"
     * instruction to enable indirect calls and branches
     */
     bti    jc
#endif
    .endm

    /*
     * This macro is used to mark the end of a function.
     */
    .macro endfunc _name
    .cfi_endproc
    .size \_name, . - \_name
    .endm

#endif  /* !ASM_MACRO_UTILS__S__ */
