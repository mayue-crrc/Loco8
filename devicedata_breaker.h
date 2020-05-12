#ifndef DEVICEDATA_BREAKER_H
#define DEVICEDATA_BREAKER_H

#include "mybase.h"
#include "QLabel"
#include "QPushButton"

namespace Ui {
class DeviceData_Breaker;
}

class DeviceData_Breaker : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_Breaker(QWidget *parent = 0);
    ~DeviceData_Breaker();
    void updatePage();

private slots:
    void SelectTrainEvent();

private:
    Ui::DeviceData_Breaker *ui;
    void hideAll();
    QList<QPushButton*> TrainSelect;
    QList<QLabel*> ACUList;
    QList<bool> ACUstate[4];
    int TrainIndex;
    void setaLabelstate(QList<QLabel*> lbl,QList<bool> state);
};

#endif // DEVICEDATA_BREAKER_H
