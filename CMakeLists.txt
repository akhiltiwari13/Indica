cmake_minimum_required(VERSION 3.10)

project(competitive_programming)
set(CMAKE_CXX_STANDARD 20)

MESSAGE(STATUS "***competitive_programming*** ${PROJECT_SOURCE_DIR}")

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # set(MACOSX TRUE)
    include_directories(${CMAKE_SOURCE_DIR}/osx_inc/)
endif()

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED COMPONENTS)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    MESSAGE(STATUS "***boost found!*** ${Boost_INCLUDE_DIR}")
endif()


add_subdirectory(CSES.fiProblemSet)
add_subdirectory(TheBook)
add_subdirectory(EOPI)
add_subdirectory(ADTImpl)
add_subdirectory(MyCodeSchool)
add_subdirectory(CppFeatures)
add_subdirectory(AssortedProblems)
add_subdirectory(TMCC)
add_subdirectory(malloncpp)
add_subdirectory(nptel_cpp)

