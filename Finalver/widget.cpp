#include "widget.h"
#include "ui_widget.h"
#include "QTableWidget"
#include "main.h"
#include "QMessageBox"

extern nm users[200];                                                                   //全局变量，结构体数组
extern int number;                                                                      //全局变量，内存中结构体数组组数
extern char c_username[20];

nm* temp=NULL;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    number = readall(users);
    money();
    save(users);
    temp = rankmoney(users);

    ui->setupUi(this);
    for(int i = 0; i < ui->table_user->rowCount()+1;i++)//行
    {


        if(users[i].t_charge<=0) continue;
        ui->table_user ->setItem(i, 0,new QTableWidgetItem(QString::fromUtf8(users[i].username)));
        ui->table_user ->setItem(i, 1,new QTableWidgetItem(QString::fromUtf8(users[i].name)));
        ui->table_user ->setItem(i, 2,new QTableWidgetItem(QString::number(users[i].t_charge)));

    }                                                                                   //预加载公示表格


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_chargeinform_clicked()                                                  //查询缴费情况
{
    nm c_user;
    readall(users);
    c_user = search(c_username);                                                        //查找当前用户在结构体数组中的位置
    char print1[20]="您需缴",print2[20];
    if(c_user.owemoney<=0){
        QMessageBox mess(QMessageBox::Information,tr("缴费"),tr("您已提前缴完所需费用"));   //跳出提前缴费弹窗
        QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
        mess.exec();
    }
    else{

        sprintf_s(print2,20,"%d",c_user.t_charge);
        strcat(print1,print2);
        strcat(print1,"元");
        QMessageBox mess(QMessageBox::Information,tr("缴费"),tr(print1));                 //跳出应缴费弹窗
        QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
        mess.exec();
    }


}


void Widget::on_personalinform_clicked()
{
    p->show();                                                                          //打开个人信息窗口
}


void Widget::on_pushButton_clicked()
{
    pa->show();                                                                         //打开缴费窗口
}


void Widget::on_pushButton_2_clicked()
{
    m->show();                                                                          //打开募捐窗口
}

