#include "main_simulate.h"
#include "ui_main_simulate.h"

Main_Simulate::Main_Simulate(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Simulate)
{
    ui->setupUi(this);
}

Main_Simulate::~Main_Simulate()
{
    delete ui;
}
