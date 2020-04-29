#ifndef SETTNG_BYPASS_H
#define SETTNG_BYPASS_H

#include <mybase.h>

namespace Ui {
class Settng_Bypass;
}

class Settng_Bypass : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Bypass(QWidget *parent = 0);
    ~Settng_Bypass();

private:
    Ui::Settng_Bypass *ui;
};

#endif // SETTNG_BYPASS_H
