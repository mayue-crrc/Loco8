#ifndef MAIN_DOUBLEPANTO_H
#define MAIN_DOUBLEPANTO_H
#include "mybase.h"
#include "qpushbutton.h"
#include "qtimer.h"

#include <QWidget>

namespace Ui {
class Main_DoublePanto;
}

class Main_DoublePanto : public MyBase
{
    Q_OBJECT

public:
    explicit Main_DoublePanto(QWidget *parent = 0);
    ~Main_DoublePanto();
    enum functionSignal{
        active=1,
        cancel,
    };
    QTimer* qTimer;
    QList<QPushButton*> funcButtons;
    void updatePage();

private:
    Ui::Main_DoublePanto *ui;
    void releaseAllButtons();
    void enableAllButtons();
    void unEnaleAllButtons();

private slots:
    void funcButtonPressEvent();
    void updateSet();
};

#endif // MAIN_DOUBLEPANTO_H
