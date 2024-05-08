#include "maildialog.h"
#include "qdatetime.h"
#include "ui_maildialog.h"
#include<QSqlQuery>
MailDialog::MailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MailDialog)
{
    ui->setupUi(this);
}

MailDialog::~MailDialog()
{
    delete ui;
}

void MailDialog::on_pushButton_3_clicked()
{
    accept();
}


void MailDialog::on_pushButton_clicked()
{
    QString s;
    if(State == "遺失"){
        State = "未領";
        s = 'N';

    }
    else if(State == "未領"){
        State = "遺失";
        s = 'L';
    }
    ui->lineEdit_state->setText(State);
    QSqlQuery qry;
    qry.prepare("update Mails set State = '"+s+"' where RId = '"+RId+"'");


}

void MailDialog::setInfo(QString RID, QString RT, QString REM, QString GA, QString GD, QString TA, QString TD, QString MADD, QString MID, QString state)
{

    RId=RID;
    Rtype=(RT == "掛" ? "掛號":"包裹");
    Remark=REM;
    QSqlQuery qry;
    qry.exec("select GName from Guards where GAccount = '"+GA+"'");
    qry.first();
    GivenA=qry.value(0).toString();
    qDebug() << qry.value(0);
    GivenD=GD;
    if(TA.length() > 0){
        QSqlQuery qry1;
        qry1.exec("select GName from Guards where GAccount = '"+TA+"'");
        qry1.first();
        TakenA=qry1.value(0).toString();
    }
    else{
        TakenA=TA;
    }

    TakenD=TD;
    Maddress=MADD;
    MId=MID;
    if(state == 'L'){
        State = "遺失";
    }
    else if(state == 'N'){
        State ="未領";
    }
    else if(state == 'W'){
        State = "欲領";
    }
    else if(state == 'T'){
        State = "已領";
        ui->lineEdit_state->setEnabled(false);
    }
    ui->lineEdit_rid->setText(RId);
    ui->lineEdit_type->setText(Rtype);
    ui->lineEdit_Rem->setText(Remark);
    ui->lineEdit_GG->setText(GivenA);
    ui->lineEdit_GD->setText(GivenD);
    ui->lineEdit_TG->setText(TakenA);
    ui->lineEdit_TD->setText(TakenD);
    ui->lineEdit_add->setText(Maddress);
    ui->lineEdit_MId->setText(MId);
    ui->lineEdit_state->setText(State);
}


void MailDialog::on_pushButton_2_clicked()
{
    if(State == "欲領"){
        QDateTime date = QDateTime::currentDateTime();
        QString formattedTime1 = date.toString("yyyy-MM-dd");
        State = 'T';
        ui->lineEdit_state->setText("已領");
        QSqlQuery qry;
        qry.exec("select GName from Guards where GAccount = '"+user+"'");
        qry.first();
        ui->lineEdit_GG->setText(qry.value(0).toString());
        ui->lineEdit_GD->setText(formattedTime1);
        QSqlQuery qry1;
        qry1.prepare("update Mails set State = '"+State+"', GivenAccount = '"+user+"', GivenDate = '"+formattedTime1+"' where RId = '"+RId+"'");
        qry1.exec();
        qDebug() << qry1.lastQuery();
    }
}

