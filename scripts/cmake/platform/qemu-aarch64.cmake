set(TARGET_ARCH     "armv8-a"       CACHE STRING "Target Architecture" FORCE)
set(TARGET_CPU      "cortex-a53"    CACHE STRING "Target CPU" FORCE)
set(ARCH            "aarch64"       CACHE STRING "Architecture" FORCE)
set(PLAT            "qemu-aarch64"  CACHE STRING "Platform" FORCE)

include(${CMAKE_CURRENT_LIST_DIR}/../gnu/aarch64-none-elf.cmake)