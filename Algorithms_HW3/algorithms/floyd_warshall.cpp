//
// Created by Максим Кузнецов on 13.06.2023.
//

#include <iostream>
#include "floyd_warshall.h"

void floydWarshall(std::vector<std::vector<Edge>> &graph, int source, int stock) {
    int n = static_cast<int>(graph.size());
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    for (int u = 0; u < n; ++u) {
        for (const Edge &edge: graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            dist[u][v] = weight;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != std::numeric_limits<int>::max() &&
                    dist[k][j] != std::numeric_limits<int>::max() &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
//    std::cout << "[Флойд-Уоршел] Кратчайшее расстояние от вершины " << source << " до вершины " << stock << " равно "
//              << dist[0][n - 1] << "\n";
}