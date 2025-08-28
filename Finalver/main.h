#ifndef MAIN_H
#define MAIN_H

#endif // MAIN_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct normal {
char username[21];      //用户名
char key[20];           //密码
char name[20];          //姓名
char sex[10];           //性别
char phone[20];         //电话
int building;           //楼号
int unit;               //单元
int room;               //房间
int area;               //面积
int price;              //物业单价
int we_charge;          //公摊水电费
int t_charge;           //总物业费
int owemoney;           //欠费月数
char other[50];         //备注
}nm;

#define PATH "D:\\test.bin"

int create_n(nm* newuser);
int log(nm* log);
int save(nm* user);
int readall(nm* user);
nm* rankmoney(nm* people);
nm* rankbuilding(nm* people);
nm* money();
nm search(char* search);
int search_i(char* search);

