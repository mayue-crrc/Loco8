#ifndef CTRLTRACBRAKE_H
#define CTRLTRACBRAKE_H

#include <QWidget>
#include "global.h"
namespace Ui {
class CtrlTracBrake;
}

class CtrlTracBrake : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlTracBrake(QWidget *parent = 0);
    ~CtrlTracBrake();
    void setCtrlValueRect(int value,bool trac,bool brake);

private:
    Ui::CtrlTracBrake *ui;
};

#endif // CTRLTRACBRAKE_H
