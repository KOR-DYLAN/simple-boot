#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>

/* CNTFRQ_EL0, Counter-timer Frequency Register
 * Bits [31:0]
 *  Clock frequency.
 *  Indicates the system counter clock frequency, in Hz.*/
rw_sysreg_func_def cntfrq_el0

/* Counter-timer Control Register
 * ISTATUS, bit [2]
 *  The status of the timer. This bit indicates whether the timer condition is met:
 *      0: Timer condition is not met.
 *      1: Timer condition is met.
 *  When the value of the ENABLE bit is 1, ISTATUS indicates whether the timer condition is met.
 *  ISTATUS takes no account of the value of the IMASK bit.
 *  If the value of ISTATUS is 1 and the value of IMASK is 0 then the timer interrupt is asserted.
 *  Access to this field is RO.
 * IMASK, bit [1]
 *  Timer interrupt mask bit. Permitted values are:
 *      0: Timer interrupt is not masked by the IMASK bit.
 *      1: Timer interrupt is masked by the IMASK bit.
 * ENABLE, bit [0]
 *  Enables the timer. Permitted values are:
 *      0: Timer disabled.
 *      1: Timer enabled.
 */
/* CNTHP_CTL_EL2, Counter-timer Control Register */
rw_sysreg_func_def cnthp_ctl_el2
/* CNTPS_CTL_EL1, Counter-timer Physical Secure Timer Control Register */
rw_sysreg_func_def cntps_ctl_el1
/* CNTP_CTL_EL0: Counter-timer Physical Timer Control Register */
rw_sysreg_func_def cntp_ctl_el0
/* CNTHCTL_EL2, Counter-timer Hypervisor Control Register */
rw_sysreg_func_def cnthctl_el2
/* CNTV_CTL_EL0: Counter-timer Virtual Timer Control Register */
rw_sysreg_func_def cntv_ctl_el0
/* CNTKCTL_EL1, Counter-timer Kernel Control Register */
rw_sysreg_func_def cntkctl_el1

/* Counter-timer TimerValue Register 
 * TimerValue, bits [31:0]
 *  The TimerValue view of the ELx timer.
 *  On a read of this register:
 *      - If <CNTxx>CTL_ELx.ENABLE is 0, the value returned is UNKNOWN.
 *      - If <CNTxx>CTL_ELx.ENABLE is 1, the value returned is <CNTxx>_CVAL_ELx - CNTPCT_EL0).
 *  On a write of this register, <CNTxx>_CVAL_ELx is set to (CNTPCT_EL0 + TimerValue), where TimerValue is treated as a signed 32-bit integer.
 *  When <CNTxx>CTL_ELx.ENABLE is 1, the timer condition is met when (CNTPCT_EL0 - <CNTxx>_CVAL_ELx) is greater than or equal to zero.
 *  This means that TimerValue acts like a 32-bit downcounter timer. When the timer condition is met:
 *      - <CNTxx>CTL_ELx.ISTATUS is set to 1.
 *      - If <CNTxx>CTL_ELx.IMASK is 0, an interrupt is generated.
 *  When <CNTxx>CTL_ELx.ENABLE is 0, the TimerValue cannot be read but continues to decrement.
 *  When the timer is enabled, the TimerValue represents the elapsed time whether that time was spent enabled or disabled.
 *  The reset behavior of this field is:
 *      - On a Warm reset, this field resets to an architecturally UNKNOWN value.
 */
/* CNTHP_TVAL_EL2, Counter-timer Physical Timer TimerValue Register (EL2) */
rw_sysreg_func_def cnthp_tval_el2
/* CNTPS_TVAL_EL1: Counter-timer Physical Secure Timer TimerValue Register */
rw_sysreg_func_def cntps_tval_el1
/* CNTP_TVAL_EL0: Counter-timer Physical Timer TimerValue Register */
rw_sysreg_func_def cntp_tval_el0

/* Counter-timer CompareValue Register
 * CompareValue, bits [63:0]
 *  Holds the ELx timer CompareValue.
 *  When <CNTxx>CTL_ELx.ENABLE is 1, and TimerConditionMet is TRUE for the ELx timer, the timer condition is met and all of the following are true:
 *      - <CNTxx>CTL_ELx.ISTATUS is set to 1.
 *      - If <CNTxx>CTL_ELx.IMASK is 0, an interrupt is generated.
 *  TimerConditionMet is defined by 'Operation of the CompareValue views of the timers'.
 *  The CompareValue view of the timer acts like a 64-bit upcounter timer.
 *  When <CNTxx>CTL_ELx.ENABLE is 0, the timer condition is not met, but CNTPCT_EL0 continues to count.
 *  If the Generic counter is implemented at a size less than 64 bits, then this field is permitted to be implemented at the same width as the counter, and the upper bits are RES0.
 *  The value of this field is treated as zero-extended in all counter calculations.
 *  The reset behavior of this field is:
 *      - On a Warm reset, this field resets to an architecturally UNKNOWN value.
 */
/* CNTHP_CVAL_EL2, Counter-timer Physical Timer CompareValue Register (EL2) */
rw_sysreg_func_def cnthp_cval_el2
/* CNTPS_CVAL_EL1, Counter-timer Physical Secure Timer CompareValue Register */
rw_sysreg_func_def cntps_cval_el1
/* CNTP_CVAL_EL0, Counter-timer Physical Timer CompareValue Register */
rw_sysreg_func_def cntp_cval_el0
/* CNTV_CVAL_EL0: Counter-timer Virtual Timer CompareValue Register */
rw_sysreg_func_def cntv_cval_el0

/* CNTPCT_EL0, Counter-timer Physical Count register
 * Bits [63:0]
 *  Physical count value. */
ro_sysreg_func_def cntpct_el0
