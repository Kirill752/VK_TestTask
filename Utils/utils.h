#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <unordered_map>

#include "Graph/Graph.h"

namespace utils
{
    // Функция для выполнения BFS и поиска расстояний от startVertex до всех остальных вершин
    std::vector<int> bfsDistances(const Graph &graph, int startVertex);
    std::vector<std::string> split_string(const std::string &str, char delim);
}
#endif