#include "fault_detail.h"
#include "ui_fault_detail.h"
#include "crrcfault.h"
Fault_Detail::Fault_Detail(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Fault_Detail)
{
    ui->setupUi(this);
}

Fault_Detail::~Fault_Detail()
{
    delete ui;
}

void Fault_Detail::on_BTNCurrentFault_clicked()
{

}

void Fault_Detail::on_BTNConfirm_clicked()
{
    if(CrrcFault::getCrrcFault()->getConfirmFaultListSize()>0)
        CrrcFault::getCrrcFault()->deleteConfirmFault(0);


}
void Fault_Detail::updatePage()
{
    if(CrrcFault::getCrrcFault()->getConfirmFaultListSize()>0)
    {
        ui->LBLCode->setText(CrrcFault::getCrrcFault()->getCurrentFaultCode(0));
        ui->LBLLevel->setText(CrrcFault::getCrrcFault()->getCurrentFaultLevel(0));
        ui->LBLNumber->setText(QString::number(database->data_TCN->TrainLocal->LOCO_NO));
        ui->LBLName->setText(CrrcFault::getCrrcFault()->getCurrentFaultName(0));
        ui->LBLTips->setText(CrrcFault::getCrrcFault()->getCurrentFaultDescription(0));
        ui->LBLDevice->setText(CrrcFault::getCrrcFault()->getCurrentFaultDevice(0));
        ui->LBLStarttime->setText(CrrcFault::getCrrcFault()->getCurrentFaultDate(0)+" "+
                                  CrrcFault::getCrrcFault()->getCurrentFaultTime(0));

    }else
    {
        ui->LBLCode->setText("");
        ui->LBLLevel->setText("");
        ui->LBLNumber->setText("");
        ui->LBLName->setText("");
        ui->LBLTips->setText("");
        ui->LBLDevice->setText("");
        ui->LBLStarttime->setText("");
    }


}

void Fault_Detail::showEvent(QShowEvent *event)
{

}
