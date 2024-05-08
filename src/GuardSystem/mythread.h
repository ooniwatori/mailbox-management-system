#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include<QObject>
#include<QtNetwork>
#include<QTcpSocket>
#include<QDebug>
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(qintptr ID, QObject *parent);
    void run();
private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
public slots:
    void readyRead();
    void disconnected();
signals:
    void error(QTcpSocket::SocketError socketerror);
};

#endif // MYTHREAD_H
