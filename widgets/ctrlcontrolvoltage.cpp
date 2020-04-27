#include "ctrlcontrolvoltage.h"
#include "ui_ctrlcontrolvoltage.h"

CtrlControlVoltage::CtrlControlVoltage(QWidget *parent,int yellow1,int yellow2,int red1,int red2) :
    QWidget(parent),
    m_yellowline1(yellow1),
    m_yellowline2(yellow2),
    m_redline1(red1),
    m_redline2(red2),

    ui(new Ui::CtrlControlVoltage)
{
    ui->setupUi(this);
}

CtrlControlVoltage::~CtrlControlVoltage()
{
    delete ui;
}
void CtrlControlVoltage::setCtrlValueRect(int value)
{
    if(value > 1300)
        value = 1300;


    ui->LBLValueRect->setGeometry(41,31,ui->LBLValueRect->width(),320-(float)value/10*320/130);
    ui->LBLValue->setText(QString::number((float)value/10,10,1));
}
