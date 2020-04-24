#pragma once

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void submitButtonSlot();

private slots:
    void updateSlider();

private:
    QTimer *timer = nullptr;
    Ui::Widget *ui;
};
