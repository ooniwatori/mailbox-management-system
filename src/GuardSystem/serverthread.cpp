#include "serverthread.h"

ServerThread::ServerThread(QObject *parent)
    : QThread{parent}
{

}

void ServerThread::run()
{
    MyServer server;
    server.startServer();

    exec();
}
