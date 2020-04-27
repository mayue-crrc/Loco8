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

        T1_B_AXLE_ISO_REL_ALLOW[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),0,7);//允许取消轴x隔离
        T1_B_EBRK_ISO_REL_ALLOW[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),0,6);//允许取消电制动隔离
        T1_B_INVT_SELT_TEST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),0,3);//逆变器正常
        T1_B_TCU_SELT_TEST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),0,2);//TCU自检状态
        T1_B_ANTI_SLIP_SAND[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),0,1);//制动防滑撒砂请求
        T1_B_ANTI_RACING_SAND[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),0,0);//防空转撒沙请求
        T1_B_INVT_RUN[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),1,7);//逆变器运行指示
        T1_B_KA_PC_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),1,6);//充电接触器正常
        T1_B_4Q_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),1,4);//整流器正常
        T1_B_KA_WORK_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),1,2);//工作接触器正常
        T1_B_AXLE_DEGRADE[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),1,0);//轴减小的功率指示（降功率）
        T1_B_AXLE_EBRK_ISO[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),2,7);//轴电制动隔离指示
        T1_B_AXLE_ISO[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),2,6);//轴隔离
        T1_B_AXLE_EBRK_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),2,5);//轴电制动正常
        T1_B_EBRK_ON[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),2,4);//电制动正在施加
        T1_B_ANSC_PR_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),2,3);//过分相准备完毕信号
        T1_B_ANSC_RE_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),2,2);//过分相恢复完毕信号
        T1_B_CARB_PPC_OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),2,1);//库内动车预充电完成信号
        T1_B_NO_TB[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),3,7);//脉冲封锁
        T1_B_4Q_ISO[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),3,6);//四象限隔离
        T1_B_T_CHAR[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),3,0);//牵引/制动特性反馈
        T1_B_4Q_FAULT1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),8,7);//四象限硬件故障
        T1_B_4Q_FAULT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),8,6);//四象限故障预留2
        T1_B_4Q_FAULT3[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),8,5);//四象限直流回路过压
        T1_B_4Q_FAULT4[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),8,4);//四象限直流回路欠压
        T1_B_4Q_FAULT5[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),8,3);//四象限输入过流
        T1_B_4Q_FAULT6[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),8,2);//四象限输入短路故障
        T1_B_4Q_FAULT7[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),8,1);//四象限充电故障
        T1_B_4Q_FAULT8[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),8,0);//四象限网压过压
        T1_B_4Q_FAULT9[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),9,7);//四象限网压欠压
        T1_B_4Q_FAULT10[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),9,6);//四象限接地保护
        T1_B_4Q_FAULT11[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),9,5);//四象限水温异常
        T1_B_4Q_FAULT12[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),9,4);//四象限水压异常
        T1_B_4Q_FAULT13[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),9,3);//四象限变压器原边过流
        T1_B_4Q_FAULT14[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),9,2);//四象限变压器温度异常
        T1_B_4Q_FAULT15[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),9,1);//四象限自检异常
        T1_B_4Q_FAULT16[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),9,0);//四象限同步信号异常
        T1_B_4Q_FAULT17[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),10,7);//四象限1充电接触器卡合
        T1_B_4Q_FAULT18[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),10,6);//四象限故障预留18
        T1_B_4Q_FAULT19[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),10,5);//四象限1工作接触器卡合
        T1_B_4Q_FAULT20[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),10,4);//四象限1工作接触器卡分
        T1_B_4Q_FAULT21[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),10,3);//四象限中间直流短路故障
        T1_B_4Q_FAULT22[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),10,2);//四象限A相上桥臂故障
        T1_B_4Q_FAULT23[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),10,1);//四象限A相下桥臂故障
        T1_B_4Q_FAULT24[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),10,0);//四象限B相上桥臂故障
        T1_B_4Q_FAULT25[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),11,7);//四象限B相下桥臂故障
        T1_B_4Q_FAULT26[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),11,6);//四象限1同步信号反向
        T1_B_4Q_FAULT27[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),11,5);//四象限1输入电流传感器断路
        T1_B_4Q_FAULT28[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),11,4);//四象限1斩波电阻过温
        T1_B_4Q_FAULT29[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),11,3);//不可用(四象限2和3有对应故障)
        T1_B_4Q_FAULT30[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),11,2);//四象限故障预留30
        T1_B_4Q_FAULT31[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),11,1);//四象限故障预留31
        T1_B_4Q_FAULT32[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),11,0);//四象限1充电接触器卡分
        T1_B_INVT_FAULT1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),12,7);//逆变器驱动或硬件故障
        T1_B_INVT_FAULT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),12,6);//逆变器斩波驱动或硬件故障
        T1_B_INVT_FAULT3[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),12,5);//逆变器直流母线过压
        T1_B_INVT_FAULT4[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),12,4);//逆变器故障预留4
        T1_B_INVT_FAULT5[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),12,3);//逆变器电机过流
        T1_B_INVT_FAULT6[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),12,2);//逆变器电机转速检测故障
        T1_B_INVT_FAULT7[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),12,1);//逆变器输出缺相
        T1_B_INVT_FAULT8[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),12,0);//逆变器电机过温
        T1_B_INVT_FAULT9[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),13,7);//逆变器斩波过流
        T1_B_INVT_FAULT10[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),13,6);//逆变器斩波电阻过温
        T1_B_INVT_FAULT11[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),13,5);//逆变器1斩波电路故障
        T1_B_INVT_FAULT12[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),13,4);//逆变器1斩波脉冲故障
        T1_B_INVT_FAULT13[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),13,3);//逆变器U相过流
        T1_B_INVT_FAULT14[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),13,2);//逆变器V相过流
        T1_B_INVT_FAULT15[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),13,1);//逆变器W相过流
        T1_B_INVT_FAULT16[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),13,0);//逆变器故障预留16
        T1_B_INVT_FAULT17[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),14,7);//逆变器方向指令故障
        T1_B_INVT_FAULT18[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),14,6);//逆变器故障预留18
        T1_B_INVT_FAULT19[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),14,5);//逆变器自检故障
        T1_B_INVT_FAULT20[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),14,4);//逆变器库内充电故障
        T1_B_INVT_FAULT21[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),14,3);//逆变器库内过压故障
        T1_B_INVT_FAULT22[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),14,2);//逆变器轴没有牵引力
        T1_B_INVT_FAULT23[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),14,1);//逆变器1U相上桥臂驱动故障
        T1_B_INVT_FAULT24[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),14,0);//逆变器1U相下桥臂驱动故障
        T1_B_INVT_FAULT25[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),15,7);//逆变器1V相上桥臂驱动故障
        T1_B_INVT_FAULT26[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),15,6);//逆变器1V相下桥臂驱动故障
        T1_B_INVT_FAULT27[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),15,5);//逆变器1W相上桥臂驱动故障
        T1_B_INVT_FAULT28[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),15,4);//逆变器1W相下桥臂驱动故障
        T1_B_INVT_FAULT29[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),15,3);//逆变器1斩波器驱动故障
        T1_B_INVT_FAULT30[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),15,2);//逆变器故障预留30
        T1_B_INVT_FAULT31[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),15,1);//逆变器故障预留31
        T1_B_INVT_FAULT32[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),15,0);//逆变器故障预留32
        T1_B_RLD[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),31,3);//RLD
        T1_B_LAT[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),31,2);//LAT
        T1_B_P400CHECK0[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),31,1);//数据校验(固定发0)
        T1_B_P400CHECK1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i),31,0);//数据校验(固定发1)
        T1_B_P401CHECK0[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i+1),31,1);//数据校验(固定发0)
        T1_B_P401CHECK1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(2*i+1),31,0);//数据校验(固定发1)

        T1_N_MOT_TEMP[i] = CrrcMvb::getCrrcMvb()->getSignedInt(m_ports.at(2*i+1),0);//电机温度
        T1_N_AXLE_FORCE[i] = CrrcMvb::getCrrcMvb()->getSignedInt(m_ports.at(2*i+1),4);//轴x牵引力的百分比

        T1_N_4Q_IN_V[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i),16);//牵引变流器输入电压
        T1_N_4Q_IN_C[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i),18);//牵引变流器输入电流
        T1_N_INVT_IN_V[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i),24);//逆变器直流母线电压
        T1_N_INVT_OUT_V[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i),26);//牵引变流器输出电压
        T1_N_INVT_OUT_C[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i),28);//牵引变流器输出电流
        T1_N_MOT_FREQ[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i+1),2);//电机频率
        T1_N_NET_VOLT_SENS[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i+1),6);//网压传感器电压值
        T1_N_SPEED[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i+1),8);//速度传感器值
        T1_N_WATER_PRESS[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i+1),24);//冷却液压力
        T1_N_WATER_TEMP[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(2*i+1),26);//冷却液温度


        T1_N_TCU_LIFE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(2*i),30);//TCU生命信号
        T1_N_GW_VER[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(2*i+1),14);//版本号1(网关)
        T1_N_4Q_VER[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(2*i+1),15);//版本号2(整流)
        T1_N_INVT_VER[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(2*i+1),16);//版本号3(逆变)
        T1_N_BAK_VER[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(2*i+1),17);//版本号4(备用)
        T1_N_4Q_LIFE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(2*i+1),18);//四象限生命信号
        T1_N_INVT_LIFE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(2*i+1),19);//逆变器生命信号
    }


}
