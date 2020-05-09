#include "datainputwheelpage.h"
#include "ui_datainputwheelpage.h"
#include "buttonrectutil.h"
#include <QButtonGroup>
#include <QTimer>

class ButtonRectUtil;

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
