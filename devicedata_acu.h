#ifndef DEVICEDATA_ACU_H
#define DEVICEDATA_ACU_H

#include "mybase.h"
#include "QPushButton"
#include "QLabel"

namespace Ui {
class DeviceData_ACU;
}

class DeviceData_ACU : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_ACU(QWidget *parent = 0);
    ~DeviceData_ACU();
    void updatePage();

private slots:
    void SelectTrainEvent();

private:
    Ui::DeviceData_ACU *ui;
    void hideAll();
    QList<QPushButton*> TrainSelect;
    QList<QLabel*> SWList,HBList;
    QList<bool> SWState[4],HBState[4];
    int TrainIndex;
    void setSWstate(QLabel* lbl,bool ok);
    void setSWstate(QList<QLabel*> lblList,QList<bool> stateList);
    void setHBstate(QLabel* lbl,bool close);
    void setHBstate(QList<QLabel*> lblList,QList<bool> stateList);
};

#endif // DEVICEDATA_ACU_H
