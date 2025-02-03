#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <platform_def.h>

    .global libc_init
    .global libc_get_stack

    /* Clobbers: x0 - x19, x30 */
func libc_init
    /* backup 'lr' in 'x19' */
    mov x19, x30

    /* TODO */

    /* store 'lr' from 'x19' */
    mov x30, x19
    ret
endfunc libc_init

    /* Clobbers: x0 - x19, x30 */
func libc_get_stack
    /* backup 'lr' in 'x19' */
    mov x19, x30

    adrp x2, (libc_stacks + PLAT_STACK_SIZE)
    add x2, x2, :lo12:(libc_stacks + PLAT_STACK_SIZE)
    mov x1, #PLAT_STACK_SIZE
    madd x0, x0, x1, x2

    /* store 'lr' from 'x19' */
    mov x30, x19
    ret
endfunc libc_get_stack
