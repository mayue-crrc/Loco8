#include "main_380.h"
#include "ui_main_380.h"

Main_380::Main_380(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_380)
{
    ui->setupUi(this);
}

Main_380::~Main_380()
{
    delete ui;
}
