cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

add_executable(dfs dfs.cpp)
add_executable(bfs bfs.cpp)
add_executable(graphConnectivity graphConnectivity.cpp)
add_executable(cycleDetection cycleDetection.cpp)
add_executable(bipartiteColoring bipartiteColoring.cpp)
add_executable(bellmanFord bellmanFord.cpp)
add_executable(floydWarshall floydWarshall.cpp)
add_executable(topologicalSort topologicalSort.cpp)
