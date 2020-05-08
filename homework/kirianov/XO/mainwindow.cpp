#include "mainwindow.h"
#include "ui_mainwindow.h"

int state[3][3];
bool win = false;
int level = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->exitbtn, &QPushButton::clicked, this, [=](){
        exit();
    });
    connect(ui->lvl, &QPushButton::clicked, this, [=](){
        changelvl();
    });
    connect(ui->clearbtn, &QPushButton::clicked, this, [=](){
        clear();
    });
    connect(ui->t00, &QPushButton::clicked, this, [=](){
        click(0, 0, ui->t00);
    });
    connect(ui->t01, &QPushButton::clicked, this, [=](){
        click(0, 1, ui->t01);
    });
    connect(ui->t10, &QPushButton::clicked, this, [=](){
        click(1, 0, ui->t10);
    });
    connect(ui->t11, &QPushButton::clicked, this, [=](){
        click(1, 1, ui->t11);
    });
    connect(ui->t02, &QPushButton::clicked, this, [=](){
        click(0, 2, ui->t02);
    });
    connect(ui->t20, &QPushButton::clicked, this, [=](){
        click(2, 0, ui->t20);
    });
    connect(ui->t22, &QPushButton::clicked, this, [=](){
        click(2, 2, ui->t22);
    });
    connect(ui->t21, &QPushButton::clicked, this, [=](){
        click(2, 1, ui->t21);
    });
    connect(ui->t12, &QPushButton::clicked, this, [=](){
        click(1, 2, ui->t12);
    });
    clear();
}

void MainWindow::exit(){
    QApplication::quit();
}
void MainWindow::changelvl(){
    if(win){
        //
    } else if(level==0){
        level = 1;
    } else if(level==1){
        level = 2;
    } else if(level==2){
        level = 0;
    }
    clear();
}
int aut = 0;
void MainWindow::clear(){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            state[i][j] = 0;
        }
    }
    win = false;
    if(level==0){
        ui->lvl->setText("Level 0");
    } else if(level==1){
        ui->lvl->setText("Level 1");
    } else if(level==2){
        ui->lvl->setText("Level 2");
    }
    aut = 0;
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

void MainWindow::click(int x, int y, QPushButton* btn){
    if(state[x][y]==0 && !win){
        state[x][y] = 2;
        btn->setIcon(QIcon(":/img/resources/2.png"));
        checkwin();
        doturn();
    }
}

void MainWindow::checkwin(){
    int zcnt = 0;
    for(int i = 0; i<3; i++){
        int cnt2 = 0, cnt1 = 0;
        for(int j = 0; j<3; j++){
            if(state[i][j]==1)
                cnt1++;
            else if(state[i][j]==2)
                cnt2++;
            else zcnt++;
        }
        if(cnt1==3){
            win = true;
            ui->lvl->setText(":(");
        } else if(cnt2==3){
            win = true;
            ui->lvl->setText(":)");
        }
    }
    for(int i = 0; i<3; i++){
        int cnt2 = 0, cnt1 = 0;
        for(int j = 0; j<3; j++){
            if(state[j][i]==1)
                cnt1++;
            else if(state[j][i]==2)
                cnt2++;
        }
        if(cnt1==3){
            win = true;
            ui->lvl->setText(":(");
        } else if(cnt2==3){
            win = true;
            ui->lvl->setText(":)");
        }
    }
    int cnt2 = 0, cnt1 = 0;
    for(int j = 0; j<3; j++){
        if(state[j][j]==1)
            cnt1++;
        else if(state[j][j]==2)
            cnt2++;
    }
    if(cnt1==3){
        win = true;
        ui->lvl->setText(":(");
    } else if(cnt2==3){
        win = true;
        ui->lvl->setText(":)");
    }
    cnt2 = 0;
    cnt1 = 0;
    for(int j = 0; j<3; j++){
        if(state[j][2-j]==1)
            cnt1++;
        else if(state[j][2-j]==2)
            cnt2++;
    }
    if(cnt1==3){
        win = true;
        ui->lvl->setText(":(");
    } else if(cnt2==3){
        win = true;
        ui->lvl->setText(":)");
    }
    if(!win && zcnt==0){
        win = true;
        ui->lvl->setText(":|");
    }
}

void MainWindow::doturn(){
    if(!win){
        if(aut==0){
            state[1][1] = 1;
            ui->t11->setIcon(QIcon(":/img/resources/1.png"));
            aut = 1;
        } else {
            if(level==0 || level==3){
                int fcnt = 0;
                for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(state[i][j] == 0)
                            fcnt++;
                    }
                }
                int k = rand()%fcnt+1;
                for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(state[i][j] == 0){
                            k--;
                            if(k==0){
                                state[i][j] = 1;
                                switchi(i, j, QIcon(":/img/resources/1.png"));
                            }
                        }
                    }
                }
            } else if(level==1){
                //instant_win
                for(int i = 0; i<3; i++){
                    int cnt2 = 0, cnt1 = 0;
                    for(int j = 0; j<3; j++){
                        if(state[i][j]==1)
                            cnt1++;
                        else if(state[i][j]==2)
                            cnt2++;
                    }
                    if(cnt2==0 && cnt1==2){
                        for(int j = 0; j<3; j++){
                            if(state[i][j]==0){
                                state[i][j] = 1;
                                switchi(i, j, QIcon(":/img/resources/1.png"));
                                checkwin();
                                return;
                            }
                        }
                    }
                }
                for(int i = 0; i<3; i++){
                    int cnt2 = 0, cnt1 = 0;
                    for(int j = 0; j<3; j++){
                        if(state[j][i]==1)
                            cnt1++;
                        else if(state[j][i]==2)
                            cnt2++;
                    }
                    if(cnt2==0 && cnt1==2){
                        for(int j = 0; j<3; j++){
                            if(state[j][i]==0){
                                state[j][i] = 1;
                                switchi(j, i, QIcon(":/img/resources/1.png"));
                                checkwin();
                                return;
                            }
                        }
                    }
                }
                int cnt2 = 0, cnt1 = 0;
                for(int j = 0; j<3; j++){
                    if(state[j][j]==1)
                        cnt1++;
                    else if(state[j][j]==2)
                        cnt2++;
                }
                if(cnt2==0 && cnt1==2){
                    for(int j = 0; j<3; j++){
                        if(state[j][j]==0){
                            state[j][j] = 1;
                            switchi(j, j, QIcon(":/img/resources/1.png"));
                            checkwin();
                            return;
                        }
                    }
                }
                cnt2 = 0;
                cnt1 = 0;
                for(int j = 0; j<3; j++){
                    if(state[j][2-j]==1)
                        cnt1++;
                    else if(state[j][2-j]==2)
                        cnt2++;
                }
                if(cnt2==0 && cnt1==2){
                    for(int j = 0; j<3; j++){
                        if(state[j][2-j]==0){
                            state[j][2-j] = 1;
                            switchi(j, 2-j, QIcon(":/img/resources/1.png"));
                            checkwin();
                            return;
                        }
                    }
                }
                //instant win for p2
                for(int i = 0; i<3; i++){
                    int cnt2 = 0, cnt1 = 0;
                    for(int j = 0; j<3; j++){
                        if(state[i][j]==1)
                            cnt1++;
                        else if(state[i][j]==2)
                            cnt2++;
                    }
                    if(cnt2==2 && cnt1==0){
                        for(int j = 0; j<3; j++){
                            if(state[i][j]==0){
                                state[i][j] = 1;
                                switchi(i, j, QIcon(":/img/resources/1.png"));
                                checkwin();
                                return;
                            }
                        }
                    }
                }
                for(int i = 0; i<3; i++){
                    int cnt2 = 0, cnt1 = 0;
                    for(int j = 0; j<3; j++){
                        if(state[j][i]==1)
                            cnt1++;
                        else if(state[j][i]==2)
                            cnt2++;
                    }
                    if(cnt2==2 && cnt1==0){
                        for(int j = 0; j<3; j++){
                            if(state[j][i]==0){
                                state[j][i] = 1;
                                switchi(j, i, QIcon(":/img/resources/1.png"));
                                checkwin();
                                return;
                            }
                        }
                    }
                }
                cnt2 = 0;
                cnt1 = 0;
                for(int j = 0; j<3; j++){
                    if(state[j][j]==1)
                        cnt1++;
                    else if(state[j][j]==2)
                        cnt2++;
                }
                if(cnt2==2 && cnt1==0){
                    for(int j = 0; j<3; j++){
                        if(state[j][j]==0){
                            state[j][j] = 1;
                            switchi(j, j, QIcon(":/img/resources/1.png"));
                            checkwin();
                            return;
                        }
                    }
                }
                cnt2 = 0;
                cnt1 = 0;
                for(int j = 0; j<3; j++){
                    if(state[j][2-j]==1)
                        cnt1++;
                    else if(state[j][2-j]==2)
                        cnt2++;
                }
                if(cnt2==2 && cnt1==0){
                    for(int j = 0; j<3; j++){
                        if(state[j][2-j]==0){
                            state[j][2-j] = 1;
                            switchi(j, 2-j, QIcon(":/img/resources/1.png"));
                            checkwin();
                            return;
                        }
                    }
                }
                //else
                level = 3;
                doturn();
            }
        }
        if(level==3)
            level = 1;
        checkwin();
    }

}
void MainWindow::switchi(int x, int y, QIcon img){
    if(x==0 && y==0)
    ui->t00->setIcon(img);
    if(x==0 && y==1)
    ui->t01->setIcon(img);
    if(x==1 && y==0)
    ui->t10->setIcon(img);
    if(x==1 && y==1)
    ui->t11->setIcon(img);
    if(x==0 && y==2)
    ui->t02->setIcon(img);
    if(x==2 && y==0)
    ui->t20->setIcon(img);
    if(x==1 && y==2)
    ui->t12->setIcon(img);
    if(x==2 && y==1)
    ui->t21->setIcon(img);
    if(x==2 && y==2)
    ui->t22->setIcon(img);
}
MainWindow::~MainWindow()
{
    delete ui;
}
