#include "store_manager.h"
#include "ui_store_manager.h"


store_manager::store_manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::store_manager)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("stock_system");
    db.setUserName("root");
    db.setPassword("zk654321");
    if (!db.open())
       qDebug()<<"can't open!"<<db.lastError();
    else
         qDebug()<<"open!";

    setWindowFlags(Qt::FramelessWindowHint);

    setFixedSize(682,386);

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);//密文

    QStringList strList;
    strList<<"普通用户"<<"管理员"<<"仓库出入库管理员"<<"数据管理员"<<"会计";
    ui->comboBox->addItems(strList);

    ui->lineEdit_user->setMaxLength(16);
    ui->lineEdit_password->setMaxLength(16);

}

store_manager::~store_manager()
{
    delete ui;
}


void store_manager::on_pushButton_exit_clicked()
{
    this->close();
}

QString new_user;
QString new_password;
void store_manager::on_pushButton_login_clicked()
{
    new_user = ui->lineEdit_user->text();
    new_password=ui->lineEdit_password->text();
    if(new_user==""){
        QMessageBox::warning(NULL,"提示","用户名不能为空！");
    }else if(new_password==""){
        QMessageBox::warning(NULL,"提示","密码不能为空！");
    }else{
        QString l = QString("SELECT * from user_table where username='%1';").arg(new_user);
        QString s = QString("SELECT * from user_table where username='%1' and userpassword='%2';").arg(new_user).arg(new_password);
        QString a = QString("select power from user_table where username='%1';").arg(new_user);
        QSqlQuery query;
        QString reallyPower;
        QString power=ui->comboBox->currentText();
        query.exec(a);
        while(query.next()){
            reallyPower = query.value(0).toString();
        }
        if(query.exec(l)&&query.exec(s)&&query.size()&&reallyPower == power){
            stock_system *stock_system1=new stock_system();
            this->close();
            stock_system1->show();
        }else if(query.exec(l)&&query.size()){
            if(reallyPower!= power){
                QMessageBox::information(NULL,"提示","您不拥有此权限！");
            }else
            QMessageBox::information(NULL,"提示","密码或账号错误");            
        }else{
            int reply=QMessageBox::question(NULL,"提示","账号不存在是否注册为新账号？", QMessageBox::Yes | QMessageBox::No);
            if(reply==QMessageBox::Yes){
                question *question1 =new question();
                question1->show();
            }else{
            }
        }
    }
}

void store_manager::on_pushButton_findpassword_clicked()
{
    findpassword *findpassword1 = new findpassword();
    findpassword1->show();
}
