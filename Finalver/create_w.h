#ifndef CREATE_W_H
#define CREATE_W_H

#include <QWidget>

namespace Ui {
class create_w;
}

class create_w : public QWidget
{
    Q_OBJECT

public:
    explicit create_w(QWidget *parent = nullptr);
    ~create_w();

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

private:
    Ui::create_w *ui;
};

#endif // CREATE_W_H
