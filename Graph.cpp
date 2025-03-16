#include "Graph.h"

Graph::Graph(int numVertices_) : numVertices(numVertices_)
{
    adjList.reserve(numVertices_);
};

void Graph::add(int src, int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void Graph::printGraph()
{
    for (const auto &[vertex, neighbors] : adjList)
    {
        std::cout << "Вершина " << vertex << " соединена с: ";
        for (int neighbor : neighbors)
        {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}