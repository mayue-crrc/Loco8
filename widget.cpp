#include "widget.h"
#include "ui_widget.h"
#include "mybase.h"
#include "header.h"
#include "qtimer.h"
#include "database.h"
#include "navigator.h"
#include "vehiclerunstatepage.h"
#include "crrcmvb.h"
#include "crrcfault.h"
#include "simulation.h"
#include "devicedata_breaker.h"
#include "devicedata_acu.h"
#include "devicedata_version.h"
#include "devicedata_online.h"
#include "devicedata_mainconv.h"
#include "devicedata_io.h"

#ifdef QT_VERSION_5_6
#include "qdesktopwidget.h"
#endif

#include "maindata_trainoutline.h"
#include "settng_bypass.h"
#include "settng_test.h"
#include "settng_panto.h"
#include "settng_distance.h"
#include "datainputwheelpage.h"
#include "datainputdatetimepage.h"
#include "datainputother.h"
#include "datainputcalibratepage.h"
#include "datainputlubricatepage.h"
#include "datainputsplitlinepage.h"
#include "devicedata_trainoutline.h"
#include "fault_history.h"
#include "main_allportdata.h"

#include "main_simulate.h"
#include "main_lubrication.h"
#include "main_assistantdevice.h"
#include "main_380.h"
#include "main_separation.h"
#include "main_doublepanto.h"
#include "devicedata_tracbrakeoutline.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QDesktopWidget *desktop = QApplication::desktop();

    if (desktop->width() == 800 && desktop->height() == 600)
    {
        this->showFullScreen();
    }
    else
    {
        this->move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
    }

    this->database = new Database();
    MyBase::database = this->database;

    this->timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePage()));

    if(CrrcFault::initCrrcFault("fault_type_Loco8.db","fault_DB_Loco8.db"))
    {
        crrcFault = CrrcFault::getCrrcFault();
    }else
    {
        logger()->error("故障文件初始化错误");
    }



    this->simulation = new Simulation();
    this->simulation->hide();

    this->navigator = new Navigator(this);
    this->navigator->setMyBase(uTop,QString("导航栏"));
    this->navigator->show();
    connect(navigator,SIGNAL(translateLanguage()),this,SLOT(translateLanguage()));

    this->vehicleRunStatePage = new VehicleRunStatePage(this);
    this->vehicleRunStatePage->setMyBase(uMiddleMainPage,QString("主界面"));
    this->vehicleRunStatePage->show();

    this->dataInputLubricatePage = new DataInputLubricatePage(this);
    this->dataInputLubricatePage->setMyBase(uMiddleMainPage, QString("润滑设定"));
    this->dataInputLubricatePage->hide();

    this->dataInputWheelPage = new DataInputWheelPage(this);
    this->dataInputWheelPage->setMyBase(uMiddleMainPage, QString("轮径相关"));
    this->dataInputWheelPage->hide();

    this->dataInputDateTimePage = new DataInputDateTimePage(this);
    this->dataInputDateTimePage->setMyBase(uMiddleMainPage, QString("日期/时间"));
    this->dataInputDateTimePage->hide();

    this->dataInputOther = new DataInputOther(this);
    this->dataInputOther->setMyBase(uMiddleMainPage, QString("其他设置"));
    this->dataInputOther->hide();

    this->dataInputCalibratePage = new DataInputCalibratePage(this);
    this->dataInputCalibratePage->setMyBase(uMiddleMainPage, QString("屏幕校准"));
    this->dataInputCalibratePage->hide();

    this->dataInputSplitLinePage = new DataInputSplitLinePage(this);
    this->dataInputSplitLinePage->setMyBase(uMiddleMainPage, QString("分相线路"));
    this->dataInputSplitLinePage->hide();

    this->header = new Header(this);
    this->header->setMyBase(uBottom,QString("提示"));
    this->header->show();

    //add maindata pages

    this->mainData_TrainOutline = new MainData_TrainOutline(this);
    this->mainData_TrainOutline->setMyBase(uMiddleTrainData,QString("机车概况"));
    this->mainData_TrainOutline->hide();

    //add setting pages
    this->settng_Bypass = new Settng_Bypass(this);
    this->settng_Bypass->setMyBase(uMiddleControl,QString("隔离"));
    this->settng_Bypass->hide();

    this->settng_Test = new Settng_Test(this);
    this->settng_Test->setMyBase(uMiddleControl,QString("运行测试"));
    this->settng_Test->hide();

    this->settng_Panto = new Settng_Panto(this);
    this->settng_Panto->setMyBase(uMiddleControl,QString("受电弓"));
    this->settng_Panto->hide();

    this->settng_Distance = new Settng_Distance(this);
    this->settng_Distance->setMyBase(uMiddleControl,QString("距离计数"));
    this->settng_Distance->hide();


    //add driver pages
    this->deviceData_TrainOutline = new DeviceData_TrainOutline(this);
    this->deviceData_TrainOutline->setMyBase(uMiddleDeviceData,QString("驱动概述"));
    this->deviceData_TrainOutline->hide();

    //add tracbrake pages
    this->deviceData_TracBrakeOutline = new DeviceData_TracBrakeOutline(this);
    this->deviceData_TracBrakeOutline->setMyBase(uMiddleDeviceData,QString("驱动概述"));
    this->deviceData_TracBrakeOutline->hide();
    this->mainData_DriverOutline = new DeviceData_TrainOutline(this);
    this->mainData_DriverOutline->setMyBase(uMiddleControl,QString("驱动概述"));
    this->mainData_DriverOutline->hide();

    //add device_data pages
    this->deviceData_Breaker = new DeviceData_Breaker(this);
    this->deviceData_Breaker->setMyBase(uMiddleDeviceData,QString("断路器"));
    this->deviceData_Breaker->hide();

    this->deviceData_ACU = new DeviceData_ACU(this);
    this->deviceData_ACU->setMyBase(uMiddleDeviceData,QString("辅助"));
    this->deviceData_ACU->hide();

    this->deviceData_Version = new DeviceData_Version(this);
    this->deviceData_Version->setMyBase(uMiddleDeviceData,QString("软件版本"));
    this->deviceData_Version->hide();

    this->deviceData_Online = new DeviceData_Online(this);
    this->deviceData_Online->setMyBase(uMiddleDeviceData,QString("在线状态"));
    this->deviceData_Online->hide();

    //maintaince
    this->main_Simulate=new Main_Simulate(this);
    this->main_Simulate->setMyBase(uMiddleMain,QString("仿真测试"));
    this->main_Simulate->hide();
    this->main_Lubrication=new Main_Lubrication(this);
    this->main_Lubrication->setMyBase(uMiddleMain,QString("轮缘"));
    this->main_Lubrication->hide();
    this->main_AssistantDevice=new Main_AssistantDevice(this);
    this->main_AssistantDevice->setMyBase(uMiddleMain,QString("辅助测试"));
    this->main_AssistantDevice->hide();
    this->main_380=new Main_380(this);
    this->main_380->setMyBase(uMiddleMain,QString("库内380"));
    this->main_380->hide();
    this->main_Separation=new Main_Separation(this);
    this->main_Separation->setMyBase(uMiddleMain,QString("过分相测试"));
    this->main_Separation->hide();
    this->main_DoublePanto=new Main_DoublePanto(this);
    this->main_DoublePanto->setMyBase(uMiddleMain,QString("双弓测试"));
    this->main_DoublePanto->hide();
    this->deviceData_MainConv = new DeviceData_MainConv(this);
    this->deviceData_MainConv->setMyBase(uMiddleDeviceData,QString("主变流"));
    this->deviceData_MainConv->hide();

    this->deviceData_IO = new DeviceData_IO(this);
    this->deviceData_IO->setMyBase(uMiddleDeviceData,QString("信号状态"));
    this->deviceData_IO->hide();


    this->fault_History = new Fault_HIstory(this);
    this->fault_History->setMyBase(uMiddleFault,QString("历史故障"));
    this->fault_History->hide();

    this->main_Allportdata = new Main_Allportdata(this);
    this->main_Allportdata->setMyBase(uMiddleFault,QString("数据监控"));
    this->main_Allportdata->hide();

    this->widgets.insert(uVehicleRunStatePage,this->vehicleRunStatePage);
    this->widgets.insert(uMainData_TrainOutline,this->mainData_TrainOutline);
    this->widgets.insert(uSettng_Bypass,this->settng_Bypass);
    this->widgets.insert(uDeviceData_TrainOutline,this->deviceData_TrainOutline);
    this->widgets.insert(uDeviceData_TracBrake,this->deviceData_TracBrakeOutline);

    this->widgets.insert(uSettng_Test,this->settng_Test);
    this->widgets.insert(uSettng_Panto,this->settng_Panto);
    this->widgets.insert(uSettng_Distance,this->settng_Distance);
    this->widgets.insert(uDeviceData_Breaker,this->deviceData_Breaker);
    this->widgets.insert(uDeviceData_ACU,this->deviceData_ACU);
    this->widgets.insert(uDeviceData_Version,this->deviceData_Version);

    this->widgets.insert(uDeviceData_TrainOutline,this->mainData_DriverOutline);
    this->widgets.insert(uDeviceData_Online,this->deviceData_Online);
    this->widgets.insert(uDeviceData_MainConv,this->deviceData_MainConv);
    this->widgets.insert(uDeviceData_IO,this->deviceData_IO);

    //数据输入

    this->widgets.insert(uDataInputWheelPage, this->dataInputWheelPage);
    this->widgets.insert(uDataInputDateTimePage, this->dataInputDateTimePage);
    this->widgets.insert(uDataInputOther, this->dataInputOther);
    this->widgets.insert(uDataInputCalibratePage, this->dataInputCalibratePage);
    this->widgets.insert(uDataInputLubricatePage, this->dataInputLubricatePage);
    this->widgets.insert(uDataInputSplitLinePage, this->dataInputSplitLinePage);
    this->widgets.insert(uFault_History, this->fault_History);
    this->widgets.insert(uMain_Allportdata, this->main_Allportdata);

    this->widgets.insert(uMain_Simulate,this->main_Simulate);
    this->widgets.insert(uMain_Lubrication,this->main_Lubrication);
    this->widgets.insert(uMain_AssistantDevice,this->main_AssistantDevice);
    this->widgets.insert(uMain_380,this->main_380);
    this->widgets.insert(uMain_Separation,this->main_Separation);
    this->widgets.insert(uMain_DoublePanto,this->main_DoublePanto);

    this->navigator->setPageName(this->widgets[uVehicleRunStatePage]->name);
    crrcMvb = CrrcMvb::getCrrcMvb();


    ctrlDialog = new CtrlDialog(this);
    ctrlDialog->setGeometry(125,150,ctrlDialog->width(),ctrlDialog->height());
    ctrlDialog->hide();
    connect(ctrlDialog,SIGNAL(passwordResponse()),navigator,SLOT(getpasswordResponse()));
    connect(navigator,SIGNAL(passwordRequest()),ctrlDialog,SLOT(getpasswordRequest()));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::updatePage()
{
    static int counter = 1;
    this->navigator->updatePage();
    this->widgets[MyBase::currentPage]->updatePage();

    // update comm data,some base logic
    if(counter%2 == 0)
    {
        crrcMvb->synchronizeMvbData();
        this->simulation->installMvb(CrrcMvb::getCrrcMvb());
        this->database->updateData();
    }
    // start fault scanning thread
    static int faultdelaycnt = 45;
    if ((faultdelaycnt++ > 45) && !crrcFault->isRunning())
    {
        crrcFault->start();
    }
    // define local time for recording and showing
//       QDateTime dateTimeLocal;
//       if(this->database->PUBPORT_CCUOnline_B1 && faultdelaycnt>45)
//       {
//           VCUtime2HMI10s();

//           QDate date( this->database->CTAL_SysTimeYear_U8+2000,this->database->CTAL_SysTimeMonth_U8,this->database->CTAL_SysTimeDay_U8  );
//           QTime time( this->database->CTAL_SysTimeHour_U8, this->database->CTAL_SysTimeMinute_U8, this->database->CTAL_SysTimeSecond_U8);

//           this->database->HMI_DateTime_foruse.setDate(date);
//           this->database->HMI_DateTime_foruse.setTime(time);


//           if(this->database->HMI_DateTime_foruse.isValid())
//           {

//           }else
//           {
//               this->database->HMI_DateTime_foruse.setDate(dateTimeLocal.currentDateTime().date());
//               this->database->HMI_DateTime_foruse.setTime(dateTimeLocal.currentDateTime().time());
//           }
//       }else
//       {
//           this->database->HMI_DateTime_foruse.setDate(dateTimeLocal.currentDateTime().date());
//           this->database->HMI_DateTime_foruse.setTime(dateTimeLocal.currentDateTime().time());
//       }
//       this->crrcFault->getLocalDateTime(this->database->HMI_DateTime_foruse);
       QDateTime dateTimeLocal;

       this->crrcFault->getLocalDateTime(dateTimeLocal.currentDateTime());

    counter >= 100 ? (counter = 1) : (counter ++);



}
void Widget::changePage(int page)
{
    foreach (int key, this->widgets.keys())
    {
        if (key == page)
        {
            MyBase::currentPage = page;
            this->widgets[page]->show();

            this->navigator->setPageName(this->widgets[page]->name);

            _LOG << "change page to" << this->widgets[page]->name;
        }
        else
        {
            this->widgets[key]->hide();
        }
    }
    //navigator->updateButtonsNamesByPositon(this->widgets[MyBase::currentPage]->Position);

}
void Widget::showEvent(QShowEvent *)
{
    if(MainGetDefaultPara::configureValid())
    {
#ifndef WINDOWS_MODE

        if(!crrcMvb->initializeMvb())
        {
            logger()->error("MVB板卡初始化失败");
        }
        //add ports
        {
            CrrcMvb::getCrrcMvb()->addSourcePort(0xfff,MVB_FCode4,32);
            for(int i = 0;i < 32;i++)
            {
                CrrcMvb::getCrrcMvb()->setUnsignedChar(0xfff,i,0);
            }

            //source
            CrrcMvb::getCrrcMvb()->addSourcePort(0x300,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSourcePort(0x301,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSourcePort(0x302,MVB_FCode4,128);

            //sink
            //acu
            CrrcMvb::getCrrcMvb()->addSinkPort(0x103,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x104,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x105,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x113,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x114,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x115,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x100,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x110,MVB_FCode4,64);

            //bcu
            CrrcMvb::getCrrcMvb()->addSinkPort(0x136,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x1f,MVB_FCode4,128);

            //riom
            CrrcMvb::getCrrcMvb()->addSinkPort(0x200,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x207,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x210,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x214,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x217,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x220,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x227,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x208,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x218,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x228,MVB_FCode4,64);

            //ddu
            CrrcMvb::getCrrcMvb()->addSinkPort(0x710,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x711,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x712,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x713,MVB_FCode4,128);

            //cmd
            CrrcMvb::getCrrcMvb()->addSinkPort(0x310,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x320,MVB_FCode4,128);

            //tcu
            CrrcMvb::getCrrcMvb()->addSinkPort(0x400,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x401,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x402,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x410,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x411,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x412,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x420,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x421,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x422,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x430,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x431,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x432,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x500,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x501,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x502,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x503,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x530,MVB_FCode4,64);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x531,MVB_FCode4,64);


            //tcn
            CrrcMvb::getCrrcMvb()->addSinkPort(0x600,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x601,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x602,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x603,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x604,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x605,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x606,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x607,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x608,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x609,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x60a,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x60b,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x60c,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x60d,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x60e,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x60f,MVB_FCode4,128);

            CrrcMvb::getCrrcMvb()->addSinkPort(0x610,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x611,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x612,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x613,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x614,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x615,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x616,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x617,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x618,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x619,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x61a,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x61b,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x61c,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x61d,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x61e,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x61f,MVB_FCode4,128);

            CrrcMvb::getCrrcMvb()->addSinkPort(0x620,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x621,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x622,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x623,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x624,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x625,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x626,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x627,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x628,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x629,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x62a,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x62b,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x62c,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x62d,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x62e,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x62f,MVB_FCode4,128);

            CrrcMvb::getCrrcMvb()->addSinkPort(0x630,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x631,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x632,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x633,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x634,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x635,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x636,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x637,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x638,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x639,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x63a,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x63b,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x63c,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x63d,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x63e,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x63f,MVB_FCode4,128);

            CrrcMvb::getCrrcMvb()->addSinkPort(0x700,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x701,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x702,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x703,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0x704,MVB_FCode4,128);
            //virtual ports 62b-631  3分时  0x162b~0x362b
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x162b,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x162c,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x162d,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x162e,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x162f,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x1630,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x1631,MVB_FCode4);

            CrrcMvb::getCrrcMvb()->addVirtualPort(0x262b,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x262c,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x262d,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x262e,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x262f,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x2630,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x2631,MVB_FCode4);

            CrrcMvb::getCrrcMvb()->addVirtualPort(0x362b,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x362c,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x362d,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x362e,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x362f,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x3630,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x3631,MVB_FCode4);
            //virtual ports 702  3分时  0x1702~0x3702
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x1702,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x2702,MVB_FCode4);
            CrrcMvb::getCrrcMvb()->addVirtualPort(0x3702,MVB_FCode4);

            //ato
            CrrcMvb::getCrrcMvb()->addSinkPort(0xfb0,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0xfc0,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0xfc1,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0xfc2,MVB_FCode4,128);
            CrrcMvb::getCrrcMvb()->addSinkPort(0xfc3,MVB_FCode4,128);




        }
#endif

        if(crrcMvb->InitReadPortData())
        {
            logger()->error("MVB板卡设置操作模式失败");
        }

        timer->start(333);
    }else
    {
        logger()->error("configure.ini文件错误");
        _LOG << "fail to read configure file.";
    }

}


void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        this->close();
    }else if (event->key() == Qt::Key_S)
    {
        QDesktopWidget *desktop = QApplication::desktop();

        // show a window uesd to manipulate the mvb ports and change page

        simulation->move((desktop->width() - simulation->width()) / 2, (desktop->height() - simulation->height()) / 2);
        simulation->show();
    }
}
void Widget::translateLanguage()
{
    QTranslator *translator = new QTranslator(0);
    static bool t_istranslate = false;
    if(t_istranslate)
    {
        qApp->removeTranslator(translator);
    }else
    {
        translator->load("language_en.qm");
        qApp->installTranslator(translator);
    }
    t_istranslate = !t_istranslate;
    foreach(int i,this->widgets.keys())
    {
        this->widgets[i]->updateLanguage();
    }

    delete translator;
}
