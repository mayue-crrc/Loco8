#ifndef MAIN_ASSISTANTDEVICE_H
#define MAIN_ASSISTANTDEVICE_H
#include "mybase.h"

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

private:
    Ui::Main_AssistantDevice *ui;
};

#endif // MAIN_ASSISTANTDEVICE_H
