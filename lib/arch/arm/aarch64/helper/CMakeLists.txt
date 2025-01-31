# ASM Source
list(APPEND ASM_SRC reset_helper.S)

# C Source
# list(APPEND C_SRC helper.c)

# Target
target_sources(${PROJECT_NAME} PRIVATE ${ASM_SRC} ${C_SRC})
