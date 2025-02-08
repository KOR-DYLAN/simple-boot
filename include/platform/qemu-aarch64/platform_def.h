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

#endif  /* !PLATFORM_DEF__H__ */
