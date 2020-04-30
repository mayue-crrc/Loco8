#ifndef SETTNG_TEST_H
#define SETTNG_TEST_H

#include "mybase.h"

namespace Ui {
class Settng_Test;
}

class Settng_Test : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Test(QWidget *parent = 0);
    ~Settng_Test();
    void timerEvent(QTimerEvent*);

private slots:
    void on_BTN_LightTest_pressed();

private:
    Ui::Settng_Test *ui;
    int testTimer;
};

#endif // SETTNG_TEST_H
