#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <fstream>
#include <string>
#include "extern/catch.hpp"
#include "utils.h"
#include "Graph.h"
#include "validation.h"

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

TEST_CASE("Distance test", "[distance]")
{
    std::unordered_map<int, int> res;
    // Граф из одной вершины
    Graph g1(1, {{{0}, {}}});
    res = {
        {0, 0}};
    REQUIRE(utils::bfsDistances(g1, 0) == res);
    // Граф с одной компонентой связанности
    Graph g2(5, {{0, {1, 4}},
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
    REQUIRE(utils::bfsDistances(g2, 4) == res);
    // Граф с циклами
    Graph g3(2, {{0, {1}},
                 {1, {0}}});
    res = {
        {0, 0},
        {1, 1}};
    REQUIRE(utils::bfsDistances(g3, 0) == res);
    // Граф с петлями
    Graph g4(4, {{0, {1, 3}},
                 {1, {0, 2}},
                 {2, {1, 3}},
                 {3, {0, 2}}});
    res = {
        {0, 2},
        {1, 1},
        {2, 0},
        {3, 1}};
    REQUIRE(utils::bfsDistances(g4, 2) == res);
    // Петля в виде восьмерки
    Graph g5(7, {{0, {1, 3}},
                 {1, {0, 2}},
                 {2, {1, 3, 4, 6}},
                 {3, {0, 2}},
                 {4, {5, 2}},
                 {5, {4, 6}},
                 {6, {5, 2}}});
    res = {
        {0, 2},
        {1, 1},
        {2, 0},
        {3, 1},
        {5, 2},
        {4, 1},
        {6, 1}};
    REQUIRE(utils::bfsDistances(g5, 2) == res);
    // Граф в виде звезды
    Graph g6(7, {{0, {1, 2, 3, 4, 5, 6}}});
    res = {
        {0, 0},
        {1, 1},
        {2, 1},
        {3, 1},
        {5, 1},
        {4, 1},
        {6, 1}};
    REQUIRE(utils::bfsDistances(g6, 0) == res);
    // Гарф в виде цепочки
    Graph g7(11, {{0, {1}}, {1, {2}}, {2, {3}}, {3, {4}}, {4, {5}}, {5, {6}}, {6, {7}}, {7, {8}}, {8, {9}}, {9, {10}}});
    res = {{0, 0},
           {1, 1},
           {2, 2},
           {3, 3},
           {4, 4},
           {5, 5},
           {6, 6},
           {7, 7},
           {8, 8},
           {9, 9},
           {10, 10}};
    REQUIRE(utils::bfsDistances(g7, 0) == res);
}

TEST_CASE("Validation test", "[validation]")
{
    std::ifstream in;
    // Несуществующий файл
    REQUIRE_THROWS_WITH(validation::file("no_file.txt"), "error open file");

    // Валидация файла из примера
    in.open("./tests/test1.txt");
    REQUIRE_NOTHROW(validation::file("./tests/test1.txt"));
    in.close();

    // Валидация первой строки
    in.open("./tests/test2.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test2.txt"), "error: row must include only one number");
    in.close();

    in.open("./tests/test6.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test6.txt"), "error: row must include only one number");
    in.close();

    // Валидация второй строки
    in.open("./tests/test3.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test3.txt"), "error: row must include only one number");
    in.close();

    in.open("./tests/test7.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test7.txt"), "error: row must include only one number");
    in.close();

    // Валидация ввода ребер
    in.open("./tests/test4.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test4.txt"), "error: edge must contain two nodes");
    in.close();

    in.open("./tests/test8.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test8.txt"), "error: row must include only one number");
    in.close();

    in.open("./tests/test10.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test10.txt"), "error: invalid node index");
    in.close();

    // Валидация последней строки
    in.open("./tests/test5.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test5.txt"), "error: row must include only one number");
    in.close();

    in.open("./tests/test9.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test9.txt"), "error: row must include only one number");
    in.close();

    in.open("./tests/test11.txt");
    REQUIRE_THROWS_WITH(validation::file("./tests/test11.txt"), "error: invalid number of rows");
    in.close();
}