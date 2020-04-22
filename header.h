#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include "mybase.h"

namespace Ui {
    class Header;
}

class Header : public MyBase
{
    Q_OBJECT

public:
    explicit Header(QWidget *parent = 0);
    void updatePage();

    void updateLanguage();

    ~Header();

private:
    Ui::Header *ui;

};

#endif // HEADER_H
