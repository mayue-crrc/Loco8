#ifndef MAINDATA_TRAINOUTLINE_H
#define MAINDATA_TRAINOUTLINE_H

#include <mybase.h>
#include "widgets/ctrltrainoutline.h"
#include "widgets/ctrltrainoutlinereverse.h"

namespace Ui {
class MainData_TrainOutline;
}

class MainData_TrainOutline : public MyBase
{
    Q_OBJECT

public:
    explicit MainData_TrainOutline(QWidget *parent = 0);
    ~MainData_TrainOutline();
    void updatePage();

private:
    Ui::MainData_TrainOutline *ui;
    QList<QList<bool> > allBoolData;
    QList<QList<QString> > allImageData;
    void showTrainData(CtrlTrainOutLine*widget,int n);
    void showTrainData(CtrlTrainOutLineReverse*widget,int n);
    void SetAllData(int n);
};

#endif // MAINDATA_TRAINOUTLINE_H
