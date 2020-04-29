#ifndef DATAINPUTOTHER_H
#define DATAINPUTOTHER_H

#include "mybase.h"
class ButtonRectUtil;
class QButtonGroup;
namespace Ui {
class DataInputOther;
}

class DataInputOther : public MyBase
{
    Q_OBJECT
    
public:
    explicit DataInputOther(QWidget *parent = 0);
    ~DataInputOther();
    void showEvent(QShowEvent *);
private slots:
    /**
    @brief:display the input value in real time
    @param: the button id , equal to the button text value
    */
    void onButtonsClicked(int);
    /**
    @brief:triggered when change mode
    @param: the button id , equal to the button text value
    */
    void onModeClicked(int);
private:
    Ui::DataInputOther *ui;
    ButtonRectUtil* buttonRectUtil;
};

#endif // DATAINPUTOTHER_H
