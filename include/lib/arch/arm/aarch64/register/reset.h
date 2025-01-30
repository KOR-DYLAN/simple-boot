/****************************************************************************************************
 * AArch64 reset registers
 ****************************************************************************************************/
#ifndef RESET__H__
#define RESET__H__

/****************************************************************************************************
 * RVBAR_EL3:           RO, 64bit, Reset Vector Base Address Register, EL3
 ****************************************************************************************************/
/* [63:0] RVBA:             Reset Vector Base Address. 
                            The address that execution starts from after reset when executing in 64-bit state.
                            Bits[1:0] of this register are 0b00, as this address must be aligned, 
                            and bits [63:40] are 0x000000 because the address must be within the physical address size supported by the processor. */
#define RVBAR_EL3_SHIFT             U(0)
#define RVBAR_EL3_MASK              U(0xffffffffffffffff)

/****************************************************************************************************
 * RMR_EL3:             RW, 32bit, Reset Management Register
 ****************************************************************************************************/
/* [1] RR:                  Reset Request. The possible values are:
                                0   This is the reset value.
                                1   Requests a warm reset. This bit is set to 0 by either a cold or warm reset.
                                The bit is strictly a request. */
#define RMR_EL3_RR_SHIFT            U(1)
#define RMR_EL3_RR_MASK             U(0x1)
/* [0] AA64.a:              Determines which execution state the processor boots into after a warm reset. The possible values are:
                                0   AArch32 Execution state.
                                1   AArch64 Execution state.
                            The reset vector address on reset takes a choice between two values, depending on the value in the AA64 bit.
                            This ensures that even with reprogramming of the AA64 bit, it is not possible to change the reset vector to go to a different location. 
                            a. The cold reset value depends on the AA64nAA32 signal.*/
#define RMR_EL3_AA64_SHIFT          U(0)
#define RMR_EL3_AA64_MASK           U(0x1)

#endif  /* !RESET__H__ */
