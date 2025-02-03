#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <platform_def.h>

    .global libc_stacks
    .section .libc_stacks, "aw", %nobits
    .align PLAT_STACK_ALIGN_COUNT
libc_stacks:
    .space (PLAT_STACK_SIZE * PLAT_NUM_CPUS), 0
