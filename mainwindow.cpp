
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

void MainWindow::on_forward_speed_valueChanged(int arg1){

}

void MainWindow::on_forward_clicked()
{

}





