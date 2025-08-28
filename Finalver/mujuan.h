#ifndef MUJUAN_H
#define MUJUAN_H

#include <QWidget>

namespace Ui {
class mujuan;
}

class mujuan : public QWidget
{
    Q_OBJECT

public:
    explicit mujuan(QWidget *parent = nullptr);
    ~mujuan();

private:
    Ui::mujuan *ui;
};

#endif // MUJUAN_H
