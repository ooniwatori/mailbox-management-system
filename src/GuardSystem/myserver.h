#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QObject>
#include"mythread.h"
class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);
    void startServer();
protected:
    void incomingConnection(qintptr socketDecriptor);
};

#endif // MYSERVER_H
