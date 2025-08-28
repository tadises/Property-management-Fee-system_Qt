#include "create_w.h"
#include "ui_create_w.h"
#include "main.h"
#include "string.h"
#include "QMessageBox"
extern nm users[200];
extern int number;


create_w::create_w(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create_w)
{
    ui->setupUi(this);
}

create_w::~create_w()
{
    delete ui;
}

void create_w::on_confirm_clicked()
{
    number = readall(users);

    int building_i, unit_i, room_i,i=0;
    char  * key_str=NULL,* keycon_str=NULL,* sex_str=NULL,* name_str=NULL ,*phone_str=NULL;
    char *username_str = NULL;

    QByteArray username_qba = ui->c_username->text().toUtf8();
    username_str = username_qba.data();
    QByteArray key_qba = ui->c_key->text().toUtf8();
    key_str=key_qba.data();
    QByteArray keycon_qba = ui->c_key_con->text().toUtf8();
    keycon_str=keycon_qba.data();
    QByteArray name_qba = ui->c_name->text().toUtf8();
    name_str=name_qba.data();
    QByteArray sex_qbr = ui->c_sex->currentText().toUtf8();
    sex_str = sex_qbr.data();
    QByteArray phone_qbr = ui->c_phone->text().toUtf8();
    phone_str = phone_qbr.data();
    building_i = ui->c_building->text().toInt();
    unit_i = ui->c_unit->text().toInt();
    room_i = ui->c_room->text().toInt();                        //读取信息栏中的数据，转换数据

    nm* newuser;
    newuser = (nm*)malloc(sizeof(nm));
    strcpy(newuser->username,username_str);
    strcpy(newuser->key,key_str);
    strcpy(newuser->sex,sex_str);
    strcpy(newuser->name,name_str);
    strcpy(newuser->phone,phone_str);
    newuser->building = building_i;                             //复制转换数据进结构体
    newuser->unit = unit_i;
    newuser->room = room_i;
    newuser->owemoney = 0;
    newuser->we_charge = 0;
    strcpy(newuser->other,"");
    if(strcmp(key_str,keycon_str)!=0){                          //比较密码和确认密码
        QMessageBox mess(QMessageBox::Information,tr("key"),tr("密码与确认密码不匹配！"));
        QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
        mess.exec();

    }
    else if(create_n(newuser)==1){
        free(newuser);
        ui->c_username->clear();
        ui->c_key->clear();
        ui->c_key_con->clear();
        ui->c_name->clear();
        ui->c_phone->clear();
        ui->c_building->clear();
        ui->c_unit->clear();
        ui->c_room->clear();                                    //确认没有用户名重名，清空输入栏
        this->close();
    }
    else  {                                                     //弹出警告
        QMessageBox mess(QMessageBox::Information,tr("username"),tr("用户名已经被注册或用户名不符合规范！"));
        QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
        free(newuser);
        mess.exec();
    }
}



void create_w::on_cancel_clicked()
{
    this->close();                                              //关闭窗口
}

