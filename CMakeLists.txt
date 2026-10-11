cmake_minimum_required(VERSION 3.20)

project(gameboy_emulator LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Portable emulation core
add_library(gb_core STATIC
    src/core/gameboy.c
)

target_include_directories(gb_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Desktop executable
add_executable(gameboy
    src/desktop/main.c
)

target_link_libraries(gameboy PRIVATE gb_core)