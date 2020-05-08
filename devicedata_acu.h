#ifndef DEVICEDATA_ACU_H
#define DEVICEDATA_ACU_H

#include "mybase.h"

namespace Ui {
class DeviceData_ACU;
}

class DeviceData_ACU : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_ACU(QWidget *parent = 0);
    ~DeviceData_ACU();

private:
    Ui::DeviceData_ACU *ui;
};

#endif // DEVICEDATA_ACU_H
