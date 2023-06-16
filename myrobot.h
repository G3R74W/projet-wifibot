#ifndef MYROBOT_H
#define MYROBOT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QUrl>
#include <QTimer>
#include <QMutex>
#include "direction.h"
#include <iostream>
#include <array>

class MyRobot : public QObject {
    Q_OBJECT
public:
    explicit MyRobot(QObject *parent = 0);
    void doConnect();
    void disConnect();
    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;
    void move(Direction direction);
    int getSpeed();
    void setSpeed(int speed);
    std::array<unsigned long, 2> readOdometry();


signals:
    void updateUI(const QByteArray Data);
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void MyTimerSlot();


private:
    QTcpSocket *socket;
    QTimer *TimerEnvoi;
    int speed;

};

#endif // MYROBOT_H
