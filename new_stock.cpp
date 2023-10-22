#include "new_stock.h"
#include "ui_new_stock.h"

new_stock::new_stock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_stock)
{
    ui->setupUi(this);
}

new_stock::~new_stock()
{
    delete ui;
}

void new_stock::on_pushButton_clicked()
{
    QString stock_id = ui->lineEdit->text();
    QString stock_name = ui->lineEdit_2->text();
    QString goods_type = ui->lineEdit_3->text();
    QString x = QString("insert into stock_table values('%1','%2','%3');").arg(stock_id).arg(stock_name).arg(goods_type);
    QSqlQuery query;
    query.exec(x);
    QMessageBox::information(this,"提示","插入成功");
}

void new_stock::on_pushButton_2_clicked()
{
    this->close();
}
