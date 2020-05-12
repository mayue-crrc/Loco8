#include "devicedata_acu.h"
#include "ui_devicedata_acu.h"

#define SWITCHCLOSE"border-image: url(:/images/images/SWclose.png);"
#define SWITCHOPEN "border-image: url(:/images/images/SWopen.png);"
#define SWITCHCLOSE_V"border-image: url(:/images/images/SWcloseV.png);"
#define SWITCHOPEN_V "border-image: url(:/images/images/SWopenV.png);"
#define PHCLOSE "border-image: url(:/images/images/PHclose.png);"
#define PHOPEN "border-image: url(:/images/images/PHopen.png);"

#define CIRCLE_YELLOW "border-image: url(:/images/images/Circle.png);"
#define CIRCLE_GREEN "border-image: url(:/images/images/Circle_Green.png);"


DeviceData_ACU::DeviceData_ACU(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_ACU)
{
    ui->setupUi(this);
    hideAll();
    this->ui->BTN_Train1->setStyleSheet(TRAINDOWNL);
    TrainIndex = 0;

    TrainSelect<<this->ui->BTN_Train1<<this->ui->BTN_Train2<<this->ui->BTN_Train3<<this->ui->BTN_Train4;

    SWList<<this->ui->LBL_OND_CVS1<<this->ui->LBL_SEC_CVS<<this->ui->LBL_OND_CVS2<<this->ui->LBL_C_MT1
         <<this->ui->LBL_C_MT2<<this->ui->LBL_C_BM1<<this->ui->LBL_C_BM2<<this->ui->LBL_C1_CPR<<this->ui->LBL_C2_CPR
        <<this->ui->LBL_C3_CPR<<this->ui->LBL_C_SM1<<this->ui->LBL_C_SM2;

    HBList<<this->ui->LBL_DJ_CPR<<this->ui->LBL_PH1<<this->ui->LBL_PH2<<this->ui->LBL_PE1
         <<this->ui->LBL_PE2<<this->ui->LBL_PE3<<this->ui->LBL_PE4;

    foreach (QPushButton* button, TrainSelect) {
        connect(button,SIGNAL(pressed()),this,SLOT(SelectTrainEvent()));
    }
}

DeviceData_ACU::~DeviceData_ACU()
{
    delete ui;
}

void DeviceData_ACU::updatePage()
{
    hideAll();

    SWState[TrainIndex]<<this->database->data_TCN->train[TrainIndex]->STATE_C_BAU1<<this->database->data_TCN->train[TrainIndex]->STATE_C_SEC
                      <<this->database->data_TCN->train[TrainIndex]->STATE_C_BAU2<<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_MT1
                     <<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_MT2<<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_BM1
                    <<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_BM2<<this->database->data_TCN->train[TrainIndex]->STATE_C1_CPR
                   <<this->database->data_TCN->train[TrainIndex]->STATE_C2_CPR<<this->database->data_TCN->train[TrainIndex]->STATE_C3_CPR
                  <<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_SM1<<this->database->data_TCN->train[TrainIndex]->STATE_C_VT_SM2;
    setSWstate(SWList,SWState[TrainIndex]);
    SWState[TrainIndex].clear();

    HBState[TrainIndex]<<this->database->data_TCN->train[TrainIndex]->STATE_Q_TH_CPR<<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PH1
                         <<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PH2<<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PE1
                           <<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PE2<<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PE3
                             <<this->database->data_TCN->train[TrainIndex]->STATE_DJ_PE4;
    setHBstate(HBList,HBState[TrainIndex]);
    SWState[TrainIndex].clear();

    this->ui->LBL_CON1->setText(QString::number(this->database->data_TCN->train[TrainIndex]->ACU1_FREQ)+"HZ");
    this->ui->LBL_CON2->setText(QString::number(this->database->data_TCN->train[TrainIndex]->ACU2_FREQ)+"HZ");

    this->ui->LBL_AFC1->setText(QString::number(this->database->data_TCN->train[TrainIndex]->WATER_TEMP1+50)+"C");
    this->ui->LBL_AFC2->setText(QString::number(this->database->data_TCN->train[TrainIndex]->WATER_TEMP2+50)+"C");


    setHBstate(this->ui->LBL_DJQUAI,this->database->data_CCU->DJ_QUAI);
    setSWstate(this->ui->LBL_C_QUAI,this->database->data_CCU->C_QUAI);

    if(this->database->data_CCU->Q_PP_QUAI)
    {
        this->ui->LBL_PPQUAI->setStyleSheet(CIRCLE_GREEN);
    }else
    {
        this->ui->LBL_PPQUAI->setStyleSheet(CIRCLE_YELLOW);
    }

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

void DeviceData_ACU::hideAll()
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

void DeviceData_ACU::SelectTrainEvent()
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

void DeviceData_ACU::setSWstate(QLabel *lbl, bool ok)
{
    if(ok)
    {
        lbl->setStyleSheet(SWITCHCLOSE);
    }else
    {
        lbl->setStyleSheet(SWITCHOPEN);
    }
}

void DeviceData_ACU::setSWstate(QList<QLabel *> lblList, QList<bool> stateList)
{
    for(int i = 0;i<lblList.size();i++)
    {
        if(stateList.at(i))
        {
            if(1 == i)
            {
                lblList.at(i)->setStyleSheet(SWITCHCLOSE_V);
            }else
            {
                lblList.at(i)->setStyleSheet(SWITCHCLOSE);
            }

        }else
        {
            if(1 == i)
            {
                lblList.at(i)->setStyleSheet(SWITCHOPEN_V);
            }else
            {
                lblList.at(i)->setStyleSheet(SWITCHOPEN);
            }
        }
    }
}

void DeviceData_ACU::setHBstate(QLabel *lbl, bool close)
{
    if(close)
    {
        lbl->setStyleSheet(PHCLOSE);
    }else
    {
        lbl->setStyleSheet(PHOPEN);
    }
}

void DeviceData_ACU::setHBstate(QList<QLabel *> lblList, QList<bool> stateList)
{
    for(int i = 0;i<lblList.size();i++)
    {
        if(stateList.at(i))
        {
            lblList.at(i)->setStyleSheet(PHCLOSE);
        }else
        {
            lblList.at(i)->setStyleSheet(PHOPEN);
        }
    }
}
