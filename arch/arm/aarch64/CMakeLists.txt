project(simple-boot-aarch64
    VERSION 0.0.1
    LANGUAGES ASM C
)

# Linker Script
set(LDS_SRC boot.lds)

# ASM Source
list(APPEND ASM_SRC startup.S)
list(APPEND ASM_SRC runtime_exceptions.S)

# C Source
list(APPEND C_SRC main.c)

# Library
list(APPEND LIBS arch)
list(APPEND LIBS plat)
list(APPEND LIBS c)

# Target
add_executable(${PROJECT_NAME} ${ASM_SRC} ${C_SRC})
target_link_options(${PROJECT_NAME} PUBLIC -Wl,--script ${CMAKE_CURRENT_BINARY_DIR}/${LDS_SRC} -Wl,-Map=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.map)
target_link_libraries(${PROJECT_NAME} ${LIBS})
set_property(
    TARGET ${PROJECT_NAME}
    APPEND
    PROPERTY ADDITIONAL_CLEAN_FILES
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.map
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.asm
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.bin
)

# Linker Script
add_dependencies(${PROJECT_NAME} LINKER_SCRIPT)
add_custom_target(LINKER_SCRIPT
    WORKING_DIRECTORY
        ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS
        ${LDS_SRC}
)
add_custom_command(
    OUTPUT
    ${LDS_SRC}
    COMMAND
        ${CMAKE_PP} -E -xc -D__LINKER__ ${COMMON_INCLUDES} -Wp,-MD,${CMAKE_CURRENT_BINARY_DIR}/${LDS_SRC}.d -MT ${CMAKE_CURRENT_BINARY_DIR}/${LDS_SRC} -MP ${CMAKE_CURRENT_LIST_DIR}/${LDS_SRC}.S -P -o ${CMAKE_CURRENT_BINARY_DIR}/${LDS_SRC}
    WORKING_DIRECTORY
        ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS
        ${CMAKE_CURRENT_LIST_DIR}/${LDS_SRC}.S
)

# Extract ASM
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND
        ${CMAKE_OBJDUMP} -dx ${PROJECT_NAME} > ${PROJECT_NAME}.asm
    WORKING_DIRECTORY
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT
        "Extract ASM"
)

# Extract HEX
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND
        ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME} ${PROJECT_NAME}.hex
    WORKING_DIRECTORY
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        COMMENT
        "Extract HEX"
)

# Extract BIN
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND
        ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME} ${PROJECT_NAME}.bin
    WORKING_DIRECTORY
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT
        "Extract BIN"
)
