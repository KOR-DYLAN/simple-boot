if(ARCH STREQUAL "aarch32")
    add_subdirectory(arm/aarch32)
elseif(ARCH STREQUAL "aarch64")
    add_subdirectory(arm/aarch64)
else()
    message(FATAL_ERROR "Invalid 'ARCH'...")
endif()
