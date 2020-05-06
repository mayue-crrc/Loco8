#ifndef DEVICEDATA_ONLINE_H
#define DEVICEDATA_ONLINE_H

#include "mybase.h"
#include "QLabel"

namespace Ui {
class DeviceData_Online;
}

class DeviceData_Online : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_Online(QWidget *parent = 0);
    ~DeviceData_Online();
    void updatePage();

private:
    Ui::DeviceData_Online *ui;
    void setLabelState(QLabel* lbl,bool online);
    void setLabelState(QLabel* lbl,bool online,bool Master);
};

#endif // DEVICEDATA_ONLINE_H
