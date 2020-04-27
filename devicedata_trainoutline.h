#ifndef MAINDATA_DRIVEROUTLINE_H
#define MAINDATA_DRIVEROUTLINE_H

#include <mybase.h>
#include "qpushbutton.h"
#include "qlabel.h"

namespace Ui {
class DeviceData_TrainOutline;
}

class DeviceData_TrainOutline : public MyBase
{
    Q_OBJECT

public:
    explicit DeviceData_TrainOutline(QWidget *parent = 0);
    ~DeviceData_TrainOutline();
    void updatePage();

private:
    Ui::DeviceData_TrainOutline *ui;
    QList<QPushButton* > buttons;
    QList<QLabel* > labels;
    int currentIndex;

    void NBreleaseEvent();
private slots:
    void NBpressEvent();


};

#endif // MAINDATA_DRIVEROUTLINE_H
