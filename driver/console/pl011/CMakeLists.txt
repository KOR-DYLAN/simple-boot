# ASM Source
# list(APPEND ASM_SRC pl011_aarch64.S)

# C Source
list(APPEND C_SRC pl011.c)

# Target
target_sources(${PROJECT_NAME} PRIVATE ${ASM_SRC} ${C_SRC})
