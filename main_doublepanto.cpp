#include "main_doublepanto.h"
#include "ui_main_doublepanto.h"

Main_DoublePanto::Main_DoublePanto(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_DoublePanto)
{
    ui->setupUi(this);
}

Main_DoublePanto::~Main_DoublePanto()
{
    delete ui;
}
