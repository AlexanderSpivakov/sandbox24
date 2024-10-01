cmake_minimum_required(VERSION 3.5)
PROJECT(solving_quadratic_equation)

set(Export_App_Target ${CmaKE_CURRENT_BINARY_DIR})

set(APP_SOURCE
	main.cpp
	quad_eq.cpp)

set(APP_HEADER
	quad_eq.hpp)

add_executable(Task_quad
				${APP_SOURCE}
				${APP_HEADER})

set(EXECUTABLE_OUTPUT_PATH ${Export_App_Target})