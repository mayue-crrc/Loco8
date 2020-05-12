#ifndef FAULT_DETAIL_H
#define FAULT_DETAIL_H

#include <mybase.h>

namespace Ui {
class Fault_Detail;
}

class Fault_Detail : public MyBase
{
    Q_OBJECT

public:
    explicit Fault_Detail(QWidget *parent = 0);
    ~Fault_Detail();
    void showEvent(QShowEvent *event);
    void updatePage();
private slots:
    void on_BTNCurrentFault_clicked();

    void on_BTNConfirm_clicked();

private:
    Ui::Fault_Detail *ui;

};

#endif // FAULT_DETAIL_H
