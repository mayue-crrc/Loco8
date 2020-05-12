#include "devicedata_breaker.h"
#include "ui_devicedata_breaker.h"

DeviceData_Breaker::DeviceData_Breaker(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_Breaker)
{
    ui->setupUi(this);
    this->ui->BTN_Train1->setStyleSheet(TRAINDOWNL);
    hideAll();
    TrainIndex = 0;
    TrainSelect<<this->ui->BTN_Train1<<this->ui->BTN_Train2<<this->ui->BTN_Train3<<this->ui->BTN_Train4;

    ACUList<<this->ui->LBL_C1_CPR<<this->ui->LBL_C2_CPR<<this->ui->LBL_C3_CPR<<this->ui->LBL_DJ_CPR
             <<this->ui->LBL_Q_REC<<this->ui->LBL_CVT_BM1<<this->ui->LBL_CVT_BM2<<this->ui->LBL_CVT_MT1
               <<this->ui->LBL_CVT_MT2<<this->ui->LBL_CVT_SM1<<this->ui->LBL_CVT_SM2<<this->ui->LBL_DJ_PE1
                 <<this->ui->LBL_DJ_PE2<<this->ui->LBL_DJ_PE3<<this->ui->LBL_DJ_PE4<<this->ui->LBL_DJ_PH1
                   <<this->ui->LBL_DJ_PH2<<this->ui->LBL_DJ_VT_SM1<<this->ui->LBL_DJ_VT_SM2<<this->ui->LBL_Q_TH_VT_BM1
                     <<this->ui->LBL_Q_TH_VT_BM2<<this->ui->LBL_Q_TH_VT_MT1<<this->ui->LBL_Q_TH_VT_MT2;

    foreach (QPushButton* button, TrainSelect) {
        connect(button,SIGNAL(pressed()),this,SLOT(SelectTrainEvent()));
    }
}

DeviceData_Breaker::~DeviceData_Breaker()
{
    delete ui;
}

void DeviceData_Breaker::updatePage()
{
    hideAll();
    ACUstate[TrainIndex]<<this->database->data_TCN->train[TrainIndex]->STATE_C1_CPR<<this->database->data_TCN->train[TrainIndex]->STATE_C2_CPR
                       <<this->database->data_TCN->train[TrainIndex]->STATE_C3_CPR<<this->database->data_TCN->train[TrainIndex]->STATE_Q_TH_CPR
                         <<this->database->data_TCN->train[TrainIndex]->STATE_Q_REC<<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_BM1
                           <<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_BM2<<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_MT1
                             <<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_MT2<<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_SM1
                               <<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_SM2<<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PE1
                                 <<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PE2<<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PE3
                                   <<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PE4<<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PH1
                                     <<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PH2<<this->database->data_TCN->train[TrainIndex]->STATE_DJ_VT_SM1
                                       <<this->database->data_TCN->train[TrainIndex]->STATE_DJ_VT_SM2<<this->database->data_TCN->train[TrainIndex]->STATE_Q_TH_VT_BM1
                                         <<this->database->data_TCN->train[TrainIndex]->STATE_Q_TH_VT_BM2<<this->database->data_TCN->train[TrainIndex]->STATE_Q_TH_VT_MT1
                                           <<this->database->data_TCN->train[TrainIndex]->STATE_Q_TH_VT_MT2;

    setaLabelstate(ACUList,ACUstate[TrainIndex]);
    ACUstate[TrainIndex].clear();

    switch (this->database->data_CCU->RULOCO_NO)
    {
    case 0:
        this->ui->LBL_Train1Num->show();
        this->ui->BTN_Train1->show();
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->LOCO_NO,16));
        break;
    case 1:
        this->ui->LBL_Train1Num->show();
        this->ui->BTN_Train1->show();
        this->ui->LBL_Train2Num->show();
        this->ui->BTN_Train2->show();
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->LOCO_NO,16));
        this->ui->LBL_Train2Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[1]->LOCO_NO,16));
        break;
    case 2:
        this->ui->LBL_Train1Num->show();
        this->ui->BTN_Train1->show();
        this->ui->LBL_Train2Num->show();
        this->ui->BTN_Train2->show();
        this->ui->LBL_Train3Num->show();
        this->ui->BTN_Train3->show();
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->LOCO_NO,16));
        this->ui->LBL_Train2Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[1]->LOCO_NO,16));
        this->ui->LBL_Train3Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[2]->LOCO_NO,16));
        break;
    case 3:
        this->ui->LBL_Train1Num->show();
        this->ui->BTN_Train1->show();
        this->ui->LBL_Train2Num->show();
        this->ui->BTN_Train2->show();
        this->ui->LBL_Train3Num->show();
        this->ui->BTN_Train3->show();
        this->ui->LBL_Train4Num->show();
        this->ui->BTN_Train4->show();
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->LOCO_NO,16));
        this->ui->LBL_Train2Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[1]->LOCO_NO,16));
        this->ui->LBL_Train3Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[2]->LOCO_NO,16));
        this->ui->LBL_Train4Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[3]->LOCO_NO,16));
        break;
    default:
        break;
    }
}

void DeviceData_Breaker::SelectTrainEvent()
{
    for(int i=0;i<TrainSelect.size();i++)
    {
        if(0 == i%2)
        {
            TrainSelect.at(i)->setStyleSheet(TRAINUPL);
        }else
        {
            TrainSelect.at(i)->setStyleSheet(TRAINUPR);
        }
    }

   TrainIndex = ((QPushButton*)this->sender())->whatsThis().toInt();

   switch(TrainIndex)
   {
   case 0:
       this->ui->BTN_Train1->setStyleSheet(TRAINDOWNL);
       break;
   case 1:
       this->ui->BTN_Train2->setStyleSheet(TRAINDOWNR);
       break;
   case 2:
       this->ui->BTN_Train3->setStyleSheet(TRAINDOWNL);
       break;
   case 3:
       this->ui->BTN_Train4->setStyleSheet(TRAINDOWNR);
       break;
   }

}

void DeviceData_Breaker::hideAll()
{
    this->ui->LBL_Train1Num->hide();
    this->ui->BTN_Train1->hide();
    this->ui->LBL_Train2Num->hide();
    this->ui->BTN_Train2->hide();
    this->ui->LBL_Train3Num->hide();
    this->ui->BTN_Train3->hide();
    this->ui->LBL_Train4Num->hide();
    this->ui->BTN_Train4->hide();
}

void DeviceData_Breaker::setaLabelstate(QList<QLabel *> lbl, QList<bool> state)
{
    for(int i =0;i<lbl.size();i++)
    {
        if(state.at(i))
        {
            lbl.at(i)->setStyleSheet(GREEN);
        }else
        {
            lbl.at(i)->setStyleSheet(RED);
        }
    }
}
