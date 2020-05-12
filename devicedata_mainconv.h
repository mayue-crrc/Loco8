#ifndef DEVICEDATA_MAINCONV_H
#define DEVICEDATA_MAINCONV_H

#include "mybase.h"
#include "QLabel"

namespace Ui {
class DeviceData_MainConv;
}

class DeviceData_MainConv : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_MainConv(QWidget *parent = 0);
    ~DeviceData_MainConv();
    void updatePage();

private:
    Ui::DeviceData_MainConv *ui;
    void setLabelState(QLabel* lbl,bool ok);
};

#endif // DEVICEDATA_MAINCONV_H
