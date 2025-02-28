cmake_minimum_required(VERSION 3.16)

project(simple-boot VERSION 0.0.1)

# Output Path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)

# Common Include Path
include_directories(${CMAKE_SOURCE_DIR}/include/lib/libc)
if(ARCH STREQUAL "aarch32")
include_directories(${CMAKE_SOURCE_DIR}/include/lib/libc/arm/aarch32)
elseif(ARCH STREQUAL "aarch64")
include_directories(${CMAKE_SOURCE_DIR}/include/lib/libc/arm/aarch64)
else()
    message(FATAL_ERROR "Invalid 'ARCH'...")
endif()

list(APPEND subdir_lists arch)
list(APPEND subdir_lists lib)
list(APPEND subdir_lists driver)
list(APPEND subdir_lists platform)

subdirs(${subdir_lists})
