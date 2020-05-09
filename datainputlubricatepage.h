#ifndef DATAINPUTLUBRICATEPAGE_H
#define DATAINPUTLUBRICATEPAGE_H

#include "mybase.h"
class ButtonRectUtil;
class QButtonGroup;
class QTimer;
namespace Ui {
class DataInputLubricatePage;
}

class DataInputLubricatePage : public MyBase
{
    Q_OBJECT

public:
    explicit DataInputLubricatePage(QWidget *parent = 0);
    ~DataInputLubricatePage();
/**
@brief:the object of keyboard;
*/
    ButtonRectUtil* buttonRectUtil;
    void showEvent(QShowEvent *);

    QTimer *timer;
private slots:
/**
@brief:display the input value in real time
@param: the button id , equal to the button text value
*/
    void onButtonsClicked(int);

/**
 @brief: triggered when change the set buttons
 @param: the button id
 */
    void onSetGroupClicked(int);
    void on_btnStore_clicked();
    void onTimerTimeout();

private:
    Ui::DataInputLubricatePage *ui;
    QButtonGroup* setButtonGroup;
    //records which value to be set
    int currentSetId;
};

#endif // DATAINPUTLUBRICATEPAGE_H
