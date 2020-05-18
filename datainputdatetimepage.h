#ifndef DATAINPUTDATETIMEPAGE_H
#define DATAINPUTDATETIMEPAGE_H

#include "mybase.h"
class QButtonGroup;
class QTimer;
namespace Ui {
class DataInputDateTimePage;
}

class DataInputDateTimePage : public MyBase
{
    Q_OBJECT
    
public:
    explicit DataInputDateTimePage(QWidget *parent = 0);
    ~DataInputDateTimePage();
    void updatePage();
    void showEvent(QShowEvent *event);
    void showInfo(QString info);
private:
    Ui::DataInputDateTimePage *ui;    

    QButtonGroup *timeMinusButtons, *timePlusButtons;
    QMap<int, QLabel*> labelList;
    QTimer *timer;
private slots:

    /**
    @brief:triggered when minus buttons clicked
    @param:timeMinusButtons id
    */
    void onTimeMinusSet(int);
    /**
    @brief:triggered when plus buttons clicked
    @param:timePlusButtons id
    */
    void onTimePlusSet(int);
    void on_btnUpdateTime_clicked();
    void onTimerTimeout();
};

#endif // DATAINPUTDATETIMEPAGE_H
