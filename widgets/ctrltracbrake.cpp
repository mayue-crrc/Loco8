#include "ctrltracbrake.h"
#include "ui_ctrltracbrake.h"
#include "global.h"
CtrlTracBrake::CtrlTracBrake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlTracBrake)
{
    ui->setupUi(this);
}

CtrlTracBrake::~CtrlTracBrake()
{
    delete ui;
}
void CtrlTracBrake::setCtrlValueRect(int value)
{
    int t_value = value/10-100;
    QString t_style;
    if(t_value>0)
    {
        t_style = DARKBLUE;
        ui->LBLStatus->setStyleSheet(QIANYIN);
    }else if(t_value<0)
    {
        t_style = RED;
        ui->LBLStatus->setStyleSheet(ZHIDONG);
    }
    else
    {
        t_style = BLACK;
        ui->LBLStatus->setStyleSheet("");
    }
    ui->LBLBackground->setStyleSheet(t_style);

    t_value = (t_value < 0) ?(-t_value):t_value;
    if(t_value > 100 )
        t_value = 100;

    ui->LBLValueRect->setGeometry(36,31,ui->LBLValueRect->width(),320-(float)t_value*320/100);
    ui->LBLValue->setText(QString::number((float)t_value,10,1));
}
