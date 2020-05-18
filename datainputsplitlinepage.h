#ifndef DATAINPUTSPLITLINEPAGE_H
#define DATAINPUTSPLITLINEPAGE_H

#include "mybase.h"
class QButtonGroup;
namespace Ui {
class DataInputSplitLinePage;
}

class DataInputSplitLinePage : public MyBase
{
    Q_OBJECT

public:
    explicit DataInputSplitLinePage(QWidget *parent = 0);
    ~DataInputSplitLinePage();
    void showEvent(QShowEvent *event);

    void updatePage();
private:
    Ui::DataInputSplitLinePage *ui;
    QButtonGroup *modeButton;

    int mode;
private slots:
    void onModeButtonClicked(int);
    void on_btnConfirm_clicked();
};

#endif // DATAINPUTSPLITLINEPAGE_H
