#include <QApplication>
#include <QWidget>
#include <QIcon>

#include "widget.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Widget window;
    window.setWindowTitle("Tic Tac Toe");
    window.setWindowIcon(QIcon("pic.jpg"));
    window.show();

    return app.exec();
}
