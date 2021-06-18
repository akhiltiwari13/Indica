cmake_minimum_required(VERSION 3.10)
project(CPP_FEATURES)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComptProg ComptProg.cpp)
add_executable(MoveSemantics MoveSemantics.cpp)
add_executable(RuleOfFive RuleOfFive.cpp)
add_executable(RuleOfThree RuleOfThree.cpp)
add_executable(SmartPointers SmartPointers.cpp)
add_executable(io IO.cpp)
add_executable(Threads Threads.cpp)
add_executable(LowLevelThreadFeature LowLevelThreadFeature.cpp)
add_executable(Promise Promise.cpp)
add_executable(Mutex Mutex.cpp)

#link thread libraries.
target_link_libraries(Threads PUBLIC pthread)
target_link_libraries(LowLevelThreadFeature PUBLIC pthread)
target_link_libraries(Promise PUBLIC pthread)
target_link_libraries(Mutex PUBLIC pthread)
