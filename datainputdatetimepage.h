#ifndef DATAINPUTDATETIMEPAGE_H
#define DATAINPUTDATETIMEPAGE_H

#include "mybase.h"

namespace Ui {
class DataInputDateTimePage;
}

class DataInputDateTimePage : public MyBase
{
    Q_OBJECT
    
public:
    explicit DataInputDateTimePage(QWidget *parent = 0);
    ~DataInputDateTimePage();
private:
    Ui::DataInputDateTimePage *ui;    

};

#endif // DATAINPUTDATETIMEPAGE_H
