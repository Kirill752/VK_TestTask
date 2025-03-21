#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

class Graph
{
private:
    int numVertices = 0;
    std::unordered_map<int, std::vector<int>> adjList;

public:
    Graph() {}
    Graph(int numVertices_);
    Graph(int numVertices_, std::unordered_map<int, std::vector<int>> adjList_) : numVertices(numVertices_),
                                                                                  adjList(adjList_) {}
    ~Graph() {};
    // Добавление ребра между вершинами v и u
    void add(int v, int u);
    void printGraph();
    int getNumVrtices() const { return numVertices; }
    std::unordered_map<int, std::vector<int>> getAdjList() const { return adjList; }
};
#endif