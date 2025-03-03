# ASM Source
list(APPEND ASM_SRC generic_timer.S)

# C Source
list(APPEND C_SRC generic_timer.c)

# Target
target_sources(${PROJECT_NAME} PRIVATE ${ASM_SRC} ${C_SRC})
