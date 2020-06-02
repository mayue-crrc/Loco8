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

void Settng_Test::on_BTN_LightTest_pressed()
{
    this->ui->BTN_LightTest->setStyleSheet(NButtonDOWN);
    testTimer = startTimer(3000);
    this->database->data_CCU->LAMP_TEST = true;
}

void Settng_Test::timerEvent(QTimerEvent *)
{
    killTimer(testTimer);
    this->ui->BTN_LightTest->setStyleSheet(NButtonUP);
    this->database->data_CCU->LAMP_TEST = false;
}

void Settng_Test::hideEvent(QHideEvent *)
{
    this->database->data_CCU->LAMP_TEST = false;
}

