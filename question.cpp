#include "question.h"
#include "ui_question.h"

extern QString new_user;
extern QString new_password;

question::question(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::question)
{
    ui->setupUi(this);

    QStringList strList;
    strList<<"你所在的学校？"<<"你所在的公司？"<<"你所在的居住地？";
    ui->comboBox->addItems(strList);
}

question::~question()
{
    delete ui;
}

void question::on_pushButton_clicked()
{
    QString question=ui->comboBox->currentText();
    QString answer=ui->lineEdit->text();
    QString x=QString("insert into user_table(username,userpassword,passwordquestion,passwordanswer) values('%1','%2','%3','%4');").arg(new_user).arg(new_password).arg(question).arg(answer);
    QSqlQuery query;
    query.exec(x);
    QMessageBox::information(this,"提示","密保问题设置完成");
    this->close();
}

void question::on_pushButton_2_clicked()
{
    this->close();
}
