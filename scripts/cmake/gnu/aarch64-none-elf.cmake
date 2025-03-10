set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(GNU_MACHINE "aarch64-none-elf" CACHE STRING "GNU compiler triple" FORCE)

set(CMAKE_ASM_COMPILER ${GNU_MACHINE}-gcc)
set(CMAKE_C_COMPILER   ${GNU_MACHINE}-gcc)
set(CMAKE_CXX_COMPILER ${GNU_MACHINE}-g++)
set(CMAKE_LINKER       ${GNU_MACHINE}-gcc)
set(CMAKE_PP           ${GNU_MACHINE}-cpp)
set(CMAKE_AR           ${GNU_MACHINE}-ar)
set(CMAKE_OBJCOPY      ${GNU_MACHINE}-objcopy)
set(CMAKE_OBJDUMP      ${GNU_MACHINE}-objdump)
set(CMAKE_SIZE         ${GNU_MACHINE}-size)

set(CMAKE_C_COMPILER_WORKS TRUE CACHE BOOL "" FORCE)
set(CMAKE_CXX_COMPILER_WORKS TRUE CACHE BOOL "" FORCE)

# Common Option
set(COMMON_INCLUDES "-I${CMAKE_SOURCE_DIR}/include -I${CMAKE_SOURCE_DIR}/include/lib/arch/arm/aarch64 -I${CMAKE_SOURCE_DIR}/include/platform -I${CMAKE_SOURCE_DIR}/include/platform/${PLAT}")
set(COMMON_ASFLAGS "-x assembler-with-cpp -march=${TARGET_ARCH} -mtune=${TARGET_CPU} -nostdinc -mgeneral-regs-only -mstrict-align -ffreestanding -Wa,--fatal-warnings -D__ASSEMBLER__ ${COMMON_INCLUDES}")
set(COMMON_CFLAGS "-march=${TARGET_ARCH} -mtune=${TARGET_CPU} -nostdinc -mgeneral-regs-only -mstrict-align -ffunction-sections -fdata-sections -ffreestanding -fno-common ${COMMON_INCLUDES}")
set(COMMON_LDFLAGS "-z noexecstack -Wl,--fatal-warnings -Wl,--gc-sections -Wl,-z,common-page-size=4096 -Wl,-z,max-page-size=4096 -Wl,--build-id=none -Wl,--sort-section=alignment -nostdlib")
string(REPLACE " " ";" COMMON_INCLUDES "${COMMON_INCLUDES}")

# Debug
set(CMAKE_ASM_FLAGS_DEBUG "${COMMON_ASFLAGS} -DENABLE_BTI=1 -O0 -g -Wa,-gdwarf-4"  CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_DEBUG   "${COMMON_CFLAGS} -DENABLE_BTI=1 -O0 -g -gdwarf-4"   CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${COMMON_LDFLAGS} -O0" CACHE STRING "" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "" CACHE STRING "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "" CACHE STRING "" FORCE)
set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "" CACHE STRING "" FORCE)

# MinSizeRel
set(CMAKE_ASM_FLAGS_MINSIZEREL "${COMMON_ASFLAGS} -DENABLE_BTI=0 -Os -DNDEBUG"  CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_MINSIZEREL   "${COMMON_CFLAGS} -DENABLE_BTI=0 -Os -DNDEBUG"   CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "${COMMON_LDFLAGS} -Os " CACHE STRING "" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL "" CACHE STRING "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL "" CACHE STRING "" FORCE)
set(CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL "" CACHE STRING "" FORCE)

# Release
set(CMAKE_ASM_FLAGS_RELEASE "${COMMON_ASFLAGS} -DENABLE_BTI=0 -O2 -DNDEBUG"  CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELEASE   "${COMMON_CFLAGS} -DENABLE_BTI=0 -O2 -DNDEBUG"   CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${COMMON_LDFLAGS} -O2" CACHE STRING "" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "" CACHE STRING "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "" CACHE STRING "" FORCE)
set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "" CACHE STRING "" FORCE)

# RelWithDebInfo
set(CMAKE_ASM_FLAGS_RELWITHDEBINFO "${COMMON_ASFLAGS} -DENABLE_BTI=1 -O2 -g -Wa,-gdwarf-4"  CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELWITHDEBINFO   "${COMMON_CFLAGS} -DENABLE_BTI=1 -O2 -g -gdwarf-4"   CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${COMMON_LDFLAGS} -O2" CACHE STRING "" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO "" CACHE STRING "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "" CACHE STRING "" FORCE)
set(CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO "" CACHE STRING "" FORCE)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
