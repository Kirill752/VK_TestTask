#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "extern/catch.hpp"
#include "utils.h"
#include "Graph.h"

// struct testCase
// {
//     Graph g;
//     std::unordered_map<int, int> expexted_res;
// };

TEST_CASE("Can be constructed", "[Graph]")
{
    std::unordered_map<int, std::vector<int>> AdjList;

    Graph g1;
    REQUIRE(g1.getNumVrtices() == 0);
    REQUIRE(g1.getAdjList() == AdjList);

    Graph g2(5);
    g2.add(0, 1);
    g2.add(0, 4);
    g2.add(1, 2);
    g2.add(1, 3);
    AdjList = {
        {0, {1, 4}},
        {1, {0, 2, 3}},
        {2, {1}},
        {3, {1}},
        {4, {0}}};
    REQUIRE(g2.getNumVrtices() == 5);
    REQUIRE(g2.getAdjList() == AdjList);

    Graph g3(3, {{0, {1, 2}},
                 {1, {0, 2}},
                 {2, {0, 1}}});
    AdjList = {{0, {1, 2}},
               {1, {0, 2}},
               {2, {0, 1}}};
    REQUIRE(g3.getNumVrtices() == 3);
    REQUIRE(g3.getAdjList() == AdjList);
}

TEST_CASE("Simple test", "[distance]")
{
    std::unordered_map<int, int> res;
    Graph g1(5, {{0, {1, 4}},
                {1, {0, 2, 3}},
                {2, {1}},
                {3, {1}},
                {4, {0}}});
    res = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 3},
        {4, 0},
    };
    REQUIRE(utils::bfsDistances(g1, 4) == res);
}