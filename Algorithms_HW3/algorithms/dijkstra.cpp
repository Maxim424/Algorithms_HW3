//
// Created by Максим Кузнецов on 09.06.2023.
//

#include "dijkstra.h"

const int INF = 1e9;

void dijkstra(std::vector<std::vector<Edge>> &graph, int source, int stock) {
    int n = static_cast<int>(graph.size());
    std::vector<int> distances;
    distances.resize(n, INF);
    distances[source] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, source);
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (const Edge &edge: graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.emplace(distances[v], v);
            }
        }
    }
//    std::cout << "[Дейкстра] Кратчайшее расстояние от вершины " << source << " до вершины " << stock << " равно "
//              << distances[stock] << "\n";
}

int minDistance(std::vector<int> &dist, std::vector<bool> &visited) {
    int mn_dist = std::numeric_limits<int>::max();
    int mn_vertex = -1;
    int n = static_cast<int>(dist.size());
    for (int v = 0; v < n; ++v) {
        if (!visited[v] && dist[v] < mn_dist) {
            mn_dist = dist[v];
            mn_vertex = v;
        }
    }
    return mn_vertex;
}

void vectorDijkstra(std::vector<std::vector<Edge>> &graph, int source, int stock) {
    int n = static_cast<int>(graph.size());
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<bool> visited(n, false);
    dist[source] = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (const Edge &edge: graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (!visited[v] && dist[u] != std::numeric_limits<int>::max() &&
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
//    std::cout << "[Дейкстра на массиве] Кратчайшее расстояние от вершины " << source << " до вершины " << stock << " равно "
//          << dist[stock] << "\n";
}