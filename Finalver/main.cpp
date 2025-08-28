#include "widget.h"
#include "logging.h"
#include <QApplication>
#include "main.h"
struct tm *info;


nm users[200];
int number;
int main(int argc, char *argv[])
{
    time_t now;
    now = time(NULL);
    info = localtime(&now);                         //调用系统时间
    QApplication a(argc, argv);

    money();
    //Widget w;
    Logging v;

    v.show();                                       //登录界面
    //w.show();
    return a.exec();
}
