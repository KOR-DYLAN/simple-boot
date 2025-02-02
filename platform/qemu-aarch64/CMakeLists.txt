project(plat
    VERSION 0.0.1
    LANGUAGES ASM C
)

# ASM Source
list(APPEND ASM_SRC plat_cpu.S)
list(APPEND ASM_SRC plat_mem.S)

# C Source
list(APPEND C_SRC dummy.c)

# Target
add_library(${PROJECT_NAME} ${ASM_SRC} ${C_SRC})
