#include "devicedata_version.h"
#include "ui_devicedata_version.h"

DeviceData_Version::DeviceData_Version(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_Version)
{
    ui->setupUi(this);
}

DeviceData_Version::~DeviceData_Version()
{
    delete ui;
}
