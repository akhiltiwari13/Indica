cmake_minimum_required(VERSION 3.10)

project(competitive_programming)
set(CMAKE_CXX_STANDARD 17)

MESSAGE(STATUS "***competitive_programming*** ${PROJECT_SOURCE_DIR}")

add_subdirectory(cses.fi_problemset)
add_subdirectory(the_book)
add_subdirectory(eopi)

MESSAGE(STATUS "***competitive_programming*** ${PROJECT_SOURCE_DIR}")
