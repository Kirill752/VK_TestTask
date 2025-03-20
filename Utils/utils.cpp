#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>

#include "Graph/Graph.h"
#include "utils.h"

namespace utils
{
    std::vector<int> bfsDistances(const Graph &graph, int startVertex)
    {
        std::vector<int> distances(graph.getNumVrtices());
        std::unordered_map<int, bool> seen;
        std::queue<int> q;
        std::unordered_map<int, std::vector<int>> adjList = graph.getAdjList();

        distances[startVertex] = 0;
        q.push(startVertex);

        while (!q.empty())
        {
            int currentVertex = q.front();
            q.pop();
            seen[currentVertex] = true;
            std::vector<int> neighbors = adjList[currentVertex];
            for (int neighbor : neighbors)
            {
                if (!seen[neighbor])
                {                                                      
                    distances[neighbor] = distances[currentVertex] + 1; 
                    seen[neighbor] = true;
                    q.push(neighbor);
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
}