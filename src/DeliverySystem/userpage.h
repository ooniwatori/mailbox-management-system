#ifndef USERPAGE_H
#define USERPAGE_H

#include <QWidget>

namespace Ui {
class UserPage;
}

class UserPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = nullptr);
    ~UserPage();
    void setUser(QString s, QString IP) { user = s; ip = IP;}
    void setInfo();

private:
    Ui::UserPage *ui;
    QString user;
    QString ip;
private slots:

    void on_pushButton_4_clicked();

    void on_btn_cp_clicked();

    void on_btn_pp_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

signals:
    void logoutBtn();
    void up2pp();
    void up2cp();
};

#endif // USERPAGE_H
