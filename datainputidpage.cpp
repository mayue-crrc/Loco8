#include "datainputidpage.h"
#include "ui_datainputidpage.h"

DataInputIDPage::DataInputIDPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataInputIDPage)
{
    ui->setupUi(this);
}

DataInputIDPage::~DataInputIDPage()
{
    delete ui;
}
