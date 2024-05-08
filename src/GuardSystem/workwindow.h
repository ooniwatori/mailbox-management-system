#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QMainWindow>

namespace Ui {
class WorkWindow;
}

class WorkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkWindow(QWidget *parent = nullptr);
    ~WorkWindow();

private:
    Ui::WorkWindow *ui;
};

#endif // WORKWINDOW_H
