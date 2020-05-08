#include "main_doublepanto.h"
#include "ui_main_doublepanto.h"

Main_DoublePanto::Main_DoublePanto(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_DoublePanto)
{
    ui->setupUi(this);
    funcButtons<<ui->BP_Active<<ui->BP_Unactive;
    foreach (QPushButton* button, funcButtons) {
        connect(button,SIGNAL(pressed()),this,SLOT(funcButtonPressEvent()));
    }

    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(updateSet()));
}

Main_DoublePanto::~Main_DoublePanto()
{
    delete ui;
}

void Main_DoublePanto::funcButtonPressEvent()
{
    int number=((QPushButton *)this->sender())->whatsThis().toInt();
    switch (number) {
    case active:
        database->data_CCU->DOUBLE_PG_ON=1;
        qTimer->start(2000);
        unEnaleAllButtons();
        ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
        break;
    case cancel:
        database->data_CCU->DOUBLE_PG_OFF=1;
        qTimer->start(2000);
        unEnaleAllButtons();
        ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
        break;
    }
}

void Main_DoublePanto::updateSet()
{
    database->data_CCU->DOUBLE_PG_ON=0;
    database->data_CCU->DOUBLE_PG_OFF=0;
    releaseAllButtons();
    enableAllButtons();
}

void Main_DoublePanto::updatePage()
{
    //ui->lbl_information->setStyleSheet();
}

void Main_DoublePanto::releaseAllButtons()
{
    ui->BP_Active->setStyleSheet(BUTTONRELEASE);
    ui->BP_Unactive->setStyleSheet(BUTTONRELEASE);
}

void Main_DoublePanto::enableAllButtons()
{
    ui->BP_Active->setEnabled(true);
    ui->BP_Unactive->setEnabled(true);
}

void Main_DoublePanto::unEnaleAllButtons()
{
    ui->BP_Active->setEnabled(false);
    ui->BP_Unactive->setEnabled(false);
}
