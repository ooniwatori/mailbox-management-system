#ifndef WORKBENCH_H
#define WORKBENCH_H

#include <QWidget>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
namespace Ui {
class WorkBench;
}

class WorkBench : public QWidget
{
    Q_OBJECT

public:
    explicit WorkBench(QWidget *parent = nullptr);
    ~WorkBench();
    void setUser(QString u);

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();




    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_tableView_3_doubleClicked(const QModelIndex &index);

    void on_pushButton_10_clicked();

private:
    Ui::WorkBench *ui;
    QSqlDatabase db;
    QString user;
signals:
    void logout();
};

#endif // WORKBENCH_H
