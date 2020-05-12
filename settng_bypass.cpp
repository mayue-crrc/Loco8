#include "settng_bypass.h"
#include "ui_settng_bypass.h"

#define BrkISO "background-color:rgb(255,0,0);color:black;font:16px;border-bottom: 2px solid white;border-right: 2px solid white;"
#define BrkNISO "background-color:rgb(0,255,0);color:black;font:16px;border-top: 2px solid white;border-left: 2px solid white;"

Settng_Bypass::Settng_Bypass(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Bypass)
{
    ui->setupUi(this);

    BrkList<<this->ui->LBL_EMBState<<this->ui->LBL_PBState<<this->ui->LBL_Cylinder1State<<this->ui->LBL_Cylinder2State;

    TrainSelect<<this->ui->BTN_Train1<<this->ui->BTN_Train2<<this->ui->BTN_Train3<<this->ui->BTN_Train4;

    TCUList<<this->ui->BTN_TCU1<<this->ui->BTN_4QR1<<this->ui->BTN_4QR2<<this->ui->BTN_MotorInv1<<this->ui->BTN_MotorInv2<<this->ui->BTN_AUX1
          <<this->ui->BTN_TCU2<<this->ui->BTN_4QR3<<this->ui->BTN_4QR4<<this->ui->BTN_MotorInv3<<this->ui->BTN_MotorInv4<<this->ui->BTN_AUX2
         <<this->ui->BTN_AlertControl<<this->ui->BTN_EBreak<<this->ui->BTN_Compressor<<this->ui->BTN_Lubrication;

    TCUlabList<<this->ui->LBL_TCU1<<this->ui->LBL_4QR1<<this->ui->LBL_4QR2<<this->ui->LBL_MotorInv1<<this->ui->LBL_MotorInv2<<this->ui->LBL_AUX1
             <<this->ui->LBL_TCU2<<this->ui->LBL_4QR3<<this->ui->LBL_4QR4<<this->ui->LBL_MotorInv3<<this->ui->LBL_MotorInv4<<this->ui->LBL_AUX2
            <<this->ui->LBL_AlertControl<<this->ui->LBL_EBreak<<this->ui->LBL_Compressor<<this->ui->LBL_Lubrication;


    handISO<<"☝牵引变流器1"<<"☝四象限整流器1"<<"☝四象限整流器2"<<"☝电机逆变器1"<<"☝电机逆变器2"<<"☝辅助逆变器1"<<"☝牵引变流器2"<<"☝四象限整流器3"<<"☝四象限整流器4"<<"☝电机逆变器3"
             <<"☝电机逆变器4"<<"☝辅助逆变器2"<<"☝警惕控制"<<"☝动力制动"<<"☝空压机"<<"☝轮缘润滑";

    notISO<<"牵引变流器1"<<"四象限整流器1"<<"四象限整流器2"<<"电机逆变器1"<<"电机逆变器2"<<"辅助逆变器1"<<"牵引变流器2"<<"四象限整流器3"<<"四象限整流器4"<<"电机逆变器3"
             <<"电机逆变器4"<<"辅助逆变器2"<<"警惕控制"<<"动力制动"<<"空压机"<<"轮缘润滑";


    foreach (QPushButton* button, TrainSelect) {
        connect(button,SIGNAL(pressed()),this,SLOT(SelectTrainEvent()));
    }

    foreach (QPushButton* button, TCUList) {
        connect(button,SIGNAL(pressed()),this,SLOT(TCUListEvent()));
    }

    this->ui->setBox->hide();
    this->ui->BTN_Train1->setStyleSheet(TRAINDOWNL);
    TrainIndex = 0;

    hideAll();
}

Settng_Bypass::~Settng_Bypass()
{
    delete ui;
}

void Settng_Bypass::updatePage()
{
    hideAll();
    setButtonState(this->ui->BTN_AutoSandCutout,this->database->data_CCU->SAND_CUT,"☝自动撒沙切除","自动撒沙切除");
    setButtonState(this->ui->BTN_CombCutout,this->database->data_CCU->ELEC_AIR_CUT,"☝空电联合切除","空电联合切除");

    TrainBrkISOstate[TrainIndex]<<this->database->data_TCN->train[TrainIndex]->STATE_RB_EMG<<this->database->data_TCN->train[TrainIndex]->STATE_RB_IS_FS
                               <<this->database->data_TCN->train[TrainIndex]->STATE_RB_IS_CF1<<this->database->data_TCN->train[TrainIndex]->STATE_RB_IS_CF2;

    TrainISOstate[TrainIndex]<<this->database->data_TCN->train[TrainIndex]->BOGIE1ISO<<this->database->data_TCN->train[TrainIndex]->FAULT_COV1_ISO<<this->database->data_TCN->train[TrainIndex]->FAULT_COV2_ISO
            <<this->database->data_TCN->train[TrainIndex]->FAULT_INV1_ISO<<this->database->data_TCN->train[TrainIndex]->FAULT_INV2_ISO
            <<this->database->data_TCN->train[TrainIndex]->FAULT_ACU1_ISO<<this->database->data_TCN->train[TrainIndex]->BOGIE2ISO<<this->database->data_TCN->train[TrainIndex]->FAULT_COV3_ISO
            <<this->database->data_TCN->train[TrainIndex]->FAULT_COV4_ISO<<this->database->data_TCN->train[TrainIndex]->FAULT_INV3_ISO
            <<this->database->data_TCN->train[TrainIndex]->FAULT_INV4_ISO<<this->database->data_TCN->train[TrainIndex]->FAULT_ACU2_ISO
            <<this->database->data_TCN->train[TrainIndex]->FAULT_DEADMAN_ISO<<this->database->data_TCN->train[TrainIndex]->FAULT_DLZD_ISO
            <<0<<this->database->data_TCN->train[TrainIndex]->FAULT_LUBRA_ISO;

    TrainHISOstate[TrainIndex]<<this->database->data_TCN->train[TrainIndex]->BOGIE1HISO<<this->database->data_TCN->train[TrainIndex]->FAULT_COV1_HISO<<this->database->data_TCN->train[TrainIndex]->FAULT_COV2_HISO
                 <<this->database->data_TCN->train[TrainIndex]->FAULT_INV1_HISO<<this->database->data_TCN->train[TrainIndex]->FAULT_INV2_HISO
                <<this->database->data_TCN->train[TrainIndex]->FAULT_ACU1_HISO<<this->database->data_TCN->train[TrainIndex]->BOGIE2HISO<<this->database->data_TCN->train[TrainIndex]->FAULT_COV3_HISO
                  <<this->database->data_TCN->train[TrainIndex]->FAULT_COV4_HISO<<this->database->data_TCN->train[TrainIndex]->FAULT_INV3_HISO
                 <<this->database->data_TCN->train[TrainIndex]->FAULT_INV4_HISO<<this->database->data_TCN->train[TrainIndex]->FAULT_ACU2_HISO
                  <<0<<this->database->data_TCN->train[TrainIndex]->FAULT_DLZD_HISO<<this->database->data_TCN->train[TrainIndex]->FAULT_KYJ_HISO<<TrainIndex;

    Train1CutSignal<<&this->database->data_CCU->TC1_BOGIE1_ISO_RQ<<&this->database->data_CCU->TC1_4Q1_ISO_RQ
                    <<&this->database->data_CCU->TC1_4Q2_ISO_RQ<<&this->database->data_CCU->TC1_AXLE1_ISO_RQ
                      <<&this->database->data_CCU->TC1_AXLE2_ISO_RQ<<&this->database->data_CCU->TC1_AUX1_ISO_RQ
                   <<&this->database->data_CCU->TC1_BOGIE2_ISO_RQ <<&this->database->data_CCU->TC1_4Q3_ISO_RQ
                      <<&this->database->data_CCU->TC1_4Q4_ISO_RQ <<&this->database->data_CCU->TC1_AXLE3_ISO_RQ
                         <<&this->database->data_CCU->TC1_AXLE4_ISO_RQ <<&this->database->data_CCU->TC1_AUX2_ISO_RQ
                        <<&this->database->data_CCU->TC1_DAMAN_ISO_RQ<<&this->database->data_CCU->TC1_EBRK_ISO_RQ
                       <<&this->database->data_CCU->TC1_CPR_ISO_RQ<<&this->database->data_CCU->TC1_FLL_ISO_RQ;

    Train2CutSignal<<&this->database->data_CCU->TC2_BOGIE1_ISO_RQ<<&this->database->data_CCU->TC2_4Q1_ISO_RQ
                    <<&this->database->data_CCU->TC2_4Q2_ISO_RQ<<&this->database->data_CCU->TC2_AXLE1_ISO_RQ
                      <<&this->database->data_CCU->TC2_AXLE2_ISO_RQ<<&this->database->data_CCU->TC2_AUX1_ISO_RQ
                   <<&this->database->data_CCU->TC2_BOGIE2_ISO_RQ <<&this->database->data_CCU->TC2_4Q3_ISO_RQ
                      <<&this->database->data_CCU->TC2_4Q4_ISO_RQ <<&this->database->data_CCU->TC2_AXLE3_ISO_RQ
                         <<&this->database->data_CCU->TC2_AXLE4_ISO_RQ <<&this->database->data_CCU->TC2_AUX2_ISO_RQ
                        <<&this->database->data_CCU->TC2_DAMAN_ISO_RQ<<&this->database->data_CCU->TC2_EBRK_ISO_RQ
                       <<&this->database->data_CCU->TC2_CPR_ISO_RQ<<&this->database->data_CCU->TC2_FLL_ISO_RQ;

    Train3CutSignal<<&this->database->data_CCU->TC3_BOGIE1_ISO_RQ<<&this->database->data_CCU->TC3_4Q1_ISO_RQ
                    <<&this->database->data_CCU->TC3_4Q2_ISO_RQ<<&this->database->data_CCU->TC3_AXLE1_ISO_RQ
                      <<&this->database->data_CCU->TC3_AXLE2_ISO_RQ<<&this->database->data_CCU->TC3_AUX1_ISO_RQ
                   <<&this->database->data_CCU->TC3_BOGIE2_ISO_RQ <<&this->database->data_CCU->TC3_4Q3_ISO_RQ
                      <<&this->database->data_CCU->TC3_4Q4_ISO_RQ <<&this->database->data_CCU->TC3_AXLE3_ISO_RQ
                         <<&this->database->data_CCU->TC3_AXLE4_ISO_RQ <<&this->database->data_CCU->TC3_AUX2_ISO_RQ
                        <<&this->database->data_CCU->TC3_DAMAN_ISO_RQ<<&this->database->data_CCU->TC3_EBRK_ISO_RQ
                       <<&this->database->data_CCU->TC3_CPR_ISO_RQ<<&this->database->data_CCU->TC3_FLL_ISO_RQ;

    Train4CutSignal<<&this->database->data_CCU->TC4_BOGIE1_ISO_RQ<<&this->database->data_CCU->TC4_4Q1_ISO_RQ
                    <<&this->database->data_CCU->TC4_4Q2_ISO_RQ<<&this->database->data_CCU->TC4_AXLE1_ISO_RQ
                      <<&this->database->data_CCU->TC4_AXLE2_ISO_RQ<<&this->database->data_CCU->TC4_AUX1_ISO_RQ
                   <<&this->database->data_CCU->TC4_BOGIE2_ISO_RQ <<&this->database->data_CCU->TC4_4Q3_ISO_RQ
                      <<&this->database->data_CCU->TC4_4Q4_ISO_RQ <<&this->database->data_CCU->TC4_AXLE3_ISO_RQ
                         <<&this->database->data_CCU->TC4_AXLE4_ISO_RQ <<&this->database->data_CCU->TC4_AUX2_ISO_RQ
                        <<&this->database->data_CCU->TC4_DAMAN_ISO_RQ<<&this->database->data_CCU->TC4_EBRK_ISO_RQ
                       <<&this->database->data_CCU->TC4_CPR_ISO_RQ<<&this->database->data_CCU->TC4_FLL_ISO_RQ;

    Train1CancelSignal<<&this->database->data_CCU->TC1_BOGIE1_ISO_REL_RQ<<&this->database->data_CCU->TC1_4Q1_ISO_REL_RQ
                    <<&this->database->data_CCU->TC1_4Q2_ISO_REL_RQ<<&this->database->data_CCU->TC1_AXLE1_ISO_REL_RQ
                      <<&this->database->data_CCU->TC1_AXLE2_ISO_REL_RQ<<&this->database->data_CCU->TC1_AUX1_ISO_REL_RQ
                   <<&this->database->data_CCU->TC1_BOGIE2_ISO_REL_RQ <<&this->database->data_CCU->TC1_4Q3_ISO_REL_RQ
                      <<&this->database->data_CCU->TC1_4Q4_ISO_REL_RQ <<&this->database->data_CCU->TC1_AXLE3_ISO_REL_RQ
                         <<&this->database->data_CCU->TC1_AXLE4_ISO_REL_RQ <<&this->database->data_CCU->TC1_AUX2_ISO_REL_RQ
                        <<&this->database->data_CCU->TC1_DAMAN_ISO_REL_RQ<<&this->database->data_CCU->TC1_EBRK_ISO_REL_RQ
                       <<&this->database->data_CCU->TC1_CPR_ISO_REL_RQ<<&this->database->data_CCU->TC1_FLL_ISO_REL_RQ;

    Train2CancelSignal<<&this->database->data_CCU->TC2_BOGIE1_ISO_REL_RQ<<&this->database->data_CCU->TC2_4Q1_ISO_REL_RQ
                    <<&this->database->data_CCU->TC2_4Q2_ISO_REL_RQ<<&this->database->data_CCU->TC2_AXLE1_ISO_REL_RQ
                      <<&this->database->data_CCU->TC2_AXLE2_ISO_REL_RQ<<&this->database->data_CCU->TC2_AUX1_ISO_REL_RQ
                   <<&this->database->data_CCU->TC2_BOGIE2_ISO_REL_RQ <<&this->database->data_CCU->TC2_4Q3_ISO_REL_RQ
                      <<&this->database->data_CCU->TC2_4Q4_ISO_REL_RQ <<&this->database->data_CCU->TC2_AXLE3_ISO_REL_RQ
                         <<&this->database->data_CCU->TC2_AXLE4_ISO_REL_RQ <<&this->database->data_CCU->TC2_AUX2_ISO_REL_RQ
                        <<&this->database->data_CCU->TC2_DAMAN_ISO_REL_RQ<<&this->database->data_CCU->TC2_EBRK_ISO_REL_RQ
                       <<&this->database->data_CCU->TC2_CPR_ISO_REL_RQ<<&this->database->data_CCU->TC2_FLL_ISO_REL_RQ;

    Train3CancelSignal<<&this->database->data_CCU->TC3_BOGIE1_ISO_REL_RQ<<&this->database->data_CCU->TC3_4Q1_ISO_REL_RQ
                    <<&this->database->data_CCU->TC3_4Q2_ISO_REL_RQ<<&this->database->data_CCU->TC3_AXLE1_ISO_REL_RQ
                      <<&this->database->data_CCU->TC3_AXLE2_ISO_REL_RQ<<&this->database->data_CCU->TC3_AUX1_ISO_REL_RQ
                   <<&this->database->data_CCU->TC3_BOGIE2_ISO_REL_RQ <<&this->database->data_CCU->TC3_4Q3_ISO_REL_RQ
                      <<&this->database->data_CCU->TC3_4Q4_ISO_REL_RQ <<&this->database->data_CCU->TC3_AXLE3_ISO_REL_RQ
                         <<&this->database->data_CCU->TC3_AXLE4_ISO_REL_RQ <<&this->database->data_CCU->TC3_AUX2_ISO_REL_RQ
                        <<&this->database->data_CCU->TC3_DAMAN_ISO_REL_RQ<<&this->database->data_CCU->TC3_EBRK_ISO_REL_RQ
                       <<&this->database->data_CCU->TC3_CPR_ISO_REL_RQ<<&this->database->data_CCU->TC3_FLL_ISO_REL_RQ;

    Train4CancelSignal<<&this->database->data_CCU->TC4_BOGIE1_ISO_REL_RQ<<&this->database->data_CCU->TC4_4Q1_ISO_REL_RQ
                    <<&this->database->data_CCU->TC4_4Q2_ISO_REL_RQ<<&this->database->data_CCU->TC4_AXLE1_ISO_REL_RQ
                      <<&this->database->data_CCU->TC4_AXLE2_ISO_REL_RQ<<&this->database->data_CCU->TC4_AUX1_ISO_REL_RQ
                   <<&this->database->data_CCU->TC4_BOGIE2_ISO_REL_RQ <<&this->database->data_CCU->TC4_4Q3_ISO_REL_RQ
                      <<&this->database->data_CCU->TC4_4Q4_ISO_REL_RQ <<&this->database->data_CCU->TC4_AXLE3_ISO_REL_RQ
                         <<&this->database->data_CCU->TC4_AXLE4_ISO_REL_RQ <<&this->database->data_CCU->TC4_AUX2_ISO_REL_RQ
                        <<&this->database->data_CCU->TC4_DAMAN_ISO_REL_RQ<<&this->database->data_CCU->TC4_EBRK_ISO_REL_RQ
                       <<&this->database->data_CCU->TC4_CPR_ISO_REL_RQ<<&this->database->data_CCU->TC4_FLL_ISO_REL_RQ;

    FaultReset<<&this->database->data_CCU->TC1_FAULT_RESET<<&this->database->data_CCU->TC2_FAULT_RESET
             <<&this->database->data_CCU->TC3_FAULT_RESET<<&this->database->data_CCU->TC4_FAULT_RESET; 


    setLabelState(BrkList,TrainBrkISOstate[TrainIndex]);
    TrainBrkISOstate[TrainIndex].clear();

    setLabelState(TCUlabList,TrainHISOstate[TrainIndex],TrainISOstate[TrainIndex]);
    TrainHISOstate[TrainIndex].clear();
    TrainISOstate[TrainIndex].clear();

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

void Settng_Bypass::hideAll()
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

void Settng_Bypass::SelectTrainEvent()
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

void Settng_Bypass::setLabelState(QList<QLabel *> lblList, QList<bool> stateList)
{

    for(int i = 0;i<lblList.size();i++)
    {
        if(stateList.at(i))
        {
            lblList.at(i)->setStyleSheet(BrkISO);
        }else
        {
            lblList.at(i)->setStyleSheet(BrkNISO);
        }
    }
}

void Settng_Bypass::setLabelState(QList<QLabel *> lblList, QList<bool> handISOList, QList<bool> ISOList)
{
    for(int i = 0;i<lblList.size();i++)
    {
        if(ISOList.at(i))
        {
            lblList.at(i)->setStyleSheet(BrkISO);
        }else if(handISOList.at(i))
        {
            lblList.at(i)->setStyleSheet(BrkISO);
            lblList.at(i)->setText(handISO[i]);
        }else
        {
            lblList.at(i)->setStyleSheet(BrkNISO);
            lblList.at(i)->setText(notISO[i]);
        }
    }
}

void Settng_Bypass::setButtonState(QPushButton *btn, bool iso, QString str1, QString str2)
{
    if(iso)
    {
        btn->setStyleSheet(BrkISO);
        btn->setText(str1);
    }else
    {
        btn->setStyleSheet(BrkNISO);
        btn->setText(str2);
    }
}

void Settng_Bypass::TCUListEvent()
{
    this->ui->setBox->show();
    SelectIndex = ((QPushButton*)this->sender())->whatsThis().toInt();
    this->ui->LBL_SetTitle->setText(TCUlabList.at(SelectIndex)->text());
}

void Settng_Bypass::on_BTN_Close_pressed()
{
    this->ui->setBox->hide();
}

void Settng_Bypass::on_BTN_HandISO_pressed()
{
    this->ui->BTN_HandISO->setStyleSheet(BYPASSDOWN);
    switch (TrainIndex) {
    case 0:
        *Train1CutSignal.at(SelectIndex) = true;
        break;
    case 1:
        *Train2CutSignal.at(SelectIndex) = true;
        break;
    case 2:
        *Train3CutSignal.at(SelectIndex) = true;
        break;
    case 3:
        *Train4CutSignal.at(SelectIndex) = true;
        break;
    default:
        break;
    }
    timerISO = startTimer(3000);
}

void Settng_Bypass::on_BTN_ISOCancel_pressed()
{
    this->ui->BTN_ISOCancel->setStyleSheet(BYPASSDOWN);
    switch (TrainIndex) {
    case 0:
        *Train1CancelSignal.at(SelectIndex) = true;
        break;
    case 1:
        *Train2CancelSignal.at(SelectIndex) = true;
        break;
    case 2:
        *Train3CancelSignal.at(SelectIndex) = true;
        break;
    case 3:
        *Train4CancelSignal.at(SelectIndex) = true;
        break;
    default:
        break;
    }
    timerREL = startTimer(3000);
}

void Settng_Bypass::timerEvent(QTimerEvent *e)
{
    if(timerISO == e->timerId())
    {
        killTimer(timerISO);
        this->ui->BTN_HandISO->setStyleSheet(BYPASSUP);
        switch (TrainIndex) {
        case 0:
            *Train1CutSignal.at(SelectIndex) = false;
            break;
        case 1:
            *Train2CutSignal.at(SelectIndex) = false;
            break;
        case 2:
            *Train3CutSignal.at(SelectIndex) = false;
            break;
        case 3:
            *Train4CutSignal.at(SelectIndex) = false;
            break;
        default:
            break;
        }
        timerISO = 0;
    }

    if(timerREL == e->timerId())
    {
        killTimer(timerREL);
        this->ui->BTN_ISOCancel->setStyleSheet(BYPASSUP);
        switch (TrainIndex) {
        case 0:
            *Train1CancelSignal.at(SelectIndex) = false;
            break;
        case 1:
            *Train2CancelSignal.at(SelectIndex) = false;
            break;
        case 2:
            *Train3CancelSignal.at(SelectIndex) = false;
            break;
        case 3:
            *Train4CancelSignal.at(SelectIndex) = false;
            break;
        default:
            break;
        }
        timerREL = 0;
    }

    if(timerResetFault == e->timerId())
    {
        killTimer(timerResetFault);
        *FaultReset[TrainIndex] = false;
        this->ui->BTN_ClearFault->setStyleSheet(NButtonUP);
    }

    this->ui->setBox->hide();
}


void Settng_Bypass::on_BTN_AutoSandCutout_pressed()
{
    if(this->database->data_CCU->SAND_CUT)
    {
        this->database->data_CCU->SAND_CUTDDU = false;
    }else
    {
        this->database->data_CCU->SAND_CUTDDU = true;
    }
}

void Settng_Bypass::on_BTN_CombCutout_pressed()
{
    if(this->database->data_CCU->ELEC_AIR_CUT)
    {
        this->database->data_CCU->ELEC_AIR_CUTDDU = false;
    }else
    {
        this->database->data_CCU->ELEC_AIR_CUTDDU = true;
    }
}

void Settng_Bypass::on_BTN_ClearFault_pressed()
{
    if(this->database->data_TCN->train[TrainIndex]->CMD_DDU_RESET)
    {
        *FaultReset[TrainIndex] = false;
    }else
    {
        this->ui->BTN_ClearFault->setStyleSheet(NButtonDOWN);
        *FaultReset[TrainIndex] = true;
        timerResetFault = startTimer(3000);
    }
}
