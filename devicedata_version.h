#ifndef DEVICEDATA_VERSION_H
#define DEVICEDATA_VERSION_H

#include "mybase.h"

namespace Ui {
class DeviceData_Version;
}

class DeviceData_Version : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_Version(QWidget *parent = 0);
    ~DeviceData_Version();

private:
    Ui::DeviceData_Version *ui;
};

#endif // DEVICEDATA_VERSION_H
