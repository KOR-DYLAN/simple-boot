#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>
#include <platform.h>

    .global plat_is_primary_core
    .global plat_reset_handler

func plat_is_primary_core
    mrs x0, mpidr_el1
    and x0, x0, #(MPIDR_EL1_CLUSTER_MASK | MPIDR_EL1_CPU_MASK)
    cmp x0, #PLAT_PRIMARY_CORE_NUM
    cset w0, eq /* = (x0 == #PLAT_PRIMARY_CORE_NUM) ? 1 : 0 */
    ret
endfunc plat_is_primary_core

func plat_reset_handler
    ret
endfunc plat_reset_handler
