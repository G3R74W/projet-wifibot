/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *left;
    QPushButton *right;
    QPushButton *forward;
    QPushButton *backward;
    QPushButton *disconnect;
    QPushButton *connect;
    QPushButton *forwardL;
    QPushButton *forwardR;
    QPushButton *backwardL;
    QPushButton *backwardR;
    QWebEngineView *cameraFrame;
    QPushButton *pushButton;
    QPushButton *cameraLeft;
    QPushButton *cameraRight;
    QPushButton *cameraUp;
    QPushButton *cameraDown;
    QProgressBar *batteryLevel;
    QSlider *speedSlider;
    QLabel *leftSpeed;
    QLabel *rightSpeed;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        left = new QPushButton(centralwidget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(250, 460, 93, 29));
        right = new QPushButton(centralwidget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(450, 460, 93, 29));
        forward = new QPushButton(centralwidget);
        forward->setObjectName(QString::fromUtf8("forward"));
        forward->setGeometry(QRect(350, 430, 93, 29));
        backward = new QPushButton(centralwidget);
        backward->setObjectName(QString::fromUtf8("backward"));
        backward->setGeometry(QRect(350, 490, 93, 29));
        disconnect = new QPushButton(centralwidget);
        disconnect->setObjectName(QString::fromUtf8("disconnect"));
        disconnect->setGeometry(QRect(700, 50, 93, 29));
        connect = new QPushButton(centralwidget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(700, 10, 93, 29));
        forwardL = new QPushButton(centralwidget);
        forwardL->setObjectName(QString::fromUtf8("forwardL"));
        forwardL->setGeometry(QRect(260, 440, 80, 18));
        forwardR = new QPushButton(centralwidget);
        forwardR->setObjectName(QString::fromUtf8("forwardR"));
        forwardR->setGeometry(QRect(460, 440, 80, 18));
        backwardL = new QPushButton(centralwidget);
        backwardL->setObjectName(QString::fromUtf8("backwardL"));
        backwardL->setGeometry(QRect(260, 500, 80, 18));
        backwardR = new QPushButton(centralwidget);
        backwardR->setObjectName(QString::fromUtf8("backwardR"));
        backwardR->setGeometry(QRect(460, 500, 80, 18));
        cameraFrame = new QWebEngineView(centralwidget);
        cameraFrame->setObjectName(QString::fromUtf8("cameraFrame"));
        cameraFrame->setGeometry(QRect(180, 90, 471, 321));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 80, 18));
        cameraLeft = new QPushButton(centralwidget);
        cameraLeft->setObjectName(QString::fromUtf8("cameraLeft"));
        cameraLeft->setGeometry(QRect(10, 420, 93, 29));
        cameraRight = new QPushButton(centralwidget);
        cameraRight->setObjectName(QString::fromUtf8("cameraRight"));
        cameraRight->setGeometry(QRect(120, 420, 93, 29));
        cameraUp = new QPushButton(centralwidget);
        cameraUp->setObjectName(QString::fromUtf8("cameraUp"));
        cameraUp->setGeometry(QRect(60, 380, 93, 29));
        cameraDown = new QPushButton(centralwidget);
        cameraDown->setObjectName(QString::fromUtf8("cameraDown"));
        cameraDown->setGeometry(QRect(60, 460, 93, 29));
        batteryLevel = new QProgressBar(centralwidget);
        batteryLevel->setObjectName(QString::fromUtf8("batteryLevel"));
        batteryLevel->setGeometry(QRect(140, 10, 118, 23));
        batteryLevel->setMaximum(200);
        batteryLevel->setValue(24);
        speedSlider = new QSlider(centralwidget);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setGeometry(QRect(710, 210, 16, 160));
        speedSlider->setMaximum(240);
        speedSlider->setValue(150);
        speedSlider->setOrientation(Qt::Vertical);
        leftSpeed = new QLabel(centralwidget);
        leftSpeed->setObjectName(QString::fromUtf8("leftSpeed"));
        leftSpeed->setGeometry(QRect(690, 400, 37, 12));
        rightSpeed = new QLabel(centralwidget);
        rightSpeed->setObjectName(QString::fromUtf8("rightSpeed"));
        rightSpeed->setGeometry(QRect(690, 430, 37, 12));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        left->setText(QCoreApplication::translate("MainWindow", "left", nullptr));
        right->setText(QCoreApplication::translate("MainWindow", "right", nullptr));
        forward->setText(QCoreApplication::translate("MainWindow", "forward", nullptr));
        backward->setText(QCoreApplication::translate("MainWindow", "backward", nullptr));
        disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        forwardL->setText(QCoreApplication::translate("MainWindow", "Forward-Left", nullptr));
        forwardR->setText(QCoreApplication::translate("MainWindow", "Forward-Right", nullptr));
        backwardL->setText(QCoreApplication::translate("MainWindow", "Backward-Left", nullptr));
        backwardR->setText(QCoreApplication::translate("MainWindow", "Backward-Right", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        cameraLeft->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        cameraRight->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        cameraUp->setText(QCoreApplication::translate("MainWindow", "/\\", nullptr));
        cameraDown->setText(QCoreApplication::translate("MainWindow", "\\/", nullptr));
        leftSpeed->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rightSpeed->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
