#include "main_lubrication.h"
#include "ui_main_lubrication.h"

Main_Lubrication::Main_Lubrication(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Lubrication)
{
    ui->setupUi(this);
    funcButtons<<ui->BP_Running<<ui->BP_Cancel;
    foreach (QPushButton* button, funcButtons) {
        connect(button,SIGNAL(pressed()),this,SLOT(funcButtonPressEvent()));
    }

    qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(updateSet()));
}

Main_Lubrication::~Main_Lubrication()
{
    delete ui;
}

void Main_Lubrication::funcButtonPressEvent()
{
    int number=((QPushButton *)this->sender())->whatsThis().toInt();
    switch (number) {
    case active:
        database->data_CCU->FLL_TEST_START=1;
        qTimer->start(2000);
        unEnaleAllButtons();
        ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
        break;
    case cancel:
        database->data_CCU->FLL_TEST_CANCEL=1;
        qTimer->start(2000);
        unEnaleAllButtons();
        ((QPushButton *)this->sender())->setStyleSheet(BUTTONPRESSED);
        break;
    }
}

void Main_Lubrication::updateSet()
{
    database->data_CCU->FLL_TEST_START=0;
    database->data_CCU->FLL_TEST_CANCEL=0;
    releaseAllButtons();
    enableAllButtons();

}

void Main_Lubrication::updatePage()
{
  ui->lbl_information1->setText("返回"+QString::number(database->data_CCU->FLL_SECONDS)+"秒");
}

void Main_Lubrication::releaseAllButtons()
{
    ui->BP_Cancel->setStyleSheet(BUTTONRELEASE);
    ui->BP_Running->setStyleSheet(BUTTONRELEASE);
}

void Main_Lubrication::enableAllButtons()
{
    ui->BP_Cancel->setEnabled(true);
    ui->BP_Running->setEnabled(true);
}

void Main_Lubrication::unEnaleAllButtons()
{
    ui->BP_Cancel->setEnabled(false);
    ui->BP_Running->setEnabled(false);
}
