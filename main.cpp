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

    try {
        validation::file(filename);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    std::string line;
    std::getline(in, line);
    int n = std::stoi(line);
    auto graph = std::make_unique<Graph>(n);
    std::getline(in, line);
    int r = std::stoi(line);
    for (int i = 0; i < r; i++) {
        std::getline(in, line);
        std::vector<std::string> nodes = utils::split_string(line, ' ');
        graph->add(std::stoi(nodes[0]), std::stoi(nodes[1]));
    }
    std::getline(in, line);
    int startVertex = std::stoi(line);
    in.close();

    std::vector<int> res = utils::bfsDistances(*graph, startVertex);

    for (size_t i = 0; i < res.size(); i++)    
    {
        std::cout << res[i] << std::endl;
    }
}