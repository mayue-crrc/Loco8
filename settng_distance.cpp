#include "settng_distance.h"
#include "ui_settng_distance.h"

Settng_Distance::Settng_Distance(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Distance)
{
    ui->setupUi(this);
}

Settng_Distance::~Settng_Distance()
{
    delete ui;
}
