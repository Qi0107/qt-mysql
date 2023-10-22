#ifndef STORE_MANAGER_H
#define STORE_MANAGER_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDebug>
#include<QSqlError>
#include<QMessageBox>
#include<QtSql>
#include <QLineEdit>
#include"question.h"
#include"findpassword.h"
#include"stock_system.h"
#include<QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class store_manager; }
QT_END_NAMESPACE

class store_manager : public QMainWindow
{
    Q_OBJECT

public:
    store_manager(QWidget *parent = nullptr);
    ~store_manager();

    question *window=NULL;

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_findpassword_clicked();

private:
    Ui::store_manager *ui;
};
#endif // STORE_MANAGER_H
