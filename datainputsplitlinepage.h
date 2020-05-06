#ifndef DATAINPUTSPLITLINEPAGE_H
#define DATAINPUTSPLITLINEPAGE_H

#include "mybase.h"

namespace Ui {
class DataInputSplitLinePage;
}

class DataInputSplitLinePage : public MyBase
{
    Q_OBJECT

public:
    explicit DataInputSplitLinePage(QWidget *parent = 0);
    ~DataInputSplitLinePage();

private:
    Ui::DataInputSplitLinePage *ui;
};

#endif // DATAINPUTSPLITLINEPAGE_H
