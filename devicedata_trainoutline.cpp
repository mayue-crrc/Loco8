#include "devicedata_trainoutline.h"
#include "ui_devicedata_trainoutline.h"

#define NBUTTONDOWN "border-image: url(:/images/images/TrainLogo.png);"
#define NBUTTONDOWNR "border-image: url(:/images/images/TrainLogo-reverse.png);"
#define NBUTTONUP   "border-image: url(:/images/images/TrainLogoUp.png);"
#define NBUTTONUPR   "border-image: url(:/images/images/TrainLogoUp-reverse.png);"

DeviceData_TrainOutline::DeviceData_TrainOutline(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_TrainOutline)
{
    ui->setupUi(this);
    buttons<< ui->NButton1<< ui->NButton2<< ui->NButton3<<ui->NButton4;
    labels<< ui->LBLCode1<< ui->LBLCode2<< ui->LBLCode3<< ui->LBLCode4;

    foreach(QPushButton* button,buttons)
    {
        connect(button,SIGNAL(pressed()),this,SLOT(NBpressEvent()));
        button->hide();
    }
    for(int i =0; i < labels.size(); i++)
    {
        labels.at(i)->hide();
    }
    currentIndex= 0;
}

DeviceData_TrainOutline::~DeviceData_TrainOutline()
{
    delete ui;
}

void DeviceData_TrainOutline::updatePage()
{
    int num = database->data_CCU->RULOCO_NO;
    int vehiclevalue,trainvalue;

    //num = 3;
    for(int i =0; i < buttons.size(); i++)
    {
        if (i < num)
        {
            // 编号
            labels.at(i)->setText("HXD2" + QString::number(database->data_TCN->train[i]->LOCO_NO));
            buttons.at(i)->show();
            labels.at(i)->show();
        }
        else
        {
            buttons.at(i)->hide();
            labels.at(i)->hide();
        }
    }
    //原边电压
    ui->LBL1_1->setText(QString::number(database->data_TCN->train[currentIndex]->NET_VOLT / 128));
    //主变压器温度1
    ui->LBL1_2->setText(QString::number((database->data_TCN->train[currentIndex]->TRANS_TEMP1 + 50) / 2));
    //设定速度[Km/h]:
    //ui->LBL1_3->setText(QString::number(database->data_TCN->train[currentIndex]->ACTUAL_SPEED));
    //原边电流[A]:
    ui->LBL2_1->setText(QString::number(database->data_TCN->train[currentIndex]->NET_CURRENT / 2));
    //主变压器温度2
    ui->LBL2_2->setText(QString::number((database->data_TCN->train[currentIndex]->TRANS_TEMP2 + 50) / 2));
    //实际速度[Km/h]:
    ui->LBL2_3->setText(QString::number(database->data_TCN->train[currentIndex]->ACTUAL_SPEED));
    //原边功率[kW]:
    //ui->LBL3_1->setText(QString::number(database->data_TCN->train[currentIndex]->NET_VOLT));
    //辅助变流器1频率[HZ]:
    ui->LBL3_2->setText(QString::number(database->data_TCN->train[currentIndex]->ACU1_FREQ));
    //辅助变流器2频率[HZ]:
    ui->LBL3_3->setText(QString::number(database->data_TCN->train[currentIndex]->ACU2_FREQ));
    //设定牵引/制动力[kN]:
    ui->LBL4_1->setText(QString::number(database->data_TCN->train[currentIndex]->TOTAL_TE_ACTUAL));

    //主电压[V]:
    ui->LBL5_1->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q1_PRIM_V));
    ui->LBL5_2->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q2_PRIM_V));
    ui->LBL5_3->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q3_PRIM_V));
    ui->LBL5_4->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q4_PRIM_V));
    //主电流[A]:
    ui->LBL6_1->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q1_PRIM_C));
    ui->LBL6_2->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q2_PRIM_C));
    ui->LBL6_3->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q3_PRIM_C));
    ui->LBL6_4->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q4_PRIM_C));
    //中间直流电压[V]:
    ui->LBL7_1->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q1_DC_LINK_V));
    ui->LBL7_1->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q2_DC_LINK_V));
    ui->LBL7_1->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q3_DC_LINK_V));
    ui->LBL7_1->setText(QString::number(database->data_TCN->train[currentIndex]->Q4Q4_DC_LINK_V));
    //冷却液压力[kPa]:
    ui->LBL8_1->setText(QString::number((database->data_TCN->train[currentIndex]->WATER_PRES1 * 25 / 100)));
    ui->LBL8_2->setText(QString::number((database->data_TCN->train[currentIndex]->WATER_PRES2 * 25 / 100)));
    ui->LBL8_3->setText(QString::number((database->data_TCN->train[currentIndex]->WATER_PRES3 * 25 / 100)));
    ui->LBL8_4->setText(QString::number((database->data_TCN->train[currentIndex]->WATER_PRES4 * 25 / 100)));
    //冷却液温度[℃]:
    ui->LBL9_1->setText(QString::number((database->data_TCN->train[currentIndex]->WATER_TEMP1 + 50)));
    ui->LBL9_2->setText(QString::number((database->data_TCN->train[currentIndex]->WATER_TEMP2 + 50)));
    ui->LBL9_3->setText(QString::number((database->data_TCN->train[currentIndex]->WATER_TEMP3 + 50)));
    ui->LBL9_4->setText(QString::number((database->data_TCN->train[currentIndex]->WATER_TEMP4 + 50)));
    //实际牵引力/制动力[kN]:
    //vehiclevalue =

    //ui->LBL10_1->setText(QString::number(database->data_TCN->train[currentIndex]->TE_AXLE1 + 100));
    //ui->LBL10_2->setText(QString::number(database->data_TCN->train[currentIndex]->TE_AXLE1 + 100));
    ui->LBL10_3->setText(QString::number(database->data_TCN->train[currentIndex]->TE_AXLE1 + 100));
    ui->LBL10_4->setText(QString::number(database->data_TCN->train[currentIndex]->TE_AXLE2 + 100));
    ui->LBL10_5->setText(QString::number(database->data_TCN->train[currentIndex]->TE_AXLE3 + 100));
    ui->LBL10_6->setText(QString::number(database->data_TCN->train[currentIndex]->TE_AXLE4 + 100));
    //电机电流[A]:
    //ui->LBL11_1->setText(QString::number(database->data_TCN->train[currentIndex]->TE_AXLE1 + 100));
    //ui->LBL11_2->setText(QString::number(database->data_TCN->train[currentIndex]->TE_AXLE1 + 100));
    ui->LBL11_3->setText(QString::number(database->data_TCN->train[currentIndex]->MOT1_C / 2));
    ui->LBL11_4->setText(QString::number(database->data_TCN->train[currentIndex]->MOT2_C / 2));
    ui->LBL11_5->setText(QString::number(database->data_TCN->train[currentIndex]->MOT3_C / 2));
    ui->LBL11_6->setText(QString::number(database->data_TCN->train[currentIndex]->MOT4_C / 2));
    //电机温度
    //ui->LBL12_1->setText(QString::number(database->data_TCN->train[currentIndex]->MOT1_TEMP + 100));
    //ui->LBL12_2->setText(QString::number(database->data_TCN->train[currentIndex]->MOT1_TEMP + 100));
    ui->LBL12_3->setText(QString::number((database->data_TCN->train[currentIndex]->MOT1_TEMP + 50) / 2));
    ui->LBL12_4->setText(QString::number((database->data_TCN->train[currentIndex]->MOT2_TEMP + 50) / 2));
    ui->LBL12_5->setText(QString::number((database->data_TCN->train[currentIndex]->MOT3_TEMP + 50) / 2));
    ui->LBL12_6->setText(QString::number((database->data_TCN->train[currentIndex]->MOT4_TEMP + 50) / 2));
}

void DeviceData_TrainOutline::NBpressEvent()
{
    currentIndex = ((QPushButton*)this->sender())->whatsThis().toInt();

    NBreleaseEvent();
    switch (currentIndex)
    {
        case 0:
            ui->NButton1->setStyleSheet(NBUTTONDOWN);
        break;
        case 1:
            ui->NButton2->setStyleSheet(NBUTTONDOWNR);
        break;
        case 2:
            ui->NButton3->setStyleSheet(NBUTTONDOWN);
        break;
        case 3:
            ui->NButton4->setStyleSheet(NBUTTONDOWNR);
        break;
        default:
        break;
    }
}

void DeviceData_TrainOutline::NBreleaseEvent()
{
    ui->NButton1->setStyleSheet(NBUTTONUP);
    ui->NButton2->setStyleSheet(NBUTTONUPR);
    ui->NButton3->setStyleSheet(NBUTTONUP);
    ui->NButton4->setStyleSheet(NBUTTONUPR);
}
