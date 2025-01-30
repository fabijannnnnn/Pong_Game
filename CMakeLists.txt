cmake_minimum_required(VERSION 3.26)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)

add_executable(Pong
        src/main.cpp
        src/game.cpp
        src/game.h
        src/ball.h
        src/ball.cpp
)

target_link_libraries(Pong PRIVATE raylib)