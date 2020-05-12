#include "datainputwheelpage.h"
#include "ui_datainputwheelpage.h"
#include "buttonrectutil.h"
#include <QButtonGroup>
#include <QTimer>

class ButtonRectUtil;

DataInputWheelPage::DataInputWheelPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputWheelPage)
{
    ui->setupUi(this);
    this->buttonRectUtil = new ButtonRectUtil(this);
    this->buttonRectUtil->setGeometry(336,170,this->buttonRectUtil->width(),this->buttonRectUtil->height());
    connect(this->buttonRectUtil->inputButtons, SIGNAL(buttonClicked(int)), this, SLOT(onButtonsClicked(int)));
    this->timer = new QTimer;
    this->timer->stop();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
    ui->btnStore->setEnabled(true);
}

DataInputWheelPage::~DataInputWheelPage()
{
    delete ui;
}

void DataInputWheelPage::showEvent(QShowEvent *event)
{
    ui->labelCurrentValue->setText(QString::number(this->database->data_CCU->WHEEL_DIA));
}

void DataInputWheelPage::onButtonsClicked(int buttonId)
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

void DataInputWheelPage::on_btnStore_clicked()
{
    this->database->data_CCU->WHEEL_DIADDU = ui->labelInput->text().toUInt();

    if (!this->timer->isActive())
    {
        this->database->data_CCU->WHEEL_DIA_SET = true;
        this->timer->start(3000);
        ui->btnStore->setEnabled(false);
    }

}

void DataInputWheelPage::onTimerTimeout()
{
    this->database->data_CCU->WHEEL_DIA_SET = false;
    this->timer->stop();
    ui->btnStore->setEnabled(true);
    ui->labelCurrentValue->setText(QString::number(this->database->data_CCU->WHEEL_DIA));
}
