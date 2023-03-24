# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
# set(PICO_SDK_PATH "d:/RaspberryPiPico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(servo C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1


add_executable(servo servo.c )

pico_set_program_name(servo "servo")
pico_set_program_version(servo "0.2")

pico_enable_stdio_uart(servo 1)
pico_enable_stdio_usb(servo 1)

target_sources(servo PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.c
        ${CMAKE_CURRENT_LIST_DIR}/loop.c
        ${CMAKE_CURRENT_LIST_DIR}/blinker.c
        ${CMAKE_CURRENT_LIST_DIR}/servo.c
        )

# Add the standard library to the build
target_link_libraries(servo pico_stdlib)

# Add any user requested libraries
target_link_libraries(servo
        hardware_timer
        hardware_watchdog
        hardware_clocks
        )

# pull in common dependencies and additional pwm hardware support
target_link_libraries(servo pico_stdlib hardware_pwm)

# pico_add_extra_outputs(servo)
# must be removed or build fails
