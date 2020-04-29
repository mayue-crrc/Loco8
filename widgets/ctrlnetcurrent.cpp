#include "ctrlnetcurrent.h"
#include "ui_ctrlnetcurrent.h"

CtrlNetCurrent::CtrlNetCurrent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlNetCurrent)
{
    ui->setupUi(this);
}

CtrlNetCurrent::~CtrlNetCurrent()
{
    delete ui;
}
void CtrlNetCurrent::setCtrlValueRect(int value)
{
    if(value > 620)
        value = 620;
    ui->LBLValueRect->setGeometry(36,31,ui->LBLValueRect->width(),320-(float)value*320/620);
    ui->LBLValue->setText(QString::number(value));
}
