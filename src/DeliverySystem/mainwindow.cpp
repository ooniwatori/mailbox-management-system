#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QtNetwork>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1, &pp);
    ui->stackedWidget->insertWidget(2, &cp);
    ui->stackedWidget->insertWidget(3, &up);
    connect(&up, SIGNAL(logoutBtn()), this, SLOT(logoutSignal()));
    connect(&cp, SIGNAL(cp2pp()), this, SLOT(topp()));
    connect(&cp, SIGNAL(cp2up()), this, SLOT(toup()));
    connect(&pp, SIGNAL(pp2cp()), this, SLOT(tocp()));
    connect(&pp, SIGNAL(pp2up()), this, SLOT(toup()));
    connect(&up, SIGNAL(up2pp()), this, SLOT(topp()));
    connect(&up, SIGNAL(up2cp()), this, SLOT(tocp()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// login
void MainWindow::on_pushButton_clicked()
{


    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString response = "nothing";
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost(ip, 4800);
    socket->waitForConnected();
    if(socket->state() == QAbstractSocket::ConnectedState)
       {
           QString data = username+"0"+password;
           socket->write(data.toUtf8());
           socket->waitForReadyRead();
           QByteArray Data = socket->readAll();
           response = QString(Data);
       }
    else{
        qDebug() << "Fail to connect";
    }
    if(response == "ok"){
        ui->label_5->setText("");
        ui->stackedWidget->setCurrentIndex(3);
        pp.setUser(username, ip);
        up.setUser(username, ip);
        cp.setUser(username, ip);
        user = username;
        up.setInfo();
        socket->disconnect();
    }
    else{
        ui->label_5->setStyleSheet("QLabel {color : red;}");
        ui->label_5->setText("帳號密碼錯誤");
    }




}

//log out
void MainWindow::logoutSignal(){
     ui->stackedWidget->setCurrentIndex(0);
     user = "";
     pp.setUser(user, ip);
     up.setUser(user, ip);
     cp.setUser(user, ip);

}


void MainWindow::topp(){
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::tocp(){
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::toup(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_2_clicked()
{
    ip = ui->lineEdit_3->text();
}

