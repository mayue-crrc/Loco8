#ifndef CTRLNETVOLTAGE_H
#define CTRLNETVOLTAGE_H

#include <QWidget>

namespace Ui {
class CtrlNetVoltage;
}

class CtrlNetVoltage : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlNetVoltage(QWidget *parent = 0, int green1 = 120, int green2 = 50,
                            int red1 = 170, int red2 = 40, int blue = 160);
    ~CtrlNetVoltage();
    void setCtrlValueRect(int value);
private:
    Ui::CtrlNetVoltage *ui;
    int m_greenline1,m_greenline2,m_redline1,m_redline2,m_blueline;
};

#endif // CTRLNETVOLTAGE_H
