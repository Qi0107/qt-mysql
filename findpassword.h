#ifndef FINDPASSWORD_H
#define FINDPASSWORD_H

#include<cstring>
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

namespace Ui {
class findpassword;
}

class findpassword : public QWidget
{
    Q_OBJECT

public:
    explicit findpassword(QWidget *parent = nullptr);
    ~findpassword();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::findpassword *ui;
};

#endif // FINDPASSWORD_H
