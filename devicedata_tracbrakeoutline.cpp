#include "devicedata_tracbrakeoutline.h"
#include "ui_devicedata_tracbrakeoutline.h"

DeviceData_TracBrakeOutline::DeviceData_TracBrakeOutline(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::DeviceData_TracBrakeOutline)
{
    ui->setupUi(this);

    progbar_Act1<< ui->BARTrain1Act1_1<< ui->BARTrain1Act2_1<< ui->BARTrain1Act3_1<< ui->BARTrain1Act4_1
                << ui->BARTrain2Act1_1<< ui->BARTrain2Act2_1<< ui->BARTrain2Act3_1<< ui->BARTrain2Act4_1;

    progbar_Act2<< ui->BARTrain1Act1_2<< ui->BARTrain1Act2_2<< ui->BARTrain1Act3_2<< ui->BARTrain1Act4_2
                << ui->BARTrain2Act1_2<< ui->BARTrain2Act2_2<< ui->BARTrain2Act3_2<< ui->BARTrain2Act4_2;

    progbar_Set1<< ui->BARTrain1Set1_1<< ui->BARTrain1Set2_1<< ui->BARTrain1Set3_1<< ui->BARTrain1Set4_1
                << ui->BARTrain2Set1_1<< ui->BARTrain2Set2_1<< ui->BARTrain2Set3_1<< ui->BARTrain2Set4_1;

    progbar_Set2<< ui->BARTrain1Set1_2<< ui->BARTrain1Set2_2<< ui->BARTrain1Set3_2<< ui->BARTrain1Set4_2
                << ui->BARTrain2Set1_2<< ui->BARTrain2Set2_2<< ui->BARTrain2Set3_2<< ui->BARTrain2Set4_2;

    progbar_ActTotal1<< ui->BARTrainAct1_1<< ui->BARTrainAct2_1<< ui->BARTrainAct3_1<< ui->BARTrainAct4_1;
    progbar_ActTotal2<< ui->BARTrainAct1_2<< ui->BARTrainAct2_2<< ui->BARTrainAct3_2<< ui->BARTrainAct4_2;
    progbar_SetTotal1<< ui->BARTrainSet1_1<< ui->BARTrainSet2_1<< ui->BARTrainSet3_1<< ui->BARTrainSet4_1;
    progbar_SetTotal2<< ui->BARTrainSet1_2<< ui->BARTrainSet2_2<< ui->BARTrainSet3_2<< ui->BARTrainSet4_2;

    foreach(QProgressBar* bar, progbar_Act1)
    {
        bar->setRange(0,100); //设置进度条最小值和最大值(取值范围)
        bar->setMinimum(0); //设置进度条最小值
        bar->setMaximum(100); //设置进度条最大值
        //bar->setInvertedAppearance(true);
    }
    foreach(QProgressBar* bar, progbar_Act2)
    {
        bar->setRange(-100,0); //设置进度条最小值和最大值(取值范围)
        bar->setMinimum(-100); //设置进度条最小值
        bar->setMaximum(0); //设置进度条最大值
    }
    foreach(QProgressBar* bar, progbar_Set1)
    {
        bar->setRange(0,100); //设置进度条最小值和最大值(取值范围)
        bar->setMinimum(0); //设置进度条最小值
        bar->setMaximum(100); //设置进度条最大值
    }
    foreach(QProgressBar* bar, progbar_Set2)
    {
        bar->setRange(-100,0); //设置进度条最小值和最大值(取值范围)
        bar->setMinimum(-100); //设置进度条最小值
        bar->setMaximum(0); //设置进度条最大值
    }
    foreach(QProgressBar* bar, progbar_ActTotal1)
    {
        bar->setRange(0,600); //设置进度条最小值和最大值(取值范围)
        bar->setMinimum(0); //设置进度条最小值
        bar->setMaximum(600); //设置进度条最大值
    }
    foreach(QProgressBar* bar, progbar_ActTotal2)
    {
        bar->setRange(-600,0); //设置进度条最小值和最大值(取值范围)
        bar->setMinimum(-600); //设置进度条最小值
        bar->setMaximum(0); //设置进度条最大值
    }
    foreach(QProgressBar* bar, progbar_SetTotal1)
    {
        bar->setRange(0,600); //设置进度条最小值和最大值(取值范围)
        bar->setMinimum(0); //设置进度条最小值
        bar->setMaximum(600); //设置进度条最大值
    }
    foreach(QProgressBar* bar, progbar_SetTotal2)
    {
        bar->setRange(-600,0); //设置进度条最小值和最大值(取值范围)
        bar->setMinimum(-600); //设置进度条最小值
        bar->setMaximum(0); //设置进度条最大值
    }

}

DeviceData_TracBrakeOutline::~DeviceData_TracBrakeOutline()
{
    delete ui;
}

void DeviceData_TracBrakeOutline::updatePage()
{
    int uic1,uic2;

    getUICValue(uic1,uic2);

    value_Change1.clear();
    value_Tmp.clear();
    value_Tmp<< database->data_TCN->train[uic1]->TE_AXLE1<< database->data_TCN->train[uic1]->TE_AXLE2
            << database->data_TCN->train[uic1]->TE_AXLE3<< database->data_TCN->train[uic1]->TE_AXLE4
            << database->data_TCN->train[uic2]->TE_AXLE1<< database->data_TCN->train[uic2]->TE_AXLE2
            << database->data_TCN->train[uic2]->TE_AXLE3<< database->data_TCN->train[uic2]->TE_AXLE4;
    calcActAxleValue(value_Tmp,value_Change1);
    SetProgbarValue(progbar_Act1,progbar_Act2,value_Change1);
    labels.clear();
    labels<<ui->LBL_ActAxis1<<ui->LBL_ActAxis2<<ui->LBL_ActAxis3<<ui->LBL_ActAxis4
            <<ui->LBL_ActAxis5<<ui->LBL_ActAxis6<<ui->LBL_ActAxis7<<ui->LBL_ActAxis8;
    setLabelTextValue(labels,value_Change1);

    value_Change2.clear();
    value_Tmp.clear();
    value_Tmp<< database->data_CCU->TE_AXLE_SET<< database->data_CCU->TE_AXLE_SET
            << database->data_CCU->TE_AXLE_SET<< database->data_CCU->TE_AXLE_SET
            << database->data_CCU->TE_AXLE_SET<< database->data_CCU->TE_AXLE_SET
            << database->data_CCU->TE_AXLE_SET<< database->data_CCU->TE_AXLE_SET;
    calcSetAxleValue(value_Tmp,value_Change2);
    SetProgbarValue(progbar_Set1,progbar_Set2,value_Change2);
    labels.clear();
    labels<<ui->LBL_SetAxis1<<ui->LBL_SetAxis2<<ui->LBL_SetAxis3<<ui->LBL_SetAxis4
            <<ui->LBL_SetAxis5<<ui->LBL_SetAxis6<<ui->LBL_SetAxis7<<ui->LBL_SetAxis8;
    setLabelTextValue(labels,value_Change2);

    value_Tatol.clear();
    calcTotalAxleValue(value_Change1,value_Tatol);
    SetProgbarValue(progbar_ActTotal1,progbar_ActTotal2,value_Tatol);
    labels.clear();
    labels<<ui->LBL_ActTrain1<<ui->LBL_ActTrain2<<ui->LBL_ActTrain3<<ui->LBL_ActTrain4;
    setLabelTextValue(labels,value_Tatol);

    value_Tatol.clear();
    calcTotalAxleValue(value_Change2,value_Tatol);
    SetProgbarValue(progbar_SetTotal1,progbar_SetTotal2,value_Tatol);
    labels.clear();
    labels<<ui->LBL_SetTrain1<<ui->LBL_SetTrain2<<ui->LBL_SetTrain3<<ui->LBL_SetTrain4;
    setLabelTextValue(labels,value_Tatol);

    //实际速度
    ui->LBL_ActSpeed->setText(QString::number(database->data_CCU->ACTUAL_SPEED/10) + " km/h");
    //设定速度
    ui->LBL_SetSpeed->setText(QString::number(database->data_CCU->SET_SPEED) + " km/h");
    //司控器级位
    ui->LBL_LEvel->setText(QString::number((database->data_CCU->MSCT_GRD - 200)/10));

}

void DeviceData_TracBrakeOutline::setLabelTextValue(QList<QLabel *> label, QList<int> value)
{
    if(label.size() != value.size())
        return;

    for(int i = 0; i < label.size(); i++)
    {
        label.at(i)->setText(QString::number(value.at(i)));
    }
}

void DeviceData_TracBrakeOutline::getUICValue(int &uic1, int &uic2)
{
    uic1 = database->data_CCU->UIC_ADDR;
    uic2 = 0;

    switch(uic1)
    {
    case 1:
    case 2:
        uic1 = 1;
        uic2 = 2;
        break;
    case 3:
    case 4:
        uic1 = 3;
        uic2 = 4;
        break;
    default:
        uic1 = 1;
        uic2 = 2;
    }
}

void DeviceData_TracBrakeOutline::calcActAxleValue(QList<unsigned char> tmp, QList<int > &value)
{
    for (int i = 0; i < tmp.size(); i++)
    {
        value << tmp.at(i) - 100;
    }
}

void DeviceData_TracBrakeOutline::calcSetAxleValue(QList<unsigned char> tmp, QList<int > &value)
{
    for (int i = 0; i < tmp.size(); i++)
    {
        value << tmp.at(i)/10 - 1000;
    }
}

void DeviceData_TracBrakeOutline::calcTotalAxleValue(QList<int> tmp, QList<int> &value)
{

    if (tmp.size() % 8 != 0)
        return;
    for (int i = 0; i < tmp.size() / 2; i++)
    {
        value << tmp.at(i) + tmp.at(i + 4);
    }
}

void DeviceData_TracBrakeOutline::SetProgbarValue(QList<QProgressBar *> bar1, QList<QProgressBar *> bar2, QList<int> value)
{
    if (bar1.size() != bar2.size() || bar1.size() != value.size())
        return;

    for(int i = 0; i < value.size(); i++)
    {
        if (value.at(i) == 0)
        {
            bar1.at(i)->setValue(0);
            bar2.at(i)->setValue(0);
        }
        else if (value.at(i) > 0)
        {
            bar1.at(i)->setValue(100  + value.at(i));
            bar2.at(i)->setValue(0);
        }
        else if (value.at(i) < 0)
        {
            bar1.at(i)->setValue(0);
            bar2.at(i)->setValue(value.at(i));
            //progbar_Act.at(i)->
        }
    }
}
