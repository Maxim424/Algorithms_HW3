cmake_minimum_required(VERSION 3.25)
project(Algorithms_HW3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithms_HW3 main.cpp algorithms/dijkstra.cpp algorithms/dijkstra.h utilities/generate_graph.cpp utilities/generate_graph.h utilities/edge_struct.h utilities/executor.cpp utilities/executor.h algorithms/floyd_warshall.cpp algorithms/floyd_warshall.h algorithms/bellman_ford.cpp algorithms/bellman_ford.h)
