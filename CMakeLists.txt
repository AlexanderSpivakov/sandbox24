cmake_minimum_required(VERSION 3.10.2)
PROJECT(hello_world_project)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/HelloWorld)
set(Export_App_Target ${CMAKE_CURRENT_BINARY_DIR}/HelloWorld)

add_executable(hello_world main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${Export_App_Target})
