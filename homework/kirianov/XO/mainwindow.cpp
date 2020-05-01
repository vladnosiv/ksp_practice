#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->exitbtn, SIGNAL (released()), this, SLOT (exit()));
}
void MainWindow::exit(){
    QApplication::quit();
}
MainWindow::~MainWindow()
{
    delete ui;
}
