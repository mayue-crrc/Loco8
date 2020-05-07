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

void Fault_HIstory::on_BTNPre_clicked()
{

}

void Fault_HIstory::on_BTNNext_clicked()
{

}
