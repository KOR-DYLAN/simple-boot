#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>

    .global image_entrypoint

func image_entrypoint
    /* Feature Disable, System Control Register
     * SCTLR_EL3.EE:
     *  - Little endian. This is the reset value.
     * SCTLR_EL3.WXN:
     *  - Regions with write permissions are not forced XN.
     * SCTLR_EL3.SA:
     *  - Disables data and unified caches.
     * SCTLR_EL3.A:
     *  - Disables alignment fault checking. */
    mov_imm x0, (SCTLR_EL3_RESET_VAL & ~(SCTLR_EL3_EE_BIT | SCTLR_EL3_WXN_BIT | SCTLR_EL3_SA_BIT | SCTLR_EL3_A_BIT))
    msr sctlr_el3, x0
    isb

    /* check and branch boot method */
    bl plat_is_primary_core
    cbz x0, do_warm_boot    /* secondary cores */
    b do_cold_boot          /* primary core */
endfunc image_entrypoint

/* boot: secondary cores - Not Supported */
func do_warm_boot
    wfi
    b .
endfunc do_warm_boot

func do_cold_boot
    /* Set the exception vectors. */
    adr x0, runtime_exceptions
    msr vbar_el3, x0
    isb

    bl reset_hanlder
    bl setup_el3_execution_context
    bl init_mem

    b .
endfunc do_cold_boot

    /* Clobbers: x0 - x20, x30 */
func reset_hanlder
    /* backup 'lr' in 'x20' */
    mov x20, x30

    bl plat_reset_handler
    bl cpu_reset_handler

    /* store 'lr' from 'x20' */
    mov x30, x20
    ret
endfunc reset_hanlder

    /* Clobbers: x0 - x20, x30 */
func el3_arch_init_common
    /* backup 'lr' in 'x20' */
    mov x20, x30

    /* Feature Enable, System Control Register
     *SCTLR_EL3.I:
     *  - Instruction caches enabled.
     * SCTLR_EL3.A:
     *  - Enables alignment fault checking.
     * SCTLR_EL3.SA:
     *  - Enables stack alignment check. */
    mov x1, #(SCTLR_EL3_I_BIT | SCTLR_EL3_A_BIT | SCTLR_EL3_SA_BIT)
    mrs x0, sctlr_el3
    orr x0, x0, x1
    msr sctlr_el3, x0
    isb

    /* Set the following system registers to reset values:
     * - SCR_EL3 : Secure Configuration Register
     * - MDCR_EL3: Monitor Debug Configuration Register
     * - CPTR_EL3: Architectural Feature Trap Register
     */
    mov_imm x0, SCR_EL3_RESET_VAL
    msr scr_el3, x0
    mov_imm x0, MDCR_EL3_RESET_VAL
    msr mdcr_el3, x0
    mov_imm x0, CPTR_EL3_RESET_VAL
    msr cptr_el3, x0

    /* store 'lr' from 'x20' */
    mov x30, x20
    ret
endfunc el3_arch_init_common

    /* Clobbers: x0 - x20, x30 */
func setup_el3_execution_context
    /* backup 'lr' in 'x20' */
    mov x20, x30

    /* Enable External Aborts and SError Interrupts at EL3. */
    msr daifclr, #DAIF_A_BIT

    /* Feature Enable, Monitor Debug Configuration Register
     * MDCR_EL3.SDD:
     *  - Debug exceptions from all exception levels in Secure state are disabled. */
    mrs x0, mdcr_el3
    orr x0, x0, #MDCR_EL3_SDD_BIT
    msr mdcr_el3, x0

    /* Feature Enable, Monitor Debug Configuration Register
     * SCR_EL3.EA:
     *  - External Aborts and SError Interrupts while executing at all exception levels are taken in EL3.
     * SCR_EL3.SIF:
     *  - Secure state instruction fetches from Non-secure memory are not permitted. */
    mrs x0, scr_el3
    orr x0, x0, #SCR_EL3_EA_BIT
    orr x0, x0, #SCR_EL3_SIF_BIT
    msr scr_el3, x0

    isb

    /* store 'lr' from 'x20' */
    mov x30, x20
    ret
endfunc setup_el3_execution_context

    /* Clobbers: x0 - x20, x30 */
func init_mem
    /* backup 'lr' in 'x20' */
    mov x20, x30

    bl plat_mem_init
    bl init_c_runtime

    /* Use SP_EL0 for the C runtime stack. */
    msr spsel, #0
    bl alloc_stack
    mov sp, x0

    /* store 'lr' from 'x20' */
    mov x30, x20
    ret
endfunc init_mem

    /* Clobbers: x0 - x19, x30 */
func init_c_runtime
    /* backup 'lr' in 'x19' */
    mov x19, x30

    /* TODO */

    /* store 'lr' from 'x19' */
    mov x30, x19
    ret
endfunc init_c_runtime

func alloc_stack
    /* backup 'lr' in 'x19' */
    mov x19, x30

    /* TODO */

    /* store 'lr' from 'x19' */
    mov x30, x19
    ret
endfunc alloc_stack
