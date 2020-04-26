#include "devicedata_online.h"
#include "ui_devicedata_online.h"

DeviceData_Online::DeviceData_Online(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_Online)
{
    ui->setupUi(this);
}

DeviceData_Online::~DeviceData_Online()
{
    delete ui;
}
