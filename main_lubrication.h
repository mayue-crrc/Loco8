#ifndef MAIN_LUBRICATION_H
#define MAIN_LUBRICATION_H
#include "mybase.h"

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

private:
    Ui::Main_Lubrication *ui;
};

#endif // MAIN_LUBRICATION_H
