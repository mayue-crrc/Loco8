#ifndef DEVICEDATA_VERSION_H
#define DEVICEDATA_VERSION_H

#include "mybase.h"
#include "QLabel"

namespace Ui {
class DeviceData_Version;
}

class DeviceData_Version : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_Version(QWidget *parent = 0);
    ~DeviceData_Version();
    void updatePage();

private:
    Ui::DeviceData_Version *ui;
    QList<QLabel*> Device,VerX,VerY,VerZ;
    QList<QString> NameList;
};

#endif // DEVICEDATA_VERSION_H
