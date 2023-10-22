#ifndef QUESTION_H
#define QUESTION_H

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
class question;
}

class question : public QWidget
{
    Q_OBJECT

public:
    explicit question(QWidget *parent = nullptr);
    ~question();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::question *ui;
};

#endif // QUESTION_H
