#include <algorithm>
#include <vector>
#include "logic.hpp"

Grid::Grid(char filler) {
    std::fill(&a[0][0], &a[GRID_SIZE - 1][GRID_SIZE - 1] + 1, filler);
}

char& Grid::operator()(std::size_t i, std::size_t j) {
    return a[i][j];
}

char& Grid::operator()(std::pair<std::size_t, std::size_t> x) {
    return a[x.first][x.second];
}

inline bool Grid::check(int x1, int y1, int x2, int y2, char ch) {
    return a[x1][y1] == a[x2][y2] && a[x2][y2] == ch;
}

char Grid::get_winner() {
    for (int i = 0; i < GRID_SIZE; i++) { // check rows
        char ch = a[i][0];
        bool flag = true;
        for (int j = 1; j < GRID_SIZE && flag; j++) {
            flag &= (a[i][j] == ch);
        }
        if (flag && ch != '.') {
            return ch;
        }
    }

    for (int j = 0; j < GRID_SIZE; j++) { // check columns
        char ch = a[0][j];
        bool flag = true;
        for (int i = 1; i < GRID_SIZE && flag; i++) {
            flag &= (a[i][j] == ch);
        }
        if (flag && ch != '.') {
            return ch;
        }
    }

    char ch = a[0][0];
    bool flag = true;

    for (int i = 1; i < GRID_SIZE && flag; i++) { // check one diagonal
        flag &= (a[i][i] == ch);
    }

    if (flag) {
        return ch;
    }

    ch = a[GRID_SIZE - 1][0];
    flag = true;
    for (int i = GRID_SIZE - 2, j = 1; i >= 0 && flag; i--, j++) { // check another
        flag &= (a[i][j] == ch);
    }

    if (flag) {
        return ch;
    }


    flag = true;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            flag &= (a[i][j] != '.');
        }
    }

    if (flag) {
        return 'd'; // draw
    }

    // none
    return '.';
}

Logic::Logic(Grid& grid) : grid(grid) {}
Logic::Logic(Grid&& grid) : grid(grid) {}

const std::vector < std::pair < std::size_t, std::size_t > > angles = { { 0, 0 }, { 0, 2 }, { 2, 2 }, { 2, 0 } };
const std::vector < std::pair < std::size_t, std::size_t > > sides = { { 1, 0 }, { 0, 1 }, { 1, 2 }, { 2, 1 } };

std::pair < std::size_t, std::size_t > Logic::get_turn() {
    for (int i = 0; i < GRID_SIZE; i++) {     // check o o o ...  .  ... o o o
        for (int exclude = 0; exclude < GRID_SIZE; exclude++) {
            if (grid(i, exclude) != '.') {
                continue;
            }

            char ch = (exclude == 0 ? grid(i, 1) : grid(i, 0));
            if (ch != 'o') {
                continue;
            }

            bool flag = true;
            for (int j = 0; j < GRID_SIZE && flag; j++) {
                if (j != exclude) {
                    flag &= (ch == grid(i, j));
                }
            }
            if (flag) {
                return { i, exclude };
            }
        }
    }
                                                                // check
    for (int j = 0; j < GRID_SIZE; j++) {                       //       o
        for (int exclude = 0; exclude < GRID_SIZE; exclude++) { //       o
            if (grid(exclude, j) != '.') {                      //       o
                continue;                                       //      ...
            }                                                   //       .
                                                                //      ...
            char ch = (exclude == 0 ? grid(1, j) : grid(0, j)); //       o
            if (ch != 'o') {                                    //       o
                continue;                                       //       o
            }

            bool flag = true;
            for (int i = 0; i < GRID_SIZE && flag; i++) {
                if (i != exclude) {
                    flag &= (ch == grid(i, j));
                }
            }
            if (flag) {
                return { exclude, j };
            }
        }
    }

    for (int exclude = 0; exclude < GRID_SIZE; exclude++) {
        if (grid(exclude, exclude) != '.') {
            continue;
        }

        char ch = (exclude == 0 ? grid(1, 1) : grid(0, 0));
        if (ch != 'o') {
            continue;
        }

        bool flag = true;
        for (int i = 0; i < GRID_SIZE; i++) {
            if (i != exclude) {
                flag &= (ch == grid(i, i));
            }
        }
        if (flag) {
            return { exclude, exclude };
        }
    }

    for (int exclude = 0; exclude < GRID_SIZE; exclude++) {
        if (grid(exclude, GRID_SIZE - exclude - 1) != '.') {
            continue;
        }

        char ch = (exclude == 0 ? grid(1, GRID_SIZE - 2) : grid(0, GRID_SIZE - 1));
        if (ch != 'o') {
            continue;
        }

        bool flag = true;
        for (int i = 0; i < GRID_SIZE; i++) {
            if (i != exclude) {
                flag &= (ch == grid(i, GRID_SIZE - i - 1));
            }
        }
        if (flag) {
            return { exclude, GRID_SIZE - exclude - 1 };
        }
    }

    /////////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < GRID_SIZE; i++) {     // check x x x ...  .  ... x x x
        for (int exclude = 0; exclude < GRID_SIZE; exclude++) {
            if (grid(i, exclude) != '.') {
                continue;
            }

            char ch = (exclude == 0 ? grid(i, 1) : grid(i, 0));
            if (ch != 'x') {
                continue;
            }

            bool flag = true;
            for (int j = 0; j < GRID_SIZE && flag; j++) {
                if (j != exclude) {
                    flag &= (ch == grid(i, j));
                }
            }
            if (flag) {
                return { i, exclude };
            }
        }
    }
                                                                // check
    for (int j = 0; j < GRID_SIZE; j++) {                       //       x
        for (int exclude = 0; exclude < GRID_SIZE; exclude++) { //       x
            if (grid(exclude, j) != '.') {                      //       x
                continue;                                       //      ...
            }                                                   //       .
                                                                //      ...
            char ch = (exclude == 0 ? grid(1, j) : grid(0, j)); //       x
            if (ch != 'x') {                                    //       x
                continue;                                       //       x
            }

            bool flag = true;
            for (int i = 0; i < GRID_SIZE && flag; i++) {
                if (i != exclude) {
                    flag &= (ch == grid(i, j));
                }
            }
            if (flag) {
                return { exclude, j };
            }
        }
    }

    for (int exclude = 0; exclude < GRID_SIZE; exclude++) {
        if (grid(exclude, exclude) != '.') {
            continue;
        }

        char ch = (exclude == 0 ? grid(1, 1) : grid(0, 0));
        if (ch != 'x') {
            continue;
        }

        bool flag = true;
        for (int i = 0; i < GRID_SIZE; i++) {
            if (i != exclude) {
                flag &= (ch == grid(i, i));
            }
        }
        if (flag) {
            return { exclude, exclude };
        }
    }

    for (int exclude = 0; exclude < GRID_SIZE; exclude++) {
        if (grid(exclude, GRID_SIZE - exclude - 1) != '.') {
            continue;
        }

        char ch = (exclude == 0 ? grid(1, GRID_SIZE - 2) : grid(0, GRID_SIZE - 1));
        if (ch != 'x') {
            continue;
        }

        bool flag = true;
        for (int i = 0; i < GRID_SIZE; i++) {
            if (i != exclude) {
                flag &= (ch == grid(i, GRID_SIZE - i - 1));
            }
        }
        if (flag) {
            return { exclude, GRID_SIZE - exclude - 1 };
        }
    }

    /////////////////////////////////////////////////////////////////////////////////

    if (grid(1, 1) != '.') {
        if (grid(1, 1) == 'x') {
            for (auto x : angles) {
                if (grid(x) == '.') {
                    return x;
                }
            }

            for (auto x : sides) {
                if (grid(x) == '.') {
                    return x;
                }
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                if ((grid(angles[(i + 3) % 4]) == 'x' || grid(angles[(i + 1) % 4]) == 'x') && grid(angles[i]) == '.') {
                    return angles[i];
                }
            }
            for (int i = 0; i < 4; i++) {
                if (grid(sides[i]) == 'x' && grid(sides[(i + 1) % 4]) == 'x') {
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
                    if (grid(i, j) == '.') {
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
