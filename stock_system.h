#ifndef STOCK_SYSTEM_H
#define STOCK_SYSTEM_H

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
#include<new_stock.h>
#include"store_manager.h"
#include"button.h"
#include"test64.h"

namespace Ui {
class stock_system;
}

class stock_system : public QWidget
{
    Q_OBJECT

public:
    explicit stock_system(QWidget *parent = nullptr);
    ~stock_system();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index);

signals:
    void open(const QModelIndex &index);
    void deleteData(const QModelIndex &index);

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

private:
    QPoint m_mousePoint;  // 鼠标位置
    QScopedPointer<QPushButton> m_pOpenButton;
    QScopedPointer<QPushButton> m_pDeleteButton;
    QStringList m_list;
    int m_nSpacing;  // 按钮之间的间距
    int m_nWidth;  // 按钮宽度
    int m_nHeight;  // 按钮高度
    int m_nType;  // 按钮状态-1：划过 2：按下
    Ui::stock_system *ui;
    QSqlTableModel *m;
    QSqlTableModel *n;
};

#endif // STOCK_SYSTEM_H
