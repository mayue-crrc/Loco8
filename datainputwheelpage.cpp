#include "datainputwheelpage.h"
#include "ui_datainputwheelpage.h"

DataInputWheelPage::DataInputWheelPage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputWheelPage)
{
    ui->setupUi(this);
}

DataInputWheelPage::~DataInputWheelPage()
{
    delete ui;
}
