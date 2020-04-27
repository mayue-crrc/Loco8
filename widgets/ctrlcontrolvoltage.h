#ifndef CTRLCONTROLVOLTAGE_H
#define CTRLCONTROLVOLTAGE_H

#include <QWidget>

namespace Ui {
class CtrlControlVoltage;
}

class CtrlControlVoltage : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlControlVoltage(QWidget *parent = 0 ,int yellow1 = 120, int yellow2 = 50,
                                int red1 = 170, int red2 = 40);
    ~CtrlControlVoltage();
    void setCtrlValueRect(int value1,int value2);
private:
    Ui::CtrlControlVoltage *ui;
    int m_yellowline1,m_yellowline2,m_redline1,m_redline2;
};

#endif // CTRLCONTROLVOLTAGE_H
