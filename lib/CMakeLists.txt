set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/../app/QuadEq)

set(LIB_INCLUDE
   quad_eq.hpp
)

set(LIB_SOURCE
   quad_eq.cpp
)

list(TRANSFORM LIB_INCLUDE PREPEND "include/")
list(TRANSFORM LIB_SOURCE PREPEND "source/")

add_library(QuadEqlib SHARED
    ${LIB_INCLUDE}
    ${LIB_SOURCE}
)

target_include_directories(QuadEqlib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/source
)
