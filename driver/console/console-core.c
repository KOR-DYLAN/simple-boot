#include <stddef.h>
#include <driver/console/console.h>
#include "pl011/pl011.h"

typedef int32_t(*console_register_entry_t)(console_t *console, uintptr_t base);

static const console_register_entry_t console_register[NUM_CONSOLES] = {
    [CONSOLE_PL011] = console_pl011_register,
};

static console_t *g_console;

int32_t console_init(console_id_t id, uintptr_t base, uint32_t clock, uint32_t baudrate)
{
    int32_t result = -1;
    console_t new_console;
    static console_t console;

    if (id < NUM_CONSOLES)
    {
        result = console_register[id](&new_console, base);
        if (result == 0)
        {
            result = new_console.init(new_console.base, clock, baudrate);
            if (result == 0)
            {
                console = new_console;
                g_console = &console;
            }
        }
    }

    return result;
}

int32_t console_set_baudrate(uint32_t clock, uint32_t baudrate)
{
    int32_t result = -1;

    if (g_console != NULL)
    {
        result = g_console->set_baudrate(g_console->base, clock, baudrate);
    }

    return result;
}

int32_t console_putc(int32_t character)
{
    int32_t result = -1;

    if (g_console != NULL)
    {
        if (character == (int32_t)'\n')
        {
            result = g_console->putc(g_console->base, (int32_t)'\r');
            if (result == 0)
            {
                result = g_console->putc(g_console->base, (int32_t)'\n');
            }
        }
        else
        {
            result = g_console->putc(g_console->base, character);
        }
    }

    return result;
}

int32_t console_getc(void)
{
    int32_t val = -1;

    if (g_console != NULL)
    {
        val = g_console->getc(g_console->base);
    }

    return val;
}

void console_flush(void)
{
    if (g_console != NULL)
    {
        g_console->flush(g_console->base);
    }
}
