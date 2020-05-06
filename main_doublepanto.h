#ifndef MAIN_DOUBLEPANTO_H
#define MAIN_DOUBLEPANTO_H
#include "mybase.h"

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

private:
    Ui::Main_DoublePanto *ui;
};

#endif // MAIN_DOUBLEPANTO_H
