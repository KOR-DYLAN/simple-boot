#include <stddef.h>
#include <stdint.h>
#include <lib/arch/generic_timer.h>
#include "generic_timer_internal.h"

static size_t g_tick_per_ns = 0;

void generic_timer_init(size_t freq)
{
    u_register_t cntp_ctl;

    /* Write the System Timer Frequency to CNTFRQ manually, 
     * this is required to use the delay_timer functionality. */
    if (0 < freq) {
        write_cntfrq_el0(freq);
    }

    /* Pre-calculate ns per tick. */
    g_tick_per_ns = UL(1000000000) / read_cntfrq_el0();

    /* Enable the secure physical timer */
    cntp_ctl = U(1) << CNTP_CTL_ENABLE_SHIFT;
    write_cntps_ctl_el1(cntp_ctl);
}

size_t generic_timer_get_tickcount(void)
{
    return read_cntpct_el0();
}

size_t generic_timer_get_us(void)
{
    return read_cntpct_el0() * g_tick_per_ns / UL(1000);
}

size_t generic_timer_get_ms(void)
{
    return read_cntpct_el0() * g_tick_per_ns / UL(1000000);
}

void generic_timer_delay_us(size_t us)
{
    size_t start, delta, total_delta;

    total_delta = us * UL(1000) / g_tick_per_ns;

    start = read_cntpct_el0();
    do {
        delta = read_cntpct_el0() - start;
    } while(delta < total_delta);
}

void generic_timer_delay_ms(size_t ms)
{
    size_t start, delta, total_delta;

    total_delta = ms * UL(1000000) / g_tick_per_ns;

    start = read_cntpct_el0();
    do {
        delta = read_cntpct_el0() - start;
    } while(delta < total_delta);
}
