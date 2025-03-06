#ifndef GENERIC_TIMER__H__
#define GENERIC_TIMER__H__

#define SKIP_FREQ   (0)

#define get_ms      generic_timer_get_ms
#define get_us      generic_timer_get_us
#define mdelay      generic_timer_delay_ms
#define udelay      generic_timer_delay_us

extern void generic_timer_init(size_t freq);
extern size_t generic_timer_get_tickcount(void);
extern size_t generic_timer_get_us(void);
extern size_t generic_timer_get_ms(void);
extern void generic_timer_delay_us(size_t us);
extern void generic_timer_delay_ms(size_t ms);

#endif  /* !GENERIC_TIMER__H__ */
