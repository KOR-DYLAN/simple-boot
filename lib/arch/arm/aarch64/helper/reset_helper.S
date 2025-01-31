#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>

    .global cpu_reset_handler

    /* The plat_reset_handler can clobber x0 - x19, x30 */
func cpu_reset_handler
    mov x18, x30

    /* TODO */

    mov x30, x18
    ret
endfunc cpu_reset_handler
