//
// Created by Максим Кузнецов on 12.06.2023.
//

#ifndef ALGORITHMS_HW3_EXECUTOR_H
#define ALGORITHMS_HW3_EXECUTOR_H

#include <fstream>
#include <vector>
#include "edge_struct.h"
#include "generate_graph.h"
#include "../algorithms/dijkstra.h"
#include "../algorithms/floyd_warshall.h"
#include "../algorithms/bellman_ford.h"

void execute(std::ofstream &fout, void (*func)(std::vector<std::vector<Edge>> &graph, int source, int stock));

#endif //ALGORITHMS_HW3_EXECUTOR_H
