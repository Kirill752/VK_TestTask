#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "validation.h"
#include "utils.h"

namespace validation
{
    void file(const std::string &filename)
    {
        std::vector<std::string> nums;
        std::string line;
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw "error open file";
        }
        // в первой строке должно быть одно число
        std::getline(file, line);
        one_number(line);
        int n = std::stoi(line);
        // во второй строке должно быть одно число
        std::getline(file, line);
        one_number(line);
        // Валидайция ввода ребер графа
        int r = std::stoi(line);
        for (int i = 0; i < r; i++)
        {
            std::getline(file, line);
            edge(n, line);
        }
        // в последней строке должно быть одно число
        std::getline(file, line);
        one_number(line);
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
                throw "error: row must include only one number";
            }
        }
    };

    void edge(const int n, const std::string &str) {
        std::vector<std::string> nodes = utils::split_string(str, ' ');
        if (nodes.size() != 2)
        {
            throw "error: edge must contain two nodes";
        }
        for (size_t i = 0; i < nodes.size(); i++)
        {
            one_number(nodes[i]);
            int nodeIdx = std::stoi(nodes[i]);
            if (nodeIdx >= n) {
                throw "invalid node index";
            }
        }
    };
} // namespace validation
