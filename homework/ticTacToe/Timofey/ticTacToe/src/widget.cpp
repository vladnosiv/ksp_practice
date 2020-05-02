#include "widget.hpp"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {

    ui->setupUi(this);

    connect(ui->scaleSlider, &QSlider::valueChanged, this, [=]() {
        ui->winLength->setMaximum(ui->scaleSlider->value());
        ui->curScale->setText(QString::number(ui->scaleSlider->value()));
    });
    connect(ui->winLength, &QSlider::valueChanged, this, [=]() {
        ui->curLength->setText(QString::number(ui->winLength->value()));
    });
    connect(ui->start, &QPushButton::clicked, this, &Widget::startGame);
    ui->msgWin->hide();
}

Widget::~Widget() {
    delete ui;
}

void Widget::startGame() {
    scale = ui->scaleSlider->value();

    btn = new QPushButton*[static_cast<unsigned long>(scale) * static_cast<unsigned long>(scale)];
    for (int i = 0; i < scale * scale; ++i) {
        btn[i] = new QPushButton("–", this);
        btn[i]->resize(50, 50);
        btn[i]->move(20 + getPos(i).second * 60, 80 + getPos(i).first * 60);
        btn[i]->setStyleSheet("font: 30px");
        connect(btn[i], &QPushButton::clicked, this, [=]() {
            test(btn[i], i);
        });
        btn[i]->show();
    }

    ui->start->setEnabled(false);
    game_ = new TicTacToe(ui->scaleSlider->value(), ui->winLength->value());
    num = 0;
    ui->msgWin->hide();
}

void Widget::test(QPushButton *curBtn, int x) {
    if (num % 2 == 0) {
        curBtn->setText("×");
        if (game_->set(getPos(x).first, getPos(x).second, num % 2 + 1)) {
            curBtn->setText("W");
            endGame(num % 2);
        }
    } else {
        curBtn->setText("○");
        if (game_->set(getPos(x).first, getPos(x).second, num % 2 + 1)) {
            curBtn->setText("W");
            endGame(num % 2);
        }
    }
    num++;
    curBtn->setEnabled(false);
}

void Widget::endGame(int winner) {
    for (int i = 0; i < 9; ++i) {
        btn[i]->setEnabled(false);
        btn[i]->close();
    }
    delete[] btn;
    btn = nullptr;

    ui->start->setEnabled(true);
    ui->msgWin->show();
    if (winner == 0)
        ui->msgWin->setText("Winning ×");
    else
        ui->msgWin->setText("Winning ○");
}

std::pair<int, int> Widget::getPos(int i) {
    return {i / scale, i % scale};
}



