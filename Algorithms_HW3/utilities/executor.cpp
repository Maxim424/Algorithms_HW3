//
// Created by Максим Кузнецов on 12.06.2023.
//

#include "executor.h"

#define SIZE 3

void execute(std::ofstream &fout, decltype(dijkstra) func) {
    fout
            << "vertices;tree graph edges;tree graph time;connected graph edges;"
            << "connected graph time;complete graph edges;complete graph time\n";

    for (int n = 10; n < 1011; n += 50) {
        std::cout << "vertices = " << n << "\n";
        std::vector<std::vector<Edge>> tree_graph = generateTreeGraph(n);
        std::vector<std::vector<Edge>> connected_graph = generateConnectedGraph(n);
        std::vector<std::vector<Edge>> complete_graph = generateCompleteGraph(n);

        // tree graph
        auto *tree_graph_time = new std::chrono::nanoseconds[SIZE];
        for (int k = 0; k < SIZE; ++k) {
            auto start = std::chrono::high_resolution_clock::now();
            func(tree_graph, 0, n - 1);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            tree_graph_time[k] = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
        }
        std::chrono::nanoseconds tree_graph_sum = {};
        for (int k = 0; k < SIZE; ++k) {
            tree_graph_sum += tree_graph_time[k];
        }
        fout << n << ";" << countEdges(tree_graph) << ";" << (tree_graph_sum / SIZE).count() << ";";

        // connected graph
        auto *connected_graph_time = new std::chrono::nanoseconds[SIZE];
        for (int k = 0; k < SIZE; ++k) {
            auto start = std::chrono::high_resolution_clock::now();
            func(connected_graph, 0, n - 1);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            connected_graph_time[k] = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
        }
        std::chrono::nanoseconds connected_graph_sum = {};
        for (int k = 0; k < SIZE; ++k) {
            connected_graph_sum += connected_graph_time[k];
        }
        fout << countEdges(connected_graph) << ";" << (connected_graph_sum / SIZE).count() << ";";

        // complete graph
        auto *complete_graph_time = new std::chrono::nanoseconds[SIZE];
        for (int k = 0; k < SIZE; ++k) {
            auto start = std::chrono::high_resolution_clock::now();
            func(complete_graph, 0, n - 1);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            complete_graph_time[k] = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
        }
        std::chrono::nanoseconds complete_graph_sum = {};
        for (int k = 0; k < SIZE; ++k) {
            complete_graph_sum += complete_graph_time[k];
        }
        fout << countEdges(complete_graph) << ";" << (complete_graph_sum / SIZE).count() << ";";

        fout << "\n";
    }

    fout.close();
}