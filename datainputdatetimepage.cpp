#include "datainputdatetimepage.h"
#include "ui_datainputdatetimepage.h"
#include <QButtonGroup>
#include <QDateTime>
#include <QMap>
#include <QTimer>
enum buttonId
{
    uMPUTime = 0,
    uSYSTime
};

enum timeSetId
{
    uYear = 0,
    uMonth,
    uDay,
    uHour,
    uMinute,
    uSecond
};

DataInputDateTimePage::DataInputDateTimePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputDateTimePage)
{
    ui->setupUi(this);    
    labelList.insert(uYear, ui->labelYear);
    labelList.insert(uMonth, ui->labelMonth);
    labelList.insert(uDay, ui->labelDate);
    labelList.insert(uHour, ui->labelHour);
    labelList.insert(uMinute, ui->labelMinute);
    labelList.insert(uSecond, ui->labelSecond);

    this->timeMinusButtons = new QButtonGroup;
    this->timeMinusButtons->addButton(ui->btnLeftY, uYear);
    this->timeMinusButtons->addButton(ui->btnLeftMonth, uMonth);
    this->timeMinusButtons->addButton(ui->btnLeftD, uDay);
    this->timeMinusButtons->addButton(ui->btnLeftH, uHour);
    this->timeMinusButtons->addButton(ui->btnLeftM, uMinute);
    this->timeMinusButtons->addButton(ui->btnLeftS, uSecond);

    this->timePlusButtons = new QButtonGroup;
    this->timePlusButtons->addButton(ui->btnRightY, uYear);
    this->timePlusButtons->addButton(ui->btnRightMonth, uMonth);
    this->timePlusButtons->addButton(ui->btnRightD, uDay);
    this->timePlusButtons->addButton(ui->btnRightH, uHour);
    this->timePlusButtons->addButton(ui->btnRightM, uMinute);
    this->timePlusButtons->addButton(ui->btnRightS, uSecond);
    connect(this->timeMinusButtons, SIGNAL(buttonClicked(int)),this, SLOT(onTimeMinusSet(int)));
    connect(this->timePlusButtons, SIGNAL(buttonClicked(int)),this, SLOT(onTimePlusSet(int)));

    this->timer = new QTimer;
    this->timer->stop();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));

    ui->btnUpdateTime->setEnabled(true);
}

DataInputDateTimePage::~DataInputDateTimePage()
{
    delete ui;
}

void DataInputDateTimePage::updatePage()
{
    ui->labelMPUTime->setText(QString::number(this->database->data_CCU->YEAR) + ":" + QString::number(this->database->data_CCU->MINUTE) + ":" + QString::number(this->database->data_CCU->SECOND)
                           + "\n" + QString::number(this->database->data_CCU->HOUR) + "-" + QString::number(this->database->data_CCU->MINUTE) + "-" + QString::number(this->database->data_CCU->SECOND));
    ui->labelSystemTime->setText(QDateTime::currentDateTime().toString("hh:mm:ss") + "\n" + QDateTime::currentDateTime().toString("yyyy-MM-dd"));
}

void DataInputDateTimePage::showEvent(QShowEvent *event)
{
    QList<QString> times;
    QList<QLabel*> labels;
    times << QString::number(this->database->data_CCU->YEAR) << QString::number(this->database->data_CCU->MONTH) << QString::number(this->database->data_CCU->DATE)
          << QString::number(this->database->data_CCU->HOUR) << QString::number(this->database->data_CCU->MINUTE) << QString::number(this->database->data_CCU->SECOND);

    labels << ui->labelYear << ui->labelMonth << ui->labelDate << ui->labelHour << ui->labelMinute << ui->labelSecond;
    if (times.size() != labels.size() ||0 == times.size())
    {
        logger()->error("the two lists' sizes are not the same or the size is 0");
        return;
    }
    for (int i = 0; i < times.size(); i++)
    {
        labels[i]->setText(times[i]);
    }
}

void DataInputDateTimePage::onTimeMinusSet(int id)
{
    if (labelList.contains(id))
    {
        int timeValue = labelList[id]->text().toUInt();
        if (timeValue > 0)
        {
            timeValue--;
        }
        int valueTemp = 0;

        //set the upper limit (in case of...)
        switch (id)
        {
        case uYear: valueTemp = 9999; break;
        case uMonth: valueTemp = 12; break;
        case uDay: valueTemp = 31; break;
        case uHour: valueTemp = 23; break;
        case uMinute: case uSecond: valueTemp = 59; break;
        }

        if (timeValue > valueTemp)//in case of
        {
            timeValue = 0;
        }
        labelList[id]->setText(QString::number(timeValue));
    }
    else
    {
        logger()->error("labelList is not has the key ", id);
    }
}

void DataInputDateTimePage::onTimePlusSet(int id)
{
    if (labelList.contains(id))
    {
        int timeValue = labelList[id]->text().toUInt();
        timeValue++;

        int valueTemp = 0;
        //set the upper limit
        switch (id)
        {
        case uYear: valueTemp = 9999; break;
        case uMonth: valueTemp = 12; break;
        case uDay: valueTemp = 31; break;
        case uHour: valueTemp = 23; break;
        case uMinute: case uSecond: valueTemp = 59; break;
        }

        if (timeValue > valueTemp)//in case of
        {
            timeValue = 0;
        }

        labelList[id]->setText(QString::number(timeValue));
    }else
    {
        logger()->error("labelList is not has the key ", id);
    }
}

void DataInputDateTimePage::on_btnUpdateTime_clicked()
{
    if (QDate::isValid(ui->labelYear->text().toUInt(), ui->labelMonth->text().toUInt(), ui->labelDate->text().toUInt())
        && QTime::isValid(ui->labelHour->text().toUInt(), ui->labelMinute->text().toUInt(), ui->labelSecond->text().toUInt()))
    {
        this->database->data_CCU->YEARDDU = ui->labelYear->text().toUInt();
        this->database->data_CCU->MONTHDDU = ui->labelMonth->text().toUInt();
        this->database->data_CCU->DAYDDU = ui->labelDate->text().toUInt();
        this->database->data_CCU->HOURDDU = ui->labelHour->text().toUInt();
        this->database->data_CCU->MINUTEDDU = ui->labelMinute->text().toUInt();
        this->database->data_CCU->SECONDDDU = ui->labelSecond->text().toUInt();

        if (!this->timer->isActive())
        {
            this->timer->start(3000);
            this->database->data_CCU->TIME_SET = true;
            ui->btnUpdateTime->setEnabled(false);
        }
    }
    else
    {
        logger()->error("the date time is not valid," +
                        ui->labelYear->text() + "-" + ui->labelMonth->text() + "-" + ui->labelDate->text() + "\n"
                        + ui->labelHour->text() + ":" + ui->labelMinute->text() + ":" + ui->labelSecond->text());
        showInfo("时间格式错误，请确认后再输入。");
    }
}

void DataInputDateTimePage::showInfo(QString info)
{
    ui->labelInfo->setText(info);
}

void DataInputDateTimePage::onTimerTimeout()
{
    this->database->data_CCU->TIME_SET = false;
    this->timer->stop();
    ui->btnUpdateTime->setEnabled(true);
    showInfo("时间设置成功");
}
