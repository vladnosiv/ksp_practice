#include <QSpinBox>
#include <QLabel>
#include <QPushButton>

#include "startdialog.hpp"

StartDialog::StartDialog(QWidget *parent) : QDialog(parent) {
    this->setModal(true);
    this->setGeometry(500, 500, 300, 100);

    input = new QSpinBox(this);
    input->setRange(1, 3);
    input->setValue(2);
    input->setGeometry(20, 10, 50, 50);
    input->show();

    QLabel *message = new QLabel(this);
    message->setGeometry(90, 70, 150, 30);
    message->setText("Enter difficulty level");

    level = new QLabel(this);
    level->setGeometry(90, 25, 75, 15);
    level->setText("Medium");

    QPushButton *start = new QPushButton(this);
    start->setGeometry(200, 20, 60, 30);
    start->setText("Play!");

    difficulty = 1;
    connect(start, SIGNAL(clicked(bool)), this, SLOT(start_game()));
    connect(input, SIGNAL(valueChanged(int)), this, SLOT(change_text(int)));
}

void StartDialog::start_game() {
    difficulty = input->value();
    this->close();
}

void StartDialog::change_text(int value) {
    if (value == 1) {
        level->setText("Easy");
    }
    if (value == 2) {
        level->setText("Medium");
    }
    if (value == 3) {
        level->setText("Impossible");
    }
}
