cmake_minimum_required(VERSION 3.10.2)
PROJECT(quad_eq_solver)

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")
endif()

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QuadEq)

add_subdirectory(tests)
add_subdirectory(lib)
add_subdirectory(app)
