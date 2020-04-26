#include "datainputdatetimepage.h"
#include "ui_datainputdatetimepage.h"

DataInputDateTimePage::DataInputDateTimePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataInputDateTimePage)
{
    ui->setupUi(this);
}

DataInputDateTimePage::~DataInputDateTimePage()
{
    delete ui;
}
