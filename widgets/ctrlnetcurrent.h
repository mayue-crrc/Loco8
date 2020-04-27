#ifndef CTRLNETCURRENT_H
#define CTRLNETCURRENT_H

#include <QWidget>

namespace Ui {
class CtrlNetCurrent;
}

class CtrlNetCurrent : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlNetCurrent(QWidget *parent = 0);
    ~CtrlNetCurrent();
    void setCtrlValueRect(int value);

private:
    Ui::CtrlNetCurrent *ui;
};

#endif // CTRLNETCURRENT_H
