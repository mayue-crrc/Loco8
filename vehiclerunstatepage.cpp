#include "vehiclerunstatepage.h"
#include "ui_vehiclerunstatepage.h"

#define FAULTLEVEL1 "background-color:rgb(240,0,0);color:black;border:transparent;"
#define FAULTLEVEL2 "background-color:rgb(240,240,0);color:black;border:transparent;"
#define FAULTLEVEL3 "background-color:rgb(0,0,0);color:rgb(248,248,248);border:transparent;"

VehicleRunStatePage::VehicleRunStatePage(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::VehicleRunStatePage)
{
    ui->setupUi(this);

    ctrlNetVoltage = new CtrlNetVoltage(this);
    ctrlNetVoltage->setGeometry(140,0,this->ctrlNetVoltage->width(),this->ctrlNetVoltage->height());

    ctrlNetCurrent = new CtrlNetCurrent(this);
    ctrlNetCurrent->setGeometry(230,0,this->ctrlNetCurrent->width(),this->ctrlNetCurrent->height());

    ctrlControlVoltage = new CtrlControlVoltage(this);
    ctrlControlVoltage->setGeometry(320,0,this->ctrlControlVoltage->width(),this->ctrlControlVoltage->height());

    ctrlTracBrake = new CtrlTracBrake(this);
    ctrlTracBrake->setGeometry(410,0,this->ctrlTracBrake->width(),this->ctrlTracBrake->height());
}

VehicleRunStatePage::~VehicleRunStatePage()
{
    delete ui;
}

void VehicleRunStatePage::updatePage()
{
    static int i   = 0;
    i +=10;
    ctrlNetVoltage->setCtrlValueRect(database->data_CCU->LINE_VOLT);
    ctrlNetCurrent->setCtrlValueRect(database->data_CCU->PRIM_C);
    ctrlControlVoltage->setCtrlValueRect(database->data_CCU->BAT_VOLT);
    //ctrlTracBrake->setCtrlValueRect(database->data_CCU->TEBE_EFFORT,,i/10%3);
    //eg
    QList<bool> t_status;
    QList<QString> t_style;

    //方向
    t_style<<FANGXIANGZHONGLI<<FANGXIANGXIANGHOU<<FANGXIANGXIANGQIAN<<NULLIMAGE;
    t_status<<database->data_TCN->TrainLocal->CMD_DIR_N<<database->data_TCN->TrainLocal->CMD_DIR_B<<database->data_TCN->TrainLocal->CMD_DIR_f<<true;
    setLBLpic(ui->LBLC11,t_status,t_style);


    //受电弓
    t_style<<PANTOUP<<PANTODOWN<<NULLIMAGE;
    t_status<<(database->data_TCN->train[0]->STATE_PANTO_RD||database->data_TCN->train[1]->STATE_PANTO_RD
             ||database->data_TCN->train[2]->STATE_PANTO_RD||database->data_TCN->train[3]->STATE_PANTO_RD)
            <<(database->data_TCN->train[0]->STATE_PANTO_DN||database->data_TCN->train[1]->STATE_PANTO_DN
            ||database->data_TCN->train[2]->STATE_PANTO_DN||database->data_TCN->train[3]->STATE_PANTO_DN)
            <<true;
    setLBLpic(ui->LBLC12,t_status,t_style);

    //主断路器
    t_style<<ZHUDUANBIHE<<ZHUDUANDUANKAI<<ZHUDUANJIUXU<<ZHUDUANGELI<<NULLIMAGE;
    t_status<<(database->data_TCN->TrainLocal->STATE_QFM_ON)<<(database->data_TCN->TrainLocal->STATE_QFM_OFF)
            <<(database->data_TCN->TrainLocal->STATE_QFM_K)<<(database->data_TCN->TrainLocal->STATE_QFM_ISO)
            <<true;
    setLBLpic(ui->LBLC13,t_status,t_style);

    //分相
    t_style<<FENXIANGQU<<NULLIMAGE;
    t_status<<(database->data_CCU->NSC_START||database->data_CCU->NSC_END)<<true;
    setLBLpic(ui->LBLC14,t_status,t_style);

    //停放制动
    t_style<<TINGFANGZHIDONGELI<<TINGFANGZHIDONGSHIJIA<<TINGFANGZHIDONGHUANJIE;
    t_status<<database->data_TCN->TrainLocal->STATE_PARK_BRK_I<<database->data_TCN->TrainLocal->STATE_PARK_BRK_ON<<true;
    setLBLpic(ui->LBLC15,t_status,t_style);

    //撒沙
    t_style<<SASHA<<NULLIMAGE;
    t_status<<database->data_CCU->SANDING<<true;
    setLBLpic(ui->LBLC16,t_status,t_style);

    //空转
    t_style<<KONGZHUAN<<HUAXING<<NULLIMAGE;
    t_status<<database->data_CCU->RACING<<database->data_CCU->SLIP<<true;
    setLBLpic(ui->LBLC21,t_status,t_style);

    //定速
    t_style<<DINGSUMOSHI<<NULLIMAGE;
    t_status<<database->data_CCU->SPEED_CTL<<true;
    setLBLpic(ui->LBLC22,t_status,t_style);

    //惩罚制动
    t_style<<CHENGFAZHIDONG<<JINJIZHIDONG<<NULLIMAGE;
    t_status<<database->data_CCU->PENALTY_BRK<<database->data_TCN->TrainLocal->STATE_EMG_BRK_ON<<true;
    setLBLpic(ui->LBLC23,t_status,t_style);

    //设定速度
    ui->LBLSetSpeed->setText(QString::number(database->data_CCU->SPEED_SET));
    //实际速度
    ui->LBLActualSpeed->setText(QString::number(database->data_CCU->ACTUAL_SPEED));
    //实际牵引力
    ui->LBLActualForce->setText(QString::number(database->data_CCU->TEBE_EFFORT));
    //设定牵引力
    ui->LBLSetForce->setText(QString::number(database->data_CCU->TE_AXLE_SET));
}
void VehicleRunStatePage::showEvent(QShowEvent *)
{

}



void VehicleRunStatePage::on_BTNSpeedplus_clicked()
{
    database->data_CCU->SPEED_SET++;
}

void VehicleRunStatePage::on_BTNSpeedminus_clicked()
{
    if(database->data_CCU->SPEED_SET>0)
        database->data_CCU->SPEED_SET--;

}
