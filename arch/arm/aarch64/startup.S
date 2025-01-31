#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>

    .global image_entrypoint

func image_entrypoint
    /* SCTLR_EL3.EE:
     *  - Little endian. This is the reset value.
     * SCTLR_EL3.WXN:
     *  - egions with write permissions are not forced XN.
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

/* boot: secondary cores - Not Supported */
do_warm_boot:
    wfi
    b do_warm_boot

/* boot: primary core */
do_cold_boot:
    /* Set the exception vectors. */
    adr x0, runtime_exceptions
    msr vbar_el3, x0
    isb

    b .
endfunc image_entrypoint
