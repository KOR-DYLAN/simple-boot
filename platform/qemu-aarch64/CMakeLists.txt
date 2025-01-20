project(platform
    VERSION 0.0.1
    LANGUAGES ASM C
)

# ASM Source
list(APPEND ASM_SRC dummy.S)

# C Source
list(APPEND C_SRC dummy.c)

# Target
add_library(${PROJECT_NAME} ${ASM_SRC} ${C_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/platform)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/platform/${PLATFORM})
