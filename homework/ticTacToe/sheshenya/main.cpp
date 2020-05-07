#include <QApplication>
#include <QWidget>

#include "widget.h"
#include "startdialog.hpp"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Widget window;
    window.setWindowTitle("Tic Tac Toe");

    window.show();

    return app.exec();
}
