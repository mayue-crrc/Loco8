#include "settng_bypass.h"
#include "ui_settng_bypass.h"

Settng_Bypass::Settng_Bypass(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Bypass)
{
    ui->setupUi(this);
    this->ui->setBox->hide();
}

Settng_Bypass::~Settng_Bypass()
{
    delete ui;
}
