#include "maindata_trainoutline.h"
#include "ui_maindata_trainoutline.h"

MainData_TrainOutline::MainData_TrainOutline(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::MainData_TrainOutline)
{
    ui->setupUi(this);
}

MainData_TrainOutline::~MainData_TrainOutline()
{
    delete ui;
}
