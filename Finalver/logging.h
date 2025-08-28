#ifndef LOGGING_H
#define LOGGING_H

#include <QWidget>
#include "widget.h"
#include "create_w.h"
#include "rootc.h"

namespace Ui {
class Logging;
}

class Logging : public QWidget
{
    Q_OBJECT

public:
    explicit Logging(QWidget *parent = nullptr);
    ~Logging();

    Widget * w = new Widget;
    create_w * c = new create_w;
    rootc * r = new rootc;


private slots:
    void on_out_clicked();

    void on_log_clicked();

    void on_create_clicked();

private:
    Ui::Logging *ui;


};

#endif // LOGGING_H
