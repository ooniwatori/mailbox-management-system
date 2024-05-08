#ifndef CALENDERPAGE_H
#define CALENDERPAGE_H

#include <QWidget>

namespace Ui {
class CalenderPage;
}

class CalenderPage : public QWidget
{
    Q_OBJECT

public:
    explicit CalenderPage(QWidget *parent = nullptr);
    ~CalenderPage();
    void setUser(QString s, QString IP) { user = s; ip = IP;}

private:
    Ui::CalenderPage *ui;
    QString selectedDate;
    QString user;
    QString ip;
signals:
    void cp2pp();
    void cp2up();

private slots:
    void on_btn_pp_clicked();
    void on_btn_up_clicked();
    void on_calendarWidget_clicked(const QDate &date);
};

#endif // CALENDERPAGE_H
