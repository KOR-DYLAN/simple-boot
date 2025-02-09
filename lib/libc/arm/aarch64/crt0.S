#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <platform_def.h>

    .global libc_init
    .global libc_get_stack

    /* Clobbers: x0 - x19, x30 */
func libc_init
    /* backup 'lr' in 'x19' */
    mov x19, x30

    /* ---------------------------------------------------------------------
     * Invalidate the RW memory.
     * This includes the data and NOBITS sections.
     * This is done to safeguard against possible corruption of this memory 
     * by dirty cache lines in a system cache as a result of use 
     * by  an earlier boot loader stage. 
     * ---------------------------------------------------------------------
     */
    adrp x0, __RW_START__                           /* x0 = __RW_START__ & 0xfffffffffffff000 */
    add x0, x0, :lo12:__RW_START__                  /* x0 = x0 + (__RW_START__ & 0xfff) */
    adrp x1, __RW_END__                             /* x1 = __RW_END__ & 0xfffffffffffff000 */
    add x1, x1, :lo12:__RW_END__                    /* x1 = x1 + (__RW_END__ & 0xfff) */
    sub x1, x1, x0                                  /* x1 = x1 - x0 */
    bl invalidate_data_cache_range                  /* invalidate_data_cache_range(x0: addr, x1: len) */

    adrp x0, __BSS_START__                          /* x0 = __BSS_START__ & 0xfffffffffffff000 */
    add x0, x0, :lo12:__BSS_START__                 /* x0 = x0 + (__BSS_START__ & 0xfff ) */
    adrp x1, __BSS_END__                            /* x1 = __BSS_END__ & 0xfffffffffffff000 */
    add x1, x1, :lo12:__BSS_END__                   /* x1 = x1 + (__BSS_END__ & 0xfff ) */
    sub x1, x1, x0                                  /* x1 = x1 - x0 */
    bl zeromem                                      /* zeromem(x0: addr, x1: len) */

    /* store 'lr' from 'x19' */
    mov x30, x19
    ret
endfunc libc_init

    /* Clobbers: x0 - x19, x30 */
func libc_get_stack
    /* backup 'lr' in 'x19' */
    mov x19, x30

    bl plat_get_core_pos                                /* x0 = core pos */
    adrp x2, (libc_stacks + PLAT_STACK_SIZE)            /* x2 = (libc_stacks + PLAT_STACK_SIZE) & 0xfffffffffffff000 */
    add x2, x2, :lo12:(libc_stacks + PLAT_STACK_SIZE)   /* x2 = x2 + ((libc_stacks + PLAT_STACK_SIZE) & 0xfff) */
    mov x1, #PLAT_STACK_SIZE                            /* x1 = PLAT_STACK_SIZE */
    madd x0, x0, x1, x2                                 /* x0 = (x0 * x1) + x2 */

    /* store 'lr' from 'x19' */
    mov x30, x19
    ret
endfunc libc_get_stack
