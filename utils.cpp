#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>

#include "Graph.h"
#include "utils.h"

namespace utils
{
    // Функция для выполнения BFS и поиска расстояний от startVertex до всех остальных вершин
    std::unordered_map<int, int> bfsDistances(const Graph &graph, int startVertex)
    {
        std::unordered_map<int, int> distances;
        std::unordered_map<int, bool> seen;
        std::queue<int> q;
        std::unordered_map<int, std::vector<int>> adjList = graph.getAdjList();

        // Начинаем с начальной вершины
        distances[startVertex] = 0;
        q.push(startVertex);

        while (!q.empty())
        {
            int currentVertex = q.front();
            q.pop();
            seen[currentVertex] = true;
            std::vector<int> neighbors = adjList[currentVertex];
            // Обходим всех соседей текущей вершины
            for (int neighbor : neighbors)
            {
                if (!seen[neighbor])
                {                                                       // Если сосед ещё не посещён
                    distances[neighbor] = distances[currentVertex] + 1; // Увеличиваем расстояние
                    seen[neighbor] = true;
                    q.push(neighbor); // Добавляем соседа в очередь
                }
            }
        }

        return distances;
    }

    std::vector<std::string> split_string(const std::string &str, char delim = ' ')
    {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, delim))
        {
            if (!token.empty())
                tokens.push_back(token);
        }
        return tokens;
    }
} // namespace utils