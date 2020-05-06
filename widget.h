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
class DeviceData_TrainOutline;

class Main_Simulate;
class Main_Lubrication;
class Main_AssistantDevice;
class Main_380;
class Main_Separation;
class Main_DoublePanto;


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
    DeviceData_TrainOutline* mainData_DriverOutline;

    Main_Simulate* main_Simulate;
    Main_Lubrication* main_Lubrication;
    Main_AssistantDevice* main_AssistantDevice;
    Main_380* main_380;
    Main_Separation* main_Separation;
    Main_DoublePanto* main_DoublePanto;
};

#endif // WIDGET_H
