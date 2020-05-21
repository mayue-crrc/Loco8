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

void Settng_Distance::updatePage()
{
    this->ui->LBL_MSCount->setText(QString::number(this->database->data_CCU->MCB_ON_COUNTER));
    this->ui->LBL_ResetDis->setText(QString::number(this->database->data_CCU->TRIP_COUNTER));
    this->ui->LBL_TotalDis->setText(QString::number(this->database->data_CCU->TOTAL_DISTANCE));
}

void Settng_Distance::on_BTN_Reset_pressed()
{
    this->database->data_CCU->MILEAGE_RESET = true;
    resetTimer = startTimer(3000);
    this->ui->BTN_Reset->setStyleSheet(NButtonDOWN);
}

void Settng_Distance::timerEvent(QTimerEvent *)
{
    killTimer(resetTimer);
    this->database->data_CCU->MILEAGE_RESET = false;
    this->ui->BTN_Reset->setStyleSheet(NButtonUP);
}

void Settng_Distance::hideEvent(QHideEvent *)
{
    this->database->data_CCU->MILEAGE_RESET = false;
}
