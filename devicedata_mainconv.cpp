#include "devicedata_mainconv.h"
#include "ui_devicedata_mainconv.h"

#define SWITCHCLOSE"border-image: url(:/images/images/SWclose.png);"
#define SWITCHOPEN "border-image: url(:/images/images/SWopen.png);"
#define PHCLOSE "border-image: url(:/images/images/PHclose.png);"
#define PHOPEN "border-image: url(:/images/images/PHopen.png);"


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

void DeviceData_MainConv::updatePage()
{
  setLabelState(this->ui->LBL_PC_CF1,this->database->data_TCU->KA_PC_OK[0]);
  setLabelState(this->ui->LBL_IS_CF1,this->database->data_TCU->KA_WORK_OK[0]);
  setLabelState(this->ui->LBL_PC_CF2,this->database->data_TCU->KA_PC_OK[1]);
  setLabelState(this->ui->LBL_IS_CF2,this->database->data_TCU->KA_WORK_OK[1]);
  setLabelState(this->ui->LBL_PC_CF3,this->database->data_TCU->KA_PC_OK[2]);
  setLabelState(this->ui->LBL_IS_CF3,this->database->data_TCU->KA_WORK_OK[2]);
  setLabelState(this->ui->LBL_PC_CF4,this->database->data_TCU->KA_PC_OK[3]);
  setLabelState(this->ui->LBL_IS_CF4,this->database->data_TCU->KA_WORK_OK[3]);
  setLabelState(this->ui->LBL_IS_QUAI,this->database->data_CCU->C_IS_QUAI);
  setLabelState(this->ui->LBL_PC_QUAI,this->database->data_CCU->C_PC_QUAI);


  if(this->database->data_CCU->DJ_QUAI)
  {
      this->ui->LBL_DJQUAI->setStyleSheet(PHCLOSE);
  }else
  {
      this->ui->LBL_DJQUAI->setStyleSheet(PHOPEN);
  }

  this->ui->LBL_Volta1->setText(QString::number(this->database->data_TCU->INVT_IN_V[0]));
  this->ui->LBL_Volta2->setText(QString::number(this->database->data_TCU->INVT_IN_V[1]));
  this->ui->LBL_Volta3->setText(QString::number(this->database->data_TCU->INVT_IN_V[2]));
  this->ui->LBL_Volta4->setText(QString::number(this->database->data_TCU->INVT_IN_V[3]));

}

void DeviceData_MainConv::setLabelState(QLabel *lbl, bool ok)
{
    if(ok)
    {
        lbl->setStyleSheet(SWITCHCLOSE);
    }else
    {
        lbl->setStyleSheet(SWITCHOPEN);
    }
}
