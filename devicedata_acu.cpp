#include "devicedata_acu.h"
#include "ui_devicedata_acu.h"

DeviceData_ACU::DeviceData_ACU(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_ACU)
{
    ui->setupUi(this);
}

DeviceData_ACU::~DeviceData_ACU()
{
    delete ui;
}
