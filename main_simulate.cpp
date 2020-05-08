#include "main_simulate.h"
#include "ui_main_simulate.h"

QString Main_Simulate::input1="";
QString Main_Simulate::input2="";

Main_Simulate::Main_Simulate(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Simulate)
{
    ui->setupUi(this);
    buttons<<ui->PB_N_0<<ui->PB_N_1<<ui->PB_N_2<<ui->PB_N_3
          <<ui->PB_N_4<<ui->PB_N_5<<ui->PB_N_6<<ui->PB_N_7
         <<ui->PB_N_8<<ui->PB_N_9<<ui->PB_N_C;
    foreach(QPushButton* button,buttons)
    {
        connect(button,SIGNAL(pressed()),this,SLOT(numberButtonPressEvent()));
    }

    funcButtons<<ui->PB_F_dataSend<<ui->PB_F_isoSwitch<<ui->PB_F_keySwitch<<ui->PB_F_Simulate
              <<ui->PB_F_speedInput<<ui->PB_F_testActive<<ui->PB_F_volInput;
    foreach (QPushButton* button , funcButtons) {
        connect(button,SIGNAL(pressed()),this,SLOT(functionButtonPressEvent()));
    }

    inputFlag=1;
    qTimer=new QTimer(this);
    simulateFlag=false;
    testActiveFlag=false;
    sendFlag=false;
}

Main_Simulate::~Main_Simulate()
{
    delete ui;
}

void Main_Simulate::numberButtonPressEvent()
{
    int number = ((QPushButton *)this->sender())->whatsThis().toInt();
    if(number!=10){
        if(inputFlag==1)
        {
            Main_Simulate::input1.append(QString::number(number));
            ui->lbl_number1->setText(Main_Simulate::input1);
        }
        else if(inputFlag==2)
        {
            Main_Simulate::input2.append(QString::number(number));
            ui->lbl_number2->setText(Main_Simulate::input2);
        }
    }
    else
    {
        if(inputFlag==1)
        {
            ui->lbl_number1->setText("");
            Main_Simulate::input1="";
        }
        else if(inputFlag==2)
        {
            ui->lbl_number2->setText("");
            Main_Simulate::input2="";
        }
        else{}

    }
}

void Main_Simulate::functionButtonPressEvent()
{
    int number=((QPushButton *)this->sender())->whatsThis().toInt();
    switch(number)
    {
    case simulate:
        if(simulateFlag)
        {
            database->data_CCU->SIM_ON=false;
            ui->PB_F_Simulate->setStyleSheet(BUTTONRELEASE);
            simulateFlag=false;
            ui->lbl_SimulatMode->setText("仿真模式：关");
        }
        else
        {
            database->data_CCU->SIM_ON=true;
            ui->PB_F_Simulate->setStyleSheet(BUTTONPRESSED);
            simulateFlag=true;
            ui->lbl_SimulatMode->setText("仿真模式：开");
        }
        break;
    case testActive:
        if(testActiveFlag)
        {
            database->data_CCU->SEQUENCE_TEST=false;
            ui->PB_F_testActive->setStyleSheet(BUTTONRELEASE);
            testActiveFlag=false;
        }
        else
        {
            database->data_CCU->SEQUENCE_TEST=true;
            ui->PB_F_testActive->setStyleSheet(BUTTONPRESSED);
            testActiveFlag=true;
        }
        break;
    case speedInput:
        inputFlag=1;
        ui->PB_F_speedInput->setStyleSheet(BUTTONPRESSED);
        ui->PB_F_volInput->setStyleSheet(BUTTONRELEASE);
        break;
    case volInput:
        inputFlag=2;
        ui->PB_F_volInput->setStyleSheet(BUTTONPRESSED);
        ui->PB_F_speedInput->setStyleSheet(BUTTONRELEASE);
        break;
    case dataSend:
        if(sendFlag)
        {
            database->data_CCU->SIM_LINE_VOLT=0;
            database->data_CCU->SIM_SPEED=0;
            ui->PB_F_dataSend->setStyleSheet(BUTTONRELEASE);
            sendFlag=false;
            ui->PB_F_dataSend->setText("数据发送");
        }
        else
        {
            database->data_CCU->SIM_LINE_VOLT=Main_Simulate::input2.toInt();
            database->data_CCU->SIM_SPEED=Main_Simulate::input1.toInt();
            ui->PB_F_dataSend->setStyleSheet(BUTTONPRESSED);
            sendFlag=true;
            ui->PB_F_dataSend->setText("停止数据发送");
        }

        break;
    case isoSwitch:
        break;
    case keySwitch:
        break;
    }
}
