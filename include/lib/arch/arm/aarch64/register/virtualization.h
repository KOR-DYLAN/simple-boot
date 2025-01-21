/****************************************************************************************************
 * AArch64 virtualization registers
 ****************************************************************************************************/
#ifndef VIRTUALIZATION__H__
#define VIRTUALIZATION__H__

/****************************************************************************************************
 * VPIDR_EL2:           RW, 32bit, Virtualization Processor ID Register
 ****************************************************************************************************/

/****************************************************************************************************
 * VMPIDR_EL2:          RW, 64bit, Virtualization Multiprocessor ID Register
 ****************************************************************************************************/

/****************************************************************************************************
 * SCTLR_EL2:           RW, 32bit, System Control Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * ACTLR_EL2:           RW, 32bit, Auxiliary Control Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * HCR_EL2:             RW, 64bit, Hypervisor Configuration Register
 ****************************************************************************************************/

/****************************************************************************************************
 * MDCR_EL2:            RW, 32bit, Hyp Debug Control Register
 ****************************************************************************************************/

/****************************************************************************************************
 * CPTR_EL2:            RW, 32bit, Architectural Feature Trap Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * HSTR_EL2:            RW, 32bit, Hyp System Trap Register
 ****************************************************************************************************/

/****************************************************************************************************
 * HACR_EL2:            RW, 32bit, Hyp Auxiliary Configuration Register
 ****************************************************************************************************/

/****************************************************************************************************
 * TTBR0_EL2:           RW, 64bit, Translation Table Base Address Register 0, EL3
 ****************************************************************************************************/

/****************************************************************************************************
 * TCR_EL2:             RW, 32bit, Translation Control Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * VTTBR_EL2:           RW, 64bit, Virtualization Translation Table Base Address Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * VTCR_EL2:            RW, 32bit, Virtualization Translation Control Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * DACR32_EL2:          RW, 32bit, Domain Access Control Register
 ****************************************************************************************************/

/****************************************************************************************************
 * AFSR0_EL2:           RW, 32bit, Auxiliary Fault Status Register 0, EL1, EL2 and EL3
 ****************************************************************************************************/

/****************************************************************************************************
 * AFSR1_EL2:           RW, 32bit, Auxiliary Fault Status Register 1, EL1, EL2 and EL3
 ****************************************************************************************************/

/****************************************************************************************************
 * ESR_EL2:             RW, 32bit, Exception Syndrome Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * ESR_EL2:             RW, 64bit, Fault Address Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * HPFAR_EL2:           RW, 64bit, Hypervisor IPA Fault Address Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * MAIR_EL2:            RW, 64bit, Memory Attribute Indirection Register, EL2
 ****************************************************************************************************/

/****************************************************************************************************
 * AMAIR_EL2:           RW, 64bit, Auxiliary Memory Attribute Indirection Register, EL1, EL2 and EL3
 ****************************************************************************************************/

/****************************************************************************************************
 * VBAR_EL2:            RW, 64bit, Vector Base Address Register, EL2
 ****************************************************************************************************/

#endif  /* !VIRTUALIZATION__H__ */
