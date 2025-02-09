# ASM Source
list(APPEND ASM_SRC cache_helper.S)

# Target
target_sources(${PROJECT_NAME} PRIVATE ${ASM_SRC})
