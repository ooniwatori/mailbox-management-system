#include "mythread.h"
#include "mainwindow.h"
MyThread::MyThread(qintptr ID, QObject *parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run(){
    qDebug() << "Thread starting";
    socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << socketDescriptor << "Client Connected";

    exec();
}

void MyThread::readyRead()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("3@6/7dFe*4");
    db.setDatabaseName("mailsystem");
    db.setPort(3306);
    if(!db.open()){
        qDebug() << ("Open failed.");

    }
    else{
        qDebug() << ("Open successed.");

    }
    QByteArray Data = socket->readAll();
    qDebug() << socketDescriptor << "Data in:" << Data;
    QString request = QString(Data);
    QString address = request.first(7);
    QString type = request.mid(7,1);
    QDataStream out{socket};
    if(type == '0'){ // login
        QString password = request.mid(8, request.length()-8);
        qDebug() << "User:" << address;
        qDebug() << "Password:" << password;
        socket->waitForConnected();
        QSqlQuery qry;
        QString resp;
        if(qry.exec("select * from Residents where RAddress='" + address + "' and RPassword='" + password + "'")){

            if(qry.first()){
                resp = "ok";
                qDebug() << resp;
                socket->write(resp.toUtf8());
                socket->flush();
            }
            else{
                qDebug() << "no";
                resp = "no";
                out << resp;
            }
        }
    }
    else if(type == '1'){ // change password
        QSqlQuery qry;
        QString password = request.mid(8, request.length()-8);
        qry.exec("update Residents set RPassword = '"+password+"' where RAddress = '"+address+"'");
        socket->write("ok");
    }
    else if(type == '2'){ // search mail
        QSqlQuery qry;
        QString mails = "";
        QString date = request.mid(8, request.length()-8);
        qry.exec("select RId from Mails where MAddress = '"+address+"' and TakenDate = '"+date+"'order by RId desc");
        while (qry.next()) {
                QString state = qry.value(1).toString();
                state = (state == "N" ? "未領" : "已領");
                QString mail = qry.value(0).toString() + ":" + state + " ";
                qDebug() << mail;
                mails += mail;
            }
        qDebug() << mails;
        mails = (mails == "" ? "None" : mails);
        socket->write(mails.toUtf8());
    }
    else if(type == '3'){ // take mail
        QSqlQuery qry;
        qry.exec("update Mails set State = 'W' where MAddress = '"+address+"' and State = 'N'");
        socket->write("ok");
    }
    else if(type == '4'){ // look mail
        QSqlQuery qry;
        QString mails = "";
        qry.exec("select RId, State from Mails where  MAddress = '"+address+"' and State = 'N' order by RId desc");
        while (qry.next()) {
                mails += qry.value(0).toString() + " ";
            }
        qDebug() << mails;
        qDebug() << qry.lastQuery();
        mails = (mails == "" ? "None" : mails);
        socket->write(mails.toUtf8());
    }
    else if(type == '5'){ // set notice time
        QSqlQuery qry;
        QString time = request.mid(8, request.length()-8);
        qry.exec("update Residents set NoticeTime = '"+time+"' where RAddress = '"+address+"'");
        socket->write("ok");
    }


}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << "Disconnected";

    socket->deleteLater();
    exit(0);
}
