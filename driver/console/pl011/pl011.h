#ifndef PL011__H__
#define PL011__H__

extern int32_t console_pl011_init(uintptr_t base, uint32_t clock, uint32_t baudrate);
extern int32_t console_pl011_set_baudrate(uintptr_t base, uint32_t clock, uint32_t baudrate);
extern int32_t console_pl011_putc(uintptr_t base, int32_t character);
extern int32_t console_pl011_getc(uintptr_t base);
extern int32_t console_pl011_flush(uintptr_t base);
extern int32_t console_pl011_register(console_t *console, uintptr_t base);

#endif  /* !PL011__H__ */
