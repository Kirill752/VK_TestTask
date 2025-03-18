#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <memory>
#include <unordered_map>

#include "Graph.h"
#include "validation.h"
#include "utils.h"

int main()
{
    const char *filename = "./graph.txt";
    std::ifstream in;
    std::string line;

    in.open(filename, std::ios::in);
    /*Валидация данных*/
    try
    {
        validation::file(filename);
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
        exit(1);
    }
    /*Считывание данных и формирование графа*/
    std::getline(in, line);
    int n = std::stoi(line);
    auto g = std::make_unique<Graph>(n);
    // Считываем количество ребер
    std::getline(in, line);
    int r = std::stoi(line);
    for (int i = 0; i < r; i++)
    {
        std::getline(in, line);
        std::vector<std::string> nodes = utils::split_string(line, ' ');
        g->add(std::stoi(nodes[0]), std::stoi(nodes[1]));
    }
    // Считываем от какого ребра считать расстояние
    std::getline(in, line);
    int startVertex = std::stoi(line);

    /*Основной рассчет*/
    std::unordered_map<int, int> res = utils::bfsDistances(*g, startVertex);

    /*Вывод результата*/
    g->printGraph();
    for (const auto &[vertex, dist] : res)
    {
        std::cout << "Расстояние до " << vertex << " равно " << dist;
        std::cout << std::endl;
    }
    in.close();
}