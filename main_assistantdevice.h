#ifndef MAIN_ASSISTANTDEVICE_H
#define MAIN_ASSISTANTDEVICE_H
#include "mybase.h"
#include "qpushbutton.h"
#include "qtimer.h"

#include <QWidget>

namespace Ui {
class Main_AssistantDevice;
}

class Main_AssistantDevice : public MyBase
{
    Q_OBJECT

public:
    explicit Main_AssistantDevice(QWidget *parent = 0);
    ~Main_AssistantDevice();
    QList<QPushButton *> funcButtons;

private:
    Ui::Main_AssistantDevice *ui;
    QTimer *qTimer;
    void makeButtonsUnEnable();
    void makeButtonsEnable();
    enum textKind{
        mainPresss=1,
        coolWind1,
        coolWind2,
        tractWind1,
        tractWin2,
        machinWind1,
        machinWind2

    };

private slots:
    void  funcButtonPressEvent();
    void  updateSet();
};

#endif // MAIN_ASSISTANTDEVICE_H
