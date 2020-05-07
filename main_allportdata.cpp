#include "main_allportdata.h"
#include "ui_main_allportdata.h"
#include "crrcmvb.h"
#include "qpainter.h"
Main_Allportdata::Main_Allportdata(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Main_Allportdata)
{
    ui->setupUi(this);


    RIOMPorts<<0x200<<0x207<<0x210
            <<0x214<<0x217<<0x220<<0x227
            <<0x208<<0x218<<0x228;

    HMIPorts<<0x700<<0x701<<0x702<<0x703
            <<0x704<<0x710<<0x711<<0x712<<0x713;

    TCN1Ports<<0x600<<0x601<<0x602<<0x603
             <<0x604<<0x605<<0x606<<0x607
             <<0x608<<0x609<<0x60a<<0x60b
             <<0x60c<<0x60d<<0x60e<<0x60f;

    TCN2Ports<<0x610<<0x611<<0x612<<0x613
             <<0x614<<0x615<<0x616<<0x617
             <<0x618<<0x619<<0x61a<<0x61b
             <<0x61c<<0x61d<<0x61e<<0x61f;
    TCN3Ports<<0x620<<0x621<<0x622<<0x623
             <<0x624<<0x625<<0x626<<0x627
             <<0x628<<0x629<<0x62a<<0x62b
             <<0x62c<<0x62d<<0x62e<<0x62f;
    TCN4Ports<<0x630<<0x631<<0x632<<0x633
             <<0x634<<0x635<<0x636<<0x637
             <<0x638<<0x639<<0x63a<<0x63b
             <<0x63c<<0x63d<<0x63e<<0x63f;

    TCUPorts<<0x502<<0x503<<0x400<<0x401<<0x402<<0x410
             <<0x411<<0x412<<0x420<<0x421
             <<0x422<<0x530<<0x531<<0x500<<0x501<<0xfb0;
    OtherPorts<<0x103<<0x104<<0x105<<0x113
            <<0x114<<0x115<<0x136<<0x1f
            <<0x100<<0x110<<0x310<<0x320
            <<0xfc0<<0xfc1<<0xfc2<<0xfc3;



    this->m_PortsList = HMIPorts;
    ui->BTNDDU->setStyleSheet(NButtonDOWN);

    buttons<<ui->BTNDDU<<ui->BTNTCN1<<ui->BTNTCN2<<ui->BTNTCN3<<ui->BTNTCN4<<ui->BTNRIOM<<ui->BTNTCU
           <<ui->BTNOTHER;

    foreach (QPushButton *button, buttons)
    {
        connect(button, SIGNAL(clicked()), this, SLOT(ButtonsPressEvent()));
    }
}

Main_Allportdata::~Main_Allportdata()
{
    delete ui;
}
void Main_Allportdata::updatePage()
{
    this->update();
}
void Main_Allportdata::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QFont font;
    font.setFamily("微软雅黑");
    font.setPixelSize(11);
    painter.setFont(font);
    painter.setPen(QPen(Qt::white,2));
    painter.setBrush(QBrush(Qt::transparent));

    // draw title
    for(int i = 0; i < 34 ; i++)
    {

        QString text1;
        QRect rect1;
        if(i == 0)
        {
            text1 = "port";
            rect1 = QRect(1,2,34,25);
            painter.drawRect(rect1);

        }else if(i == 33)
        {
            text1 = "cycle";
            rect1 = QRect(20*32+35,2,40,25);

        }else
        {
            QString tmp;
            tmp.sprintf("%02d",i-1);
            text1 = tmp;
            rect1 = QRect(i*20+14,2,20,25);

        }


        if(i%2==1)
        {
            painter.drawRect(QRect(i*20+14,2,40,25));
        }
        painter.drawText(rect1,Qt::AlignCenter,text1);

    }



    //draw data
    for(int j = 0 ;j < 16 ;j++)
    {
        for(int i = 0; i < 34 ; i++)
        {
            QString text2;
            QRect rect2,rect3;

            if(j%3 == 0)// set pen color
            {
                painter.setPen(QPen(QColor(255,128,0),2));
            }else if(j%3 == 1)
            {
                painter.setPen(QPen(Qt::lightGray,2));
            }else
            {
                painter.setPen(QPen(QColor(255, 255, 0),2));
            }
            //portaddress
            if(i == 0)
            {
                if(j<m_PortsList.size())
                {
                    QString tmp;
                    tmp.sprintf("%03x",m_PortsList[j]);

                    text2 = tmp.toUpper();
                }else
                {
                    text2 = "";
                }
                rect2 = QRect(1,2+(j+1)*24,34,25);
                painter.drawRect(rect2);
                painter.drawText(rect2,Qt::AlignCenter,text2);
            }else if(i == 33)//cycle
            {
                painter.save();
                painter.setPen(QPen(Qt::white,2));

                if(j<m_PortsList.size())
                {
                    QString tmp;
                    tmp.sprintf("%02d",CrrcMvb::getCrrcMvb()->getPortCycle(m_PortsList[j]));


                    if(CrrcMvb::getCrrcMvb()->isPortTimeout(m_PortsList[j]))
                    {
                        painter.setBrush(QBrush(Qt::red));
                    }else
                    {
                        painter.setBrush(QBrush(Qt::transparent));
                    }
                    text2 = tmp.toUpper();
                }else
                {
                    painter.setBrush(QBrush(Qt::transparent));
                    text2 = "";
                }
                rect2 = QRect(32*20+35,2+(j+1)*24,41,25);

                painter.drawRect(rect2);
                painter.drawText(rect2,Qt::AlignCenter,text2);
                painter.restore();

            }else//data
            {
                QString tmp;

                if(j<m_PortsList.size())
                {
                    tmp.sprintf("%02x",CrrcMvb::getCrrcMvb()->getUnsignedChar(m_PortsList[j],i-1));

                    text2 = tmp.toUpper();
                }else
                {
                    text2 = "";
                }
                rect3 = QRect(i*20+14,2+(j+1)*24,20,25);
                painter.drawText(rect3,Qt::AlignCenter,text2);
            }


            if(i%2==1)
            {
                painter.drawRect(QRect(i*20+14,2+(j+1)*24,40,25));
            }

        }
    }




}
void Main_Allportdata::ButtonsPressEvent()
{
    QString BtnName = ((QPushButton *)this->sender())->text();
    if(BtnName == "DDU")
    {
        this->m_PortsList = HMIPorts;
    }else if(BtnName == "TCN1")
    {
        this->m_PortsList = TCN1Ports;

    }else if(BtnName == "TCN2")
    {
        this->m_PortsList = TCN2Ports;

    }else if(BtnName == "TCN3")
    {
        this->m_PortsList = TCN3Ports;

    }else if(BtnName == "TCN4")
    {
        this->m_PortsList = TCN4Ports;

    }else if(BtnName == "RIOM")
    {
        this->m_PortsList = RIOMPorts;

    }else if(BtnName == "TCU")
    {
        this->m_PortsList = TCUPorts;

    }else if(BtnName == "OTHER")
    {
        this->m_PortsList = OtherPorts;

    }


    for(int i = 0; i < buttons.size();i++)
    {
       buttons[i]->setStyleSheet(NButtonUP);
    }
    ((QPushButton *)this->sender())->setStyleSheet(NButtonDOWN);


}
