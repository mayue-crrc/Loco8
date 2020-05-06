#ifndef MAIN_SIMULATE_H
#define MAIN_SIMULATE_H
#include "mybase.h"

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

private:
    Ui::Main_Simulate *ui;
};

#endif // MAIN_SIMULATE_H
