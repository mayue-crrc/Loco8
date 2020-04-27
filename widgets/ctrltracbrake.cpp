#include "ctrltracbrake.h"
#include "ui_ctrltracbrake.h"

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
void CtrlTracBrake::setCtrlValueRect(int value, bool trac, bool brake)
{
    QString t_style;
    if(trac)
    {
        t_style = DARKBLUE;
    }else if(brake)
    {
        t_style = RED;
    }
    else
    {
        return;
    }
    ui->LBLBackground->setStyleSheet(t_style);

    if(value > 100)
        value = 100;
    ui->LBLValueRect->setGeometry(36,31,ui->LBLValueRect->width(),320-(float)value*320/100);
    ui->LBLValue->setText(QString::number(value));
}
