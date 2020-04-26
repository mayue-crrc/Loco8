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
}

VehicleRunStatePage::~VehicleRunStatePage()
{
    delete ui;
}

void VehicleRunStatePage::updatePage()
{

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

}
void VehicleRunStatePage::showEvent(QShowEvent *)
{

}


