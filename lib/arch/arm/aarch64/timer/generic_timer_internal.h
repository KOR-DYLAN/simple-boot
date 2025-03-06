#ifndef GENERIC_TIMER_INTERNAL__H__
#define GENERIC_TIMER_INTERNAL__H__

#include <common/bitops.h>

/* Physical timer control register bit fields shifts and masks */
#define CNTP_CTL_ENABLE_SHIFT   U(0)
#define CNTP_CTL_IMASK_SHIFT    U(1)
#define CNTP_CTL_ISTATUS_SHIFT  U(2)

/* Counter-timer Frequency Register */
extern void write_cntfrq_el0(u_register_t value);
extern u_register_t read_cntfrq_el0(void);

/* Counter-timer Control Register */
extern void write_cnthp_ctl_el2(u_register_t value);
extern u_register_t read_cnthp_ctl_el2(void);

extern void write_cntps_ctl_el1(u_register_t value);
extern u_register_t read_cntps_ctl_el1(void);

extern void write_cntp_ctl_el0(u_register_t value);
extern u_register_t read_cntp_ctl_el0(void);

extern void write_cnthctl_el2(u_register_t value);
extern u_register_t read_cnthctl_el2(void);

extern void write_cntv_ctl_el0(u_register_t value);
extern u_register_t read_cntv_ctl_el0(void);

extern void write_cntkctl_el1(u_register_t value);
extern u_register_t read_cntkctl_el1(void);

/* Counter-timer TimerValue Register  */
extern void write_cnthp_tval_el2(u_register_t value);
extern u_register_t read_cnthp_tval_el2(void);

extern void write_cntps_tval_el1(u_register_t value);
extern u_register_t read_cntps_tval_el1(void);

extern void write_cntp_tval_el0(u_register_t value);
extern u_register_t read_cntp_tval_el0(void);

/* Counter-timer CompareValue Register */
extern void write_cnthp_cval_el2(u_register_t value);
extern u_register_t read_cnthp_cval_el2(void);

extern void write_cntps_cval_el1(u_register_t value);
extern u_register_t read_cntps_cval_el1(void);

extern void write_cntp_cval_el0(u_register_t value);
extern u_register_t read_cntp_cval_el0(void);

extern void write_cntv_cval_el0(u_register_t value);
extern u_register_t read_cntv_cval_el0(void);

/* Counter-timer Physical Count register */
extern u_register_t read_cntpct_el0(void);

#endif  /* !GENERIC_TIMER_INTERNAL__H__ */
