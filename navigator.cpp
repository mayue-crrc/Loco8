#include "navigator.h"
#include "ui_navigator.h"

Navigator::Navigator(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Navigator)
{
    ui->setupUi(this);

    buttons<<this->ui->NButton1<<this->ui->NButton2<<this->ui->NButton3<<this->ui->NButton4<<this->ui->NButton5
            <<this->ui->NButton6<<this->ui->NButton7<<this->ui->NButton8;
    buttons2<<this->ui->N2Button1<<this->ui->N2Button2<<this->ui->N2Button3<<this->ui->N2Button4<<this->ui->N2Button5
            <<this->ui->N2Button6<<this->ui->N2Button7<<this->ui->N2Button8;

    foreach (QPushButton *button, buttons)
    {
        connect(button, SIGNAL(pressed()), this, SLOT(NBpressEvent()));
    }
    foreach (QPushButton *button, buttons2)
    {
        connect(button, SIGNAL(pressed()), this, SLOT(N2BpressEvent()));
    }

    buttonIndexList<<uVehicleRunStatePage<<uMainData_TrainOutline<<uSettng_Bypass<<
                 uBrake_Info<<uDeviceData_TrainOutline<<uDataInputWheelPage<<uMain_Simulate<<uFault_Current;


    button2NameList<<""<<""<<""<<""<<""<<""<<""<<"";
    m_oldposition = m_position = uMiddleMainPage;
    m_ButtonIndex = 0;
    m_CurrentMainMode = false;
    QList<QString> t_style;
    t_style<<""<<PINGBAO<<LIANGDUJIANGDI<<LIANGDUZENGJIA<<LIANGDUZIDONG<<QIEHUANYUYAN<<CASHISUOPING<<WEIHU;
    this->ui->NButton1->setStyleSheet(YUNXINGANXIA);
    for(int i = 0;i<buttons2.size();i++)
    {
        buttons2[i]->setText("");
        buttons2[i]->setStyleSheet(t_style.at(i));
    }
}

Navigator::~Navigator()
{
    delete ui;
}
void Navigator::updatePage()
{
    this->ui->LBLDate->setText(QDateTime::currentDateTime().date().toString("yyyy-MM-dd"));
    this->ui->LBLTime->setText(QDateTime::currentDateTime().time().toString("hh:mm:ss"));

    if(!m_CurrentMainMode)
    {
        buttons[5]->setDisabled(true);
        buttons[6]->setDisabled(true);
        buttons[7]->setDisabled(true);
        buttons[5]->setText("");
        buttons[6]->setText("");
        buttons[7]->setText("");

    }else
    {
        buttons[5]->setDisabled(false);
        buttons[6]->setDisabled(false);
        buttons[7]->setDisabled(false);
        buttons[5]->setText("数据输入");
        buttons[6]->setText("维护测试");
        buttons[7]->setText("故障浏览");

    }
}
void Navigator::setPageName(QString name)
{
    this->ui->LBLPagename->setText(name);
}
void Navigator::NBpressEvent()
{

    m_ButtonIndex = ((QPushButton *)this->sender())->whatsThis().toInt();
    for(int i = 0; i < buttons.size();i++)
    {
        buttons[i]->setStyleSheet(NButtonUP);
    }

    this->ui->NButton1->setStyleSheet(YUNXING);
    buttonNameList.clear();
    buttonIndexList.clear();
    //m_ButtonIndex的值和position的枚举一致，在这里直接switch m_ButtonIndex
    m_position = (pagePosition)m_ButtonIndex;
    switch (m_position)
    {
        case uMiddleMainPage:
        buttonIndexList<<uVehicleRunStatePage<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL;
        buttonNameList<<"主界面"<<""<<""<<""<<""<<""<<""<<"";
        break;
        case uMiddleTrainData:
        buttonIndexList<<uMainData_TrainOutline<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL;
        buttonNameList<<QString("机车概况")<<""<<""<<""<<""<<""<<""<<"";
        break;
        case uMiddleControl:
        buttonIndexList<<uSettng_Bypass<<uSettng_Panto<<uSettng_Test<<uSettng_Distance<<uNULL<<uNULL<<uNULL<<uNULL;
        buttonNameList<<"隔离"<<"受电弓"<<"运行测试"<<"距离计数"<<""<<""<<""<<"";
        break;
        case uMiddleBrake:
        buttonIndexList<<uBrake_Info<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL;
        buttonNameList<<"空气制动"<<""<<""<<""<<""<<""<<""<<"";
        break;
        case uMiddleDeviceData:
        buttonIndexList<<uDeviceData_TrainOutline<<uDeviceData_TracBrake<<uDeviceData_Breaker<<uDeviceData_ACU
                      <<uDeviceData_Version<<uDeviceData_Online<<uDeviceData_MainConv<<uDeviceData_IO;
        buttonNameList<<"驱动概述"<<"牵引/制动"<<"断路器"<<"辅助"<<"软件版本"<<"在线状态"<<"主变流"<<"信号状态";
        break;
        case uMiddleSetting:
        buttonIndexList<<uDataInputWheelPage<<uDataInputDateTimePage<<uDataInputOther<<uDataInputCalibratePage<<uDataInputLubricatePage<<uDataInputSplitLinePage<<uNULL<<uNULL;
        buttonNameList<<"轮径相关"<<"日期/时间"<<"其他设置"<<"屏幕校准"<<"润滑设定"<<"分相线路"<<""<<"";
        break;
        case uMiddleMain:
        buttonIndexList<<uMain_Simulate<<uMain_Lubrication<<uMain_AssistantDevice<<uMain_380<<uMain_Separation<<uMain_DoublePanto<<uMain_Allportdata<<uNULL;
        buttonNameList<<"仿真测试"<<"轮缘"<<"辅助测试"<<"库内380"<<"过分相\n测试"<<"双弓测试"<<"数据监控"<<"";
        break;
        case uMiddleFault:
        buttonIndexList<<uFault_History<<uFault_Download<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL<<uNULL;
        buttonNameList<<"历史故障"<<"故障下载"<<""<<""<<""<<""<<""<<"";
        break;

        default:
        break;
    }

    QList<QString> t_style;
    t_style<<""<<PINGBAO<<LIANGDUJIANGDI<<LIANGDUZENGJIA<<LIANGDUZIDONG<<QIEHUANYUYAN<<CASHISUOPING<<((m_CurrentMainMode) ? YUNXING:  WEIHU);
    if(m_position == uMiddleMainPage)    //主界面下，二级导航栏不changpage
    {
        this->ui->NButton1->setStyleSheet(YUNXINGANXIA);
        for(int i = 0;i<buttons2.size();i++)
        {
            buttons2[i]->setText("");
            buttons2[i]->setStyleSheet(t_style.at(i));
        }

    }else
    {
        for(int i = 0;i<buttons2.size();i++)
        {
            buttons2[i]->setText(buttonNameList.at(i));
            buttons2[i]->setStyleSheet(NButtonUP);
        }
        ((QPushButton *)this->sender())->setStyleSheet(NButtonDOWN);
        buttons2[0]->setStyleSheet(NButtonDOWN);
    }
    if(buttonIndexList.at(0) == uDataInputWheelPage || buttonIndexList.at(0) == uMain_Separation)
    {
        passwordRequest(buttonIndexList.at(0));
    }else
    {
        changePage(buttonIndexList.at(0));
    }

}
void Navigator::N2BpressEvent()
{
    int btnindex = ((QPushButton *)this->sender())->whatsThis().toInt();
    if(m_position == uMiddleMainPage)    //主界面下，二级导航栏不changpage
    {
//        changePage(buttonIndexList.at(((QPushButton *)this->sender())->whatsThis().toInt()));

        switch(btnindex)
        {
        case 0:
            break;
        case 7:
            if(m_CurrentMainMode)
            {
                m_CurrentMainMode = false;
                ui->N2Button8->setStyleSheet(WEIHU);
            }else
            {
                m_CurrentMainMode = true;
                ui->N2Button8->setStyleSheet(YUNXING);
            }
            break;
        }
    }else
    {
        for(int i = 0; i < buttons2.size();i++)
        {
            buttons2[i]->setStyleSheet(NButtonUP);
        }
        ((QPushButton *)this->sender())->setStyleSheet(NButtonDOWN);

        if(buttonIndexList.at(((QPushButton *)this->sender())->whatsThis().toInt()) == uDataInputWheelPage ||
           buttonIndexList.at(((QPushButton *)this->sender())->whatsThis().toInt()) == uMain_Separation)
        {
            passwordRequest(buttonIndexList.at(((QPushButton *)this->sender())->whatsThis().toInt()));
        }else
        {
            changePage(buttonIndexList.at(((QPushButton *)this->sender())->whatsThis().toInt()));
        }

    }
}

void Navigator::updateLanguage()
{
    this->ui->retranslateUi(this);
}
void Navigator::getpasswordResponse(pageIndex p)
{
    changePage(p);
}
