cmake_minimum_required(VERSION 3.16)

project(simple-boot VERSION 0.0.1)

# Output Path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)

list(APPEND subdir_lists arch)
list(APPEND subdir_lists lib)
list(APPEND subdir_lists platform)

subdirs(${subdir_lists})
