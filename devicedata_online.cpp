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

void DeviceData_Online::updatePage()
{
    setLabelState(this->ui->LBL_GW1,this->database->data_CCU->UIC_GW1_ONLINE);
    setLabelState(this->ui->LBL_GW2,this->database->data_CCU->UIC_GW2_ONLINE);
    setLabelState(this->ui->LBL_GW3,this->database->data_CCU->GW3_ONLINE);
    setLabelState(this->ui->LBL_RIOM1,this->database->data_CCU->RIOM1_ONLINE);
    setLabelState(this->ui->LBL_RIOM2,this->database->data_CCU->RIOM2_ONLINE);
    setLabelState(this->ui->LBL_TCU1,this->database->data_CCU->TCU1_ONLINE);
    setLabelState(this->ui->LBL_TCU2,this->database->data_CCU->TCU2_ONLINE);
    setLabelState(this->ui->LBL_TCU3,this->database->data_CCU->TCU3_ONLINE);
    setLabelState(this->ui->LBL_TCU4,this->database->data_CCU->TCU4_ONLINE);
    setLabelState(this->ui->LBL_ACU1,this->database->data_CCU->ACU1_ONLINE);
    setLabelState(this->ui->LBL_ACU2,this->database->data_CCU->ACU2_ONLINE);
    setLabelState(this->ui->LBL_MPU1,this->database->data_CCU->MPU1_ONLINE,this->database->data_CCU->CUR_MPU1);
    setLabelState(this->ui->LBL_MPU2,this->database->data_CCU->MPU2_ONLINE,this->database->data_CCU->CUR_MPU2);

    setLabelState(this->ui->LBL_DDU,this->database->data_CCU->DDU_ONLINE);
    setLabelState(this->ui->LBL_BCU,this->database->data_CCU->BCU_ONLINE);
    setLabelState(this->ui->LBL_CMD,this->database->data_CCU->ONLINE6A);
}

void DeviceData_Online::setLabelState(QLabel *lbl, bool online)
{
    if(online)
    {
        lbl->setStyleSheet(GREENBACKGROUND);
    }else
    {
        lbl->setStyleSheet(REDBACKGROUND);
    }

}

void DeviceData_Online::setLabelState(QLabel *lbl, bool online, bool Master)
{
    if(online)
    {
        if(Master)
        {
            lbl->setStyleSheet(GREENBACKGROUND);
        }else
        {
            lbl->setStyleSheet(YELLOWBACKGROUND);
        }
    }else
    {
        lbl->setStyleSheet(REDBACKGROUND);
    }

}
