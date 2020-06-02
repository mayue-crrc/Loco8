#include "maindata_trainoutline.h"
#include "ui_maindata_trainoutline.h"

MainData_TrainOutline::MainData_TrainOutline(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::MainData_TrainOutline)
{
    ui->setupUi(this);
    ui->Train1->hide();
    ui->Train2->hide();
    ui->Train3->hide();
    ui->Train4->hide();

}

MainData_TrainOutline::~MainData_TrainOutline()
{
    delete ui;
}

void MainData_TrainOutline::updatePage()
{
    int num = database->data_CCU->RULOCO_NO;

    num = 3;

    switch(num)
    {
        case 1:
            showTrainData(ui->Train1,0);
            ui->Train2->hide();
            ui->Train3->hide();
            ui->Train4->hide();
        break;
        case 2:
             showTrainData(ui->Train1,0);
             showTrainData(ui->Train2,1);
             ui->Train3->hide();
             ui->Train4->hide();
        break;
        case 3:
            showTrainData(ui->Train1,0);
            showTrainData(ui->Train2,1);
            showTrainData(ui->Train3,2);
             ui->Train4->hide();
        break;
        case 4:
            showTrainData(ui->Train1,0);
            showTrainData(ui->Train2,1);
            showTrainData(ui->Train3,2);
            showTrainData(ui->Train4,3);
        break;
        default:
            ui->Train1->hide();
            ui->Train2->hide();
            ui->Train3->hide();
            ui->Train4->hide();
        break;
    }

}

void MainData_TrainOutline::showTrainData(CtrlTrainOutLine *widget, int n)
{
    unsigned short int kn,no;

    SetAllData(n);
    widget->updateData(allBoolData,allImageData);
    widget->show();

    kn = database->data_TCN->train[n]->LOAD_VALUE;
    no = database->data_TCN->train[n]->LOCO_NO;
    widget->updateStringData(no,kn);

}

void MainData_TrainOutline::showTrainData(CtrlTrainOutLineReverse *widget, int n)
{
    unsigned short int kn,no;

    SetAllData(n);
    widget->updateData(allBoolData,allImageData);
    widget->show();

    kn = database->data_TCN->train[n]->LOAD_VALUE;
    no = database->data_TCN->train[n]->LOCO_NO;
    widget->updateStringData(no,kn);
}

void MainData_TrainOutline::SetAllData(int n)
{
    QList<bool> data;
    QList<QString> t_style;

    allBoolData.clear();
    allImageData.clear();

    // 电钥匙激活
    data.clear();
    t_style.clear();
    t_style<< SIJISHIJIHUO<< HIDEIMAGE;
    data<< database->data_TCN->train[n]->STATE_CAB_ACT<< true;

    allBoolData<< data;
    allImageData<< t_style;
    //方向
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->CMD_DIR_f
            <<database->data_TCN->train[n]->CMD_DIR_N
            <<database->data_TCN->train[n]->CMD_DIR_B
            <<true;
    t_style<<FANGXIANGXIANGQIAN<<FANGXIANGZHONGLI<<FANGXIANGXIANGHOU<<HIDEIMAGE;
    allBoolData<< data;
    allImageData<< t_style;
    //受电弓
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->STATE_PANTO_DN
         <<database->data_TCN->train[n]->STATE_PANTO_RG
         <<database->data_TCN->train[n]->STATE_PANTO_RD
         <<database->data_TCN->train[n]->STATE_PANTO_ISO
         <<true;
    t_style<<PANTODOWN<<PANTOUP<<PANTOIRISE<<PANTOISOLATE<<HIDEIMAGE;
    allBoolData<< data;
    allImageData<< t_style;
    //高压
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->STATE_H_HT
         <<true;
    t_style<<GAOYABIHE<<GAOYADUANKAI;
    allBoolData<< data;
    allImageData<< t_style;
    //主断
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->STATE_QFM_ON
           <<database->data_TCN->train[n]->STATE_QFM_OFF
           <<database->data_TCN->train[n]->STATE_QFM_K
           <<database->data_TCN->train[n]->STATE_QFM_ISO
           <<true;
    t_style<<ZHUDUANBIHE<<ZHUDUANDUANKAI<<ZHUDUANJIUXU<<ZHUDUANGELI<<HIDEIMAGE;
    allBoolData<< data;
    allImageData<< t_style;
    //空气制动
    //1
    data.clear();
    t_style.clear();
    data<< database->data_TCN->train[n]->STATE_AIR_BRK1_ON
         <<database->data_TCN->train[n]->STATE_AIR_BRK1_I
         <<true;
    t_style<<CHANGYONGZHIDONGGELI<<CHANGYONGZHIDONGSHIJIA<<CHANGYONGZHIDONGHUANJIE;
    allBoolData<< data;
    allImageData<< t_style;
    //2
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->STATE_AIR_BRK2_ON
         <<database->data_TCN->train[n]->STATE_AIR_BRK2_I
         <<true;
    t_style<<CHANGYONGZHIDONGGELI<<CHANGYONGZHIDONGSHIJIA<<CHANGYONGZHIDONGHUANJIE;
    allBoolData<< data;
    allImageData<< t_style;
    //停放制动
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->STATE_PARK_BRK_I
           <<database->data_TCN->train[n]->STATE_PARK_BRK_ON
           <<true;
    t_style<<TINGFANGZHIDONGELI<<TINGFANGZHIDONGSHIJIA<<TINGFANGZHIDONGHUANJIE;
    allBoolData<< data;
    allImageData<< t_style;
    //轴隔离状态
    //轴1
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->CMD_TC1_AXLE1_ISO_RQ
            <<database->data_TCN->train[n]->CMD_TC1_AXLE1_ISO_REL_RQ
            <<true;
    t_style<<QUDONGGELI<<QUDONGOK<<HIDEIMAGE;
    allBoolData<< data;
    allImageData<< t_style;
    //轴2
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->CMD_TC1_AXLE2_ISO_RQ
            <<database->data_TCN->train[n]->CMD_TC1_AXLE2_ISO_REL_RQ
            <<true;
    t_style<<QUDONGGELI<<QUDONGOK<<HIDEIMAGE;
    allBoolData<< data;
    allImageData<< t_style;
    //轴3
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->CMD_TC1_AXLE3_ISO_RQ
            <<database->data_TCN->train[n]->CMD_TC1_AXLE3_ISO_REL_RQ
            <<true;
    t_style<<QUDONGGELI<<QUDONGOK<<HIDEIMAGE;
    allBoolData<< data;
    allImageData<< t_style;
    //轴4
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->CMD_TC1_AXLE4_ISO_RQ
            <<database->data_TCN->train[n]->CMD_TC1_AXLE4_ISO_REL_RQ
            <<true;
    t_style<<QUDONGGELI<<QUDONGOK<<HIDEIMAGE;
    allBoolData<< data;
    allImageData<< t_style;
    //恒力矩
    data.clear();
    t_style.clear();
    data<<database->data_TCN->train[n]->STATE_T_CHAR<<true;
    t_style<<GREENBACKGROUND<<REDBACKGROUND;
    allBoolData<< data;
    allImageData<< t_style;
    //准恒速
    data.clear();
    t_style.clear();
    data<<!database->data_TCN->train[n]->STATE_T_CHAR<<true;
    t_style<<GREENBACKGROUND<<REDBACKGROUND;
    allBoolData<< data;
    allImageData<< t_style;
}
