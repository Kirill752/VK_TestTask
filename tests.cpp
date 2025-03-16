#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "extern/catch.hpp"
#include "utils.h"
#include "Graph.h"

struct testCase
{
    Graph g;
    std::unordered_map<int, int> expexted_res;
};


TEST_CASE("Simple test", "distance") {
    Graph g(5);
    g.add(0, 1);
    g.add(0, 4);
    g.add(1, 2);
    g.add(1, 3);
    std::unordered_map<int, int> res  = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 3},
        {4, 0},
    };
    REQUIRE(utils::bfsDistances(g, 4) == res);
}