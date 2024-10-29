cmake_minimum_required(VERSION 3.10.2)
PROJECT(hello_world_project)

#Сборка библиотеки
#Создаю директорию для хранения библиотеки на выходе
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/library)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_BINARY_DIR}/library)

#Добавил заголовочные файлы
set(LIB_INCLUDE
   quad_eq.hpp
)

#Добавил исходники
set(LIB_SOURCE
   quad_eq.cpp
)

#Добавляю префиксы для указания верных путей при добавлении к библиотеке
list(TRANSFORM LIB_INCLUDE PREPEND "lib/include/")
list(TRANSFORM LIB_SOURCE PREPEND "lib/source/")

#Создаю библиотеку
add_library(QuadEqlib STATIC)

#Добавляю исходники в библиотеку
target_sources(QuadEqlib PRIVATE
    ${LIB_INCLUDE}
    ${LIB_SOURCE})

#Пути для компактного включения заголовочных файлов
include_directories(QuadEqlib PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/source
)

 #Включаю поддержку тестирования
enable_testing()

#Добавляю исходники googletest-ов в проект
add_subdirectory(googletest)

#Создаю директорию для хранения исполняемого файла
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tests)

#Добавляю все файлы в проект
set(TEST_SOURCE
    test_main.cpp
    test_quadEq.cpp
)

#Добавляю префикс "tests/" к исходникам для указания верного пути
list(TRANSFORM TEST_SOURCE PREPEND "tests/")

#Создаю исполняемый файл
add_executable(QuadEq_Tests
    ${TEST_SOURCE}
)

#Линкую проект со своей библиотекой и googletest
target_link_libraries(QuadEq_Tests PRIVATE
    GTest::gtest_main
    QuadEqlib
)

#Сборка демо приложения
#Создаю директорию для исполняемых файлов
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/QuadEq)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}/QuadEq)

#Добавляю исходники
set(APP_SOURCE
    main.cpp
)

#Добавляю префиксык исходникам для указания верных путей
list(TRANSFORM APP_INCLUDE PREPEND "app/include/")
list(TRANSFORM APP_SOURCE PREPEND "app/source/")

#Создаю исполняемый файл для графического приложения
add_executable(QuadEq
    ${APP_INCLUDE}
    ${APP_SOURCE}
)

#Пути для компактного включения заголовочных файлов
include_directories(QuadEq PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/app/include
    ${CMAKE_CURRENT_SOURCE_DIR}/app/source
)

#Линкую библиотеки
target_link_libraries(QuadEq PRIVATE
    QuadEqlib
)