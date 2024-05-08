#include "calenderpage.h"
#include "qtablewidget.h"
#include "ui_calenderpage.h"
#include<QtNetwork>
CalenderPage::CalenderPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalenderPage)
{
    ui->setupUi(this);
}

CalenderPage::~CalenderPage()
{
    delete ui;
}

void CalenderPage::on_btn_pp_clicked()
{
    emit cp2pp();
}


void CalenderPage::on_btn_up_clicked()
{
    emit cp2up();
}


void CalenderPage::on_calendarWidget_clicked(const QDate &date)
{
    selectedDate = ui->calendarWidget->selectedDate().toString();
    ui->label_2->setText(selectedDate);
    qDebug() << selectedDate;

    QStringList d = selectedDate.split(" ");
    QString y = d.value(3);
    QString day = d.value(2).rightJustified(2,'0');
    QString m = d.value(1);
    if(m == "Jan"){
        m = "01";
    }
    else if(m == "Feb"){
        m = "02";
    }
    else if(m == "Mar"){
        m = "03";
    }
    else if(m == "Apr"){
        m = "04";
    }
    else if(m == "May"){
        m = "05";
    }
    else if(m == "Jun"){
        m = "06";
    }
    else if(m == "Jul"){
        m = "07";
    }
    else if(m == "Aug"){
        m = "08";
    }
    else if(m == "Sep"){
        m = "09";
    }
    else if(m == "Oct"){
        m = "10";
    }
    else if(m == "Nov"){
        m = "11";
    }
    else if(m == "Dec"){
        m = "12";
    }
    QString d_t = y + "-" + m + "-" + day;
    QString response = "no";
    QTcpSocket *socket = new QTcpSocket(this);
    socket->connectToHost(ip, 4800);
    socket->waitForConnected();
    if(socket->state() == QAbstractSocket::ConnectedState)
       {
           QString data = user+"2"+d_t;
           socket->write(data.toUtf8());
           socket->waitForReadyRead();
           response = QString(socket->readAll());
           socket->disconnect();
           qDebug() << response;
       }
    response.replace(' ', "\n");
    qDebug() << response;
    ui->label_3->setText(response);
}

