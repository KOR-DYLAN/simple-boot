/****************************************************************************************************
 * AArch64 secure registers
 ****************************************************************************************************/
#ifndef SECURE__H__
#define SECURE__H__

/****************************************************************************************************
 * SCR_EL3:             RW, 32bit, Secure Configuration Register
 ****************************************************************************************************/
/* [13] TWE:                Traps WFE instructions. The possible values are:
                                0   WFE instructions are not trapped. This is the reset value.
                                1   WFE instructions executed in AArch32 or AArch64 from EL2, EL1 or EL0 are trapped to EL3 if
                                    the instruction would otherwise cause suspension of execution, that is if:
                                        • The event register is not set.
                                        • There is not a pending WFE wakeup event.
                                        • The instruction is not trapped at EL2 or EL1.
                                See the Arm® Architecture Reference Manual Armv8, for Armv8-A architecture profile for more information. */
#define SCR_TWE_SHIFT                       U(13)
#define SCR_TWE_MASK                        U(0x1)
/* [12] TWI:                Traps WFI instructions. The possible values are:
                                0   WFI instructions are not trapped. This is the reset value.
                                1   WFI instructions executed in AArch32 or AArch64 from EL2, EL1 or EL0 are trapped to EL3 if
                                    the instruction would otherwise cause suspension of execution, 
                                    that is if there is not a pending WFI wakeup event and the instruction is not trapped at EL2 or EL1.
                                See the Arm® Architecture Reference Manual Armv8, for Armv8-A architecture profile for more information. */
#define SCR_TWI_SHIFT                       U(12)
#define SCR_TWI_MASK                        U(0x1)
/* [11] ST:                 Enable Secure EL1 access to CNTPS_TVAL_EL1, CNTS_CTL_EL1, and CNTPS_CVAL_EL1 registers. 
                            The possible values are:
                                0   Registers accessible only in EL3. This is the reset value.
                                1   Registers accessible in EL3 and EL1 when SCR_EL3.NS is 0. */
#define SCR_ST_SHIFT                        U(11)
#define SCR_ST_MASK                         U(0x1)
/* [10] RW:                 Register width control for lower exception levels. The possible values are:
                                0   Lower levels are all AArch32. This is the reset value.
                                1   The next lower level is AArch64. */
#define SCR_RW_SHIFT                        U(10)
#define SCR_RW_MASK                         U(0x1)
/* [9] SIF:                 Secure Instruction Fetch. When the processor is in Secure state, 
                            this bit disables instruction fetches from Non-secure memory. The possible values are:
                                0   Secure state instruction fetches from Non-secure memory are permitted. This is the reset value.
                                1   Secure state instruction fetches from Non-secure memory are not permitted. */
#define SCR_SIF_SHIFT                       U(9)
#define SCR_SIF_MASK                        U(0x1)
/* [8] HCE:                 Hyp Call enable. This bit enables the use of HVC instructions. The possible values are:
                                0   The HVC instruction is UNDEFINED at all exception levels. This is the reset value.
                                1   The HVC instruction is enabled at EL1, EL2 or EL3. */
#define SCR_HCE_SHIFT                       U(8)
#define SCR_HCE_MASK                        U(0x1)
/* [7] SMD:                 SMC instruction disable. The possible values are:
                                0   The SMC instruction is enabled at EL1, EL2, and EL3. This is the reset value.
                                1   The SMC instruction is UNDEFINED at all exception levels. At EL1, in the Non-secure state, 
                                    the HCR_EL2.TSC bit has priority over this control. */
#define SCR_SMD_SHIFT                       U(7)
#define SCR_SMD_MASK                        U(0x1)
/* [3] EA:                  External Abort and SError interrupt Routing. This bit controls which mode takes external aborts. 
                            The possible values are:
                                0   External Aborts and SError Interrupts while executing at exception levels other than EL3 are not taken in EL3. This is the reset value.
                                1   External Aborts and SError Interrupts while executing at all exception levels are taken in EL3. */
#define SCR_EA_SHIFT                        U(3)
#define SCR_EA_MASK                         U(0x1)
/* [2] FIQ:                 Physical FIQ Routing. The possible values ares:
                                0   Physical FIQ while executing at exception levels other than EL3 are not taken in EL3. This is the reset value.
                                1   Physical FIQ while executing at all exception levels are taken in EL3. */
#define SCR_FIQ_SHIFT                       U(2)
#define SCR_FIQ_MASK                        U(0x1)
/* [1] IRQ:                 Physical IRQ Routing. The possible values are:
                                0   Physical IRQ while executing at exception levels other than EL3 are not taken in EL3.
                                1   Physical IRQ while executing at all exception levels are taken in EL3. */
#define SCR_IRQ_SHIFT                       U(1)
#define SCR_IRQ_MASK                        U(0x1)
/* [0] NS:                  Non-secure bit. The possible values are. The possible values are:
                                0   EL0 and EL1 are in Secure state, memory accesses from those exception levels can access Secure memory. This is the reset value.
                                1   EL0 and EL1 are in Non-secure state, memory accesses from those exception levels cannot access Secure memory. */
#define SCR_NS_SHIFT                        U(0)
#define SCR_NS_MASK                         U(0x1)

/****************************************************************************************************
 * SDER32_EL3:          RW, 32bit, Secure Debug Enable Register
 ****************************************************************************************************/
/* [1] SUNIDEN:             Secure User Non-invasive Debug Enable The possible values are:
                                0   Non-invasive debug not permitted in Secure EL0 mode. This is the Warm reset value.
                                1   Non-invasive debug permitted in Secure EL0 mode. */
#define SDER32_SUNIDEN_SHIFT                U(1)
#define SDER32_SUNIDEN_MASK                 U(0x1)
/* [0] SUIDEN:              Secure User Invasive Debug Enable. The possible values are:
                                0   Invasive debug not permitted in Secure EL0 mode. This is the Warm reset value.
                                1   Invasive debug permitted in Secure EL0 mode. */
#define SDER32_SUIDEN_SHIFT                 U(0)
#define SDER32_SUIDEN_MASK                  U(0x1)

/****************************************************************************************************
 * CPTR_EL3:            RW, 32bit, Architectural Feature Trap Register, EL3
 ****************************************************************************************************/
/* [31] TCPAC:              This causes a direct access to the CPACR_EL1 from EL1 or the CPTR_EL2 from EL2 to trap to EL3 unless it is trapped at EL2. 
                            The possible values are:
                                0   Does not cause access to the CPACR_EL1 or CPTR_EL2 to be trapped.
                                1   Causes access to the CPACR_EL1 or CPTR_EL2 to be trapped. */
#define CPTR_EL3_TCPAC_SHIFT                U(31)
#define CPTR_EL3_TCPAC_MASK                 U(0x1)
/* [20] TTA:                Trap Trace Access.
                                Not implemented. RES0. */
#define CPTR_EL3_TTA_SHIFT                  U(20)
#define CPTR_EL3_TTA_MASK                   U(0x1)
/* [10] TFP:                This causes instructions that access the registers associated with 
                            Advanced SIMD or floating-point execution to trap to EL3 when executed from any exception level, unless trapped to EL1 or EL2. 
                            The possible values are:
                                0   Does not cause any instruction to be trapped. 
                                    This is the reset value if the Advanced SIMD and Floating-point Extension is implemented.
                                1   Causes any instructions that use the registers associated with Advanced SIMD or floating-point execution to be trapped. 
                                    This is always the value if the Advanced SIMD and Floating-point Extension is not implemented. */
#define CPTR_EL3_TFP_SHIFT                  U(10)
#define CPTR_EL3_TFP_MASK                   U(0x1)

/****************************************************************************************************
 * MDCR_EL3:            RW, 32bit, Monitor Debug Configuration Register, EL3
 ****************************************************************************************************/
/* [21] EPMAD:              External debugger access to Performance Monitors registers disabled. 
                            This disables access to these registers by an external debugger. The possible values are:
                                0   Access to Performance Monitors registers from external debugger is permitted.
                                1   Access to Performance Monitors registers from external debugger is disabled, unless overridden by authentication interface. */
#define MDCR_EL3_EPMAD_SHIFT                U(21)
#define MDCR_EL3_EPMAD_MASK                 U(0x1)
/* [20] EDAD:               External debugger access to breakpoint and watchpoint registers disabled. 
                            This disables access to these registers by an external debugger. The possible values are:
                                0   Access to breakpoint and watchpoint registers from external debugger is permitted.
                                1   Access to breakpoint and watchpoint registers from external debugger is disabled, unless overridden by authentication interface. */
#define MDCR_EL3_EDAD_SHIFT                 U(20)
#define MDCR_EL3_EDAD_MASK                  U(0x1)
/* [17] SPME:               Secure performance monitors enable. This enables event counting exceptions from Secure state.
                            The possible values are:
                                0   Event counting prohibited in Secure state. This is the reset value.
                                1   Event counting allowed in Secure state. */
#define MDCR_EL3_SPME_SHIFT                 U(17)
#define MDCR_EL3_SPME_MASK                  U(0x1)
/* [16] SDD:                AArch64 secure debug disable. Disables Software debug exceptions from Secure state 
                            if Secure EL1 is using AArch64, other than from Software breakpoint instructions. 
                            The possible values are:
                                0   Debug exceptions from Secure EL0 are enabled, and debug exceptions from Secure EL1 are enabled if MDSCR_EL1.KDE is 1 and PSTATE.D is 0.
                                1   Debug exceptions from all exception levels in Secure state are disabled.
                            The reset value is UNKNOWN. */
#define MDCR_EL3_SDD_SHIFT                  U(16)
#define MDCR_EL3_SDD_MASK                   U(0x1)
/* [15:14] SPD32:           AArch32 secure privileged debug. Enables or disables debug exceptions from Secure state if Secure EL1 is using AArch32, 
                            other than Software breakpoint instructions. The possible values are:
                                0b00    Legacy mode. Debug exceptions from Secure EL1 are enabled only if AArch32SelfHostedSecurePrivilegedInvasiveDebugEnabled().
                                0b01    Reserved.
                                0b10    Secure privileged debug disabled. Debug exceptions from Secure EL1 are disabled.
                                0b11    Secure privileged debug enabled. Debug exceptions from Secure EL1 are enabled.
                                The reset value is UNKNOWN. */
#define MDCR_EL3_SPD32_SHIFT                U(14)
#define MDCR_EL3_SPD32_MASK                 U(0x3)
/* [10] TDOSA:              Trap accesses to the OS debug system registers, OSLAR_EL1, OSLSR_EL1, OSDLR_EL1, and DBGPRCR_EL1 OS.
                                0   Accesses are not trapped.
                                1   Accesses to the OS debug system registers are trapped to EL3.
                                The reset value is UNKNOWN. */
#define MDCR_EL3_TDOSA_SHIFT                U(10)
#define MDCR_EL3_TDOSA_MASK                 U0x1()
/* [9] TDA:                 Trap accesses to the remaining sets of debug registers to EL3.
                                0   Accesses are not trapped.
                                1   Accesses to the remaining debug system registers are trapped to EL3.
                                The reset value is UNKNOWN. */
#define MDCR_EL3_TDA_SHIFT                  U(9)
#define MDCR_EL3_TDA_MASK                   U(0x1)
/* [6] TPM:                 Trap Performance Monitors accesses. The possible values are:
                                0   Accesses are not trapped.
                                1   Accesses to the Performance Monitor registers are trapped to EL3.
                                The reset value is UNKNOWN. */
#define MDCR_EL3_TPM_SHIFT                  U(6)
#define MDCR_EL3_TPM_MASK                   U(0x1)

/****************************************************************************************************
 * AFSR0_EL3:           RW, 32bit, Auxiliary Fault Status Register 0, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR0_EL1, AFSR0_EL2 and AFSR0_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AFSR1_EL3:           RW, 32bit, Auxiliary Fault Status Register 1, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR1_EL1, AFSR1_EL2 and AFSR1_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * VBAR_EL3:            RW, 64bit, Vector Base Address Register, EL3
 ****************************************************************************************************/
#ifndef REG_VBAR_EL3
#define REG_VBAR_EL3
/* [63:11] Vector base address:     Base address of the exception vectors for exceptions taken in this exception level. */
#define VBAR_EL3_SHIFT              U(11)
#define VBAR_EL3_MASK               U(0xfffffffffffff)
#endif  /* !REG_VBAR_EL3 */

#endif  /* !SECURE__H__ */
