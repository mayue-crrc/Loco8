#ifndef DEVICEDATA_BREAKER_H
#define DEVICEDATA_BREAKER_H

#include "mybase.h"

namespace Ui {
class DeviceData_Breaker;
}

class DeviceData_Breaker : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_Breaker(QWidget *parent = 0);
    ~DeviceData_Breaker();

private:
    Ui::DeviceData_Breaker *ui;
};

#endif // DEVICEDATA_BREAKER_H
