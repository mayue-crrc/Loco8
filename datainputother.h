#ifndef DATAINPUTOTHER_H
#define DATAINPUTOTHER_H

#include <QWidget>

namespace Ui {
class DataInputOther;
}

class DataInputOther : public QWidget
{
    Q_OBJECT
    
public:
    explicit DataInputOther(QWidget *parent = 0);
    ~DataInputOther();
    
private:
    Ui::DataInputOther *ui;
};

#endif // DATAINPUTOTHER_H
