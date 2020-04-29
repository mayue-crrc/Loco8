#include "datainputsplitlinepage.h"
#include "ui_datainputsplitlinepage.h"

DataInputSplitLinePage::DataInputSplitLinePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DataInputSplitLinePage)
{
    ui->setupUi(this);
}

DataInputSplitLinePage::~DataInputSplitLinePage()
{
    delete ui;
}
