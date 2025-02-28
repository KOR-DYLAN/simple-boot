project(console
    VERSION 0.0.1
    LANGUAGES ASM C
)

# Target
add_library(${PROJECT_NAME} console-core.c)
add_subdirectory(pl011)
