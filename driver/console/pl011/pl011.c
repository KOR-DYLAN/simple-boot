#include <stdint.h>
#include <common/bitops.h>
#include <common/mmio.h>
#include <driver/console/console.h>
#include "pl011_register.h"
#include "pl011.h"

int32_t console_pl011_init(uintptr_t base, uint32_t clock, uint32_t baudrate)
{
    volatile uint32_t reg;

    /* Disable uart before programming */
    reg = mmio_read_32(base + UARTCR);
    reg &= ~UARTCR_UARTEN_BIT;
    mmio_write_32(base + UARTCR, reg);

    /* TODO: implement baudrate */
    (void)clock;
    (void)baudrate;

    /* Enable tx, rx, and uart overall */
    reg = UARTCR_RXE_BIT | UARTCR_TXE_BIT | UARTCR_UARTEN_BIT;
    mmio_write_32(base + UARTCR, reg);

    return 0;
}

int32_t console_pl011_set_baudrate(uintptr_t base, uint32_t clock, uint32_t baudrate)
{
    /* TODO: implement baudrate */
    (void)base;
    (void)clock;
    (void)baudrate;

    return -1;
}

int32_t console_pl011_putc(uintptr_t base, int32_t character)
{
    volatile uint32_t reg;

    /* Check if the transmit FIFO is full */    
    do {
        reg = mmio_read_32(base + UARTFR);
    } while((reg & UARTFR_TXFF_BIT) == UARTFR_TXFF_BIT);

    mmio_write_32(base + UARTDR, (uint32_t)character);

    return 0;
}

int32_t console_pl011_getc(uintptr_t base)
{
    volatile uint32_t reg;

    /* Check if the receive FIFO is empty */
    do {
        reg = mmio_read_32(base + UARTFR);
    } while((reg & UARTFR_RXFE_BIT) == UARTFR_RXFE_BIT);

    reg = mmio_read_32(base + UARTDR);

    return (int32_t)reg;
}

int32_t console_pl011_flush(uintptr_t base)
{
    volatile uint32_t reg;

    /* Check if the transmit FIFO is full */    
    do {
        reg = mmio_read_32(base + UARTFR);
    } while((reg & UARTFR_BUSY_BIT) == UARTFR_BUSY_BIT);
}

int32_t console_pl011_register(console_t *console, uintptr_t base)
{
    int32_t result = 0;
    uint8_t periph_id = mmio_read_8(base + UARTPeriphID0);
    uint8_t pcell_id = mmio_read_8(base + UARTPCellID0);

    if ((periph_id == 0x11) && (pcell_id == 0x0d))
    {
        console->base = base;
        console->init = console_pl011_init;
        console->set_baudrate = console_pl011_set_baudrate;
        console->putc = console_pl011_putc;
        console->getc = console_pl011_getc;
        console->flush = console_pl011_flush;
    }
    else
    {
        result = -1;
    }

    return result;
}
