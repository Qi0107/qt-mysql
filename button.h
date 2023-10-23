#ifndef BUTTON_H
#define BUTTON_H

#include <QStyledItemDelegate>
#include <QWidget>
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
#include <QTest>
#include <QMenu>
#include<QMouseEvent>
#include<new_stock.h>
#include"stock_system.h"

namespace Ui {
class button;
class stock_system;
}

class button : public QWidget
{
    Q_OBJECT

public:
    explicit button(QWidget *parent = nullptr);
    ~button();

private slots:
    void on_pushButton_clicked();
    void action();
    void action2();
    void action3();

private:
    Ui::button *ui;
};

#endif // BUTTON_H
