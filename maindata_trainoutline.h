#ifndef MAINDATA_TRAINOUTLINE_H
#define MAINDATA_TRAINOUTLINE_H

#include <mybase.h>

namespace Ui {
class MainData_TrainOutline;
}

class MainData_TrainOutline : public MyBase
{
    Q_OBJECT

public:
    explicit MainData_TrainOutline(QWidget *parent = 0);
    ~MainData_TrainOutline();

private:
    Ui::MainData_TrainOutline *ui;
};

#endif // MAINDATA_TRAINOUTLINE_H
