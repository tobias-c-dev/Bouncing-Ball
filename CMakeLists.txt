cmake_minimum_required(VERSION 3.16)

project(Bouncing-Ball)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(Bouncing-Ball
    main.cpp
)

target_link_libraries(Bouncing-Ball raylib)