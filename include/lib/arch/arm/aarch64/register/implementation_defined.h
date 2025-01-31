/****************************************************************************************************
 * AArch64 implementation defined registers
 ****************************************************************************************************/
#ifndef IMPLEMENTATION_DEFINED__H__
#define IMPLEMENTATION_DEFINED__H__

/****************************************************************************************************
 * ACTLR_EL1:           RW, 32bit, Auxiliary Control Register, EL1
 ****************************************************************************************************/
/* The processor does not implement the ACTLR_EL1 register. This register is always RES0 */

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
 * AFSR0_EL1:           RW, 32bit, Auxiliary Fault Status Register 0, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR0_EL1, AFSR0_EL2 and AFSR0_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AFSR1_EL1:           RW, 32bit, Auxiliary Fault Status Register 1, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR1_EL1, AFSR1_EL2 and AFSR1_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AFSR0_EL2:           RW, 32bit, Auxiliary Fault Status Register 0, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR0_EL1, AFSR0_EL2 and AFSR0_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AFSR1_EL2:           RW, 32bit, Auxiliary Fault Status Register 1, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR1_EL1, AFSR1_EL2 and AFSR1_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AFSR0_EL3:           RW, 32bit, Auxiliary Fault Status Register 0, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR0_EL1, AFSR0_EL2 and AFSR0_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AFSR1_EL3:           RW, 32bit, Auxiliary Fault Status Register 1, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AFSR1_EL1, AFSR1_EL2 and AFSR1_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * AMAIR_EL1:           RW, 64bit, Auxiliary Memory Attribute Indirection Register, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AMAIR_EL1, therefore these registers are always RES0. */

/****************************************************************************************************
 * AMAIR_EL2:           RW, 64bit, Auxiliary Memory Attribute Indirection Register, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AMAIR_EL2, therefore these registers are always RES0. */

/****************************************************************************************************
 * AMAIR_EL3:           RW, 64bit, Auxiliary Memory Attribute Indirection Register, EL1, EL2 and EL3
 ****************************************************************************************************/
/* The processor does not implement AMAIR_EL3, therefore these registers are always RES0. */

/****************************************************************************************************
 * L2CTLR_EL1:          RW, 32bit, L2 Control Register
 ****************************************************************************************************/
/* [25:24] Number of cores:         Number of cores present:
                                        0b00    One core, core 0.
                                        0b01    Two cores, core 0 and core 1.
                                        0b10    Three cores, cores 0 to 2.
                                        0b11    Four cores, cores 0 to 3.
                                        The value of this field is fixed during implementation. All writes to this field are ignored. */
#define L2CTLR_EL1_NUMBER_OF_CORES_SHIFT                U(24)
#define L2CTLR_EL1_NUMBER_OF_CORES_MASK                 U(0x3)
/* [22] CPU Cache Protection:       CPU Cache Protection. Core RAMs are implemented:
                                        0   Without ECC.
                                        1   With ECC.
                                        The value of this field is fixed during implementation. All writes to this field are ignored. */
#define L2CTLR_EL1_CPU_CACHE_PROTECTION_SHIFT           U(22)
#define L2CTLR_EL1_CPU_CACHE_PROTECTION_MASK            U0x1()
/* [21] SCU-L2 Cache Protection:    SCU-L2 Cache Protection. L2 cache is implemented:
                                        0   Without ECC.
                                        1   With ECC.
                                        The value of this field is fixed during implementation. All writes to this field are ignored. */
#define L2CTLR_EL1_SCU_L2_CACHE_PROTECTION_SHIFT        U(21)
#define L2CTLR_EL1_SCU_L2_CACHE_PROTECTION_MASK         U(0x1)
/* [5] L2 data RAM input latency:   L2 data RAM input latency:
                                        0   1-cycle input delay from L2 data RAMs.
                                        1   2-cycle input delay from L2 data RAMs.
                                        The value of this field is fixed during implementation. All writes to this field are ignored. */
#define L2CTLR_EL1_L2_DATA_RAM_INPUT_LATENCY_SHIFT      U(5)
#define L2CTLR_EL1_L2_DATA_RAM_INPUT_LATENCY_MASK       U(0x1)
/* [0] L2 data RAM output latency:  L2 data RAM output latency:
                                        0   2-cycle output delay from L2 data RAMs.
                                        1   3-cycle output delay from L2 data RAMs.
                                        The value of this field is fixed during implementation. All writes to this field are ignored. */
#define L2CTLR_EL1_L2_DATA_RAM_OUTPUT_LATENCY_SHIFT     U(0)
#define L2CTLR_EL1_L2_DATA_RAM_OUTPUT_LATENCY_MASK      U(0x1)

/****************************************************************************************************
 * L2ECTLR_EL1:         RW, 32bit, L2 Extended Control Register
 ****************************************************************************************************/
/* [30] L2 internal asynchronous error:     L2 internal asynchronous error caused by L2 RAM double-bit ECC error. 
                                            The possible values are:
                                                0   No pending asynchronous error. This is the reset value.
                                                1   An asynchronous error has occurred.
                                                A write of 0 clears this bit and drives nINTERRIRQ HIGH. 
                                                A write of 1 is ignored. */
#define L2ECTLR_EL1_L2_INTERNAL_ASYNCHRONOUS_ERROR_SHIFT    U(30)
#define L2ECTLR_EL1_L2_INTERNAL_ASYNCHRONOUS_ERROR_MASK     U(0x1)
/* [29] AXI or CHI asynchronous error:      AXI or CHI asynchronous error indication. The possible values are:
                                                0   No pending asynchronous error.
                                                1   An asynchronous error has occurred.
                                                A write of 0 clears this bit and drives nEXTERRIRQ HIGH. 
                                                A write of 1 is ignored. */
#define L2ECTLR_EL1_AXI_OR_CHI_ASYNCHRONOUS_ERROR_SHIFT     U(29)
#define L2ECTLR_EL1_AXI_OR_CHI_ASYNCHRONOUS_ERROR_MASK      U(0x1)
/* [2:0] L2 dynamic retention control:      L2 dynamic retention control. The possible values are:
                                                0b000   L2 dynamic retention disabled. This is the reset value.
                                                0b001   2 Generic Timer ticks required before retention entry.
                                                0b010   8 Generic Timer ticks required before retention entry.
                                                0b011   32 Generic Timer ticks required before retention entry.
                                                0b100   64 Generic Timer ticks required before retention entry.
                                                0b101   128 Generic Timer ticks required before retention entry.
                                                0b110   256 Generic Timer ticks required before retention entry.
                                                0b111   512 Generic Timer ticks required before retention entry. 
                                            Note
                                                Software must not rely on retention state entry 
                                                when the system counter is in low-power modes 
                                                where CNTVALUEB increments are greater than 1. 
                                                Entry to retention state relies on the system counter increments being +1.*/
#define L2ECTLR_EL1_L2_DYNAMIC_RETENTION_CONTROL_SHIFT      U(0)
#define L2ECTLR_EL1_L2_DYNAMIC_RETENTION_CONTROL_MASK       U(0x7)

/****************************************************************************************************
 * L2ACTLR_EL1:         RW, 32bit, L2 Auxiliary Control Register, EL1
 ****************************************************************************************************/
/* [29] L2DEIEN:                                L2 cache data RAM error injection enable. The possible values are:
                                                    0   Normal behavior, errors are not injected. This is the reset value.
                                                    1   Double-bit errors are injected on all writes to the L2 cache data RAMs. */
#define L2ACTLR_EL1_L2DEIEN_SHIFT                                   U(29)
#define L2ACTLR_EL1_L2DEIEN_MASK                                    U(0x1)
/* [24] L2TEIEN:                                L2 cache tag RAM error injection enable. The possible values are:
                                                    0   Normal behavior, errors are not injected. This is the reset value.
                                                    1   Double-bit errors are injected on all writes to the L2 cache tag RAMs. */
#define L2ACTLR_EL1_L2TEIEN_SHIFT                                   U(24)
#define L2ACTLR_EL1_L2TEIEN_MASK                                    U(0x1)
/* [14] Enable UniqueClean evictions with data: Enables sending of WriteEvict transactions for UniqueClean evictions with data.
                                                WriteEvict transactions update downstream caches that are outside the cluster. 
                                                Enable WriteEvict transactions only if there is an L3 or system cache implemented in the system.
                                                The possible values are:
                                                    0   Disables UniqueClean evictions with data. This is the reset value for ACE.
                                                    1   Enables UniqueClean evictions with data. This is the reset value for CHI. 
                                                Note
                                                    Some ACE interconnects might not support the WriteEvict transaction. 
                                                    You must not enable this bit if your interconnect does not support WriteEvict transactions.*/
#define L2ACTLR_EL1_ENABLE_UNIQUE_CLEAN_EVICTIONS_WITH_DATA_SHIFT   U(14)
#define L2ACTLR_EL1_ENABLE_UNIQUE_CLEAN_EVICTIONS_WITH_DATA_MASK    U(0x1)
/* [3] Disable clean/evict push to external:    Disables sending of Evict transactions for clean cache lines that are evicted from the processor.
                                                This is required only if the external interconnect contains a snoop filter that requires notification when the processor evicts the cache line. 
                                                The possible values are:
                                                    0   Enables clean/evict to be pushed out to external. This is the reset value for ACE.
                                                    1   Disables clean/evict from being pushed to external. This is the reset value for CHI. */
#define L2ACTLR_EL1_DISABLE_CLEAN_EVICT_PUSH_TO_EXTERNAL_SHIFT      U(3)
#define L2ACTLR_EL1_DISABLE_CLEAN_EVICT_PUSH_TO_EXTERNAL_MASK       U(0x1)

/****************************************************************************************************
 * CPUACTLR_EL1:        RW, 64bit, CPU Auxiliary Control Register, EL1
 ****************************************************************************************************/
/* [44] ENDCCASCI:                              Enable data cache clean as data cache clean/invalidate. The possible values are:
                                                    0   Normal behavior, data cache clean operations are unaffected. This is the reset value.
                                                    1   Executes data cache clean operations as data cache clean and invalidate. 
                                                        The following operations are affected:
                                                        • In AArch32, DCCSW is executed as DCCISW, DCCMVAU and DCCMVAC are executed as DCCIMVAC.
                                                        • In AArch64, DC CSW is executed as DC CISW, DC CVAU and DC CVAC are executed as DC CIVAC. */
#define CPUACTLR_EL1_ENDCCASCI_SHIFT                                U(44)
#define CPUACTLR_EL1_ENDCCASCI_MASK                                 U(0x1)
/* [30] FPDIDIS:                                Disable floating-point dual issue. The possible values are:
                                                    0   Enable dual issue of floating-point, Advanced SIMD and Cryptography instructions. This is the reset value.
                                                    1   Disable dual issue of floating-point, Advanced SIMD and Cryptography instructions. */
#define CPUACTLR_EL1_FPDIDIS_SHIFT                                  U(30)
#define CPUACTLR_EL1_FPDIDIS_MASK                                   U(0x1)
/* [29] DIDIS:                                  Disable Dual Issue. The possible values are:
                                                    0   Enable Dual Issue of instructions. This is the reset value.
                                                    1   Disable Dual Issue of all instructions. */
#define CPUACTLR_EL1_DIDIS_SHIFT                                    U(29)
#define CPUACTLR_EL1_DIDIS_MASK                                     U(0x1)
/* [28:27] RADIS:                               Write streaming no-allocate threshold. The possible values are:
                                                    0b00    16th consecutive streaming cache line does not allocate in the L1 or L2 cache.
                                                    0b01    128th consecutive streaming cache line does not allocate in the L1 or L2 cache. This is the reset value.
                                                    0b10    512th consecutive streaming cache line does not allocate in the L1 or L2 cache.
                                                    0b11    Disables streaming. All write-allocate lines allocate in the L1 or L2 cache. */
#define CPUACTLR_EL1_RADIS_SHIFT                                    U(27)
#define CPUACTLR_EL1_RADIS_MASK                                     U(0x3)
/* [26:25] L1RADIS:                             Write streaming no-L1-allocate threshold. The possible values are:
                                                    0b00    4th consecutive streaming cache line does not allocate in the L1 cache. This is the reset value.
                                                    0b01    64th consecutive streaming cache line does not allocate in the L1 cache.
                                                    0b10    128th consecutive streaming cache line does not allocate in the L1 cache.
                                                    0b11    Disables streaming. All write-allocate lines allocate in the L1 cache. */
#define CPUACTLR_EL1_L1RADIS_SHIFT                                  U(25)
#define CPUACTLR_EL1_L1RADIS_MASK                                   U(0x3)
/* [24] DTAH:                                   Disable transient and no-read-allocate hints for loads. The possible values are:
                                                    0   Normal operation.
                                                    1   Transient and no-read-allocate hints in the MAIR are ignored and treated the same as non-transient, read-allocate types for loads. 
                                                        The LDNP instruction in AArch64 behaves the same as the equivalent LDP instruction. This is the reset value. */
#define CPUACTLR_EL1_DTAH_SHIFT                                     U(24)
#define CPUACTLR_EL1_DTAH_MASK                                      U(0x1)
/* [23] STBPFRS:                                Disable ReadUnique request for prefetch streams initiated by STB accesses:
                                                    0   ReadUnique used for prefetch streams initiated from STB accesses. This is the reset value.
                                                    1   ReadShared used for prefetch streams initiated from STB accesses. */
#define CPUACTLR_EL1_STBPFRS_SHIFT                                  U(23)
#define CPUACTLR_EL1_STBPFRS_MASK                                   U(0x1)
/* [22] STBPFDIS:                               Disable prefetch streams initiated from STB accesses:
                                                    0   Enable Prefetch streams initiated from STB accesses. This is the reset value.
                                                    1   Disable Prefetch streams initiated from STB accesses. */
#define CPUACTLR_EL1_STBPFDIS_SHIFT                                 U(22)
#define CPUACTLR_EL1_STBPFDIS_MASK                                  U(0x1)
/* [21] IFUTHDIS:                               IFU fetch throttle disabled. The possible values are:
                                                    0   Fetch throttle enabled. This is the reset value.
                                                    1   Fetch throttle disabled. This setting increases power consumption. */
#define CPUACTLR_EL1_IFUTHDIS_SHIFT                                 U(21)
#define CPUACTLR_EL1_IFUTHDIS_MASK                                  U(0x1)
/* [20:19] NPFSTRM:                             Number of independent data prefetch streams. The possible values are:
                                                    0b00    1 stream.
                                                    0b01    2 streams. This is the reset value.
                                                    0b10    3 streams.
                                                    0b11    4 streams. */
#define CPUACTLR_EL1_NPFSTRM_SHIFT                                  U(19)
#define CPUACTLR_EL1_NPFSTRM_MASK                                   U(0x3)
/* [18] DSTDIS:                                 Enable device split throttle. The possible values are:
                                                    0   Device split throttle disabled.
                                                    1   Device split throttle enabled. This is the reset value. */
#define CPUACTLR_EL1_DSTDIS_SHIFT                                   U(18)
#define CPUACTLR_EL1_DSTDIS_MASK                                    U(0x1)
/* [17] STRIDE:                                 Configure the sequence length that triggers data prefetch streams. The possible values are:
                                                    0   2 linefills to consecutive cache lines triggers prefetch. This is the reset value.
                                                    1   3 linefills to consecutive cache lines triggers prefetch.
                                                In both configurations, Three linefills with a fixed stride pattern are required to trigger prefetch, 
                                                if the stride spans more than one cache line. */
#define CPUACTLR_EL1_STRIDE_SHIFT                                   U(17)
#define CPUACTLR_EL1_STRIDE_MASK                                    U(0x1)
/* [15:13] L1PCTL:                              L1 Data prefetch control.
                                                The value of this field determines the maximum number of outstanding data prefetches allowed in the L1 memory system,
                                                excluding those generated by software load or PLD instructions. The possible values are:
                                                    0b000   Prefetch disabled.
                                                    0b001   1 outstanding prefetch allowed.
                                                    0b010   2 outstanding prefetches allowed.
                                                    0b011   3 outstanding prefetches allowed.
                                                    0b100   4 outstanding prefetches allowed.
                                                    0b101   5 outstanding prefetches allowed. This is the reset value.
                                                    0b110   6 outstanding prefetches allowed.
                                                    0b111   8 outstanding prefetches allowed. */
#define CPUACTLR_EL1_L1PCTL_SHIFT                                   U(13)
#define CPUACTLR_EL1_L1PCTL_MASK                                    U(0x7)
/* [10] DODMBS:                                 Disable optimized Data Memory Barrier behavior. The possible values are:
                                                    0   Enable optimized Data Memory Barrier behavior. This is the reset value.
                                                    1   Disable optimized Data Memory Barrier behavior. */
#define CPUACTLR_EL1_DODMBS_SHIFT                                   U(10)
#define CPUACTLR_EL1_DODMBS_MASK                                    U(0x1)
/* [6] L1DEIEN:                                 L1 D-cache data RAM error injection enable. The possible values are:
                                                    0   Normal behavior, errors are not injected. This is the reset value.
                                                    1   Double-bit errors are injected on all writes to the L1 D-cache data RAMs for the first word of each 32-byte region. */
#define CPUACTLR_EL1_L1DEIEN_SHIFT                                  U(6)
#define CPUACTLR_EL1_L1DEIEN_MASK                                   U(0x1)

/****************************************************************************************************
 * CPUECTLR_EL1:        RW, 64bit, CPU Extended Control Register, EL1
 ****************************************************************************************************/
/* [6] SMPEN:                                   Enable hardware management of data coherency with other cores in the cluster. The possible values are:
                                                    0   Disables data coherency with other cores in the cluster. This is the reset value.
                                                    1   Enables data coherency with other cores in the cluster. 
                                                Note
                                                    Set the SMPEN bit before enabling the caches, even if there is only one core in the system.*/
#define CPUECTLR_EL1_SMPEN_SHIFT                                    U(6)
#define CPUECTLR_EL1_SMPEN_MASK                                     U(0x1)
/* [5:3] FPRETCTL:                              Advanced SIMD and Floating-point retention control. The possible values are:
                                                    0b000   Disable the retention circuit. This is the reset value.
                                                    0b001   2 Architectural Timer ticks are required before retention entry.
                                                    0b010   8 Architectural Timer ticks are required before retention entry.
                                                    0b011   32 Architectural Timer ticks are required before retention entry.
                                                    0b100   64 Architectural Timer ticks are required before retention entry.
                                                    0b101   128 Architectural Timer ticks are required before retention entry.
                                                    0b110   256 Architectural Timer ticks are required before retention entry.
                                                    0b111   512 Architectural Timer ticks are required before retention entry.
                                                Note
                                                    This field is present only if the Advanced SIMD and Floating-point Extension is implemented. Otherwise, it is RES0.
                                                    Software must not rely on retention state entry when the system counter is in low-power modes where CNTVALUEB increments are greater than 1. 
                                                    Entry to retention state relies on the system counter increments being +1. */
#define CPUECTLR_EL1_FPRETCTL_SHIFT                                 U(3)
#define CPUECTLR_EL1_FPRETCTL_MASK                                  U(0x7)
/* [2:0] CPURETCTL:                             CPU retention control. The possible values are:
                                                    0b000   Disable the retention circuit. This is the reset value.
                                                    0b001   2 Architectural Timer ticks are required before retention entry.
                                                    0b010   8 Architectural Timer ticks are required before retention entry.
                                                    0b011   32 Architectural Timer ticks are required before retention entry.
                                                    0b100   64 Architectural Timer ticks are required before retention entry.
                                                    0b101   128 Architectural Timer ticks are required before retention entry.
                                                    0b110   256 Architectural Timer ticks are required before retention entry.
                                                    0b111   512 Architectural Timer ticks are required before retention entry.
                                                Note
                                                    Software must not rely on retention state entry when the system counter is in low-power modes where CNTVALUEB increments are greater than 1. 
                                                    Entry to retention state relies on the system counter increments being +1. */
#define CPUECTLR_EL1_CPURETCTL_SHIFT                                U(0)
#define CPUECTLR_EL1_CPURETCTL_MASK                                 U(0x7)

/****************************************************************************************************
 * CPUMERRSR_EL1:       RW, 64bit, CPU Memory Error Syndrome Register
 ****************************************************************************************************/
/* [63] Fatal:                                  Fatal bit. This bit is set to 1 on the first memory error that caused a data abort. 
                                                It is a sticky bit so that after it is set, it remains set until the register is written.
                                                The reset value is 0. */
#define CPUMERRSR_EL1_FATAL_SHIFT                                   U(63)
#define CPUMERRSR_EL1_FATAL_MASK                                    U(0x1)
/* [47:40] Other error count:                   This field is set to 0 on the first memory error and is incremented on any memory error 
                                                that does not match the RAMID and Bank/Way information in this register while the sticky Valid bit is set.
                                                The reset value is 0. */
#define CPUMERRSR_EL1_OTHER_ERROR_COUNT_SHIFT                       U(40)
#define CPUMERRSR_EL1_OTHER_ERROR_COUNT_MASK                        U(0xff)
/* [39:32] Repeat error count:                  This field is set to 0 on the first memory error and is incremented on any memory error 
                                                that exactly matches the RAMID and Bank/Way information in this register while the sticky Valid bit is set.
                                                The reset value is 0. */
#define CPUMERRSR_EL1_REPEAT_ERROR_COUNT_SHIFT                      U(32)
#define CPUMERRSR_EL1_REPEAT_ERROR_COUNT_MASK                       U(0xff)
/* [31] Valid:                                  Valid bit. This bit is set to 1 on the first memory error. 
                                                It is a sticky bit so that after it is set, it remains set until the register is written.
                                                The reset value is 0. */
#define CPUMERRSR_EL1_VALID_SHIFT                                   U(31)
#define CPUMERRSR_EL1_VALID_MASK                                    U(0x1)
/* [30:24] RAMID:                               RAM Identifier. Indicates the RAM in which the first memory error. The possible values are:
                                                    0x00    L1 Instruction tag RAM.
                                                    0x01    L1 Instruction data RAM.
                                                    0x08    L1 Data tag RAM.
                                                    0x09    L1 Data data RAM.
                                                    0x0A    L1 Data dirty RAM.
                                                    0x18    TLB RAM. */
#define CPUMERRSR_EL1_RAMID_SHIFT                                   U(24)
#define CPUMERRSR_EL1_RAMID_MASK                                    U(0x7f)
/* [20:18] CPUID/Way:                           Indicates the RAM where the first memory error occurred.
                                                    L1 I-tag RAM        L1 I-data RAM       TLB RAM
                                                    0x0     Way 0       0x0     Bank 0      0x0     Way 0
                                                    0x1     Way 1       0x1     Bank 1      0x1     Way 1
                                                    0x2-0x7 Unused      0x2-0x7 Unused      0x2     Way 2
                                                                                            0x3     Way 3
                                                                                            0x4-0x7 Unused

                                                    L1 D-dirty RAM      L1 D-tag RAM        L1 D-data RAM
                                                    0x0     Dirty RAM   0x0     Way 0       0x0     Bank 0
                                                    0x1-0x7 Unused      0x1     Way 1       0x1     Bank 1
                                                                        0x2     Way 2       0x2     Bank 2
                                                                        0x3     Way 3       0x3     Bank 3
                                                                        0x4-0x7 Unused      ...
                                                                                            0x7     Bank 7 */
#define CPUMERRSR_EL1_CPUID_WAY_SHIFT                               U(18)
#define CPUMERRSR_EL1_CPUID_WAY_MASK                                U(0x7)
/* [11:0] RAM address:                          Indicates the index address of the first memory error.
                                                Note
                                                    • A fatal error results in the RAMID, Way, and RAM address recording the fatal error, even if the sticky bit is set.
                                                    • Only L1 Data data and L1 Data dirty RAMs can signal fatal errors, because all other RAM instances are protected only by parity.
                                                    • If two or more memory errors in the same RAM occur in the same cycle, only one error is reported.
                                                    • If two or more first memory error events from different RAMs occur in the same cycle, one of the errors is selected arbitrarily.
                                                    • If two or more memory error events from different RAMs, that do not match the RAMID, Way, 
                                                      and index information in this register while the sticky Valid bit is set, occur in the same cycle,
                                                      then the Other error count field is incremented only by one. */
#define CPUMERRSR_EL1_RAM_ADDRESS_SHIFT                             U(0)
#define CPUMERRSR_EL1_RAM_ADDRESS_MASK                              U(0xfff)

/****************************************************************************************************
 * L2MERRSR_EL1:        RW, 64bit, L2 Memory Error Syndrome Register
 ****************************************************************************************************/
/* [63] Fatal:                                  Fatal bit. This bit is set to 1 on the first memory error that caused a data abort. 
                                                It is a sticky bit so that after it is set, it remains set until the register is written.
                                                The reset value is 0. */
#define L2MERRSR_EL1_FATAL_SHIFT                                    U(63)
#define L2MERRSR_EL1_FATAL_MASK                                     U(0x1)
/* [47:40] Other error count:                   This field is set to 0 on the first memory error and is incremented on any memory error 
                                                that does not match the RAMID and Bank/Way information in this register while the sticky Valid bit is set.
                                                The reset value is 0. */
#define L2MERRSR_EL1_OTHER_ERROR_COUNT_SHIFT                        U(40)
#define L2MERRSR_EL1_OTHER_ERROR_COUNT_MASK                         U(0xff)
/* [39:32] Repeat error count:                  This field is set to 0 on the first memory error and is incremented on any memory error 
                                                that exactly matches the RAMID and Bank/Way information in this register while the sticky Valid bit is set.
                                                The reset value is 0. */
#define L2MERRSR_EL1_REPEAT_ERROR_COUNT_SHIFT                       U(32)
#define L2MERRSR_EL1_REPEAT_ERROR_COUNT_MASK                        U(0xff)
/* [31] Valid:                                  Valid bit. This bit is set to 1 on the first memory error. 
                                                It is a sticky bit so that after it is set, it remains set until the register is written.
                                                The reset value is 0. */
#define L2MERRSR_EL1_VALID_SHIFT                                    U(31)
#define L2MERRSR_EL1_VALID_MASK                                     U(0x1)
/* [30:24] RAMID:                               RAM Identifier. Indicates the RAM in which the first memory error occurred. The possible values are:
                                                    0x10    L2 tag RAM.
                                                    0x11    L2 data RAM.
                                                    0x12    SCU snoop filter RAM. */
#define L2MERRSR_EL1_RAMID_SHIFT                                    U(24)
#define L2MERRSR_EL1_RAMID_MASK                                     U(0x7f)
/* [21:18] CPUID/Way:                           Indicates the RAM where the first memory error occurred.
                                                    L2 tag RAM          L2 data RAM         SCU snoop filter RAM
                                                    0x0     Way 0       0x0     Bank 0      0x0 CPU0:Way0
                                                    0x1     Way 1       0x1     Bank 1      0x1 CPU0:Way1
                                                    ...                 ...                 ...
                                                    0xE     Way 14      0x7     Bank 7      0xE CPU3:Way2
                                                    0xF     Way 15      0x8-0xF Unused      0xF CPU3:Way3 */
#define L2MERRSR_EL1_CPUID_WAY_SHIFT                                U(18)
#define L2MERRSR_EL1_CPUID_WAY_MASK                                 U(0xf)
/* [16:3] RAM address:                          Indicates the index address of the first memory error. 
                                                Note
                                                    • A fatal error results in the RAMID, CPU ID/Way and RAM address recording the fatal error, even if the sticky bit was set.
                                                    • If two or more memory errors in the same RAM occur in the same cycle, only one error is reported.
                                                    • If two or more first memory error events from different RAMs occur in the same cycle,
                                                      one of the errors is selected arbitrarily, while the Other error count field is incremented only by one.
                                                    • If two or more memory error events from different RAMs, that do not match the RAMID, bank, way, 
                                                      or index information in this register while the sticky Valid bit is set, occur in the same cycle, 
                                                      the Other error count field is incremented only by one. */
#define L2MERRSR_EL1_RAM_ADDRESS_SHIFT                              U(3)
#define L2MERRSR_EL1_RAM_ADDRESS_MASK                               U(0x3fff)

/****************************************************************************************************
 * CBAR_EL1:            RO, 64bit, Configuration Base Address Register, EL1
 ****************************************************************************************************/
/* [39:18] PERIPHBASE[39:18]:                   The input PERIPHBASE[39:18] determines the reset value. */
#define CBAR_EL1_PERIPHBASE_SHIFT                                   U(18)
#define CBAR_EL1_PERIPHBASE_MASK                                    U(0x3fffff)

#endif  /* !IMPLEMENTATION_DEFINED__H__ */
