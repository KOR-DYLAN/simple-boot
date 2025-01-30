/****************************************************************************************************
 * AArch64 performance monitor registers
 ****************************************************************************************************/
#ifndef PERFORMANCE_MONITOR__H__
#define PERFORMANCE_MONITOR__H__

/****************************************************************************************************
 * PMCR_EL0:            RW, 32bit, Performance Monitors Control Register
 ****************************************************************************************************/
/* [31:24] IMP:             Implementer code:
                                0x41    Arm.
                                This is a read-only field. */
#define PMCR_EL0_IMP_SHIFT                  U(24)
#define PMCR_EL0_IMP_MASK                   U(0xff)
/* [23:16] IDCODE:          Identification code:
                                0x03    Cortex-A53.
                                This is a read-only field. */
#define PMCR_EL0_IDCODE_SHIFT               U(16)
#define PMCR_EL0_IDCODE_MASK                U(0xff)
/* [15:11] N:               Number of event counters.
                                0b00110     Six counters. */
#define PMCR_EL0_N_SHIFT                    U(11)
#define PMCR_EL0_N_MASK                     U(0x1f)
/* [6] LC:                  Long cycle count enable. 
                            Determines which PMCCNTR_EL0 bit generates an overflow recorded in PMOVSR[31]. The possible values are:
                                0   Overflow on increment that changes PMCCNTR_EL0[31] from 1 to 0.
                                1   Overflow on increment that changes PMCCNTR_EL0[63] from 1 to 0. */
#define PMCR_EL0_LC_SHIFT                   U(6)
#define PMCR_EL0_LC_MASK                    U(0x1)
/* [5] DP:                  Disable cycle counter, PMCCNTR_EL0 when event counting is prohibited:
                                0   Cycle counter operates regardless of the non-invasive debug authentication settings. This is the reset value.
                                1   Cycle counter is disabled if non-invasive debug is not permitted and enabled.
                                This bit is read/write. */
#define PMCR_EL0_DP_SHIFT                   U(5)
#define PMCR_EL0_DP_MASK                    U(0x1)
/* [4] X:                   Export enable. This bit permits events to be exported to another debug device, such as a trace macrocell, over an event bus:
                                0   Export of events is disabled. This is the reset value.
                                1   Export of events is enabled.
                                This bit is read/write and does not affect the generation of Performance Monitors interrupts on the nPMUIRQ pin. */
#define PMCR_EL0_X_SHIFT                    U(4)
#define PMCR_EL0_X_MASK                     U(0x1)
/* [3] D:                   Clock divider:
                                0   When enabled, PMCCNTR_EL0 counts every clock cycle. This is the reset value.
                                1   When enabled, PMCCNTR_EL0 counts every 64 clock cycles.
                                This bit is read/write. */
#define PMCR_EL0_D_SHIFT                    U(3)
#define PMCR_EL0_D_MASK                     U(0x1)
/* [2] C:                   Clock counter reset. This bit is WO. The effects of writing to this bit are:
                                0   No action. This is the reset value.
                                1   Reset PMCCNTR_EL0 to 0.
                                This bit is always RAZ. 
                            Note
                                Resetting PMCCNTR does not clear the PMCCNTR_EL0 overflow bit to 0. 
                                See the Arm® Architecture Reference Manual Armv8, for Armv8-A architecture profile for more information. */
#define PMCR_EL0_C_SHIFT                    U(2)
#define PMCR_EL0_C_MASK                     U(0x1)
/* [1] P:                   Event counter reset. This bit is WO. The effects of writing to this bit are:
                                0   No action. This is the reset value.
                                1   Reset all event counters, not including PMCCNTR_EL0, to zero.
                                This bit is always RAZ.
                            In Non-secure EL0 and EL1, a write of 1 to this bit does not reset event counters that MDCR_EL2.HPMN reserves for EL2 use.
                            In EL2 and EL3, a write of 1 to this bit resets all the event counters.
                            Resetting the event counters does not clear any overflow bits to 0. */
#define PMCR_EL0_P_SHIFT                    U(1)
#define PMCR_EL0_P_MASK                     U(0x1)
/* [0] E:                   Enable. The possible values of this bit are:
                                0   All counters, including PMCCNTR_EL0, are disabled. This is the reset value.
                                1   All counters are enabled.
                            This bit is RW.
                            In Non-secure EL0 and EL1, this bit does not affect the operation of event counters that MDCR_EL2.HPMN
                            reserves for EL2 use.
                            On Warm reset, the field resets to 0. */
#define PMCR_EL0_E_SHIFT                    U(0)
#define PMCR_EL0_E_MASK                     U(0x1)

/****************************************************************************************************
 * PMCNTENSET_EL0:      RW, 32bit, Performance Monitors Count Enable Set Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMCNTENCLR_EL0:      RW, 32bit, Performance Monitors Count Enable Clear Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMOVSCLR_EL0:        RW, 32bit, Performance Monitors Overflow Flag Status Clear Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMSWINC_EL0:         WO, 32bit, Performance Monitors Software Increment Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMSELR_EL0:          RW, 32bit, Performance Monitors Event Counter Selection Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMCEID0_EL0:         RO, 32bit, Performance Monitors Common Event Identification Register 0
 ****************************************************************************************************/
/* [31] 0x1F L1D_CACHE_ALLOCATE:        L1 Data cache allocate:
                                            0   This event is not implemented. */
#define PMCEID0_EL0_L1D_CACHE_ALLOCATE_SHIFT        U(31)
/* [30] 0x1E CHAIN:                     Chain. For odd-numbered counters, counts once for each overflow of the preceding even-numbered counter. 
                                        For even-numbered counters, does not count:
                                            1   This event is implemented. */
#define PMCEID0_EL0_CHAIN_SHIFT                     U(30)
/* [29] 0x1D BUS_CYCLES:                Bus cycle:
                                            1   This event is implemented. */
#define PMCEID0_EL0_BUS_CYCLES_SHIFT                U(29)
/* [28] 0x1C TTBR_WRITE_RETIRED:        TTBR write, architecturally executed, condition check pass - write to translation table base:
                                            0   This event is not implemented. */
#define PMCEID0_EL0_TTBR_WRITE_RETIRED_SHIFT        U(28)
/* [27] 0x1B INST_SPEC:                 Instruction speculatively executed:
                                            0   This event is not implemented. */
#define PMCEID0_EL0_INST_SPEC_SHIFT                 U(27)
/* [26] 0x1A MEMORY_ERROR:              Local memory error:
                                            1   This event is implemented. */
#define PMCEID0_EL0_MEMORY_ERROR_SHIFT              U(26)
/* [25] 0x19 BUS_ACCESS:                Bus access:
                                            1   This event is implemented. */
#define PMCEID0_EL0_BUS_ACCESS_SHIFT                U(25)
/* [24] 0x18 L2D_CACHE_WB:              L2 Data cache Write-Back:
                                            0   This event is not implemented if the Cortex-A53 processor has been configured without an L2 cache.
                                            1   This event is implemented if the Cortex-A53 processor has been configured with an L2 cache. */
#define PMCEID0_EL0_L2D_CACHE_WB_SHIFT              U(24)
/* [23] 0x17 L2D_CACHE_REFILL:          L2 Data cache refill:
                                            0   This event is not implemented if the Cortex-A53 processor has been configured without an L2 cache.
                                            1   This event is implemented if the Cortex-A53 processor has been configured with an L2 cache. */
#define PMCEID0_EL0_L2D_CACHE_REFILL_SHIFT          U(23)
/* [22] 0x16 L2D_CACHE:                 L2 Data cache access:
                                            0   This event is not implemented if the Cortex-A53 processor has been configured without an L2 cache.
                                            1   This event is implemented if the Cortex-A53 processor has been configured with an L2 cache. */
#define PMCEID0_EL0_L2D_CACHE_SHIFT                 U(22)
/* [21] 0x15 L1D_CACHE_WB:              L1 Data cache Write-Back:
                                            1   This event is implemented. */
#define PMCEID0_EL0_L1D_CACHE_WB_SHIFT              U(21)
/* [20] 0x14 L1I_CACHE:                 L1 Instruction cache access:
                                            1   This event is implemented. */
#define PMCEID0_EL0_L1I_CACHE_SHIFT                 U(20)
/* [19] 0x13 MEM_ACCESS:                Data memory access:
                                            1   This event is implemented. */
#define PMCEID0_EL0_MEM_ACCESS_SHIFT                U(19)
/* [18] 0x12 BR_PRED:                   Predictable branch speculatively executed:
                                            1   This event is implemented. */
#define PMCEID0_EL0_BR_PRED_SHIFT                   U(18)
/* [17] 0x11 CPU_CYCLES:                Cycle:
                                            1   This event is implemented. */
#define PMCEID0_EL0_CPU_CYCLES_SHIFT                U(17)
/* [16] 0x10 BR_MIS_PRED:               Mispredicted or not predicted branch speculatively executed:
                                            1   This event is implemented. */
#define PMCEID0_EL0_BR_MIS_PRED_SHIFT               U(16)
/* [15] 0x0F UNALIGNED_LDST_RETIRED:    Instruction architecturally executed, condition check pass - unaligned load or store:
                                            1   This event is implemented. */
#define PMCEID0_EL0_UNALIGNED_LDST_RETIRED_SHIFT    U(15)
/* [14] 0x0E BR_RETURN_RETIRED:         Instruction architecturally executed, condition check pass - procedure return:
                                            0   This event is not implemented. */
#define PMCEID0_EL0_BR_RETURN_RETIRED_SHIFT         U(14)
/* [13] 0x0D BR_IMMED_RETIRED:          Instruction architecturally executed - immediate branch:
                                            1   This event is implemented. */
#define PMCEID0_EL0_BR_IMMED_RETIRED_SHIFT          U(13)
/* [12] 0x0C PC_WRITE_RETIRED:          Instruction architecturally executed, condition check pass - software change of the PC:
                                            1   This event is implemented. */
#define PMCEID0_EL0_PC_WRITE_RETIRED_SHIFT          U(12)
/* [11] 0x0B CID_WRITE_RETIRED:         Instruction architecturally executed, condition check pass - write to CONTEXTIDR:
                                            1   This event is implemented. */
#define PMCEID0_EL0_CID_WRITE_RETIRED_SHIFT         U(11)
/* [10] 0x0A EXC_RETURN:                Instruction architecturally executed, condition check pass - exception return:
                                            1   This event is implemented. */
#define PMCEID0_EL0_EXC_RETURN_SHIFT                U(10)
/* [9] 0x09 EXC_TAKEN:                  Exception taken:
                                            1   This event is implemented. */
#define PMCEID0_EL0_EXC_TAKEN_SHIFT                 U(9)
/* [8] 0x08 INST_RETIRED:               Instruction architecturally executed:
                                            1   This event is implemented. */
#define PMCEID0_EL0_INST_RETIRED_SHIFT              U(8)
/* [7] 0x07 ST_RETIRED:                 Instruction architecturally executed, condition check pass - store:
                                            1   This event is implemented. */
#define PMCEID0_EL0_ST_RETIRED_SHIFT                U(7)
/* [6] 0x06 LD_RETIRED:                 Instruction architecturally executed, condition check pass - load:
                                            1   This event is implemented. */
#define PMCEID0_EL0_LD_RETIRED_SHIFT                U(6)
/* [5] 0x05 L1D_TLB_REFILL:             L1 Data TLB refill:
                                            1   This event is implemented. */
#define PMCEID0_EL0_L1D_TLB_REFILL_SHIFT            U(5)
/* [4] 0x04 L1D_CACHE:                  L1 Data cache access:
                                            1   This event is implemented. */
#define PMCEID0_EL0_L1D_CACHE_SHIFT                 U(4)
/* [3] 0x03 L1D_CACHE_REFILL:           L1 Data cache refill:
                                            1   This event is implemented. */
#define PMCEID0_EL0_L1D_CACHE_REFILL_SHIFT          U(3)
/* [2] 0x02 L1I_TLB_REFILL:             L1 Instruction TLB refill:
                                            1   This event is implemented. */
#define PMCEID0_EL0_L1I_TLB_REFILL_SHIFT            U(2)
/* [1] 0x01 L1I_CACHE_REFILL:           L1 Instruction cache refill:
                                            1   This event is implemented. */
#define PMCEID0_EL0_L1I_CACHE_REFILL_SHIFT          U(1)
/* [0] 0x00 SW_INCR:                    Instruction architecturally executed, condition check pass - software increment:
                                            1   This event is implemented. */
#define PMCEID0_EL0_SW_INCR_SHIFT                   U(0)
#define PMCEID0_EL0_MASK                            U(0x1)

/****************************************************************************************************
 * PMCCNTR_EL0:         RW, 64bit, Performance Monitors Cycle Counter
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMXEVTYPER_EL0:      RW, 32bit, Performance Monitors Selected Event Type and Filter Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMXEVCNTR_EL0:       RW, 32bit, Performance Monitors Selected Event Counter Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMUSERENR_EL0:       RW, 32bit, Performance Monitors User Enable Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMINTENSET_EL1:      RW, 32bit, Performance Monitors Interrupt Enable Set Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMINTENCLR_EL1:      RW, 32bit, Performance Monitors Interrupt Enable Clear Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMOVSSET_EL0:        RW, 32bit, Performance Monitors Overflow Flag Status Set Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMEVCNTR0_EL0:        RW, 32bit, Performance Monitor Event Count Registers
 * PMEVCNTR1_EL0
 * PMEVCNTR2_EL0
 * PMEVCNTR3_EL0
 * PMEVCNTR4_EL0
 * PMEVCNTR5_EL0
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMEVTYPER0_EL0:      RW, 32bit, Performance Monitor Event Type Registers
 * PMEVTYPER1_EL0
 * PMEVTYPER2_EL0
 * PMEVTYPER3_EL0
 * PMEVTYPER4_EL0
 * PMEVTYPER5_EL0
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

/****************************************************************************************************
 * PMCCFILTR_EL0:       RW, 32bit, Performance Monitors Cycle Count Filter Register
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

#endif  /* !PERFORMANCE_MONITOR__H__ */
