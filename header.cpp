#include "header.h"
#include "ui_header.h"
#include "qdatetime.h"
#include "qdebug.h"
Header::Header(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Header)
{
    ui->setupUi(this);
}

Header::~Header()
{
    delete ui;
}
void Header::updatePage()
{
}
void Header::updateLanguage()
{
    this->ui->retranslateUi(this);
}
