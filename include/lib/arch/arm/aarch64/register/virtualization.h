/****************************************************************************************************
 * AArch64 virtualization registers
 ****************************************************************************************************/
#ifndef VIRTUALIZATION__H__
#define VIRTUALIZATION__H__

/****************************************************************************************************
 * VPIDR_EL2:           RW, 32bit, Virtualization Processor ID Register
 ****************************************************************************************************/
#ifndef REG_VPIDR_EL2
#define REG_VPIDR_EL2
/* [31:0] VPIDR:            MIDR value returned by Non-secure PL1 reads of the MIDR. 
                            The MIDR description defines the subdivision of this value. */
#define VPIDR_SHIFT                         U(0)
#define VPIDR_MASK                          U(0xffffffff)
#endif  /* !REG_VPIDR_EL2 */

/****************************************************************************************************
 * VMPIDR_EL2:          RW, 64bit, Virtualization Multiprocessor ID Register
 ****************************************************************************************************/
#ifndef REG_VMPIDR_EL2
#define REG_VMPIDR_EL2
/* [63:0] VMPIDR:           MPIDR value returned by Non-secure EL1 reads of the MPIDR_EL1. 
                            The MPIDR description defines the subdivision of this value. */
#define VMPIDR_SHIFT                         U(0)
#define VMPIDR_MASK                          U(0xffffffffffffffff)
#endif  /* !REG_VMPIDR_EL2 */

/****************************************************************************************************
 * SCTLR_EL2:           RW, 32bit, System Control Register, EL2
 ****************************************************************************************************/
#ifndef REG_SCTLR_EL2
#define REG_SCTLR_EL2
/* [25] EE:                 Exception endianness. The possible values are:
                                0   Little endian.
                                1   Big endian.
                                The reset value depends on the value of the CFGEND configuration input. */
#define SCTLR_EL2_EE_SHIFT                  U(25)
#define SCTLR_EL2_EE_MASK                   U(0x1)
/* [19] WXN:                Force treatment of all memory regions with write permissions as XN. The possible values are:
                                0   Regions with write permissions are not forced XN. This is the reset value.
                                1   Regions with write permissions are forced XN. */
#define SCTLR_EL2_WXN_SHIFT                 U(19)
#define SCTLR_EL2_WXN_MASK                  U(0x1)
/* [12] I:                  Instruction cache enable. The possible values are:
                                0   Instruction caches disabled. This is the reset value.
                                1   Instruction caches enabled. */
#define SCTLR_EL2_I_SHIFT                   U(12)
#define SCTLR_EL2_I_MASK                    U(0x1)
/* [3] SA:                  Enables stack alignment check. The possible values are:
                                0   Disables stack alignment check.
                                1   Enables stack alignment check. This is the reset value. */
#define SCTLR_EL2_SA_SHIFT                  U(3)
#define SCTLR_EL2_SA_MASK                   U(0x1)
/* [2] C:                   Global enable for data and unifies caches. The possible values are:
                                0   Disables data and unified caches. This is the reset value.
                                1   Enables data and unified caches. */
#define SCTLR_EL2_C_SHIFT                   U(2)
#define SCTLR_EL2_C_MASK                    U(0x1)
/* [1] A:                   Enable alignment fault check The possible values are:
                                0   Disables alignment fault checking. This is the reset value.
                                1   Enables alignment fault checking. */
#define SCTLR_EL2_A_SHIFT                   U(1)
#define SCTLR_EL2_A_MASK                    U(0x1)
/* [0] M:                   Global enable for the EL2 MMU. The possible values are:
                                0   Disables EL2 MMU. This is the reset value.
                                1   Enables EL2 MMU. */
#define SCTLR_EL2_M_SHIFT                   U(0)
#define SCTLR_EL2_M_MASK                    U(0x1)
#endif  /* !REG_SCTLR_EL2 */

/****************************************************************************************************
 * ACTLR_EL2:           RW, 32bit, Auxiliary Control Register, EL2
 ****************************************************************************************************/
#ifndef REG_ACTLR_EL2
#define REG_ACTLR_EL2
/* [6] L2ACTLR_EL1 access control:  L2ACTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from Non-secure EL1.This is the reset value.
                                        1   The register is write accessible from Non-secure EL1.
                                            Write access from Non-secure EL1 also requires ACTLR_EL3[6] to be set. */
#define ACTLR_EL2_L2ACTLR_EL1_SHIFT         U(6)
#define ACTLR_EL2_L2ACTLR_EL1_MASK          U(0x1)
/* [5] L2ECTLR_EL1 access control:  L2ECTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from Non-secure EL1.This is the reset value.
                                        1   The register is write accessible from Non-secure EL1.
                                            Write access from Non-secure EL1 also requires ACTLR_EL3[5] to be set. */
#define ACTLR_EL2_L2ECTLR_EL1_SHIFT         U(5)
#define ACTLR_EL2_L2ECTLR_EL1_MASK          U(0x1)
/* [4] L2CTLR_EL1 access control:   L2CTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from Non-secure EL1.This is the reset value.
                                        1   The register is write accessible from Non-secure EL1.
                                            Write access from Non-secure EL1 also requires ACTLR_EL3[4] to be set. */
#define ACTLR_EL2_L2CTLR_EL1_SHIFT          U(4)
#define ACTLR_EL2_L2CTLR_EL1_MASK           U(0x1)
/* [1] CPUECTLR_EL1 access control: CPUECTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from Non-secure EL1.This is the reset value.
                                        1   The register is write accessible from Non-secure EL1.
                                            Write access from Non-secure EL1 also requires ACTLR_EL3[1] to be set. */
#define ACTLR_EL2_CPUECTLR_EL1_SHIFT        U(1)
#define ACTLR_EL2_CPUECTLR_EL1_MASK         U(0x1)
/* [0] CPUACTLR_EL1 access control: CPUACTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from Non-secure EL1.This is the reset value.
                                        1   The register is write accessible from Non-secure EL1.
                                            Write access from Non-secure EL1 also requires ACTLR_EL3[0] to be set. */
#define ACTLR_EL2_CPUACTLR_EL1_SHIFT        U(0)
#define ACTLR_EL2_CPUACTLR_EL1_MASK         U(0x1)
#endif  /* !REG_ACTLR_EL2 */

/****************************************************************************************************
 * HCR_EL2:             RW, 64bit, Hypervisor Configuration Register
 ****************************************************************************************************/
/* [33] ID:                 Disables stage 2 instruction cache. When HCR_EL2.VM is 1, 
                            this forces all stage 2 translations for instruction accesses to Normal memory to be Non-cacheable 
                            for the EL1/EL0 translation regimes. The possible values are:
                                0   Has no effect on stage 2 EL1/EL0 translation regime for instruction accesses. This is the reset value.
                                1   Forces all stage 2 translations for instruction accesses to Normal memory to be Non-cacheable for the EL1/EL0 translation regime. */
#define HCR_ID_SHIFT                        U(33)
#define HCR_ID_MASK                         U(0x1)
/* [32] CD:                 Disables stage 2 data cache. When HCR_EL2.VM is 1, this forces all stage 2 translations 
                            for data accesses and translation table walks to Normal memory to be Non-cacheable for the EL1/EL0 translation regimes. 
                            The possible values are:
                                0   Has no effect on stage 2 EL1/EL0 translation regime for data access or translation table walks. This is the reset value.
                                1   Forces all stage 2 translations for data accesses and translation table walks to Normal memory to be Non-cacheable for the EL1/EL0 translation regime. */
#define HCR_CD_SHIFT                        U(32)
#define HCR_CD_MASK                         U(0x1)
/* [31] RW:                 Register width control for lower exception levels. The possible values are:
                                0   Lower levels are all AArch32. This is the reset value.
                                1   EL1 is AArch64. EL0 is determined by the register width described in the current processing state when executing at EL0. */
#define HCR_RW_SHIFT                        U(31)
#define HCR_RW_MASK                         U(0x1)
/* [30] TRVM:               Trap reads of Virtual Memory controls.a The possible values are:
                                0   Non-secure EL1 reads are not trapped. This is the reset value.
                                1   Non-secure EL1 reads are trapped to EL2. */
#define HCR_TRVM_SHIFT                      U(30)
#define HCR_TRVM_MASK                       U(0x1)
/* [29] HCD:                Reserved, RES0. */
#define HCR_HCD_SHIFT                       U(29)
#define HCR_HCD_MASK                        U(0x1)
/* [28] TDZ:                Traps DC ZVA instruction. The possible values are:
                                0   DC ZVA instruction is not trapped. This is the reset value.
                                1   DC ZVA instruction is trapped to EL2 when executed in Non-secure EL1 or EL0. */
#define HCR_TDZ_SHIFT                       U(28)
#define HCR_TDZ_MASK                        U(0x1)
/* [27] TGE:                Traps general exceptions. If this bit is set, and SCR_EL3.NS is set, then:
                                • All Non-secure EL1 exceptions are routed to EL2.
                                • For Non-secure EL1, the SCTLR_EL1.M bit is treated as 0 regardless of its actual state other than the purpose of reading the bit.
                                • The HCR_EL2.FMO, HCR_EL2.IMO, and HCR_EL2.AMO bits are treated as 1 regardless of their actual state other than for the purpose of reading the bits.
                                • All virtual interrupts are disabled.
                                • Any implementation defined mechanisms for signaling virtual interrupts are disabled.
                                • An exception return to Non-secure EL1 is treated as an illegal exception return. */
#define HCR_TGE_SHIFT                       U(27)
#define HCR_TGE_MASK                        U(0x1)
/* [26] TVM:                Trap virtual memory controls.a The possible values are:
                                0   Non-secure EL1 writes are not trapped. This is the reset value.
                                1   Non-secure EL1 writes are trapped to EL2. */
#define HCR_TVM_SHIFT                       U(26)
#define HCR_TVM_MASK                        U(0x1)
/* [25] TTLB:               Traps TLB maintenance instructions.a The possible values are:
                                0   Non-secure EL1 TLB maintenance instructions are not trapped. This is the reset value.
                                1   TLB maintenance instructions executed from Non-secure EL1that are not UNDEFINED are trapped to EL2. */
#define HCR_TTLB_SHIFT                      U(25)
#define HCR_TTLB_MASK                       U(0x1)
/* [24] TPU:                Traps cache maintenance instructions to Point of Unification (POU).a The possible values are:
                                0   Cache maintenance instructions are not trapped. This is the reset value.
                                1   Cache maintenance instructions to the POU executed from Non-secure EL1 or EL0 that are not UNDEFINED are trapped to EL2. */
#define HCR_TPU_SHIFT                       U(24)
#define HCR_TPU_MASK                        U(0x1)
/* [23] TPC:                Traps data or unified cache maintenance instructions to Point of Coherency (POC).a The possible values are:
                                0   Data or unified cache maintenance instructions are not trapped. This is the reset value.
                                1   Data or unified cache maintenance instructions by address to the POC executed 
                                    from Non-secure EL1 or EL0 that are not UNDEFINED are trapped to EL2. */
#define HCR_TPC_SHIFT                       U(23)
#define HCR_TPC_MASK                        U(0x1)
/* [22] TSW:                Traps data or unified cache maintenance instructions by Set or Way.a The possible values are:
                                0   Data or unified cache maintenance instructions are not trapped. This is the reset value.
                                1   Data or unified cache maintenance instructions by Set or Way executed 
                                    from Non-secure EL1 that are not UNDEFINED are trapped to EL2.are not trapped. */
#define HCR_TSW_SHIFT                       U(22)
#define HCR_TSW_MASK                        U(0x1)
/* [21] TACR:               Traps Auxiliary Control registers. The possible values are:
                                0   Accesses to Auxiliary Control registers are not trapped. This is the reset value.
                                1   Accesses to ACTLR in AArch32 state or the ACTLR_EL1 in the AArch64 state 
                                    from Non-secure EL1 are trapped to EL2. */
#define HCR_TACR_SHIFT                      U(21)
#define HCR_TACR_MASK                       U(0x1)
/* [20] TIDCP:              Trap Implementation Dependent functionality.
                            When 1, this causes accesses to the following instruction set space executed from Non-secure EL1 to be trapped to EL2:
                                AArch32     All CP15 MCR and MRC instructions as follows:
                                            • CRn is 9, Opcode1 is 0 to 7, CRm is c0, c1, c2, c5, c6, c7, or c8, and Opcode2 is 0 to 7.
                                            • CRn is 10, Opcode1 is 0 to 7, CRm is c0, c1, c4, or c8, and Opcode2 is 0 to 7.
                                            • CRn is 11, Opcode1 is 0 to 7, CRm is c0 to c8, or c15, and Opcode2 is 0 to 7.
                                AArch64     Reserved control space for IMPLEMENTATION DEFINED functionality.
                                            Accesses from EL0 are UNDEFINED. The reset value is 0. */
#define HCR_TIDCP_SHIFT                     U(20)
#define HCR_TIDCP_MASK                      U(0x1)
/* [19] TSC:                Traps SMC instruction. The possible values are:
                                0   SMC instruction in not trapped. This is the reset value.
                                1   SMC instruction executed in Non-secure EL1 is trapped to EL2 for AArch32 and AArch64 Execution states. */
#define HCR_TSC_SHIFT                       U(19)
#define HCR_TSC_MASK                        U(0x1)
/* [18] TID3:               Traps ID group 3 registers.a The possible values are:
                                0   ID group 3 register accesses are not trapped. This is the reset value.
                                1   Reads to ID group 3 registers executed from Non-secure EL1 are trapped to EL2. */
#define HCR_TID3_SHIFT                      U(18)
#define HCR_TID3_MASK                       U(0x1)
/* [17] TID2:               Traps ID group 2 registers.a The possible values are:
                                0   ID group 2 register accesses are not trapped. This is the reset value.
                                1   Reads to ID group 2 registers and writes to CSSELR and CSSELR_EL1executed 
                                    from Non-secure EL1 or EL0, if not UNDEFINED, are trapped to EL2. */
#define HCR_TID2_SHIFT                      U(17)
#define HCR_TID2_MASK                       U(0x1)
/* [16] TID1:               Traps ID group 1 registers.a The possible values are:
                                0   ID group 1 register accesses are not trapped. This is the reset value.
                                1   Reads to ID group 1registers executed from Non-secure EL1 are trapped to EL2. */
#define HCR_TID1_SHIFT                      U(16)
#define HCR_TID1_MASK                       U(0x1)
/* [15] TID0:               Traps ID group 0 registers.a The possible values are:
                                0   ID group 0 register accesses are not trapped. This is the reset value.
                                1   Reads to ID group 0 registers executed from Non-secure EL1 are trapped to EL2. */
#define HCR_TID0_SHIFT                      U(15)
#define HCR_TID0_MASK                       U(0x1)
/* [14] TWE:                Traps WFE instruction if it would cause suspension of execution. For example, if there is no pending WFE event.
                                The possible values are:
                                0   WFE instruction is not trapped. This is the reset value.
                                1   WFE instruction executed in Non-secure EL1 or EL0 is trapped to EL2 
                                    for AArch32 and AArch64 Execution states. */
#define HCR_TWE_SHIFT                       U(14)
#define HCR_TWE_MASK                        U(0x1)
/* [13] TWI:                Traps WFI instruction if it causes suspension of execution. 
                            For example, if there is no pending WFI event. The possible values are:
                                0   WFI instruction is not trapped. This is the reset value.
                                1   WFI instruction executed in Non-secure EL1 or EL0 is trapped to EL2 
                                    for AArch32 and AArch64 Execution states. */
#define HCR_TWI_SHIFT                       U(13)
#define HCR_TWI_MASK                        U(0x1)
/* [12] DC:                 Default cacheable. When this bit is set it causes:
                                • SCTLR_EL1.M to behave as 0 for all purposes other than reading the bit.
                                • HCR_EL2.VM to behave as 1 for all purposes other than reading the bit.
                            The memory type produced by the first stage of translation in Non-secure EL1 and EL0 is Non-Shareable, 
                            Inner Write-Back Write-Allocate, Outer Write-Back Write-Allocate. The reset value is 0. */
#define HCR_DC_SHIFT                        U(12)
#define HCR_DC_MASK                         U(0x1)
/* [11:10] BSU:             Barrier shareability upgrade. Determines the minimum shareability domain that is supplied to any barrier executed from Non-secure EL1 or EL0. 
                            The possible values are:
                                0b00    No effect. This is the reset value.
                                0b01    Inner Shareable.
                                0b10    Outer Shareable.
                                0b11    Full system.
                                This value is combined with the specified level of the barrier held in its instruction, 
                                according to the algorithm for combining shareability attributes. */
#define HCR_BSU_SHIFT                       U(10)
#define HCR_BSU_MASK                        U(0x3)
/* [9] FB:                  Forces broadcast.b The possible values are:
                                0   Instructions are not broadcast. This is the reset value.
                                1   Forces instruction broadcast within Inner Shareable domain when executing from Non-secure EL1. */
#define HCR_FB_SHIFT                        U(9)
#define HCR_FB_MASK                         U(0x1)
/* [8] VSE:                 Virtual System Error/Asynchronous Abort. The possible values are:
                                0   Virtual System Error/Asynchronous Abort is not pending by this mechanism. This is the reset value.
                                1   Virtual System Error/Asynchronous Abort is pending by this mechanism.
                                The virtual System Error/Asynchronous Abort is enabled only when the HCR_EL2.AMO bit is set. */
#define HCR_VSE_SHIFT                       U(8)
#define HCR_VSE_MASK                        U(0x1)
/* [7] VI:                  Virtual IRQ interrupt. The possible values are:
                                0   Virtual IRQ is not pending by this mechanism. This is the reset value.
                                1   Virtual IRQ is pending by this mechanism.
                                The virtual IRQ is enabled only when the HCR_EL2.IMO bit is set. */
#define HCR_VI_SHIFT                        U(7)
#define HCR_VI_MASK                         U(0x1)
/* [6] VF:                  Virtual FIQ interrupt. The possible values are:
                                0   Virtual FIQ is not pending by this mechanism. This is the reset value.
                                1   Virtual FIQ is pending by this mechanism.
                                The virtual FIQ is enabled only when the HCR_EL2.FMO bit is set. */
#define HCR_VF_SHIFT                        U(6)
#define HCR_VF_MASK                         U(0x1)
/* [5] AMO:                 Asynchronous abort and error interrupt routing. The possible values are:
                                0   Asynchronous external Aborts and SError Interrupts while executing at exception levels lower than EL2 are not taken at EL2. 
                                    Virtual System Error/Asynchronous Abort is disabled. This is the reset value.
                                1   Asynchronous external Aborts and SError Interrupts while executing at EL2 or lower are taken in EL2 unless routed by SCTLR_EL3.EA bit to EL3. 
                                    Virtual System Error/Asynchronous Abort is enabled. */
#define HCR_AMO_SHIFT                       U(5)
#define HCR_AMO_MASK                        U(0x1)
/* [4] IMO:                 Physical IRQ routing. The possible values are:
                                0   Physical IRQ while executing at exception levels lower than EL2 are not taken at EL2. 
                                    Virtual IRQ interrupt is disabled. This is the reset value.
                                1   Physical IRQ while executing at EL2 or lower are taken in EL2 unless routed by SCTLR_EL3.IRQ bit to EL3. 
                                    Virtual IRQ interrupt is enabled. */
#define HCR_IMO_SHIFT                       U(4)
#define HCR_IMO_MASK                        U(0x1)
/* [3] FMO:                 Physical FIQ routing. The possible values are:
                                0   Physical FIQ while executing at exception levels lower than EL2 are not taken at EL2. 
                                    Virtual FIQ interrupt is disabled. This is the reset value.
                                1   Physical FIQ while executing at EL2 or lower are taken in EL2 unless routed by SCTLR_EL3.FIQ bit to EL3. 
                                    Virtual FIQ interrupt is enabled. */
#define HCR_FMO_SHIFT                       U(3)
#define HCR_FMO_MASK                        U(0x1)
/* [2] PTW:                 Protected Table Walk. 
                            When this bit is set, if the stage 2 translation of a translation table access, 
                            made as part of a stage 1 translation table walk at EL0 or EL1, maps to Device memory, 
                            the access is faulted as a stage 2 Permission fault. The reset value is 0. */
#define HCR_PTW_SHIFT                       U(2)
#define HCR_PTW_MASK                        U(0x1)
/* [1] SWIO:                Set/Way Invalidation Override.
                            Non-secure EL1 execution of the data cache invalidate by set/way instruction is treated as data cache clean and invalidate by set/way. 
                            When this bit is set:
                                • DCISW is treated as DCCISW when in the AArch32 Execution state.
                                • DC ISW is treated as DC CISW when in the AArch64 Execution state.
                            This bit is RES1. */
#define HCR_SWIO_SHIFT                      U(1)
#define HCR_SWIO_MASK                       U(0x1)
/* [0] VM:                  Enables second stage of translation. The possible values are:
                                0   Disables second stage translation. This is the reset value.
                                1   Enables second stage translation for execution in Non-secure EL1 and EL0. */
#define HCR_VM_SHIFT                        U(0)
#define HCR_VM_MASK                         U(0x1)

/****************************************************************************************************
 * MDCR_EL2:            RW, 32bit, Hyp Debug Control Register
 ****************************************************************************************************/
/* [11] TDRA:               Trap debug ROM address register access.
                                0   Has no effect on accesses to debug ROM address registers from EL1 and EL0.
                                1   Trap valid Non-secure EL1 and EL0 access to debug ROM address registers to Hyp mode.
                            When this bit is set to 1, any access to the following registers from EL1 or EL0 is trapped to EL2:
                                • AArch32: DBGDRAR, DBGDSAR.
                                • AArch64: MDRAR_EL1.
                            If HCR_EL2.TGE is 1 or MDCR_EL2.TDE is 1, then this bit is ignored and treated as though it is 1 other than for the value read back from MDCR_EL2.
                            On Warm reset, the field resets to 0. */
#define MDCR_TDRA_SHIFT                     U(11)
#define MDCR_TDRA_MASK                      U(0x1)
/* [10] TDOSA:              Trap Debug OS-related register access:
                                0   Has no effect on accesses to OS-related debug registers.
                                1   Trap valid Non-secure accesses to OS-related debug registers to EL2.
                            When this bit is set to 1, any access to the following registers from EL1 or EL0 is trapped to EL2:
                                • AArch32: DBGOSLAR, DBGOSLSR, DBGOSDLR, DBGPRCR.
                                • AArch64: OSLAR_EL1, OSLSR_EL1, OSDLR_EL1, DBGPRCR_EL1.
                            If HCR_EL2.TGE is 1 or MDCR_EL2.TDE is 1, then this bit is ignored and treated as though it is 1 other than for the value read back from MDCR_EL2.
                            On Warm reset, the field resets to 0. */
#define MDCR_TDOSA_SHIFT                    U(10)
#define MDCR_TDOSA_MASK                     U(0x1)
/* [9] TDA:                 Trap Debug Access:
                                0   Has no effect on accesses to Debug registers.
                                1   Trap valid Non-secure accesses to Debug registers to EL2.
                            When this bit is set to 1, any valid Non-secure access to the debug registers from EL1 or EL0, other than the registers trapped by the TDRA and TDOSA bits, is trapped to EL2.
                            If HCR_EL2.TGE is 1 or MDCR_EL2.TDE is1, then this bit is ignored and treated as though it is 1 other than for the value read back from MDCR_EL2.
                            On Warm reset, the field resets to 0. */
#define MDCR_TDA_SHIFT                      U(9)
#define MDCR_TDA_MASK                       U(0x1)
/* [8] TDE:                 Trap software debug exceptions:
                                0   Has no effect on software debug exceptions.
                                1   Route Software debug exceptions from Non-secure EL1 and EL0 to EL2. Also enables traps on all debug register accesses to EL2.
                            If HCR_EL2.TGE is 1, then this bit is ignored and treated as though it is 1 other than for the value read back from MDCR_EL2.This bit resets to 0. */
#define MDCR_TDE_SHIFT                      U(8)
#define MDCR_TDE_MASK                       U(0x1)
/* [7] HPME:                Hypervisor Performance Monitor Enable:
                                0   EL2 performance monitor counters disabled.
                                1   EL2 performance monitor counters enabled.
                            When this bit is set to 1, the Performance Monitors counters that are reserved for use from EL2 or Secure state are enabled. For more information see the description of the HPMN field.
                            The reset value of this bit is UNKNOWN. */
#define MDCR_HPME_SHIFT                     U(7)
#define MDCR_HPME_MASK                      U(0x1)
/* [6] TPM:                 Trap Performance Monitor accesses:
                                0   Has no effect on performance monitor accesses.
                                1   Trap Non-secure EL0 and EL1 accesses to Performance Monitors registers that are not
                            UNALLOCATED to EL2.
                            This bit resets to 0. */
#define MDCR_TPM_SHIFT                      U(6)
#define MDCR_TPM_MASK                       U(0x1)
/* [5] TPMCR:               Trap PMCR_EL0 accesses:
                                0   Has no effect on PMCR_EL0 accesses.
                                1   Trap Non-secure EL0 and EL1 accesses to PMCR_EL0 to EL2.
                            This bit resets to 0.
                            See the Arm® Architecture Reference Manual Armv8, for Armv8-A architecture profile for more information. */
#define MDCR_TPMCR_SHIFT                    U(5)
#define MDCR_TPMCR_MASK                     U(0x1)
/* [4:0] HPMN:              Hyp Performance Monitor count. Defines the number of Performance Monitors counters that are accessible from Non-secure EL1 and EL0 modes.
                            In Non-secure state, HPMN divides the Performance Monitors counters as follows. For counter n in Non-secure state:
                            For example, If PMnEVCNTR is performance monitor counter n then, in Non-secure state:
                                • If n is in the range 0 ≤ n < HPMN, the counter is accessible from EL1 and EL2, 
                                  and from EL0 if permitted by PMUSERENR_EL0. PMCR_EL0.E enables the operation of counters in this range.
                                • If n is in the range HPMN ≤ n < 6a, the counter is accessible only from EL2. 
                                  MDCR_EL2.HPME enables the operation of counters in this range.
                            If the field is set to 0, then Non-secure EL0 or EL1 has no access to any counters.
                            If the field is set to a value greater than six, the behavior is the same as if the value is six.
                            For reads of MDCR_EL2.HPMN by EL2 or higher, if this field is set to 0 or to a value larger than PMCR_EL0.N, 
                            the processor returns the value that was written to MDCR_EL2.HPMN.
                            This field resets to 0x6. */
#define MDCR_HPMN_SHIFT                     U(0)
#define MDCR_HPMN_MASK                      U(0x1f)

/****************************************************************************************************
 * CPTR_EL2:            RW, 32bit, Architectural Feature Trap Register, EL2
 ****************************************************************************************************/
/* [31] TCPAC:              Traps direct access to CPACR from Non-secure EL1 to EL2. The possible values are:
                                0   Access to CPACR is not trapped. This is the reset value.
                                1   Access to CPACR is trapped. */
#define CPTR_EL2_TCPAC_SHIFT                U(31)
#define CPTR_EL2_TCPAC_MASK                 U(0x1)
/* [20] TTA:                Trap Trace Access.
                                Not implemented. RES0. */
#define CPTR_EL2_TTA_SHIFT                  U(20)
#define CPTR_EL2_TTA_MASK                   U(0x1)
/* [10] TFP:                Traps instructions that access registers associated with 
                            Advanced SIMD and Floating-point execution from a lower exception level to EL2, unless trapped to EL1. 
                            The possible values are:
                                0   Instructions are not trapped. This is the reset value if Advanced SIMD and Floating-point are implemented.
                                1   Instructions are trapped. This is always the value if Advanced SIMD and Floating-point are not implemented. */
#define CPTR_EL2_TFP_SHIFT                   U(10)
#define CPTR_EL2_TFP_MASK                    U(0x1)

/****************************************************************************************************
 * HSTR_EL2:            RW, 32bit, Hyp System Trap Register
 ****************************************************************************************************/
/* [16] TTEE:           Trap T32EE. This value is:
                            0   T32EE is not supported. */
#define HSTR_TTEE_SHIFT                     U(16)
#define HSTR_TTEE_MASK                      U(0x1)
/* [15] T15:            Trap coprocessor primary register CRn = 15. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 15 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T15_SHIFT                      U(15)
#define HSTR_T15_MASK                       U(0x1)
/* [13] T13:            Trap coprocessor primary register CRn = 13. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 13 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T13_SHIFT                      U(13)
#define HSTR_T13_MASK                       U(0x1)
/* [12] T12:            Trap coprocessor primary register CRn = 12. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 12 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T12_SHIFT                      U(12):
#define HSTR_T12_MASK                       U(0x1)
/* [11] T11:            Trap coprocessor primary register CRn = 11. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 11 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T11_SHIFT                      U(11)
#define HSTR_T11_MASK                       U(0x1)
/* [10] T10:            Trap coprocessor primary register CRn = 10. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 10 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T10_SHIFT                      U(10)
#define HSTR_T10_MASK                       U(0x1)
/* [9] T9:              Trap coprocessor primary register CRn = 9. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 9 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T9_SHIFT                       U(9)
#define HSTR_T9_MASK                        U(0x1)
/* [8] T8:              Trap coprocessor primary register CRn = 8. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 8 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T8_SHIFT                       U(8)
#define HSTR_T8_MASK                        U(0x1)
/* [7] T7:              Trap coprocessor primary register CRn = 7. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 7 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T7_SHIFT                       U(7)
#define HSTR_T7_MASK                        U(0x1)
/* [6] T6:              Trap coprocessor primary register CRn = 6. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 6 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T6_SHIFT                       U(6)
#define HSTR_T6_MASK                        U(0x1)
/* [5] T5:              Trap coprocessor primary register CRn = 5. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 5 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T5_SHIFT                       U(5)
#define HSTR_T5_MASK                        U(0x1)
/* [3] T3:              Trap coprocessor primary register CRn = 3. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 3 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T3_SHIFT                       U(3)
#define HSTR_T3_MASK                        U(0x1)
/* [2] T2:              Trap coprocessor primary register CRn = 2. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 2 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T2_SHIFT                       U(2)
#define HSTR_T2_MASK                        U(0x1)
/* [1] T1:              Trap coprocessor primary register CRn = 1. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 1 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T1_SHIFT                       U(1)
#define HSTR_T1_MASK                        U(0x1)
/* [0] T0:              Trap coprocessor primary register CRn = 0. The possible values are:
                            0   Has no effect on Non-secure accesses to CP15 registers.
                            1   Trap valid Non-secure accesses to coprocessor primary register CRn = 0 to Hyp mode.
                            The reset value is 0. */
#define HSTR_T0_SHIFT                       U(0)
#define HSTR_T0_MASK                        U(0x1)

/****************************************************************************************************
 * HACR_EL2:            RW, 32bit, Hyp Auxiliary Configuration Register
 ****************************************************************************************************/
/* The processor does not implement HACR_EL2, so this register is always RES0. */

/****************************************************************************************************
 * TTBR0_EL2:           RW, 64bit, Translation Table Base Address Register 0, EL3
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * TCR_EL2:             RW, 32bit, Translation Control Register, EL2
 ****************************************************************************************************/
#ifndef REG_TCR_EL2
#define REG_TCR_EL2
/* [20] TBI:                Top Byte Ignored. Indicates whether the top byte of the input address is used for address match.
                            The possible values are:
                                0   Top byte used in the address calculation.
                                1   Top byte ignored in the address calculation. */
#define TCR_EL2_TBI_SHIFT               U(20)
#define TCR_EL2_TBI_MASK                U(0x1)
/* [18:16] PS:              Physical address size. The possible values are:
                                0b000   32 bits, 4 GB.
                                0b001   36 bits, 64 GB.
                                0b010   40 bits, 1 TB.
                                Other values are reserved. */
#define TCR_EL2_PS_SHIFT                U(16)
#define TCR_EL2_PS_MASK                 U(0x7)
/* [15:14] TG0:             TTBR0_EL2 granule size. The possible values are:
                                0b00    4 KB.
                                0b01    64 KB.
                                0b11    Reserved.
                                All other values are not supported. */
#define TCR_EL2_TG0_SHIFT               U(14)
#define TCR_EL2_TG0_MASK                U(0x3)
/* [13:12] SH0:             Shareability attribute for memory associated with translation table walks using TTBR0_EL2.
                                The possible values are:
                                0b00    Non-shareable.
                                0b01    Reserved.
                                0b10    Outer shareable.
                                0b11    Inner shareable. */
#define TCR_EL2_SH0_SHIFT               U(12)
#define TCR_EL2_SH0_MASK                U(0x3)
/* [11:10] ORGN0:           Outer cacheability attribute for memory associated with translation table walks using TTBR0_EL2. 
                            The possible values are:
                                0b00    Normal memory, Outer Non-cacheable.
                                0b01    Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Outer Write-Through Cacheable.
                                0b11    Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
#define TCR_EL2_ORGN0_SHIFT             U(8)
#define TCR_EL2_ORGN0_MASK              U(0x3)
/* [9:8] IRGN0:             Inner cacheability attribute for memory associated with translation table walks using TTBR0_EL2. 
                                The possible values are:
                                0b00    Normal memory, Inner Non-cacheable.
                                0b01    Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Inner Write-Through Cacheable.
                                0b11    Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
#define TCR_EL2_IRGN0_SHIFT             U(8)
#define TCR_EL2_IRGN0_MASK              U(0x3)
/* [5:0] T0SZ:              Size offset of the memory region addressed by TTBR0_EL2. 
                            The region size is 2^(64-T0SZ) bytes. */
#define TCR_EL2_T0SZ_SHIFT              U(0)
#define TCR_EL2_T0SZ_MASK               U(0x3f)
#endif  /* !REG_TCR_EL2 */

/****************************************************************************************************
 * VTTBR_EL2:           RW, 64bit, Virtualization Translation Table Base Address Register, EL2
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * VTCR_EL2:            RW, 32bit, Virtualization Translation Control Register, EL2
 ****************************************************************************************************/
#ifndef REG_VTCR_EL2
#define REG_VTCR_EL2
/* [18:16] PS:              Physical Address Size. The possible values are:
                                0b000   32 bits, 4 GB.
                                0b001   36 bits, 64 GB.
                                0b010   40 bits, 1 TB.
                                All other values are reserved. */
#define VTCR_EL2_PS_SHIF                U(16)
#define VTCR_EL2_PS_MASK                U(0x7)
/* [15:14] TG0:             Granule size for the corresponding VTTBR_EL2.
                                0b00    4 KB.
                                0b01    64 KB.
                                0b11    Reserved.
                                All other values are not supported. */
#define VTCR_EL2_TG0_SHIF               U(14)
#define VTCR_EL2_TG0_MASK               U(0x3)
/* [13:12] SH0:             Shareability attribute for memory associated with translation table walks using VTTBR_EL2.
                                0b00    Non-shareable.
                                0b01    Reserved.
                                0b10    Outer Shareable.
                                0b11    Inner Shareable. */
#define VTCR_EL2_SH0_SHIF               U(12)
#define VTCR_EL2_SH0_MASK               U(0x3)
/* [11:10] ORGN0:           Outer cacheability attribute for memory associated with translation table walks using VTTBR_EL2.
                                0b00    Normal memory, Outer Non-cacheable.
                                0b01    Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Outer Write-Through Cacheable.
                                0b11    Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
#define VTCR_EL2_ORGN0_SHIF             U(10)
#define VTCR_EL2_ORGN0_MASK             U(0x3)
/* [9:8] IRGN0:             Inner cacheability attribute for memory associated with translation table walks using VTTBR_EL2.
                                0b00    Normal memory, Inner Non-cacheable.
                                0b01    Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Inner Write-Through Cacheable.
                                0b11    Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
#define VTCR_EL2_IRGN0_SHIF             U(8)
#define VTCR_EL2_IRGN0_MASK             U(0x3)
/* [7:6] SL0:               Starting level of the VTCR_EL2 addressed region. */
#define VTCR_EL2_SL0_SHIF               U(6)
#define VTCR_EL2_SL0_MASK               U(0x3)
/* [5:0] T0SZ:              The size offset of the memory region addressed by VTTBR_EL2. The region size is 2^(64-T0SZ) bytes. */
#define VTCR_EL2_T0SZ_SHIF              U(0)
#define VTCR_EL2_T0SZ_MASK              U(0x3f)
#endif  /* !REG_VTCR_EL2 */

/****************************************************************************************************
 * DACR32_EL2:          RW, 32bit, Domain Access Control Register
 ****************************************************************************************************/
/* [31:30] D15:         Domain 15 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D15_SHIFT                U(30)
#define DACR32_EL2_D15_MASK                 U(0x3)
/* [29:28] D14:         Domain 14 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D14_SHIFT                U(28)
#define DACR32_EL2_D14_MASK                 U(0x3)
/* [27:26] D13:         Domain 13 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D13_SHIFT                U(26)
#define DACR32_EL2_D13_MASK                 U(0x3)
/* [25:24] D12:         Domain 12 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D12_SHIFT                U(24)
#define DACR32_EL2_D12_MASK                 U(0x3)
/* [23:22] D11:         Domain 11 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D11_SHIFT                U(22)
#define DACR32_EL2_D11_MASK                 U(0x3)
/* [21:20] D10:         Domain 10 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D10_SHIFT                U(20)
#define DACR32_EL2_D10_MASK                 U(0x3)
/* [19:18] D9:          Domain 9 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D9_SHIFT                 U(18)
#define DACR32_EL2_D9_MASK                  U(0x3)
/* [17:16] D8:          Domain 8 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D8_SHIFT                 U(16)
#define DACR32_EL2_D8_MASK                  U(0x3)
/* [15:14] D7:          Domain 7 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D7_SHIFT                 U(14)
#define DACR32_EL2_D7_MASK                  U(0x3)
/* [13:12] D6:          Domain 6 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D6_SHIFT                 U(12)
#define DACR32_EL2_D6_MASK                  U(0x3)
/* [11:10] D5:          Domain 5 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D5_SHIFT                 U(10)
#define DACR32_EL2_D5_MASK                  U(0x3)
/* [9:8] D4:            Domain 4 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D4_SHIFT                 U(8)
#define DACR32_EL2_D4_MASK                  U(0x3)
/* [7:6] D3:            Domain 3 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D3_SHIFT                 U(6)
#define DACR32_EL2_D3_MASK                  U(0x3)
/* [5:4] D2:            Domain 2 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D2_SHIFT                 U(4)
#define DACR32_EL2_D2_MASK                  U(0x3)
/* [3:2] D1:            Domain 1 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D1_SHIFT                 U(2)
#define DACR32_EL2_D1_MASK                  U(0x3)
/* [1:0] D0:            Domain 0 access permission. Permitted values are:
                            0b00    No access. Any access to the domain generates a Domain fault.
                            0b01    Client. Accesses are checked against the permission bits in the translation tables.
                            0b11    Manager. Accesses are not checked against the permission bits in the translation tables.
                            The value 0b10 is reserved. */
#define DACR32_EL2_D0_SHIFT                 U(0)
#define DACR32_EL2_D0_MASK                  U(0x3)


/****************************************************************************************************
 * AFSR0_EL2:           RW, 32bit, Auxiliary Fault Status Register 0, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR0_EL1, AFSR0_EL2 and AFSR0_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AFSR1_EL2:           RW, 32bit, Auxiliary Fault Status Register 1, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR1_EL1, AFSR1_EL2 and AFSR1_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * ESR_EL2:             RW, 32bit, Exception Syndrome Register, EL2
 ****************************************************************************************************/
#ifndef REG_ESR_EL2
#define REG_ESR_EL2
/* [31:26] EC:              Exception Class. 
                            Indicates the reason for the exception that this register holds information about. */
#define ESR_EL2_EC_SHIFT            U(26)
#define ESR_EL2_EC_MASK             U(0x1)
/* [25] IL                  Instruction Length for synchronous exceptions. The possible values are:
                                0   16-bit.
                                1   32-bit. */
#define ESR_EL2_IL_SHIFT            U(25)
#define ESR_EL2_IL_MASK             U(0x1)
/* [24:0] ISS:              Syndrome information. 
                                ISS[23:22]  ISS[1:0]    Description
                                0b00        0b00        DECERR on external access
                                0b00        0b01        Double-bit error detected on dirty line in L2 cache
                                0b00        0b10        SLVERR on external access
                                0b01        0b00        nSEI , or nVSEI in a guest OS, asserted
                                0b01        0b01        nREI asserted*/
#define ESR_EL2_ISS_SHIFT           U(0)
#define ESR_EL2_ISS_MASK            U(0x1ffffff)
#endif  /* !REG_ESR_EL2 */

/****************************************************************************************************
 * FAR_EL2:             RW, 64bit, Fault Address Register, EL2
 ****************************************************************************************************/
#ifndef REG_FAR_EL2
#define REG_FAR_EL2
/* [63:0] VA:               The faulting Virtual Address for all synchronous instruction or data aborts, 
                            or an exception from a misaligned PC, taken in EL2.
                            If a memory fault that sets the FAR is generated from one of the data cache instructions, 
                            this field holds the address specified in the register argument of the instruction. */
#define FAR_EL2_VA_SHIFT            U(0)
#define FAR_EL2_VA_MASK             U(0xffffffffffffffff)
#endif  /* !REG_FAR_EL2 */

/****************************************************************************************************
 * HPFAR_EL2:           RW, 64bit, Hypervisor IPA Fault Address Register, EL2
 ****************************************************************************************************/
#ifndef REG_HPFAR_EL2
#define REG_HPFAR_EL2
/* [39:4] FIPA[47:12]:      Bits [47:12] of the faulting intermediate physical address. 
                            The equivalent upper bits in this field are RES0. */
#define HPFAR_EL2_FIPA_SHIFT        U(4)
#define HPFAR_EL2_FIPA_MASK         U(0xfffffffff)
#endif  /* !REG_HPFAR_EL2 */

/****************************************************************************************************
 * MAIR_EL2:            RW, 64bit, Memory Attribute Indirection Register, EL2
 ****************************************************************************************************/
#ifndef REG_MAIR_EL2
#define REG_MAIR_EL2
/* [63:56] Attr7:           Attr<n> is the memory attribute encoding for an AttrIndx[2:0] entry in a Long descriptor format translation table entry, 
                            where AttrIndx[2:0] gives the value of <n> in Attr<n>. 
                            Attr<n>[7:4] bit assignments
                                Bits                Meaning
                                    0b0000              Device memory. See Table 4-114 for the type of Device memory.
                                    0b00RW, RW not 00   Normal Memory, Outer Write-through transient.a
                                    0b0100              Normal Memory, Outer Non-Cacheable.
                                    0b01RW, RW not 00   Normal Memory, Outer Write-back transient.a
                                    0b10RW              Normal Memory, Outer Write-through non-transient.
                                    0b11RW              Normal Memory, Outer Write-back non-transient.
                                a. The transient hint is ignored. 
                            Attr<n>[3:0] bit assignments 
                                Bits                Meaning when Attr<n>[7:4] is 0000   Meaning when Attr<n>[7:4] is not 0000
                                0b0000              Device-nGnRnE memory                UNPREDICTABLE
                                0b00RW, RW not 00   UNPREDICTABLE                       Normal Memory, Inner Write-through transient
                                0b0100              Device-nGnRE memory                 Normal memory, Inner Non-Cacheable
                                0b01RW, RW not 00   UNPREDICTABLE                       Normal Memory, Inner Write-back transient
                                0b1000              Device-nGRE memory                  Normal Memory, Inner Write-through non-transient (RW=00)
                                0b10RW, RW not 00   UNPREDICTABLE                       Normal Memory, Inner Write-through non-transient
                                0b1100              Device-GRE memory                   Normal Memory, Inner Write-back non-transient (RW=00)
                                0b11RW, RW not 00   UNPREDICTABLE                       Normal Memory, Inner Write-back non-transient 
                            Encoding of R and W bits in some Attrm fields 
                                R or W  Meaning
                                0       Do not allocate
                                1       Allocate */
#define MAIR_EL2_ATTR7_SHIFT        U(56)
#define MAIR_EL2_ATTR7_MASK         U(0xff)
/* [55:48] Attr6: */
#define MAIR_EL2_ATTR6_SHIFT        U(48)
#define MAIR_EL2_ATTR6_MASK         U(0xff)
/* [47:40] Attr5: */
#define MAIR_EL2_ATTR5_SHIFT        U(40)
#define MAIR_EL2_ATTR5_MASK         U(0xff)
/* [39:32] Attr4: */
#define MAIR_EL2_ATTR4_SHIFT        U(32)
#define MAIR_EL2_ATTR4_MASK         U(0xff)
/* [31:24] Attr3: */
#define MAIR_EL2_ATTR3_SHIFT        U(24)
#define MAIR_EL2_ATTR3_MASK         U(0xff)
/* [23:16] Attr2: */
#define MAIR_EL2_ATTR2_SHIFT        U(16)
#define MAIR_EL2_ATTR2_MASK         U(0xff)
/* [15:8] Attr1: */
#define MAIR_EL2_ATTR1_SHIFT        U(8)
#define MAIR_EL2_ATTR1_MASK         U(0xff)
/* [7:0] Attr0: */
#define MAIR_EL2_ATTR0_SHIFT        U(0)
#define MAIR_EL2_ATTR0_MASK         U(0xff)
#endif  /* !REG_MAIR_EL2 */

/****************************************************************************************************
 * AMAIR_EL2:           RW, 64bit, Auxiliary Memory Attribute Indirection Register, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AMAIR_EL2, therefore these registers are always RES0. */

/****************************************************************************************************
 * VBAR_EL2:            RW, 64bit, Vector Base Address Register, EL2
 ****************************************************************************************************/
#ifndef REG_VBAR_EL2
#define REG_VBAR_EL2
/* [63:11] Vector base address:     Base address of the exception vectors for exceptions taken in this exception level. */
#define VBAR_EL2_SHIFT              U(11)
#define VBAR_EL2_MASK               U(0xfffffffffffff)
#endif  /* !REG_VBAR_EL2 */

#endif  /* !VIRTUALIZATION__H__ */
