cmake_minimum_required(VERSION 3.13)
project(Actividad_Integradora_1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

enable_testing()

# Ejecutable principal
add_executable(Actividad_Integradora_1 main.cpp)

# Ejecutable de pruebas unitarias
add_executable(tests tests.cpp)

# Registrar pruebas para ctest
add_test(NAME RunTests COMMAND tests)
