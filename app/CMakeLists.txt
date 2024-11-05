file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QuadEq)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QuadEq)

set(APP_SOURCE
    main.cpp
)

list(TRANSFORM APP_SOURCE PREPEND "source/")

add_executable(QuadEq
    ${APP_SOURCE}
)

include_directories(QuadEq PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/source
)

target_link_libraries(QuadEq LINK_PUBLIC QuadEqlib)
