
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QVideoWidget>
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QtWebView/QtWebView>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include "myrobot.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

private slots:
    void on_connect_clicked();

    void on_disconnect_clicked();

    void on_forward_clicked();

    void on_forward_speed_valueChanged(int arg1);

    void on_forward_pressed();

    void on_right_pressed();

    void on_backward_pressed();

    void on_left_pressed();

    void on_forwardL_pressed();

    void on_forwardR_pressed();

    void on_backwardL_pressed();

    void on_pushButton_4_pressed();

    void on_backwardR_pressed();

    void on_forwardR_released();

    void on_right_released();

    void on_backwardR_released();

    void on_backward_released();

    void on_backwardL_released();

    void on_left_released();

    void on_forwardL_released();

    void on_forward_released();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MyRobot wifibot;
    int arg1 = 0;
};

#endif // MAINWINDOW_H
