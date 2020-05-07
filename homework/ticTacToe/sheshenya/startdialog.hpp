#pragma once

#include <QDialog>
#include <QSpinBox>
#include <QLabel>

class StartDialog : public QDialog {
    Q_OBJECT
public:
    StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

public: int difficulty;

};

