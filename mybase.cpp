#include "mybase.h"

MyBase::MyBase(QWidget *parent) :
    QWidget(parent)
{
    if (parent != NULL)
    {
        connect(this, SIGNAL(changePage(int)), parent, SLOT(changePage(int)));
    }
}

int MyBase::currentPage = uVehicleRunStatePage;
Database *MyBase::database = NULL;

void MyBase::setMyBase(pagePosition position, QString name)
{
    if (position == uTop)
    {
        this->setGeometry(0, 0, this->width(), this->height());
    }
    else if (position == uMiddle)
    {
        this->setGeometry(0, 125, this->width(), this->height());
    }
    else if (position == uBottom)
    {
        this->setGeometry(0, 550, this->width(), this->height());
    }
    else if (position == uHuge)
    {
        this->setGeometry(0, 0, this->width(), this->height());
    }else if (position == uMiddleMainPage ||
              position == uMiddleTrainData ||
              position == uMiddleControl ||
              position == uMiddleBrake ||
              position == uMiddleDeviceData ||
              position == uMiddleSetting ||
              position == uMiddleMain ||
              position == uMiddleFault)
    {
        this->setGeometry(0, 125, this->width(), this->height());
    }
    this->name = name;
    this->Position = position;

    this->hide();
}
void MyBase::updateLanguage()
{

}
void MyBase::updatePage()
{

}
void MyBase::processKeyboardEvent(keyboardIndex k)
{

}
