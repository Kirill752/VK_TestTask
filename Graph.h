#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

template <typename T>
class Graph
{
private:
    int numVertices;
    std::unordered_map<T, std::vector<T>> adjList;

public:
    Graph() {}
    Graph(int numVertices_);
    ~Graph() {};
    // Добавление ребра между вершинами v и u
    void add(T v, T u);
    // Удаление ребра между v и u
    void remove(T v, T u);
    void printGraph();
    int getNumVrtices() const { return numVertices; }
    std::unordered_map<T, std::vector<T>> getAdjList() const { return adjList; }
};

template <typename T>
Graph<T>::Graph(int numVertices_) : numVertices(numVertices_)
{
    adjList.reserve(numVertices_);
};

template <typename T>
void Graph<T>::add(T src, T dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

template <typename T>
void Graph<T>::printGraph()
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