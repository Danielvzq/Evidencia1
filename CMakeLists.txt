cmake_minimum_required(VERSION 3.13)
project(Actividad_Integradora_1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

enable_testing()

add_executable(Actividad_Integradora_1 main.cpp)
add_executable(tests tests.cpp) # Archivo de pruebas unitarias

add_test(NAME RunTests COMMAND tests)
