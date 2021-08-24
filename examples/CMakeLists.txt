cmake_minimum_required(VERSION 3.17)
project(examples)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(sandbox_1 ./sandbox_1.cpp)
target_link_libraries(sandbox_1 tinvest)

add_executable(sandbox_2 ./sandbox_2.cpp)
target_link_libraries(sandbox_2 tinvest)

add_executable(sandbox_3 ./sandbox_3.cpp)
target_link_libraries(sandbox_3 tinvest)