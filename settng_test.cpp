#include "settng_test.h"
#include "ui_settng_test.h"

Settng_Test::Settng_Test(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Test)
{
    ui->setupUi(this);
}

Settng_Test::~Settng_Test()
{
    delete ui;
}
