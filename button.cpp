#include "button.h"
#include "ui_button.h"

button::button(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::button)
{
    ui->setupUi(this);

    QStringList strList;
    strList<<"普通用户"<<"管理员"<<"仓库出入库管理员"<<"数据管理员"<<"会计";
    ui->comboBox->addItems(strList);

    QMenu *menu = new QMenu();

    QAction *action  = new QAction("注销",this);
    QAction *action2  = new QAction("禁止登陆",this);
    QAction *action3  = new QAction("允许登陆",this);

    menu->addAction(action);
    menu->addAction(action2);
    menu->addAction(action3);

    connect(action, SIGNAL(triggered()), this, SLOT(action()));

    connect(action2, SIGNAL(triggered()), this, SLOT(action2()));

    connect(action3, SIGNAL(triggered()), this, SLOT(action3()));


    ui->toolButton->setMenu(menu);
}

button::~button()
{
    delete ui;
}

void button::on_pushButton_clicked()
{
    int y = ui->pushButton->parentWidget()->frameGeometry().y();
    int datar = (y/30);
    QString datarow = QString("select username from user_table limit %1,1").arg(datar);
    QSqlQuery query;
    QString username;
    query.exec(datarow);
    qDebug()<<datarow;
    while(query.next()){
        username = query.value(0).toString();
    }
    qDebug()<<username;
    QString x = ui->comboBox->currentText();
    QString changepower = QString("update user_table set power='%1' where username ='%2'").arg(x).arg(username);
    qDebug()<<changepower;
    query.exec(changepower);
}

void button::action(){
    int y = ui->pushButton->parentWidget()->frameGeometry().y();
    int datar = (y/30);
    QString datarow = QString("select username from user_table limit %1,1").arg(datar);
    QSqlQuery query;
    QString username;
    query.exec(datarow);
    qDebug()<<datarow;
    while(query.next()){
        username = query.value(0).toString();
    }
    QString deleteuser = QString("DELETE FROM user_table WHERE username = '%1'").arg(username);
    qDebug()<<deleteuser;
    query.exec(deleteuser);
}

void button::action2(){
    int y = ui->pushButton->parentWidget()->frameGeometry().y();
    int datar = (y/30);
    QString deleteuser = QString("update user_table set power='无' where username ='%1'").arg(datar);
    QSqlQuery query;
    query.exec(deleteuser);
}

void button::action3(){
    int y = ui->pushButton->parentWidget()->frameGeometry().y();
    int datar = (y/30);
    QString reuseuser = QString("update user_table set power='普通用户' where username ='%1'").arg(datar);
    QSqlQuery query;
    query.exec(reuseuser);
}
