#ifndef DEVICEDATA_TRACBRAKEOUTLINE_H
#define DEVICEDATA_TRACBRAKEOUTLINE_H

#include <mybase.h>
#include "qprogressbar.h"

namespace Ui {
class DeviceData_TracBrakeOutline;
}

class DeviceData_TracBrakeOutline : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_TracBrakeOutline(QWidget *parent = 0);
    ~DeviceData_TracBrakeOutline();
    void updatePage();

private:
    Ui::DeviceData_TracBrakeOutline *ui;
    QList<QProgressBar* >progbar_Act1,progbar_Act2,progbar_Set1,progbar_Set2,progbar_ActTotal1,progbar_ActTotal2,progbar_SetTotal1,progbar_SetTotal2;
    QList<unsigned char >value_Tmp;
    QList<int >value_Change1,value_Change2,value_Tatol;
    QList<QLabel* >labels;
    void setLabelTextValue(QList<QLabel* >label,QList<int >value);
    void getUICValue(int &uic1,int &uic2);
    void calcActAxleValue(QList<unsigned char >tmp,QList<int >&value);
    void calcSetAxleValue(QList<unsigned char >tmp,QList<int >&value);
    void calcTotalAxleValue(QList<int >tmp,QList<int >&value);
    void SetProgbarValue(QList<QProgressBar* >bar1,QList<QProgressBar* >bar2,QList<int >value);
};

#endif // DEVICEDATA_TRACBRAKEOUTLINE_H
