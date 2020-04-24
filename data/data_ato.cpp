#include "data_ato.h"
#include "crrcmvb.h"
Data_ATO::Data_ATO()
{

}
void Data_ATO::updateData()
{
    B_MSCT_T = CrrcMvb::getCrrcMvb()->getBool(0xFB0,2,0);//牵引
    B_MSCT_B = CrrcMvb::getCrrcMvb()->getBool(0xFB0,2,1);//制动
    B_MODE_ATO = CrrcMvb::getCrrcMvb()->getBool(0xFB0,3,0);//自动驾驶模式
    B_AUTOMODE_ACTIVE = CrrcMvb::getCrrcMvb()->getBool(0xFB0,6,0);//自动驾驶激活
    B_AUTOMODE_EXIT = CrrcMvb::getCrrcMvb()->getBool(0xFB0,6,1);//自动驾驶退出
    B_CAB1_ACTIVE = CrrcMvb::getCrrcMvb()->getBool(0xFB0,6,2);//I端屏激活
    B_CAB2_ACTIVE = CrrcMvb::getCrrcMvb()->getBool(0xFB0,6,3);//II端屏激活
    B_SAND_RQ1 = CrrcMvb::getCrrcMvb()->getBool(0xFB0,6,4);//撒砂请求
    B_ABH_RUN = CrrcMvb::getCrrcMvb()->getBool(0xFB0,8,0);//大闸运转位
    B_ABH_MIN = CrrcMvb::getCrrcMvb()->getBool(0xFB0,8,1);//大闸初制动
    B_ABH_SERV_Z = CrrcMvb::getCrrcMvb()->getBool(0xFB0,8,2);//大闸常用制动
    B_ABH_FULL_SERV = CrrcMvb::getCrrcMvb()->getBool(0xFB0,8,3);//大闸全制动
    B_ABH_SUPPRESS = CrrcMvb::getCrrcMvb()->getBool(0xFB0,8,4);//大闸抑制位
    B_ABH_MU = CrrcMvb::getCrrcMvb()->getBool(0xFB0,8,5);//大闸重连位
    B_ABH_EMG = CrrcMvb::getCrrcMvb()->getBool(0xFB0,8,6);//大闸紧急位
    B_AIH_RUN = CrrcMvb::getCrrcMvb()->getBool(0xFB0,9,0);//小闸运转位
    B_AIH_SERV_Z = CrrcMvb::getCrrcMvb()->getBool(0xFB0,9,1);//小闸常用制动
    B_AIH_FULL_SERV = CrrcMvb::getCrrcMvb()->getBool(0xFB0,9,2);//小闸全制动
    B_Bail_ACT = CrrcMvb::getCrrcMvb()->getBool(0xFB0,9,3);//小闸单缓
    B_SAND_RQ2 = CrrcMvb::getCrrcMvb()->getBool(0xFB0,9,4);//撒砂请求
    B_PCHECK0 = CrrcMvb::getCrrcMvb()->getBool(0xFB0,31,6);//数据校验（固定发0）
    B_PCHECK1 = CrrcMvb::getCrrcMvb()->getBool(0xFB0,31,7);//数据校验（固定发1）

    N_MSCT_SAMPLE = CrrcMvb::getCrrcMvb()->getUnsignedInt(0xFB0,0);//手柄级位
    N_SPEED_SET = CrrcMvb::getCrrcMvb()->getUnsignedInt(0xFB0,4);//设定速度
    B_BRAKE_ZIDONG = CrrcMvb::getCrrcMvb()->getUnsignedInt(0xFB0,10);//自动制动手柄位
    B_BRAKE_DANDU = CrrcMvb::getCrrcMvb()->getUnsignedInt(0xFB0,12);//单独制动手柄位

    N_MODE_ATO = CrrcMvb::getCrrcMvb()->getUnsignedChar(0xFB0,7);//自动驾驶模式
    N_STATE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0xFB0,16);//STO设备状态
    N_VERSION = CrrcMvb::getCrrcMvb()->getUnsignedChar(0xFB0,18);//STO版本号
    N_LIFE_SELF = CrrcMvb::getCrrcMvb()->getUnsignedChar(0xFB0,19);//STO生命信号
    N_GW_VERSION = CrrcMvb::getCrrcMvb()->getUnsignedChar(0xFB0,29);//STO网关版本号
    N_GW_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0xFB0,30);//STO网关生命信号
}
