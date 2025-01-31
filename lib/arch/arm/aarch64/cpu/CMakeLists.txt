# ASM Source
list(APPEND ASM_SRC cortex-a53.S)

# C Source
# list(APPEND C_SRC cortex-a53.c)

# Target
target_sources(${PROJECT_NAME} PRIVATE ${ASM_SRC} ${C_SRC})
