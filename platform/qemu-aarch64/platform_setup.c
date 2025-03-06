#include <stdio.h>
#include <driver/console/console.h>
#include <lib/arch/generic_timer.h>
#include <platform.h>

void platform_setup(void)
{
    generic_timer_init(SKIP_FREQ);
    console_init(CONSOLE_PL011, UART0_BASE, SKIP_CONSOLE_CLOCK, SKIP_CONSOLE_BAUDRATE);
}
