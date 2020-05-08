#include "devicedata_mainconv.h"
#include "ui_devicedata_mainconv.h"

DeviceData_MainConv::DeviceData_MainConv(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_MainConv)
{
    ui->setupUi(this);
}

DeviceData_MainConv::~DeviceData_MainConv()
{
    delete ui;
}
