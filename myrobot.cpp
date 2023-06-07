// myrobot.cpp

#include "myrobot.h"

MyRobot::MyRobot(QObject *parent) : QObject(parent) {
    DataToSend.resize(9);
    DataToSend[0] = 0xFF;
    DataToSend[1] = 0x07;
    DataToSend[2] = 0x0;
    DataToSend[3] = 0x0;
    DataToSend[4] = 0x0;
    DataToSend[5] = 0x0;
    DataToSend[6] = 0x0;
    DataToSend[7] = 0x0;
    DataToSend[8] = 0x0;
    DataReceived.resize(21);
    TimerEnvoi = new QTimer();
    // setup signal and slot
    connect(TimerEnvoi, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));

}


void MyRobot::doConnect() {
    socket = new QTcpSocket(this); // socket creation
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    qDebug() << "connecting..."; // this is not blocking call
    //socket->connectToHost("192.168.10.1", 5010);
    socket->connectToHost("192.168.1.106", 15020); // connection to wifibot
    // we need to wait...
    if(!socket->waitForConnected(5002)) {
        qDebug() << "Error: " << socket->errorString();
        return;
    }
    TimerEnvoi->start(75);

}

void MyRobot::disConnect() {
    TimerEnvoi->stop();
    socket->close();
}

void MyRobot::connected() {
    qDebug() << "connected..."; // Hey server, tell me about you.
}

void MyRobot::disconnected() {
    qDebug() << "disconnected...";
}

void MyRobot::bytesWritten(qint64 bytes) {
    qDebug() << bytes << " bytes written...";
}

void MyRobot::readyRead() {
    qDebug() << "reading..."; // read the data from the socket
    DataReceived = socket->readAll();
    emit updateUI(DataReceived);
    qDebug() << DataReceived[0] << DataReceived[1] << DataReceived[2];
}

void MyRobot::MyTimerSlot() {
    qDebug() << "Timer...";
    while(Mutex.tryLock());
    socket->write(DataToSend);
    Mutex.unlock();
}


//fonction permettant calculer le CRC

short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max)
{
    unsigned int Crc = 0xFFFF;
    unsigned int Polynome = 0xA001;
    unsigned int CptOctet = 0;
    unsigned int CptBit = 0;
    unsigned int Parity= 0;
    Crc = 0xFFFF;
    Polynome = 0xA001;
    for ( CptOctet= 1 ; CptOctet < Taille_max ; CptOctet++){
        Crc ^= *( Adresse_tab + CptOctet);
        for ( CptBit = 0; CptBit <= 7 ; CptBit++){
            Parity= Crc;
            Crc >>= 1;
            if (Parity%2 == true) Crc ^= Polynome;
        }
    }
    return(Crc);
}



//directions definition

/*
data goes from 0 to 8

*/
void MyRobot::move(Direction direction, int speed){
    while (Mutex.tryLock());

    this->DataToSend[2] = 0x00;
    this->DataToSend[3] = 0x00;
    this->DataToSend[4] = 0x00;
    this->DataToSend[5] = 0x00;

    //using switch case to define ervery direction
    switch (direction) {
    //forward direction
    case Direction::FORWARD:
        this->DataToSend[2] = speed;
        this->DataToSend[3] = 0;
        this->DataToSend[4] = speed;
        this->DataToSend[5] = 0;
        this->DataToSend[6] = 0b01010000;
        break;

    //backwards left direction
    case Direction::FORWARD_LEFT:
        this->DataToSend[2] = (speed  > 0 ? (speed - 70) : 0);
        this->DataToSend[3] = 0;
        this->DataToSend[4] = speed;
        this->DataToSend[5] = 0;
        this->DataToSend[6] = 0b01010000;
        break;

    //forward right direction
    case Direction::FORWARD_RIGHT:
        this->DataToSend[2] = speed;
        this->DataToSend[3] = 0;
        this->DataToSend[4] = (speed - 70) > 0 ? (speed - 70) : 0 ;
        this->DataToSend[5] = 0;
        this->DataToSend[6] = 0b01010000;
        break;

    //right direction
    //permet de faire du surplace
    case Direction::RIGHT:
        this->DataToSend[2] = speed;
        this->DataToSend[3] = 0;
        this->DataToSend[4] = speed;
        this->DataToSend[5] = 0;
        this->DataToSend[6] = 0b01000000;
        break;

    //left direction
    //permet de faire du surplace
    case Direction::LEFT:
        this->DataToSend[2] = speed;
        this->DataToSend[3] = 0;
        this->DataToSend[4] = speed;
        this->DataToSend[5] = 0;
        this->DataToSend[6] = 0b00010000;
        break;

    //backward direction
    //permet de reculer
    case Direction::BACKWARD:
        this->DataToSend[2] = speed;
        this->DataToSend[3] = 0;
        this->DataToSend[4] = speed;
        this->DataToSend[5] = 0;
        this->DataToSend[6] = 0b00000000;
        break;

    //backward left direction
    case Direction::BACKWARD_LEFT:
        this->DataToSend[2] = (speed - 70) > 0 ? (speed - 70) : 0 ;
        this->DataToSend[3] = 0;
        this->DataToSend[4] = speed;
        this->DataToSend[5] = 0;
        this->DataToSend[6] = 0b00000000;
        break;
    case Direction::BACKWARD_RIGHT:
        this->DataToSend[2] = speed;
        this->DataToSend[3] = 0;
        this->DataToSend[4] = (speed - 130) > 0 ? (speed - 130) : 0 ;
        this->DataToSend[5] = 0;
        this->DataToSend[6] = 0b00000000;
        break;
    default :
        break;
    }

    //envoie du CRC

    unsigned char *p = (unsigned char *)DataToSend.data();
    short crc = (short)Crc16(p, 7);

    DataToSend[7] = (char)crc;
    DataToSend[8] = (char)(crc >> 8);

    Mutex.unlock();
}
