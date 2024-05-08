#ifndef MAILDIALOG_H
#define MAILDIALOG_H

#include <QDialog>

namespace Ui {
class MailDialog;
}

class MailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MailDialog(QWidget *parent = nullptr);
    ~MailDialog();
    void setInfo(QString RID, QString RT, QString REM, QString GA, QString GD, QString TA, QString TD, QString MADD, QString MID, QString state);
    void setUser(QString u) { user = u; }

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MailDialog *ui;
    QString RId;
    QString Rtype;
    QString Remark;
    QString GivenA;
    QString GivenD;
    QString TakenA;
    QString TakenD;
    QString Maddress;
    QString MId;
    QString State;
    QString user;
};

#endif // MAILDIALOG_H
