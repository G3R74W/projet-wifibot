
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myrobot.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    MyRobot *wifibot = new MyRobot();
    QWebEngineView *test = new QWebEngineView();
    QUrl URL = QUrl("http://192.168.1.106:8080/?action=stream");
    test->load(URL);
    test->show();

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
    wifibot.move(Direction::FORWARD);
}

void MainWindow::on_right_pressed()
{
    wifibot.move(Direction::RIGHT);
}


void MainWindow::on_backward_pressed()
{
    wifibot.move(Direction::BACKWARD);
}


void MainWindow::on_left_pressed()
{
    wifibot.move(Direction::LEFT);
}



void MainWindow::on_forwardL_pressed()
{
    wifibot.move(Direction::FORWARD_LEFT);
}


void MainWindow::on_forwardR_pressed()
{
    wifibot.move(Direction::FORWARD_RIGHT);
}

void MainWindow::on_forwardR_released()
{
    wifibot.move(Direction::NONE);
}


void MainWindow::on_backwardL_pressed()
{
    wifibot.move(Direction::BACKWARD_LEFT);
}


void MainWindow::on_backwardR_pressed()
{
    wifibot.move(Direction::BACKWARD_RIGHT);
}


void MainWindow::on_forward_clicked(){

}

void MainWindow::on_forward_speed_valueChanged(int arg1){

}

void MainWindow::on_pushButton_4_pressed(){

}

void MainWindow::on_right_released()
{
    wifibot.move(Direction::NONE);
}


void MainWindow::on_backwardR_released()
{
    wifibot.move(Direction::NONE);
}


void MainWindow::on_backward_released()
{
    wifibot.move(Direction::NONE);
}


void MainWindow::on_backwardL_released()
{
    wifibot.move(Direction::NONE);
}


void MainWindow::on_left_released()
{
    wifibot.move(Direction::NONE);
}


void MainWindow::on_forwardL_released()
{
    wifibot.move(Direction::NONE);
}


void MainWindow::on_forward_released()
{
    wifibot.move(Direction::NONE);
}

