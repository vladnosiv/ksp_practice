#pragma once

#include <algorithm>

#define GRID_SIZE 3

class Grid{
private:
    char a[GRID_SIZE][GRID_SIZE];
public:
    Grid() {}
    Grid(char filler);
    char& operator()(std::size_t i, std::size_t j);
    char& operator()(std::pair < std::size_t, std::size_t > x);
    char get_winner();
    inline bool check(int x1, int y1, int x2, int y2, char c);
};

class Logic {
public:
    Logic() {}
    Logic(Grid& x);
    Logic(Grid&& x);
    std::pair < std::size_t, std::size_t > get_turn();
public:
    Grid grid;
};

