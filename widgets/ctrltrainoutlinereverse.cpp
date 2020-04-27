#include "ctrltrainoutlinereverse.h"
#include "ui_ctrltrainoutlinereverse.h"

CtrlTrainOutLineReverse::CtrlTrainOutLineReverse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CtrlTrainOutLineReverse)
{
    ui->setupUi(this);
    labels<< ui->LBLActivation<< ui->LBLDirection<< ui->LBLPanto<< ui->LBLGaoya<< ui->LBLZhuduan
            << ui->LBLBraking1<< ui->LBLBraking2<< ui->LBLParking<< ui->LBLTraction1<< ui->LBLTraction2
            << ui->LBLTraction3<< ui->LBLTraction4<< ui->LBLHengLiJu<< ui->LBLZhunHengSu;
}

CtrlTrainOutLineReverse::~CtrlTrainOutLineReverse()
{
    delete ui;
}

void CtrlTrainOutLineReverse::updateData(QList<QList<bool> > bo, QList<QList<QString> > str)
{
    for (int i = 0; i< labels.size(); i++)
    {
        setLBLpic(labels.at(i),bo.at(i),str.at(i));
    }
}

/*
void CtrlTrainOutLineReverse::updateData(QList<bool> &activation, QList<bool> &direction, QList<bool> &panto, QList<bool> &gaoya,
                                  QList<bool> &zhuduan, QList<bool> &parking, QList<bool> &traction, QList<bool> &brake)
{
    QList<QString> t_style;
    QList<bool> tmp_string;
    QList<QLabel* > labels;

    // 电钥匙激活
    t_style<< HIDEIMAGE<< HIDEIMAGE;
    setLBLpic(ui->LBLActivation,activation,t_style);
    //方向
    t_style<<FANGXIANGXIANGQIAN<<FANGXIANGZHONGLI<<FANGXIANGXIANGHOU<<HIDEIMAGE;
    setLBLpic(ui->LBLDirection,direction,t_style);
    //受电弓
    t_style<<PANTODOWN<<PANTOUP<<PANTOIRISE<<PANTOISOLATE<<HIDEIMAGE;
    setLBLpic(ui->LBLPanto,panto,t_style);
    //gaoya
    t_style<<PANTODOWN<<PANTODOWN;
    setLBLpic(ui->LBLGaoya,gaoya,t_style);
    //主断路器
    t_style<<ZHUDUANBIHE<<ZHUDUANJIUXU<<ZHUDUANDUANKAI<<ZHUDUANGELI<<HIDEIMAGE;
    setLBLpic(ui->LBLGaoya,zhuduan,t_style);
    //空气制动
    labels.clear();
    labels<<ui->LBLBraking1<<ui->LBLBraking2;
    for(int i=0; i< labels.size(); i++)
    {
        t_style<<CHANGYONGZHIDONGGELI<<CHANGYONGZHIDONGSHIJIA<<CHANGYONGZHIDONGHUANJIE;
        tmp_string<<brake.at(i*3)<< brake.at(i*3 + 1)<< brake.at(i*3 + 2);
        setLBLpic(labels.at(i),tmp_string,t_style);
    }
    //停放制动
    t_style<<TINGFANGZHIDONGGELI<<TINGFANGZHIDONGSHIJIA<<TINGFANGZHIDONGHUANJIE;
    setLBLpic(ui->LBLParking,parking,t_style);

    //轴隔离状态
    labels.clear();
    labels<<ui->LBLTraction1<<ui->LBLTraction2<<ui->LBLTraction3<<ui->LBLTraction4;
    for(int i=0; i< labels.size(); i++)
    {
        t_style<<QUDONGGELI<<QUDONGOK<<HIDEIMAGE;
        tmp_string<<traction.at(i*3)<< traction.at(i*3 + 1)<< traction.at(i*3 + 2);
        setLBLpic(labels.at(i),tmp_string,t_style);
    }
}
*/
void CtrlTrainOutLineReverse::updateStringData(unsigned short no, unsigned short kn)
{
    //KN
    this->ui->LBLKn->setText(QString::number(kn));
    // 编号
    this->ui->LBLCode->setText("HXD2" + QString::number(no));
}

void CtrlTrainOutLineReverse::setLBLpic(QLabel *lbl, QList<bool> status, QList<QString> stylestr)
{
    if(status.size() != stylestr.size())
    {
        qDebug()<<"status's size doesnt equal stylestr's size"<<status.size()<<stylestr.size();
        return;

    }
    for(int i = 0;i<status.size();i++)
    {
        if(status.at(i))
        {
            lbl->setStyleSheet(stylestr.at(i));
            return;
        }
    }
}
