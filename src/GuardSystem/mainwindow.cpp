#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include"serverthread.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



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
    ui->stackedWidget->insertWidget(1, &regPage);
    ui->stackedWidget->insertWidget(2, &wbPage);

    connect(&regPage, SIGNAL(returnbtnClicked()), this, SLOT(movehome()));
    connect(&wbPage, SIGNAL(logout()), this, SLOT(movehome()));

    ServerThread *thread = new ServerThread(this);

    thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QSqlQuery qry;
    if(qry.exec("select * from Guards where GAccount='" + username + "' and GPassword='" + password + "'")){
        ui->lineEdit_password->setText("");
        int count = 0;
        while(qry.next()){
            count++;
        }
        if(count == 1){
            ui->lineEdit_username->setText("");
            ui->label_test->setText("");
            ui->stackedWidget->setCurrentIndex(2);
            wbPage.setUser(username);
            user = username;
        }
        else{
            ui->label_test->setStyleSheet("QLabel {color : red;}");
            ui->label_test->setText("帳號或密碼錯誤");
        }
    }
}


void MainWindow::on_pushButton_signup_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::movehome(){
    ui->stackedWidget->setCurrentIndex(0);
    wbPage.setUser("");
    user = "";
}

bool MainWindow::connOpen(){
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("3@6/7dFe*4");
    db.setDatabaseName("mailsystem");
    db.setPort(3306);
    if(!db.open()){
        qDebug() << ("Open failed.");
        return false;
    }
    else{
        qDebug() << ("Open successed.");
        return true;
    }

}

void MainWindow::on_pushButton_clicked()
{
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
}

