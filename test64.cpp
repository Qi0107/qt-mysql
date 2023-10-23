
#include "test64.h"
#include "ui_test64.h"
#include <QPushButton>
test64::test64(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::test64)
{
    ui->setupUi(this);
    //创建一个表
    QSqlQuery query;

    QString sqlcreate=QString("create table corporation(id int primary key,"
                              "username varchar(20),"
                              "margin int);");
    query.exec(sqlcreate);
    //配置表格参数
    ui->tableWidget->setRowCount(10);//行
    ui->tableWidget->setColumnCount(3);//列
    connect(ui->bt_shuaxin,&QPushButton::clicked,this,&test64::on_bt_shuaxin_clicked);
    connect(ui->bt_ruku,&QPushButton::clicked,this,&test64::insertdata);
    connect(ui->bt_chuku,&QPushButton::clicked,this,&test64::reduce);
    connect(ui->bt_kong,&QPushButton::clicked,this,&test64::deletedata);

}

void test64::on_bt_shuaxin_clicked(){
            QSqlQuery query;
          //读取表中的最新10条数据
              query.exec("SELECT * FROM corporation");//表名  30代表获取30条数据
              for(int i=0;i<10;i++)
              {
                  query.next();
                  QString id = query.value("id").toString();
                  QString username = query.value("username").toString();
                  QString margin=query.value("margin").toString();
                  int j=0;
                  ui->tableWidget->setItem(i,j, new QTableWidgetItem(id));//第i行第j列
                  j++;
                  ui->tableWidget->setItem(i,j, new QTableWidgetItem(username));
                  j++;
                  ui->tableWidget->setItem(i,j, new QTableWidgetItem(margin));
              }

}



void test64::deletedata(){
    QString id = ui->lineEdit->text();
    QString username=ui->lineEdit_2->text();
    QString margin=ui->lineEdit_3->text();
    QSqlQuery query;
    QString sql="DELETE FROM corporation WHERE id=id";
    query.prepare(sql);
    query.addBindValue(id);
    query.addBindValue(username);
    query.addBindValue(margin);
    if(query.exec())
    {
        QMessageBox::information(this,"通知","成功删除所有数据!");
    }
    else
    {
        QString text=query.lastError().text();
        QMessageBox::warning(this,"提示",text);
    }

}

void test64::reduce()
{
    QSqlQuery query;
    QString id = ui->lineEdit->text();
    query.exec("update corporation set margin=margin-1 where id=id");
    if(query.exec())
    {
        QMessageBox::information(this,"通知","成功删除一条数据!");
    }
    else
    {
        QString text=query.lastError().text();
        QMessageBox::warning(this,"提示",text);
    }
}

void test64::insertdata()
{
    QString id = ui->lineEdit->text();
    QString username=ui->lineEdit_2->text();
    QString margin=ui->lineEdit_3->text();
    QSqlQuery query;
    QString sql="INSERT INTO corporation(id,username,margin)VALUES(:id,:username,:margin)";
    query.prepare(sql);
    query.addBindValue(id);
    query.addBindValue(username);
    query.addBindValue(margin);
    if(query.exec())
    {
        QMessageBox::information(this,"通知","成功插入一条数据!");
    }
    else
    {
        QString text=query.lastError().text();
        QMessageBox::warning(this,"提示",text);
    }
}




QSqlDatabase test64::getConnectionByName(const QString &connectionName)
{
    return QSqlDatabase::database(connectionName);
}

test64::~test64()
{
    delete ui;
}

