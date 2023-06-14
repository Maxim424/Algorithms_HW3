//
// Created by Максим Кузнецов on 09.06.2023.
//

#ifndef ALGORITHMS_HW3_GENERATE_GRAPH_H
#define ALGORITHMS_HW3_GENERATE_GRAPH_H

#include <vector>
#include <random>
#include "edge_struct.h"

std::vector<std::vector<Edge>> generateTreeGraph(int n);

std::vector<std::vector<Edge>> generateConnectedGraph(int n);

std::vector<std::vector<Edge>> generateCompleteGraph(int n);

int countEdges(const std::vector<std::vector<Edge>> &graph);

#endif //ALGORITHMS_HW3_GENERATE_GRAPH_H
