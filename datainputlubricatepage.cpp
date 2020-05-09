#include "datainputlubricatepage.h"
#include "ui_datainputlubricatepage.h"
#include "buttonrectutil.h"
#include <QButtonGroup>
#include <QTimer>

enum setGroupID
{
    setTime = 0,
    setDistance
};

DataInputLubricatePage::DataInputLubricatePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputLubricatePage)
{
    ui->setupUi(this);
    this->buttonRectUtil = new ButtonRectUtil(this);
    connect(this->buttonRectUtil->inputButtons, SIGNAL(buttonClicked(int)), this, SLOT(onButtonsClicked(int)));
    this->buttonRectUtil->setGeometry(296, 150, this->buttonRectUtil->width(), this->buttonRectUtil->height());
    this->buttonRectUtil->show();

    //the buttonGroup of the two SET buttons;
    this->setButtonGroup = new QButtonGroup;
    this->setButtonGroup->addButton(ui->btnSetTime, setTime);
    this->setButtonGroup->addButton(ui->btnSetDistance, setDistance);
    this->setButtonGroup->setExclusive(true);
    connect(this->setButtonGroup, SIGNAL(buttonClicked(int)),this, SLOT(onSetGroupClicked(int)));
    // set time default
    this->currentSetId = setTime;
    onSetGroupClicked(setTime);
    ui->labelInput->setText(QString::number(this->database->data_CCU->FLL_TIME));

    this->timer = new QTimer;
    this->timer->stop();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
}

DataInputLubricatePage::~DataInputLubricatePage()
{
    delete ui;
}

void DataInputLubricatePage::showEvent(QShowEvent *)
{
    ui->labelSetTime->setText(QString::number(this->database->data_CCU->FLL_TIME));
    ui->labelSetDistance->setText(QString::number(this->database->data_CCU->FLL_DIS_STRAIGHT));
}

void DataInputLubricatePage::onButtonsClicked(int buttonId)
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

void DataInputLubricatePage::onSetGroupClicked(int setId)
{
    if (!this->setButtonGroup->button(setId))
    {
        logger()->error("the select id is invalid;");
    }
    else
    {
        for (int i = 0; i < this->setButtonGroup->buttons().size(); i++)
        {
            this->setButtonGroup->button(i)->setStyleSheet(NButtonUP);
        }
        this->setButtonGroup->button(setId)->setStyleSheet(NButtonDOWN);
        this->currentSetId = setId;
    }
}

void DataInputLubricatePage::on_btnStore_clicked()
{
    if (setTime == this->currentSetId)
    {
        //sent time value
        this->database->data_CCU->FLL_TIMEDDU = ui->labelInput->text().toInt();
    }
    else if (setDistance == this->currentSetId)
    {
        //set distance value and sign
        this->database->data_CCU->FLL_DIS = ui->labelInput->text().toInt();
    }
    this->database->data_CCU->FLL_SET = true;
    ui->labelSetTime->setText(QString::number(this->database->data_CCU->FLL_TIME));
    ui->labelSetDistance->setText(QString::number(this->database->data_CCU->FLL_DIS_STRAIGHT));
}

void DataInputLubricatePage::onTimerTimeout()
{

}
