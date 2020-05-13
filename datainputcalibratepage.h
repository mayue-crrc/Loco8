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
    void showInfo(bool show);

private slots:
    void on_btnCalibrate_clicked();

    void on_btnYes_clicked();

    void on_btnCancel_clicked();

private:
    Ui::DataInputCalibratePage *ui;

};

#endif // DATAINPUTCALIBRATEPAGE_H
