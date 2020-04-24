#include <QTimer>
#include <string>

#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
}

void Widget::submitButtonSlot() {
    if (timer != nullptr) {
        delete timer;
    }
    ui->timeSlider->setValue(0);
    ui->label->setNum(0);
    timer = new QTimer();
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateSlider()));
    timer->start();
}

void Widget::updateSlider() {
    ui->timeSlider->setValue( ui->timeSlider->value() + 1 );
    ui->label->setNum(ui->timeSlider->value());
    if (ui->timeSlider->value() == ui->timeSlider->maximum()) {
        delete timer;
        timer = nullptr;
    }
}

Widget::~Widget() {
    delete ui;
}

