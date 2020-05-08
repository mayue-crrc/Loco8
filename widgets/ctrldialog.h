#ifndef CTRLDIALOG_H
#define CTRLDIALOG_H

#include <QWidget>

namespace Ui {
class CtrlDialog;
}

class CtrlDialog : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlDialog(QWidget *parent = 0);
    ~CtrlDialog();

private slots:
    void on_BTNreturn_clicked();

    void on_BTNOK_clicked();
    void ButtonPressEvent();
    void getpasswordRequest();
private:
    Ui::CtrlDialog *ui;
    QString  m_input;
    int m_btnindex;
signals:
    void passwordResponse();
};

#endif // CTRLDIALOG_H
