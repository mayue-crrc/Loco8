#include "buttonrectutil.h"
#include "ui_buttonrectutil.h"
#include <QButtonGroup>

enum buttonId
{
    number0 = 0,
    number1,
    number2,
    number3,
    number4,
    number5,
    number6,
    number7,
    number8,
    number9,
    numberClear
};

ButtonRectUtil::ButtonRectUtil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonRectUtil)
{
    ui->setupUi(this);
    this->inputButtons = new QButtonGroup;
    this->inputButtons->addButton(ui->btn0, number0);
    this->inputButtons->addButton(ui->btn1, number1);
    this->inputButtons->addButton(ui->btn2, number2);
    this->inputButtons->addButton(ui->btn3, number3);
    this->inputButtons->addButton(ui->btn4, number4);
    this->inputButtons->addButton(ui->btn5, number5);
    this->inputButtons->addButton(ui->btn6, number6);
    this->inputButtons->addButton(ui->btn7, number7);
    this->inputButtons->addButton(ui->btn8, number8);
    this->inputButtons->addButton(ui->btn9, number9);
    this->inputButtons->addButton(ui->btnClear, numberClear);
    this->inputButtons->setExclusive(true);
}

int ButtonRectUtil::getClearButtonId()
{
    return numberClear;
}

ButtonRectUtil::~ButtonRectUtil()
{
    delete ui;
}
