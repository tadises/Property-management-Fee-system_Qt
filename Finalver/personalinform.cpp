#include "personalinform.h"
#include "ui_personalinform.h"
#include "main.h"

extern nm users[200];
extern int number;
extern char c_username[20];
personalinform::personalinform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personalinform)
{
    ui->setupUi(this);
}

personalinform::~personalinform()
{
    delete ui;
}

void personalinform::on_fresh_clicked()
{
    nm c_user;
    readall(users);
    c_user = search(c_username);                                                //查找当前用户信息
    QString str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11;
    str0 = QString::fromUtf8(c_user.username);
    str1 = QString::fromUtf8(c_user.key);
    str2 = QString::fromUtf8(c_user.name);
    str3 = QString::fromUtf8(c_user.sex);
    str4 = QString::fromUtf8(c_user.phone);
    str5 = QString::number(c_user.building);
    str6 = QString::number(c_user.unit);
    str7 = QString::number(c_user.room);
    str8 = QString::number(c_user.we_charge);
    str9 = QString::number(c_user.t_charge);
    str10 = QString::number(c_user.owemoney);
    str11 = QString(c_user.other);
    ui->pi ->setItem(0, 0,new QTableWidgetItem(str0));
    ui->pi ->setItem(1, 0,new QTableWidgetItem(str1));
    ui->pi ->setItem(2, 0,new QTableWidgetItem(str2));
    ui->pi ->setItem(3, 0,new QTableWidgetItem(str3));
    ui->pi ->setItem(4, 0,new QTableWidgetItem(str4));
    ui->pi ->setItem(5, 0,new QTableWidgetItem(QString::number(c_user.building)));
    ui->pi ->setItem(6, 0,new QTableWidgetItem(QString::number(c_user.unit)));
    ui->pi ->setItem(7, 0,new QTableWidgetItem(QString::number(c_user.room)));
    ui->pi ->setItem(8, 0,new QTableWidgetItem(str11));                         //在表格中显示
}


void personalinform::on_save_clicked()
{
    nm c_user;
    readall(users);
    c_user = search(c_username);
    int building_i, unit_i, room_i,i=0,we_charge_i,t_charge_i,owemoney_i;
    char  * key_str=NULL,*username_str = NULL,* sex_str=NULL,* name_str=NULL ,*phone_str=NULL,*other_str=NULL;
    QByteArray username_qba = ui->pi->item(0,0)->text().toUtf8();
    username_str = username_qba.data();
    QByteArray key_qba = ui->pi->item(1,0)->text().toUtf8();
    key_str=key_qba.data();
    QByteArray name_qba = ui->pi->item(2,0)->text().toUtf8();
    name_str=name_qba.data();
    QByteArray sex_qbr = ui->pi->item(3,0)->text().toUtf8();
    sex_str = sex_qbr.data();
    QByteArray phone_qbr = ui->pi->item(4,0)->text().toUtf8();
    phone_str = phone_qbr.data();
    building_i = ui->pi->item(5,0)->text().toInt();
    unit_i = ui->pi->item(6,0)->text().toInt();
    room_i = ui->pi->item(7,0)->text().toInt();                    //读取表格内容，转换数据
    QByteArray other_qbr = ui->pi->item(8,0)->text().toUtf8();
    other_str = other_qbr.data();
    i=search_i(c_user.username);
    strcpy(c_user.username,username_str);
    strcpy(c_user.key,key_str);
    strcpy(c_user.sex,sex_str);
    strcpy(c_user.name,name_str);
    strcpy(c_user.phone,phone_str);
    strcpy(c_user.other,other_str);
    c_user.building = building_i;
    c_user.unit = unit_i;
    c_user.room = room_i;
    c_user.we_charge = users[i].we_charge;
    c_user.t_charge = users[i].t_charge;
    c_user.owemoney = users[i].owemoney;
    users[i]=c_user;
    save(users);                                                    //调用保存函数
}


void personalinform::on_quit_clicked()
{
    this->close();                                                  //关闭弹窗
}

