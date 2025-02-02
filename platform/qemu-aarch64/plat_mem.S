#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>
#include <platform.h>

    .global plat_mem_init

    /* Clobbers: x0 - x19, x30 */
func plat_mem_init
    /* backup 'lr' in 'x19' */
    mov x19, x30
    /* store 'lr' from 'x19' */
    mov x30, x19
    ret
endfunc plat_mem_init
