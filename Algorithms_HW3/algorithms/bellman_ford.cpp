//
// Created by Максим Кузнецов on 14.06.2023.
//

#include <iostream>
#include "bellman_ford.h"

void bellmanFord(std::vector<std::vector<Edge>> &graph, int source, int stock) {
    int n = static_cast<int>(graph.size());
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    dist[source] = 0;
    bool any = true;
    for (int i = 0; i < n - 1 && any; ++i) {
        any = false;
        for (int u = 0; u < n; ++u) {
            for (const Edge &edge: graph[u]) {
                int v = edge.to;
                int weight = edge.weight;
                if (dist[u] != std::numeric_limits<int>::max() &&
                    dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    any = true;
                }
            }
        }
    }
//    std::cout << "[Беллман-Форд] Кратчайшее расстояние от вершины " << source << " до вершины " << stock << " равно "
//          << dist[stock] << "\n";
}