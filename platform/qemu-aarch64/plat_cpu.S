#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>
#include <platform.h>

    .global plat_get_core_pos
    .global plat_is_primary_core
    .global plat_reset_handler

func plat_get_core_pos
    mrs x0, mpidr_el1                                                           /* x0 = mpidr_el1 */
    and x1, x0, #MPIDR_EL1_CPU_MASK                                             /* x1 = x0 & MPIDR_EL1_CPU_MASK */
    and x0, x0, #MPIDR_EL1_CLUSTER_MASK                                         /* x0 = x0 & MPIDR_EL1_CLUSTER_MASK */
    add x0, x1, x0, LSR #(MPIDR_EL1_AFF1_SHIFT - PLAT_CPU_PER_CLUSTER_SHIFT)    /* x0 = x1 + (x0 >> (MPIDR_EL1_AFF1_SHIFT - PLAT_CPU_PER_CLUSTER_SHIFT)) */
    ret 
endfunc plat_get_core_pos

func plat_is_primary_core
    mrs x0, mpidr_el1
    and x0, x0, #(MPIDR_EL1_CLUSTER_MASK | MPIDR_EL1_CPU_MASK)
    cmp x0, #PLAT_PRIMARY_CORE_NUM
    cset w0, eq /* = (x0 == #PLAT_PRIMARY_CORE_NUM) ? 1 : 0 */
    ret
endfunc plat_is_primary_core

    /* Clobbers: x0 - x19, x30 */
func plat_reset_handler
    /* backup 'lr' in 'x19' */
    mov x19, x30
    /* store 'lr' from 'x19' */
    mov x30, x19
    ret
endfunc plat_reset_handler
