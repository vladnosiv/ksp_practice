#include "logic.hpp"
#include <algorithm>
#include <vector>

grid::grid(char filler) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = filler;
        }
    }
}

char& grid::operator() (size_t i, size_t j) {
    return a[i][j];
}

char& grid::operator() (std::pair<size_t, size_t> x) {
    return a[x.first][x.second];
}

bool grid::check(int x1, int y1, int x2, int y2, char c) {
    return a[x1][y1] == a[x2][y2] && a[x2][y2] == c;
}

char grid::get_winner() {
    for (int i = 0; i < 3; i++) { // check rows
        char c = a[i][0];
        bool flag = true;
        for (int j = 1; j < 3 && flag; j++) {
            flag &= (a[i][j] == c);
        }
        if (flag && c != '.') {
            return c;
        }
    }

    for (int j = 0; j < 3; j++) { // check columns
        char c = a[0][j];
        bool flag = true;
        for (int i = 1; i < 3 && flag; i++) {
            flag &= (a[i][j] == c);
        }
        if (flag && c != '.') {
            return c;
        }
    }

    char c = a[0][0];
    bool flag = true;

    for (int i = 1; i < 3 && flag; i++) { // check diagonals
        flag &= (a[i][i] == c);
    }
    if (flag && c != '.') {
        return c;
    }

    if (a[2][0] == a[1][1] && a[1][1] == a[0][2] && a[1][1] != '.') {
        return a[1][1];
    }

    flag = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            flag &= (a[i][j] != '.');
        }
    }

    if (flag) {
        return 'd'; // draw
    }

    // none
    return '.';
}

logic::logic(grid x) : a(x) {}

const std::vector < std::pair < size_t, size_t > > angles = { { 0, 0 }, { 0, 2 }, { 2, 2 }, { 2, 0 } };
const std::vector < std::pair < size_t, size_t > > sides = { { 1, 0 }, { 0, 1 }, { 1, 2 }, { 2, 1 } };

std::pair < size_t, size_t > logic::get_turn() {
    for (int i = 0; i < 3; i++) {                           // o o .   and   . o o   and   o . o
        if (a.check(i, 0, i, 1, 'o') && a(i, 2) == '.') {
            return { i, 2 };
        }
        if (a.check(i, 1, i, 2, 'o') && a(i, 0) == '.') {
            return { i, 0 };
        }
        if (a.check(i, 0, i, 2, 'o') && a(i, 1) == '.') {
            return { i, 1 };
        }
    }

    for (int j = 0; j < 3; j++) {                            // o         .          o
        if (a.check(0, j, 1, j, 'o') && a(2, j) == '.') {    // o   and   o    and   .
            return { 2, j };                                 // .         o          o
        }
        if (a.check(1, j, 2, j, 'o') && a(0, j) == '.') {
            return { 0, j };
        }
        if (a.check(0, j, 2, j, 'o') && a(1, j) == '.') {
            return { 1, j };
        }
    }

    if (a.check(0, 0, 1, 1, 'o') && a(2, 2) == '.') {
        return { 2, 2 };
    }
    if (a.check(1, 1, 2, 2, 'o') && a(0, 0) == '.') {
        return { 0, 0 };
    }
    if (a.check(0, 0, 2, 2, 'o') && a(1, 1) == '.') {
        return { 1, 1 };
    }
    if (a.check(0, 2, 1, 1, 'o') && a(2, 0) == '.') {
        return { 2, 0 };
    }
    if (a.check(1, 1, 2, 0, 'o') && a(0, 2) == '.') {
        return { 0, 2 };
    }
    if (a.check(0, 2, 2, 0, 'o') && a(1, 1) == '.') {
        return { 1, 1 };
    }


    for (int i = 0; i < 3; i++) {                           // x x .   and   . x x   and   x . x
        if (a.check(i, 0, i, 1, 'x') && a(i, 2) == '.') {
            return { i, 2 };
        }
        if (a.check(i, 1, i, 2, 'x') && a(i, 0) == '.') {
            return { i, 0 };
        }
        if (a.check(i, 0, i, 2, 'x') && a(i, 1) == '.') {
            return { i, 1 };
        }
    }

    for (int j = 0; j < 3; j++) {                            // x         .          x
        if (a.check(0, j, 1, j, 'x') && a(2, j) == '.') {    // x   and   x    and   .
            return { 2, j };                                 // .         x          x
        }
        if (a.check(1, j, 2, j, 'x') && a(0, j) == '.') {
            return { 0, j };
        }
        if (a.check(0, j, 2, j, 'x') && a(1, j) == '.') {
            return { 1, j };
        }
    }

    if (a.check(0, 0, 1, 1, 'x') && a(2, 2) == '.') {
        return { 2, 2 };
    }
    if (a.check(1, 1, 2, 2, 'x') && a(0, 0) == '.') {
        return { 0, 0 };
    }
    if (a.check(0, 0, 2, 2, 'x') && a(1, 1) == '.') {
        return { 1, 1 };
    }
    if (a.check(0, 2, 1, 1, 'x') && a(2, 0) == '.') {
        return { 2, 0 };
    }
    if (a.check(1, 1, 2, 0, 'x') && a(0, 2) == '.') {
        return { 0, 2 };
    }
    if (a.check(0, 2, 2, 0, 'x') && a(1, 1) == '.') {
        return { 1, 1 };
    }


    if (a(1, 1) != '.') {
        if (a(1, 1) == 'x') {
            for (auto x : angles) {
                if (a(x) == '.') {
                    return x;
                }
            }

            for (auto x : sides) {
                if (a(x) == '.') {
                    return x;
                }
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                if ((a(angles[(i + 3) % 4]) == 'x' || a(angles[(i + 1) % 4]) == 'x') && a(angles[i]) == '.') {
                    return angles[i];
                }
            }
            for (int i = 0; i < 4; i++) {
                if (a(sides[i]) == 'x' && a(sides[(i + 1) % 4]) == 'x') {
                    if (i % 2 == 0) {
                        return { sides[i].second, sides[(i + 1) % 4].first };
                    }
                    else {
                        return { sides[i].first, sides[(i + 1) % 4].second };
                    }
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (a(i, j) == '.') {
                        return { i, j };
                    }
                }
            }
        }
    }
    else {
        return { 1, 1 };
    }

    return { 4, 4 };
}
