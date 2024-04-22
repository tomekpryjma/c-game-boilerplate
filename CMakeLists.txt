cmake_minimum_required(VERSION 3.29)

project(game)

set(SRC main.c core/core.h core/core.c)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

if (WIN32)
    add_executable(game WIN32_EXECUTABLE ${SRC})
elseif(APPLE)
    add_executable(game MACOSX_BUNDLE ${SRC})
endif()

target_link_libraries(game PRIVATE SDL2::SDL2)
