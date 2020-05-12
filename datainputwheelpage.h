#ifndef DATAINPUTWHEELPAGE_H
#define DATAINPUTWHEELPAGE_H

#include "mybase.h"
class ButtonRectUtil;
class QTimer;

namespace Ui {
class DataInputWheelPage;
}

class DataInputWheelPage : public MyBase
{
    Q_OBJECT
    
public:
    explicit DataInputWheelPage(QWidget *parent = 0);
    ~DataInputWheelPage();
    void showEvent(QShowEvent *event);
    
private:
    Ui::DataInputWheelPage *ui;
    ButtonRectUtil *buttonRectUtil;
    QTimer *timer;

private slots:
    /**
    @brief:display the input value in real time
    @param: the button id , equal to the button text value
    */
    void onButtonsClicked(int);
    void onTimerTimeout();
    void on_btnStore_clicked();
};

#endif // DATAINPUTWHEELPAGE_H
