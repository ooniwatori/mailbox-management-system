#include "packagepage.h"
#include "ui_packagepage.h"
#include<QtNetwork>
PackagePage::PackagePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PackagePage)
{
    ui->setupUi(this);
}

PackagePage::~PackagePage()
{
    delete ui;
}

void PackagePage::on_btn_cp_clicked()
{
    emit pp2cp();
}


void PackagePage::on_btn_up_clicked()
{
    emit pp2up();
}

//領取郵件
void PackagePage::on_pushButton_clicked()
{
    QString response = "no";
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost(ip, 4800);
    socket->waitForConnected();
    if(socket->state() == QAbstractSocket::ConnectedState)
       {
           QString data = user+"3";
           socket->write(data.toUtf8());
           socket->waitForReadyRead();
           response = QString(socket->readAll());
           socket->disconnect();
       }
    if(response == "ok"){
        qDebug() << response;
    }
}

//更新郵件
void PackagePage::on_pushButton_2_clicked()
{
    QString response = "no";
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost(ip, 4800);
    socket->waitForConnected();
    if(socket->state() == QAbstractSocket::ConnectedState)
       {
           QString data = user+"4";
           socket->write(data.toUtf8());
           socket->waitForReadyRead();
           response = QString(socket->readAll());
           socket->disconnect();
           qDebug() << response;
       }
    response.replace(' ', "\n");
    ui->label_2->setText(response);

}

