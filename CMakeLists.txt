cmake_minimum_required(VERSION 3.13)
project(Actividad_Integradora_1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

enable_testing()

# Descargar GoogleTest si no está disponible
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Evitar instalar tests de GoogleTest para evitar warnings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Actividad_Integradora_1 main.cpp)

add_executable(tests tests.cpp)

# Linkear GoogleTest al ejecutable tests
target_link_libraries(tests gtest_main)

# Registrar test para ctest
add_test(NAME RunTests COMMAND tests)
