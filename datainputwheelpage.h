#ifndef DATAINPUTWHEELPAGE_H
#define DATAINPUTWHEELPAGE_H

#include "mybase.h"

namespace Ui {
class DataInputWheelPage;
}

class DataInputWheelPage : public MyBase
{
    Q_OBJECT
    
public:
    explicit DataInputWheelPage(QWidget *parent = 0);
    ~DataInputWheelPage();
    
private:
    Ui::DataInputWheelPage *ui;
};

#endif // DATAINPUTWHEELPAGE_H
