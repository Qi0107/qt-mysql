#include "stock_system.h"
#include "ui_stock_system.h"

extern QString new_user;

stock_system::stock_system(QWidget *parent)
    :QWidget(parent),
    ui(new Ui::stock_system)

{
    ui->setupUi(this);

    n = new QSqlTableModel;
    n->setTable("user_table");
    ui->tableView_2->setModel(n);

    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->textBrowser->setText(new_user);


}

stock_system::~stock_system()
{
    delete ui;
}

void stock_system::on_pushButton_5_clicked()
{
   /* QString x=ui->lineEdit->text();
    if(x != NULL)
    m->setFilter(QObject::tr("(id ='%1' ) OR (stock ='%2')").arg(x).arg(x));
    m->select();*/
}

void stock_system::on_pushButton_clicked()
{
    store_manager *store_manager1=new store_manager();
    this->close();
    store_manager1->show();
}

void stock_system::on_pushButton_2_clicked()
{


}

void stock_system::on_pushButton_3_clicked()
{
    ui->page->hide();
    ui->page_5->show();
    n->select();
    for (int i=1;i<5;i++) {
        ui->tableView_2->hideColumn(i);
    }
    QSqlQuery query;
    int row=0;
    query.exec("SELECT count(*) FROM user_table");
    while(query.next()){
        row = query.value(0).toInt();
    }
    for (int i=0;i<row;i++) {
        button *button1 =new button();
        button1->setProperty("row",i);
        ui->tableView_2->setIndexWidget(n->index(i,6), button1);
    }

}

void stock_system::on_pushButton_4_clicked()
{


}

void stock_system::on_pushButton_6_clicked()
{
    new_stock *new_stock1=new new_stock();
    new_stock1->show();
}

void stock_system::on_pushButton_9_clicked()
{
    ui->page->show();
    ui->page_5->hide();}
