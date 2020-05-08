#include "main_380.h"
#include "ui_main_380.h"

Main_380::Main_380(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_380)
{
    ui->setupUi(this);
    funcButtons<<ui->PB_Active<<ui->PB_Unactive;
    foreach (QPushButton * button, funcButtons) {
        connect(button,SIGNAL(pressed()),this,SLOT(funcButtonPressEvent()));
    }

    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(upSet()));
    signalLabels<<ui->lbl_1_value<<ui->lbl_2_value<<ui->lbl_3_value
               <<ui->lbl_4_value<<ui->lbl_5_value<<ui->lbl_6_value;
    //signalDatas<<
    //signalNames1<<"正常位"<<""
    //signalNames2

}

Main_380::~Main_380()
{
    delete ui;
}

void Main_380::funcButtonPressEvent()
{
    int number=((QPushButton*)this->sender())->whatsThis().toInt();
    switch(number)
    {
        case active:
        database->data_CCU->DEPOT_380_ACT=1;
        qTimer->start(2000);
        ui->PB_Active->setStyleSheet(BUTTONPRESSED);
        unEnableAllButtons();
        break;
        case unactive:
        database->data_CCU->DEPOT_380_DEACT=1;
        qTimer->start(2000);
        ui->PB_Unactive->setStyleSheet(BUTTONPRESSED);
        unEnableAllButtons();
        break;
    }
}

void Main_380::upSet()
{
    database->data_CCU->DEPOT_380_ACT=0;
    database->data_CCU->DEPOT_380_DEACT=0;
    releaseAllButtons();
    enEnableAllButtons();
}

void Main_380::updatePage()
{

}

void Main_380::releaseAllButtons()
{
    ui->PB_Active->setStyleSheet(BUTTONRELEASE);
    ui->PB_Unactive->setStyleSheet(BUTTONRELEASE);
}

void Main_380::unEnableAllButtons()
{
    ui->PB_Active->setEnabled(false);
    ui->PB_Unactive->setEnabled(false);
}

void Main_380::enEnableAllButtons()
{
    ui->PB_Active->setEnabled(true);
    ui->PB_Unactive->setEnabled(true);
}

void Main_380::updateSignal(QList<QLabel *> labels, QList<bool> datas, QList<QString> names1,QList<QString> names2)
{
    if((labels.length()!=datas.length())&&(labels.length()!=names1.length())&&(labels.length()!=names2.length()))
        return ;

    for(int i=0;i<labels.length();i++)
    {
        if(datas.at(i))
        {
            labels.at(i)->setText(names1.at(i));
        }
        else
        {
            labels.at(i)->setText(names2.at(i));
        }
    }

}
