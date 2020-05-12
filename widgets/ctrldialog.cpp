#include "ctrldialog.h"
#include "ui_ctrldialog.h"
#include "MainGetDefaultPara.h"
CtrlDialog::CtrlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CtrlDialog)
{
    ui->setupUi(this);
    QList<QPushButton *> buttons;

    buttons<<ui->btn0<<ui->btn1<<ui->btn2<<ui->btn3<<ui->btn4<<ui->btn5<<ui->btn6<<ui->btn7<<ui->btn8
            <<ui->btn9<<ui->btnClear;
    foreach(QPushButton* button,buttons)
    {
        connect(button,SIGNAL(clicked()),this,SLOT(ButtonPressEvent()));
    }

    m_input = "";
    this->ui->LBLTips->hide();
}

CtrlDialog::~CtrlDialog()
{
    delete ui;
}

void CtrlDialog::on_BTNreturn_clicked()
{
    this->hide();
}

void CtrlDialog::on_BTNOK_clicked()
{
    if(m_input == MainGetDefaultPara::getString("/Password/Password"))
    {
        m_input.clear();
        ui->LBLinput->clear();
        passwordResponse(m_btnindex);
        this->hide();
    }else
    {
        this->ui->LBLTips->show();
    }
}
void CtrlDialog::ButtonPressEvent()
{
    this->ui->LBLTips->hide();

    //(   (QPushButton *)this->sender())->setStyleSheet(PButtonUP);
    QString key = ((QPushButton *)this->sender())->whatsThis();
    QString text = ((QPushButton *)this->sender())->text();
    if(text == "清除")
    {
        m_input = m_input.left(m_input.size()-1);
    }else
    {
        m_input =m_input + key;
    }
    ui->LBLinput->setText(m_input);

}
void CtrlDialog::getpasswordRequest(pageIndex p)
{
    m_btnindex = p;
    this->exec();
}
