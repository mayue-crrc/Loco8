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

class DeviceData_Online;

class MainData_TrainOutline;
class Settng_Bypass;

class DataInputWheelPage;
class DataInputDateTimePage;
class DataInputOther;
class DataInputCalibratePage;
class DataInputLubricatePage;
class DataInputSplitLinePage;

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

    DeviceData_Online* deviceData_Online;

    MainData_TrainOutline* mainData_TrainOutline;
    Settng_Bypass* settng_Bypass;

    DataInputWheelPage* dataInputWheelPage;
    DataInputDateTimePage* dataInputDateTimePage;
    DataInputOther* dataInputOther;
    DataInputLubricatePage* dataInputLubricatePage;
    DataInputCalibratePage* dataInputCalibratePage;
    DataInputSplitLinePage* dataInputSplitLinePage;
};

#endif // WIDGET_H
