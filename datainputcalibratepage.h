#ifndef DATAINPUTCALIBRATEPAGE_H
#define DATAINPUTCALIBRATEPAGE_H

#include "mybase.h"

namespace Ui {
class DataInputCalibratePage;
}

class DataInputCalibratePage : public MyBase
{
    Q_OBJECT

public:
    explicit DataInputCalibratePage(QWidget *parent = 0);
    ~DataInputCalibratePage();

private:
    Ui::DataInputCalibratePage *ui;

};

#endif // DATAINPUTCALIBRATEPAGE_H
