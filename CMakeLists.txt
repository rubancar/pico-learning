cmake_minimum_required(VERSION 3.28)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(my_projects C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

add_executable(my_projects
        blinky.c)
target_link_libraries(my_projects pico_stdlib)
pico_add_extra_outputs(my_projects)