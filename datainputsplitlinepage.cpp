#include "datainputsplitlinepage.h"
#include "ui_datainputsplitlinepage.h"
#include <QButtonGroup>

enum modeId
{
    uNormal = 0,
    uFreight,
    uFault
};

DataInputSplitLinePage::DataInputSplitLinePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputSplitLinePage)
{
    ui->setupUi(this);
    this->modeButton = new QButtonGroup;
    this->modeButton->addButton(ui->btnNormalLine, uNormal);
    this->modeButton->addButton(ui->btnFreightLine, uFreight);
    this->modeButton->setExclusive(true);
    connect(this->modeButton, SIGNAL(buttonClicked(int)), this, SLOT(onModeButtonClicked(int)));
    ui->btnConfirm->setEnabled(true);
    this->mode = 0;
}

DataInputSplitLinePage::~DataInputSplitLinePage()
{
    delete ui;
}

void DataInputSplitLinePage::showEvent(QShowEvent *event)
{
    if (this->database->data_CCU->NSC_DISTANCE1 && this->database->data_CCU->NSC_DISTANCE2)
    {
        modeButton->button(uNormal)->setStyleSheet(NButtonUP);
        modeButton->button(uFreight)->setStyleSheet(NButtonUP);
        this->mode = uFault;
    }
    else if (this->database->data_CCU->NSC_DISTANCE1)
    {        
        modeButton->button(uNormal)->setStyleSheet(NButtonDOWN);
        modeButton->button(uFreight)->setStyleSheet(NButtonUP);
        this->mode = uNormal;
    }
    else if (this->database->data_CCU->NSC_DISTANCE2)
    {
        modeButton->button(uNormal)->setStyleSheet(NButtonUP);
        modeButton->button(uFreight)->setStyleSheet(NButtonDOWN);
        this->mode = uFreight;
    }
    else
    {
        modeButton->button(uNormal)->setStyleSheet(NButtonUP);
        modeButton->button(uFreight)->setStyleSheet(NButtonUP);
        this->mode = uFault;
    }
}

void DataInputSplitLinePage::onModeButtonClicked(int id)
{
    modeButton->button(uNormal)->setStyleSheet(NButtonUP);
    modeButton->button(uFreight)->setStyleSheet(NButtonUP);
    modeButton->button(id)->setStyleSheet(NButtonDOWN);    
}

void DataInputSplitLinePage::updatePage()
{
    if (this->database->data_CCU->NSC_DISTANCE1 && this->database->data_CCU->NSC_DISTANCE2)
    {
        ui->labelMode->setText("模式冲突");
    }
    else if (this->database->data_CCU->NSC_DISTANCE1)
    {
        ui->labelMode->setText("常规线路");
    }
    else if (this->database->data_CCU->NSC_DISTANCE2)
    {
        ui->labelMode->setText("货运专线");
    }
    else
        ui->labelMode->setText("无");
}

void DataInputSplitLinePage::on_btnConfirm_clicked()
{
    if (uNormal == this->mode)
    {
        this->database->data_CCU->NSC_DISTANCE1DDU  = true;
        this->database->data_CCU->NSC_DISTANCE2DDU = false;
    }
    else if (uFreight == this->mode)
    {
        this->database->data_CCU->NSC_DISTANCE1DDU  = false;
        this->database->data_CCU->NSC_DISTANCE2DDU = true;
    }
    this->database->data_CCU->NSC_SET = true;
}
