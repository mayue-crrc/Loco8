#include "main_separation.h"
#include "ui_main_separation.h"
#include "qdebug.h"

QString Main_Separation::input="";

Main_Separation::Main_Separation(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Separation)
{
    ui->setupUi(this);
    buttons<<ui->PB_N_0<<ui->PB_N_1<<ui->PB_N_2<<ui->PB_N_3
          <<ui->PB_N_4<<ui->PB_N_5<<ui->PB_N_6<<ui->PB_N_7
         <<ui->PB_N_8<<ui->PB_N_9<<ui->PB_N_C;
    foreach(QPushButton* button,buttons)
    {
        connect(button,SIGNAL(pressed()),this,SLOT(numberButtonPressEvent()));
    }

    funCButtons<<ui->PB_T_1<<ui->PB_T_2<<ui->PB_Send;
    foreach (QPushButton* button, funCButtons) {
        connect(button,SIGNAL(pressed()),this,SLOT(functionButtonPressEvent()));
    }



}

Main_Separation::~Main_Separation()
{
    delete ui;
}


void Main_Separation::numberButtonPressEvent()
{

    int number = ((QPushButton *)this->sender())->whatsThis().toInt();
    if(number!=10){
        Main_Separation::input.append(QString::number(number));
        ui->lbl_number->setText(Main_Separation::input);
    }
    else
    {
        ui->lbl_number->setText("");
        Main_Separation::input="";
    }

}

void Main_Separation::functionButtonPressEvent()
{
    int funcEum=((QPushButton *)this->sender())->whatsThis().toInt();

    switch (funcEum)
    {
        case active:


            break;
        case cancel:

            break;
        case send:

            break;
    }

}

void Main_Separation::releaseAllButtons()
{
    foreach (QPushButton* button, funCButtons) {
        button->setStyleSheet(BUTTONRELEASE);
    }
}

void Main_Separation::enableAllButtons()
{
    foreach (QPushButton* button, funCButtons) {
        button->setEnabled(true);
    }
}

void Main_Separation::unEnaleAllButtons()
{
    foreach (QPushButton* button, funCButtons) {
        button->setEnabled(false);
    }
}
