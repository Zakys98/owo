cmake_minimum_required(VERSION 3.21.1)

set(CMAKE_CXX_STANDARD 17)

project(owo)

file(GLOB_RECURSE source_list "src/*.cpp")

add_executable(${PROJECT_NAME} ${source_list})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/cxxopts/include)

target_compile_options(${PROJECT_NAME} PRIVATE -W -Wall -Wextra -pedantic)
target_link_libraries(${PROJECT_NAME} stdc++fs)