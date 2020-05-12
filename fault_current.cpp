#include "fault_current.h"
#include "ui_fault_current.h"
#include "crrcfault.h"

#define MAXCNTPERPAGE 16
#define COLUMN        5
Fault_Current::Fault_Current(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Fault_Current)
{
    ui->setupUi(this);

    m_currentPageIndex  = 1;
    m_totalPageIndex = 1;
    m_currentPageFaultNum = 0;
    m_totalFaultNum = 0;

    QList<QLabel*> tmp;
    tmp<<this->ui->LBLCode1<<this->ui->LBLStarttime1<<this->ui->LBLName1<<this->ui->LBLLevel1<<ui->LBLConfirm1;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_2<<this->ui->LBLStarttime1_2<<this->ui->LBLName1_2<<this->ui->LBLLevel1_2<<ui->LBLConfirm2;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_3<<this->ui->LBLStarttime1_3<<this->ui->LBLName1_3<<this->ui->LBLLevel1_3<<ui->LBLConfirm3;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_4<<this->ui->LBLStarttime1_4<<this->ui->LBLName1_4<<this->ui->LBLLevel1_4<<ui->LBLConfirm4;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_5<<this->ui->LBLStarttime1_5<<this->ui->LBLName1_5<<this->ui->LBLLevel1_5<<ui->LBLConfirm5;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_6<<this->ui->LBLStarttime1_6<<this->ui->LBLName1_6<<this->ui->LBLLevel1_6<<ui->LBLConfirm6;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_7<<this->ui->LBLStarttime1_7<<this->ui->LBLName1_7<<this->ui->LBLLevel1_7<<ui->LBLConfirm7;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_8<<this->ui->LBLStarttime1_8<<this->ui->LBLName1_8<<this->ui->LBLLevel1_8<<ui->LBLConfirm8;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_9<<this->ui->LBLStarttime1_9<<this->ui->LBLName1_9<<this->ui->LBLLevel1_9<<ui->LBLConfirm9;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_10<<this->ui->LBLStarttime1_10<<this->ui->LBLName1_10<<this->ui->LBLLevel1_10<<ui->LBLConfirm10;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_11<<this->ui->LBLStarttime1_11<<this->ui->LBLName1_11<<this->ui->LBLLevel1_11<<ui->LBLConfirm11;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_12<<this->ui->LBLStarttime1_12<<this->ui->LBLName1_12<<this->ui->LBLLevel1_12<<ui->LBLConfirm12;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_13<<this->ui->LBLStarttime1_13<<this->ui->LBLName1_13<<this->ui->LBLLevel1_13<<ui->LBLConfirm13;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_14<<this->ui->LBLStarttime1_14<<this->ui->LBLName1_14<<this->ui->LBLLevel1_14<<ui->LBLConfirm14;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_15<<this->ui->LBLStarttime1_15<<this->ui->LBLName1_15<<this->ui->LBLLevel1_15<<ui->LBLConfirm15;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_16<<this->ui->LBLStarttime1_16<<this->ui->LBLName1_16<<this->ui->LBLLevel1_16<<ui->LBLConfirm16;
    m_labels.push_back(tmp);
    tmp.clear();
}

Fault_Current::~Fault_Current()
{
    delete ui;
}
void Fault_Current::updatePage()
{
    m_totalFaultNum = CrrcFault::getCrrcFault()->getCurrentFaultListSize();

    if(m_totalFaultNum < 1)
    {
        for(int i = 0; i < MAXCNTPERPAGE; i++)
        {
            for(int j = 0;j<COLUMN;j++)
            {
                m_labels.at(i).at(j)->setText("");
            }
        }
        return ;
    }

    if(m_totalFaultNum%MAXCNTPERPAGE == 0)
    {
        m_totalPageIndex = m_totalFaultNum/MAXCNTPERPAGE;
        m_currentPageFaultNum = MAXCNTPERPAGE;
    }
    else
    {
        m_totalPageIndex = m_totalFaultNum/MAXCNTPERPAGE+1;
        if(m_currentPageIndex<m_totalPageIndex)
        {
            m_currentPageFaultNum = MAXCNTPERPAGE;
        }else
        {
            m_currentPageFaultNum = m_totalFaultNum%MAXCNTPERPAGE;
        }
    }

    if(m_currentPageIndex > m_totalPageIndex)
        m_currentPageIndex = m_totalPageIndex;

    this->ui->LBLCurrentpage->setText(QString::number(m_currentPageIndex));
    this->ui->LBLTotalpage->setText(QString::number(m_totalPageIndex));
    if(m_currentPageIndex < m_totalPageIndex)
    {
        for(int i = 0; i < MAXCNTPERPAGE;i++)
        {
            this->DrawFaults(i);
        }

    }else
    {
        for(int i = 0; i < MAXCNTPERPAGE; i++)
        {
            if(i < m_currentPageFaultNum)
            {
                this->DrawFaults(i);
            }else
            {
                for(int j = 0;j<COLUMN;j++)
                {
                    m_labels.at(i).at(j)->setText("");

                }
            }

        }
    }

}

void Fault_Current::DrawFaults(int i)
{

    QString Num = QString::number(i+(m_currentPageIndex-1)*MAXCNTPERPAGE+1);
    this->m_labels.at(i).at(0)->setText(CrrcFault::getCrrcFault()->getCurrentFaultCode(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(1)->setText(CrrcFault::getCrrcFault()->getCurrentFaultDate(i+(m_currentPageIndex-1)*MAXCNTPERPAGE)+" "+
                                        CrrcFault::getCrrcFault()->getCurrentFaultTime(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));

    this->m_labels.at(i).at(2)->setText(CrrcFault::getCrrcFault()->getCurrentFaultName(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));

    this->m_labels.at(i).at(3)->setText(CrrcFault::getCrrcFault()->getCurrentFaultLevel(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(4)->setText(CrrcFault::getCrrcFault()->getCurrentFaultConfirm(i+(m_currentPageIndex-1)*MAXCNTPERPAGE) ? "已确认":"未确认");


}
void Fault_Current::on_BTNPre_clicked()
{
    if(m_currentPageIndex>1)
        m_currentPageIndex--;
}

void Fault_Current::on_BTNNext_clicked()
{
    if(m_currentPageIndex<m_totalPageIndex)
        m_currentPageIndex++;
}
