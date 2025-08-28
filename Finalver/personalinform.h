#ifndef PERSONALINFORM_H
#define PERSONALINFORM_H

#include <QWidget>

namespace Ui {
class personalinform;
}

class personalinform : public QWidget
{
    Q_OBJECT

public:
    explicit personalinform(QWidget *parent = nullptr);
    ~personalinform();

private slots:
    void on_fresh_clicked();

    void on_save_clicked();

    void on_quit_clicked();

private:
    Ui::personalinform *ui;
};

#endif // PERSONALINFORM_H
