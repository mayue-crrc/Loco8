#include "fault_history.h"
#include "ui_fault_history.h"

Fault_HIstory::Fault_HIstory(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Fault_HIstory)
{
    ui->setupUi(this);
}

Fault_HIstory::~Fault_HIstory()
{
    delete ui;
}
