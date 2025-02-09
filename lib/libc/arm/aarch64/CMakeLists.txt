# ASM Source
list(APPEND ASM_SRC declare_stack.S)
list(APPEND ASM_SRC crt0.S)
list(APPEND ASM_SRC misc.S)

# C Source
# list(APPEND C_SRC <TheName>)

# Target
target_sources(${PROJECT_NAME} PRIVATE ${ASM_SRC} ${C_SRC})
