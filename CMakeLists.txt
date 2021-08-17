cmake_minimum_required(VERSION 3.20)
project(computation C)
set(CMAKE_C_STANDARD 99)
add_executable(computation main.c headerComput.h algorit.h pointerH.h pointer.c)

find_package(GSL REQUIRED)
target_link_libraries(computation PRIVATE GSL::gsl GSL::gslcblas)
find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(computation PRIVATE unofficial::sqlite3::sqlite3)