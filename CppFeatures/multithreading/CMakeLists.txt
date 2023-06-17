add_executable(thread01 Threads.cpp)
add_executable(LowLevelThreadFeature LowLevelThreadFeature.cpp)
add_executable(Promise Promise.cpp)
add_executable(Mutex Mutex.cpp)

add_executable(stdthreadbasics01 stdthreadbasics01.cpp)



#link thread libraries.
target_link_libraries(thread01 PUBLIC pthread)
target_link_libraries(LowLevelThreadFeature PUBLIC pthread)
target_link_libraries(Promise PUBLIC pthread)
target_link_libraries(Mutex PUBLIC pthread)
