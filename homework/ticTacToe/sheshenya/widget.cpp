#include "widget.h"
#include "./ui_widget.h"
#include "logic.hpp"
#include <chrono>
#include <random>

#include "startdialog.hpp"

#include <iostream>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget), solver(Grid('.')) {
    ui->setupUi(this);
    ui->result->hide();
    connect(ui->button11, SIGNAL(clicked(bool)), this, SLOT(set_X_11()));
    connect(ui->button12, SIGNAL(clicked(bool)), this, SLOT(set_X_12()));
    connect(ui->button13, SIGNAL(clicked(bool)), this, SLOT(set_X_13()));
    connect(ui->button21, SIGNAL(clicked(bool)), this, SLOT(set_X_21()));
    connect(ui->button22, SIGNAL(clicked(bool)), this, SLOT(set_X_22()));
    connect(ui->button23, SIGNAL(clicked(bool)), this, SLOT(set_X_23()));
    connect(ui->button31, SIGNAL(clicked(bool)), this, SLOT(set_X_31()));
    connect(ui->button32, SIGNAL(clicked(bool)), this, SLOT(set_X_32()));
    connect(ui->button33, SIGNAL(clicked(bool)), this, SLOT(set_X_33()));

    StartDialog *start = new StartDialog(this);
    start->exec();
    difficulty = start->difficulty;
    if (!difficulty) {
        this->close();
    }
}

Widget::~Widget() {
    delete ui;
}

void Widget::restart() {
    disconnect(ui->result, SIGNAL(clicked(bool)), this, SLOT(restart()));
    ui->result->hide();
    ui->result->setText("");
    ui->button11->setText("");
    ui->button12->setText("");
    ui->button13->setText("");
    ui->button21->setText("");
    ui->button22->setText("");
    ui->button23->setText("");
    ui->button31->setText("");
    ui->button32->setText("");
    ui->button33->setText("");
    solver = Logic(Grid('.'));
    connect(ui->button11, SIGNAL(clicked(bool)), this, SLOT(set_X_11()));
    connect(ui->button12, SIGNAL(clicked(bool)), this, SLOT(set_X_12()));
    connect(ui->button13, SIGNAL(clicked(bool)), this, SLOT(set_X_13()));
    connect(ui->button21, SIGNAL(clicked(bool)), this, SLOT(set_X_21()));
    connect(ui->button22, SIGNAL(clicked(bool)), this, SLOT(set_X_22()));
    connect(ui->button23, SIGNAL(clicked(bool)), this, SLOT(set_X_23()));
    connect(ui->button31, SIGNAL(clicked(bool)), this, SLOT(set_X_31()));
    connect(ui->button32, SIGNAL(clicked(bool)), this, SLOT(set_X_32()));
    connect(ui->button33, SIGNAL(clicked(bool)), this, SLOT(set_X_33()));

    StartDialog *start = new StartDialog(this);
    start->exec();
    difficulty = start->difficulty;
    if (!difficulty) {
        this->close();
    }
}

int rng_on(int l, int r) {
    return rng() % (r - l + 1) + l;
}

void Widget::do_turn() {
    if (solver.grid.get_winner() == '.') {
        auto turns = solver.get_turns();
        std::pair <std::size_t, std::size_t> turn;

        if (difficulty == 1) {
            turn = turns[rng_on(0, turns.size() - 1)];
        }
        if (difficulty == 2) {
            turn = turns[rng_on(0, turns.size() / 2)];
        }
        if (difficulty == 3) {
            turn = turns.front();
        }

        solver.grid(turn) = 'o';
        auto [x, y] = turn;
        if (x != 4 && y != 4) {
            x++, y++;

            if (x == 1 && y == 1) {
                set_O_11();
            }
            else if (x == 1 && y == 2) {
                set_O_12();
            }
            else if (x == 1 && y == 3) {
                set_O_13();
            }
            else if (x == 2 && y == 1) {
                set_O_21();
            }
            else if (x == 2 && y == 2) {
                set_O_22();
            }
            else if (x == 2 && y == 3) {
                set_O_23();
            }
            else if (x == 3 && y == 1) {
                set_O_31();
            }
            else if (x == 3 && y == 2) {
                set_O_32();
            }
            else if (x == 3 && y == 3) {
                set_O_33();
            }
        }
    }

    char winner = solver.grid.get_winner();
    if (winner != '.') {
        connect(ui->result, SIGNAL(clicked(bool)), this, SLOT(restart()));
        if (winner == 'x') {
            ui->result->setText("No way! You won me! Press here to play again");
        }
        if (winner == 'd') {
            ui->result->setText("Draw! Press here to play again");
        }
        if (winner == 'o') {
            ui->result->setText("You lost! Press here to play again");
        }
        ui->result->show();
        disconnect(ui->button11, SIGNAL(clicked(bool)), this, SLOT(set_X_11()));
        disconnect(ui->button12, SIGNAL(clicked(bool)), this, SLOT(set_X_12()));
        disconnect(ui->button13, SIGNAL(clicked(bool)), this, SLOT(set_X_13()));
        disconnect(ui->button21, SIGNAL(clicked(bool)), this, SLOT(set_X_21()));
        disconnect(ui->button22, SIGNAL(clicked(bool)), this, SLOT(set_X_22()));
        disconnect(ui->button23, SIGNAL(clicked(bool)), this, SLOT(set_X_23()));
        disconnect(ui->button31, SIGNAL(clicked(bool)), this, SLOT(set_X_31()));
        disconnect(ui->button32, SIGNAL(clicked(bool)), this, SLOT(set_X_32()));
        disconnect(ui->button33, SIGNAL(clicked(bool)), this, SLOT(set_X_33()));
    }
}

void Widget::set_X_11() {
    ui->button11->setText(QString("X"));
    solver.grid(0, 0) = 'x';
    disconnect(ui->button11, SIGNAL(clicked(bool)), this, SLOT(set_X_11()));
    do_turn();
}
void Widget::set_O_11() {
    ui->button11->setText(QString("O"));
    disconnect(ui->button11, SIGNAL(clicked(bool)), this, SLOT(set_X_11()));
}

void Widget::set_X_12() {
    ui->button12->setText(QString("X"));
    solver.grid(0, 1) = 'x';
    disconnect(ui->button12, SIGNAL(clicked(bool)), this, SLOT(set_X_12()));
    do_turn();
}
void Widget::set_O_12() {
    ui->button12->setText(QString("O"));
    disconnect(ui->button12, SIGNAL(clicked(bool)), this, SLOT(set_X_12()));
}

void Widget::set_X_13() {
    ui->button13->setText(QString("X"));
    solver.grid(0, 2) = 'x';
    disconnect(ui->button13, SIGNAL(clicked(bool)), this, SLOT(set_X_13()));
    do_turn();
}
void Widget::set_O_13() {
    ui->button13->setText(QString("O"));
    disconnect(ui->button13, SIGNAL(clicked(bool)), this, SLOT(set_X_13()));
}


void Widget::set_X_21() {
    ui->button21->setText(QString("X"));
    solver.grid(1, 0) = 'x';
    disconnect(ui->button21, SIGNAL(clicked(bool)), this, SLOT(set_X_21()));
    do_turn();
}
void Widget::set_O_21() {
    ui->button21->setText(QString("O"));
    disconnect(ui->button21, SIGNAL(clicked(bool)), this, SLOT(set_X_21()));
}

void Widget::set_X_22() {
    ui->button22->setText(QString("X"));
    solver.grid(1, 1) = 'x';
    disconnect(ui->button22, SIGNAL(clicked(bool)), this, SLOT(set_X_22()));
    do_turn();/////////////////////////////////////////////////////
}
void Widget::set_O_22() {
    ui->button22->setText(QString("O"));
    disconnect(ui->button22, SIGNAL(clicked(bool)), this, SLOT(set_X_22()));
}

void Widget::set_X_23() {
    ui->button23->setText(QString("X"));
    solver.grid(1, 2) = 'x';
    disconnect(ui->button23, SIGNAL(clicked(bool)), this, SLOT(set_X_23()));
    do_turn();
}
void Widget::set_O_23() {
    ui->button23->setText(QString("O"));
    disconnect(ui->button23, SIGNAL(clicked(bool)), this, SLOT(set_X_23()));
}

void Widget::set_X_31() {
    ui->button31->setText(QString("X"));
    solver.grid(2, 0) = 'x';
    disconnect(ui->button31, SIGNAL(clicked(bool)), this, SLOT(set_X_31()));
    do_turn();
}
void Widget::set_O_31() {
    ui->button31->setText(QString("O"));
    disconnect(ui->button31, SIGNAL(clicked(bool)), this, SLOT(set_X_31()));
}

void Widget::set_X_32() {
    ui->button32->setText(QString("X"));
    solver.grid(2, 1) = 'x';
    disconnect(ui->button32, SIGNAL(clicked(bool)), this, SLOT(set_X_32()));
    do_turn();
}
void Widget::set_O_32() {
    ui->button32->setText(QString("O"));
    disconnect(ui->button32, SIGNAL(clicked(bool)), this, SLOT(set_X_32()));
}

void Widget::set_X_33() {
    ui->button33->setText(QString("X"));
    solver.grid(2, 2) = 'x';
    disconnect(ui->button33, SIGNAL(clicked(bool)), this, SLOT(set_X_33()));
    do_turn();
}
void Widget::set_O_33() {
    ui->button33->setText(QString("O"));
    disconnect(ui->button33, SIGNAL(clicked(bool)), this, SLOT(set_X_33()));
}
