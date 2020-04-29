#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QWidget>
#include <QMap>
#include "log4qt/logger.h"
#include "global.h"

namespace Ui {
    class Widget;
}
class MyBase;
class Header;
class QTimer;
class Database;
class Navigator;
class VehicleRunStatePage;
class CrrcMvb;
class CrrcFault;
class Simulation;

class DeviceData_Version;
class DeviceData_Breaker;
class DeviceData_ACU;
class DeviceData_Online;
class DeviceData_MainConv;
class DeviceData_IO;

class MainData_TrainOutline;
class Settng_Bypass;
class Settng_Test;
class Settng_Panto;
class Settng_Distance;
class DataInputWheelPage;
class DataInputDateTimePage;
class DataInputOther;
class DataInputCalibratePage;
class DataInputLubricatePage;
class DataInputSplitLinePage;

class DeviceData_TrainOutline;
class Widget : public QWidget
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER

public:
    explicit Widget(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *);
    QMap<int, MyBase *> widgets;

    ~Widget();

public slots:
    void changePage(int page);
    void updatePage();
    void translateLanguage();

private:
    Ui::Widget *ui;
    QTimer* timer;
    Database* database;
    Navigator* navigator;
    VehicleRunStatePage* vehicleRunStatePage;
    Header *header;
    CrrcMvb* crrcMvb;
    CrrcFault* crrcFault;
    Simulation* simulation;

    DeviceData_Breaker* deviceData_Breaker;
    DeviceData_ACU* deviceData_ACU;
    DeviceData_Version* deviceData_Version;
    DeviceData_Online* deviceData_Online;
    DeviceData_MainConv* deviceData_MainConv;
    DeviceData_IO* deviceData_IO;
    MainData_TrainOutline* mainData_TrainOutline;
    Settng_Bypass* settng_Bypass;
    Settng_Test* settng_Test;
    Settng_Panto* settng_Panto;
    Settng_Distance* settng_Distance;

    DataInputWheelPage* dataInputWheelPage;
    DataInputDateTimePage* dataInputDateTimePage;
    DataInputOther* dataInputOther;
    DataInputLubricatePage* dataInputLubricatePage;
    DataInputCalibratePage* dataInputCalibratePage;
    DataInputSplitLinePage* dataInputSplitLinePage;
    DeviceData_TrainOutline* mainData_DriverOutline;
};

#endif // WIDGET_H
