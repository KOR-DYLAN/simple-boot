project(plat
    VERSION 0.0.1
    LANGUAGES ASM C
)

# ASM Source
list(APPEND ASM_SRC plat_cpu.S)
list(APPEND ASM_SRC plat_mem.S)

# C Source
list(APPEND C_SRC platform_setup.c)

# Library
list(APPEND LIBS arch)
list(APPEND LIBS c)
list(APPEND LIBS console)

# Target
add_library(${PROJECT_NAME} ${ASM_SRC} ${C_SRC})
target_link_libraries(${PROJECT_NAME} ${LIBS})
