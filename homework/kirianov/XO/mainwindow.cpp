#include "mainwindow.h"
#include "ui_mainwindow.h"

int state[3][3];
bool win = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->exitbtn, SIGNAL (released()), this, SLOT (exit()));
    connect(ui->clearbtn, SIGNAL (released()), this, SLOT (exit()));
    connect(ui->t00, SIGNAL (released()), this, SLOT (click(0, 0)));
    connect(ui->t01, SIGNAL (released()), this, SLOT (click(0, 1)));
    connect(ui->t10, SIGNAL (released()), this, SLOT (click(1, 0)));
    connect(ui->t11, SIGNAL (released()), this, SLOT (click(1, 1)));
    connect(ui->t00, SIGNAL (released()), this, SLOT (click(2, 0)));
    connect(ui->t01, SIGNAL (released()), this, SLOT (click(0, 2)));
    connect(ui->t10, SIGNAL (released()), this, SLOT (click(2, 2)));
    connect(ui->t11, SIGNAL (released()), this, SLOT (click(2, 1)));
    connect(ui->t11, SIGNAL (released()), this, SLOT (click(1, 2)));
    clear();
}

void MainWindow::exit(){
    QApplication::quit();
}

void MainWindow::clear(){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            state[i][j] = 0;
        }
    }
    ui->t00->setIcon(QIcon(":/img/resources/0.png"));
    ui->t01->setIcon(QIcon(":/img/resources/0.png"));
    ui->t10->setIcon(QIcon(":/img/resources/0.png"));
    ui->t11->setIcon(QIcon(":/img/resources/0.png"));
    ui->t02->setIcon(QIcon(":/img/resources/0.png"));
    ui->t20->setIcon(QIcon(":/img/resources/0.png"));
    ui->t12->setIcon(QIcon(":/img/resources/0.png"));
    ui->t21->setIcon(QIcon(":/img/resources/0.png"));
    ui->t22->setIcon(QIcon(":/img/resources/0.png"));
    doturn();
}

void MainWindow::click(int x, int y){
    if(state[x][y]==0 && !win){
        state[x][y] = 2;
        if(x==0 && y==0)
            ui->t00->setIcon(QIcon(":/img/resources/2.png"));
        if(x==1 && y==0)
            ui->t10->setIcon(QIcon(":/img/resources/2.png"));
        if(x==0 && y==1)
            ui->t01->setIcon(QIcon(":/img/resources/2.png"));
        if(x==1 && y==1)
            ui->t11->setIcon(QIcon(":/img/resources/2.png"));
        if(x==1 && y==2)
            ui->t12->setIcon(QIcon(":/img/resources/2.png"));
        if(x==2 && y==1)
            ui->t21->setIcon(QIcon(":/img/resources/2.png"));
        if(x==2 && y==2)
            ui->t22->setIcon(QIcon(":/img/resources/2.png"));
        if(x==2 && y==0)
            ui->t20->setIcon(QIcon(":/img/resources/2.png"));
        if(x==0 && y==2)
            ui->t02->setIcon(QIcon(":/img/resources/2.png"));
    }
}

void MainWindow::doturn(){

}

MainWindow::~MainWindow()
{
    delete ui;
}
