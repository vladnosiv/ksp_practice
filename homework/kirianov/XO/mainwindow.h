#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void exit();
    void click(int x, int y, QPushButton* btn);
    void clear();
    void doturn();
    void checkwin();
    void changelvl();
    void switchi(int x, int y, QIcon img);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
