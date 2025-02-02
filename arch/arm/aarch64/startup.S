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

    /* do 'reset' handler */
    bl plat_reset_handler
    bl cpu_reset_handler

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

    b .
endfunc do_cold_boot
