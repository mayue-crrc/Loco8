#include "devicedata_version.h"
#include "ui_devicedata_version.h"

DeviceData_Version::DeviceData_Version(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_Version)
{
    ui->setupUi(this);

    Device<<this->ui->LBL_Name_2<<this->ui->LBL_Name_3<<this->ui->LBL_Name_4<<this->ui->LBL_Name_5<<this->ui->LBL_Name_6
         <<this->ui->LBL_Name_7<<this->ui->LBL_Name_8<<this->ui->LBL_Name_9<<this->ui->LBL_Name_10<<this->ui->LBL_Name_11
        <<this->ui->LBL_Name_12<<this->ui->LBL_Name_13<<this->ui->LBL_Name_14<<this->ui->LBL_Name_15<<this->ui->LBL_Name_16;

    VerX<<this->ui->LBL_StateX_2<<this->ui->LBL_StateX_3<<this->ui->LBL_StateX_4<<this->ui->LBL_StateX_5<<this->ui->LBL_StateX_6
       <<this->ui->LBL_StateX_7<<this->ui->LBL_StateX_8<<this->ui->LBL_StateX_9<<this->ui->LBL_StateX_10<<this->ui->LBL_StateX_11
      <<this->ui->LBL_StateX_12<<this->ui->LBL_StateX_13<<this->ui->LBL_StateX_14<<this->ui->LBL_StateX_15<<this->ui->LBL_StateX_16;

    VerY<<this->ui->LBL_StateY_2<<this->ui->LBL_StateY_3<<this->ui->LBL_StateY_4<<this->ui->LBL_StateY_5<<this->ui->LBL_StateY_6
       <<this->ui->LBL_StateY_7<<this->ui->LBL_StateY_8<<this->ui->LBL_StateY_9<<this->ui->LBL_StateY_10<<this->ui->LBL_StateY_11
      <<this->ui->LBL_StateY_12<<this->ui->LBL_StateY_13<<this->ui->LBL_StateY_14<<this->ui->LBL_StateY_15<<this->ui->LBL_StateY_16;

    VerZ<<this->ui->LBL_StateZ_2<<this->ui->LBL_StateZ_3<<this->ui->LBL_StateZ_4<<this->ui->LBL_StateZ_5<<this->ui->LBL_StateZ_6
       <<this->ui->LBL_StateZ_7<<this->ui->LBL_StateZ_8<<this->ui->LBL_StateZ_9<<this->ui->LBL_StateZ_10<<this->ui->LBL_StateZ_11
      <<this->ui->LBL_StateZ_12<<this->ui->LBL_StateZ_13<<this->ui->LBL_StateZ_14<<this->ui->LBL_StateZ_15<<this->ui->LBL_StateZ_16;

    NameList<<"MPU1"<<"MPU2"<<"ACU1"<<"ACU2"<<"TCU1"<<"TCU2"<<"TCU3"<<"TCU4"<<"BCU"
           <<"DDU"<<"GW3"<<"GW1"<<"GW2"<<"RIOM1"<<"RIOM2";
}

DeviceData_Version::~DeviceData_Version()
{
    delete ui;
}

void DeviceData_Version::updatePage()
{
    if(this->database->data_CCU->DEVICE_NO > 0)
    {
        Device.at(this->database->data_CCU->DEVICE_NO-1)->setText(NameList.at(this->database->data_CCU->DEVICE_NO-1));
        VerX.at(this->database->data_CCU->DEVICE_NO-1)->setText(QString::number(this->database->data_CCU->VERSION_X));
        VerY.at(this->database->data_CCU->DEVICE_NO-1)->setText(QString::number(this->database->data_CCU->VERSION_Y));
        VerZ.at(this->database->data_CCU->DEVICE_NO-1)->setText(QString::number(this->database->data_CCU->VERSION_Z));
    }

}
