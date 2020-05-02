#import "ticTacToe.hpp"

TicTacToe::TicTacToe(int scale, int lenWin) : scale_(scale), lenWin_(lenWin) {
    grid_ = new int*[static_cast<unsigned long>(scale_)];
    grid_[0] = new int[static_cast<unsigned long>(scale_) * static_cast<unsigned long>(scale_)];
    for (int i = 1; i < scale_; ++i)
        grid_[i] = grid_[0] + scale_ * i;
    for (int i = 0; i < scale_ * scale_; ++i)
        grid_[0][i] = 0;

    tmp_ = new int*[static_cast<unsigned long>(scale_)];
    tmp_[0] = new int[static_cast<unsigned long>(scale_) * static_cast<unsigned long>(scale_)];
    for (int i = 1; i < scale_; ++i)
        tmp_[i] = tmp_[0] + scale_ * i;
}

TicTacToe::~TicTacToe() {
    delete[] grid_[0];
    delete[] grid_;

    delete[] tmp_[0];
    delete[] tmp_;
}

int TicTacToe::set(int r, int c, int t) {
    grid_[r][c] = t;
    return check_();
}

int TicTacToe::check_() {
    return checkVertical_() || checkHorizontal_() || checkDiagDULR_() || checkDiagUDLR_();
}

int TicTacToe::checkVertical_() {
    int res = 0;
    for (int i = 0; i < scale_ && res == 0; ++i) {
        for (int j = 0; j < scale_ && res == 0; ++j) {
            if (grid_[i][j] != 0) {
                if(i == 0)
                    tmp_[i][j] = 1;
                else if (grid_[i][j] == grid_[i - 1][j])
                    tmp_[i][j] = tmp_[i - 1][j] + 1;
                else
                    tmp_[i][j] = 1;
            } else {
                tmp_[i][j] = 0;
            }

            if (tmp_[i][j] >= lenWin_)
                res = grid_[i][j];
        }
    }
    return res;
}

int TicTacToe::checkHorizontal_() {
    int res = 0;

    for (int j = 0; j < scale_ && res == 0; ++j) {
        for (int i = 0; i < scale_ && res == 0; ++i) {
            if (grid_[i][j] != 0) {
                if (j == 0)
                    tmp_[i][j] = 1;
                else if (grid_[i][j] == grid_[i][j - 1])
                    tmp_[i][j] = tmp_[i][j - 1] + 1;
                else
                    tmp_[i][j] = 1;
            } else {
                tmp_[i][j] = 0;
            }

            if (tmp_[i][j] >= lenWin_)
                res = grid_[i][j];
        }
    }

    return res;
}

int TicTacToe::checkDiagUDLR_() {
    int res = 0;

    for (int i = 0; i < scale_; ++i) {
        for (int j = 0; j < scale_; ++j) {
            if (grid_[i][j] != 0) {
                if (i == 0 || j == 0)
                    tmp_[i][j] = 1;
                else if (grid_[i][j] == grid_[i - 1][j - 1])
                    tmp_[i][j] = tmp_[i - 1][j - 1] + 1;
                else
                    tmp_[i][j] = 1;
            } else {
                tmp_[i][j] = 0;
            }

            if (tmp_[i][j] >= lenWin_)
                res = grid_[i][j];
        }
    }

    return res;
}

int TicTacToe::checkDiagDULR_() {
    int res = 0;

    for (int i = 0; i < scale_; ++i) {
        for (int j = 0; j < scale_; ++j) {
            if (grid_[i][j] != 0) {
				if (i == 0 || j == scale_ - 1)
					tmp_[i][j] = 1;
				else if (grid_[i][j] == grid_[i - 1][j + 1])
					tmp_[i][j] = tmp_[i - 1][j + 1] + 1;
				else
					tmp_[i][j] = 1;
            } else {
				tmp_[i][j] = 0;
            }

			if (tmp_[i][j] >= lenWin_)
				res = grid_[i][j];
        }
    }

    return res;
}
