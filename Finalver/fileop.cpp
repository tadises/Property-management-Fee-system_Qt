#include "main.h"
extern nm users[200];
extern int number;
extern struct tm *info;

FILE* fpc;
FILE* fps;


int create_n(nm* newuser) {
    int i=0;
    number = readall(users);
    fpc = fopen(PATH, "ab+");
	if (fpc == NULL) return 0;
    if (strlen(newuser->username)<3) return -1;                             //判断用户名是否过短

    while (strlen(users[i].username)>=3) {
        if (strcmp(newuser->username, users[i].username) == 0)return 0;     //判断是否重名
        i++;
    }

    i=0;
    fwrite(newuser->username, sizeof(newuser->username),1, fpc);
    fwrite(newuser->key, sizeof(newuser->key), 1, fpc);
    fwrite(newuser->name, sizeof(newuser->name), 1, fpc);
    fwrite(newuser->sex, sizeof(newuser->sex), 1, fpc);
    fwrite(newuser->phone, sizeof(newuser->phone), 1, fpc);
    fwrite(&newuser->building, sizeof(int), 1, fpc);
    fwrite(&newuser->unit, sizeof(int), 1, fpc);
    fwrite(&newuser->room, sizeof(int), 1, fpc);
    fwrite(&newuser->area, sizeof(int), 1, fpc);
    fwrite(&newuser->price, sizeof(int), 1, fpc);
    fwrite(&newuser->we_charge, sizeof(int), 1, fpc);
    fwrite(&newuser->t_charge, sizeof(int), 1, fpc);
    fwrite(&newuser->owemoney, sizeof(int), 1, fpc);
    fwrite(newuser->other, sizeof(newuser->other), 1, fpc);
    fclose(fpc);                                                            //写入文件
    return 1;
}

int log(nm* log) {
    int i = 0;
    char temp1[10]="root",temp2[10]="qwerty";                               //管理员账号识别
    if(!strcmp(log->username, temp1)) {
        if(!strcmp(log->key, temp2))return -1;
    }
    while (users[i].username[1]) {
        if (strcmp(log->username, users[i].username) == 0)break;            //用户账号识别
        i++;
    }
    if (strcmp(log->key, users[i].key) == 0) {  return 1; }                 //密码是否正确
    else  return 0;
}

int readall(nm* user) {
    FILE* fpr;
    int i = 0;
    fpr = fopen(PATH, "rb");
    if (feof(fpr)) return -1;                                               //文件是否正常打开
    while (i<200) {
        fread(user[i].username, sizeof(char), 21, fpr);                     //从文件读取用户信息
        fread(user[i].key, sizeof(char), 20, fpr);
        fread(user[i].name, sizeof(char), 20, fpr);
        fread(user[i].sex, sizeof(user[i].sex), 1, fpr);
        fread(user[i].phone, sizeof(user->phone), 1, fpr);
        fread(&user[i].building, sizeof(int), 1, fpr);
        fread(&user[i].unit, sizeof(int), 1, fpr);
        fread(&user[i].room, sizeof(int), 1, fpr);
        fread(&user[i].area, sizeof(int), 1, fpr);
        fread(&user[i].price, sizeof(int), 1, fpr);
        fread(&user[i].we_charge, sizeof(int), 1, fpr);
        fread(&user[i].t_charge, sizeof(int), 1, fpr);
        fread(&user[i].owemoney, sizeof(int), 1, fpr);
        fread(user[i].other, sizeof(char), 50, fpr);
        if (feof(fpr)) {fclose(fpr);return i-1;}
        i++;
    }
    fclose(fpr);
    return 1;
}

int save(nm* user) {
    FILE* fpc;
    fpc = fopen(PATH, "wb+");
    int i = 0;
    while (i<=number) {
        fwrite(user[i].username, sizeof(user[i].username), 1, fpc);         //保存用户信息，写入文件
        fwrite(user[i].key, sizeof(user[i].key), 1, fpc);
        fwrite(user[i].name, sizeof(user[i].name), 1, fpc);
        fwrite(user[i].sex, sizeof(user[i].sex), 1, fpc);
        fwrite(user[i].phone, sizeof(user[i].phone), 1, fpc);
        fwrite(&user[i].building, sizeof(int), 1, fpc);
        fwrite(&user[i].unit, sizeof(int), 1, fpc);
        fwrite(&user[i].room, sizeof(int), 1, fpc);
        fwrite(&user[i].area, sizeof(int), 1, fpc);
        fwrite(&user[i].price, sizeof(int), 1, fpc);
        fwrite(&user[i].we_charge, sizeof(int), 1, fpc);
        fwrite(&user[i].t_charge, sizeof(int), 1, fpc);
        fwrite(&user[i].owemoney, sizeof(int), 1, fpc);
        fwrite(user[i].other, sizeof(user[i].other), 1, fpc);
        i++;
    }
    fclose(fpc);
    return 1;
}

nm* rankmoney(nm* people)
{

    nm tt = { 0 };                                                          //临时变量 交换整个用户的信息
    int i = 0, test, j;
    test = number;
    if (!test) return 0;
                                                                            //对t_charge的大小进行冒泡排序
    for (i = 0; i <= test; i++)
        for (j = 0; j <= test - i; j++)
        {
            if (people[j].t_charge < people[j + 1].t_charge)
            {
                tt = people[j];                                             //交换
                people[j] = people[j + 1];
                people[j + 1] = tt;
            }
            }
                                                                            //输出数组
    return people;
}

nm* rankbuilding(nm* people)
{

    nm tt = { 0 };                                                          //临时变量 交换整个用户的信息
    int i = 0, test, j;
    test = number;
    if (!test) return 0;
                                                                            //对building的大小进行冒泡排序
    for (i = 0; i <= test; i++)
        for (j = 0; j <= test - i; j++)
        {
            if (people[j].building < people[j + 1].building)
            {
                tt = people[j];
                people[j] = people[j + 1];
                people[j + 1] = tt;
            }
        }
                                                                            //输出数组
    return people;
}

nm* money(){                                                                //计算物业费
    int i = 0 , j = 0 ,tempm = 0 , oweday = 0;
    int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (info->tm_year/4==0){
        md[1]=29;
    }
    while(i<=number){
        switch (users[i].building) {                                        //根据楼号判断住房面积和物业单价
        case 1:
            users[i].area = 110;
            users[i].price = 2;
            break;
        case 2:
            users[i].area = 90;
            users[i].price = 2;
            break;
        case 3:
            users[i].area = 100;
            users[i].price = 3;
            break;
        default:
            users[i].area = 0;
            users[i].price = 0;
            users[i].t_charge = (users[i].area*users[i].price+users[i].we_charge)*users[i].owemoney;
            break;
        }
    if (users[i].owemoney-1>0){                                             //判断是否是跨年欠费
        if (info->tm_mon - users[i].owemoney+1<=0) {
            tempm = info->tm_mon - users[i].owemoney+1 + 12;
            for(j=1; j<info->tm_mon ; j++) oweday += md[i-1];
            for(j=tempm; j<=12 ; j++) oweday += md[i-1];                    //计算跨年计费
            oweday += info->tm_mon;
        }
        else {
            for(j=info->tm_mon - users[i].owemoney+1; j<info->tm_mon ; j++) oweday += md[i-1];
            oweday += info->tm_mon;                                         //计算未跨年欠费用户欠费金额
        }
        users[i].t_charge = pow(oweday, 1.01)*(users[i].area*users[i].price+users[i].we_charge);
    }
    else if(users[i].owemoney==1){                                          //计算当月未缴费用户
        users[i].t_charge = users[i].area*users[i].price+users[i].we_charge;
    }
    else  users[i].t_charge = 0;                                            //提前缴费用户欠费清零
    oweday = 0;
    tempm = 0;
    i++;
    }
    return users;
}

nm search(char* search){                                                    //查询用户，返回结构体
    int i = 0;
    nm nosearch={0};
    for(;i<=number;i++){
        if (!strcmp(search,users[i].username)){
            return users[i];
        }
        else if (!strcmp(search,users[i].name)){
            return users[i];
        }
    }
    return nosearch;
}

int search_i(char* search){                                                 //查询用户，返回在内存中的编号
    int i = 0;
    for(;i<=number;i++){
        if (!strcmp(search,users[i].username)){
            return i;
        }
        else if (!strcmp(search,users[i].name)){
            return i;
        }
    }
    return 201;
}
