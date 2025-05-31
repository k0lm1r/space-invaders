cmake_minimum_required(VERSION 3.10.0)
project(space LANGUAGES C)
set(CMAKE_C_STANDARD 23)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")
endif()

add_executable(space src/main.c list/list.c graphics/drawing.c game/enemies.c game/hero.c game/game.c)
target_include_directories(space PRIVATE graphics src game list)