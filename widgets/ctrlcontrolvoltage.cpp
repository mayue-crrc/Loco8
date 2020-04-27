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
void CtrlControlVoltage::setCtrlValueRect(int value1,int value2)
{
    if(value1 > 130)
        value1 = 130;
    if(value2 > 130)
        value2 = 130;

    ui->LBLValueRect->setGeometry(51,31,ui->LBLValueRect->width(),320-(float)value1*320/130);
    ui->LBLValue->setText(QString::number(value1));

    ui->LBLValueRect2->setGeometry(106,31,ui->LBLValueRect2->width(),320-(float)value2*320/130);
    ui->LBLValue2->setText(QString::number(value2));
}
