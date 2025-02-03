project(c
    VERSION 0.0.1
    LANGUAGES ASM C
)

# Target
add_library(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/lib/libc)
if(ARCH STREQUAL "aarch32")
    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/lib/libc/arm/aarch32)
    add_subdirectory(arm/aarch32)
elseif(ARCH STREQUAL "aarch64")
    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/lib/libc/arm/aarch64)
    add_subdirectory(arm/aarch64)
else()
    message(FATAL_ERROR "Invalid 'ARCH'...")
endif()
