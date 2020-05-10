#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QWidget>
#include <QMap>
#include "log4qt/logger.h"
#include "global.h"
#include "widgets/ctrldialog.h"
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
class Fault_HIstory;
class DeviceData_TrainOutline;
class DeviceData_TracBrakeOutline;
class Main_Allportdata;

class Main_Simulate;
class Main_Lubrication;
class Main_AssistantDevice;
class Main_380;
class Main_Separation;
class Main_DoublePanto;
class Fault_Current;
class Fault_Detail;

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
    DeviceData_TrainOutline* deviceData_TrainOutline;
    DeviceData_TracBrakeOutline* deviceData_TracBrakeOutline;
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

    Fault_HIstory* fault_History;
    Main_Allportdata* main_Allportdata;
    Main_Simulate* main_Simulate;
    Main_Lubrication* main_Lubrication;
    Main_AssistantDevice* main_AssistantDevice;
    Main_380* main_380;
    Main_Separation* main_Separation;
    Main_DoublePanto* main_DoublePanto;

    CtrlDialog* ctrlDialog;
    Fault_Current* fault_Current;
    Fault_Detail* fault_Detail;
};

#endif // WIDGET_H
