#ifndef DEVICEDATA_IO_H
#define DEVICEDATA_IO_H

#include "mybase.h"
#include "QLabel"

namespace Ui {
class DeviceData_IO;
}

class DeviceData_IO : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_IO(QWidget *parent = 0);
    ~DeviceData_IO();
    void updatePage();

private:
    Ui::DeviceData_IO *ui;
    void SetLabelState(QLabel* lbl,bool state,int type);
};

#endif // DEVICEDATA_IO_H
