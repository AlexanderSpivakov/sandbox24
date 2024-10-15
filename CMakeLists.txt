cmake_minimum_required(VERSION 2.8)
PROJECT(QuadEqProject)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QuadEq)
set(Export_App_Target ${CMAKE_CURRENT_BINARY_DIR}/QuadEq)

set(APP_SOURCE 
	main.cpp
	quadraticEquation.cpp)

set(APP_HEADER quadraticEquation.hpp)

add_executable(QuadEq 
			${APP_SOURCE}
			${APP_HEADER})

set(EXECUTABLE_OUTPUT_PATH ${Export_App_Target})