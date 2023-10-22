#include "findpassword.h"
#include "ui_findpassword.h"


findpassword::findpassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findpassword)
{
    ui->setupUi(this);

    QStringList strList;
    strList<<"你所在的学校？"<<"你所在的公司？"<<"你所在的居住地？";
    ui->comboBox->addItems(strList);
}

findpassword::~findpassword()
{
    delete ui;
}

void findpassword::on_pushButton_2_clicked()
{
    this->close();
}

void findpassword::on_pushButton_clicked()
{
    QString new_user = ui->lineEdit_2->text();
    QString l = QString("SELECT passwordanswer from user_table where username='%1';").arg(new_user);
    QString pass = QString("SELECT userpassword from user_table where username='%1';").arg(new_user);
    QSqlQuery query;
    QString questionanswer,password;
    query.exec(l);
    while(query.next()){
        questionanswer = query.value(0).toString();
    }
    query.exec(pass);
    while(query.next()){
        password = query.value(0).toString();
    }
    QString x = ui->lineEdit->text();
    if(x == questionanswer){
        QMessageBox::information(this,"你的密码",password);
    }else{
        QMessageBox::information(this,"提示","答案错误！");
    }

}
