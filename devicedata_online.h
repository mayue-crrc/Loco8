#ifndef DEVICEDATA_ONLINE_H
#define DEVICEDATA_ONLINE_H

#include "mybase.h"

namespace Ui {
class DeviceData_Online;
}

class DeviceData_Online : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_Online(QWidget *parent = 0);
    ~DeviceData_Online();

private:
    Ui::DeviceData_Online *ui;
};

#endif // DEVICEDATA_ONLINE_H
