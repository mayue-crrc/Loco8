#include "data_bcu.h"
#include "crrcmvb.h"
Data_BCU::Data_BCU()
{

}
void Data_BCU::updateData()
{

    BP_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,20,0);//
    MR_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,20,1);//
    ER_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,20,2);//
    BC1_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,20,3);//
    E_BRAKE_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,20,4);//
    BCU_Penalty_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,20,5);//
    CAB_STATE = CrrcMvb::getCrrcMvb()->getBool(0x136,20,6);//
    BCU_STATE1 = CrrcMvb::getCrrcMvb()->getBool(0x136,21,0);//
    BCU_STATE2 = CrrcMvb::getCrrcMvb()->getBool(0x136,21,1);//
    BCU_EB_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,21,2);//
    BC2_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,21,3);//
    ATP_Penalty_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,21,4);//
    TRA_BLK_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,21,5);//
    Bail_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,21,6);//
    Bail_NULL = CrrcMvb::getCrrcMvb()->getBool(0x136,21,7);//
    STATE_DBI1 = CrrcMvb::getCrrcMvb()->getBool(0x136,22,0);//
    STATE_DBI2 = CrrcMvb::getCrrcMvb()->getBool(0x136,22,1);//
    ABC_MOVED = CrrcMvb::getCrrcMvb()->getBool(0x136,22,2);//
    EMG_BRK_ISO = CrrcMvb::getCrrcMvb()->getBool(0x136,22,3);//
    PARK_BRK_ISO = CrrcMvb::getCrrcMvb()->getBool(0x136,22,4);//
    BRK_CYL_ISO = CrrcMvb::getCrrcMvb()->getBool(0x136,22,5);//
    ABH_RUN = CrrcMvb::getCrrcMvb()->getBool(0x136,23,0);//大闸运转位
    ABH_MIN = CrrcMvb::getCrrcMvb()->getBool(0x136,23,1);//大闸初制动
    ABH_SERV_Z = CrrcMvb::getCrrcMvb()->getBool(0x136,23,2);//大闸常用制动
    ABH_FULL_SERV = CrrcMvb::getCrrcMvb()->getBool(0x136,23,3);//大闸全制动
    ABH_SUPPRESS = CrrcMvb::getCrrcMvb()->getBool(0x136,23,4);//大闸抑制位
    ABH_MU = CrrcMvb::getCrrcMvb()->getBool(0x136,23,5);//大闸重连位
    ABH_EMG = CrrcMvb::getCrrcMvb()->getBool(0x136,23,6);//大闸紧急位
    BCU_FAULT1 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,0);//司机制动阀故障
    BCU_FAULT2 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,1);//司机制动阀失效
    BCU_FAULT3 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,2);//列车管控制失效
    BCU_FAULT4 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,3);//总风传感器1故障
    BCU_FAULT5 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,4);//司机室1制动控制器故障
    BCU_FAULT6 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,5);//
    BCU_FAULT7 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,6);//流量计故障
    BCU_FAULT8 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,7);//压力转换电磁阀故障
    BCU_FAULT9 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,0);//遮断阀故障
    BCU_FAULT10 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,1);//分配阀电空模块转换电磁阀故障
    BCU_FAULT11 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,2);//紧急电磁阀2故障
    BCU_FAULT12 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,3);//单缓故障
    BCU_FAULT13 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,4);//
    BCU_FAULT14 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,5);//分配阀电空模块故障
    BCU_FAULT15 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,6);//单独制动故障
    BCU_FAULT16 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,7);//
    BCU_FAULT17 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,0);//紧急制动隔离
    BCU_FAULT18 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,1);//平均管控制故障
    BCU_FAULT19 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,2);//主控/从控功能故障
    BCU_FAULT20 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,3);//制动缸传感器故障
    BCU_FAULT21 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,4);//制动显示屏故障
    BCU_FAULT22 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,5);//停放制动传感器故障
    BCU_FAULT23 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,6);//列车管控制故障
    BCU_FAULT24 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,7);//CAN(控制器局域网)总线故障
    BCU_FAULT25 = CrrcMvb::getCrrcMvb()->getBool(0x136,27,0);//总风传感器故障
    BCU_FAULT26 = CrrcMvb::getCrrcMvb()->getBool(0x136,27,1);//制动控制单元启动故障
    BCU_FAULT27 = CrrcMvb::getCrrcMvb()->getBool(0x136,27,2);//MVB(多功能车辆总线)通信故障
    BCU_FAULT28 = CrrcMvb::getCrrcMvb()->getBool(0x136,27,3);//中立功能故障
    AIH_RUN = CrrcMvb::getCrrcMvb()->getBool(0x136,29,0);//小闸运转位
    AIH_SERV_Z = CrrcMvb::getCrrcMvb()->getBool(0x136,29,1);//小闸常用制动
    AIH_FULL_SERV = CrrcMvb::getCrrcMvb()->getBool(0x136,29,2);//小闸全制动


    BP_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,0);//
    MR_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,2);//
    ER_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,4);//
    BC1_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,6);//
    BC2_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,8);//
    EG_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,10);//
    FLOW = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,12);//
    EBRAKE = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,14);//
    Version = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,16);//

    BCU_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x136,28);//



    LocoSpeedValid = CrrcMvb::getCrrcMvb()->getBool(0x1F,8,0);//
    PenaltyBrakeRQ = CrrcMvb::getCrrcMvb()->getBool(0x1F,9,0);//
    EmerBrakeRQ = CrrcMvb::getCrrcMvb()->getBool(0x1F,9,1);//
    TRAIL = CrrcMvb::getCrrcMvb()->getBool(0x1F,9,2);//
    DBI1_RQ = CrrcMvb::getCrrcMvb()->getBool(0x1F,9,3);//
    DBI2_RQ = CrrcMvb::getCrrcMvb()->getBool(0x1F,9,4);//
    Cab_Act = CrrcMvb::getCrrcMvb()->getBool(0x1F,9,5);//

   LocoSpeed = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x1F,0);//
   MPU_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x1F,15);//
   DateTime = CrrcMvb::getCrrcMvb()->getUnsignedInt32(0x1F,4);//



}
