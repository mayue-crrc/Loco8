#ifndef MYBASE_H
#define MYBASE_H

#include "global.h"
#include <QWidget>
#include "database.h"
#include "log4qt/logger.h"

#include "qlabel.h"
class MyBase : public QWidget
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit MyBase(QWidget *parent = 0);
    void setMyBase(enum pagePosition position, QString name);
    virtual void updatePage();
    virtual void updateLanguage();
    virtual void processKeyboardEvent(keyboardIndex k);

public:
    static int currentPage;
    static Database *database;
    QString name;
    enum pagePosition Position;
    void setLBLtext(QLabel *lbl, int value,  float dem = 1,unsigned char scale = 0);
    void setVLBLtext(QLabel *lbl,  bool vaild,int value, float dem = 1,unsigned char scale = 0);
    void setLBLpic(QLabel *lbl, QList<bool> &status,QList<QString> &stylestr);
    void setLBLpic(QLabel *lbl, bool status,QString stylestr);
public slots:
signals:
    void changePage(int);
};

#endif // MYBASE_H
