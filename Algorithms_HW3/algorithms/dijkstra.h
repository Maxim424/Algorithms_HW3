//
// Created by Максим Кузнецов on 09.06.2023.
//

#ifndef ALGORITHMS_HW3_DIJKSTRA_H
#define ALGORITHMS_HW3_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <queue>
#include "../utilities/edge_struct.h"

void dijkstra(std::vector<std::vector<Edge>> &graph, int source, int stock);

void vectorDijkstra(std::vector<std::vector<Edge>> &graph, int source, int stock);

#endif //ALGORITHMS_HW3_DIJKSTRA_H
