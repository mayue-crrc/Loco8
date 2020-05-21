#include "settng_panto.h"
#include "ui_settng_panto.h"

Settng_Panto::Settng_Panto(QWidget *parent) :
    MyBase(parent),
    ui(new Ui::Settng_Panto)
{
    ui->setupUi(this);
    hideAllTrain();
    this->ui->BTN_Train1->setStyleSheet(TRAINDOWNL);
    TrainList<<this->ui->BTN_Train1<<this->ui->BTN_Train2<<this->ui->BTN_Train3<<this->ui->BTN_Train4;

    foreach (QPushButton* button, TrainList) {
        connect(button,SIGNAL(pressed()),this,SLOT(TrainSelectEvent()));
    }

    t_style<<PANTOSETDOWN<<PANTOSETUP<<PANTOSETISO;
    t_status1<<database->data_TCN->train[0]->STATE_PANTO_RD<<database->data_TCN->train[0]->STATE_PANTO_DN<<database->data_TCN->train[0]->STATE_PANTO_ISO;
    t_status2<<database->data_TCN->train[1]->STATE_PANTO_RD<<database->data_TCN->train[1]->STATE_PANTO_DN<<database->data_TCN->train[1]->STATE_PANTO_ISO;
    t_status3<<database->data_TCN->train[2]->STATE_PANTO_RD<<database->data_TCN->train[2]->STATE_PANTO_DN<<database->data_TCN->train[2]->STATE_PANTO_ISO;
    t_status4<<database->data_TCN->train[3]->STATE_PANTO_RD<<database->data_TCN->train[3]->STATE_PANTO_DN<<database->data_TCN->train[3]->STATE_PANTO_ISO;

}

Settng_Panto::~Settng_Panto()
{
    delete ui;
}

void Settng_Panto::updatePage()
{

    hideAllTrain();
    switch (this->database->data_CCU->RULOCO_NO) {
    case 0:
        show1Train();
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->LOCO_NO,16));
        Active(this->ui->LBL_2Active1,this->database->data_TCN->train[0]->STATE_CAB_ACT);
        setLBLpic(this->ui->LBL_2PANTO1,t_status1,t_style);
        break;
    case 1:
        show2Train();
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->LOCO_NO,16));
        this->ui->LBL_Train2Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[1]->LOCO_NO,16));
        Active(this->ui->LBL_2Active1,this->database->data_TCN->train[0]->STATE_CAB_ACT);
        Active(this->ui->LBL_2Active2,this->database->data_TCN->train[1]->STATE_CAB_ACT);
        setLBLpic(this->ui->LBL_2PANTO1,t_status1,t_style);
        setLBLpic(this->ui->LBL_2PANTO2,t_status2,t_style);
        break;
    case 2:
        show3Train();
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->LOCO_NO,16));
        this->ui->LBL_Train2Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[1]->LOCO_NO,16));
        this->ui->LBL_Train3Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[2]->LOCO_NO,16));
        Active(this->ui->LBL_4Active1,this->database->data_TCN->train[0]->STATE_CAB_ACT);
        Active(this->ui->LBL_4Active2,this->database->data_TCN->train[1]->STATE_CAB_ACT);
        Active(this->ui->LBL_4Active3,this->database->data_TCN->train[2]->STATE_CAB_ACT);
        setLBLpic(this->ui->LBL_4PANTO1,t_status1,t_style);
        setLBLpic(this->ui->LBL_4PANTO2,t_status2,t_style);
        setLBLpic(this->ui->LBL_4PANTO3,t_status3,t_style);
        break;
    case 3:
        show4Train();
        this->ui->LBL_Train1Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[0]->LOCO_NO,16));
        this->ui->LBL_Train2Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[1]->LOCO_NO,16));
        this->ui->LBL_Train3Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[2]->LOCO_NO,16));
        this->ui->LBL_Train4Num->setText("HXD2  "+QString::number(this->database->data_TCN->train[3]->LOCO_NO,16));
        Active(this->ui->LBL_4Active1,this->database->data_TCN->train[0]->STATE_CAB_ACT);
        Active(this->ui->LBL_4Active2,this->database->data_TCN->train[1]->STATE_CAB_ACT);
        Active(this->ui->LBL_4Active3,this->database->data_TCN->train[2]->STATE_CAB_ACT);
        Active(this->ui->LBL_4Active4,this->database->data_TCN->train[3]->STATE_CAB_ACT);
        setLBLpic(this->ui->LBL_4PANTO1,t_status1,t_style);
        setLBLpic(this->ui->LBL_4PANTO2,t_status2,t_style);
        setLBLpic(this->ui->LBL_4PANTO3,t_status3,t_style);
        setLBLpic(this->ui->LBL_4PANTO4,t_status4,t_style);
        break;
    default:
        break;
    }
}

void Settng_Panto::show1Train()
{
    this->ui->LBL_2Train1->show();
    this->ui->LBL_2Train1->setGeometry(255,130,this->ui->LBL_2Train1->width(),this->ui->LBL_2Train1->height());
    this->ui->LBL_2PANTO1->show();
    this->ui->LBL_2PANTO1->setGeometry(339,124,this->ui->LBL_2PANTO1->width(),this->ui->LBL_2PANTO1->height());
    this->ui->LBL_2Active1->hide();
    this->ui->LBL_2Active1->setGeometry(299,190,this->ui->LBL_2Active1->width(),this->ui->LBL_2Active1->height());
    this->ui->BTN_Train1->show();
    this->ui->LBL_Train1Num->show();
}

void Settng_Panto::show2Train()
{
    //2Car1
    this->ui->LBL_2Train1->show();
    this->ui->LBL_2Train1->setGeometry(109,130,this->ui->LBL_2Train1->width(),this->ui->LBL_2Train1->height());
    this->ui->LBL_2PANTO1->show();
    this->ui->LBL_2PANTO1->setGeometry(193,124,this->ui->LBL_2PANTO1->width(),this->ui->LBL_2PANTO1->height());
    this->ui->LBL_2Active1->hide();
    this->ui->LBL_2Active1->setGeometry(153,190,this->ui->LBL_2Active1->width(),this->ui->LBL_2Active1->height());
    //2Car2
    this->ui->LBL_2Train2->show();
    this->ui->LBL_2Train2->setGeometry(400,130,this->ui->LBL_2Train2->width(),this->ui->LBL_2Train2->height());
    this->ui->LBL_2PANTO2->show();
    this->ui->LBL_2PANTO2->setGeometry(562,124,this->ui->LBL_2PANTO2->width(),this->ui->LBL_2PANTO2->height());
    this->ui->LBL_2Active2->hide();
    this->ui->LBL_2Active2->setGeometry(628,190,this->ui->LBL_2Active2->width(),this->ui->LBL_2Active2->height());

    this->ui->BTN_Train1->show();
    this->ui->LBL_Train1Num->show();
    this->ui->BTN_Train2->show();
    this->ui->LBL_Train2Num->show();
}

void Settng_Panto::show3Train()
{
    //3Car1
    this->ui->LBL_4Train1->show();
    this->ui->LBL_4Train1->setGeometry(121,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4PANTO1->show();
    this->ui->LBL_4PANTO1->setGeometry(176,133,this->ui->LBL_4PANTO1->width(),this->ui->LBL_4PANTO1->height());
    this->ui->LBL_4Active1->hide();
    this->ui->LBL_4Active1->setGeometry(150,180,this->ui->LBL_4Active1->width(),this->ui->LBL_4Active1->height());
    //3Car2
    this->ui->LBL_4Train2->show();
    this->ui->LBL_4Train2->setGeometry(305,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4PANTO2->show();
    this->ui->LBL_4PANTO2->setGeometry(406,133,this->ui->LBL_4PANTO2->width(),this->ui->LBL_4PANTO2->height());
    this->ui->LBL_4Active2->hide();
    this->ui->LBL_4Active2->setGeometry(354,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());
    //3Car3
    this->ui->LBL_4Train3->show();
    this->ui->LBL_4Train3->setGeometry(501,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4PANTO3->show();
    this->ui->LBL_4PANTO3->setGeometry(556,133,this->ui->LBL_4PANTO3->width(),this->ui->LBL_4PANTO3->height());
    this->ui->LBL_4Active3->hide();
    this->ui->LBL_4Active3->setGeometry(430,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());
    this->ui->BTN_Train1->show();
    this->ui->LBL_Train1Num->show();
    this->ui->BTN_Train2->show();
    this->ui->LBL_Train2Num->show();
    this->ui->BTN_Train3->show();
    this->ui->LBL_Train3Num->show();
}

void Settng_Panto::show4Train()
{
    //4Car1
    this->ui->LBL_4Train1->show();
    this->ui->LBL_4Train1->setGeometry(21,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4PANTO1->show();
    this->ui->LBL_4PANTO1->setGeometry(76,133,this->ui->LBL_4PANTO1->width(),this->ui->LBL_4PANTO1->height());
    this->ui->LBL_4Active1->hide();
    this->ui->LBL_4Active1->setGeometry(50,180,this->ui->LBL_4Active1->width(),this->ui->LBL_4Active1->height());
    //4Car2
    this->ui->LBL_4Train2->show();
    this->ui->LBL_4Train2->setGeometry(205,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4PANTO2->show();
    this->ui->LBL_4PANTO2->setGeometry(306,133,this->ui->LBL_4PANTO2->width(),this->ui->LBL_4PANTO2->height());
    this->ui->LBL_4Active2->hide();
    this->ui->LBL_4Active2->setGeometry(354,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());
    //4Car3
    this->ui->LBL_4Train3->show();
    this->ui->LBL_4Train3->setGeometry(401,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4PANTO3->show();
    this->ui->LBL_4PANTO3->setGeometry(456,133,this->ui->LBL_4PANTO3->width(),this->ui->LBL_4PANTO3->height());
    this->ui->LBL_4Active3->hide();
    this->ui->LBL_4Active3->setGeometry(430,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());
    //4Car4
    this->ui->LBL_4Train4->show();
    this->ui->LBL_4Train4->setGeometry(590,143,this->ui->LBL_4Train1->width(),this->ui->LBL_4Train1->height());
    this->ui->LBL_4PANTO4->show();
    this->ui->LBL_4PANTO4->setGeometry(691,133,this->ui->LBL_4PANTO1->width(),this->ui->LBL_4PANTO1->height());
    this->ui->LBL_4Active4->hide();
    this->ui->LBL_4Active4->setGeometry(738,180,this->ui->LBL_4Active4->width(),this->ui->LBL_4Active4->height());

    this->ui->BTN_Train1->show();
    this->ui->LBL_Train1Num->show();
    this->ui->BTN_Train2->show();
    this->ui->LBL_Train2Num->show();
    this->ui->BTN_Train3->show();
    this->ui->LBL_Train3Num->show();
    this->ui->BTN_Train4->show();
    this->ui->LBL_Train4Num->show();
}

void Settng_Panto::hideAllTrain()
{
    //2Car1
    this->ui->LBL_2Train1->hide();
    this->ui->LBL_2PANTO1->hide();
    this->ui->LBL_2Active1->hide();
    //2Car2
    this->ui->LBL_2Train2->hide();
    this->ui->LBL_2PANTO2->hide();
    this->ui->LBL_2Active2->hide();
    //4Car1
    this->ui->LBL_4Train1->hide();
    this->ui->LBL_4PANTO1->hide();
    this->ui->LBL_4Active1->hide();
    //4Car2
    this->ui->LBL_4Train2->hide();
    this->ui->LBL_4PANTO2->hide();
    this->ui->LBL_4Active2->hide();
    //4Car3
    this->ui->LBL_4Train3->hide();
    this->ui->LBL_4PANTO3->hide();
    this->ui->LBL_4Active3->hide();
    //4Car4
    this->ui->LBL_4Train4->hide();
    this->ui->LBL_4PANTO4->hide();
    this->ui->LBL_4Active4->hide();
    //TrainButton&Label
    this->ui->BTN_Train1->hide();
    this->ui->BTN_Train2->hide();
    this->ui->BTN_Train3->hide();
    this->ui->BTN_Train4->hide();
    this->ui->LBL_Train1Num->hide();
    this->ui->LBL_Train2Num->hide();
    this->ui->LBL_Train3Num->hide();
    this->ui->LBL_Train4Num->hide();
}

void Settng_Panto::TrainSelectEvent()
{
    for(int i=0;i<TrainList.size();i++)
    {
        if(0 == i%2)
        {
            TrainList.at(i)->setStyleSheet(TRAINUPL);
        }else
        {
            TrainList.at(i)->setStyleSheet(TRAINUPR);
        }
    }

   TrainIndex = ((QPushButton*)this->sender())->whatsThis().toInt();

   switch(TrainIndex)
   {
   case 0:
       this->ui->BTN_Train1->setStyleSheet(TRAINDOWNL);
       break;
   case 1:
       this->ui->BTN_Train2->setStyleSheet(TRAINDOWNR);
       break;
   case 2:
       this->ui->BTN_Train3->setStyleSheet(TRAINDOWNL);
       break;
   case 3:
       this->ui->BTN_Train4->setStyleSheet(TRAINDOWNR);
       break;
   }

}

void Settng_Panto::Active(QLabel *lbl,bool Active)
{
    if(Active)
    {
        lbl->show();
    }else
    {
        lbl->hide();
    }
}

void Settng_Panto::on_BTN_PANTO_Cutout_pressed()
{
    timerCutout = startTimer(3000);
    switch (TrainIndex) {
    case 0:
        this->database->data_CCU->TC1_PANTO_ISO_RQ = true;
        break;
    case 1:
        this->database->data_CCU->TC2_PANTO_ISO_RQ = true;
        break;
    case 2:
        this->database->data_CCU->TC3_PANTO_ISO_RQ = true;
        break;
    case 3:
        this->database->data_CCU->TC4_PANTO_ISO_RQ = true;
        break;
    default:
        break;
    }
    this->ui->BTN_PANTO_Cutout->setStyleSheet(NButtonDOWN);
}

void Settng_Panto::on_BTN_PANTO_CancelCutout_pressed()
{
    timerCancel = startTimer(3000);
    switch (TrainIndex) {
    case 0:
        this->database->data_CCU->TC1_PANTO_ISO_REL_RQ = true;
        break;
    case 1:
        this->database->data_CCU->TC2_PANTO_ISO_REL_RQ = true;
        break;
    case 2:
        this->database->data_CCU->TC3_PANTO_ISO_REL_RQ = true;
        break;
    case 3:
        this->database->data_CCU->TC4_PANTO_ISO_REL_RQ = true;
        break;
    default:
        break;
    }
    this->ui->BTN_PANTO_CancelCutout->setStyleSheet(NButtonDOWN);
}

void Settng_Panto::timerEvent(QTimerEvent *e)
{
    if(timerCutout == e->timerId())
    {
        killTimer(timerCutout);
        switch (TrainIndex) {
        case 0:
            this->database->data_CCU->TC1_PANTO_ISO_RQ = false;
            break;
        case 1:
            this->database->data_CCU->TC2_PANTO_ISO_RQ = false;
            break;
        case 2:
            this->database->data_CCU->TC3_PANTO_ISO_RQ = false;
            break;
        case 3:
            this->database->data_CCU->TC4_PANTO_ISO_RQ = false;
            break;
        default:
            break;
        }
        this->ui->BTN_PANTO_Cutout->setStyleSheet(NButtonUP);
        timerCutout = 0;
    }
    if(timerCancel == e->timerId())
    {
        killTimer(timerCancel);
        switch (TrainIndex) {
        case 0:
            this->database->data_CCU->TC1_PANTO_ISO_REL_RQ = false;
            break;
        case 1:
            this->database->data_CCU->TC2_PANTO_ISO_REL_RQ = false;
            break;
        case 2:
            this->database->data_CCU->TC3_PANTO_ISO_REL_RQ = false;
            break;
        case 3:
            this->database->data_CCU->TC4_PANTO_ISO_REL_RQ = false;
            break;
        default:
            break;
        }
        this->ui->BTN_PANTO_CancelCutout->setStyleSheet(NButtonUP);
        timerCancel = 0;
    }
}

void Settng_Panto::hideEvent(QHideEvent *)
{
    this->database->data_CCU->TC1_PANTO_ISO_RQ = false;
    this->database->data_CCU->TC2_PANTO_ISO_RQ = false;
    this->database->data_CCU->TC3_PANTO_ISO_RQ = false;
    this->database->data_CCU->TC4_PANTO_ISO_RQ = false;
    this->database->data_CCU->TC1_PANTO_ISO_REL_RQ = false;
    this->database->data_CCU->TC2_PANTO_ISO_REL_RQ = false;
    this->database->data_CCU->TC3_PANTO_ISO_REL_RQ = false;
    this->database->data_CCU->TC4_PANTO_ISO_REL_RQ = false;
}

