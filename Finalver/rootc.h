#ifndef ROOTC_H
#define ROOTC_H

#include <QWidget>
#include "create_w.h"
namespace Ui {
class rootc;
}

class rootc : public QWidget
{
    Q_OBJECT

public:
    explicit rootc(QWidget *parent = nullptr);
    ~rootc();
    create_w * create_widget = new create_w;

private slots:
    void on_searchButton_clicked();

    void on_pushButton_clicked();

    void on_saveButton_clicked();

    void on_add_clicked();

    void on_deleteButton_clicked();

    void on_sort_clicked();

private:
    Ui::rootc *ui;
};

#endif // ROOTC_H
