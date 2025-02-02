project(arch
    VERSION 0.0.1
    LANGUAGES ASM C
)

# Target
add_library(${PROJECT_NAME})

# append source lsits
add_subdirectory(cpu)
# add_subdirectory(helper)
