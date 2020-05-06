#include "main_assistantdevice.h"
#include "ui_main_assistantdevice.h"

Main_AssistantDevice::Main_AssistantDevice(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_AssistantDevice)
{
    ui->setupUi(this);
}

Main_AssistantDevice::~Main_AssistantDevice()
{
    delete ui;
}
