#include "myserver.h"

MyServer::MyServer(QObject *parent)
    : QTcpServer{parent}
{

}

void MyServer::startServer()
{
    int port = 4800;
    if(!this->listen(QHostAddress::Any, port)){
        qDebug() << "Cloud not start a server";
    }
    else{
        qDebug() << "Listening to port " << port << "...";
    }
}

void MyServer::incomingConnection(qintptr socketDecriptor)
{
    qDebug() << socketDecriptor << "Conneting..";

    MyThread *thread = new MyThread(socketDecriptor, this);

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
