#include <common/asm_macro_utils.S>
#include <aarch64_asm_macro_util.S>
#include <lib/arch/sysreg.h>
#include <platform.h>
#include "pl011.h"

#define OFFSETOF_CONSOLE_BASE   (U(0) * U(8))
#define OFFSETOF_CONSOLE_PUTC   (U(1) * U(8))
#define OFFSETOF_CONSOLE_GETC   (U(2) * U(8))
#define OFFSETOF_CONSOLE_FLUSH  (U(3) * U(8))

    .global asm_console_pl011_init
    .global asm_console_pl011_putc
    .global asm_console_pl011_getc

func asm_console_pl011_init
    mov x29, x30                                                    /* backup 'lr' */

    /* copy 'pl011' base address from console structure */
    ldr x9, [x0, #OFFSETOF_CONSOLE_BASE]                            /* x9 = (uint64_t *)(x0 + OFFSETOF_CONSOLE_BASE) */

    /* Disable uart before programming */
    ldr w10, [x9, #UARTCR]                                          /* w10 = *(uint32_t *)(x9 + UARTCR) */
    mov w11, #UARTCR_UARTEN_BIT                                     /* w11 = UARTCR_UARTEN_BIT */
    bic w10, w10, w11                                               /* w10 = w10 & ~w11 */
    str w10, [x9, #UARTCR]                                          /* *(uint32_t *)(x9 + UARTCR) = w10 */

    /* Enable tx, rx, and uart overall */
    mov w12, #(UARTCR_RXE_BIT | UARTCR_TXE_BIT | UARTCR_UARTEN_BIT) /* w12 = UARTCR_RXE_BIT | UARTCR_TXE_BIT | UARTCR_UARTEN_BIT  */
    str w12, [x9, #UARTCR]                                          /* *(uint32_t *)(x9 + UARTCR) = w12 */

    adrp x13, asm_console_pl011_putc                                /* x13 = asm_console_pl011_putc & 0xfffffffffffff000 */
    add x13, x13, :lo12:asm_console_pl011_putc                      /* x13 = x13 + (asm_console_pl011_putc & 0xfff) */
    str x13, [x0, #OFFSETOF_CONSOLE_PUTC]                           /* *(uint64_t *)(x0 + OFFSETOF_CONSOLE_PUTC) = x13 */

    adrp x13, asm_console_pl011_getc                                /* x13 = asm_console_pl011_getc & 0xfffffffffffff000 */
    add x13, x13, :lo12:asm_console_pl011_getc                      /* x13 = x13 + (asm_console_pl011_getc & 0xfff) */
    str x13, [x0, #OFFSETOF_CONSOLE_GETC]                           /* *(uint64_t *)(x0 + OFFSETOF_CONSOLE_GETC) = x13 */

    mov x30, x29                                                    /* store 'lr' */
    ret
endfunc asm_console_pl011_init

func asm_console_pl011_putc
    mov x29, x30                                                    /* backup 'lr' */

    /* copy 'pl011' base address from console structure */
    ldr x9, [x0, #OFFSETOF_CONSOLE_BASE]                            /* x9 = (uint64_t *)(x0 + OFFSETOF_CONSOLE_BASE) */

    /* if (w1 != '\n') goto label-2; */
    cmp w1, #ASCII_LF
    b.ne 2f
1:
    ldr w10, [x9, #UARTFR]                                          /* w10 = *(uint32_t *)(x9 + UARTFR) */
    /* if ((w10 & (1 << UARTFR_TXFF_SHIFT)) != 0) goto label-1;  */
    tbnz w10, #UARTFR_TXFF_SHIFT, 1b
    mov w11, #ASCII_CR                                              /* w11 = ASCII_CR */
    str w11, [x9, #UARTDR]                                          /* *(uint32_t *)(x9 + UARTDR) = w11 */
2:
    ldr w10, [x9, #UARTFR]                                          /* w10 = *(uint32_t *)(x9 + UARTFR) */
    /* if ((w10 & (1 << UARTFR_TXFF_SHIFT)) != 0) goto label-2;  */
    tbnz w10, #UARTFR_TXFF_SHIFT, 2b
    str w1, [x9, #UARTDR]                                           /* *(uint32_t *)(x9 + UARTDR) = w1 */

    mov x30, x29                                                    /* store 'lr' */
    ret
endfunc asm_console_pl011_putc

func asm_console_pl011_getc
    mov x29, x30                                                    /* backup 'lr' */

    /* copy 'pl011' base address from console structure */
    ldr x9, [x0, #OFFSETOF_CONSOLE_BASE]                            /* x9 = (uint64_t *)(x0 + OFFSETOF_CONSOLE_BASE) */
    
    mov x30, x29                                                    /* store 'lr' */
    ret
endfunc asm_console_pl011_getc
