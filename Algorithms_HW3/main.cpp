// Все алгоритмы взяты из решений контеста №14 и лекций М.К. Горденко и немного доработаны так,
// чтобы в каждом алгоритме граф был представлен в виде списка смежности типа std::vector<std::vector<Edge>>.

#include <iostream>
#include <fstream>
#include "utilities/executor.h"

int main() {
    std::ofstream fout;
    std::cout << "dijkstra\n";
    fout.open("../tables/dijkstra.csv");
    execute(fout, dijkstra);
    std::cout << "floydWarshall\n";
    fout.open("../tables/floydWarshall.csv");
    execute(fout, floydWarshall);
    std::cout << "bellmanFord\n";
    fout.open("../tables/bellmanFord.csv");
    execute(fout, bellmanFord);
    std::cout << "vectorDijkstra\n";
    fout.open("../tables/vectorDijkstra.csv");
    execute(fout, vectorDijkstra);
}
