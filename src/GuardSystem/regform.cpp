#include "regform.h"
#include "ui_regform.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include "mainwindow.h"

RegForm::RegForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegForm)
{
    ui->setupUi(this);
}

RegForm::~RegForm()
{
    delete ui;
}

void RegForm::on_pushButton_clicked()
{

    bool acc_varify = false, pss_varify = false;
    QString name = ui->lineEdit_name->text();
    QString account = ui->lineEdit_uraccount->text();
    QString password = ui->lineEdit_pass->text();
    QString password_2 = ui->lineEdit_passConfirm->text();
    QSqlQuery qry;
    //"select * from Guards where GAccount='" + account + "'"
    qry.exec("select GAccount from Guards where GAccount='" + account + "'");
    qry.first();
    if(qry.value(0).toString().length() > 0 || account == ""){
        qDebug() << qry.value(0);
        ui->label_acc_sat->setStyleSheet("QLabel {color : red;}");
        ui->label_acc_sat->setText("帳號重複");
        acc_varify = false;
    }
    else {
        ui->label_acc_sat->setStyleSheet("QLabel {color : green;}");
        ui->label_acc_sat->setText("✓");
        acc_varify = true;
    }

    if(QString::compare(password, password_2, Qt::CaseSensitive) || password == ""){
        ui->label_sat->setStyleSheet("QLabel {color : red;}");
        ui->label_sat->setText("密碼不一致");
        pss_varify = false;
    }
    else {
        ui->label_sat->setStyleSheet("QLabel {color : green;}");
        ui->label_sat->setText("✓");
        pss_varify = true;
    }

    if (acc_varify && pss_varify){
        qry.prepare("insert into Guards values('"+ account + "', '" + password + "', '" + name + "')");
        qry.exec();
        ui->stackedWidget_2->setCurrentIndex(1);
        ui->label_urname->setText("姓名: " + name);
        ui->label_uraccount->setText("帳號: " + account);
    }

}


void RegForm::on_pushButton_2_clicked()
{

    emit returnbtnClicked();

}

