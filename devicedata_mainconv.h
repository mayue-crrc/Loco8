#ifndef DEVICEDATA_MAINCONV_H
#define DEVICEDATA_MAINCONV_H

#include "mybase.h"

namespace Ui {
class DeviceData_MainConv;
}

class DeviceData_MainConv : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_MainConv(QWidget *parent = 0);
    ~DeviceData_MainConv();

private:
    Ui::DeviceData_MainConv *ui;
};

#endif // DEVICEDATA_MAINCONV_H
