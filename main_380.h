#ifndef MAIN_380_H
#define MAIN_380_H
#include "mybase.h"
#include "qtimer.h"
#include "qpushbutton.h"
#include "qlabel.h"

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
    QTimer* qTimer;
    QList<QPushButton *> funcButtons;
    QList<QLabel *> signalLabels;
    QList<bool> signalDatas;
    QList<QString> signalNames1;
    QList<QString> signalNames2;

    enum funcNumber{
        active=1,
        unactive,
    };
    void updatePage();


private:
    Ui::Main_380 *ui;
    void releaseAllButtons();
    void unEnableAllButtons();
    void enEnableAllButtons();
    void updateSignal(QList<QLabel *> labels,QList<bool> datas,QList<QString> names1,QList<QString> names2);

private slots:
   void funcButtonPressEvent();
   void upSet();
   };

#endif // MAIN_380_H
