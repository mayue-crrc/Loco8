#include "ctrlnetvoltage.h"
#include "ui_ctrlnetvoltage.h"

CtrlNetVoltage::CtrlNetVoltage(QWidget *parent, int green1 , int green2,
                               int red1 , int red2, int blue ) :
    QWidget(parent),
    m_greenline1(green1),
    m_greenline2(green2),
    m_redline1(red1),
    m_redline2(red2),
    m_blueline(blue),
    ui(new Ui::CtrlNetVoltage)
{
    ui->setupUi(this);


}

CtrlNetVoltage::~CtrlNetVoltage()
{
    delete ui;
}
void CtrlNetVoltage::setCtrlValueRect(int value)
{
    if(value > 32000)
        value = 32000;
    ui->LBLValueRect->setGeometry(36,31,ui->LBLValueRect->width(),320-(float)value/1000*10);
    ui->LBLValue->setText(QString::number((float)value/1000,10,1));
}
