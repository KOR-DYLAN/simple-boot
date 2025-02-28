#ifndef PLATFORM_DEF__H__
#define PLATFORM_DEF__H__

#include <common/bitops.h>

#define PLAT_LINKER_FORMAT          "elf64-littleaarch64"
#define PLAT_LINKER_ARCH            aarch64
#define PLAT_IMAGE_BASE             0x40000000
#define PLAT_IMAGE_LIMIT            0x40040000
#define PAGE_SIZE                   0x1000
#define STRUCT_ALIGN                8
#define DATA_ALIGN                  1
#define BSS_ALIGN                   16

#define PLAT_NUM_CPUS               4
#define PLAT_STACK_SIZE             0x1000
#define PLAT_STACK_ALIGN_COUNT      6
#define PLAT_STACK_ALIGN            (1 << PLAT_STACK_ALIGN_COUNT)

#define PLAT_CPU_PER_CLUSTER_SHIFT  U(3)
#define PLAT_PRIMARY_CORE_NUM       U(0)

/*
 * PL011 related constants
 */
#define UART0_BASE                  0x09000000
#define UART1_BASE                  0x09040000
#define UART0_CLK_IN_HZ             1
#define UART1_CLK_IN_HZ             1
#define PLAT_QEMU_CONSOLE_BAUDRATE  115200

/*
 * GIC related constants
 */
 #define GICD_BASE                  0x8000000
 #define GICC_BASE                  0x8010000
 #define GICR_BASE                  0x80A0000
 
 #define QEMU_IRQ_SEC_SGI_0         8
 #define QEMU_IRQ_SEC_SGI_1         9
 #define QEMU_IRQ_SEC_SGI_2         10
 #define QEMU_IRQ_SEC_SGI_3         11
 #define QEMU_IRQ_SEC_SGI_4         12
 #define QEMU_IRQ_SEC_SGI_5         13
 #define QEMU_IRQ_SEC_SGI_6         14
 #define QEMU_IRQ_SEC_SGI_7         15

#endif  /* !PLATFORM_DEF__H__ */
