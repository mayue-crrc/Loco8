#include "datainputdatetimepage.h"
#include "ui_datainputdatetimepage.h"

DataInputDateTimePage::DataInputDateTimePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputDateTimePage)
{
    ui->setupUi(this); 
}

DataInputDateTimePage::~DataInputDateTimePage()
{
    delete ui;
}
