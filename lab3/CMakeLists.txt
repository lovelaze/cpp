cmake_minimum_required(VERSION 2.8.4)
project(cppgame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp character.cpp item.cpp env.cpp container.cpp)
add_executable(cppgame ${SOURCE_FILES})