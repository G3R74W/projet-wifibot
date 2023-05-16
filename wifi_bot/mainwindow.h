
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private slots:
    void on_connect_clicked();

    void on_disconnect_clicked();

    void on_forward_clicked();

    void on_forward_speed_valueChanged(int arg1);

    void on_forward_pressed();

private:
    Ui::MainWindow *ui;
    MyRobot wifibot;
    int arg1 = 0;
};

#endif // MAINWINDOW_H
