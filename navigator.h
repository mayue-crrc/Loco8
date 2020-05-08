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
    bool m_CurrentMainMode;//0:normal  1:maintanence
    enum pagePosition m_position,m_oldposition;
private slots:
    void NBpressEvent();
    void N2BpressEvent();

    void getpasswordResponse();
signals:
    void translateLanguage();
    void passwordRequest();

};

#endif // NAVIGATOR_H
