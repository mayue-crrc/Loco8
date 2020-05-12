#include "datainputcalibratepage.h"
#include "ui_datainputcalibratepage.h"


DataInputCalibratePage::DataInputCalibratePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputCalibratePage)
{
    ui->setupUi(this);
    showInfo(false);
}

DataInputCalibratePage::~DataInputCalibratePage()
{
    delete ui;
}

void DataInputCalibratePage::showInfo(bool show)
{
    if (show)
    {
        ui->labelInfo->show();
        ui->btnYes->show();
        ui->btnCancel->show();
    }
    else
    {
        ui->labelInfo->hide();
        ui->btnYes->hide();
        ui->btnCancel->hide();
    }
}

void DataInputCalibratePage::on_btnCalibrate_clicked()
{
    showInfo(true);
    ui->btnCalibrate->setEnabled(false);
}

void DataInputCalibratePage::on_btnYes_clicked()
{
    //system("...");
    showInfo(false);
    ui->btnCalibrate->setEnabled(true);
}


void DataInputCalibratePage::on_btnCancel_clicked()
{
    showInfo(false);
    ui->btnCalibrate->setEnabled(true);
}
