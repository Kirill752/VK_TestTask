#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>

#include "Graph.h"
#include "validation.h"
#include "utils.h"

int main()
{
    const char *filename = "./graph.txt";
    Graph g;
    std::ifstream in;
    std::string line;
    int n, r;
    in.open(filename, std::ios::in);
    try
    {
        validation::file(filename);
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    // Считываем количество вершин
    std::getline(in, line);
    n = std::stoi(line);
    // Считываем количество ребер
    std::getline(in, line);
    r = std::stoi(line);
    for (int i = 0; i < r; i++)
    {
        std::getline(in, line);
        std::vector<std::string> nodes = utils::split_string(line, ' ');
        g.add(std::stoi(nodes[0]), std::stoi(nodes[1]));
    }
    g.printGraph();
    std::unordered_map<int, int> res = utils::bfsDistances(g, 0);
    for (const auto &[vertex, dist] : res)
    {
        std::cout << "Расстояние до " << vertex << " равно " << dist;
        std::cout << std::endl;
    }
}