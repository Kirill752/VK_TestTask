#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <memory>
#include <unordered_map>

#include "Graph/Graph.h"
#include "Validation/validation.h"
#include "Utils/utils.h"

int main()
{
    const std::string filename = "./graph.txt";
    std::ifstream in; 
    in.open(filename, std::ios::in);

    /*Валидация данных*/
    try {
        validation::file(filename);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    /*Считывание данных и формирование графа*/
    std::string line;
    std::getline(in, line);
    int n = std::stoi(line);
    auto g = std::make_unique<Graph>(n);
    // Считываем количество ребер
    std::getline(in, line);
    int r = std::stoi(line);
    for (int i = 0; i < r; i++) {
        std::getline(in, line);
        std::vector<std::string> nodes = utils::split_string(line, ' ');
        g->add(std::stoi(nodes[0]), std::stoi(nodes[1]));
    }
    // Считываем от какого ребра считать расстояние
    std::getline(in, line);
    int startVertex = std::stoi(line);
    in.close();

    /*Основной рассчет*/
    std::vector<int> res = utils::bfsDistances(*g, startVertex);

    /*Вывод результата*/
    // g->printGraph();s
    for (size_t i = 0; i < res.size(); i++)    
    {
        std::cout << res[i] << std::endl;
    }
}