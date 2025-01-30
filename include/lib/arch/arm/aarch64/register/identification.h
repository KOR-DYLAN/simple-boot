/****************************************************************************************************
 * AArch64 Identification registers
 ****************************************************************************************************/
#ifndef IDENTIFICATION__H__
#define IDENTIFICATION__H__

/****************************************************************************************************
 * MIDR_EL1:            RO, 32bit, Main ID Register
 ****************************************************************************************************/
/* [31:24] Implementer:     Indicates the implementer code. */
#define MIDR_IMPLEMENTER_SHIFT              U(24)
#define MIDR_IMPLEMENTER_MASK               U(0xff)
/* [23:20] Variant:         Indicates the variant number of the processor. 
                            This is the major revision number x in the rx part of the rxpy description of the product revision status. */
#define MIDR_VARIANT_SHIFT                  U(20)
#define MIDR_VARIANT_MASK                   U(0xf)
/* [19:16] Architecture:    Indicates the architecture code. */
#define MIDR_ARCHITECTURE_SHIFT             U(16)
#define MIDR_ARCHITECTURE_MASK              U(0xf)
/* [15:4] PartNum:          Indicates the primary part number. */
#define MIDR_PARTNUM_SHIFT                  U(4)
#define MIDR_PARTNUM_MASK                   U(0xfff)
/* [3:0] Revision:          Indicates the minor revision number of the processor. 
                            This is the minor revision number y in the py part of the rxpy description of the product revision status. */
#define MIDR_REVISION_SHIFT                 U(3)
#define MIDR_REVISION_MASK                  U(0xf)

/****************************************************************************************************
 * MPIDR_EL1:           RO, 64bit, Multiprocessor Affinity Register
 ****************************************************************************************************/
/* [39:32] Aff3:            Affinity level 3. Highest level affinity field. */
#define MPIDR_AFF3_SHIFT                    U(32)
#define MPIDR_AFF3_MASK                     U(0xff)
/* [30] U:                  Indicates a single core system, as distinct from core 0 in a cluster. */
#define MPIDR_U_SHIFT                       U(30)
#define MPIDR_U_MASK                        U(0x1)
/* [24] MT:                 Indicates whether the lowest level of affinity consists of logical cores that are implemented using a multi-threading type approach. */
#define MPIDR_MT_SHIFT                      U(24)
#define MPIDR_MT_MASK                       U(0x1)
/* [23:16] Aff2:            Affinity level 2. Second highest level affinity field.
                            Indicates the value read in the CLUSTERIDAFF2 configuration signal. */
#define MPIDR_AFF2_SHIFT                    U(16)
#define MPIDR_AFF2_MASK                     U(0xff)
/* [15:8] Aff1:             Affinity level 1. Third highest level affinity field.
                            Indicates the value read in the CLUSTERIDAFF1 configuration signal. */
#define MPIDR_AFF1_SHIFT                    U(8)
#define MPIDR_AFF1_MASK                     U(0xff)
/* [7:0] Aff0:              Affinity level 0. Lowest level affinity field.
                            Indicates the core number in the Cortex-A53 processor. 
                            The possible values are:
                                0x0                 A cluster with one core only.
                                0x0, 0x1            A cluster with two cores.
                                0x0, 0x1, 0x2       A cluster with three cores.
                                0x0, 0x1, 0x2, 0x3  A cluster with four cores. */
#define MPIDR_AFF0_SHIFT                    U(0)
#define MPIDR_AFF0_MASK                     U(0xff)

/****************************************************************************************************
 * REVIDR_EL1:          RO, 32bit, Revision ID Register
 ****************************************************************************************************/
/* [31:0] ID number:        Implementation-specific revision information. */
#define REVIDR_SHIFT                        U(0)
#define REVIDR_MASK                         U(0xffffffff)

/****************************************************************************************************
 * ID_PFR0_EL1:         RO, 32bit, AArch32 Processor Feature Register 0
 ****************************************************************************************************/
/* [15:12] State3:          Indicates support for Thumb Execution Environment (T32EE) instruction set. */
#define ID_PFR0_STATE3_SHIFT                U(12)
#define ID_PFR0_STATE3_MASK                 U(0xf)
/* [11:8] State2:           Indicates support for Jazelle. */
#define ID_PFR0_STATE2_SHIFT                U(8)
#define ID_PFR0_STATE2_MASK                 U(0xf)
/* [7:4] State1:            Indicates support for T32 instruction set. */
#define ID_PFR0_STATE1_SHIFT                U(4)
#define ID_PFR0_STATE1_MASK                 U(0xf)
/* [3:0] State0:            Indicates support for A32 instruction set. */
#define ID_PFR0_STATE0_SHIFT                U(0)
#define ID_PFR0_STATE0_MASK                 U(0xf)

/****************************************************************************************************
 * ID_PFR1_EL1:         RO, 32bit, AArch32 Processor Feature Register 1
 ****************************************************************************************************/
/* [31:28] GIC CPU:         GIC CPU support:
                                0x0     GIC CPU interface is disabled, GICCDISABLE is HIGH.
                                0x1     GIC CPU interface is enabled. */
#define ID_PFR1_GIC_CPU_SHIFT               U(28)
#define ID_PFR1_GIC_CPU_MASK                U(0xf)
/* [19:16] GenTimer:        Generic Timer support: */
#define ID_PFR1_GENTIMER_SHIFT              U(16)
#define ID_PFR1_GENTIMER_MASK               U(0xf)
/* [15:12] Virtualization:  Virtualization support: */
#define ID_PFR1_VIRTUALIZATION_SHIFT        U(12)
#define ID_PFR1_VIRTUALIZATION_MASK         U(0xf)
/* [11:8] MProgMod:         M profile programmers' model support: */
#define ID_PFR1_MPROGMOD_SHIFT              U(8)
#define ID_PFR1_MPROGMOD_MASK               U(0xf)
/* [7:4] Security:          Security support: */
#define ID_PFR1_SECURITY_SHIFT              U(4)
#define ID_PFR1_SECURITY_MASK               U(0xf)
/* [3:0] ProgMod:           Indicates support for the standard programmers model for Armv4 and later.
                            Model must support User, FIQ, IRQ, Supervisor, Abort, Undefined, and System modes: */
#define ID_PFR1_PROGMOD_SHIFT               U(0)
#define ID_PFR1_PROGMOD_MASK                U(0xf)

/****************************************************************************************************
 * ID_DFR0_EL1:         RO, 32bit, AArch32 Debug Feature Register 0
 ****************************************************************************************************/
/* [27:24] PerfMon:         Indicates support for performance monitor model: */
#define ID_DFR0_PERFMON_SHFIT               U(24)
#define ID_DFR0_PERFMON_MASK                U(0xf)
/* [23:20] MProfDbg:        Indicates support for memory-mapped debug model for M profile processors: */
#define ID_DFR0_MPROFDBG_SHFIT              U(20)
#define ID_DFR0_MPROFDBG_MASK               U(0xf)
/* [19:16] MMapTrc:         Indicates support for memory-mapped trace model: */
#define ID_DFR0_MMAPTRC_SHFIT               U(16)
#define ID_DFR0_MMAPTRC_MASK                U(0xf)
/* [15:12] CopTrc:          Indicates support for coprocessor-based trace model: */
#define ID_DFR0_COPTRC_SHFIT                U(12)
#define ID_DFR0_COPTRC_MASK                 U(0xf)
/* [7:4] CopSDbg:           Indicates support for coprocessor-based Secure debug model: */
#define ID_DFR0_COPSDBG_SHFIT               U(4)
#define ID_DFR0_COPSDBG_MASK                U(0xf)
/* [3:0] CopDbg:            Indicates support for coprocessor-based debug model: */
#define ID_DFR0_COPDBG_SHFIT                U(0)
#define ID_DFR0_COPDBG_MASK                 U(0xf)

/****************************************************************************************************
 * ID_AFR0_EL1:         RO, 32bit, AArch32 Auxiliary Feature Register
 ****************************************************************************************************/
/* This register is always RES0. */

/****************************************************************************************************
 * ID_MMFR0_EL1:        RO, 32bit, AArch32 Memory Model Feature Register 0
 ****************************************************************************************************/
/* [31:28] InnerShr:         Indicates the innermost shareability domain implemented: */
#define ID_MMFR0_INNERSHR_SHIFT             U(28)
#define ID_MMFR0_INNERSHR_MASK              U(0xf)
/* [27:24] FCSE:            Indicates support for Fast Context Switch Extension (FCSE): */
#define ID_MMFR0_FCSE_SHIFT                 U(24)
#define ID_MMFR0_FCSE_MASK                  U(0xf)
/* [23:20] AuxReg:          Indicates support for Auxiliary registers: */
#define ID_MMFR0_AUXREG_SHIFT               U(20)
#define ID_MMFR0_AUXREG_MASK                U()
/* [19:16] TCM:             Indicates support for TCMs and associated DMAs: */
#define ID_MMFR0_TCM_SHIFT                  U(16)
#define ID_MMFR0_TCM_MASK                   U(0xf)
/* [15:12] ShareLvl:        Indicates the number of shareability levels implemented: */
#define ID_MMFR0_SHARELVL_SHIFT             U(12)
#define ID_MMFR0_SHARELVL_MASK              U(0xf)
/* [11:8] OuterShr:         Indicates the outermost shareability domain implemented: */
#define ID_MMFR0_OUTERSHR_SHIFT             U(8)
#define ID_MMFR0_OUTERSHR_MASK              U(0xf)
/* [7:4] PMSA:              Indicates support for a Protected Memory System Architecture (PMSA): */
#define ID_MMFR0_PMSA_SHIFT                 U(4)
#define ID_MMFR0_PMSA_MASK                  U(0xf)
/* [3:0] VMSA:              Indicates support for a Virtual Memory System Architecture (VMSA). */
#define ID_MMFR0_VMSA_SHIFT                 U(0)
#define ID_MMFR0_VMSA_MASK                  U(0xf)

/****************************************************************************************************
 * ID_MMFR1_EL1:        RO, 32bit, AArch32 Memory Model Feature Register 1
 ****************************************************************************************************/
/* [31:28] BPred:           Indicates branch predictor management requirements: */
#define ID_MMFR1_BPRED_SHIFT                U(28)
#define ID_MMFR1_BPRED_MASK                 U(0xf)
/* [27:24] L1TstCln:        Indicates the supported L1 Data cache test and clean operations, for Harvard or unified cache implementation: */
#define ID_MMFR1_L1TSTCLN_SHIFT             U(24)
#define ID_MMFR1_L1TSTCLN_MASK              U(0xf)
/* [23:20] L1Uni:           Indicates the supported entire L1 cache maintenance operations, for a unified cache implementation: */
#define ID_MMFR1_L1UNI_SHIFT                U(20)
#define ID_MMFR1_L1UNI_MASK                 U(0xf)
/* [19:16] L1Hvd:           Indicates the supported entire L1 cache maintenance operations, for a Harvard cache implementation: */
#define ID_MMFR1_L1HVD_SHIFT                U(16)
#define ID_MMFR1_L1HVD_MASK                 U(0xf)
/* [15:12] L1UniSW:         Indicates the supported L1 cache line maintenance operations by set/way, for a unified cache implementation: */
#define ID_MMFR1_L1UNISW_SHIFT              U(12)
#define ID_MMFR1_L1UNISW_MASK               U(0xf)
/* [11:8] L1HvdSW:          Indicates the supported L1 cache line maintenance operations by set/way, for a Harvard cache implementation: */
#define ID_MMFR1_L1HVDSW_SHIFT              U(8)
#define ID_MMFR1_L1HVDSW_MASK               U(0xf)
/* [7:4] L1UniVA:           Indicates the supported L1 cache line maintenance operations by MVA, for a unified cache implementation: */
#define ID_MMFR1_L1UNIVA_SHIFT              U(4)
#define ID_MMFR1_L1UNIVA_MASK               U(0xf)
/* [3:0] L1HvdVA:           Indicates the supported L1 cache line maintenance operations by MVA, for a Harvard cache implementation: */
#define ID_MMFR1_L1HVDVA_SHIFT              U(0)
#define ID_MMFR1_L1HVDVA_MASK               U(0xf)

/****************************************************************************************************
 * ID_MMFR2_EL1:        RO, 32bit, AArch32 Memory Model Feature Register 2
 ****************************************************************************************************/
/* [31:28] HWAccFlg:    Hardware access flag. Indicates support for a hardware access flag, as part of the VMSAv7 implementation: */
#define ID_MMFR2_HWACCFLG_SHIFT             U(28)
#define ID_MMFR2_HWACCFLG_MASK              U(0xf)
/* [27:24] WFIStall:    Wait For Interrupt Stall. Indicates the support for Wait For Interrupt (WFI) stalling: */
#define ID_MMFR2_WFISTALL_SHIFT             U(24)
#define ID_MMFR2_WFISTALL_MASK              U(0xf)
/* [23:20] MemBarr:     Memory Barrier. Indicates the supported CP15 memory barrier operations. */
#define ID_MMFR2_MEMBARR_SHIFT              U(20)
#define ID_MMFR2_MEMBARR_MASK               U(0xf)
/* [19:16] UniTLB:      Unified TLB. Indicates the supported TLB maintenance operations, for a unified TLB implementation */
#define ID_MMFR2_UNITLB_SHIFT               U(16)
#define ID_MMFR2_UNITLB_MASK                U(0xf)
/* [15:12] HvdTLB:      Harvard TLB. Indicates the supported TLB maintenance operations, for a Harvard TLB implementation: */
#define ID_MMFR2_HVDTLB_SHIFT               U(12)
#define ID_MMFR2_HVDTLB_MASK                U(0xf)
/* [11:8] LL1HvdRng:    L1 Harvard cache Range. Indicates the supported L1 cache maintenance range operations, for a Harvard cache implementation: */
#define ID_MMFR2_LL1HVDRNG_SHIFT            U(8)
#define ID_MMFR2_LL1HVDRNG_MASK             U(0xf)
/* [7:4] L1HvdBG:       L1 Harvard cache Background fetch. Indicates the supported L1 cache background prefetch operations, for a Harvard cache implementation: */
#define ID_MMFR2_L1HVDBG_SHIFT              U(4)
#define ID_MMFR2_L1HVDBG_MASK               U(0xf)
/* [3:0] L1HvdFG:       L1 Harvard cache Foreground fetch. Indicates the supported L1 cache foreground prefetch operations, for a Harvard cache implementation: */
#define ID_MMFR2_L1HVDFG_SHIFT              U(0)
#define ID_MMFR2_L1HVDFG_MASK               U(0xf)

/****************************************************************************************************
 * ID_MMFR3_EL1:        RO, 32bit, AArch32 Memory Model Feature Register 3
 ****************************************************************************************************/
/* [31:28] Supersec:    Supersections. Indicates support for supersections: */
#define ID_MMFR3_SUPERSEC_SHIFT             U(28)
#define ID_MMFR3_SUPERSEC_MASK              U(0xf)
/* [27:24] CMemSz:      Cached memory size. Indicates the size of physical memory supported by the processor caches: */
#define ID_MMFR3_CMEMSZ_SHIFT               U(24)
#define ID_MMFR3_CMEMSZ_MASK                U(0xf)
/* [23:20] CohWalk:     Coherent walk. Indicates whether translation table updates require a clean to the point of unification: */
#define ID_MMFR3_COHWALK_SHIFT              U(20)
#define ID_MMFR3_COHWALK_MASK               U(0xf)
/* [15:12] MaintBcst:   Maintenance broadcast. Indicates whether cache, TLB and branch predictor operations are broadcast: */
#define ID_MMFR3_MAINTBCST_SHIFT            U(12)
#define ID_MMFR3_MAINTBCST_MASK             U(0xf)
/* [11:8] BPMaint:      Branch predictor maintenance. Indicates the supported branch predictor maintenance operations. */
#define ID_MMFR3_BPMAINT_SHIFT              U(8)
#define ID_MMFR3_BPMAINT_MASK               U(0xf)
/* [7:4] CMaintSW:      Cache maintenance by set/way. Indicates the supported cache maintenance operations by set/way. */
#define ID_MMFR3_CMAINTSW_SHIFT             U(4)
#define ID_MMFR3_CMAINTSW_MASK              U(0xf)
/* [3:0] CMaintVA:      Cache maintenance by MVA. Indicates the supported cache maintenance operations by MVA. */
#define ID_MMFR3_CMAINTVA_SHIFT             U(0)
#define ID_MMFR3_CMAINTVA_MASK              U(0xf)

/****************************************************************************************************
 * ID_ISAR0_EL1:        RO, 32bit, AArch32 Instruction Set Attribute Register 0
 ****************************************************************************************************/
/* [27:24] Divide:      Indicates the implemented Divide instructions: */
#define ID_ISAR0_DIVIDE_SHIFT               U(24)
#define ID_ISAR0_DIVIDE_MASK                U(0xf)
/* [23:20] Debug:       Indicates the implemented Debug instructions: */
#define ID_ISAR0_DEBUG_SHIFT                U(20)
#define ID_ISAR0_DEBUG_MASK                 U(0xf)
/* [19:16] Coproc Indicates the implemented Coprocessor instructions: */
#define ID_ISAR0_COPROC_SHIFT               U(16)
#define ID_ISAR0_COPROC_MASK                U(0xf)
/* [15:12] CmpBranch:   Indicates the implemented combined Compare and Branch instructions in the T32 instruction set: */
#define ID_ISAR0_CMPBRANCH_SHIFT            U(12)
#define ID_ISAR0_CMPBRANCH_MASK             U(0xf)
/* [11:8] Bitfield:     Indicates the implemented bit field instructions: */
#define ID_ISAR0_BITFIELD_SHIFT             U(8)
#define ID_ISAR0_BITFIELD_MASK              U(0xf)
/* [7:4] BitCount:      Indicates the implemented Bit Counting instructions: */
#define ID_ISAR0_BITCOUNT_SHIFT             U(4)
#define ID_ISAR0_BITCOUNT_MASK              U(0xf)
/* [3:0] Swap:          Indicates the implemented Swap instructions in the A32 instruction set: */
#define ID_ISAR0_SWAP_SHIFT                 U(0)
#define ID_ISAR0_SWAP_MASK                  U(0xf)

/****************************************************************************************************
 * ID_ISAR1_EL1:        RO, 32bit, AArch32 Instruction Set Attribute Register 1
 ****************************************************************************************************/
/* [31:28] Jazelle:     Indicates the implemented Jazelle state instructions: */
#define ID_ISAR1_JAZELLE_SHIFT              U(28)
#define ID_ISAR1_JAZELLE_MASK               U(0xf)
/* [27:24] Interwork:   Indicates the implemented Interworking instructions: */
#define ID_ISAR1_INTERWORK_SHIFT            U(24)
#define ID_ISAR1_INTERWORK_MASK             U(0xf)
/* [23:20] Immediate:   Indicates the implemented data-processing instructions with long immediates: */
#define ID_ISAR1_IMMEDIATE_SHIFT            U(20)
#define ID_ISAR1_IMMEDIATE_MASK             U(0xf)
/* [19:16] IfThen:      Indicates the implemented If-Then instructions in the T32 instruction set: */
#define ID_ISAR1_IFTHEN_SHIFT               U(16)
#define ID_ISAR1_IFTHEN_MASK                U(0xf)
/* [15:12] Extend:      Indicates the implemented Extend instructions: */
#define ID_ISAR1_EXTEND_SHIFT               U(12)
#define ID_ISAR1_EXTEND_MASK                U(0xf)
/* [11:8] Except_AR:    Indicates the implemented A profile exception-handling instructions: */
#define ID_ISAR1_EXCEPT_AR_SHIFT            U(8)
#define ID_ISAR1_EXCEPT_AR_MASK             U(0xf)
/* [7:4] Except:        Indicates the implemented exception-handling instructions in the A32 instruction set: */
#define ID_ISAR1_EXCEPT_SHIFT               U(4)
#define ID_ISAR1_EXCEPT_MASK                U(0xf)
/* [3:0] Endian:        Indicates the implemented Endian instructions: */
#define ID_ISAR1_ENDIAN_SHIFT               U(0)
#define ID_ISAR1_ENDIAN_MASK                U(0xf)

/****************************************************************************************************
 * ID_ISAR2_EL1:        RO, 32bit, AArch32 Instruction Set Attribute Register 2
 ****************************************************************************************************/
/* [31:28] Reversal:        Indicates the implemented Reversal instructions: */
#define ID_ISAR2_REVERSAL_SHIFT             U(28)
#define ID_ISAR2_REVERSAL_MASK              U(0xf)
/* [27:24] PSR_AR:          Indicates the implemented A and R profile instructions to manipulate the PSR: */
#define ID_ISAR2_PSR_AR_SHIFT               U(24)
#define ID_ISAR2_PSR_AR_MASK                U(0xf)
/* [23:20] MultU:           Indicates the implemented advanced unsigned Multiply instructions: */
#define ID_ISAR2_MULTU_SHIFT                U(20)
#define ID_ISAR2_MULTU_MASK                 U(0xf)
/* [19:16] MultS:           Indicates the implemented advanced signed Multiply instructions. */
#define ID_ISAR2_MULTS_SHIFT                U(16)
#define ID_ISAR2_MULTS_MASK                 U(0xf)
/* [15:12] Mult:            Indicates the implemented additional Multiply instructions: */
#define ID_ISAR2_MULT_SHIFT                 U(12)
#define ID_ISAR2_MULT_MASK                  U(0xf)
/* [11:8] MultiAccessInt:   Indicates the support for interruptible multi-access instructions: */
#define ID_ISAR2_MULTIACCESSINT_SHIFT       U(8)
#define ID_ISAR2_MULTIACCESSINT_MASK        U(0xf)
/* [7:4] MemHint:           Indicates the implemented memory hint instructions: */
#define ID_ISAR2_MEMHINT_SHIFT              U(4)
#define ID_ISAR2_MEMHINT_MASK               U(0xf)
/* [3:0] LoadStore:         Indicates the implemented additional load/store instructions: */
#define ID_ISAR2_LOADSTORE_SHIFT            U(0)
#define ID_ISAR2_LOADSTORE_MASK             U(0xf)

/****************************************************************************************************
 * ID_ISAR3_EL1:        RO, 32bit, AArch32 Instruction Set Attribute Register 3
 ****************************************************************************************************/
/* [31:28] ThumbEE:     Indicates the implemented Thumb Execution Environment (T32EE) instructions: */
#define ID_ISAR3_THUMBEE_SHIFT              U(28)
#define ID_ISAR3_THUMBEE_MASK               U(0xf)
/* [27:24] TrueNOP:     Indicates support for True NOP instructions: */
#define ID_ISAR3_TRUENOP_SHIFT              U(24)
#define ID_ISAR3_TRUENOP_MASK               U(0xf)
/* [23:20] ThumbCopy:   Indicates the support for T32 non flag-setting MOV instructions: */
#define ID_ISAR3_THUMBCOPY_SHIFT            U(20)
#define ID_ISAR3_THUMBCOPY_MASK             U(0xf)
/* [19:16] TabBranch:   Indicates the implemented Table Branch instructions in the T32 instruction set. */
#define ID_ISAR3_TABBRANCH_SHIFT            U(16)
#define ID_ISAR3_TABBRANCH_MASK             U(0xf)
/* [15:12] SynchPrim:   Indicates the implemented Synchronization Primitive instructions: */
#define ID_ISAR3_SYNCHPRIM_SHIFT            U(12)
#define ID_ISAR3_SYNCHPRIM_MASK             U(0xf)
/* [11:8] SVC:          Indicates the implemented SVC instructions: */
#define ID_ISAR3_SVC_SHIFT                  U(8)
#define ID_ISAR3_SVC_MASK                   U(0xf)
/* [7:4] SIMD:          Indicates the implemented Single Instruction Multiple Data (SIMD) instructions. */
#define ID_ISAR3_SIMD_SHIFT                 U(4)
#define ID_ISAR3_SIMD_MASK                  U(0xf)
/*[3:0] Saturate:       Indicates the implemented Saturate instructions:  */
#define ID_ISAR3_SATURATE_SHIFT             U(0)
#define ID_ISAR3_SATURATE_MASK              U(0xf)

/****************************************************************************************************
 * ID_ISAR4_EL1:        RO, 32bit, AArch32 Instruction Set Attribute Register 4
 ****************************************************************************************************/
/* [31:28] SWP_frac:        Indicates support for the memory system locking the bus for SWP or SWPB instructions: */
#define ID_ISAR4_SWP_FRAC_SHIFT             U(28)
#define ID_ISAR4_SWP_FRAC_MASK              U(0xf)
/* [27:24] PSR_M:           Indicates the implemented M profile instructions to modify the PSRs: */
#define ID_ISAR4_PSR_M_SHIFT                U(24)
#define ID_ISAR4_PSR_M_MASK                 U(0xf)
/* [23:20] SynchPrim_frac:  This field is used with the ID_ISAR3.SynchPrim field to indicate the implemented Synchronization Primitive instructions: */
#define ID_ISAR4_SYNCHPRIM_FRAC_SHIFT       U(20)
#define ID_ISAR4_SYNCHPRIM_FRAC_MASK        U()
/* [19:16] Barrier:         Indicates the supported Barrier instructions in the A32 and T32 instruction sets: */
#define ID_ISAR4_BARRIER_SHIFT              U(16)
#define ID_ISAR4_BARRIER_MASK               U(0xf)
/* [15:12] SMC:             Indicates the implemented SMC instructions: */
#define ID_ISAR4_SMC_SHIFT                  U(12)
#define ID_ISAR4_SMC_MASK                   U(0xf)
/* [11:8] WriteBack:        Indicates the support for Write-Back addressing modes: */
#define ID_ISAR4_WRITEBACK_SHIFT            U(8)
#define ID_ISAR4_WRITEBACK_MASK             U(0xf)
/* [7:4] WithShifts:        Indicates the support for instructions with shifts. */
#define ID_ISAR4_WITHSHIFTS_SHIFT           U(4)
#define ID_ISAR4_WITHSHIFTS_MASK            U(0xf)
/* [3:0] Unpriv:            Indicates the implemented unprivileged instructions */
#define ID_ISAR4_UNPRIV_SHIFT               U(0)
#define ID_ISAR4_UNPRIV_MASK                U(0xf)

/****************************************************************************************************
 * ID_ISAR5_EL1:        RO, 32bit, AArch32 Instruction Set Attribute Register 5
 ****************************************************************************************************/
/* [19:16] CRC32:           Indicates whether CRC32 instructions are implemented in AArch32 state: */
#define ID_ISAR5_CRC32_SHIFT                U(16)
#define ID_ISAR5_CRC32_MASK                 U(0xf)
/* [15:12] SHA2:            Indicates whether SHA2 instructions are implemented in AArch32 state: */
#define ID_ISAR5_SHA2_SHIFT                 U(12)
#define ID_ISAR5_SHA2_MASK                  U(0xf)
/* [11:8] SHA1:             Indicates whether SHA1 instructions are implemented in AArch32 state: */
#define ID_ISAR5_SHA1_SHIFT                 U(8)
#define ID_ISAR5_SHA1_MASK                  U(0xf)
/* [7:4] AES:               Indicates whether AES instructions are implemented in AArch32 state: */
#define ID_ISAR5_AES_SHIFT                  U(4)
#define ID_ISAR5_AES_MASK                   U(0xf)
/* [3:0] SEVL:              Indicates whether the SEVL instruction is implemented: */
#define ID_ISAR5_SEVL_SHIFT                 U(0)
#define ID_ISAR5_SEVL_MASK                  U(0xf)

/****************************************************************************************************
 * ID_AA64PFR0_EL1:     RO, 64bit, AArch64 Processor Feature Register 0
 ****************************************************************************************************/
/* [27:24] GIC:             GIC CPU interface: */
#define ID_AA64PFR0_GIC_SHIFT               U(24)
#define ID_AA64PFR0_GIC_MASK                U(0xf)
/* [23:20] AdvSIMD:         Advanced SIMD. */
#define ID_AA64PFR0_ADVSIMD_SHIFT           U(20)
#define ID_AA64PFR0_ADVSIMD_MASK            U(0xf)
/* [19:16] FP:              Floating-point. */
#define ID_AA64PFR0_FP_SHIFT                U(16)
#define ID_AA64PFR0_FP_MASK                 U(0xf)
/* [15:12] EL3 handling:    EL3 exception handling: */
#define ID_AA64PFR0_EL3_HANDLING_SHIFT      U(12)
#define ID_AA64PFR0_EL3_HANDLING_MASK       U(0xf)
/* [11:8] EL2 handling:     EL2 exception handling: */
#define ID_AA64PFR0_EL2_HANDLING_SHIFT      U(8)
#define ID_AA64PFR0_EL2_HANDLING_MASK       U(0xf)
/* [7:4] EL1 handling:      EL1 exception handling. */
#define ID_AA64PFR0_EL1_HANDLING_SHIFT      U(4)
#define ID_AA64PFR0_EL1_HANDLING_MASK       U(0xf)
/* [3:0] EL0 handling:      EL0 exception handling. */
#define ID_AA64PFR0_EL0_HANDLING_SHIFT      U(0)
#define ID_AA64PFR0_EL0_HANDLING_MASK       U(0xf)

/****************************************************************************************************
 * ID_AA64PFR1_EL1:     RO, 64bit, AArch64 Processor Feature Register 1
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * ID_AA64DFR0_EL1:     RO, 64bit, AArch64 Debug Feature Register 0, EL1
 ****************************************************************************************************/
/* [31:28] CTX_CMP:         Number of breakpoints that are context-aware, minus 1. */
#define ID_AA64DFR0_CTX_CMP_SHIFT           U(28)
#define ID_AA64DFR0_CTX_CMP_MASK            U(0xf)
/* [23:20] WRP:             The number of watchpoints minus 1: */
#define ID_AA64DFR0_WRP_SHIFT               U(20)
#define ID_AA64DFR0_WRP_MASK                U(0xf)
/* [15:12] BRP:             The number of breakpoints minus 1: */
#define ID_AA64DFR0_BRP_SHIFT               U(12)
#define ID_AA64DFR0_BRP_MASK                U(0xf)
/* [11:8] PMUver:           Performance Monitors extension version. */
#define ID_AA64DFR0_PMUVER_SHIFT            U(8)
#define ID_AA64DFR0_PMUVER_MASK             U(0xf)
/* [7:4] Tracever:          Trace extension: */
#define ID_AA64DFR0_TRACEVER_SHIFT          U(4)
#define ID_AA64DFR0_TRACEVER_MASK           U(0xf)
/* [3:0] Debugger:          Debug architecture version: */
#define ID_AA64DFR0_DEBUGGER_SHIFT          U(0)
#define ID_AA64DFR0_DEBUGGER_MASK           U(0xf)

/****************************************************************************************************
 * ID_AA64DFR1_EL1:     RO, 64bit, AArch64 Debug Feature Register 1
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * ID_AA64AFR0_EL1:     RO, 64bit, AArch64 Auxiliary Feature Register 0
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * ID_AA64AFR1_EL1:     RO, 64bit, AArch64 Auxiliary Feature Register 1
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * ID_AA64ISAR0_EL1:    RO, 64bit, AArch64 Instruction Set Attribute Register 0, EL1
 ****************************************************************************************************/
/* [19:16] CRC32:           Indicates whether CRC32 instructions are implemented in AArch64 state: */
#define ID_AA64ISAR0_CRC32_SHIFT            U(16)
#define ID_AA64ISAR0_CRC32_MASK             U(0xf)
/* [15:12] SHA2:            Indicates whether SHA2 instructions are implemented. 
                            The possible values are:
                                0b0000  No SHA2 instructions implemented. 
                                        This is the value if the implementation does not include the Cryptography Extension, or if it is disabled.
                                0b0001  SHA256H, SHA256H2, SHA256U0, and SHA256U1 implemented. 
                                        This is the value if the implementation includes the Cryptography Extension. */
#define ID_AA64ISAR0_SHA2_SHIFT             U(12)
#define ID_AA64ISAR0_SHA2_MASK              U(0xf)
/* [11:8] SHA1:             Indicates whether SHA1 instructions are implemented. 
                            The possible values are:
                                0b0000  No SHA1 instructions implemented. 
                                        This is the value if the implementation does not include the Cryptography Extension.
                                0b0001  SHA1C, SHA1P, SHA1M, SHA1SU0, and SHA1SU1 implemented. 
                                        This is the value if the implementation includes the Cryptography Extension. */
#define ID_AA64ISAR0_SHA1_SHIFT             U(8)
#define ID_AA64ISAR0_SHA1_MASK              U(0xf)
/* [7:4] AES:               Indicates whether AES instructions are implemented. 
                            The possible values are:
                                0b0000  No AES instructions implemented. 
                                        This is the value if the implementation does not include the Cryptography Extension.
                                0b0010  AESE, AESD, AESMC, and AESIMC implemented, plus PMULL and PMULL2 instructions operating on 64-bit data. 
                                        This is the value if the implementation includes the Cryptography Extension. */
#define ID_AA64ISAR0_AES_SHIFT              U(4)
#define ID_AA64ISAR0_AES_MASK               U(0xf)

/****************************************************************************************************
 * ID_AA64ISAR1_EL1:    RO, 64bit, AArch64 Instruction Set Attribute Register 1
 ****************************************************************************************************/
/* [31:28] TGran4:          Support for 4 KB memory translation granule size: */
#define ID_AA64ISAR1_TGRAN4_SHIFT           U(28)
#define ID_AA64ISAR1_TGRAN4_MASK            U(0xf)
/* [27:24] TGran64:         Support for 64 KB memory translation granule size: */
#define ID_AA64ISAR1_TGRAN64_SHIFT          U(24)
#define ID_AA64ISAR1_TGRAN64_MASK           U(0xf)
/* [23:20] TGran16:         Support for 16 KB memory translation granule size: */
#define ID_AA64ISAR1_TGRAN16_SHIFT          U(20)
#define ID_AA64ISAR1_TGRAN16_MASK           U(0xf)
/* [19:16] BigEndEL0:       Mixed-endian support only at EL0. */
#define ID_AA64ISAR1_BIGENDEL0_SHIFT        U(16)
#define ID_AA64ISAR1_BIGENDEL0_MASK         U(0xf)
/* [15:12] SNSMem:          Secure versus Non-secure Memory distinction: */
#define ID_AA64ISAR1_SNSMEM_SHIFT           U(12)
#define ID_AA64ISAR1_SNSMEM_MASK            U(0xf)
/* [11:8] BigEnd:           Mixed-endian configuration support: */
#define ID_AA64ISAR1_BIGEND_SHIFT           U(8)
#define ID_AA64ISAR1_BIGEND_MASK            U(0xf)
/* [7:4] ASIDBits:          Number of ASID bits: */
#define ID_AA64ISAR1_ASIDBITS_SHIFT         U(4)
#define ID_AA64ISAR1_ASIDBITS_MASK          U(0xf)
/* [3:0] PARange:           Physical address range supported: */
#define ID_AA64ISAR1_PARANGE_SHIFT          U(0)
#define ID_AA64ISAR1_PARANGE_MASK           U(0xf)

/****************************************************************************************************
 * ID_AA64MMFR0_EL1:    RO, 64bit, AArch64 Memory Model Feature Register 0, EL1
 ****************************************************************************************************/
/* [31:28] TGran4:          Support for 4 KB memory translation granule size: */
#define ID_AA64MMFR0_TGRAN4_SHIFT           U(28)
#define ID_AA64MMFR0_TGRAN4_MASK            U(0xf)
/* [27:24] TGran64:         Support for 64 KB memory translation granule size: */
#define ID_AA64MMFR0_TGRAN64_SHIFT          U(24)
#define ID_AA64MMFR0_TGRAN64_MASK           U(0xf)
/* [23:20] TGran16:         Support for 16 KB memory translation granule size: */
#define ID_AA64MMFR0_TGRAN16_SHIFT          U(20)
#define ID_AA64MMFR0_TGRAN16_MASK           U(0xf)
/* [19:16] BigEndEL0:       Mixed-endian support only at EL0. */
#define ID_AA64MMFR0_BIGENDEL0_SHIFT        U(16)
#define ID_AA64MMFR0_BIGENDEL0_MASK         U(0xf)
/* [15:12] SNSMem:          Secure versus Non-secure Memory distinction: */
#define ID_AA64MMFR0_SNSMEM_SHIFT           U(12)
#define ID_AA64MMFR0_SNSMEM_MASK            U(0xf)
/* [11:8] BigEnd:           Mixed-endian configuration support: */
#define ID_AA64MMFR0_BIGEND_SHIFT           U(8)
#define ID_AA64MMFR0_BIGEND_MASK            U(0xf)
/* [7:4] ASIDBits:          Number of ASID bits: */
#define ID_AA64MMFR0_ASIDBITS_SHIFT         U(4)
#define ID_AA64MMFR0_ASIDBITS_MASK          U(0xf)
/* [3:0] PARange:           Physical address range supported: */
#define ID_AA64MMFR0_PARANGE_SHIFT          U(0)
#define ID_AA64MMFR0_PARANGE_MASK           U(0xf)

/****************************************************************************************************
 * ID_AA64MMFR1_EL1:    RO, 64bit, AArch64 Memory Model Feature Register 1
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * CCSIDR_EL1:          RO, 32bit, Cache Size ID Register
 ****************************************************************************************************/
/* [31] WT:                 Indicates support for write-through:
                                0   Cache level does not support write-through.
                                1   Cache level support write-through. */
#define CCSIDR_WT_SHIFT                     U(31)
#define CCSIDR_WT_MASK                      U(0x1)
/* [30] WB:                 Indicates support for write-back:
                                0   Cache level does not support write-back.
                                1   Cache level supports write-back. */
#define CCSIDR_WB_SHIFT                     U(30)
#define CCSIDR_WB_MASK                      U(0x1)
/* [29] RA:                 Indicates support for Read-Allocation:
                                0   Cache level does not support Read-Allocation.
                                1   Cache level supports Read-Allocation. */
#define CCSIDR_RA_SHIFT                     U(29)
#define CCSIDR_RA_MASK                      U(0x1)
/* [28] WA:                 Indicates support for Write-Allocation:
                                0   Cache level does not support Write-Allocation.
                                1   Cache level supports Write-Allocation. */
#define CCSIDR_WA_SHIFT                     U(28)
#define CCSIDR_WA_MASK                      U(0x1)
/* [27:13] NumSets:         Indicates the number of sets in cache - 1. 
                            Therefore, a value of 0 indicates 1 set in the cache. 
                            The number of sets does not have to be a power of 2. */
#define CCSIDR_NUMSETS_SHIFT                U(13)
#define CCSIDR_NUMSETS_MASK                 U(0x7fff)
/* [12:3] Associativity:    Indicates the associativity of cache - 1. 
                            Therefore, a value of 0 indicates an associativity of 1. 
                            The associativity does not have to be a power of 2. */
#define CCSIDR_ASSOCIATIVITY_SHIFT          U(3)
#define CCSIDR_ASSOCIATIVITY_MASK           U(0x3ff)
/* [2:0] LineSize:          Indicates the (log2 (number of words in cache line)) - 2: */
#define CCSIDR_LINESIZE_SHIFT               U(0)
#define CCSIDR_LINESIZE_MASK                U(0x7)

/****************************************************************************************************
 * CLIDR_EL1:           RO, 64bit, Cache Level ID Register
 ****************************************************************************************************/
/* [32:30] ICB:             Inner cache boundary. This field indicates the boundary between the inner and the outer domain. */
#define CLIDR_ICB_SHIFT                     U(30)
#define CLIDR_ICB_MASK                      U(0x7)
/* [29:27] LoUU:            LoUU Indicates the Level of Unification Uniprocessor for the cache hierarchy: */
#define CLIDR_LOUU_SHIFT                    U(27)
#define CLIDR_LOUU_MASK                     U(0x7)
/* [26:24] LoC:             Indicates the Level of Coherency for the cache hierarchy: */
#define CLIDR_LOC_SHIFT                     U(24)
#define CLIDR_LOC_MASK                      U(0x7)
/* [23:21] LoUIS:           Indicates the Level of Unification Inner Shareable for the cache hierarchy: */
#define CLIDR_LOUIS_SHIFT                   U(21)
#define CLIDR_LOUIS_MASK                    U(0x7)
/* [8:6] Ctype3:            Indicates the type of cache if the processor implements L3 cache: */
#define CLIDR_CTYPE3_SHIFT                  U(6)
#define CLIDR_CTYPE3_MASK                   U(0x7)
/* [5:3] Ctype2:            Indicates the type of cache if the processor implements L2 cache: */
#define CLIDR_CTYPE2_SHIFT                  U(3)
#define CLIDR_CTYPE2_MASK                   U(0x7)
/* [2:0] Ctype1:            Indicates the type of cache implemented at L1: */
#define CLIDR_CTYPE1_SHIFT                  U(0)
#define CLIDR_CTYPE1_MASK                   U(0x7)

/****************************************************************************************************
 * AIDR_EL1:            RO, 32bit, Auxiliary ID Register
 ****************************************************************************************************/
/* The processor does not implement AIDR_EL1, so this register is always RES0. */

/****************************************************************************************************
 * CSSELR_EL1:          RW, 32bit, Cache Size Selection Register
 ****************************************************************************************************/
/* [3:1] Level:             Cache level of required cache:
                                0b000           L1.
                                0b001           L2.
                                0b010-0b111     Reserved. */
#define CSSELR_LEVEL_SHIFT                  U(1)
#define CSSELR_LEVEL_MASK                   U(0x7)
/* [0] InDa:                Instruction not Data bit:
                                0   Data or unified cache.
                                1   Instruction cache. */
#define CSSELR_IND_SHIFT                    U(0)
#define CSSELR_IND_MASK                     U(0x1)

/****************************************************************************************************
 * CTR_EL0:             RO, 32bit, Cache Type Register
 ****************************************************************************************************/
/* [27:24] CWG:             Cache Write-Back granule. 
                            Log2 of the number of words of the maximum size of memory 
                            that can be overwritten as a result of the eviction of a cache entry 
                            that has had a memory location in it modified: */
#define CTR_CWG_SHIFT                       U(24)
#define CTR_CWG_MASK                        U(0xf)
/* [23:20] ERG:             Exclusives Reservation Granule. 
                            Log2 of the number of words of the maximum size of the reservation granule
                            that has been implemented for the Load-Exclusive and Store-Exclusive instructions: */
#define CTR_ERG_SHIFT                       U(20)
#define CTR_ERG_MASK                        U(0xf)
/* [19:16] DminLine:        Log2 of the number of words in the smallest cache line of all the data 
                            and unified caches that the processor controls: */
#define CTR_DMINLINE_SHIFT                  U(16)
#define CTR_DMINLINE_MASK                   U(0xf)
/* [15:14] L1lp:            L1 Instruction cache policy. 
                            Indicates the indexing and tagging policy for the L1 Instruction cache: */
#define CTR_L1LP_SHIFT                      U(14)
#define CTR_L1LP_MASK                       U(0x3)
/* [3:0] IminLine:          Log2 of the number of words in the smallest cache line of all the instruction caches 
                            that the processor controls. */
#define CTR_IMINLINE_SHIFT                  U(0)
#define CTR_IMINLINE_MASK                   U(0xf)

/****************************************************************************************************
 * DCZID_EL0:           RO, 32bit, Data Cache Zero ID Register
 ****************************************************************************************************/
/* [4] DZP:                 Prohibit the DC ZVA instruction:
                                0   DC ZVA instruction permitted.
                                1   DC ZVA instruction is prohibited */
#define DCZID_DZP_SHIFT                     U(4)
#define DCZID_DZP_MASK                      U(0x1)
/* [3:0] BlockSize:         Log2 of the block size in words: */
#define DCZID_BLOCKSIZE_SHIFT               U(0)
#define DCZID_BLOCKSIZE_MASK                U(0xf)

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
/* [63:0] VMPIDR:           MPIDR value returned by Non-secure EL1 reads of the MPIDR_EL1. 
                            The MPIDR description defines the subdivision of this value. */
#define VMPIDR_SHIFT                         U(0)
#define VMPIDR_MASK                          U(0xffffffffffffffff)

#endif  /* !IDENTIFICATION__H__ */
