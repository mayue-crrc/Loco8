#include "devicedata_io.h"
#include "ui_devicedata_io.h"

DeviceData_IO::DeviceData_IO(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_IO)
{
    ui->setupUi(this);
}

DeviceData_IO::~DeviceData_IO()
{
    delete ui;
}
