cmake_minimum_required(VERSION 3.10)

project(competitive_programming)
set(CMAKE_CXX_STANDARD 17)

MESSAGE(STATUS "***competitive_programming*** ${PROJECT_SOURCE_DIR}")

add_subdirectory(CSES.fiProblemSet)
add_subdirectory(TheBook)
add_subdirectory(EOPI)
add_subdirectory(ADTImpl)
add_subdirectory(MyCodeSchool)
add_subdirectory(CppFeatures)
add_subdirectory(AssortedProblems)
add_subdirectory(TheC++ProgrammingLangurge-4thEdition-AssignmentProblems)
