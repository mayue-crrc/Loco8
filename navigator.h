#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QWidget>
#include "mybase.h"
#include "QPushButton"
namespace Ui {
    class Navigator;
}

class Navigator : public MyBase
{
    Q_OBJECT

public:
    explicit Navigator(QWidget *parent = 0);
    ~Navigator();
    void updateLanguage();
    void setPageName(QString name);
    void updatePage();
private:
    Ui::Navigator *ui;
    QList<QPushButton*>buttons,buttons2;
    QList<pageIndex >buttonIndexList,button2IndexList;
    QList<QString >buttonNameList,button2NameList;
    int m_ButtonIndex;
    enum pagePosition m_position,m_oldposition;
private slots:
    void NBpressEvent();
    void N2BpressEvent();
signals:
    void translateLanguage();

};

#endif // NAVIGATOR_H
