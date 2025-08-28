#include "logging.h"
#include "ui_logging.h"
#include "widget.h"
#include "main.h"
#include "rootc.h"
#include "QMessageBox"
extern nm users[200];                                                       //全局变量，用户结构体数组
extern int number;
char c_username[20];                                                        //当前用户结构体

Logging::Logging(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logging)
{
    ui->setupUi(this);

}

Logging::~Logging()
{
    delete ui;
}

void Logging::on_out_clicked()
{
    this->close();
}


void Logging::on_log_clicked()
{
    number = readall(users);
    nm* user;
    user = (nm*)malloc(sizeof(nm));
    char*  username_str,* key_str;                                          //读取文本框内的文字，并转换数据
    QByteArray username_qba = ui->username->text().toLocal8Bit();
    username_str=username_qba.data();
    QByteArray key_qba = ui->key->text().toLocal8Bit();
    key_str=key_qba.data();

    strcpy(user->username,username_str);
    strcpy(user->key,key_str);

    if(log(user)==1){                                                       //调用后端登录函数
        strcpy(c_username,username_str);                                    //符合用户情况，弹出下一窗口
        w->show();

        this->close();
    }
    else if(log(user)==-1){
        r->show();                                                          //弹出管理员窗口
        this->close();
    }
    else {                                                                  //不符合情况，弹出用户名或密码错误
        QMessageBox mess(QMessageBox::Information,tr("logging"),tr("用户名或密码错误！"));
        QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
        mess.exec();
    }
    free(user);


}




void Logging::on_create_clicked()
{
    c->show();                                                              //弹出创建账户窗口
    //c.show();

}

