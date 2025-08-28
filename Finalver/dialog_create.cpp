#include "dialog_create.h"
#include "ui_dialog_create.h"

Dialog_create::Dialog_create(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_create)
{
    ui->setupUi(this);
}

Dialog_create::~Dialog_create()
{
    delete ui;
}
