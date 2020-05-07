#ifndef MAIN_380_H
#define MAIN_380_H
#include "mybase.h"

#include <QWidget>

namespace Ui {
class Main_380;
}

class Main_380 : public MyBase
{
    Q_OBJECT

public:
    explicit Main_380(QWidget *parent = 0);
    ~Main_380();

private:
    Ui::Main_380 *ui;
};

#endif // MAIN_380_H
