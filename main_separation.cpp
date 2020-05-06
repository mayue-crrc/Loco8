#include "main_separation.h"
#include "ui_main_separation.h"
#include "qdebug.h"

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

}

Main_Separation::~Main_Separation()
{
    delete ui;
}


void Main_Separation::numberButtonPressEvent()
{
    qDebug()<<"1111";
}
