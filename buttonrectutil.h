#ifndef BUTTONRECTUTIL_H
#define BUTTONRECTUTIL_H

#include <QWidget>

class QButtonGroup;
namespace Ui {
class ButtonRectUtil;
}

class ButtonRectUtil : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonRectUtil(QWidget *parent = 0);
    ~ButtonRectUtil();
    QButtonGroup *inputButtons;
    int getClearButtonId();

private:
    Ui::ButtonRectUtil *ui;

};

#endif // BUTTONRECTUTIL_H
