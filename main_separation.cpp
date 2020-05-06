#include "main_separation.h"
#include "ui_main_separation.h"

Main_Separation::Main_Separation(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Separation)
{
    ui->setupUi(this);
}

Main_Separation::~Main_Separation()
{
    delete ui;
}
