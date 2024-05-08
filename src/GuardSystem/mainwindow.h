#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include "workbench.h"
#include "regform.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool connOpen();
private slots:

    void on_pushButton_login_clicked();

    void on_pushButton_signup_clicked();

    void movehome();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    RegForm regPage;
    WorkBench wbPage;
    QString user;
};



#endif // MAINWINDOW_H
