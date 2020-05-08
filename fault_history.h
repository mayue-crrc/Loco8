#ifndef FAULT_HISTORY_H
#define FAULT_HISTORY_H

#include <mybase.h>

namespace Ui {
class Fault_HIstory;
}

class Fault_HIstory : public MyBase
{
    Q_OBJECT

public:
    explicit Fault_HIstory(QWidget *parent = 0);
    ~Fault_HIstory();
    void updatePage();
private slots:
    void on_BTNPre_clicked();

    void on_BTNNext_clicked();

private:
    Ui::Fault_HIstory *ui;
    QList<QList<QLabel*> > m_labels;
    int m_currentPageIndex,m_totalPageIndex,m_totalFaultNum,m_currentPageFaultNum;
    void DrawFaults(int i);
};

#endif // FAULT_HISTORY_H
