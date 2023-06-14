//
// Created by Максим Кузнецов on 13.06.2023.
//

#ifndef ALGORITHMS_HW3_FLOYD_WARSHALL_H
#define ALGORITHMS_HW3_FLOYD_WARSHALL_H
#include <vector>
#include <limits>
#include "../utilities/edge_struct.h"

void floydWarshall(std::vector<std::vector<Edge>> &graph, int source, int stock);

#endif //ALGORITHMS_HW3_FLOYD_WARSHALL_H
