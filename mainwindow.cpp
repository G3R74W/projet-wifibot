
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myrobot.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QWebEngineView *test = new QWebEngineView();
    QUrl URL = QUrl("http://192.168.1.106:8080/?action=stream");
    test->load(URL);
    test->show();
//    QWidget *window = new QWidget(this);
//    QVBoxLayout *layout = new QVBoxLayout(window);

//    QMediaPlayer *player = new QMediaPlayer;
//    QVideoWidget *videoWidget = new QVideoWidget;
//    player->setVideoOutput(videoWidget);

//    layout->addWidget(videoWidget);
//    window->resize(100,100);

//   player->setMedia(QUrl("http://192.168.1.106:8080/?action=stream"));
//   player->play();

//    setCentralWidget(window);
//    window->show();
//    Phonon::VideoPlayer *player = new Phonon::VideoPlayer(Phonon::VideoCategory);
//    player->play(Phonon::MediaSource("http://192.168.1.106:8080/?action=stream"));

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





