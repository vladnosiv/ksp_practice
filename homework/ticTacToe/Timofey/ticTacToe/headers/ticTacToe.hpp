#pragma once

class TicTacToe {
public:
    TicTacToe(int scale, int lenWin);
    ~TicTacToe();

    int set(int r, int c, int t);
private:
    int scale_, lenWin_;
    int **grid_;
    int **tmp_;

    int check_();
    int checkVertical_();
    int checkHorizontal_();
    int checkDiagUDLR_();
    int checkDiagDULR_();
};
