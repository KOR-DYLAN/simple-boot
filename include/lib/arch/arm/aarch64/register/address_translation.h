/****************************************************************************************************
 * AArch64 address translation operations
 ****************************************************************************************************/
#ifndef ADDRESS_TRANSLATION__H__
#define ADDRESS_TRANSLATION__H__

/****************************************************************************************************
 * PAR_EL1:             RW, 64bit, Physical Address Register, EL1
 ****************************************************************************************************/
/* 
 * PAR_EL1 pass bit assignments 
 */
/* [63:56] Attr:            Memory attributes for the returned output address. 
                            This field uses the same encoding as the Attr<n> fields in MAIR_EL1, MAIR_EL2, and MAIR_EL3. */
#define PAR_EL1_ATTR_SHIFT          U(56)
#define PAR_EL1_ATTR_MASK           U(0xff)
/* [47:12] PA:              Physical address. 
                            The Physical Address corresponding to the supplied Virtual Address. 
                            Returns address bits[47:12]. */
#define PAR_EL1_PA_SHIFT            U(12)
#define PAR_EL1_PA_MASK             U(0xfffffffff)
/* [9] NS:                  Non-secure. The NS attribute for a translation table entry read from Secure state.
                            This bit is UNKNOWN for a translation table entry from Non-secure state. */
#define PAR_EL1_NS_SHIFT            U(9)
#define PAR_EL1_NS_MASK             U(0x1)
/* [8:7] SHA:               Shareability attribute for the Physical Address returned from a translation table entry. The possible values are:
                                0b00    Non-shareable.
                                0b01    Reserved.
                                0b10    Outer Shareable
                                0b11    Inner Shareable. 
                            Note
                                Takes the value of 0b10 for:
                                • Any type of device memory.
                                • Normal memory with both Inner Non-cacheable and Outer-cacheable attributes. */
#define PAR_EL1_SHA_SHIFT           U(7)
#define PAR_EL1_SHA_MASK            U(0x3)

/* 
 * PAR_El1 fail bit assignments.
 */
/* [9] S:                   Stage of fault. Indicates the state where the translation aborted. The possible values are:
                                0   Translation aborted because of a fault in stage 1 translation.
                                1   Translation aborted because of a fault in stage 2 translation. */
#define PAR_El1_S_SHIFT             U()
#define PAR_El1_S_MASK              U()
/* [8] PTW:                 Indicates a stage 2 fault during a stage 1 table walk. The possible values are:
                                0   No stage 2 fault during a stage 1 table walk.
                                1   Translation aborted because of a stage 2 fault during a stage 1 table walk. */
#define PAR_El1_PTW_SHIFT           U()
#define PAR_El1_PTW_MASK            U()
/* [6:1] FST:               Fault status code, as shown in the Data Abort ESR encoding. 
                            See the Arm® Architecture Reference Manual Armv8, for Armv8-A architecture profile for more information. */
#define PAR_El1_FST_SHIFT           U()
#define PAR_El1_FST_MASK            U()

/* 
 * PAR_El1 common bit assignments.
 */
/* [0] F:                   Pass/Fail bit. 
                            Indicates whether the conversion completed successfully. This value is:
                                0   Virtual Address to Physical Address conversion completed successfully.
                                1   Virtual Address to Physical Address conversion aborted. */
#define PAR_EL1_F_SHIFT             U(0)
#define PAR_EL1_F_MASK              U(0x1)

/****************************************************************************************************
 * AT S1E1R:            Stage 1 current state EL1 read
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S1E1W:            Stage 1 current state EL1 write
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S1E0R:            Stage 1 current state unprivileged read
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S1E0W:            Stage 1 current state unprivileged write
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S1E2R:            Stage 1 Hyp mode read
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S1E2W:            Stage 1 Hyp mode write
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S12E1R:           Stages 1 and 2 Non-secure EL1 read
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S12E1W:           Stages 1 and 2 Non-secure EL1 write
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S12E0R:           Stages 1 and 2 Non-secure unprivileged read
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S12E0W:           Stages 1 and 2 Non-secure unprivileged write
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S1E3R:            Stage 1 current state EL3 read
 ****************************************************************************************************/

/****************************************************************************************************
 * AT S1E3W:            Stage 1 current state EL3 write
 ****************************************************************************************************/

#endif  /* !ADDRESS_TRANSLATION__H__ */
