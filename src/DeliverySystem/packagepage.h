#ifndef PACKAGEPAGE_H
#define PACKAGEPAGE_H

#include <QWidget>

namespace Ui {
class PackagePage;
}

class PackagePage : public QWidget
{
    Q_OBJECT

public:
    explicit PackagePage(QWidget *parent = nullptr);
    ~PackagePage();
    void setUser(QString s, QString IP) { user = s; ip = IP;}

private:
    Ui::PackagePage *ui;
    QString user;
    QString ip;
signals:
    void pp2cp();
    void pp2up();
private slots:
    void on_btn_cp_clicked();
    void on_btn_up_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // PACKAGEPAGE_H
