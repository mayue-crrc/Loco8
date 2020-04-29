#ifndef CTRLTRAINOUTLINE_H
#define CTRLTRAINOUTLINE_H

#include <QWidget>
#include "global.h"
#include "qpushbutton.h"
#include "qlabel.h"
#include "qstring.h"

#define TRAINMAX 4
#define WIDTH 395
#define HEIGHT 213
#define WIDTHMAX 800
#define HEIGHTMAX 500

namespace Ui {
class CtrlTrainOutLine;
}

class CtrlTrainOutLine : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlTrainOutLine(QWidget *parent = 0);
    ~CtrlTrainOutLine();
//    void updateData(QList<bool>&activation,QList<bool>&direction,QList<bool>&panto,QList<bool>&gaoya,
//                    QList<bool>&zhuduan,QList<bool>&parking,QList<bool>&traction,QList<bool>&brake);
    void updateData(QList<QList<bool > > bo,QList<QList<QString > > str);
    void updateStringData(unsigned short int no,unsigned short int kn);
    void setLBLpic(QLabel *lbl, QList<bool> status,QList<QString> stylestr);
    QList<QLabel* > labels;
private:
    Ui::CtrlTrainOutLine *ui;

};

#endif // CTRLTRAINOUTLINE_H
