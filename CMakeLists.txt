cmake_minimum_required(VERSION 3.10.2)
PROJECT(equation)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/equation)
set(Export_App_Target ${CMAKE_CURRENT_BINARY_DIR}/equation)

set(APP_SOURCE
	eq.cpp)
	


add_executable(equation
			   ${APP_SOURCE}
			   )

set(EXECUTABLE_OUTPUT_PATH ${Export_App_Target})