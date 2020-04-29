#include "datainputcalibratepage.h"
#include "ui_datainputcalibratepage.h"


DataInputCalibratePage::DataInputCalibratePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputCalibratePage)
{
    ui->setupUi(this);

}

DataInputCalibratePage::~DataInputCalibratePage()
{
    delete ui;
}


