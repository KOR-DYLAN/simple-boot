#include <stdio.h>
#include <platform.h>
#include <lib/arch/generic_timer.h>

int main(int argc, char *argv[])
{
    platform_setup();

    while(1)
    {
        printf("Hello Timer!\n");
        generic_timer_delay_ms(1000);
    }

    return 0;
}
