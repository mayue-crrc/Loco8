#include "fault_current.h"
#include "ui_fault_current.h"

Fault_Current::Fault_Current(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Fault_Current)
{
    ui->setupUi(this);
}

Fault_Current::~Fault_Current()
{
    delete ui;
}
