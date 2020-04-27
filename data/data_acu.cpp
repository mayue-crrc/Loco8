#include "data_acu.h"
#include "crrcmvb.h"
Data_ACU::Data_ACU()
{
    m_ports<<0x100<<0x110<<0x103<<0x104<<0x105<<0x113<<0x114<<0x115;
}
void Data_ACU::updateData()
{
    for(int i = 0;i<2;i++)
    {

        ANDEL[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,0);//SIV load shedding cancellation
        ANISA[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,1);//Auxiliary inverter reset
        ANISB[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,2);//Battery charger reset
        DEMCB[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,3);//Battery charger starting authorization
        DISCHB[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,4);//Battery charger isolation request
        DISCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,5);//SIV isolation request
        DSCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,6);//SIV rescue mode request
        DTRDEF[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),14,7);//ACU faults transfer request
        ISO_REL_RQ[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,0);//隔离取消请求
        ETATMPU[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,1);//MPU Health Status
        ETATTCU[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,2);//RIOM Health Status
        V1800OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,3);//中间电压1800V OK
        ANSC_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,5);//过分相开始信号
        ANSC_END[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,6);//过分相结束信号
        ANSC_CMPLT[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),15,7);//过分相完成信号
        AMCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,0);//CVS Set/Reset Command
        DELES[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,1);//CVS stop Command
        INUL[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,2);//O Curent Command
        C1_CPR[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,5);//压缩机接触器1状态
        C2_CPR[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,6);//压缩机接触器2状态
        C3_CPR[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),18,7);//压缩机接触器3状态
        VT_BM1_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,2);//冷却塔风机1测试：1测试，0停止
        VT_BM2_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,3);//冷却塔风机2测试：1测试，0停止
        VT_MT1_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,4);//牵引风机1测试：1测试，0停止
        VT_MT2_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,5);//牵引风机2测试：1测试，0停止
        VT_SM1_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,6);//机械间风机1测试：1测试，0停止
        VT_SM2_ST[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),19,7);//机械间风机2测试：1测试，0停止
        CCUACU_FALUT33[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,0);//牵引风机1故障
        CCUACU_FALUT34[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,1);//牵引风机2故障
        CCUACU_FALUT35[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,2);//冷却塔风机1故障
        CCUACU_FALUT36[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,3);//冷却塔风机2故障
        Q4Q2_FAULT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,4);//辅变流器1输出接地
        Q4Q3_FAULT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,5);//辅变流器2输出接地
        DJ_VT_SM1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,6);//机械间风机1断路器状态
        DJ_VT_SM2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),20,7);//机械间风机2断路器状态
        Q_TH_VT_BM1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),21,0);//冷却塔风机1热继状态
        Q_TH_VT_BM2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),21,1);//冷却塔风机2热继状态
        Q_TH_VT_MT1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),21,2);//牵引风机1热继状态
        Q_TH_VT_MT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),21,3);//牵引风机2热继状态
        P100CHECK0[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),31,6);//数据校验(固定发0)
        P100CHECK1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(i),31,7);//数据校验(固定发1)

        DT_YEAR[i] = CrrcMvb::getCrrcMvb()->getUnsignedInt(m_ports.at(i),2);//系统时间（年）


        MPU_LIFE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),0);//MPU生命信号
        DT_MONTH[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),4);//系统时间（月）
        DT_DAY[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),5);//系统时间（日）
        DT_HOUR[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),6);//系统时间（时）
        DT_MINUTE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),7);//系统时间（分）
        DT_SECOND[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),8);//系统时间（秒）
        FVT[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),10);//Auxiliary inverter frequency demand
        MQUAIT[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),11);//C(SEC)CVS monitoring
        DEPOT_MODE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(i),12);//库内模式参考（1：库内动车，2：风机测试，0：正常模式）

        DJ_PE1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),4,0);//水泵1断路器状态
        DJ_PE2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),4,1);//水泵2断路器状态
        DJ_PE3[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),4,2);//水泵3断路器状态
        DJ_PE4[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),4,3);//水泵4断路器状态
        DJ_PH1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),4,4);//油泵1断路器状态
        DJ_PH2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),4,5);//油泵2断路器状态
        C_VT_BM1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),6,0);//冷却塔风机1接触器状态
        C_VT_BM2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),6,1);//冷却塔风机2接触器状态
        C_VT_MT1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),6,2);//牵引风机1接触器状态
        C_VT_MT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),6,3);//牵引风机2接触器状态
        C_VT_SM1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),6,4);//机械间风机1接触器状态
        C_VT_SM2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),6,5);//机械间风机2接触器状态
        PMT_CPR_RUN[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),7,0);//允许压缩机启动
        V380OK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),17,0);//Presence 400 V at auxiliary output
        CISONDCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),17,1);//Auxiliary output contactor feedback
        CRAOK[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),17,2);//ACU application functional
        CSECCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),17,3);//Rescue contactor feedback
        ISCHB[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),17,4);//Battery charger isolated
        ISCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),17,5);//SIV isolated
        MODSECV[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),17,6);//SIV in rescue mode
        PRESA[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),17,7);//ACU supplied (110 Vdc)
        TRTCC[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),18,0);//Short-circuit handling in progress
        MED_A_KO[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),18,1);//Medium A NOK when 1
        MED_B_KO[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),18,2);//Medium B NOK when 1
        ACU_FALUT1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),20,0);//辅变1输入电路保护隔离
        ACU_FALUT2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),20,1);//辅变1输入熔断器故障
        ACU_FALUT3[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),20,2);//辅变1输入过压
        ACU_FALUT4[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),20,3);//辅变1输入欠压
        ACU_FALUT5[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),20,4);//辅变1斩波器保护隔离
        ACU_FALUT6[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),20,5);//辅变1中间回路短路保护隔离
        ACU_FALUT7[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),20,6);//辅变1中间回路短路
        ACU_FALUT8[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),20,7);//辅变1斩波器过热故障
        ACU_FALUT9[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),21,0);//辅变1斩波器输出过载
        ACU_FALUT10[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),21,1);//辅变1中间回路1级过压
        ACU_FALUT11[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),21,2);//辅变1中间回路2级过压
        ACU_FALUT12[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),21,3);//辅变1斩波器输出过流
        ACU_FALUT13[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),21,4);//辅变1斩波器门级驱动故障
        ACU_FALUT14[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),21,5);//辅变1逆变器保护隔离
        ACU_FALUT15[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),21,6);//辅变1紧急接触器卡合（原 不一致性故障）
        ACU_FALUT16[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),21,7);//辅变1交流输出接触器卡合（原 不一致性故障）
        ACU_FALUT17[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),22,0);//辅变1通风机故障
        ACU_FALUT18[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),22,1);//辅变1逆变器输出过电压
        ACU_FALUT19[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),22,2);//辅变1逆变器过载
        ACU_FALUT20[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),22,3);//辅变1逆变器过流
        ACU_FALUT21[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),22,4);//辅变1逆变器R相门极驱动故障
        ACU_FALUT22[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),22,5);//辅变1逆变器S相门极驱动故障
        ACU_FALUT23[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),22,6);//辅变1逆变器T相门极驱动故障
        ACU_FALUT24[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),22,7);//辅变1充电器保护隔离
        ACU_FALUT25[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),23,0);//辅变1充电器过热
        ACU_FALUT26[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),23,1);//辅变1蓄电池温度故障
        ACU_FALUT27[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),23,2);//辅变1充电器输出过压
        ACU_FALUT28[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),23,3);//辅变1充电器输出欠压
        ACU_FALUT29[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),23,4);//辅变1充电器输出过载
        ACU_FALUT30[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),23,5);//辅变1充电器门极驱动故障
        ACU_FALUT31[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),23,6);//辅变1充电器原边过电流
        ACU_FALUT32[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),23,7);//辅变1充电器副边过电流
        ACU_FALUT33[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),24,0);//预留
        ACU_FALUT34[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),24,1);//机械间风机1接触器卡分（原 牵引风机2故障）
        ACU_FALUT35[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),24,2);//机械间风机1接触器卡合（原 冷却塔风机1故障）
        ACU_FALUT36[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),24,3);//机械间风机2接触器卡分（原 冷却塔风机2故障）
        ACU_FALUT37[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),24,4);//机械间风机2接触器卡合（原 压缩机故障）
        ACU_FALUT38[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),24,5);//牵引风机1接触器卡分
        ACU_FALUT39[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),24,6);//牵引风机1接触器卡合
        ACU_FALUT40[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),24,7);//牵引风机2接触器卡分
        ACU_FALUT41[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),25,0);//牵引风机2接触器卡合
        ACU_FALUT42[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),25,1);//冷却塔风机1接触器卡分
        ACU_FALUT43[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),25,2);//冷却塔风机1接触器卡合
        ACU_FALUT44[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),25,3);//冷却塔风机2接触器卡分
        ACU_FALUT45[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),25,4);//冷却塔风机2接触器卡合
        ACU_FALUT46[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),25,5);//辅变1紧急接触器卡分（新增）
        ACU_FALUT47[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),25,6);//辅变1交流输出接触器卡分（新增）
        ACU_FALUT48[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),25,7);//预留
        P103CHECK0[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),31,6);//数据校验（固定发0）
        P103CHECK1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+2),31,7);//数据校验（固定发1）
        CCT_CVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),28,0);//Short-circuit fault at the converter output
        CCT_OND[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),28,1);//Short-circuit fault at the inverter output
        DA_PERMCH[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),28,2);//Battery charger permanent fault
        DA_PERMOND[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),28,3);//Inverter permanent fault
        BT_CCENTCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),28,4);//Input fuse feedback
        E_BT_CISONDCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),28,5);//Auxiliary output contactor feedback
        E_BT_CSECCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),28,6);//Rescue contactor feedback
        E_BT_DJRGBACVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),28,7);//Battery charger circuit breaker feedback
        MA_BLOC1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),29,0);//Start-stop state for the block 1 (inverter)
        MA_BLOC2[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),29,1);//Start-stop state for the block 2 (battery charger)
        E_BT_KLIXONDCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),29,2);//Inverter klixon feedback
        E_BT_KLIXDPMCVS[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),29,3);//Battery charger klixon feedback
        P105CHECK0[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),31,6);//数据校验（固定发0）
        P105CHECK1[i] = CrrcMvb::getCrrcMvb()->getBool(m_ports.at(3*i+4),31,7);//数据校验（固定发1）

        VXCRA[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(3*i+2),10);//value of x
        VYCRA[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(3*i+2),11);//value of y
        ACU_LIFE[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(3*i+2),30);//生命信号（0～255递增）
        FREQ_OND[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(3*i+4),24);//Auxiliary inverter frequency
        CODEDEF[i] = CrrcMvb::getCrrcMvb()->getUnsignedChar(m_ports.at(3*i+4),25);//Current Fault Code


        UBAT[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+2),0);//蓄电池电压
        Bus_Udc[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+3),0);//1800V直流母线电压
        Mid_Udc[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+3),4);//斩波器输出电压
        Mid_Idc[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+3),8);//斩波器输出电流
        Inverter_Uac[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+3),12);//逆变器输出电压
        Inverter_Iac[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+3),16);//逆变器输出电流
        Blower_I[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+3),20);//辅助风机电流
        E_CA_IPRIM[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+3),24);//充电变压器原边电流
        E_CA_ITOT[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+3),28);//充电机输出电流
        E_CA_TMPBAT[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+4),0);//Battery temperature measure
        Battery_Idc[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+4),4);//蓄电池放电电流
        Battery_Udc[i] = CrrcMvb::getCrrcMvb()->getSignedInt32(m_ports.at(3*i+4),8);//蓄电池电压





    }
}
