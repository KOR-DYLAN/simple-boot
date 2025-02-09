#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>

    .global invalidate_data_cache_range

    /* ---------------------------------------------------------
     * Invalidate Data Cache by MVA from base address till size.
     * 'x0' = base-address, 'x1' = size
     * ---------------------------------------------------------
     */
func invalidate_data_cache_range
    /* Exit early if size is zero */
    cbz x1, exit_loop_ivac      /* if (x1 == 0) { goto exit_loop_ivac; } */

    /* Get Data Cache Line Size */
    mrs x3, ctr_el0             /* x3 = ctr_el0 */
    ubfx x3, x3, #16, #4        /* x3 = (x3 >> 16) & 0xf */
    mov x2, #4                  /* x2 = 4 */
    lsl x2, x2, x3              /* x2 = x2 << (x3 & 0x3f) */

    add x1, x0, x1              /* x1 = x0 + x1     == Address + Len */
    sub x3, x2, #1              /* x3 = x2 - 1      == 'Data Cache Line Size' - 1 */
    bic x0, x0, x3              /* x0 = x0 & ~(x3)  == Cache Aligned Address */

loop_ivac:
    dc ivac, x0                 /* Data Cache Invalidate by Address to PoC (Point of Coherency) */
    add x0, x0, x2              /* x0 = x0 + x2     == 'Current Address' + 'Data Cache Line Size' */
    cmp x0, x1                  /* if ('x0' < 'x1')  */
    b.lo loop_ivac              /*     goto loop_ivac; */
    dsb sy                      /* Data Synchronization Barrier(  Full System ) */

exit_loop_ivac:
    ret
endfunc invalidate_data_cache_range
