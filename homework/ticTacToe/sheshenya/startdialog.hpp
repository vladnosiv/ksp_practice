#pragma once

#include <QDialog>
#include <QSpinBox>
#include <QLabel>

class StartDialog : public QDialog {
    Q_OBJECT
public:
    StartDialog(QWidget *parent = nullptr);
    ~StartDialog() {}

public slots:
    void start_game();
    void change_text(int value);
private:
    QSpinBox *input;
    QLabel *level;
public: int difficulty;

};

