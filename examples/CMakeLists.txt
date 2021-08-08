cmake_minimum_required(VERSION 3.17)
project(examples)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(sandbox ./sandbox.cpp)
target_link_libraries(sandbox tinvest)