#include "datainputother.h"
#include "ui_datainputother.h"

DataInputOther::DataInputOther(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataInputOther)
{
    ui->setupUi(this);
}

DataInputOther::~DataInputOther()
{
    delete ui;
}
