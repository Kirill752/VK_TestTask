#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
#include "Graph.h"

// Функция для выполнения BFS и поиска расстояний от startVertex до всех остальных вершин
template <typename T>
std::unordered_map<T, int> bfsDistances(const Graph<T> &graph, T startVertex)
{
    std::unordered_map<T, int> distances;
    std::unordered_map<T, bool> seen;
    std::queue<int> q;
    std::unordered_map<T, std::vector<T>> adjList = graph.getAdjList();

    // Начинаем с начальной вершины
    distances[startVertex] = 0;
    q.push(startVertex);

    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop();
        seen[currentVertex] = true;
        std::vector<T> neighbors = adjList[currentVertex];
        // Обходим всех соседей текущей вершины
        for (int neighbor : neighbors)
        {
            if (!seen[neighbor])
            {                                                       // Если сосед ещё не посещён
                distances[neighbor] = distances[currentVertex] + 1; // Увеличиваем расстояние
                seen[neighbor] = true;
                q.push(neighbor);                                   // Добавляем соседа в очередь
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

int main()
{
    Graph<int> g;
    std::ifstream in;
    std::string line;
    int n, r;
    in.open("./graph.txt", std::ios::in);
    if (!in.is_open())
    {
        exit(1);
    }
    // TODO: добавить валидацию данных
    // Считываем количество вершин
    std::getline(in, line);
    n = std::stoi(line);
    // Считываем количество ребер
    std::getline(in, line);
    r = std::stoi(line);
    for (int i = 0; i < r; i++)
    {
        std::getline(in, line);
        std::vector<std::string> nodes = split_string(line);
        g.add(std::stoi(nodes[0]), std::stoi(nodes[1]));
    }
    g.printGraph();
    std::unordered_map<int, int> res = bfsDistances<int>(g, 0);
    for (const auto &[vertex, dist] : res)
    {
        std::cout << "Расстояние до " << vertex << " равно " << dist;
        std::cout << std::endl;
    }
}