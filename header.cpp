#include "header.h"
#include "ui_header.h"
#include "qdatetime.h"
#include "qdebug.h"
#include "crrcfault.h"
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
    static int blinkcounter = 0;
    if(CrrcFault::getCrrcFault()->getConfirmFaultListSize() > 0)
    {
        ui->BTNCurrentfault->setText(CrrcFault::getCrrcFault()->getConfirmFaultName(0));
        if(blinkcounter++%2)
        {
            ui->BTNCurrentfault->setStyleSheet("background-color:red;");
        }else
        {
            ui->BTNCurrentfault->setStyleSheet("background-color:black;");
        }
    }else
    {
        ui->BTNCurrentfault->setText("当前无未确认故障");
        ui->BTNCurrentfault->setStyleSheet("background-color:black;");
    }
}
void Header::updateLanguage()
{
    this->ui->retranslateUi(this);
}

void Header::on_BTNCurrentfault_clicked()
{
    changePage(uFault_Detail);
}
