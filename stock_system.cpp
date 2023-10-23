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

    QObject::connect(n, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), ui->tableView_2, SLOT(update()));
}

stock_system::~stock_system()
{
    delete ui;
}

void stock_system::update(){
        ui->tableView_2->viewport()->update();
}

void stock_system::on_pushButton_5_clicked()
{

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
    ui->page_7->hide();
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
        button1->setMinimumSize(70,0);
        button1->setStyleSheet("QPushButton,QToolButton,QComboBox {background-color: #ffffff;border: 1px solid #dcdfe6;padding: 5px;border-radius: 5px;}QPushButton:hover,QToolButton:hover {background-color: #ecf5ff;color: #409eff;}QPushButton:pressed,QToolButton:pressed, QPushButton:checked {border: 1px solid #3a8ee6;color: #409eff;}border-radius: 20px;");
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
    ui->page_5->hide();
}

void stock_system::on_pushButton_7_clicked()
{
    QString x=ui->lineEdit->text();
    int row=0;
    QSqlQuery query;
    query.exec("SELECT count(*) FROM user_table");
    while(query.next()){
        row = query.value(0).toInt();
    }
    QString username;
    for (int i=0;i<row;i++) {
        ui->tableView_2->hideRow(i);
        QSqlQuery query;
        QString m =QString("SELECT username FROM user_table limit %1,1").arg(i);
        query.exec(m);
        while(query.next()){
            username = query.value(0).toString();
        }
        qDebug()<<username;
        qDebug()<<x;
        if(x==username||x=="")
            ui->tableView_2->showRow(i);
    }
}
