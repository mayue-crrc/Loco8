#ifndef FAULT_CURRENT_H
#define FAULT_CURRENT_H

#include <mybase.h>

namespace Ui {
class Fault_Current;
}

class Fault_Current : public MyBase
{
    Q_OBJECT

public:
    explicit Fault_Current(QWidget *parent = 0);
    ~Fault_Current();

private:
    Ui::Fault_Current *ui;
};

#endif // FAULT_CURRENT_H
