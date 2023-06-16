
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myrobot.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Recuperation du flux video de la camera
    ui->setupUi(this);
    MyRobot *wifibot = new MyRobot();
    QWebEngineView *test = this->ui->cameraFrame;
    QUrl URL = QUrl("http://192.168.1.106:8080/?action=stream");
    test->load(URL);
    test->show();
    //Création d'un timer pour associer la fonction DataSlot
    QTimer* TimerReceived;
    TimerReceived = new QTimer(this);
    connect(TimerReceived, &QTimer::timeout, this, &MainWindow::DataSlot);
    TimerReceived->start(1000);



}


MainWindow::~MainWindow()
{
    delete ui;
}
//Détection des touches et déplacement en conséquences
void MainWindow::keyPressEvent(QKeyEvent* event){
    if(event->key()==Qt::Key_Z || event->key()==Qt::Key_Up){
        wifibot.move(Direction::FORWARD);
    }
    else if(event->key()==Qt::Key_S || event->key()==Qt::Key_Down){
        wifibot.move(Direction::BACKWARD);
    }
    else if(event->key()==Qt::Key_Q || event->key()==Qt::Key_Left){
        wifibot.move(Direction::LEFT);
    }
    else if(event->key()==Qt::Key_D || event->key()==Qt::Key_Right){
        wifibot.move(Direction::RIGHT);
    }
}
//Arret du robot quand on lache les touches
void MainWindow::keyReleaseEvent(QKeyEvent* event){
    wifibot.move(Direction::NONE);
}
//lien entre commandes et bouttons de l'interface
//commentaire test


//connect to robot via button
void MainWindow::on_connect_clicked()
{
    wifibot.doConnect();

}


//disconnect robot
void MainWindow::on_disconnect_clicked()
{
    wifibot.disConnect();
}


//directions linked to buttons
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



//when buttons released robot stops
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



void MainWindow::on_pushButton_clicked()
{
    close();

}


//direction de la camera

//droite
void MainWindow::on_cameraRight_clicked()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QUrl url("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200");
    QNetworkRequest request(url);

    QNetworkReply* reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            qDebug() << "Réponse :" << data;
        } else {
            qDebug() << "Erreur :" << reply->errorString();
        }

        reply->deleteLater();
    });
}


//gauche

void MainWindow::on_cameraLeft_clicked()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QUrl url("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200");
    QNetworkRequest request(url);

    QNetworkReply* reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            qDebug() << "Réponse :" << data;
        } else {
            qDebug() << "Erreur :" << reply->errorString();
        }

        reply->deleteLater();
    });
}

//haut

void MainWindow::on_cameraUp_clicked()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QUrl url("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200");
    QNetworkRequest request(url);

    QNetworkReply* reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            qDebug() << "Réponse :" << data;
        } else {
            qDebug() << "Erreur :" << reply->errorString();
        }

        reply->deleteLater();
    });
}

//bas

void MainWindow::on_cameraDown_clicked()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QUrl url("http://192.168.1.106:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200");
    QNetworkRequest request(url);

    QNetworkReply* reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            qDebug() << "Réponse :" << data;
        } else {
            qDebug() << "Erreur :" << reply->errorString();
        }

        reply->deleteLater();
    });
}

//Fonction utilisée pour récupérer les informations envoyés par le robot
void MainWindow::DataSlot(){
    qDebug() << "Timer...";
    int batteryLevel = (int)(((unsigned char)wifibot.DataReceived[2]/10.0)*100.0/10.1);
    displayOdometry();
    qDebug()<< batteryLevel;
    ui->batteryLevel->setValue(batteryLevel);
}

//change speed
void MainWindow::on_speedSlider_sliderMoved(int position)
{
    wifibot.setSpeed(position);
}
//affichage de l'odometrie
void MainWindow::displayOdometry(){
    last_odometrie =odometrie;//on conserves l'anciene valeur d'odometrie
    odometrie = wifibot.readOdometry();//recuperation de la nouvelle odometrie

    unsigned long odo_L = odometrie[0] - last_odometrie[0];//calcul de la difference d'odometrie depuis le dernier appel de la fonction
    unsigned long odo_R = odometrie[1] - last_odometrie[1];
    float time = 1.0;//on appelle cette fonction toutes les secondes,
    float tic = 0.44/2048.0;//calcul de la distance pour 1 tic (perimetre de la roue/nb tics de la roue)
    QString a = QString::number(odo_L*tic/time);//calcul des vitesses en m/s
    QString b = QString::number(odo_R*tic/time);
    ui->rightSpeed->setText(a);//affichage
    ui->leftSpeed->setText(b);

}

