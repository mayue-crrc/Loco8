#include "data_acu.h"
#include "crrcmvb.h"
Data_ACU::Data_ACU()
{
    m_ports<<0x100<<0x110;
}
void Data_ACU::updateData()
{
    for(int i = 0;i<2;i++)
    {
        M1_A2_B_ANDEL[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,0);//SIV load shedding cancellation
        M1_A2_B_ANISA[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,1);//Auxiliary inverter reset
        M1_A2_B_ANISB[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,2);//Battery charger reset
        M1_A2_B_DEMCB[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,3);//Battery charger starting authorization
        M1_A2_B_DISCHB[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,4);//Battery charger isolation request
        M1_A2_B_DISCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,5);//SIV isolation request
        M1_A2_B_DSCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,6);//SIV rescue mode request
        M1_A2_B_DTRDEF[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,7);//ACU faults transfer request
        M1_A2_B_ISO_REL_RQ[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,0);//隔离取消请求
        M1_A2_B_ETATMPU[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,1);//MPU Health Status
        M1_A2_B_ETATTCU[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,2);//RIOM Health Status
        M1_A2_B_1800OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,3);//中间电压1800V OK
        M1_A2_B_ANSC_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,5);//过分相开始信号
        M1_A2_B_ANSC_END[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,6);//过分相结束信号
        M1_A2_B_ANSC_CMPLT[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,7);//过分相完成信号
        M1_A2_B_AMCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,0);//CVS Set/Reset Command
        M1_A2_B_DELES[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,1);//CVS stop Command
        M1_A2_B_INUL[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,2);//O Curent Command
        M1_A2_B_C1_CPR[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,5);//压缩机接触器1状态
        M1_A2_B_C2_CPR[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,6);//压缩机接触器2状态
        M1_A2_B_C3_CPR[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,7);//压缩机接触器3状态
        M1_A2_B_VT_BM1_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,2);//冷却塔风机1测试：1测试，0停止
        M1_A2_B_VT_BM2_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,3);//冷却塔风机2测试：1测试，0停止
        M1_A2_B_VT_MT1_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,4);//牵引风机1测试：1测试，0停止
        M1_A2_B_VT_MT2_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,5);//牵引风机2测试：1测试，0停止
        M1_A2_B_VT_SM1_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,6);//机械间风机1测试：1测试，0停止
        M1_A2_B_VT_SM2_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,7);//机械间风机2测试：1测试，0停止
        M1_A2_B_ACU_FALUT33[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,0);//牵引风机1故障
        M1_A2_B_ACU_FALUT34[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,1);//牵引风机2故障
        M1_A2_B_ACU_FALUT35[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,2);//冷却塔风机1故障
        M1_A2_B_ACU_FALUT36[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,3);//冷却塔风机2故障
        M1_A2_B_4Q2_FAULT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,4);//辅变流器1输出接地
        M1_A2_B_4Q3_FAULT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,5);//辅变流器2输出接地
        M1_A2_B_DJ_VT_SM1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,6);//机械间风机1断路器状态
        M1_A2_B_DJ_VT_SM2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,7);//机械间风机2断路器状态
        M1_A2_B_Q_TH_VT_BM1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),21,0);//冷却塔风机1断路器状态
        M1_A2_B_Q_TH_VT_BM2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),21,1);//冷却塔风机2断路器状态
        M1_A2_B_Q_TH_VT_MT1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),21,2);//牵引风机1断路器状态
        M1_A2_B_Q_TH_VT_MT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),21,3);//牵引风机2断路器状态
        M1_A2_B_P110CHECK0[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),31,6);//数据校验(固定发0)
        M1_A2_B_P110CHECK1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),31,7);//数据校验(固定发1)

        M1_A2_N_DT_YEAR[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i),2);//系统时间（年）

        M1_A2_N_MPU_LIFE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),0);//MPU生命信号
        M1_A2_N_DT_MONTH[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),4);//系统时间（月）
        M1_A2_N_DT_DAY[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),5);//系统时间（日）
        M1_A2_N_DT_HOUR[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),6);//系统时间（时）
        M1_A2_N_DT_MINUTE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),7);//系统时间（分）
        M1_A2_N_DT_SECOND[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),8);//系统时间（秒）
        M1_A2_N_FVT[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),10);//Auxiliary inverter frequency demand
        M1_A2_N_MQUAIT[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),11);//C(SEC)CVS monitoring
        M1_A2_N_DEPOT_MODE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),12);//库内模式参考（1：库内动车，2：风机测试，0：正常模式）
    }
}
