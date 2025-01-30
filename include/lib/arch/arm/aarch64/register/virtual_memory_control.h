/****************************************************************************************************
 * AArch64 Virtual memory control registers
 ****************************************************************************************************/
#ifndef VIRTUAL_MEMORY_CONTROL__H__
#define VIRTUAL_MEMORY_CONTROL__H__

/****************************************************************************************************
 * SCTLR_EL1:           RW, 32bit, System Control Register, EL1
 ****************************************************************************************************/
/* [26] UCI:                Enables EL0 access to the DC CVAU, DC CIVAC, DC CVAC and IC IVAU instructions in the AArch64 Execution state. 
                            The possible values are:
                                0   EL0 access disabled. This is the reset value.
                                1   EL0 access enabled. */
#define SCTLR_EL1_UCI_SHIFT                 U(26)
#define SCTLR_EL1_UCI_MASK                  U(0x1)
/* [25] EE:                 Exception endianness. The value of this bit controls the endianness for explicit data accesses at EL1. 
                            This value also indicates the endianness of the translation table data for translation table lookups. 
                            The possible values of this bit are:
                                0   Little-endian.
                                1   Big-endian.
                                The reset value of this bit is determined by the CFGEND configuration pin. */
#define SCTLR_EL1_EE_SHIFT                  U(25)
#define SCTLR_EL1_EE_MASK                   U(0x1)
/* [24] E0E:                Endianness of explicit data access at EL0. 
                            The possible values are:
                                0   Explicit data accesses at EL0 are little-endian. This is reset value.
                                1   Explicit data accesses at EL0 are big-endian. */
#define SCTLR_EL1_E0E_SHIFT                 U(24)
#define SCTLR_EL1_E0E_MASK                  U(0x1)
/* [19] WXN:                Write permission implies Execute Never (XN). 
                            This bit can be used to require all memory regions with write permissions to be treated as XN. 
                            The possible values are:
                                0   Regions with write permission are not forced XN. This is the reset value.
                                1   Regions with write permissions are forced XN. */
#define SCTLR_EL1_WXN_SHIFT                 U(19)
#define SCTLR_EL1_WXN_MASK                  U(0x1)
/* [18] nTWE:               WFE non-trapping. 
                            The possible values are:
                                0   A WFE instruction executed at EL0, that, if this bit was set to 1, would permit entry to a low-power state, is trapped to EL1.
                                1   WFE instructions executed as normal. This is the reset value. */
#define SCTLR_EL1_NTWE_SHIFT                U(18)
#define SCTLR_EL1_NTWE_MASK                 U(0x1)
/* [16] nTWI:               WFI non-trapping. 
                            The possible values are:
                                0   A WFI instruction executed at EL0, that, if this bit was set to 1, would permit entry to a low-power state, is trapped to EL1.
                                1   WFI instructions executed as normal. This is the reset value. */
#define SCTLR_EL1_NTWI_SHIFT                U(16)
#define SCTLR_EL1_NTWI_MASK                 U(0x1)
/* [15] UCT:                Enables EL0 access to the CTR_EL0 register in AArch64 Execution state. 
                            The possible values are:
                                0   Disables EL0 access to the CTR_EL0 register. This is the reset value.
                                1   Enables EL0 access to the CTR_EL0 register. */
#define SCTLR_EL1_UCT_SHIFT                 U(15)
#define SCTLR_EL1_UCT_MASK                  U(0x1)
/* [14] DZE:                Enables access to the DC ZVA instruction at EL0. The possible values are:
                                0   Disables execution access to the DC ZVA instruction at EL0.
                                    The instruction is trapped to EL1. This is the reset value.
                                1   Enables execution access to the DC ZVA instruction at EL0. */
#define SCTLR_EL1_DZE_SHIFT                 U(14)
#define SCTLR_EL1_DZE_MASK                  U(0x1)
/* [12] I:                  Instruction cache enable. The possible values are:
                                0   Instruction caches disabled. This is the reset value.
                                1   Instruction caches enabled. */
#define SCTLR_EL1_I_SHIFT                   U(12)
#define SCTLR_EL1_I_MASK                    U(0x1)
/* [9] UMA:                 User Mask Access. Controls access to interrupt masks from EL0, when EL0 is using AArch64. 
                            The possible values of this bit are:
                                0   Disable access to the interrupt masks from EL0.
                                1   Enable access to the interrupt masks from EL0. */
#define SCTLR_EL1_UMA_SHIFT                 U(9)
#define SCTLR_EL1_UMA_MASK                  U(0x1)
/* [8] SED:                 SETEND instruction disable. The possible values are:
                                0   The SETEND instruction is enabled. This is the reset value.
                                1   The SETEND instruction is UNDEFINED. */
#define SCTLR_EL1_SED_SHIFT                 U(8)
#define SCTLR_EL1_SED_MASK                  U(0x1)
/* [7] ITD:                 IT instruction disable. The possible values are:
                                0   The IT instruction functionality is enabled. This is the reset value.
                                1   All encodings of the IT instruction with hw1[3:0]!=1000 are UNDEFINED and treated as
                                    unallocated.All encodings of the subsequent instruction with the following values for hw1 are
                                    UNDEFINED (and treated as unallocated):
                                    11xxxxxxxxxxxxxx
                                        All 32-bit instructions, B(2), B(1), Undefined, SVC, Load/Store multiple
                                    1x11xxxxxxxxxxxx
                                        Miscellaneous 16-bit instructions
                                    1x100xxxxxxxxxxx
                                        ADD Rd, PC, #imm
                                    01001xxxxxxxxxxx
                                        LDR Rd, [PC, #imm]
                                    0100x1xxx1111xxx
                                        ADD(4),CMP(3), MOV, BX pc, BLX pc
                                    010001xx1xxxx111
                                        ADD(4),CMP(3), MOV
                                    Contrary to the standard treatment of conditional UNDEFINED instructions in the Arm
                                    architecture, in this case these instructions are always treated as UNDEFINED, regardless of
                                    whether the instruction would pass or fail its condition codes as a result of being in an IT block. */
#define SCTLR_EL1_ITD_SHIFT                 U(7)
#define SCTLR_EL1_ITD_MASK                  U(0x1)
/* [6] THEE:                RES0 T32EE is not implemented. */
#define SCTLR_EL1_THEE_SHIFT                U(6)
#define SCTLR_EL1_THEE_MASK                 U(0x1)
/* [5] CP15BEN:             CP15 barrier enable. The possible values are:
                                0   CP15 barrier operations disabled. Their encodings are UNDEFINED.
                                1   CP15 barrier operations enabled. This is the reset value. */
#define SCTLR_EL1_CP15BEN_SHIFT             U(5)
#define SCTLR_EL1_CP15BEN_MASK              U(0x1)
/* [4] SA0:                 Enable EL0 stack alignment check. The possible values are:
                                0   Disable EL0 stack alignment check.
                                1   Enable EL0 stack alignment check. This is the reset value. */
#define SCTLR_EL1_SA0_SHIFT                 U(4)
#define SCTLR_EL1_SA0_MASK                  U(0x1)
/* [3] SA:                  Enable SP alignment check. The possible values are:
                                0   Disable SP alignment check.
                                1   Enable SP alignment check. This is the reset value. */
#define SCTLR_EL1_SA_SHIFT                  U(3)
#define SCTLR_EL1_SA_MASK                   U(0x1)
/* [2] C:                   Cache enable. The possible values are:
                                0   Data and unified caches disabled. This is the reset value.
                                1   Data and unified caches enabled. */
#define SCTLR_EL1_C_SHIFT                   U(2)
#define SCTLR_EL1_C_MASK                    U(0x1)
/* [1] A:                   Alignment check enable. The possible values are:
                                0   Alignment fault checking disabled. This is the reset value.
                                1   Alignment fault checking enabled. */
#define SCTLR_EL1_A_SHIFT                   U(1)
#define SCTLR_EL1_A_MASK                    U(0x1)
/* [0] M:                   MMU enable. The possible values are:
                                0   EL1 and EL0 stage 1 MMU disabled. This is the reset value.
                                1   EL1 and EL0 stage 1 MMU enabled. */
#define SCTLR_EL1_M_SHIFT                   U(0)
#define SCTLR_EL1_M_MASK                    U(0x1)

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
 * SCTLR_EL3:           RW, 32bit, System Control Register, EL3
 ****************************************************************************************************/
/* [25] EE:                 Exception endianness. This bit controls the endianness for:
                                • Explicit data accesses at EL3.
                                • Stage 1 translation table walks at EL3.
                            The possible values are:
                                0   Little endian. This is the reset value.
                                1   Big endian. */
#define SCTLR_EL3_EE_SHIFT                  U(25)
#define SCTLR_EL3_EE_MASK                   U(0x1)
/* [19] WXN:                Force treatment of all memory regions with write permissions as XN. The possible values are:
                                0   Regions with write permissions are not forced XN. This is the reset value.
                                1   Regions with write permissions are forced XN. */
#define SCTLR_EL3_WXN_SHIFT                 U(19)
#define SCTLR_EL3_WXN_MASK                  U(0x1)
/* [12] I:                  Global instruction cache enable. The possible values are:
                                0   Instruction caches disabled. This is the reset value.
                                1   Instruction caches enabled. */
#define SCTLR_EL3_I_SHIFT                   U(12)
#define SCTLR_EL3_I_MASK                    U(0x1)
/* [3] SA:                  Enables stack alignment check. The possible values are:
                                0   Disables stack alignment check.
                                1   Enables stack alignment check. This is the reset value. */
#define SCTLR_EL3_SA_SHIFT                  U(3)
#define SCTLR_EL3_SA_MASK                   U(0x1)
/* [2] C:                   Global enable for data and unifies caches. The possible values are:
                                0   Disables data and unified caches. This is the reset value.
                                1   Enables data and unified caches. */
#define SCTLR_EL3_C_SHIFT                   U(2)
#define SCTLR_EL3_C_MASK                    U(0x1)
/* [1] A:                   Enable alignment fault check The possible values are:
                                0   Disables alignment fault checking. This is the reset value.
                                1   Enables alignment fault checking. */
#define SCTLR_EL3_A_SHIFT                   U(1)
#define SCTLR_EL3_A_MASK                    U(0x1)
/* [0] M:                   Global enable for the EL3 MMU. The possible values are:
                                0   Disables EL3 MMU. This is the reset value.
                                1   Enables EL3 MMU. */
#define SCTLR_EL3_M_SHIFT                   U(0)
#define SCTLR_EL3_M_MASK                    U(0x1)

/****************************************************************************************************
 * TTBR0_EL1:           RW, 64bit, Translation Table Base Register 0, EL1
 ****************************************************************************************************/
/* [63:48] ASID:            An ASID for the translation table base address. 
                            The TCR_EL1.A1 field selects either TTBR0_EL1.ASID or TTBR1_EL1.ASID. */
#define TTBR0_EL1_ASID_SHIFT                U(48)
#define TTBR0_EL1_ASID_MASK                 U(0xffff)
/* [47:0] BADDR[47:x]:      Translation table base address, bits[47:x]. Bits [x-1:0] are RES0.
                            x is based on the value of TCR_EL1.T0SZ, the stage of translation, and the memory translation granule size.
                            For instructions on how to calculate it, see the Arm® Architecture Reference Manual Armv8, for Armv8-A architecture profile
                            The value of x determines the required alignment of the translation table, that must be aligned to 2x bytes.
                            If bits [x-1:0] are not all zero, this is a misaligned Translation Table Base Address.
                            Its effects are CONSTRAINED UNPREDICTABLE, where bits [x-1:0] are treated as if all the bits are zero.
                            The value read back from those bits is the value written. */
#define TTBR0_EL1_BADDR_SHIFT               U(0xffffffffffff)
#define TTBR0_EL1_BADDR_MASK                U(0)

/****************************************************************************************************
 * TTBR1_EL1:           RW, 64bit, Translation Table Base Register 1, EL1
 ****************************************************************************************************/
/* [63:48] ASID:            An ASID for the translation table base address. 
                            The TCR_EL1.A1 field selects either TTBR0_EL1.ASID or TTBR1_EL1.ASID. */
#define TTBR1_EL1_ASID_SHIFT                U(48)
#define TTBR1_EL1_ASID_MASK                 U(0xffff)
/* [47:0] BADDR[47:x]:      Translation table base address, bits[47:x]. Bits [x-1:0] are RES0.
                            x is based on the value of TCR_EL1.T0SZ, the stage of translation, and the memory translation granule size.
                            For instructions on how to calculate it, see the Arm® Architecture Reference Manual Armv8, for Armv8-A architecture profile.
                            The value of x determines the required alignment of the translation table, that must be aligned to 2x bytes.
                            If bits [x-1:0] are not all zero, this is a misaligned Translation Table Base Address. 
                            Its effects are CONSTRAINED UNPREDICTABLE, where bits [x-1:0] are treated as if all the bits are zero. 
                            The value read back from those bits is the value written. */
#define TTBR1_EL1_BADDR_SHIFT               U(0xffffffffffff)
#define TTBR1_EL1_BADDR_MASK                U(0)

/****************************************************************************************************
 * TCR_EL1:             RW, 64bit, Translation Control Register, EL1
 ****************************************************************************************************/
/* [38] TBI1:               Top Byte Ignored. 
                            Indicates whether the top byte of the input address is used for address match for the TTBR1_EL1 region. The possible values are:
                                0   Top byte used in the address calculation.
                                1   Top byte ignored in the address calculation. */
#define TCR_EL1_TBI1_SHIFT                  U(38)
#define TCR_EL1_TBI1_MASK                   U(0x1)
/* [37] TBI0:               Top Byte Ignored. Indicates whether the top byte of the input address is used for address match for the TTBR0_EL1 region. 
                            The possible values are:
                                0   Top byte used in the address calculation.
                                1   Top byte ignored in the address calculation. */
#define TCR_EL1_TBI0_SHIFT                  U(37)
#define TCR_EL1_TBI0_MASK                   U(0x1)
/* [36] AS:                 ASID size. The possible values are:
                                0   8-bit.
                                1   16-bit. */
#define TCR_EL1_AS_SHIFT                    U(36)
#define TCR_EL1_AS_MASK                     U(0x1)
/* [34:32] IPS:             Intermediate Physical Address Size. The possible values are:
                                0b000   32 bits, 4GB.
                                0b001   36 bits, 64GB.
                                0b010   40 bits, 1TB.
                                All other values are reserved. */
#define TCR_EL1_IPS_SHIFT                   U(32)
#define TCR_EL1_IPS_MASK                    U(0x7)
/* [31:30] TG1:             TTBR1_EL1 granule size. The possible values are:
                                0b00    Reserved.
                                0b10    4KB.
                                0b11    64KB.
                                All other values are not supported. */
#define TCR_EL1_TG1_SHIFT                   U(30)
#define TCR_EL1_TG1_MASK                    U(0x3)
/* [29:28] SH1:             Shareability attribute for memory associated with translation table walks using TTBR1_EL1. 
                            The possible values are:
                                0b00    Non-shareable.
                                0b01    Reserved.
                                0b10    Outer shareable.
                                0b11    Inner shareable. */
#define TCR_EL1_SH1_SHIFT                   U(28)
#define TCR_EL1_SH1_MASK                    U(0x3)
/* [27:26] ORGN1:           Outer cacheability attribute for memory associated with translation table walks using TTBR1_EL1. 
                            The possible values are:
                                0b00    Normal memory, Outer Non-cacheable.
                                0b01    Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Outer Write-Through Cacheable.
                                0b11    Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
#define TCR_EL1_ORGN1_SHIFT                 U(26)
#define TCR_EL1_ORGN1_MASK                  U(0x3)
/* [25:24] IRGN1:           Inner cacheability attribute for memory associated with translation table walks using TTBR1_EL1. 
                            The possible values are:
                                0b00    Normal memory, Inner Non-cacheable.
                                0b01    Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Inner Write-Through Cacheable.
                                0b11    Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
#define TCR_EL1_IRGN1_SHIFT                 U(24)
#define TCR_EL1_IRGN1_MASK                  U(0x3)
/* [23] EPD1:               Translation table walk disable for translations using TTBR1_EL1. 
                            Controls whether a translation table walk is performed on a TLB miss for an address that is translated using TTBR1_EL1. 
                            The possible values are:
                                0   Perform translation table walk using TTBR1_EL1.
                                1   A TLB miss on an address translated from TTBR1_EL1 generates a Translation fault. 
                                    No translation table walk is performed. */
#define TCR_EL1_EPD1_SHIFT                  U(23)
#define TCR_EL1_EPD1_MASK                   U(0x1)
/* [22] A1:                 Selects whether TTBR0_EL1 or TTBR1_EL1 defines the ASID. The possible values are:
                                0   TTBR0_EL1.ASID defines the ASID.
                                1   TTBR1_EL1.ASID defines the ASID. */
#define TCR_EL1_A1_SHIFT                    U(22)
#define TCR_EL1_A1_MASK                     U(0x1)
/* [21:16] T1SZ:            Size offset of the memory region addressed by TTBR1_EL1. 
                            The region size is 2^(64-T1SZ) bytes. */
#define TCR_EL1_T1SZ_SHIFT                  U(16)
#define TCR_EL1_T1SZ_MASK                   U(0x3f)
/* [15:14] TG0:             TTBR0_EL1 granule size. The possible values are:
                                0b00    4KB.
                                0b01    64KB.
                                0b11    Reserved.
                                All other values are not supported. */
#define TCR_EL1_TG0_SHIFT                   U(14)
#define TCR_EL1_TG0_MASK                    U(0x3)
/* [13:12] SH0:             Shareability attribute for memory associated with translation table walks using TTBR0_EL1. 
                            The possible values are:
                                0b00    Non-shareable.
                                0b01    Reserved.
                                0b10    Outer shareable.
                                0b11    Inner shareable. */
#define TCR_EL1_SH0_SHIFT                   U(12)
#define TCR_EL1_SH0_MASK                    U(0x3)
/* [11:10] ORGN0:           Outer cacheability attribute for memory associated with translation table walks using TTBR0_EL1. 
                            The possible values are:
                                0b00    Normal memory, Outer Non-cacheable.
                                0b01    Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Outer Write-Through Cacheable.
                                0b11    Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
#define TCR_EL1_ORGN0_SHIFT                 U(10)
#define TCR_EL1_ORGN0_MASK                  U(0x3)
/* [9:8] IRGN0:             Inner cacheability attribute for memory associated with translation table walks using TTBR0_EL1. 
                            The possible values are:
                                0b00    Normal memory, Inner Non-cacheable.
                                0b01    Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Inner Write-Through Cacheable.
                                0b11    Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
#define TCR_EL1_IRGN0_SHIFT                 U(8)
#define TCR_EL1_IRGN0_MASK                  U(0x3)
/* [7] EPD0:                Translation table walk disable for translations using TTBR0_EL1. 
                            Controls whether a translation table walk is performed on a TLB miss for an address that is translated using TTBR0_EL1. 
                            The possible values are:
                                0   Perform translation table walk using TTBR0_EL1.
                                1   A TLB miss on an address translated from TTBR0_EL1 generates a Translation fault. 
                                    No translation table walk is performed. */
#define TCR_EL1_EPD0_SHIFT                  U(7)
#define TCR_EL1_EPD0_MASK                   U(0x1)
/* [5:0] T0SZ:              Size offset of the memory region addressed by TTBR0_EL1. 
                            The region size is 2^(64-T0SZ) bytes. */
#define TCR_EL1_T0SZ_SHIFT                  U(0)
#define TCR_EL1_T0SZ_MASK                   U(0x3f)

/****************************************************************************************************
 * TTBR0_EL2:           RW, 64bit, Translation Table Base Address Register 0, EL2
 ****************************************************************************************************/

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
 * TTBR0_EL3:           RW, 64bit, Translation Table Base Register 0, EL3
 ****************************************************************************************************/
/* [47:0] BADDR[47:x]:      Translation table base address, bits[47:x]. Bits [x-1:0] are RES0.
                            x is based on the value of TCR_EL1.T0SZ, the stage of translation, and the memory translation granule size.
                            For instructions on how to calculate it, see the Arm® Architecture Reference Manual Armv8, for Armv8-A architecture profile.
                            The value of x determines the required alignment of the translation table, that must be aligned to 2x bytes.
                            If bits [x-1:0] are not all zero, this is a misaligned Translation Table Base Address.
                            Its effects are CONSTRAINED UNPREDICTABLE, where bits [x-1:0] are treated as if all the bits are zero. 
                            The value read back from those bits is the value written. */
#define TTBR0_EL3_BADDR_SHIFT       U(0)
#define TTBR0_EL3_BADDR_MASK        U(0xffffffffffff)


/****************************************************************************************************
 * TCR_EL3:             RW, 32bit, Translation Control Register, EL3
 ****************************************************************************************************/
/* [20] TBI:                Top Byte Ignored. 
                            Indicates whether the top byte of the input address is used for address match.
                            The possible values are:
                                0   Top byte used in the address calculation.
                                1   Top byte ignored in the address calculation. */
#define TCR_EL3_TBI_SHIFT           U(20)
#define TCR_EL3_TBI_MASK            U(0x1)
/* [18:16] PS:              Physical address size. The possible values are:
                                0b000   32 bits, 4 GB.
                                0b001   36 bits, 64 GB.
                                0b010   40 bits, 1 TB.
                                Other values are reserved. */
#define TCR_EL3_PS_SHIFT            U(16)
#define TCR_EL3_PS_MASK             U()
/* [15:14] TG0:             TTBR0_EL3 granule size. The possible values are:
                                0b00    4 KB.
                                0b01    64 KB.
                                0b11    Reserved.
                                All other values are not supported. */
#define TCR_EL3_TG0_SHIFT           U(14)
#define TCR_EL3_TG0_MASK            U(0x3)
/* [13:12] SH0:             Shareability attribute for memory associated with translation table walks using TTBR0_EL3.
                                The possible values are:
                                0b00    Non-shareable.
                                0b01    Reserved.
                                0b10    Outer shareable.
                                0b11    Inner shareable. */
#define TCR_EL3_SH0_SHIFT           U(12)
#define TCR_EL3_SH0_MASK            U(0x3)
/* [11:10] ORGN0:           Outer cacheability attribute for memory associated with translation table walks using TTBR0_EL3.
                            The possible values are:
                                0b00    Normal memory, Outer Non-cacheable.
                                0b01    Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Outer Write-Through Cacheable.
                                0b11    Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
#define TCR_EL3_ORGN0_SHIFT         U(10)
#define TCR_EL3_ORGN0_MASK          U(0x3)
/* [9:8] IRGN0:             Inner cacheability attribute for memory associated with translation table walks using TTBR0_EL3.
                            The possible values are:
                                0b00    Normal memory, Inner Non-cacheable.
                                0b01    Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                0b10    Normal memory, Inner Write-Through Cacheable.
                                0b11    Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
#define TCR_EL3_IRGN0_SHIFT         U(8)
#define TCR_EL3_IRGN0_MASK          U(0x3)
/* [5:0] T0SZ:              Size offset of the memory region addressed by TTBR0_EL3. The region size is 2^(64-T0SZ) bytes. */
#define TCR_EL3_T0SZ_SHIFT          U(0)
#define TCR_EL3_T0SZ_MASK           U(0x3f)

/****************************************************************************************************
 * MAIR_EL1:            RW, 64bit, Memory Attribute Indirection Register, EL1
 ****************************************************************************************************/
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
#define MAIR_EL1_ATTR7_SHIFT        U(56)
#define MAIR_EL1_ATTR7_MASK         U(0xff)
/* [55:48] Attr6: */
#define MAIR_EL1_ATTR6_SHIFT        U(48)
#define MAIR_EL1_ATTR6_MASK         U(0xff)
/* [47:40] Attr5: */
#define MAIR_EL1_ATTR5_SHIFT        U(40)
#define MAIR_EL1_ATTR5_MASK         U(0xff)
/* [39:32] Attr4: */
#define MAIR_EL1_ATTR4_SHIFT        U(32)
#define MAIR_EL1_ATTR4_MASK         U(0xff)
/* [31:24] Attr3: */
#define MAIR_EL1_ATTR3_SHIFT        U(24)
#define MAIR_EL1_ATTR3_MASK         U(0xff)
/* [23:16] Attr2: */
#define MAIR_EL1_ATTR2_SHIFT        U(16)
#define MAIR_EL1_ATTR2_MASK         U(0xff)
/* [15:8] Attr1: */
#define MAIR_EL1_ATTR1_SHIFT        U(8)
#define MAIR_EL1_ATTR1_MASK         U(0xff)
/* [7:0] Attr0: */
#define MAIR_EL1_ATTR0_SHIFT        U(0)
#define MAIR_EL1_ATTR0_MASK         U(0xff)

/****************************************************************************************************
 * AMAIR_EL1:           RW, 64bit, Auxiliary Memory Attribute Indirection Register, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AMAIR_EL1, therefore these registers are always RES0. */

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
 * MAIR_EL3:            RW, 64bit, Memory Attribute Indirection Register, EL3
 ****************************************************************************************************/
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
#define MAIR_EL3_ATTR7_SHIFT        U(56)
#define MAIR_EL3_ATTR7_MASK         U(0xff)
/* [55:48] Attr6: */
#define MAIR_EL3_ATTR6_SHIFT        U(48)
#define MAIR_EL3_ATTR6_MASK         U(0xff)
/* [47:40] Attr5: */
#define MAIR_EL3_ATTR5_SHIFT        U(40)
#define MAIR_EL3_ATTR5_MASK         U(0xff)
/* [39:32] Attr4: */
#define MAIR_EL3_ATTR4_SHIFT        U(32)
#define MAIR_EL3_ATTR4_MASK         U(0xff)
/* [31:24] Attr3: */
#define MAIR_EL3_ATTR3_SHIFT        U(24)
#define MAIR_EL3_ATTR3_MASK         U(0xff)
/* [23:16] Attr2: */
#define MAIR_EL3_ATTR2_SHIFT        U(16)
#define MAIR_EL3_ATTR2_MASK         U(0xff)
/* [15:8] Attr1: */
#define MAIR_EL3_ATTR1_SHIFT        U(8)
#define MAIR_EL3_ATTR1_MASK         U(0xff)
/* [7:0] Attr0: */
#define MAIR_EL3_ATTR0_SHIFT        U(0)
#define MAIR_EL3_ATTR0_MASK         U(0xff)

/****************************************************************************************************
 * AMAIR_EL3:           RW, 64bit, Auxiliary Memory Attribute Indirection Register, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AMAIR_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * CONTEXTIDR_EL1:      RW, 32bit, Context ID Register, EL1
 ****************************************************************************************************/
/* Unknown in 'DDI0500J_cortex_a53_trm.pdf' */

#endif  /* !VIRTUAL_MEMORY_CONTROL__H__ */
