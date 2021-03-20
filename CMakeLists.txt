cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(morse_project C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(morse morse.c)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(morse pico_stdlib)

# Commend out the `pico_enable_stdio` lines below to enable stdio to use UART instead of USB
pico_enable_stdio_usb(morse 1) # Enable USB
pico_enable_stdio_uart(morse 0) # Disable UART

# create map/bin/hex file etc.
pico_add_extra_outputs(morse)
