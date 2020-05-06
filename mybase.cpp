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
        this->setGeometry(0, 115, this->width(), this->height());
    }
    else if (position == uBottom)
    {
        this->setGeometry(0, 560, this->width(), this->height());
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
void MyBase::setLBLtext(QLabel *lbl, int value, float dem,unsigned char scale)
{
    lbl->setText(QString::number((float)value/dem,10,scale));
}
void MyBase::setVLBLtext(QLabel *lbl,  bool valid,int value,float dem,unsigned char scale)
{
    if(valid)
    {
        lbl->setText(QString::number((float)value/dem,10,scale));
    }else
    {
        lbl->setText("--");
    }
}
void MyBase::setLBLpic(QLabel *lbl, QList<bool> &status, QList<QString> &stylestr)
{
    if(status.size() != stylestr.size())
    {
        qDebug()<<"status's size doesnt equal stylestr's size"<<status.size()<<stylestr.size();
        status.clear();
        stylestr.clear();
        return;

    }
    for(int i = 0;i<status.size();i++)
    {
        if(status.at(i))
        {
            lbl->setStyleSheet(stylestr.at(i));
            status.clear();
            stylestr.clear();
            return;
        }
    }
}
void MyBase::setLBLpic(QLabel *lbl, bool status,QString stylestr)
{
    if(status)
    {
        lbl->setStyleSheet(stylestr);
    }else
    {
        lbl->setStyleSheet(BLACK);
    }
}
