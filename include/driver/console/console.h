#ifndef CONSOLE__H__
#define CONSOLE__H__

#define SKIP_CONSOLE_CLOCK      (0)
#define SKIP_CONSOLE_BAUDRATE   (0)

#include <stdint.h>

typedef enum {
    CONSOLE_PL011,
    NUM_CONSOLES,
} console_id_t;

typedef struct console {
    uintptr_t base;
    int32_t (*init)(uintptr_t base, uint32_t clock, uint32_t baudrate);
    int32_t (*set_baudrate)(uintptr_t base, uint32_t clock, uint32_t baudrate);
    int32_t (*putc)(uintptr_t base, int32_t character);
    int32_t (*getc)(uintptr_t base);
    int32_t (*flush)(uintptr_t base);
} console_t;

extern int32_t console_init(console_id_t id, uintptr_t base, uint32_t clock, uint32_t baudrate);
extern int32_t console_set_baudrate(uint32_t clock, uint32_t baudrate);
extern int32_t console_putc(int32_t character);
extern int32_t console_getc(void);
extern void console_flush(void);

#endif  /* !CONSOLE__H__ */
