#ifndef FAULT_CURRENT_H
#define FAULT_CURRENT_H

#include <mybase.h>

namespace Ui {
class Fault_Current;
}

class Fault_Current : public MyBase
{
    Q_OBJECT

public:
    explicit Fault_Current(QWidget *parent = 0);
    ~Fault_Current();
    void updatePage();
private slots:
    void on_BTNPre_clicked();

    void on_BTNNext_clicked();

private:
    Ui::Fault_Current *ui;
    QList<QList<QLabel*> > m_labels;
    int m_currentPageIndex,m_totalPageIndex,m_totalFaultNum,m_currentPageFaultNum;
    void DrawFaults(int i);
};

#endif // FAULT_CURRENT_H
