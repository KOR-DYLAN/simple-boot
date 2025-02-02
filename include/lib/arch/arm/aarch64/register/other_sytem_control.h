/****************************************************************************************************
 * AArch64 Other system control registers
 ****************************************************************************************************/
#ifndef OTHER_SYTEM_CONTROL__H__
#define OTHER_SYTEM_CONTROL__H__

/****************************************************************************************************
 * ACTLR_EL1:           RW, 32bit, Auxiliary Control Register, EL1
 ****************************************************************************************************/
/* The processor does not implement the ACTLR_EL1 register. This register is always RES0 */


/****************************************************************************************************
 * CPACR_EL1:           RW, 32bit, Architectural Feature Access Control Register
 ****************************************************************************************************/
/* [28] TTA:                Causes access to the Trace functionality to trap to EL1 when executed from EL0 or EL1.
                            This bit is RES0. */
#define CPACR_TTA_SHIFT                     U(28)
#define CPACR_TTA_MASK                      U(0x1)
/* [21:20] FPEN:            Traps instructions that access registers associated with Advanced SIMD and Floating-point execution to trap to 
                            EL1 when executed from EL0 or EL1. 
                            The possible values are:
                            0bX0    Trap any instruction in EL0 or EL1 that uses registers associated with Advanced SIMD and
                                    Floating-point execution. The reset value is 0b00.
                            0b01    Trap any instruction in EL0 that uses registers associated with Advanced SIMD and
                                    Floating-point execution. Instructions in EL1 are not trapped.
                            0b11    No instructions are trapped.
                            This field is RES0 if Advanced SIMD and Floating-point are not implemented. */
#define CPACR_FPEN_SHIFT                    U(20)
#define CPACR_FPEN_MASK                     U(0x3)

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
 * ACTLR_EL3:           RW, 32bit, Auxiliary Control Register, EL3
 ****************************************************************************************************/
#ifndef REG_ACTLR_EL3
#define REG_ACTLR_EL3
/* [6] L2ACTLR_EL1 access control:  L2ACTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from a lower exception level. This is the reset value.
                                        1   The register is write accessible from EL2. */
#define ACTLR_EL3_L2ACTLR_EL1_SHIFT         U(6)
#define ACTLR_EL3_L2ACTLR_EL1_MASK          U(0x1)
/* [5] L2ECTLR_EL1 access control:  L2ECTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from a lower exception level. This is the reset value.
                                        1   The register is write accessible from EL2 */
#define ACTLR_EL3_L2ECTLR_EL1_SHIFT         U(5)
#define ACTLR_EL3_L2ECTLR_EL1_MASK          U(0x1)
/* [4] L2CTLR_EL1 access control:   L2CTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from a lower exception level. This is the reset value.
                                        1   The register is write accessible from EL2. */
#define ACTLR_EL3_L2CTLR_EL1_SHIFT          U(4)
#define ACTLR_EL3_L2CTLR_EL1_MASK           U(0x1)
/* [1] CPUECTLR_EL1 access control: CPUECTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from a lower exception level. This is the reset value.
                                        1   The register is write accessible from EL2. */
#define ACTLR_EL3_CPUECTLR_EL1_SHIFT        U(1)
#define ACTLR_EL3_CPUECTLR_EL1_MASK         U(0x1)
/* [0] CPUACTLR_EL1 access control: CPUACTLR_EL1 write access control. The possible values are:
                                        0   The register is not write accessible from a lower exception level. This is the reset value.
                                        1   The register is write accessible from EL2. */
#define ACTLR_EL3_CPUACTLR_EL1_SHIFT        U(0)
#define ACTLR_EL3_CPUACTLR_EL1_MASK         U(0x1)
#endif  /* !REG_ACTLR_EL3 */

/****************************************************************************************************
 * DIT:                 RW, 64bit, Data Independent Timing
 ****************************************************************************************************/
/* [24] DIT:                        Data Independent Timing.
                                        0   The architecture makes no statement about the timing properties of any instructions. 
                                        1   The architecture requires that:
                                            • The timing of every load and store instruction is insensitive to the value of the data being loaded or stored.
                                            • For certain data processing instructions, the instruction takes a time which is independent of:
                                                - The values of the data supplied in any of its registers.
                                                - The values of the NZCV flags.
                                            • For certain data processing instructions, the response of the instruction to asynchronous exceptions does not vary based on:
                                                - The values of the data supplied in any of its registers.
                                                - The values of the NZCV flags. */
#define DIT_SHIFT                           U(24)
#define DIT_MASK                            U(0x1)
#define DIT_BIT                             (DIT_MASK << DIT_SHIFT)

#endif  /* !OTHER_SYTEM_CONTROL__H__ */
