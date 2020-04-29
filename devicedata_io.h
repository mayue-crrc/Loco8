#ifndef DEVICEDATA_IO_H
#define DEVICEDATA_IO_H

#include "mybase.h"

namespace Ui {
class DeviceData_IO;
}

class DeviceData_IO : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_IO(QWidget *parent = 0);
    ~DeviceData_IO();

private:
    Ui::DeviceData_IO *ui;
};

#endif // DEVICEDATA_IO_H
