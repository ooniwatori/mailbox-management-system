#include "workbench.h"
#include "ui_workbench.h"
#include"maildialog.h"
WorkBench::WorkBench(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkBench)
{
    ui->setupUi(this);
    ui->lineEdit_mid_1->setMaxLength(5);
    ui->lineEdit_mid_2->setMaxLength(5);
    ui->lineEdit_mid_3->setMaxLength(5);
    ui->lineEdit_mid_4->setMaxLength(5);
    ui->lineEdit_remark->setMaxLength(45);

}

WorkBench::~WorkBench()
{
    delete ui;
}
//未領
void WorkBench::on_pushButton_5_clicked()
{
    /*db = QSqlDatabase::addDatabase("QODBC");
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

    }*/
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);

    qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'N' or State = 'W' order by RId desc");
    qry->exec();
    modal->setQuery(std::move(*qry));
    delete qry;
    ui->tableView->setModel(modal);
    ui->tableView->setColumnWidth(0, 120);
    ui->tableView->setColumnWidth(1, 120);
    ui->tableView->setColumnWidth(2, 140);
    ui->tableView->setColumnWidth(3, 200);
}

//登記
void WorkBench::on_pushButton_4_clicked()
{
    QSqlQuery qry;
    QString MId = ui->lineEdit_mid_1->text() + ui->lineEdit_mid_2->text() + ui->lineEdit_mid_3->text() + ui->lineEdit_mid_4->text();
    QString MAddress;
    if(ui->comboBox_add->currentText() != "錯誤郵件"){
        MAddress = ui->comboBox_add->currentText()
                    + ui->comboBox_floor->currentText().rightJustified(2,'0')
                    + ui->comboBox_num->currentText().rightJustified(2,'0');
    }
    else{
        MAddress = "9999999";
    }
    QString Rtype  = (ui->comboBox_type->currentIndex() == 0 ? "掛" : "包");
    QString Remark = ui->lineEdit_remark->text();
    Remark = (Remark.length() == 0 ? "null" : "'"+Remark+"'");
    QString State = "N";
    QString TakenAccount = user;
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime1 = date.toString("yyyy-MM-dd");
    QString formattedTime2 = date.toString("yyyyMMdd");
    qry.prepare("select count(TakenDate) from Mails where TakenDate = '" + formattedTime1 + "'");
    qry.exec();
    qry.first();
    QString RId = formattedTime2+qry.value(0).toString().rightJustified(3,'0');

    qry.exec("insert into Mails values ('"+RId+"', '"+MId+"', '"+Rtype +"',"+Remark+", '"+State+"',null, null,'"+TakenAccount+"', '"+formattedTime1+"','"+MAddress+"')");

    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry2 = new QSqlQuery(db);

    qry2->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'N' or State = 'W' order by RId desc");
    qry2->exec();
    modal->setQuery(std::move(*qry2));
    delete qry2;
    ui->tableView->setModel(modal);
    ui->tableView->setColumnWidth(0, 120);
    ui->tableView->setColumnWidth(1, 120);
    ui->tableView->setColumnWidth(2, 280);
}
//設定目前使用者
void WorkBench::setUser(QString u){
    user = u;
    QSqlQuery qry;
    qry.exec("select GName from Guards where GAccount = '" + user + "'");
    qry.first();
    ui->label_use->setText("目前使用者:" + qry.value(0).toString());
}
//登出
void WorkBench::on_pushButton_7_clicked()
{
    user = "";
    emit logout();
}

//欲領
void WorkBench::on_pushButton_8_clicked()
{

    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);

    qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'W' order by RId desc");
    qry->exec();
    modal->setQuery(std::move(*qry));
    delete qry;
    ui->tableView_2->setModel(modal);
    ui->tableView_2->setColumnWidth(0, 120);
    ui->tableView_2->setColumnWidth(1, 120);
    ui->tableView_2->setColumnWidth(2, 140);
    ui->tableView_2->setColumnWidth(3, 200);
}

//已領
void WorkBench::on_pushButton_9_clicked()
{
    /*db = QSqlDatabase::addDatabase("QODBC");
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

    }*/
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);

    qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'T' order by RId desc");
    qry->exec();
    modal->setQuery(std::move(*qry));
    delete qry;
    ui->tableView_3->setModel(modal);
    ui->tableView_3->setColumnWidth(0, 120);
    ui->tableView_3->setColumnWidth(1, 120);
    ui->tableView_3->setColumnWidth(2, 140);
    ui->tableView_3->setColumnWidth(3, 200);
}

//重設住戶密碼
void WorkBench::on_pushButton_6_clicked()
{
    QString RAddress = ui->comboBox_add_2->currentText()
            + ui->comboBox_floor_2->currentText().rightJustified(2,'0')
            + ui->comboBox_num_2->currentText().rightJustified(2,'0');
    QSqlQuery qry;
    qry.prepare("update Resident set RPassword = '" + RAddress+"' where RId = '" + RAddress+ "'");
    ui->label_10->setText("重設成功:   " + RAddress);
    ui->label_10->setStyleSheet("QLabel {color : green;}");
}

//選取郵件
void WorkBench::on_tableView_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *imodel = ui->tableView->model();
    QString data = imodel->data(index).toString();
    qDebug() << data;
    QSqlQuery qry;
    qry.exec("select * from Mails where RId = '" + data +"'");
    qry.first();
    QString RId = qry.value(0).toString();
    QString RType = qry.value(2).toString();
    QString Remark = qry.value(3).toString();
    QString State = qry.value(4).toString();
    QString GivenA = qry.value(5).toString();
    QString GivenD = qry.value(6).toString();
    QString TakenA = qry.value(7).toString();
    QString TakenD = qry.value(8).toString();
    QString MId = qry.value(1).toString();
    QString Maddress = qry.value(9).toString();
    MailDialog *dialog = new MailDialog(this);
    dialog->setInfo(RId, RType, Remark, GivenA, GivenD, TakenA, TakenD, Maddress, MId, State);
    dialog->setUser(user);
    dialog->show();
}

//查詢未領
void WorkBench::on_pushButton_clicked()
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
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);
    QString s = ui->lineEdit->text();
    int len = s.length();
    if(len >= 14){
        qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'N' and MId = '"+s+"' order by RId desc");
    }
    else if(len == 11){
        qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'N' and RId = '"+s+"' order by RId desc");
    }
    else if(len == 7){
        qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'N' and MAddress = '"+s+"' order by RId desc");
    }
    qDebug() << qry->lastQuery();
    qry->exec();
    modal->setQuery(std::move(*qry));
    delete qry;
    ui->tableView->setModel(modal);
    ui->tableView->setColumnWidth(0, 120);
    ui->tableView->setColumnWidth(1, 120);
    ui->tableView->setColumnWidth(2, 140);
    ui->tableView->setColumnWidth(3, 200);
}

//查詢欲領
void WorkBench::on_pushButton_2_clicked()
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
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);
    QString s = ui->lineEdit_2->text();
    int len = s.length();
    if(len >= 14){
        qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'W' and MId = '"+s+"' order by RId desc");
    }
    else if(len == 11){
        qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'W' and RId = '"+s+"' order by RId desc");
    }
    else if(len == 7){
        qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'W' and MAddress = '"+s+"' order by RId desc");
    }

    qry->exec();
    modal->setQuery(std::move(*qry));
    delete qry;
    ui->tableView_2->setModel(modal);
    ui->tableView_2->setColumnWidth(0, 120);
    ui->tableView_2->setColumnWidth(1, 120);
    ui->tableView_2->setColumnWidth(2, 140);
    ui->tableView_2->setColumnWidth(3, 200);
}

//查詢已領
void WorkBench::on_pushButton_3_clicked()
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
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);
    QString s = ui->lineEdit_3->text();
    int len = s.length();
    if(len >= 14){
        qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'T' and MId = '"+s+"' order by RId desc");
    }
    else if(len == 11){
        qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'T' and RId = '"+s+"' order by RId desc");
    }
    else if(len == 7){
        qry->prepare("select RId as '郵件號碼', RType as '郵件類型', MAddress as '收件地址', MId as '郵件編號' from Mails where State = 'T' and MAddress = '"+s+"' order by RId desc");
    }

    qry->exec();
    modal->setQuery(std::move(*qry));
    delete qry;
    ui->tableView_3->setModel(modal);
    ui->tableView_3->setColumnWidth(0, 120);
    ui->tableView_3->setColumnWidth(1, 120);
    ui->tableView_3->setColumnWidth(2, 140);
    ui->tableView_3->setColumnWidth(3, 200);
}


void WorkBench::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *imodel = ui->tableView_2->model();
    QString data = imodel->data(index).toString();
    qDebug() << data;
    QSqlQuery qry;
    qry.exec("select * from Mails where RId = '" + data +"'");
    qry.first();
    QString RId = qry.value(0).toString();
    QString RType = qry.value(2).toString();
    QString Remark = qry.value(3).toString();
    QString State = qry.value(4).toString();
    QString GivenA = qry.value(5).toString();
    QString GivenD = qry.value(6).toString();
    QString TakenA = qry.value(7).toString();
    QString TakenD = qry.value(8).toString();
    QString MId = qry.value(1).toString();
    QString Maddress = qry.value(9).toString();
    MailDialog *dialog = new MailDialog(this);
    dialog->setInfo(RId, RType, Remark, GivenA, GivenD, TakenA, TakenD, Maddress, MId, State);
    dialog->setUser(user);
    dialog->show();
}


void WorkBench::on_tableView_3_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *imodel = ui->tableView_3->model();
    QString data = imodel->data(index).toString();
    qDebug() << data;
    QSqlQuery qry;
    qry.exec("select * from Mails where RId = '" + data +"'");
    qry.first();
    QString RId = qry.value(0).toString();
    QString RType = qry.value(2).toString();
    QString Remark = qry.value(3).toString();
    QString State = qry.value(4).toString();
    QString GivenA = qry.value(5).toString();
    QString GivenD = qry.value(6).toString();
    QString TakenA = qry.value(7).toString();
    QString TakenD = qry.value(8).toString();
    QString MId = qry.value(1).toString();
    QString Maddress = qry.value(9).toString();
    MailDialog *dialog = new MailDialog(this);
    dialog->setInfo(RId, RType, Remark, GivenA, GivenD, TakenA, TakenD, Maddress, MId, State);
    dialog->setUser(user);
    dialog->show();
}


void WorkBench::on_pushButton_10_clicked()
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

