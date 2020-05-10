#ifndef SETTNG_BYPASS_H
#define SETTNG_BYPASS_H

#include <mybase.h>
#include "QPushButton"

namespace Ui {
class Settng_Bypass;
}

class Settng_Bypass : public MyBase
{
    Q_OBJECT

public:
    explicit Settng_Bypass(QWidget *parent = 0);
    ~Settng_Bypass();
    void updatePage();
    void timerEvent(QTimerEvent *e);

private slots:
    void SelectTrainEvent();
    void TCUListEvent();
    void on_BTN_Close_pressed();
    void on_BTN_HandISO_pressed();
    void on_BTN_ISOCancel_pressed();

    void on_BTN_AutoSandCutout_pressed();

    void on_BTN_CombCutout_pressed();

    void on_BTN_ClearFault_pressed();

private:
    Ui::Settng_Bypass *ui;
    QList<bool> Train1BrkISOstate,Train2BrkISOstate,Train3BrkISOstate,Train4BrkISOstate,
                Train1ISOstate,Train2ISOstate,Train3ISOstate,Train4ISOstate,
                Train1HISOstate,Train2HISOstate,Train3HISOstate,Train4HISOstate;

    QList<bool*> Train1CutSignal,Train2CutSignal,Train3CutSignal,Train4CutSignal,
                 Train1CancelSignal,Train2CancelSignal,Train3CancelSignal,Train4CancelSignal,FaultReset;
    QList<QLabel*> BrkList;
    QList<QPushButton*> TrainSelect,TCUList;
    QList<QString> handISO,notISO;
    int TrainIndex,SelectIndex,timerISO,timerREL,timerResetFault;
    void hideAll();
    void setLabelState(QList<QLabel*> lblList,QList<bool> stateList);
    void setButtonState(QList<QPushButton*> btnList,QList<bool> handISOList,QList<bool> ISOList);
    void setButtonState(QPushButton* btn,bool iso,QString str1,QString str2);


};

#endif // SETTNG_BYPASS_H
