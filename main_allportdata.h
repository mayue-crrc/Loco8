#ifndef MAIN_ALLPORTDATA_H
#define MAIN_ALLPORTDATA_H

#include <mybase.h>
#include "qpushbutton.h"
namespace Ui {
class Main_Allportdata;
}

class Main_Allportdata : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Allportdata(QWidget *parent = 0);
    ~Main_Allportdata();
    void updatePage();
private:
    Ui::Main_Allportdata *ui;
    QList <int>m_PortsList;
    QList <int> RIOMPorts,TCN1Ports,TCN2Ports,TCN3Ports,TCN4Ports,TCUPorts,HMIPorts,OtherPorts;
    QList<QPushButton*> buttons;
    void paintEvent(QPaintEvent *event);
private slots:
    void ButtonsPressEvent();
};

#endif // MAIN_ALLPORTDATA_H
