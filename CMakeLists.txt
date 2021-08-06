cmake_minimum_required(VERSION 3.21.1)

set(CMAKE_CXX_STANDARD 17)

project(owo)

file(GLOB_RECURSE source_list "src/*.cc")
include_directories(include)
include_directories(cxxopts/include)

add_executable(${PROJECT_NAME} ${source_list})
target_link_libraries(${PROJECT_NAME} stdc++fs)
