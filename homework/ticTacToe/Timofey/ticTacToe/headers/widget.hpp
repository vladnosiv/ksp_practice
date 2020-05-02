#pragma once

#include <QWidget>
#include <QPushButton>
#include <random>

#include "ticTacToe.hpp"

namespace Ui { class Widget; }

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void test(QPushButton *curBtn, int x = 10);

private:
    int scale = 3;
    int num = 0;
    TicTacToe *game_;

    Ui::Widget *ui;
    QPushButton **btn;
    int **grid;

    void startGame();
    void endGame(int winner);
    std::pair<int, int> getPos(int i);
};
