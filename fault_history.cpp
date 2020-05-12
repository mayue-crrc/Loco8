#include "fault_history.h"
#include "ui_fault_history.h"
#include "crrcfault.h"
#define MAXCNTPERPAGE 16
#define COLUMN        10

Fault_HIstory::Fault_HIstory(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Fault_HIstory)
{
    ui->setupUi(this);

    m_currentPageIndex  = 1;
    m_totalPageIndex = 1;
    m_currentPageFaultNum = 0;
    m_totalFaultNum = 0;

    QList<QLabel*> tmp;
    tmp<<this->ui->LBLCode1<<this->ui->LBLStarttime1<<this->ui->LBLEndtime1<<this->ui->LBLName1<<this->ui->LBLSpeed1
      <<this->ui->LBLVoltage1<<this->ui->LBLCurrent1<<this->ui->LBLDirection1<<this->ui->LBLGrade1<<this->ui->LBLLevel1;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_2<<this->ui->LBLStarttime1_2<<this->ui->LBLEndtime1_2<<this->ui->LBLName1_2<<this->ui->LBLSpeed1_2
      <<this->ui->LBLVoltage1_2<<this->ui->LBLCurrent1_2<<this->ui->LBLDirection1_2<<this->ui->LBLGrade1_2<<this->ui->LBLLevel1_2;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_3<<this->ui->LBLStarttime1_3<<this->ui->LBLEndtime1_3<<this->ui->LBLName1_3<<this->ui->LBLSpeed1_3
      <<this->ui->LBLVoltage1_3<<this->ui->LBLCurrent1_3<<this->ui->LBLDirection1_3<<this->ui->LBLGrade1_3<<this->ui->LBLLevel1_3;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_4<<this->ui->LBLStarttime1_4<<this->ui->LBLEndtime1_4<<this->ui->LBLName1_4<<this->ui->LBLSpeed1_4
      <<this->ui->LBLVoltage1_4<<this->ui->LBLCurrent1_4<<this->ui->LBLDirection1_4<<this->ui->LBLGrade1_4<<this->ui->LBLLevel1_4;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_5<<this->ui->LBLStarttime1_5<<this->ui->LBLEndtime1_5<<this->ui->LBLName1_5<<this->ui->LBLSpeed1_5
      <<this->ui->LBLVoltage1_5<<this->ui->LBLCurrent1_5<<this->ui->LBLDirection1_5<<this->ui->LBLGrade1_5<<this->ui->LBLLevel1_5;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_6<<this->ui->LBLStarttime1_6<<this->ui->LBLEndtime1_6<<this->ui->LBLName1_6<<this->ui->LBLSpeed1_6
      <<this->ui->LBLVoltage1_6<<this->ui->LBLCurrent1_6<<this->ui->LBLDirection1_6<<this->ui->LBLGrade1_6<<this->ui->LBLLevel1_6;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_7<<this->ui->LBLStarttime1_7<<this->ui->LBLEndtime1_7<<this->ui->LBLName1_7<<this->ui->LBLSpeed1_7
      <<this->ui->LBLVoltage1_7<<this->ui->LBLCurrent1_7<<this->ui->LBLDirection1_7<<this->ui->LBLGrade1_7<<this->ui->LBLLevel1_7;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_8<<this->ui->LBLStarttime1_8<<this->ui->LBLEndtime1_8<<this->ui->LBLName1_8<<this->ui->LBLSpeed1_8
      <<this->ui->LBLVoltage1_8<<this->ui->LBLCurrent1_8<<this->ui->LBLDirection1_8<<this->ui->LBLGrade1_8<<this->ui->LBLLevel1_8;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_9<<this->ui->LBLStarttime1_9<<this->ui->LBLEndtime1_9<<this->ui->LBLName1_9<<this->ui->LBLSpeed1_9
      <<this->ui->LBLVoltage1_9<<this->ui->LBLCurrent1_9<<this->ui->LBLDirection1_9<<this->ui->LBLGrade1_9<<this->ui->LBLLevel1_9;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_10<<this->ui->LBLStarttime1_10<<this->ui->LBLEndtime1_10<<this->ui->LBLName1_10<<this->ui->LBLSpeed1_10
      <<this->ui->LBLVoltage1_10<<this->ui->LBLCurrent1_10<<this->ui->LBLDirection1_10<<this->ui->LBLGrade1_10<<this->ui->LBLLevel1_10;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_11<<this->ui->LBLStarttime1_11<<this->ui->LBLEndtime1_11<<this->ui->LBLName1_11<<this->ui->LBLSpeed1_11
      <<this->ui->LBLVoltage1_11<<this->ui->LBLCurrent1_11<<this->ui->LBLDirection1_11<<this->ui->LBLGrade1_11<<this->ui->LBLLevel1_11;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_12<<this->ui->LBLStarttime1_12<<this->ui->LBLEndtime1_12<<this->ui->LBLName1_12<<this->ui->LBLSpeed1_12
      <<this->ui->LBLVoltage1_12<<this->ui->LBLCurrent1_12<<this->ui->LBLDirection1_12<<this->ui->LBLGrade1_12<<this->ui->LBLLevel1_12;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_13<<this->ui->LBLStarttime1_13<<this->ui->LBLEndtime1_13<<this->ui->LBLName1_13<<this->ui->LBLSpeed1_13
      <<this->ui->LBLVoltage1_13<<this->ui->LBLCurrent1_13<<this->ui->LBLDirection1_13<<this->ui->LBLGrade1_13<<this->ui->LBLLevel1_13;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_14<<this->ui->LBLStarttime1_14<<this->ui->LBLEndtime1_14<<this->ui->LBLName1_14<<this->ui->LBLSpeed1_14
      <<this->ui->LBLVoltage1_14<<this->ui->LBLCurrent1_14<<this->ui->LBLDirection1_14<<this->ui->LBLGrade1_14<<this->ui->LBLLevel1_14;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_15<<this->ui->LBLStarttime1_15<<this->ui->LBLEndtime1_15<<this->ui->LBLName1_15<<this->ui->LBLSpeed1_15
      <<this->ui->LBLVoltage1_15<<this->ui->LBLCurrent1_15<<this->ui->LBLDirection1_15<<this->ui->LBLGrade1_15<<this->ui->LBLLevel1_15;
    m_labels.push_back(tmp);
    tmp.clear();

    tmp<<this->ui->LBLCode1_16<<this->ui->LBLStarttime1_16<<this->ui->LBLEndtime1_16<<this->ui->LBLName1_16<<this->ui->LBLSpeed1_16
      <<this->ui->LBLVoltage1_16<<this->ui->LBLCurrent1_16<<this->ui->LBLDirection1_16<<this->ui->LBLGrade1_16<<this->ui->LBLLevel1_16;
    m_labels.push_back(tmp);
    tmp.clear();
}

Fault_HIstory::~Fault_HIstory()
{
    delete ui;
}
void Fault_HIstory::updatePage()
{
    m_totalFaultNum = CrrcFault::getCrrcFault()->getHistoryFaultListSize();

    if(m_totalFaultNum < 1)
    {
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




void Fault_HIstory::DrawFaults(int i)
{

    QString Num = QString::number(i+(m_currentPageIndex-1)*MAXCNTPERPAGE+1);
    this->m_labels.at(i).at(0)->setText(CrrcFault::getCrrcFault()->getHistoryFaultCode(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(1)->setText(CrrcFault::getCrrcFault()->getHistoryFaultStartDate(i+(m_currentPageIndex-1)*MAXCNTPERPAGE)+" "+
                                        CrrcFault::getCrrcFault()->getHistoryFaultStartTime(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(2)->setText(CrrcFault::getCrrcFault()->getHistoryFaultEndDate(i+(m_currentPageIndex-1)*MAXCNTPERPAGE)+" "+
                                        CrrcFault::getCrrcFault()->getHistoryFaultEndTime(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(3)->setText(CrrcFault::getCrrcFault()->getHistoryFaultName(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(4)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Speed(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(5)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Voltage(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(6)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Current(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(7)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Direction(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(8)->setText(CrrcFault::getCrrcFault()->getHistoryRunData_Grade(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));
    this->m_labels.at(i).at(9)->setText(CrrcFault::getCrrcFault()->getHistoryFaultLevel(i+(m_currentPageIndex-1)*MAXCNTPERPAGE));

}
void Fault_HIstory::on_BTNPre_clicked()
{
    if(m_currentPageIndex>1)
        m_currentPageIndex--;
}

void Fault_HIstory::on_BTNNext_clicked()
{
    if(m_currentPageIndex<m_totalPageIndex)
        m_currentPageIndex++;
}
