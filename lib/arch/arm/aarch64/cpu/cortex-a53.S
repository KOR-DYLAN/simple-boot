#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>

    .global cpu_reset_handler

/************************************************************** 
 * For CPU Reset
 **************************************************************/
/* Clobbers: x0 - x19, x30 */
func cpu_reset_handler
    /* backup 'lr' in 'x19' */
    mov x19, x30
    bl cortex_a53_enable_smp
    isb
    /* store 'lr' from 'x19' */
    mov x30, x19
    ret
endfunc cpu_reset_handler

/************************************************************** 
 * For SMP Enable/Disable 
 **************************************************************/
func cortex_a53_enable_smp
    sysreg_bit_set CPUECTLR_EL1, CPUECTLR_EL1_SMPEN_BIT
    ret
endfunc cortex_a53_enable_smp

func cortex_a53_disable_smp
    sysreg_bit_clear CPUECTLR_EL1, CPUECTLR_EL1_SMPEN_BIT
    isb
    dsb	sy
    ret
endfunc cortex_a53_disable_smp

/************************************************************** 
 * For DCACHE
 **************************************************************/
func cortex_a53_disable_dcache
    sysreg_bit_clear sctlr_el3, SCTLR_EL3_C_BIT
    isb
    ret
endfunc cortex_a53_disable_dcache

/************************************************************** 
 * For ERRATA
 **************************************************************/
/* TODO */
