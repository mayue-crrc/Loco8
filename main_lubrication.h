#ifndef MAIN_LUBRICATION_H
#define MAIN_LUBRICATION_H
#include "mybase.h"
#include "qtimer.h"
#include "qpushbutton.h"

#include <QWidget>

namespace Ui {
class Main_Lubrication;
}

class Main_Lubrication : public MyBase
{
    Q_OBJECT

public:
    explicit Main_Lubrication(QWidget *parent = 0);
    ~Main_Lubrication();

    enum functionSignal{
        active=1,
        cancel,
    };

    QTimer* qTimer;
    QList<QPushButton*> funcButtons;
    void updatePage();

private:
    Ui::Main_Lubrication *ui;
    void releaseAllButtons();
    void enableAllButtons();
    void unEnaleAllButtons();

private slots:
    void funcButtonPressEvent();
    void updateSet();
};

#endif // MAIN_LUBRICATION_H
