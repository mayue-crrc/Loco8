#include "devicedata_breaker.h"
#include "ui_devicedata_breaker.h"

DeviceData_Breaker::DeviceData_Breaker(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_Breaker)
{
    ui->setupUi(this);
}

DeviceData_Breaker::~DeviceData_Breaker()
{
    delete ui;
}
