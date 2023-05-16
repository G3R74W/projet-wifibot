
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myrobot.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_connect_clicked()
{
    wifibot.doConnect();
}


void MainWindow::on_disconnect_clicked()
{
    wifibot.disConnect();
}

void MainWindow::on_forward_pressed(){

}

void MainWindow::on_forward_speed_valueChanged(int arg1){

}

void MainWindow::on_forward_clicked()
{
    wifibot.DataToSend[2]= 120;
    wifibot.MyTimerSlot();
}

