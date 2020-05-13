#include "datainputother.h"
#include "ui_datainputother.h"
#include "buttonrectutil.h"
#include <QButtonGroup>
#include <QTimer>

enum Mode
{
    uNormalMode = 0,
    uSummerMode
};

DataInputOther::DataInputOther(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputOther)
{
    ui->setupUi(this);
    this->buttonRectUtil = new ButtonRectUtil(this);
    connect(this->buttonRectUtil->inputButtons, SIGNAL(buttonClicked(int)), this, SLOT(onButtonsClicked(int)));
    this->buttonRectUtil->setGeometry(460, 80, this->buttonRectUtil->width(), this->buttonRectUtil->height());
    this->buttonRectUtil->show();
    this->timer = new QTimer;
    this->timer->stop();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));

    //set Mode
    this->modeGroup = new QButtonGroup;
    this->modeGroup->addButton(ui->btnNormalMode, uNormalMode);
    this->modeGroup->addButton(ui->btnSummerMode, uSummerMode);
    this->modeGroup->setExclusive(true);
    connect(this->modeGroup, SIGNAL(buttonClicked(int)), this, SLOT(onModeClicked(int)));

    ui->btnStore->setEnabled(true);
}

DataInputOther::~DataInputOther()
{
    delete ui;
}

void DataInputOther::showEvent(QShowEvent *)
{
    if (this->database->data_CCU->NORMAL_MODE && this->database->data_CCU->SUMMER_MODE)
    {
        //will not happen under normal circumstances
        modeGroup->button(uNormalMode)->setStyleSheet(NButtonUP);
        modeGroup->button(uSummerMode)->setStyleSheet(NButtonUP);
    }
    else if (this->database->data_CCU->NORMAL_MODE)
    {
        modeGroup->button(uNormalMode)->setStyleSheet(NButtonDOWN);
        modeGroup->button(uSummerMode)->setStyleSheet(NButtonUP);
    }
    else if (this->database->data_CCU->SUMMER_MODE)
    {
        modeGroup->button(uNormalMode)->setStyleSheet(NButtonUP);
        modeGroup->button(uSummerMode)->setStyleSheet(NButtonDOWN);
    }
    else
    {
        //will not happen under normal circumstances
        modeGroup->button(uNormalMode)->setStyleSheet(NButtonUP);
        modeGroup->button(uSummerMode)->setStyleSheet(NButtonUP);
    }
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
    //set buttons styles
    modeGroup->button(uNormalMode)->setStyleSheet(NButtonUP);
    modeGroup->button(uSummerMode)->setStyleSheet(NButtonUP);
    modeGroup->button(mode)->setStyleSheet(NButtonDOWN);

    if (uNormalMode == mode)
    {
        this->database->data_CCU->NORMAL_MODEDDU = true;
        this->database->data_CCU->SUMMER_MODE = false;
    }
    else if (uSummerMode == mode)
    {
        this->database->data_CCU->NORMAL_MODEDDU = false;
        this->database->data_CCU->SUMMER_MODE = true;
    }
}

void DataInputOther::on_btnStore_clicked()
{
    this->database->data_CCU->LOADDDU = ui->labelInput->text().toUInt();

    if (!this->timer->isActive())
    {
        this->timer->start(3000);
        this->database->data_CCU->LOAD_SET = true;
        ui->btnStore->setEnabled(false);
    }
}

void DataInputOther::onTimerTimeout()
{
    this->database->data_CCU->LOAD_SET = false;
    this->timer->stop();
    ui->btnStore->setEnabled(true);

}

void DataInputOther::updatePage()
{
    if (this->database->data_CCU->NORMAL_MODE && this->database->data_CCU->SUMMER_MODE)
    {
        //will not happen under normal circumstances
        ui->labelInfo->setText("模式冲突");
    }
    else if (this->database->data_CCU->NORMAL_MODE)
    {
        ui->labelInfo->setText("冬季模式");
    }
    else if (this->database->data_CCU->SUMMER_MODE)
    {
        ui->labelInfo->setText("夏季模式");
    }
    else
    {
        //will not happen under normal circumstances
        ui->labelInfo->setText("无");
    }
    //update load
    ui->labelCurrentValue->setText(QString::number(this->database->data_CCU->LOAD));
}
