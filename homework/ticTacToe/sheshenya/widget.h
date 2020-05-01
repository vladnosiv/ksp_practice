#pragma once

#include <QWidget>
#include <QPushButton>
#include <QString>

#include <logic.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public: Widget(QWidget *parent = nullptr);
private: Ui::Widget *ui;

public: void do_turn();

public slots:
    void set_X_11();
    void set_O_11();

    void set_X_12();
    void set_O_12();

    void set_X_13();
    void set_O_13();

    void set_X_21();
    void set_O_21();

    void set_X_22();
    void set_O_22();

    void set_X_23();
    void set_O_23();

    void set_X_31();
    void set_O_31();

    void set_X_32();
    void set_O_32();

    void set_X_33();
    void set_O_33();

    void restart();

public:
    Logic solver;

public: ~Widget();
};

