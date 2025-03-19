#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "validation.h"
#include "Utils/utils.h"

namespace validation
{
    void file(const std::string &filename)
    {
        std::ifstream file(filename);

        if (!file.is_open())
        {
            throw std::runtime_error("error: failed to open file");
        }

        std::string line;
        // Валидация первой строки (количество вершин)
        std::getline(file, line);
        one_number(line);
        int numVertices = 0;
        try
        {
            numVertices = std::stoi(line);
        }
        catch (const std::invalid_argument &e)
        {
            throw std::runtime_error("error: invalid number of vertices");
        }

        // Валидация второй строки (количество ребер)
        std::getline(file, line);
        one_number(line);
        int numEdges = 0;
        try
        {
            numEdges = std::stoi(line);
        }
        catch (const std::invalid_argument &e)
        {
            throw std::runtime_error("error: invalid number of edges");
        }
        // Валидайция ввода ребер
        for (int i = 0; i < numEdges; i++)
        {
            std::getline(file, line);
            edge(numVertices, line);
        }
        // Валидация последней строки (стартовая вершина)
        std::getline(file, line);
        one_number(line);
        int startVertex = 0;
        try
        {
            startVertex = std::stoi(line);
        }
        catch (const std::invalid_argument &e)
        {
            throw std::runtime_error("error: invalid start Vertex");
        }
        if (startVertex >= numVertices)
        {
            throw std::runtime_error("error: invalid start Vertex");
        }
        
        // Валидация конца файла
        if (!file.eof())
        {
            throw "error: invalid number of rows";
        }
    };

    void one_number(const std::string &str)
    {
        for (size_t i = 0; i < str.size(); i++)
        {
            if (!std::isdigit(str[i]))
            {
                throw std::runtime_error("error: row must include only one number");
            }
        }
    };

    void edge(const int n, const std::string &str)
    {
        std::vector<std::string> nodes = utils::split_string(str, ' ');
        if (nodes.size() != 2)
        {
            throw std::runtime_error("error: edge must contain two nodes");
        }
        for (size_t i = 0; i < nodes.size(); i++)
        {
            one_number(nodes[i]);
            int nodeIdx = std::stoi(nodes[i]);
            if (nodeIdx >= n)
            {
                throw std::runtime_error("error: invalid node index");
            }
        }
    };
} // namespace validation
