#include "settng_panto.h"
#include "ui_settng_panto.h"

Settng_Panto::Settng_Panto(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Panto)
{
    ui->setupUi(this);
    hideAllTrain();
    show1Train();
}

Settng_Panto::~Settng_Panto()
{
    delete ui;
}

void Settng_Panto::updatePage()
{
    show1Train();
}

void Settng_Panto::hideAllTrain()
{
    //2Car1
    this->ui->LBL_2Train1->hide();
    this->ui->LBL_2HS1->hide();
    this->ui->LBL_2PANTO1->hide();
    this->ui->LBL_2Active1->hide();
    //2Car2
    this->ui->LBL_2Train2->hide();
    this->ui->LBL_2HS2->hide();
    this->ui->LBL_2PANTO2->hide();
    this->ui->LBL_2Active2->hide();
    //4Car1
    this->ui->LBL_4Train1->hide();
    this->ui->LBL_4HS1->hide();
    this->ui->LBL_4PANTO1->hide();
    this->ui->LBL_4Active1->hide();
    //4Car2
    this->ui->LBL_4Train2->hide();
    this->ui->LBL_4HS2->hide();
    this->ui->LBL_4PANTO2->hide();
    this->ui->LBL_4Active2->hide();
    //4Car3
    this->ui->LBL_4Train3->hide();
    this->ui->LBL_4HS3->hide();
    this->ui->LBL_4PANTO3->hide();
    this->ui->LBL_4Active3->hide();
    //4Car4
    this->ui->LBL_4Train4->hide();
    this->ui->LBL_4HS4->hide();
    this->ui->LBL_4PANTO4->hide();
    this->ui->LBL_4Active4->hide();
    //TrainButton&Label
    this->ui->BTN_Train1->hide();
    this->ui->BTN_Train2->hide();
    this->ui->BTN_Train3->hide();
    this->ui->BTN_Train4->hide();
    this->ui->LBL_Train1Num->hide();
    this->ui->LBL_Train2Num->hide();
    this->ui->LBL_Train3Num->hide();
    this->ui->LBL_Train4Num->hide();
}

void Settng_Panto::show1Train()
{
    this->ui->LBL_2Train1->show();
    this->ui->LBL_2Train1->setGeometry(255,130,this->ui->LBL_2Train1->width(),this->ui->LBL_2Train1->height());
    this->ui->LBL_2HS1->show();
    this->ui->LBL_2HS1->setGeometry(406,170,this->ui->LBL_2HS1->width(),this->ui->LBL_2HS1->height());
    this->ui->LBL_2PANTO1->show();
    this->ui->LBL_2PANTO1->setGeometry(339,124,this->ui->LBL_2PANTO1->width(),this->ui->LBL_2PANTO1->height());
    this->ui->LBL_2Active1->hide();
    this->ui->LBL_2Active1->setGeometry(299,190,this->ui->LBL_2Active1->width(),this->ui->LBL_2Active1->height());
    this->ui->BTN_Train1->show();
    this->ui->LBL_Train1Num->show();
}
