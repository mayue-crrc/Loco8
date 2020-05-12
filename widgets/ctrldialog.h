#ifndef CTRLDIALOG_H
#define CTRLDIALOG_H

#include <QDialog>
#include "global.h"
namespace Ui {
class CtrlDialog;
}

class CtrlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CtrlDialog(QWidget *parent = 0);
    ~CtrlDialog();

private slots:
    void on_BTNreturn_clicked();

    void on_BTNOK_clicked();
    void ButtonPressEvent();
    void getpasswordRequest(pageIndex p);
private:
    Ui::CtrlDialog *ui;
    QString  m_input;
    pageIndex m_btnindex;
signals:
    void passwordResponse(pageIndex p);
};

#endif // CTRLDIALOG_H
