cmake_minimum_required(VERSION 3.16)
project(Ball)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

add_executable(Ball
    main.cpp
)

target_link_libraries(Ball raylib)