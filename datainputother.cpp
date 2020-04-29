#include "datainputother.h"
#include "ui_datainputother.h"
#include "buttonrectutil.h"

DataInputOther::DataInputOther(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputOther)
{
    ui->setupUi(this);
    this->buttonRectUtil = new ButtonRectUtil(this);
    connect(this->buttonRectUtil->inputButtons, SIGNAL(buttonClicked(int)), this, SLOT(onButtonsClicked(int)));
    this->buttonRectUtil->setGeometry(460, 80, this->buttonRectUtil->width(), this->buttonRectUtil->height());
    this->buttonRectUtil->show();
}

DataInputOther::~DataInputOther()
{
    delete ui;
}

void DataInputOther::showEvent(QShowEvent *)
{

}

void DataInputOther::onButtonsClicked(int buttonId)
{
    if (buttonId == this->buttonRectUtil->getClearButtonId())
    {
        ui->labelInput->setText("");
    }
    else
    {
        QString text = ui->labelInput->text();
        ui->labelInput->setText(text.append(QString::number(buttonId)));
    }
}

void DataInputOther::onModeClicked(int mode)
{

}
