#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "personalinform.h"
#include "pay.h"
#include "mujuan.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    personalinform* p = new personalinform;
    pay* pa = new pay;
    mujuan *m = new mujuan;

private slots:


    void on_chargeinform_clicked();

    void on_personalinform_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
