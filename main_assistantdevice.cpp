#include "main_assistantdevice.h"
#include "ui_main_assistantdevice.h"

Main_AssistantDevice::Main_AssistantDevice(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_AssistantDevice)
{
    ui->setupUi(this);
    funcButtons<<ui->PB_F_1<<ui->PB_F_2<<ui->PB_F_3<<ui->PB_F_4
              <<ui->PB_F_5<<ui->PB_F_6<<ui->PB_F_7;

    foreach (QPushButton * button, funcButtons) {
        connect(button,SIGNAL(pressed()),this,SLOT(funcButtonPressEvent()));
    }

    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(updateSet()));


}

Main_AssistantDevice::~Main_AssistantDevice()
{
    delete ui;
}

void Main_AssistantDevice::funcButtonPressEvent()
{
    int number=((QPushButton *)this->sender())->whatsThis().toInt();
    switch (number)
    {
        case mainPresss:
            qTimer->start(2000);
            database->data_CCU->CPR_TEST=1;
            makeButtonsUnEnable();
            ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
        break;
        case coolWind1:
            qTimer->start(2000);
            database->data_CCU->VT_BM1_ST=1;
            makeButtonsUnEnable();
            ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
            break;
        case coolWind2:
            qTimer->start(2000);
            database->data_CCU->VT_BM2_ST=1;
            makeButtonsUnEnable();
            ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
            break;
        case tractWind1:
            qTimer->start(2000);
            database->data_CCU->VT_MT1_ST=1;
            makeButtonsUnEnable();
            ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
            break;
        case tractWin2:
            qTimer->start(2000);
            database->data_CCU->VT_MT2_ST=1;
            makeButtonsUnEnable();
            ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
            break;
        case machinWind1:
            qTimer->start(2000);
            database->data_CCU->VT_SM1_ST=1;
            makeButtonsUnEnable();
            ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
            break;
        case machinWind2:
            qTimer->start(2000);
            database->data_CCU->VT_SM2_ST=1;
            makeButtonsUnEnable();
            ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
            break;

    }


}

void Main_AssistantDevice::updateSet()
{
    database->data_CCU->CPR_TEST=0;
    database->data_CCU->VT_BM1_ST=0;
    database->data_CCU->VT_BM2_ST=0;
    database->data_CCU->VT_MT1_ST=0;
    database->data_CCU->VT_MT2_ST=0;
    database->data_CCU->VT_SM1_ST=0;
    database->data_CCU->VT_SM2_ST=0;
    makeButtonsEnable();
}


void Main_AssistantDevice::makeButtonsUnEnable()
{
    foreach (QPushButton *button, funcButtons) {
        button->setEnabled(false);
    }
}

void Main_AssistantDevice::makeButtonsEnable()
{
    foreach (QPushButton *button, funcButtons) {
        button->setEnabled(true);
        button->setStyleSheet(BUTTONRELEASE);
    }
}
