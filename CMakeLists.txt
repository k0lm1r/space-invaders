cmake_minimum_required(VERSION 3.10.0)
project(space LANGUAGES C)
set(CMAKE_C_STANDARD 23)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")
endif()

add_executable(space src/main.c list/list.c graphics/drawing.c characters/enemies.c characters/hero.c)
target_include_directories(space PRIVATE graphics src characters list)