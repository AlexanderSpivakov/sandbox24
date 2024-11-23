set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../QuadEq)

set(APP_SOURCE
    main.cpp
)

set(APP_INCLUDE
    quad_eq.hpp
)

list(TRANSFORM APP_SOURCE PREPEND "source/")
list(TRANSFORM APP_INCLUDE PREPEND "../lib/include/")

add_executable(QuadEq
    ${APP_SOURCE}
    ${APP_INCLUDE}
)

include_directories(QuadEq PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/include
)
