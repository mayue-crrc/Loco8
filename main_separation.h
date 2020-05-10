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
     QList<QPushButton *> funCButtons;
    static QString input;


private:
    Ui::Main_Separation *ui;
    enum funcSignal{
        active=11,
        cancel,
        send,
    };

    void releaseAllButtons();
    void enableAllButtons();
    void unEnaleAllButtons();

private slots:
    void numberButtonPressEvent();
    void functionButtonPressEvent();

};

#endif // MAIN_SEPARATION_H
