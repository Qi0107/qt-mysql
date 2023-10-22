#ifndef NEW_STOCK_H
#define NEW_STOCK_H

#include <QWidget>
#include<cstring>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDebug>
#include<QSqlError>
#include<QMessageBox>
#include<QtSql>
#include <QLineEdit>
#include<QWidget>

namespace Ui {
class new_stock;
}

class new_stock : public QWidget
{
    Q_OBJECT

public:
    explicit new_stock(QWidget *parent = nullptr);
    ~new_stock();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::new_stock *ui;
};

#endif // NEW_STOCK_H
