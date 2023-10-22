#ifndef TEST64_H
#define TEST64_H
#include <QWidget>
#include <QCoreApplication>
#include <QTextCodec>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QDebug>
#include <QTime>
#include <QSqlError>
#include <QSqlDriver>
#include <QString>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
QT_BEGIN_NAMESPACE
namespace Ui { class test64; }
QT_END_NAMESPACE

class test64 : public QMainWindow
{
    Q_OBJECT

public:
    test64(QWidget *parent = nullptr);
    ~test64();

private:
    Ui::test64 *ui;
private:
    void deletedata(void);
    void createConnectionByName(void);
    QSqlDatabase getConnectionByName(const QString &connectionName);
    void insertdata(void);
    void reduce(void);
    void on_bt_shuaxin_clicked();
};
#endif // TEST64_H
