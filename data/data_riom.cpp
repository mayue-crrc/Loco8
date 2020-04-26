#include "data_riom.h"
#include "crrcmvb.h"
Data_RIOM::Data_RIOM()
{

}
void Data_RIOM::updateData()
{


    RIOM1_DI3_12_HORN_E = CrrcMvb::getCrrcMvb()->getBool(0x200,0,4);//电笛
    RIOM1_DI3_11_BP_MTS = CrrcMvb::getCrrcMvb()->getBool(0x200,0,5);//换端
    RIOM1_DI3_10_BP_AVER = CrrcMvb::getCrrcMvb()->getBool(0x200,0,6);//高音风笛
    RIOM1_DI3_9_P_AVER = CrrcMvb::getCrrcMvb()->getBool(0x200,0,7);//低音风笛
    RIOM1_DI3_8_AC_FAULT = CrrcMvb::getCrrcMvb()->getBool(0x200,1,0);//空调故障
    RIOM1_DI3_7_P_SA = CrrcMvb::getCrrcMvb()->getBool(0x200,1,1);//手动撒砂
    RIOM1_DI3_6_BP_MNSC = CrrcMvb::getCrrcMvb()->getBool(0x200,1,2);//半自动过分相
    RIOM1_DI3_5_BP_CONS = CrrcMvb::getCrrcMvb()->getBool(0x200,1,3);//定速控制
    RIOM1_DI3_4_BP_RESET = CrrcMvb::getCrrcMvb()->getBool(0x200,1,4);//复位按钮
    RIOM1_DI3_3_Z_CPR_P = CrrcMvb::getCrrcMvb()->getBool(0x200,1,5);//强泵
    RIOM1_DI3_2_Z_CPR_R = CrrcMvb::getCrrcMvb()->getBool(0x200,1,6);//压缩机正常
    RIOM1_DI3_1_BP_VA = CrrcMvb::getCrrcMvb()->getBool(0x200,1,7);//无人警惕

    RIOM1_DI3_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x200,27,0);//RIOM1 DI3在线
    RIOM1_DO1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x200,28,0);//RIOM1 DO1在线
    RIOM1_R1_B_GW1_MVB_RLD = CrrcMvb::getCrrcMvb()->getBool(0x200,31,4);//RLD
    RIOM1_R1_B_GW1_MVB_LAT = CrrcMvb::getCrrcMvb()->getBool(0x200,31,5);//LAT
    RIOM1_P200CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x200,31,6);//数据校验（固定发0）
    RIOM1_P200CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x200,31,7);//数据校验（固定发1）
    RIOM1_P207CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x207,31,6);//数据校验（固定发0）
    RIOM1_P207CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x207,31,7);//数据校验（固定发1）
    RIOM1_DI1_16_MP_TF_N = CrrcMvb::getCrrcMvb()->getBool(0x210,0,0);//司控器零位
    RIOM1_DI1_15_MP_TF_T23 = CrrcMvb::getCrrcMvb()->getBool(0x210,0,1);//司控器T2/3位
    RIOM1_DI1_14_MP_TF_B23 = CrrcMvb::getCrrcMvb()->getBool(0x210,0,2);//司控器B2/3位
    RIOM1_DI1_13_MP_TF_T13 = CrrcMvb::getCrrcMvb()->getBool(0x210,0,3);//司控器T1/3位
    RIOM1_DI1_12_MP_TF_B13 = CrrcMvb::getCrrcMvb()->getBool(0x210,0,4);//司控器B1/3位
    RIOM1_DI1_11_MP_TF_T_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,0,5);//司控器T位
    RIOM1_DI1_10_MP_TF_B_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,0,6);//司控器B位
    RIOM1_DI1_9_Z_MS_N = CrrcMvb::getCrrcMvb()->getBool(0x210,0,7);//方向零位
    RIOM1_DI1_8_Z_MS_B_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,1,0);//向后
    RIOM1_DI1_7_Z_MS_F_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,1,1);//向前
    RIOM1_DI1_6_BP_URG_E_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,1,2);//电控紧急
    RIOM1_DI1_5_Z_DJ_K_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,1,3);//主断保持
    RIOM1_DI1_4_Z_DJ_C_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,1,4);//主断合
    RIOM1_DI1_3_Z_PT_D_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,1,5);//降弓
    RIOM1_DI1_2_Z_PT_R_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,1,6);//升弓
    RIOM1_DI1_1_Z_MES_1 = CrrcMvb::getCrrcMvb()->getBool(0x210,1,7);//电钥匙
    RIOM1_DI2_10_BP_URG_E_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,2,6);//电控紧急
    RIOM1_DI2_9_Z_DJ_K_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,2,7);//主断保持
    RIOM1_DI2_8_Z_DJ_C_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,3,0);//主断合
    RIOM1_DI2_7_Z_PT_D_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,3,1);//降弓
    RIOM1_DI2_6_Z_PT_R_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,3,2);//升弓
    RIOM1_DI2_5_MP_TF_T_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,3,3);//司控器T位
    RIOM1_DI2_4_MP_TF_B_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,3,4);//司控器B位
    RIOM1_DI2_3_Z_MS_B_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,3,5);//向后
    RIOM1_DI2_2_Z_MS_F_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,3,6);//向前
    RIOM1_DI2_1_Z_MES_2 = CrrcMvb::getCrrcMvb()->getBool(0x210,3,7);//电钥匙
    RIOM1_AX1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x210,26,0);//RIOM1 AX1在线
    RIOM1_DI1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x210,27,0);//RIOM1 DI1在线
    RIOM1_DI2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x210,27,1);//RIOM1 DI2在线

    RIOM1_R1_B_GW2_MVB_RLD = CrrcMvb::getCrrcMvb()->getBool(0x210,31,4);//RLD
    RIOM1_R1_B_GW2_MVB_LAT = CrrcMvb::getCrrcMvb()->getBool(0x210,31,5);//LAT
    RIOM1_P210CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x210,31,6);//数据校验（固定发0）
    RIOM1_P210CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x210,31,7);//数据校验（固定发1）
    RIOM1_P214CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x214,31,6);//数据校验（固定发0）
    RIOM1_P214CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x214,31,7);//数据校验（固定发1）
    RIOM1_P217CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x217,31,6);//数据校验（固定发0）
    RIOM1_P217CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x217,31,7);//数据校验（固定发1）


    RIOM1_MSCT1 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x214,12);//司控器级位

    RIOM1_GW1_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x200,30);//RIOM1_GW1生命信号（0～255递增）
    RIOM1_GW1_VX = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x207,0);//RIOM1_GW1软件版本号 x
    RIOM1_GW1_VY = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x207,1);//RIOM1_GW2软件版本号 y
    RIOM1_GW2_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x210,30);//RIOM1_GW2生命信号（0～255递增）
    RIOM1_GW2_VX = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x217,0);//RIOM1_GW1软件版本号 x
    RIOM1_GW2_VY = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x217,1);//RIOM1_GW2软件版本号 y



    RIOM2_LOOP_GHV = CrrcMvb::getCrrcMvb()->getBool(0x220,0,3);//控制回路接地
    RIOM2_DI1_12_MA1_FD = CrrcMvb::getCrrcMvb()->getBool(0x220,0,4);//小闸压力开关1
    RIOM2_DI1_11_VE1_Q_P_COM_F = CrrcMvb::getCrrcMvb()->getBool(0x220,0,5);//空电联合制动阀1状态
    RIOM2_DI1_10_Q1_DF_PH = CrrcMvb::getCrrcMvb()->getBool(0x220,0,6);//油流1
    RIOM2_DI1_9_Q_DZ_TFP_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,0,7);//主变压力释放阀
    RIOM2_DI1_8_Q1_TPH_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,1,0);//主变压器温度开关
    RIOM2_YV_PAN_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,1,1);//受电弓隔离阀
    RIOM2_DI1_6_MA_CPR_AUX_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,1,2);//辅助压力开关
    RIOM2_DI1_5_MA_SU_PT_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,1,3);//受电弓压力开关
    RIOM2_DI1_4_DJ_M_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,1,4);//主断状态
    RIOM2_DI1_3_QS_GHV_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,1,5);//接地开关1
    RIOM2_DI1_2_H_HT = CrrcMvb::getCrrcMvb()->getBool(0x220,1,6);//高压隔离开关状态
    RIOM2_DI2_12_MA2_FD = CrrcMvb::getCrrcMvb()->getBool(0x220,2,4);//小闸压力开关2
    RIOM2_DI2_11_VE2_Q_P_COM_F = CrrcMvb::getCrrcMvb()->getBool(0x220,2,5);//空电联合制动阀2状态
    RIOM2_DI2_10_Q2_DF_PH = CrrcMvb::getCrrcMvb()->getBool(0x220,2,6);//油流2
    RIOM2_DI2_9_Q_DZ_TFP_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,2,7);//主变压力释放阀
    RIOM2_DI2_8_Q1_TPH_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,3,0);//主变压器温度开关
    RIOM2_YV_PAN_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,3,1);//受电弓隔离阀
    RIOM2_DI2_6_MA_CPR_AUX_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,3,2);//辅助压力开关
    RIOM2_DI2_5_MA_SU_PT_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,3,3);//受电弓压力开关
    RIOM2_DI2_4_DJ_M_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,3,4);//主断状态
    RIOM2_DI1_3_QS_GHV_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,3,5);//接地开关2
    RIOM2_DI3_16_UM_4 = CrrcMvb::getCrrcMvb()->getBool(0x220,4,0);//内重联信号2
    RIOM2_DI3_15_UM_3 = CrrcMvb::getCrrcMvb()->getBool(0x220,4,1);//内重联信号1
    RIOM2_DI3_14_UM_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,4,2);//外重联信号2
    RIOM2_DI3_13_UM_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,4,3);//外重联信号1
    RIOM2_DI3_12_MA2_FS = CrrcMvb::getCrrcMvb()->getBool(0x220,4,4);//停放压力开关2
    RIOM2_DI3_10_BCU_Ul = CrrcMvb::getCrrcMvb()->getBool(0x220,4,6);//BCU切除牵引
    RIOM2_DI3_9_BCU_FAULT = CrrcMvb::getCrrcMvb()->getBool(0x220,4,7);//BCU故障
    RIOM2_DI3_8_BCU_EM = CrrcMvb::getCrrcMvb()->getBool(0x220,5,0);//BCU紧急
    RIOM2_DI3_7_LKJ_EM = CrrcMvb::getCrrcMvb()->getBool(0x220,5,1);//LKJ紧急
    RIOM2_DI3_6_BP_EM = CrrcMvb::getCrrcMvb()->getBool(0x220,5,2);//列车管紧急放风阀
    RIOM2_DI3_5_N24V_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,5,3);//24V-1正常
    RIOM2_MA1_D1 = CrrcMvb::getCrrcMvb()->getBool(0x220,5,4);//防火检测压力1
    RIOM2_MA2_D1 = CrrcMvb::getCrrcMvb()->getBool(0x220,5,5);//防火检测压力2
    RIOM2_DI3_2_MA2_CP = CrrcMvb::getCrrcMvb()->getBool(0x220,5,6);//总风压力2
    RIOM2_DI3_1_MA1_CP = CrrcMvb::getCrrcMvb()->getBool(0x220,5,7);//总风压力1
    RIOM2_DI4_15_MONUL = CrrcMvb::getCrrcMvb()->getBool(0x220,6,1);//监控卸载
    RIOM2_DI4_14_SBCM = CrrcMvb::getCrrcMvb()->getBool(0x220,6,2);//安全回路监测
    RIOM2_DI4_13_ANSC_FAULT = CrrcMvb::getCrrcMvb()->getBool(0x220,6,3);//ANSC故障
    RIOM2_DI4_12_ANSC2 = CrrcMvb::getCrrcMvb()->getBool(0x220,6,4);//ANSC强断
    RIOM2_DI4_11_ANSC1 = CrrcMvb::getCrrcMvb()->getBool(0x220,6,5);//ANSC预告或恢复
    RIOM2_DI4_10_Q_PP_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x220,6,6);//辅入库相序检测器
    RIOM2_DI4_9_C_IS_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x220,6,7);//辅入库工作接触器
    RIOM2_DI4_8_C_PC_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x220,7,0);//辅入库充电接触器
    RIOM2_DI4_6_DJ_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x220,7,2);//辅入库断路器状态
    RIOM2_DI4_5_RB_URG = CrrcMvb::getCrrcMvb()->getBool(0x220,7,3);//车长阀状态
    RIOM2_DI4_4_C_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x220,7,4);//辅入库接触器状态
    RIOM2_DI4_3_C_CPR_AUX = CrrcMvb::getCrrcMvb()->getBool(0x220,7,5);//辅助压缩机接触器状态
    RIOM2_DI4_2_Z_QUAI_T = CrrcMvb::getCrrcMvb()->getBool(0x220,7,6);//测试位
    RIOM2_DI4_1_Z_QUAI_M = CrrcMvb::getCrrcMvb()->getBool(0x220,7,7);//库用动车
    RIOM2_DI5_15_RB_EMG_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,8,1);//紧急制动隔离阀状态
    RIOM2_DI5_14_RB_IS_CF1 = CrrcMvb::getCrrcMvb()->getBool(0x220,8,2);//制动缸1隔离阀状态
    RIOM2_DI5_13_RB_IS_FS_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,8,3);//停放制动隔离阀状态
    RIOM2_DI5_12_Q1L_M_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,8,4);//过流继电器状态
    RIOM2_DI5_10_DRY_FAULT = CrrcMvb::getCrrcMvb()->getBool(0x220,8,6);//干燥器故障
    RIOM2_DI5_8_Q_REC = CrrcMvb::getCrrcMvb()->getBool(0x220,9,0);//压缩机低温保护
    RIOM2_DI5_7_C1_CPR_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,9,1);//压缩机接触器1状态
    RIOM2_DI5_6_Q_TH_CPR_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,9,2);//压缩机热保护继电器状态
    RIOM2_DI5_3_C3_CPR_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,9,5);//压缩机接触器3状态
    RIOM2_DI5_2_C2_CPR_1 = CrrcMvb::getCrrcMvb()->getBool(0x220,9,6);//压缩机接触器2状态
    RIOM2_DI6_15_RB_EMG_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,10,1);//紧急制动隔离阀状态
    RIOM2_DI6_14_RB_IS_CF2 = CrrcMvb::getCrrcMvb()->getBool(0x220,10,2);//制动缸隔离阀状态
    RIOM2_DI6_13_RB_IS_FS_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,10,3);//停放制动隔离阀状态
    RIOM2_DI6_12_Q1L_M_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,10,4);//过流继电器状态
    RIOM2_DI6_11_C_PHEAT3 = CrrcMvb::getCrrcMvb()->getBool(0x220,10,5);//预加热接触器3状态
    RIOM2_DI6_10_C_PHEAT1 = CrrcMvb::getCrrcMvb()->getBool(0x220,10,6);//预加热接触器1状态
    RIOM2_DI6_9_C_PHEAT2 = CrrcMvb::getCrrcMvb()->getBool(0x220,10,7);//预加热接触器2状态
    RIOM2_DI6_7_C1_CPR_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,11,1);//压缩机接触器1状态
    RIOM2_DI6_6_Q_TH_CPR_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,11,2);//压缩机热保护继电器状态
    RIOM2_DI6_5_Q_PHEAT = CrrcMvb::getCrrcMvb()->getBool(0x220,11,3);//预加热开关状态
    RIOM2_DI6_4_FC_CLA_VT = CrrcMvb::getCrrcMvb()->getBool(0x220,11,4);//顶盖通风
    RIOM2_DI6_3_C3_CPR_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,11,5);//压缩机接触器3状态
    RIOM2_DI6_2_C2_CPR_2 = CrrcMvb::getCrrcMvb()->getBool(0x220,11,6);//压缩机接触器2状态
    RIOM2_DI1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x220,27,0);//RIOM2 DI1在线
    RIOM2_DI2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x220,27,1);//RIOM2 DI2在线
    RIOM2_DI3_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x220,27,2);//RIOM2 DI3在线
    RIOM2_DI4_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x220,27,3);//RIOM2 DI4在线
    RIOM2_DI5_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x220,27,4);//RIOM2 DI5在线
    RIOM2_DI6_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x220,27,5);//RIOM2 DI6在线
    RIOM2_DO1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x220,28,0);//RIOM2 DO1在线
    RIOM2_DO2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x220,28,1);//RIOM2 DO2在线
    RIOM2_DO3_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x220,28,2);//RIOM2 DO3在线
    RIOM2_R2_B_MVB_RLD = CrrcMvb::getCrrcMvb()->getBool(0x220,31,4);//RLD
    RIOM2_R2_B_MVB_LAT = CrrcMvb::getCrrcMvb()->getBool(0x220,31,5);//LAT
    RIOM2_P220CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x220,31,6);//数据校验（固定发0）
    RIOM2_P220CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x220,31,7);//数据校验（固定发1）
    RIOM2_P227CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x227,31,6);//数据校验（固定发0）
    RIOM2_P227CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x227,31,7);//数据校验（固定发1）

    RIOM2_GW_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x220,30);//RIOM2_GW 生命信号（0～255递增）
    RIOM2_GW_VX = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x227,0);//RIOM2_GW软件版本号 x
    RIOM2_GW_VY = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x227,1);//RIOM2_GW软件版本号 y



    RIOM1_DO1_7_LS_MTS = CrrcMvb::getCrrcMvb()->getBool(0x208,1,1);//换端
    RIOM1_DO1_6_LS_SU_BA = CrrcMvb::getCrrcMvb()->getBool(0x208,1,2);//蓄电池低压
    RIOM1_DO1_5_LS_CPR = CrrcMvb::getCrrcMvb()->getBool(0x208,1,3);//压缩机故障
    RIOM1_DO1_4_LS_IS_CVS = CrrcMvb::getCrrcMvb()->getBool(0x208,1,4);//辅助隔离
    RIOM1_DO1_3_LS_IS_ES = CrrcMvb::getCrrcMvb()->getBool(0x208,1,5);//轴隔离
    RIOM1_DO1_2_LS_DJM = CrrcMvb::getCrrcMvb()->getBool(0x208,1,6);//主断分
    RIOM1_DO1_1_LS_UT_CAB = CrrcMvb::getCrrcMvb()->getBool(0x208,1,7);//他端占用
    RIOM1_P208CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x208,31,6);//数据校验（固定发0）
    RIOM1_P208CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x208,31,7);//数据校验（固定发1）
    RIOM2_DO1_10_Q_VA_1 = CrrcMvb::getCrrcMvb()->getBool(0x228,0,6);//无人警惕报警
    RIOM2_Q_FLT_LOCK = CrrcMvb::getCrrcMvb()->getBool(0x228,0,7);//Q_FLT锁定
    RIOM2_DO1_8_C3_CPR = CrrcMvb::getCrrcMvb()->getBool(0x228,1,0);//压缩机接触器3命令
    RIOM2_DO1_7_C1_CPR = CrrcMvb::getCrrcMvb()->getBool(0x228,1,1);//压缩机接触器1命令
    RIOM2_DO1_5_Q_SA1 = CrrcMvb::getCrrcMvb()->getBool(0x228,1,3);//撒沙命令1
    RIOM2_DO1_4_C2_CPR = CrrcMvb::getCrrcMvb()->getBool(0x228,1,4);//压缩机接触器2命令
    RIOM2_DO1_3_Q2_PT = CrrcMvb::getCrrcMvb()->getBool(0x228,1,5);//它车受电弓继电器
    RIOM2_DO1_2_Q_DJM_1 = CrrcMvb::getCrrcMvb()->getBool(0x228,1,6);//主断命令1
    RIOM2_DO1_1_Q1_PT = CrrcMvb::getCrrcMvb()->getBool(0x228,1,7);//本车受电弓继电器
    RIOM2_Q_FIRE1_T = CrrcMvb::getCrrcMvb()->getBool(0x228,2,2);//它车火灾报警输出1
    RIOM2_Q_FIRE1_B = CrrcMvb::getCrrcMvb()->getBool(0x228,2,3);//本车火灾报警输出1
    RIOM2_DO2_12_BFL = CrrcMvb::getCrrcMvb()->getBool(0x228,2,4);//停放制动指示灯
    RIOM2_DO2_11_Q_UAI = CrrcMvb::getCrrcMvb()->getBool(0x228,2,5);//辅入库继电器
    RIOM2_DO2_10_Q_VA_2 = CrrcMvb::getCrrcMvb()->getBool(0x228,2,6);//无人警惕报警
    RIOM2_DO2_9_Q_KBA = CrrcMvb::getCrrcMvb()->getBool(0x228,2,7);//禁止蓄电池切除
    RIOM2_DO2_8_C_PC_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x228,3,0);//辅入库预充电接触器
    RIOM2_Q_DJM_F = CrrcMvb::getCrrcMvb()->getBool(0x228,3,1);//主断故障输出？
    RIOM2_BAT_LOW = CrrcMvb::getCrrcMvb()->getBool(0x228,3,2);//蓄电池欠压保护
    RIOM2_DO2_5_Q_SA2 = CrrcMvb::getCrrcMvb()->getBool(0x228,3,3);//撒沙命令2
    RIOM2_DO2_4_Q_P_COM_F2 = CrrcMvb::getCrrcMvb()->getBool(0x228,3,4);//空电转换2继电器
    RIOM2_DO2_3_Q_P_COM_F1 = CrrcMvb::getCrrcMvb()->getBool(0x228,3,5);//空电转换1继电器
    RIOM2_DO2_2_Q_DJM_2 = CrrcMvb::getCrrcMvb()->getBool(0x228,3,6);//主断命令2
    RIOM2_DO2_1_C_IS_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x228,3,7);//辅入库工作接触器
    RIOM2_Q_FIRE2_T = CrrcMvb::getCrrcMvb()->getBool(0x228,4,2);//它车火灾报警输出2
    RIOM2_Q_FIRE2_B = CrrcMvb::getCrrcMvb()->getBool(0x228,4,3);//本车火灾报警输出2
    RIOM2_DO3_12_Q_PK = CrrcMvb::getCrrcMvb()->getBool(0x228,4,4);//停放制动输出
    RIOM2_DO3_11_VE_PU_SR_AUX = CrrcMvb::getCrrcMvb()->getBool(0x228,4,5);//辅助干燥器排风阀
    RIOM2_DO3_10_Q_BRB = CrrcMvb::getCrrcMvb()->getBool(0x228,4,6);//润滑命令
    RIOM2_DO3_9_Q2_CAB = CrrcMvb::getCrrcMvb()->getBool(0x228,4,7);//本端上电2
    RIOM2_DO3_8_Q1_CAB = CrrcMvb::getCrrcMvb()->getBool(0x228,5,0);//本端上电1
    RIOM2_DO3_7_NOMAN_BCU = CrrcMvb::getCrrcMvb()->getBool(0x228,5,1);//无人警惕惩罚
    RIOM2_DO3_6_SPEEDZERO = CrrcMvb::getCrrcMvb()->getBool(0x228,5,2);//零速
    RIOM2_DO3_5_BRAKE = CrrcMvb::getCrrcMvb()->getBool(0x228,5,3);//制动
    RIOM2_DO3_4_NEUTRAL = CrrcMvb::getCrrcMvb()->getBool(0x228,5,4);//零位
    RIOM2_DO3_3_TRACTION = CrrcMvb::getCrrcMvb()->getBool(0x228,5,5);//牵引
    RIOM2_DO3_2_BACK = CrrcMvb::getCrrcMvb()->getBool(0x228,5,6);//向后
    RIOM2_DO3_1_FORWARD = CrrcMvb::getCrrcMvb()->getBool(0x228,5,7);//向前
    RIOM2_P228CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x228,31,6);//数据校验（固定发0）
    RIOM2_P228CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x228,31,7);//数据校验（固定发1）

    RIOM1_MPU_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x208,30);//MPU生命信号（0～255递增）
    RIOM2_MPU_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x228,30);//生命信号（0～255递增）

}
