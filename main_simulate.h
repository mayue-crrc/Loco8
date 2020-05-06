#ifndef MAIN_SIMULATE_H
#define MAIN_SIMULATE_H
#include "mybase.h"
#include "qpushbutton.h"
#include "qtimer.h"
#include <QWidget>

namespace Ui {
class Main_Simulate;
}

class Main_Simulate : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Simulate(QWidget *parent = 0);
    ~Main_Simulate();
    QList<QPushButton *> buttons;
    QList<QPushButton *> funcButtons;
    static QString input1;
    static QString input2;
    int inputFlag;
    QTimer* qTimer;

    bool simulateFlag,testActiveFlag,sendFlag;


    enum funcNumber{
        simulate=11,
        testActive,
        speedInput,
        volInput,
        dataSend,
        isoSwitch,
        keySwitch
    };

private:
    Ui::Main_Simulate *ui;

private slots:
    void numberButtonPressEvent();
    void functionButtonPressEvent();

};

#endif // MAIN_SIMULATE_H
