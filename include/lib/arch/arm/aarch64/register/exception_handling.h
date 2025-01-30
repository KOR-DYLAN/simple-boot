/****************************************************************************************************
 * AArch64 Exception handling registers
 ****************************************************************************************************/
#ifndef EXCEPTION_HANDLING__H__
#define EXCEPTION_HANDLING__H__

/****************************************************************************************************
 * AFSR0_EL1:           RW, 32bit, Auxiliary Fault Status Register 0, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR0_EL1, AFSR0_EL2 and AFSR0_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AFSR1_EL1:           RW, 32bit, Auxiliary Fault Status Register 1, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR0_EL1, AFSR0_EL2 and AFSR0_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * ESR_EL1:             RW, 32bit, Exception Syndrome Register, EL1
 ****************************************************************************************************/
/* [31:26] EC:              Exception Class. Indicates the reason for the exception that this register holds information about. */
#define ESR_EL1_EC_SHIFT            U(26)
#define ESR_EL1_EC_MASK             U(0x3f)
/* [25] IL:                 Instruction Length for synchronous exceptions. The possible values are:
                                0   16-bit.
                                1   32-bit.
                            This field is 1 for the SError interrupt, instruction aborts, misaligned PC, Stack pointer misalignment, 
                            data aborts for which the ISV bit is 0, exceptions caused by an illegal instruction set state, 
                            and exceptions using the 0x00 Exception Class. */
#define ESR_EL1_IL_SHIFT            U(25)
#define ESR_EL1_IL_MASK             U(0x1)
/* [24] ISS Valid:          Syndrome valid. The possible values are:
                                0   ISS not valid, ISS is RES0.
                                1   ISS valid. */
#define ESR_EL1_ISS_VALID_SHIFT     U(24)
#define ESR_EL1_ISS_VALID_MASK      U(0x1)
/* [23:0] ISS:              Syndrome information.
                            When the EC field is 0x2F, indicating an SError interrupt has occurred, the ISS field contents are IMPLEMENTATION DEFINED.
                            ISS field contents for the Cortex-A53 processor
                                ISS[23:22]  ISS[1:0]    Description
                                0b00        0b00        DECERR on external access
                                0b00        0b01        Double-bit error detected on dirty line in L2 cache
                                0b00        0b10        SLVERR on external access
                                0b01        0b00        nSEI, or nVSEI in a guest OS, asserted
                                0b01        0b01        nREI asserted */
#define ESR_EL1_ISS_SHIFT           U(0)
#define ESR_EL1_ISS_MASK            U(0xffffff)

/****************************************************************************************************
 * IFSR32_EL2:          RW, 32bit, Instruction Fault Status Register
 ****************************************************************************************************/
/* [12] ExT:                External abort type. This field indicates whether an AXI Decode or Slave error caused an abort:
                                0   External abort marked as DECERR.
                                1   External abort marked as SLVERR.
                                For aborts other than external aborts this bit always returns 0. */
#define IFSR32_EL2_EXT_SHIFT        U(12)
#define IFSR32_EL2_EXT_MASK         U(0x1)

/* 
 * IFSR32_EL2 when using the Short-descriptor translation table format 
 */
/* [10] FS[4]:              Part of the Fault Status field. See bits [3:0] in this table. */
#define IFSR32_EL2_FS_4_SHIFT       U(10)
#define IFSR32_EL2_FS_4_MASK        U(0x1)
/* [4:0] FS[3:0]:           Fault Status bits. This field indicates the type of exception generated. Any encoding not listed is reserved.
                                0b00010     Debug event.
                                0b00011     Access flag fault, section.
                                0b00101     Translation fault, section.
                                0b00110     Access flag fault, page.
                                0b00111     Translation fault, page.
                                0b01000     Synchronous external abort, non-translation.
                                0b01001     Domain fault, section.
                                0b01011     Domain fault, page.
                                0b01100     Synchronous external abort on translation table walk, first level.
                                0b01101     Permission Fault, Section.
                                0b01110     Synchronous external abort on translation table walk, second Level.
                                0b01111     Permission fault, page.
                                0b10000     TLB conflict abort.
                                0b11001     Synchronous parity error on memory access.
                                0b11100     Synchronous parity error on translation table walk, first level.
                                0b11110     Synchronous parity error on translation table walk, second level. */
#define IFSR32_EL2_FS_SHIFT         U(0)
#define IFSR32_EL2_FS_MASK          U(0x1f)

/* 
 * IFSR32_EL2 when using the long-descriptor translation table format 
 */
/* [5:0] Status:            Fault Status bits. This field indicates the type of exception generated. Any encoding not listed is reserved.
                                0b000000    Address size fault in TTBR0 or TTBR1.
                                0b0001LL    Translation fault, LL bits indicate level.
                                0b0010LL    Access fault flag, LL bits indicate level.
                                0b0011LL    Permission fault, LL bits indicate level.
                                0b010000    Synchronous external abort.
                                0b0101LL    Synchronous external abort on translation table walk, LL bits indicate level.
                                0b011000    Synchronous parity error on memory access.
                                0b0111LL    Synchronous parity error on memory access on translation table walk, LL bits indicate level.
                                0b100001    Alignment fault.
                                0b100010    Debug event.
                                0b110000    TLB conflict abort. 
                            Encodings of LL bits associated with the MMU fault
                                0b00    Reserved
                                0b01    Level 1
                                0b10    Level 2
                                0b11    Level 3 */
#define IFSR32_EL2_STATUS_SHIFT     U(0)
#define IFSR32_EL2_STATUS_MASK      U(0x3f)

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
 * AFSR0_EL3:           RW, 32bit, Auxiliary Fault Status Register 0, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR0_EL1, AFSR0_EL2 and AFSR0_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AFSR1_EL3:           RW, 32bit, Auxiliary Fault Status Register 1, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR1_EL1, AFSR1_EL2 and AFSR1_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * ESR_EL3:             RW, 32bit, Exception Syndrome Register, EL3
 ****************************************************************************************************/
/* [31:26] EC:              Exception Class. 
                            Indicates the reason for the exception that this register holds information about. */
#define ESR_EL3_EC_SHIFT            U(26)
#define ESR_EL3_EC_MASK             U(0x1)
/* [25] IL:                 Instruction Length for synchronous exceptions. The possible values are:
                                0   16-bit.
                                1   32-bit.
                            This field is 1 for the SError interrupt, instruction aborts, misaligned PC, Stack pointer misalignment, 
                            data aborts for which the ISV bit is 0, exceptions caused by an illegal instruction set state, 
                            and exceptions using the 0x0 Exception Class. */
#define ESR_EL3_IL_SHIFT            U(25)
#define ESR_EL3_IL_MASK             U(0x1)
/* [24] ISS:                Valid Syndrome valid. The possible values are:
                                0   ISS not valid, ISS is RES0.
                                1   ISS valid. */
#define ESR_EL3_ISS_VALID_SHIFT     U(24)
#define ESR_EL3_ISS_VALID_MASK      U(0x1)
/* [23:0] ISS:              Syndrome information. 
                                ISS[23:22]  ISS[1:0]    Description
                                0b00        0b00        DECERR on external access
                                0b00        0b01        Double-bit error detected on dirty line in L2 cache
                                0b00        0b10        SLVERR on external access
                                0b01        0b00        nSEI, or nVSEI in a guest OS, asserted
                                0b01        0b01        nREI asserted*/
#define ESR_EL3_ISS_SHIFT           U(0)
#define ESR_EL3_ISS_MASK            U(0xffffff)

/****************************************************************************************************
 * FAR_EL1:             RW, 64bit, Fault Address Register, EL1
 ****************************************************************************************************/
/* [63:0] VA:               The faulting Virtual Address for all synchronous instruction or data aborts, 
                            or an exception from a misaligned PC, taken in EL1.
                            If a memory fault that sets the FAR is generated from one of the data cache instructions, 
                            this field holds the address specified in the register argument of the instruction. */
#define FAR_EL1_VA_SHIFT            U(0)
#define FAR_EL1_VA_MASK             U(0xffffffffffffffff)

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
 * FAR_EL3:             RW, 64bit, Fault Address Register, EL3
 ****************************************************************************************************/
/* [63:0] VA:               The faulting Virtual Address for all synchronous instruction or data aborts, 
                            or an exception from a misaligned PC, taken in EL3.
                            If a memory fault that sets the FAR is generated from one of the data cache instructions, 
                            this field holds the address specified in the register argument of the instruction. */
#define FAR_EL3_VA_SHIFT            U(0)
#define FAR_EL3_VA_MASK             U(0xffffffffffffffff)

/****************************************************************************************************
 * VBAR_EL1:            RW, 64bit, Vector Base Address Register, EL1
 ****************************************************************************************************/
/* [63:11] Vector base address:     Base address of the exception vectors for exceptions taken in this exception level. */
#define VBAR_EL1_SHIFT              U(11)
#define VBAR_EL1_MASK               U(0xfffffffffffff)

/****************************************************************************************************
 * ISR_EL1:             RO, 32bit, Interrupt Status Register
 ****************************************************************************************************/
/* [8] A:                           External abort pending bit:
                                        0   No pending external abort.
                                        1   An external abort is pending. */
#define ISR_EL1_A_SHIFT             U(8)
#define ISR_EL1_A_MASK              U(0x1)
/* [7] I:                           IRQ pending bit. Indicates whether an IRQ interrupt is pending:
                                        0   No pending IRQ.
                                        1   An IRQ interrupt is pending. */
#define ISR_EL1_I_SHIFT             U(7)
#define ISR_EL1_I_MASK              U(0x1)
/* [6] F:                           FIQ pending bit. Indicates whether an FIQ interrupt is pending:
                                        0   No pending FIQ.
                                        1   An FIQ interrupt is pending. */
#define ISR_EL1_F_SHIFT             U(6)
#define ISR_EL1_F_MASK              U(0x1)

/****************************************************************************************************
 * VBAR_EL2:            RW, 64bit, Vector Base Address Register, EL2
 ****************************************************************************************************/
#ifndef REG_VBAR_EL2
#define REG_VBAR_EL2
/* [63:11] Vector base address:     Base address of the exception vectors for exceptions taken in this exception level. */
#define VBAR_EL2_SHIFT              U(11)
#define VBAR_EL2_MASK               U(0xfffffffffffff)
#endif  /* !REG_VBAR_EL2 */

/****************************************************************************************************
 * VBAR_EL3:            RW, 64bit, Vector Base Address Register, EL3
 ****************************************************************************************************/
#ifndef REG_VBAR_EL3
#define REG_VBAR_EL3
/* [63:11] Vector base address:     Base address of the exception vectors for exceptions taken in this exception level. */
#define VBAR_EL3_SHIFT              U(11)
#define VBAR_EL3_MASK               U(0xfffffffffffff)
#endif  /* !REG_VBAR_EL3 */

#endif  /* !EXCEPTION_HANDLING__H__ */
