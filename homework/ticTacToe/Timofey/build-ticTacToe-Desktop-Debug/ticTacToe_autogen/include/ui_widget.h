/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QSlider *scaleSlider;
    QLabel *label;
    QLabel *label_2;
    QSlider *winLength;
    QPushButton *start;
    QLabel *curScale;
    QLabel *curLength;
    QLabel *msgWin;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(719, 681);
        scaleSlider = new QSlider(Widget);
        scaleSlider->setObjectName(QString::fromUtf8("scaleSlider"));
        scaleSlider->setGeometry(QRect(60, 20, 171, 21));
        scaleSlider->setMinimum(3);
        scaleSlider->setMaximum(10);
        scaleSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 67, 19));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 20, 81, 19));
        winLength = new QSlider(Widget);
        winLength->setObjectName(QString::fromUtf8("winLength"));
        winLength->setGeometry(QRect(380, 20, 171, 21));
        winLength->setMinimum(3);
        winLength->setMaximum(3);
        winLength->setOrientation(Qt::Horizontal);
        start = new QPushButton(Widget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(610, 16, 88, 31));
        curScale = new QLabel(Widget);
        curScale->setObjectName(QString::fromUtf8("curScale"));
        curScale->setGeometry(QRect(240, 20, 67, 19));
        curLength = new QLabel(Widget);
        curLength->setObjectName(QString::fromUtf8("curLength"));
        curLength->setGeometry(QRect(560, 20, 67, 19));
        msgWin = new QLabel(Widget);
        msgWin->setObjectName(QString::fromUtf8("msgWin"));
        msgWin->setEnabled(true);
        msgWin->setGeometry(QRect(0, 50, 721, 81));
        QFont font;
        font.setPointSize(30);
        msgWin->setFont(font);
        msgWin->setAlignment(Qt::AlignCenter);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Scale", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Win length", nullptr));
        start->setText(QCoreApplication::translate("Widget", "Start", nullptr));
        curScale->setText(QCoreApplication::translate("Widget", "3", nullptr));
        curLength->setText(QCoreApplication::translate("Widget", "3", nullptr));
        msgWin->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
