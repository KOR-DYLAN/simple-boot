#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>

    .global image_entrypoint

func image_entrypoint
    mov x0, #0
    mov x1, #1
    mov x2, #2
    mov x3, #3
    mov x4, #4
    mov x5, #5
    mov x6, #6
    b .
endfunc image_entrypoint
