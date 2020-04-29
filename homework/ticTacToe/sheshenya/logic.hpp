#pragma once
#include <algorithm>

class grid{
private:
    char a[3][3];
public:
    grid(char filler);
    char& operator() (size_t i, size_t j);
    char& operator() (std::pair < size_t, size_t > x);
    char get_winner();
    bool check(int x1, int y1, int x2, int y2, char c);
};

class logic {
public:
    logic(grid x);
    std::pair < size_t, size_t > get_turn();
public:
    grid a;
};

