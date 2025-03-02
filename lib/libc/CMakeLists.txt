project(c
    VERSION 0.0.1
    LANGUAGES ASM C
)

# Target
add_library(${PROJECT_NAME})
if(ARCH STREQUAL "aarch32")
    add_subdirectory(arm/aarch32)
elseif(ARCH STREQUAL "aarch64")
    add_subdirectory(arm/aarch64)
else()
    message(FATAL_ERROR "Invalid 'ARCH'...")
endif()

# printf
add_subdirectory(printf)

# Architecture Common Source Lists
list(APPEND C_SRC putchar.c)
list(APPEND C_SRC puts.c)

target_sources(${PROJECT_NAME} PRIVATE ${ASM_SRC} ${C_SRC})
