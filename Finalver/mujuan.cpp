#include "mujuan.h"
#include "ui_mujuan.h"

mujuan::mujuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mujuan)
{
    ui->setupUi(this);
}

mujuan::~mujuan()
{
    delete ui;
}
