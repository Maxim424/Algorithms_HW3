//
// Created by Максим Кузнецов on 09.06.2023.
//

#include <iostream>
#include "generate_graph.h"

std::vector<std::vector<Edge>> generateTreeGraph(int n) {
    std::vector<std::vector<Edge>> graph(n);
    for (int i = 1; i < n; i++) {
        int parent = rand() % i;
        int weight = rand() % 10 + 1;
        graph[parent].push_back({i, weight});
        graph[i].push_back({parent, weight});
    }
    return graph;
}

bool hasEdge(const std::vector<std::vector<Edge>> &graph, int u, int v) {
    for (const Edge &edge: graph[u]) {
        if (edge.to == v) {
            return true;
        }
    }
    return false;
}

int countEdges(const std::vector<std::vector<Edge>> &graph) {
    int edgeCount = 0;
    for (const std::vector<Edge> &edges: graph) {
        edgeCount += static_cast<int>(edges.size());
    }
    edgeCount /= 2;
    return edgeCount;
}

std::vector<std::vector<Edge>> generateConnectedGraph(int n) {
    std::vector<std::vector<Edge>> graph(n);
    srand(time(nullptr));
    std::vector<int> vertices(n);
    for (int i = 0; i < n; i++) {
        vertices[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() % (n - i);
        std::swap(vertices[i], vertices[j]);
    }
    for (int i = 0; i < n - 1; i++) {
        int u = vertices[i];
        int v = vertices[i + 1];
        bool exists = false;
        for (const Edge &edge: graph[u]) {
            if (edge.to == v) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            int weight = rand() % 10 + 1;
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }
    }
    int mx_edges = n * (n - 1) / 2;
    int desired_edges = mx_edges / 2;
    while (countEdges(graph) < desired_edges) {
        int u = rand() % n;
        int v = rand() % n;
        if (u != v && !hasEdge(graph, u, v)) {
            int weight = rand() % 10 + 1;
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }
    }
    return graph;
}

std::vector<std::vector<Edge>> generateCompleteGraph(int n) {
    std::vector<std::vector<Edge>> graph(n);
    srand(time(nullptr));
    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            int weight = rand() % 10 + 1;
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }
    }
    return graph;
}
