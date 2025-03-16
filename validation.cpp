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
        // std::vector<std::string> nums = utils::split_string(line, ' ');
        // if (nums.size() > 1)
        // {
        //     throw "error: first row must include only one number";
        // }
        // if (nums[0].find_first_not_of("0123456789") != nums[0].npos)
        // {
        //     throw "error: first row must include only number";
        // }
        // во второй строке должно быть одно число
        std::getline(file, line);
        nums = utils::split_string(line, ' ');
        if (nums.size() > 1)
        {
            throw "error: second row must include only one number";
        }
        if (nums[0].find_first_not_of("0123456789") != nums[0].npos)
        {
            throw "error: second row must include only number";
        }
        // Валидайция ввода ребер графа
        // число ребер
        int r = std::stoi(nums[0]);
        for (int i = 0; i < r; i++)
        {
            std::getline(file, line);
            std::vector<std::string> nodes = utils::split_string(line, ' ');
            if (nodes.size() != 2)
            {
                throw "error: edge must contain two nodes";
            }
        }
        // в последней строке должно быть одно число
        std::getline(file, line);
        nums = utils::split_string(line, ' ');
        if (nums.size() > 1)
        {
            throw "error: last row must include only one number";
        }
        if (nums[0].find_first_not_of("0123456789") != nums[0].npos)
        {
            throw "error: last row must include only number";
        }
        if (!file.eof())
        {
            throw "error: invalid number of rows";
        }
    };
    void one_number(const std::string& str) {
        for (size_t i = 0; i < str.size(); i++)
        {
            if (!std::isdigit(str[i]))
            {
                throw "error: row must include only one number";
            }  
        }
    };
} // namespace validation
