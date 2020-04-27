#ifndef VEHICLERUNSTATEPAGE_H
#define VEHICLERUNSTATEPAGE_H

#include <QWidget>
#include "mybase.h"

#include "widgets/ctrlnetvoltage.h"
#include "widgets/ctrlnetcurrent.h"
#include "widgets/ctrlcontrolvoltage.h"
#include "widgets/ctrltracbrake.h"
namespace Ui {
    class VehicleRunStatePage;
}

class VehicleRunStatePage : public MyBase
{
    Q_OBJECT

public:
    explicit VehicleRunStatePage(QWidget *parent = 0);
    ~VehicleRunStatePage();

    void updatePage();
    void showEvent(QShowEvent *);

private slots:


    void on_BTNSpeedplus_clicked();

    void on_BTNSpeedminus_clicked();

private:
    Ui::VehicleRunStatePage *ui;
    CtrlNetVoltage* ctrlNetVoltage;
    CtrlNetCurrent* ctrlNetCurrent;
    CtrlControlVoltage* ctrlControlVoltage;
    CtrlTracBrake* ctrlTracBrake;
};

#endif // VEHICLERUNSTATEPAGE_H
