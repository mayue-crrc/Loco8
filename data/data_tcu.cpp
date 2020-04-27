#include "data_tcu.h"
#include "crrcmvb.h"
Data_TCU::Data_TCU()
{
    m_ports<<0x400<<0x401<<0x410<<0x411<<0x420<<0x421<<0x430<<0x431;
}
void Data_TCU::updateData()
{
    for(int i = 0;i<4;i++)
    {


        AXLE_ISO_REL_ALLOW[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),0,0);//允许取消轴x隔离
        EBRK_ISO_REL_ALLOW[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),0,1);//允许取消电制动隔离
        INVT_SELT_TEST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),0,4);//逆变器正常
        TCU_SELT_TEST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),0,5);//TCU自检状态
        ANTI_SLIP_SAND[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),0,6);//制动防滑撒砂请求
        ANTI_RACING_SAND[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),0,7);//防空转撒沙请求
        INVT_RUN[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),1,0);//逆变器运行指示
        KA_PC_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),1,1);//充电接触器正常
        Q4Q_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),1,3);//整流器正常
        KA_WORK_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),1,5);//工作接触器正常
        AXLE_DEGRADE[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),1,7);//轴减小的功率指示（降功率）
        AXLE_EBRK_ISO[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),2,0);//轴电制动隔离指示
        AXLE_ISO[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),2,1);//轴隔离
        AXLE_EBRK_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),2,2);//轴电制动正常
        EBRK_ON[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),2,3);//电制动正在施加
        ANSC_PR_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),2,4);//过分相准备完毕信号
        ANSC_RE_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),2,5);//过分相恢复完毕信号
        CARB_PPC_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),2,6);//库内动车预充电完成信号
        NO_TB[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),3,0);//脉冲封锁
        Q4Q_ISO[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),3,1);//四象限隔离
        T_CHAR[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),3,7);//牵引/制动特性反馈
        Q4Q_FAULT1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),8,0);//四象限硬件故障
        Q4Q_FAULT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),8,1);//四象限故障预留2
        Q4Q_FAULT3[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),8,2);//四象限直流回路过压
        Q4Q_FAULT4[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),8,3);//四象限直流回路欠压
        Q4Q_FAULT5[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),8,4);//四象限输入过流
        Q4Q_FAULT6[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),8,5);//四象限输入短路故障
        Q4Q_FAULT7[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),8,6);//四象限充电故障
        Q4Q_FAULT8[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),8,7);//四象限网压过压
        Q4Q_FAULT9[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),9,0);//四象限网压欠压
        Q4Q_FAULT10[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),9,1);//四象限接地保护
        Q4Q_FAULT11[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),9,2);//四象限水温异常
        Q4Q_FAULT12[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),9,3);//四象限水压异常
        Q4Q_FAULT13[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),9,4);//四象限变压器原边过流
        Q4Q_FAULT14[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),9,5);//四象限变压器温度异常
        Q4Q_FAULT15[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),9,6);//四象限自检异常
        Q4Q_FAULT16[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),9,7);//四象限同步信号异常
        Q4Q_FAULT17[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),10,0);//四象限1充电接触器卡合
        Q4Q_FAULT18[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),10,1);//四象限故障预留18
        Q4Q_FAULT19[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),10,2);//四象限1工作接触器卡合
        Q4Q_FAULT20[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),10,3);//四象限1工作接触器卡分
        Q4Q_FAULT21[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),10,4);//四象限中间直流短路故障
        Q4Q_FAULT22[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),10,5);//四象限A相上桥臂故障
        Q4Q_FAULT23[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),10,6);//四象限A相下桥臂故障
        Q4Q_FAULT24[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),10,7);//四象限B相上桥臂故障
        Q4Q_FAULT25[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),11,0);//四象限B相下桥臂故障
        Q4Q_FAULT26[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),11,1);//四象限1同步信号反向
        Q4Q_FAULT27[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),11,2);//四象限1输入电流传感器断路
        Q4Q_FAULT28[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),11,3);//四象限1斩波电阻过温
        Q4Q_FAULT29[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),11,4);//不可用(四象限2和3有对应故障)
        Q4Q_FAULT30[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),11,5);//四象限故障预留30
        Q4Q_FAULT31[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),11,6);//四象限故障预留31
        Q4Q_FAULT32[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),11,7);//四象限1充电接触器卡分
        INVT_FAULT1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),12,0);//逆变器硬件故障
        INVT_FAULT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),12,1);//逆变器斩波硬件故障
        INVT_FAULT3[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),12,2);//逆变器直流母线过压
        INVT_FAULT4[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),12,3);//逆变器故障预留4
        INVT_FAULT5[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),12,4);//逆变器电机过流
        INVT_FAULT6[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),12,5);//逆变器电机转速检测故障
        INVT_FAULT7[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),12,6);//逆变器输出缺相
        INVT_FAULT8[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),12,7);//逆变器电机过温
        INVT_FAULT9[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),13,0);//逆变器斩波过流
        INVT_FAULT10[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),13,1);//逆变器斩波电阻过温
        INVT_FAULT11[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),13,2);//逆变器1斩波电路故障
        INVT_FAULT12[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),13,3);//逆变器1斩波脉冲故障
        INVT_FAULT13[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),13,4);//逆变器U相过流
        INVT_FAULT14[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),13,5);//逆变器V相过流
        INVT_FAULT15[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),13,6);//逆变器W相过流
        INVT_FAULT16[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),13,7);//逆变器故障预留16
        INVT_FAULT17[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),14,0);//逆变器方向指令故障
        INVT_FAULT18[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),14,1);//逆变器故障预留18
        INVT_FAULT19[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),14,2);//逆变器自检故障
        INVT_FAULT20[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),14,3);//逆变器库内充电故障
        INVT_FAULT21[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),14,4);//逆变器库内过压故障
        INVT_FAULT22[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),14,5);//逆变器轴没有牵引力
        INVT_FAULT23[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),14,6);//逆变器1U相上桥臂驱动故障
        INVT_FAULT24[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),14,7);//逆变器1U相下桥臂驱动故障
        INVT_FAULT25[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),15,0);//逆变器1V相上桥臂驱动故障
        INVT_FAULT26[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),15,1);//逆变器1V相下桥臂驱动故障
        INVT_FAULT27[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),15,2);//逆变器1W相上桥臂驱动故障
        INVT_FAULT28[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),15,3);//逆变器1W相下桥臂驱动故障
        INVT_FAULT29[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),15,4);//逆变器1斩波器驱动故障
        INVT_FAULT30[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),15,5);//电机速度传感器A路信号异常
        INVT_FAULT31[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),15,6);//电机速度传感器B路信号异常
        INVT_FAULT32[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),15,7);//逆变器故障预留32
        RLD[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),31,4);//RLD
        LAT[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),31,5);//LAT
        P400CHECK0[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),31,6);//数据校验(固定发0)
        P400CHECK1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2),31,7);//数据校验(固定发1)
        P401CHECK0[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2+1),31,6);//数据校验(固定发0)
        P401CHECK1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i*2+1),31,7);//数据校验(固定发1)

        MOT_TEMP[i] = CrrcMvb::getCrrcMvb()->getSignedInt(m_ports.at(i*2+1),0);//电机温度
        AXLE_FORCE[i] = CrrcMvb::getCrrcMvb()->getSignedInt(m_ports.at(i*2+1),4);//轴x牵引力的百分比

        Q4Q_IN_V[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2),16);//牵引变流器输入电压
        Q4Q_IN_C[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2),18);//牵引变流器输入电流
        INVT_IN_V[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2),24);//逆变器直流母线电压
        INVT_OUT_V[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2),26);//牵引变流器输出电压
        INVT_OUT_C[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2),28);//牵引变流器输出电流
        MOT_FREQ[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2+1),2);//电机频率
        NET_VOLT_SENS[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2+1),6);//网压传感器电压值
        SPEED[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2+1),8);//速度传感器值
        WATER_PRESS[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2+1),24);//冷却液压力
        WATER_TEMP[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2+1),26);//冷却液温度
        TCU1_PulseBlock[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i*2+1),28);//脉冲封锁条件

        TCU_LIFE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i*2),30);//TCU生命信号
        GW_VER[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i*2+1),14);//版本号1(网关)
        Q4Q_VER[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i*2+1),15);//版本号2(整流)
        INVT_VER[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i*2+1),16);//版本号3(逆变)
        BAK_VER[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i*2+1),17);//版本号4(备用)
        Q4Q_LIFE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i*2+1),18);//四象限生命信号
        INVT_LIFE [i]= CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i*2+1),19);//逆变器生命信号
    }


    AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,0,2);//轴1隔离请求
    AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,0,3);//轴2隔离请求
    AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,0,4);//轴3隔离请求
    AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,0,5);//轴4隔离请求
    AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,1,2);//轴1隔离取消请求
    AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,1,3);//轴2隔离取消请求
    AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,1,4);//轴3隔离取消请求
    AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,1,5);//轴4隔离取消请求
    MCNVT_UNLOAD = CrrcMvb::getCrrcMvb()->getBool(0x530,2,0);//主变流器卸载
    QFM_DIS = CrrcMvb::getCrrcMvb()->getBool(0x530,2,1);//主断路器状态(断）
    QFM_C = CrrcMvb::getCrrcMvb()->getBool(0x530,2,2);//主断路器状态（合）
    PANTO_R = CrrcMvb::getCrrcMvb()->getBool(0x530,2,3);//受电弓升起
    CS_MODE = CrrcMvb::getCrrcMvb()->getBool(0x530,2,4);//定速模式
    ANSC_ST = CrrcMvb::getCrrcMvb()->getBool(0x530,2,5);//过分相开始信号
    ANSC_END = CrrcMvb::getCrrcMvb()->getBool(0x530,2,6);//过分相结束信号
    ANSC_CMPLT = CrrcMvb::getCrrcMvb()->getBool(0x530,2,7);//过分相完成信号
    ANSC_FORCE_OFF = CrrcMvb::getCrrcMvb()->getBool(0x530,3,0);//MPU断主断信号
    FAULT_RESET = CrrcMvb::getCrrcMvb()->getBool(0x530,3,3);//故障复位
    AUX1_ISO = CrrcMvb::getCrrcMvb()->getBool(0x530,3,4);//辅助1隔离
    AUX2_ISO = CrrcMvb::getCrrcMvb()->getBool(0x530,3,5);//辅助2隔离
    EBRAKE = CrrcMvb::getCrrcMvb()->getBool(0x530,3,6);//电控紧急
    EMGBRK = CrrcMvb::getCrrcMvb()->getBool(0x530,3,7);//紧急制动
    AXLE1_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,24,0);//轴1电制动隔离
    AXLE1_EBRK_REL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,24,1);//轴1电制动隔离取消
    AXLE2_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,24,2);//轴2电制动隔离
    AXLE2_EBRK_REL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,24,3);//轴2电制动隔离取消
    AXLE3_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,24,4);//轴3电制动隔离
    AXLE3_EBRK_REL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,24,5);//轴3电制动隔离取消
    AXLE4_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,24,6);//轴4电制动隔离
    AXLE4_EBRK_REL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,24,7);//轴4电制动隔离取消
    SEQUENCE_TEST = CrrcMvb::getCrrcMvb()->getBool(0x530,25,2);//低压顺序试验激活
    H_HT = CrrcMvb::getCrrcMvb()->getBool(0x530,25,3);//本节高压隔离开关状态
    AXLE2_MOVE = CrrcMvb::getCrrcMvb()->getBool(0x530,25,4);//2轴动车
    T_CAHR = CrrcMvb::getCrrcMvb()->getBool(0x530,25,6);//牵引特性设定
    Q4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,26,0);//四象限1隔离请求
    Q4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,26,1);//四象限2隔离请求
    Q4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,26,2);//四象限3隔离请求
    Q4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,26,3);//四象限4隔离请求
    Q4Q1_REL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,26,4);//四象限1隔离取消请求
    Q4Q2_REL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,26,5);//四象限2隔离取消请求
    Q4Q3_REL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,26,6);//四象限3隔离取消请求
    Q4Q4_REL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x530,26,7);//四象限4隔离取消请求
    P530CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x530,31,6);//数据校验(固定发0)
    P530CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x530,31,7);//数据校验(固定发1)
    DJ_PE1 = CrrcMvb::getCrrcMvb()->getBool(0x531,18,0);//水泵1断路器状态
    DJ_PE2 = CrrcMvb::getCrrcMvb()->getBool(0x531,18,1);//水泵2断路器状态
    DJ_PE3 = CrrcMvb::getCrrcMvb()->getBool(0x531,18,2);//水泵3断路器状态
    DJ_PE4 = CrrcMvb::getCrrcMvb()->getBool(0x531,18,3);//水泵4断路器状态
    DJ_PH1 = CrrcMvb::getCrrcMvb()->getBool(0x531,18,4);//油泵1断路器状态
    DJ_PH2 = CrrcMvb::getCrrcMvb()->getBool(0x531,18,5);//油泵2断路器状态
    DJ_VT_SM1 = CrrcMvb::getCrrcMvb()->getBool(0x531,18,6);//机械间风机1断路器状态
    DJ_VT_SM2 = CrrcMvb::getCrrcMvb()->getBool(0x531,18,7);//机械间风机2断路器状态
    P531CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x531,31,6);//数据校验(固定发0)
    P531CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x531,31,7);//数据校验(固定发1)

    WHEEL_DIA_AXLE2 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x530,6);//2轴轮径值
    MSCT_GRD = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x530,14);//手柄级位
    CS_VALUE = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x530,20);//定速模式速度值
    LOAD = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x530,22);//牵引吨位
    SPEEDCCU = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x531,0);//机车速度（由MPU计算）
    NET_VOLT = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x531,4);//接触网电压值
    DT_YEAR = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x531,6);//系统时间（年）
    ACU1_OUTP = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x531,14);//辅变流柜1输出功率
    ACU2_OUTP = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x531,16);//辅变流柜2输出功率

    CARB_MODE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x530,9);//库内动车模式参考
    DIR_N = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x530,11);//无方向
    DIR_B = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x530,12);//方向向后
    DIR_F = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x530,13);//方向向前
    MSCT_N = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x530,18);//手柄在中立位
    IS_THIS_A = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x530,19);//当前机车位置
    MPU_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x530,30);//MPU生命信号
    DT_MONTH = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x531,8);//系统时间（月）
    DT_DAY = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x531,9);//系统时间（日）
    DT_HOUR = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x531,10);//系统时间（时）
    DT_MINUTE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x531,11);//系统时间（分）
    DT_SECOND = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x531,12);//系统时间（秒）

}
