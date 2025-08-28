#include "rootc.h"
#include "ui_rootc.h"
#include "main.h"
#include "qtablewidget.h"
#include "QMessageBox"
#include "string.h"

extern nm users[200];                                                           //全局变量，用户结构体数组
extern int number;


rootc::rootc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rootc)
{
    ui->setupUi(this);
    number = readall(users);
    money();                                                                    //计算用户应缴物业费
    save(users);
    QString str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11;
    for(int i = 0; i <= number ;i++)//行
    {
        int rowIndex = ui->table_rootc->rowCount();
        str0 = QString::fromUtf8(users[i].username);
        str1 = QString::fromUtf8(users[i].key);
        str2 = QString::fromUtf8(users[i].name);
        str3 = QString::fromUtf8(users[i].sex);
        str4 = QString::fromUtf8(users[i].phone);
        str5 = QString::number(users[i].building);
        str6 = QString::number(users[i].unit);
        str7 = QString::number(users[i].room);
        str8 = QString::number(users[i].we_charge);
        str9 = QString::number(users[i].t_charge);
        str10 = QString::number(users[i].owemoney);
        str11 = QString::fromUtf8(users[i].other);
        ui->table_rootc ->setItem(i, 0,new QTableWidgetItem(str0));
        ui->table_rootc ->setItem(i, 1,new QTableWidgetItem(str1));
        ui->table_rootc ->setItem(i, 2,new QTableWidgetItem(str2));
        ui->table_rootc ->setItem(i, 3,new QTableWidgetItem(str3));
        ui->table_rootc ->setItem(i, 4,new QTableWidgetItem(str4));
        ui->table_rootc ->setItem(i, 5,new QTableWidgetItem(str5));
        ui->table_rootc ->setItem(i, 6,new QTableWidgetItem(str6));
        ui->table_rootc ->setItem(i, 7,new QTableWidgetItem(str7));
        ui->table_rootc ->setItem(i, 8,new QTableWidgetItem(str8));
        ui->table_rootc ->setItem(i, 9,new QTableWidgetItem(str9));
        ui->table_rootc ->setItem(i, 10,new QTableWidgetItem(str10));
        ui->table_rootc ->setItem(i, 11,new QTableWidgetItem(str11));           //在打开窗口前预加载表格中的数据
   }
}

rootc::~rootc()
{
    delete ui;
}


void rootc::on_searchButton_clicked()                                           //查找功能
{
    nm searchuser;
    char*  search_str;
    QByteArray search_qba = ui->search->text().toUtf8();                        //转换查找栏中的数据
    search_str=search_qba.data();
    number = readall(users);
    searchuser = search(search_str);                                            //调用查找函数
    if (searchuser.username[1]==0) {                                            //没有结果跳出弹窗
        QMessageBox mess(QMessageBox::Information,tr("search"),tr("没有结果"));
        QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
        mess.exec();
    }

    QString str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11;
    str0 = QString::fromUtf8(searchuser.username);
    str1 = QString::fromUtf8(searchuser.key);
    str2 = QString::fromUtf8(searchuser.name);
    str3 = QString::fromUtf8(searchuser.sex);
    str4 = QString::fromUtf8(searchuser.phone);
    str5 = QString::number(searchuser.building);
    str6 = QString::number(searchuser.unit);
    str7 = QString::number(searchuser.room);
    str8 = QString::number(searchuser.we_charge);
    str9 = QString::number(searchuser.t_charge);
    str10 = QString::number(searchuser.owemoney);
    str11 = QString(searchuser.other);
    ui->table_search ->setItem(0, 0,new QTableWidgetItem(str0));
    ui->table_search ->setItem(0, 1,new QTableWidgetItem(str1));
    ui->table_search ->setItem(0, 2,new QTableWidgetItem(str2));
    ui->table_search ->setItem(0, 3,new QTableWidgetItem(searchuser.sex));
    ui->table_search ->setItem(0, 4,new QTableWidgetItem(str4));
    ui->table_search ->setItem(0, 5,new QTableWidgetItem(str5));
    ui->table_search ->setItem(0, 6,new QTableWidgetItem(str6));
    ui->table_search ->setItem(0, 7,new QTableWidgetItem(str7));
    ui->table_search ->setItem(0, 8,new QTableWidgetItem(str8));
    ui->table_search ->setItem(0, 9,new QTableWidgetItem(str9));
    ui->table_search ->setItem(0, 10,new QTableWidgetItem(str10));                  //在查询结果中显示
    ui->table_search ->setItem(0, 11,new QTableWidgetItem(str11));
    ui->search->clear();
}

void rootc::on_pushButton_clicked()                                                 //刷新功能
{
    number = readall(users);
    money();
    save(users);
    QString str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11;
    ui->table_rootc ->clearContents();                                              //清除表格
    for(int i = 0; i <= (number) ;i++)//行
    {

        str0 = QString::fromUtf8(users[i].username);
        str1 = QString::fromUtf8(users[i].key);
        str2 = QString::fromUtf8(users[i].name);
        str3 = QString::fromUtf8(users[i].sex);
        str4 = QString::fromUtf8(users[i].phone);
        str5 = QString::number(users[i].building);
        str6 = QString::number(users[i].unit);
        str7 = QString::number(users[i].room);
        str8 = QString::number(users[i].we_charge);
        str9 = QString::number(users[i].t_charge);
        str10 = QString::number(users[i].owemoney);
        str11 = QString(users[i].other);
        ui->table_rootc ->setItem(i, 0,new QTableWidgetItem(str0));
        ui->table_rootc ->setItem(i, 1,new QTableWidgetItem(str1));
        ui->table_rootc ->setItem(i, 2,new QTableWidgetItem(str2));
        ui->table_rootc ->setItem(i, 3,new QTableWidgetItem(str3));
        ui->table_rootc ->setItem(i, 4,new QTableWidgetItem(str4));
        ui->table_rootc ->setItem(i, 5,new QTableWidgetItem(QString::number(users[i].building)));
        ui->table_rootc ->setItem(i, 6,new QTableWidgetItem(QString::number(users[i].unit)));
        ui->table_rootc ->setItem(i, 7,new QTableWidgetItem(QString::number(users[i].room)));
        ui->table_rootc ->setItem(i, 8,new QTableWidgetItem(QString::number(users[i].we_charge)));
        ui->table_rootc ->setItem(i, 9,new QTableWidgetItem(QString::number(users[i].t_charge)));
        ui->table_rootc ->setItem(i, 10,new QTableWidgetItem(QString::number(users[i].owemoney)));
        ui->table_rootc ->setItem(i, 11,new QTableWidgetItem(str11));               //重新写入表格
   }
}


void rootc::on_saveButton_clicked()                                                 //保存功能
{
    int building_i, unit_i, room_i,i=0,we_charge_i,t_charge_i,owemoney_i;
    char  * key_str=NULL,*username_str = NULL,* sex_str=NULL,* name_str=NULL ,*phone_str=NULL,*other_str=NULL;
    number = readall(users);
    while(i<=number){
        QByteArray username_qba = ui->table_rootc->item(i,0)->text().toUtf8();
        username_str = username_qba.data();
        QByteArray key_qba = ui->table_rootc->item(i,1)->text().toUtf8();
        key_str=key_qba.data();
        QByteArray name_qba = ui->table_rootc->item(i,2)->text().toUtf8();
        name_str=name_qba.data();
        QByteArray sex_qbr = ui->table_rootc->item(i,3)->text().toUtf8();
        sex_str = sex_qbr.data();
        QByteArray phone_qbr = ui->table_rootc->item(i,4)->text().toUtf8();
        phone_str = phone_qbr.data();
        building_i = ui->table_rootc->item(i,5)->text().toInt();
        unit_i = ui->table_rootc->item(i,6)->text().toInt();
        room_i = ui->table_rootc->item(i,7)->text().toInt();                        //转换数据
        we_charge_i = ui->table_rootc->item(i,8)->text().toInt();
        t_charge_i = ui->table_rootc->item(i,9)->text().toInt();
        owemoney_i = ui->table_rootc->item(i,10)->text().toInt();
        QByteArray other_qbr = ui->table_rootc->item(i,11)->text().toUtf8();
        other_str = other_qbr.data();

        strcpy(users[i].username,username_str);
        strcpy(users[i].key,key_str);
        strcpy(users[i].sex,sex_str);
        strcpy(users[i].name,name_str);
        strcpy(users[i].phone,phone_str);
        strcpy(users[i].other,other_str);
        users[i].building = building_i;
        users[i].unit = unit_i;
        users[i].room = room_i;
        users[i].we_charge = we_charge_i;
        users[i].t_charge = t_charge_i;
        users[i].owemoney = owemoney_i;
        i++;
    }
    save(users);                                                                    //调用保存函数
}


void rootc::on_add_clicked()
{
    create_widget->show();                                                          //打开新增窗口
}


void rootc::on_deleteButton_clicked()                                               //删除功能
{
    int i = 0;
    number = readall(users);
    nm searchuser;
    char*  search_str;
    QByteArray search_qba = ui->search->text().toUtf8();
    search_str=search_qba.data();

    searchuser = search(search_str);                                                //调用查找函数，查找所要删除的结构体
    if (searchuser.price==0) {
        QMessageBox mess(QMessageBox::Information,tr("search"),tr("没有结果"));
        QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
        mess.exec();
        return;
    }
    for(;i<=number;i++){
        if (!strcmp(searchuser.username,users[i].username)){                        //向前赋值，查找结构体
            break;
        }
    }
    for(;i<=number;i++){
        users[i]=users[i+1];
    }
    number--;
    users[i]={0};
    save(users);
    QMessageBox mess(QMessageBox::Information,tr("delete"),tr("删除成功"));
    QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));     //跳出成功弹窗
    mess.exec();
}


void rootc::on_sort_clicked()                                                        //排序统计功能
{
    char* type=NULL;
    char compare1[20]="应缴物业费",compare2[20]="按月统计" ,compare3[40]="按楼号统计未缴费";
    char print1[30]="一号楼需缴",print2[30],print3[30]="二号楼需缴",print4[30]="三号楼需缴",print5[30]="本月应缴";
    number = readall(users);
    nm* temp=NULL;
    unsigned long int b1=0,b2=0,b3=0,b4=0,total=0,current=0;

    QByteArray type_qbr = ui->type->currentText().toUtf8();
    type = type_qbr.data();
    if(!strcmp(type,compare1)){
        temp = rankmoney(users);                                                    //调用冒泡排序
        for(int i = 0; i <= number ;i++)                                            //按应缴物业费排序
        {
            QString str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11;
            int rowIndex = ui->table_rootc->rowCount();
            str0 = QString::fromUtf8(temp[i].username);
            str1 = QString::fromUtf8(temp[i].key);
            str2 = QString::fromUtf8(temp[i].name);
            str3 = QString::fromUtf8(temp[i].sex);
            str4 = QString::fromUtf8(temp[i].phone);
            str5 = QString::number(temp[i].building);
            str6 = QString::number(temp[i].unit);
            str7 = QString::number(temp[i].room);
            str8 = QString::number(temp[i].we_charge);
            str9 = QString::number(temp[i].t_charge);
            str10 = QString::number(temp[i].owemoney);
            str11 = QString::fromUtf8(temp[i].other);
            ui->table_rootc ->setItem(i, 0,new QTableWidgetItem(str0));
            ui->table_rootc ->setItem(i, 1,new QTableWidgetItem(str1));
            ui->table_rootc ->setItem(i, 2,new QTableWidgetItem(str2));
            ui->table_rootc ->setItem(i, 3,new QTableWidgetItem(str3));
            ui->table_rootc ->setItem(i, 4,new QTableWidgetItem(str4));
            ui->table_rootc ->setItem(i, 5,new QTableWidgetItem(str5));
            ui->table_rootc ->setItem(i, 6,new QTableWidgetItem(str6));
            ui->table_rootc ->setItem(i, 7,new QTableWidgetItem(str7));
            ui->table_rootc ->setItem(i, 8,new QTableWidgetItem(str8));
            ui->table_rootc ->setItem(i, 9,new QTableWidgetItem(str9));
            ui->table_rootc ->setItem(i, 10,new QTableWidgetItem(str10));
            ui->table_rootc ->setItem(i, 11,new QTableWidgetItem(str11));
       }
    }                                                                               //在表格中显示出来
    else if (!strcmp(type,compare3)){                                               //按楼号统计未缴费
        temp = rankbuilding(users);                                                 //按楼号冒泡排序
        for(int i = 0; i <= number ;i++)//行
        {
            if(users[i].owemoney<=0)continue;
            switch(users[i].building){
                case 1:b1+=users[i].t_charge;
                       break;
                case 2:b2+=users[i].t_charge;
                       break;
                case 3:b3+=users[i].t_charge;
                       break;
                default:b4+=users[i].t_charge;
                       break;
            }
            QString str0,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10,str11;
            int rowIndex = ui->table_rootc->rowCount();
            str0 = QString::fromUtf8(temp[i].username);
            str1 = QString::fromUtf8(temp[i].key);
            str2 = QString::fromUtf8(temp[i].name);
            str3 = QString::fromUtf8(temp[i].sex);
            str4 = QString::fromUtf8(temp[i].phone);
            str5 = QString::number(temp[i].building);
            str6 = QString::number(temp[i].unit);
            str7 = QString::number(temp[i].room);
            str8 = QString::number(temp[i].we_charge);
            str9 = QString::number(temp[i].t_charge);
            str10 = QString::number(temp[i].owemoney);
            str11 = QString::fromUtf8(temp[i].other);
            ui->table_rootc ->setItem(i, 0,new QTableWidgetItem(str0));
            ui->table_rootc ->setItem(i, 1,new QTableWidgetItem(str1));
            ui->table_rootc ->setItem(i, 2,new QTableWidgetItem(str2));
            ui->table_rootc ->setItem(i, 3,new QTableWidgetItem(str3));
            ui->table_rootc ->setItem(i, 4,new QTableWidgetItem(str4));
            ui->table_rootc ->setItem(i, 5,new QTableWidgetItem(str5));
            ui->table_rootc ->setItem(i, 6,new QTableWidgetItem(str6));
            ui->table_rootc ->setItem(i, 7,new QTableWidgetItem(str7));
            ui->table_rootc ->setItem(i, 8,new QTableWidgetItem(str8));
            ui->table_rootc ->setItem(i, 9,new QTableWidgetItem(str9));
            ui->table_rootc ->setItem(i, 10,new QTableWidgetItem(str10));
            ui->table_rootc ->setItem(i, 11,new QTableWidgetItem(str11));
       }                                                                            //在表格中显示
        sprintf_s(print2,20,"%d",b1);
        strcat(print1,print2);
        strcat(print1,"元，");
        strcat(print1,print3);
        sprintf_s(print2,20,"%d",b2);
        strcat(print1,print2);
        strcat(print1,"元，");
        strcat(print1,print4);
        sprintf_s(print2,20,"%d",b3);
        strcat(print1,print2);
        strcat(print1,"元。");
        QMessageBox mess(QMessageBox::Information,tr("按楼号统计"),tr(print1));      //跳出统计弹窗
        QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
        mess.exec();
    }
    else if (!strcmp(type,compare2)){                                               //按月统计未缴费
        for(int i = 0; i <= number ;i++)//行
        {
            if(users[i].owemoney<=0){
                if(users[i].owemoney<=-6&&users[i].owemoney>-12){
                    total += (-1)*users[i].area*users[i].price*0.97;
                    current += (-1)*users[i].area*users[i].price*0.97;
                }
                if(users[i].owemoney<=-12){
                    total += (-1)*users[i].area*users[i].price*0.9;
                    current += (-1)*users[i].area*users[i].price*0.9;
                }
                if(users[i].owemoney>-6) {
                    total += (-1)*users[i].area*users[i].price;
                    current += (-1)*users[i].area*users[i].price;
                }
            }
            else{
                total += users[i].t_charge;
            }
       }                                                                            //根据折扣额度不同，统计缴费情况
        sprintf_s(print2,20,"%d",total);
        strcat(print5,print2);
        strcat(print5,"元，实缴");
        sprintf_s(print2,20,"%d",current);
        strcat(print5,"元。");
        QMessageBox mess(QMessageBox::Information,tr("统计"),tr(print5));            //跳出统计弹窗
        QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
        mess.exec();
    }
}


