#include "userpage.h"
#include "ui_userpage.h"
#include<QtNetwork>
UserPage::UserPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPage)
{
    ui->setupUi(this);
}

UserPage::~UserPage()
{
    delete ui;
}

void UserPage::setInfo()
{
    ui->label_3->setText(user);
    QString no = user.first(3);
    QString floor = user.mid(3,2);
    QString n = user.mid(5,2);
    ui->label_4->setText("中華東路三段"+no+"號"+floor+"樓之"+n);
}

void UserPage::on_pushButton_4_clicked()
{
    emit logoutBtn();
}





void UserPage::on_btn_cp_clicked()
{
    emit up2cp();
}


void UserPage::on_btn_pp_clicked()
{
    emit up2pp();
}

//設定密碼
void UserPage::on_pushButton_3_clicked()
{
    QString s1 = ui->lineEdit->text();
    QString s2 = ui->lineEdit_2->text();
    if(s1 != s2){
         ui->label_7->setText("密碼不一致");
    }
    else {
        QString response = "no";
        QTcpSocket *socket = new QTcpSocket(this);
        socket->connectToHost(ip, 4800);
        socket->waitForConnected();
        if(socket->state() == QAbstractSocket::ConnectedState)
           {
               QString data = user+"1"+s2;
               socket->write(data.toUtf8());
               socket->waitForReadyRead();
               response = QString(socket->readAll());
               //socket->disconnect();
           }
        if(response == "ok"){
            ui->label_7->setText("設定成功");
        }
        else{
            ui->label_7->setText("設定失敗");
        }
    }
}

//設定時間
void UserPage::on_pushButton_clicked()
{
    int new_time = ui->comboBox->currentIndex();
    QString response = "no";
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost(ip, 4800);
    socket->waitForConnected();
    if(socket->state() == QAbstractSocket::ConnectedState)
       {
           QString data = user+"5"+QString::number(new_time);
           qDebug() << data;
           socket->write(data.toUtf8());
           socket->waitForReadyRead();
           response = QString(socket->readAll());
           //socket->disconnect();
       }
    if(response == "ok"){
        ui->label_9->setText("設定成功");
    }
    else{
        ui->label_9->setText("設定失敗");
    }

}

