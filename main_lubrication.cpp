#include "main_lubrication.h"
#include "ui_main_lubrication.h"

Main_Lubrication::Main_Lubrication(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Lubrication)
{
    ui->setupUi(this);
}

Main_Lubrication::~Main_Lubrication()
{
    delete ui;
}
