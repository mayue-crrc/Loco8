#ifndef MAIN_SEPARATION_H
#define MAIN_SEPARATION_H
#include "mybase.h"
#include "qpushbutton.h"

#include <QWidget>

namespace Ui {
class Main_Separation;
}

class Main_Separation : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Separation(QWidget *parent = 0);
    ~Main_Separation();
     QList<QPushButton *> buttons;
     void numberButtonPressEvent();
     static int  textInput ;

private:
    Ui::Main_Separation *ui;

};

#endif // MAIN_SEPARATION_H
