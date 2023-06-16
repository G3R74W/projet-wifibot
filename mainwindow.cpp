
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
    qDebug()<< batteryLevel;
    ui->batteryLevel->setValue(batteryLevel);
    //Affichage odométrie
    displayOdometry();
    //Affichage distance IR
    displayIR();

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


void MainWindow::displayIR(){
    //Recuperation valeur en bits
    unsigned char forward_R = wifibot.DataReceived[11];
    unsigned char backward_R = wifibot.DataReceived[4];
    unsigned char forward_L = wifibot.DataReceived[3];
    unsigned char backward_L = wifibot.DataReceived[12];
    //Conversion en voltage
    float FR = (((float)forward_R)*1.3)/99.0;
    float BR = (((float)backward_R)*1.3)/99.0;
    float FL = (((float)forward_L)*1.3)/99.0;
    float BL = (((float)backward_L)*1.3)/99.0;
    //Conversion en cm
    float d_FR = 16.25*pow(FR,4)-129.9*pow(FR,3)+382.3*pow(FR,2)-512.6*FR+301.4;
    float d_BR = 16.25*pow(BR,4)-129.9*pow(BR,3)+382.3*pow(BR,2)-512.6*BR+301.4;
    float d_FL = 16.25*pow(FL,4)-129.9*pow(FL,3)+382.3*pow(FL,2)-512.6*FL+301.4;
    float d_BL = 16.25*pow(BL,4)-129.9*pow(BL,3)+382.3*pow(BL,2)-512.6*BL+301.4;
    //Conversion en string
    QString dist_FR = QString::number(d_FR);
    QString dist_BR = QString::number(d_BR);
    QString dist_FL = QString::number(d_FL);
    QString dist_BL = QString::number(d_BL);
    //Affichage des données dans l'interface
    ui->IR_FR->setText(dist_FR);
    ui->IR_FL->setText(dist_FL);
    ui->IR_BR->setText(dist_BR);
    ui->IR_BL->setText(dist_BL);



}
