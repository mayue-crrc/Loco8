#ifndef SETTNG_DISTANCE_H
#define SETTNG_DISTANCE_H

#include "mybase.h"

namespace Ui {
class Settng_Distance;
}

class Settng_Distance : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Distance(QWidget *parent = 0);
    ~Settng_Distance();
    void updatePage();
    void timerEvent(QTimerEvent*);

private slots:
    void on_BTN_Reset_pressed();

private:
    Ui::Settng_Distance *ui;
    int resetTimer;
};

#endif // SETTNG_DISTANCE_H
