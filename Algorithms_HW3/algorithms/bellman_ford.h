//
// Created by Максим Кузнецов on 14.06.2023.
//

#ifndef ALGORITHMS_HW3_BELLMAN_FORD_H
#define ALGORITHMS_HW3_BELLMAN_FORD_H

#include <vector>
#include <limits>
#include "../utilities/edge_struct.h"

void bellmanFord(std::vector<std::vector<Edge>> &graph, int source, int stock);

#endif //ALGORITHMS_HW3_BELLMAN_FORD_H
