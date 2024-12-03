cmake_minimum_required(VERSION 3.10.2)
PROJECT(equation)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/equation)
set(Export_App_Target ${CMAKE_CURRENT_BINARY_DIR}/equation)

set(APP_SOURCE
	main.cpp
	solutionequation.cpp)

set(APP_HEADER solutionequation.hpp)	


add_executable(equation
			   ${APP_SOURCE}
			   ${APP_HEADER}
			   )

set(EXECUTABLE_OUTPUT_PATH ${Export_App_Target})