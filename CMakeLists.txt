cmake_minimum_required(VERSION 3.19)
project(Task_33_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Task_33_2 main.cpp
        src/FishException.cpp
        src/BootException.cpp
        src/NothingException.cpp)