#include "vehiclerunstatepage.h"
#include "ui_vehiclerunstatepage.h"

#define FAULTLEVEL1 "background-color:rgb(240,0,0);color:black;border:transparent;"
#define FAULTLEVEL2 "background-color:rgb(240,240,0);color:black;border:transparent;"
#define FAULTLEVEL3 "background-color:rgb(0,0,0);color:rgb(248,248,248);border:transparent;"

VehicleRunStatePage::VehicleRunStatePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::VehicleRunStatePage)
{
    ui->setupUi(this);
}

VehicleRunStatePage::~VehicleRunStatePage()
{
    delete ui;
}

void VehicleRunStatePage::updatePage()
{

}
void VehicleRunStatePage::showEvent(QShowEvent *)
{

}


