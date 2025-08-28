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
    if (strlen(newuser->username)<3) return -1;                             //�ж��û����Ƿ����

    while (strlen(users[i].username)>=3) {
        if (strcmp(newuser->username, users[i].username) == 0)return 0;     //�ж��Ƿ�����
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
    fclose(fpc);                                                            //д���ļ�
    return 1;
}

int log(nm* log) {
    int i = 0;
    char temp1[10]="root",temp2[10]="qwerty";                               //����Ա�˺�ʶ��
    if(!strcmp(log->username, temp1)) {
        if(!strcmp(log->key, temp2))return -1;
    }
    while (users[i].username[1]) {
        if (strcmp(log->username, users[i].username) == 0)break;            //�û��˺�ʶ��
        i++;
    }
    if (strcmp(log->key, users[i].key) == 0) {  return 1; }                 //�����Ƿ���ȷ
    else  return 0;
}

int readall(nm* user) {
    FILE* fpr;
    int i = 0;
    fpr = fopen(PATH, "rb");
    if (feof(fpr)) return -1;                                               //�ļ��Ƿ�������
    while (i<200) {
        fread(user[i].username, sizeof(char), 21, fpr);                     //���ļ���ȡ�û���Ϣ
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
        fwrite(user[i].username, sizeof(user[i].username), 1, fpc);         //�����û���Ϣ��д���ļ�
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

    nm tt = { 0 };                                                          //��ʱ���� ���������û�����Ϣ
    int i = 0, test, j;
    test = number;
    if (!test) return 0;
                                                                            //��t_charge�Ĵ�С����ð������
    for (i = 0; i <= test; i++)
        for (j = 0; j <= test - i; j++)
        {
            if (people[j].t_charge < people[j + 1].t_charge)
            {
                tt = people[j];                                             //����
                people[j] = people[j + 1];
                people[j + 1] = tt;
            }
            }
                                                                            //�������
    return people;
}

nm* rankbuilding(nm* people)
{

    nm tt = { 0 };                                                          //��ʱ���� ���������û�����Ϣ
    int i = 0, test, j;
    test = number;
    if (!test) return 0;
                                                                            //��building�Ĵ�С����ð������
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
                                                                            //�������
    return people;
}

nm* money(){                                                                //������ҵ��
    int i = 0 , j = 0 ,tempm = 0 , oweday = 0;
    int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (info->tm_year/4==0){
        md[1]=29;
    }
    while(i<=number){
        switch (users[i].building) {                                        //����¥���ж�ס���������ҵ����
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
    if (users[i].owemoney-1>0){                                             //�ж��Ƿ��ǿ���Ƿ��
        if (info->tm_mon - users[i].owemoney+1<=0) {
            tempm = info->tm_mon - users[i].owemoney+1 + 12;
            for(j=1; j<info->tm_mon ; j++) oweday += md[i-1];
            for(j=tempm; j<=12 ; j++) oweday += md[i-1];                    //�������Ʒ�
            oweday += info->tm_mon;
        }
        else {
            for(j=info->tm_mon - users[i].owemoney+1; j<info->tm_mon ; j++) oweday += md[i-1];
            oweday += info->tm_mon;                                         //����δ����Ƿ���û�Ƿ�ѽ��
        }
        users[i].t_charge = pow(oweday, 1.01)*(users[i].area*users[i].price+users[i].we_charge);
    }
    else if(users[i].owemoney==1){                                          //���㵱��δ�ɷ��û�
        users[i].t_charge = users[i].area*users[i].price+users[i].we_charge;
    }
    else  users[i].t_charge = 0;                                            //��ǰ�ɷ��û�Ƿ������
    oweday = 0;
    tempm = 0;
    i++;
    }
    return users;
}

nm search(char* search){                                                    //��ѯ�û������ؽṹ��
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

int search_i(char* search){                                                 //��ѯ�û����������ڴ��еı��
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
