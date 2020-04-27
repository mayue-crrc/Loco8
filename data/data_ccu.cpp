#include "data_ccu.h"
#include "crrcmvb.h"

Data_CCU::Data_CCU()
{
    SPEED_SET = 80;

}
void Data_CCU::updateData()
{

    HEATING = CrrcMvb::getCrrcMvb()->getBool(0x710,20,0);//预加热
    NSC_START = CrrcMvb::getCrrcMvb()->getBool(0x710,20,1);//过分相开始
    NSC_END = CrrcMvb::getCrrcMvb()->getBool(0x710,20,2);//过分相结束
    AXLE2_MOVE = CrrcMvb::getCrrcMvb()->getBool(0x710,20,3);//2轴动车
    Z_ZSEC = CrrcMvb::getCrrcMvb()->getBool(0x710,20,4);//接地（重联车任一个）
    DADMAN_ALARM = CrrcMvb::getCrrcMvb()->getBool(0x710,20,5);//无人警惕报警
    SANDING = CrrcMvb::getCrrcMvb()->getBool(0x710,20,6);//撒砂
    RACING = CrrcMvb::getCrrcMvb()->getBool(0x710,20,7);//空转
    SLIP = CrrcMvb::getCrrcMvb()->getBool(0x710,21,0);//滑行
    SPEED_CTL = CrrcMvb::getCrrcMvb()->getBool(0x710,21,1);//定速模式
    PENALTY_BRK = CrrcMvb::getCrrcMvb()->getBool(0x710,21,2);//惩罚制动
    SIM_MODE = CrrcMvb::getCrrcMvb()->getBool(0x710,21,4);//仿真模式
    QS_GHV = CrrcMvb::getCrrcMvb()->getBool(0x710,21,5);//QS-GHV状态
    DEPOT_SIM = CrrcMvb::getCrrcMvb()->getBool(0x710,22,0);//库内测试
    DEPOT_MOVE = CrrcMvb::getCrrcMvb()->getBool(0x710,22,1);//库内动车
    LEAD = CrrcMvb::getCrrcMvb()->getBool(0x710,22,3);//本机
    TRAIL = CrrcMvb::getCrrcMvb()->getBool(0x710,22,4);//补机
    PSG_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(0x710,22,5);//客车位
    FREIGHT_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(0x710,22,6);//货车位
    CUT_OUT = CrrcMvb::getCrrcMvb()->getBool(0x710,22,7);//拖车
    NORMAL_MODE = CrrcMvb::getCrrcMvb()->getBool(0x710,23,1);//普通模式
    SUMMER_MODE = CrrcMvb::getCrrcMvb()->getBool(0x710,23,2);//夏天模式
    STATE_T_CHAR = CrrcMvb::getCrrcMvb()->getBool(0x710,23,3);//牵引特性反馈，0：恒转矩1：准恒速
    STATE_FORWARD = CrrcMvb::getCrrcMvb()->getBool(0x710,23,4);//方向向前
    STATE_BACK = CrrcMvb::getCrrcMvb()->getBool(0x710,23,5);//方向向后
    STATE_NEUTRAL = CrrcMvb::getCrrcMvb()->getBool(0x710,23,6);//方向零位
    DJ_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x710,24,0);//辅入库断路器状态
    Q_PP_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x710,24,1);//辅入库相序检测状态
    C_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x710,24,2);//辅入库接触器状态
    C_PC_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x710,24,3);//辅入库预充电接触器状态
    C_IS_QUAI = CrrcMvb::getCrrcMvb()->getBool(0x710,24,4);//辅入库工作接触器状态
    NSC_DISTANCE1 = CrrcMvb::getCrrcMvb()->getBool(0x710,24,5);//常规线路过分相：170m模式
    NSC_DISTANCE2 = CrrcMvb::getCrrcMvb()->getBool(0x710,24,6);//货运专线过分相：265m模式
    DOUBLE_PG = CrrcMvb::getCrrcMvb()->getBool(0x710,24,7);//双弓模式激活反馈
    STATE_PANTO_DN = CrrcMvb::getCrrcMvb()->getBool(0x710,25,0);//受电弓降下
    STATE_PANTO_RG = CrrcMvb::getCrrcMvb()->getBool(0x710,25,1);//受电弓升弓
    STATE_PANTO_RD = CrrcMvb::getCrrcMvb()->getBool(0x710,25,2);//受电弓升起
    STATE_PANTO_ISO = CrrcMvb::getCrrcMvb()->getBool(0x710,25,3);//受电弓隔离
    STATE_CAB_ACTIVE = CrrcMvb::getCrrcMvb()->getBool(0x710,25,4);//有司机室激活
    SAND_CUT = CrrcMvb::getCrrcMvb()->getBool(0x710,25,5);//自动撒沙切除
    ELEC_AIR_CUT = CrrcMvb::getCrrcMvb()->getBool(0x710,25,6);//空电联合切除
    CAB_CHANGE_START = CrrcMvb::getCrrcMvb()->getBool(0x710,25,7);//换端开始
    STATE_QFM_ON = CrrcMvb::getCrrcMvb()->getBool(0x710,31,0);//主断闭合
    STATE_QFM_ON_2 = CrrcMvb::getCrrcMvb()->getBool(0x710,31,1);//主断闭合（重联车状态不一致，红点）
    STATE_QFM_K = CrrcMvb::getCrrcMvb()->getBool(0x710,31,2);//主断预备
    STATE_QFM_OFF = CrrcMvb::getCrrcMvb()->getBool(0x710,31,3);//主断断开
    STATE_QFM_ISO = CrrcMvb::getCrrcMvb()->getBool(0x710,31,4);//主断隔离
    P710CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x710,31,6);//数据校验(固定发0)
    P710CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x710,31,7);//数据校验(固定发1)
    MPU1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,24,0);//MPU1在线
    MPU2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,24,1);//MPU2在线
    ACU1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,24,2);//ACU1 在线
    ACU2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,24,3);//ACU2 在线
    TCU1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,24,4);//TCU1 在线
    TCU2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,24,5);//TCU2 在线
    TCU3_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,24,6);//TCU3 在线
    TCU4_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,24,7);//TCU4 在线
    BCU_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,25,0);//BCU 在线
    DDU_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,25,1);//DDU1在线
    RIOM1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,25,2);//RIOM1在线
    RIOM2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,25,3);//RIOM2在线
    UIC_GW1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,25,4);//GW1在线
    UIC_GW2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,25,5);//GW2在线
    GW3_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x711,25,6);//GW3在线
    ONLINE6A = CrrcMvb::getCrrcMvb()->getBool(0x711,25,7);//6A在线
    CUR_MPU1 = CrrcMvb::getCrrcMvb()->getBool(0x711,26,0);//当前为MPU1
    CUR_MPU2 = CrrcMvb::getCrrcMvb()->getBool(0x711,26,1);//当前为MPU2
    BCV1_KM_WORK1 = CrrcMvb::getCrrcMvb()->getBool(0x711,26,4);//变流柜1工作接触器1状态
    BCV1_KM_WORK2 = CrrcMvb::getCrrcMvb()->getBool(0x711,26,5);//变流柜1工作接触器2状态
    BCV2_KM_WORK1 = CrrcMvb::getCrrcMvb()->getBool(0x711,26,6);//变流柜2工作接触器1状态
    BCV2_KM_WORK2 = CrrcMvb::getCrrcMvb()->getBool(0x711,26,7);//变流柜2工作接触器2状态
    BCV1_KM_PC1 = CrrcMvb::getCrrcMvb()->getBool(0x711,27,0);//变流柜1充电接触器1状态
    BCV1_KM_PC2 = CrrcMvb::getCrrcMvb()->getBool(0x711,27,1);//变流柜1充电接触器2状态
    BCV2_KM_PC1 = CrrcMvb::getCrrcMvb()->getBool(0x711,27,2);//变流柜2充电接触器1状态
    BCV2_KM_PC2 = CrrcMvb::getCrrcMvb()->getBool(0x711,27,3);//变流柜2充电接触器2状态
    P711CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x711,31,6);//数据校验(固定发0)
    P711CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x711,31,7);//数据校验(固定发1)
    TCMS_FAULT121 = CrrcMvb::getCrrcMvb()->getBool(0x712,16,0);//牵引变流器1冷却回路异常
    TCMS_FAULT122 = CrrcMvb::getCrrcMvb()->getBool(0x712,16,1);//牵引变流器2冷却回路异常
    TCMS_FAULT123 = CrrcMvb::getCrrcMvb()->getBool(0x712,16,2);//牵引变流器3冷却回路异常
    TCMS_FAULT124 = CrrcMvb::getCrrcMvb()->getBool(0x712,16,3);//牵引变流器4冷却回路异常
    TCMS_FAULT125 = CrrcMvb::getCrrcMvb()->getBool(0x712,16,4);//牵引电机1冷却回路异常
    TCMS_FAULT126 = CrrcMvb::getCrrcMvb()->getBool(0x712,16,5);//牵引电机2冷却回路异常
    TCMS_FAULT127 = CrrcMvb::getCrrcMvb()->getBool(0x712,16,6);//牵引电机3冷却回路异常
    TCMS_FAULT128 = CrrcMvb::getCrrcMvb()->getBool(0x712,16,7);//牵引电机4冷却回路异常
    TCMS_FAULT129 = CrrcMvb::getCrrcMvb()->getBool(0x712,17,0);//预留
    TCMS_FAULT130 = CrrcMvb::getCrrcMvb()->getBool(0x712,17,1);//机车牵引控制模式异常
    TCMS_FAULT131 = CrrcMvb::getCrrcMvb()->getBool(0x712,17,2);//机车号设置更改
    TCMS_FAULT132 = CrrcMvb::getCrrcMvb()->getBool(0x712,17,3);//牵引特性设置更改
    TCMS_FAULT133 = CrrcMvb::getCrrcMvb()->getBool(0x712,17,4);//轮径设置更改
    TCMS_FAULT134 = CrrcMvb::getCrrcMvb()->getBool(0x712,17,5);//无人警惕设置更改
    TCMS_FAULT135 = CrrcMvb::getCrrcMvb()->getBool(0x712,17,6);//
    TCMS_FAULT136 = CrrcMvb::getCrrcMvb()->getBool(0x712,17,7);//预留
    TCMS_FAULT137 = CrrcMvb::getCrrcMvb()->getBool(0x712,18,0);//
    TCMS_FAULT138 = CrrcMvb::getCrrcMvb()->getBool(0x712,18,1);//
    TCMS_FAULT139 = CrrcMvb::getCrrcMvb()->getBool(0x712,18,2);//
    TCMS_FAULT140 = CrrcMvb::getCrrcMvb()->getBool(0x712,18,3);//
    TCMS_FAULT141 = CrrcMvb::getCrrcMvb()->getBool(0x712,18,4);//
    TCMS_FAULT142 = CrrcMvb::getCrrcMvb()->getBool(0x712,18,5);//
    TCMS_FAULT143 = CrrcMvb::getCrrcMvb()->getBool(0x712,18,6);//
    TCMS_FAULT144 = CrrcMvb::getCrrcMvb()->getBool(0x712,18,7);//
    TCMS_FAULT145 = CrrcMvb::getCrrcMvb()->getBool(0x712,19,0);//
    TCMS_FAULT146 = CrrcMvb::getCrrcMvb()->getBool(0x712,19,1);//
    TCMS_FAULT147 = CrrcMvb::getCrrcMvb()->getBool(0x712,19,2);//
    TCMS_FAULT148 = CrrcMvb::getCrrcMvb()->getBool(0x712,19,3);//
    TCMS_FAULT149 = CrrcMvb::getCrrcMvb()->getBool(0x712,19,4);//
    TCMS_FAULT150 = CrrcMvb::getCrrcMvb()->getBool(0x712,19,5);//预留
    TCMS_FAULT151 = CrrcMvb::getCrrcMvb()->getBool(0x712,19,6);//预留
    TCMS_FAULT152 = CrrcMvb::getCrrcMvb()->getBool(0x712,19,7);//预留
    P712CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x712,31,6);//数据校验(固定发0)
    P712CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x712,31,7);//数据校验(固定发1)
    MODE_ATO = CrrcMvb::getCrrcMvb()->getBool(0x713,8,0);//自动驾驶模式反馈
    P713CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x713,31,6);//数据校验(固定发0)
    P713CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x713,31,7);//数据校验(固定发1)

    LINE_VOLT = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,0);//网压
    BAT_VOLT = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,2);//蓄电池电压,小数点后1位，将数值乘以10
    PRIM_C = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,4);//原边电流,单位A
    MSCT_GRD = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,6);//司控器级位*10 加200后发给DDU
    PARTNER_ID = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,8);//内重联车编号
    TE_AXLE_SET = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,10);//设定牵引力/制动力，单位KN 将数值加1000 乘10
    TEBE_EFFORT = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,12);//总牵引力/制动百分比 小数点后1位，将数值加100后乘以10
    SET_SPEED = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,14);//设定速度，单位km/h
    ACTUAL_SPEED = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,16);//机车速度kmh 乘以10后发给显示屏
    BAT_TMP = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,28);//蓄电池温度 + 50传DDU
    FLL_DIS_STRAIGHT = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,0);//轮缘润滑的距离
    FLL_SECONDS = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,2);//轮缘润滑返回秒数
    WHEEL_DIA = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,4);//轴径 单位：mm
    LOAD = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,6);// 牵引吨位
    TE_AXLE1_ACTUAL = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,8);//轴1实际牵引力/制动力，单位kN  将数值加1000 乘10
    TE_AXLE2_ACTUAL = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,10);//轴2实际牵引力/制动力，单位kN  将数值加1000 乘10
    TE_AXLE3_ACTUAL = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,12);//轴3实际牵引力/制动力，单位kN  将数值加1000 乘10
    TE_AXLE4_ACTUAL = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,14);//轴4实际牵引力/制动力，单位kN  将数值加1000 乘10
    SPD_AXLE1 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,16);//轴1轴速，单位km/h     乘以10
    SPD_AXLE2 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,18);//轴2轴速，单位km/h     乘以10
    SPD_AXLE3 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,20);//轴3轴速，单位km/h     乘以10
    SPD_AXLE4 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,22);//轴4轴速，单位km/h     乘以10
    YEAR = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x712,0);//MPU发来的年份值
    MSCT_GRD_ATO = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x713,6);//ATO级位反馈


    MCB_ON_COUNTER = CrrcMvb::getCrrcMvb()->getUnsignedInt32(0x712,12);//主断闭合次数
    TRIP_COUNTER = CrrcMvb::getCrrcMvb()->getUnsignedInt32(0x712,22);//清零后运行公里数
    TOTAL_DISTANCE = CrrcMvb::getCrrcMvb()->getUnsignedInt32(0x712,26);//总公里数
    CPR_RUN_TIME = CrrcMvb::getCrrcMvb()->getUnsignedInt32(0x713,2);//压缩机运行时间

    UIC_ADDR = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,18) == 0?1:CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,18);;//UIC地址
    OTHERUIC_ADDR = UIC_ADDR == 1?2:1;//内重联他车UIC ID

    AUX1_FREQ = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,26);//辅变流1频率
    AUX2_FREQ = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,27);//辅变流2频率
    MPU_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,30);//MPU生命信号（0～255递增）
    RULOCO_NO = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,28);//重联机车数
    MCB_OFF_CODE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,29);//故障断主断编码
    FLL_TIME = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,30);//轮缘润滑时间
    MONTH = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,2);//MPU发来的月份值
    DATE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,3);//MPU发来的日期值
    HOUR = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,4);//MPU发来的小时值
    MINUTE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,5);//MPU发来的分钟值
    SECOND = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,6);//MPU发来的秒值
    DADMAN_TIME = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,7);//无人警惕倒计时
    DEVICE_NO = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,8);//网络设备编号(循环发送)
    VERSION_X = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,9);//value of x
    VERSION_Y = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,10);//value of y
    VERSION_Z = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,11);//value of z
    DADMAN_TIMESPACE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x713,0);//无人警惕采样间隔时间
    DADMAN_ALARMTIME = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x713,1);//无人警惕报警时间


//DDU-MPU
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,0,TC4_BOGIE1_ISO_RQ);//它车4转向架1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,1,TC4_4Q1_ISO_RQ);//它车4整流器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,2,TC4_4Q2_ISO_RQ);//它车4整流器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,3,TC4_AXLE1_ISO_RQ);//它车4逆变器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,4,TC4_AXLE2_ISO_RQ);//它车4逆变器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,5,TC4_AUX1_ISO_RQ);//它车4辅变流1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,6,TC4_BOGIE2_ISO_RQ);//它车4转向架2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,7,TC4_4Q3_ISO_RQ);//它车4整流器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,0,TC4_4Q4_ISO_RQ);//它车4整流器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,1,TC4_AXLE3_ISO_RQ);//它车4逆变器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,2,TC4_AXLE4_ISO_RQ);//它车4逆变器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,3,TC4_AUX2_ISO_RQ);//它车4辅变流2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,4,TC4_DAMAN_ISO_RQ);//它车4无人警惕隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,5,TC4_EBRK_ISO_RQ);//它车4电制动隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,6,TC4_CPR_ISO_RQ);//它车4空压机隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,7,TC4_FLL_ISO_RQ);//它车4轮缘润滑隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,0,TC4_BOGIE1_ISO_REL_RQ);//它车4转向架1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,1,TC4_4Q1_ISO_REL_RQ);//它车4整流器1隔离取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,2,TC4_4Q2_ISO_REL_RQ);//它车4整流器2隔离取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,3,TC4_AXLE1_ISO_REL_RQ);//它车4逆变器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,4,TC4_AXLE2_ISO_REL_RQ);//它车4逆变器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,5,TC4_AUX1_ISO_REL_RQ);//它车4辅变流1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,6,TC4_BOGIE2_ISO_REL_RQ);//它车4转向架2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,7,TC4_4Q3_ISO_REL_RQ);//它车4整流器3隔离取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,0,TC4_4Q4_ISO_REL_RQ);//它车4整流器4隔离取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,1,TC4_AXLE3_ISO_REL_RQ);//它车4逆变器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,2,TC4_AXLE4_ISO_REL_RQ);//它车4逆变器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,3,TC4_AUX2_ISO_REL_RQ);//它车4辅变流2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,4,TC4_DAMAN_ISO_REL_RQ);//它车4无人警惕隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,5,TC4_EBRK_ISO_REL_RQ);//它车4电制动隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,6,TC4_CPR_ISO_REL_RQ);//它车4空压机隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,7,TC4_FLL_ISO_REL_RQ);//它车4轮缘润滑隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,0,TC1_BOGIE1_ISO_RQ);//它车1转向架1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,1,TC1_4Q1_ISO_RQ);//它车1整流器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,2,TC1_4Q2_ISO_RQ);//它车1整流器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,3,TC1_AXLE1_ISO_RQ);//它车1逆变器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,4,TC1_AXLE2_ISO_RQ);//它车1逆变器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,5,TC1_AUX1_ISO_RQ);//它车1辅变流1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,6,TC1_BOGIE2_ISO_RQ);//它车1转向架2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,7,TC1_4Q3_ISO_RQ);//它车1整流器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,0,TC1_4Q4_ISO_RQ);//它车1整流器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,1,TC1_AXLE3_ISO_RQ);//它车1逆变器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,2,TC1_AXLE4_ISO_RQ);//它车1逆变器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,3,TC1_AUX2_ISO_RQ);//它车1辅变流2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,4,TC1_DAMAN_ISO_RQ);//它车1无人警惕隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,5,TC1_EBRK_ISO_RQ);//它车1电制动隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,6,TC1_CPR_ISO_RQ);//它车1空压机隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,7,TC1_FLL_ISO_RQ);//它车1轮缘润滑隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,0,TC1_BOGIE1_ISO_REL_RQ);//它车1转向架1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,1,TC1_4Q1_ISO_REL_RQ);//它车1整流器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,2,TC1_4Q2_ISO_REL_RQ);//它车1整流器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,3,TC1_AXLE1_ISO_REL_RQ);//它车1逆变器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,4,TC1_AXLE2_ISO_REL_RQ);//它车1逆变器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,5,TC1_AUX1_ISO_REL_RQ);//它车1辅变流1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,6,TC1_BOGIE2_ISO_REL_RQ);//它车1转向架2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,7,TC1_4Q3_ISO_REL_RQ);//它车1整流器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,0,TC1_4Q4_ISO_REL_RQ);//它车1整流器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,1,TC1_AXLE3_ISO_REL_RQ);//它车1逆变器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,2,TC1_AXLE4_ISO_REL_RQ);//它车1逆变器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,3,TC1_AUX2_ISO_REL_RQ);//它车1辅变流2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,4,TC1_DAMAN_ISO_REL_RQ);//它车1无人警惕隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,5,TC1_EBRK_ISO_REL_RQ);//它车1电制动隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,6,TC1_CPR_ISO_REL_RQ);//它车1空压机隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,7,TC1_FLL_ISO_REL_RQ);//它车1轮缘润滑隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,0,TC2_BOGIE1_ISO_RQ);//它车2转向架1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,1,TC2_4Q1_ISO_RQ);//它车2整流器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,2,TC2_4Q2_ISO_RQ);//它车2整流器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,3,TC2_AXLE1_ISO_RQ);//它车2逆变器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,4,TC2_AXLE2_ISO_RQ);//它车2逆变器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,5,TC2_AUX1_ISO_RQ);//它车2辅变流1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,6,TC2_BOGIE2_ISO_RQ);//它车2转向架2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,7,TC2_4Q3_ISO_RQ);//它车2整流器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,0,TC2_4Q4_ISO_RQ);//它车2整流器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,1,TC2_AXLE3_ISO_RQ);//它车2逆变器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,2,TC2_AXLE4_ISO_RQ);//它车2逆变器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,3,TC2_AUX2_ISO_RQ);//它车2辅变流2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,4,TC2_DAMAN_ISO_RQ);//它车2无人警惕隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,5,TC2_EBRK_ISO_RQ);//它车2电制动隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,6,TC2_CPR_ISO_RQ);//它车2空压机隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,7,TC2_FLL_ISO_RQ);//它车2轮缘润滑隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,0,TC2_BOGIE1_ISO_REL_RQ);//它车2转向架1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,1,TC2_4Q1_ISO_REL_RQ);//它车2整流器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,2,TC2_4Q2_ISO_REL_RQ);//它车2整流器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,3,TC2_AXLE1_ISO_REL_RQ);//它车2逆变器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,4,TC2_AXLE2_ISO_REL_RQ);//它车2逆变器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,5,TC2_AUX1_ISO_REL_RQ);//它车2辅变流1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,6,TC2_BOGIE2_ISO_REL_RQ);//它车2转向架2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,7,TC2_4Q3_ISO_REL_RQ);//它车2整流器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,0,TC2_4Q4_ISO_REL_RQ);//它车2整流器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,1,TC2_AXLE3_ISO_REL_RQ);//它车2逆变器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,2,TC2_AXLE4_ISO_REL_RQ);//它车2逆变器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,3,TC2_AUX2_ISO_REL_RQ);//它车2辅变流2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,4,TC2_DAMAN_ISO_REL_RQ);//它车2无人警惕隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,5,TC2_EBRK_ISO_REL_RQ);//它车2电制动隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,6,TC2_CPR_ISO_REL_RQ);//它车2空压机隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,7,TC2_FLL_ISO_REL_RQ);//它车2轮缘润滑隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,0,TC3_BOGIE1_ISO_RQ);//它车3转向架1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,1,TC3_4Q1_ISO_RQ);//它车3整流器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,2,TC3_4Q2_ISO_RQ);//它车3整流器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,3,TC3_AXLE1_ISO_RQ);//它车3逆变器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,4,TC3_AXLE2_ISO_RQ);//它车3逆变器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,5,TC3_AUX1_ISO_RQ);//它车3辅变流1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,6,TC3_BOGIE2_ISO_RQ);//它车3转向架2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,7,TC3_4Q3_ISO_RQ);//它车3整流器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,0,TC3_4Q4_ISO_RQ);//它车3整流器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,1,TC3_AXLE3_ISO_RQ);//它车3逆变器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,2,TC3_AXLE4_ISO_RQ);//它车3逆变器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,3,TC3_AUX2_ISO_RQ);//它车3辅变流2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,4,TC3_DAMAN_ISO_RQ);//它车3无人警惕隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,5,TC3_EBRK_ISO_RQ);//它车3电制动隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,6,TC3_CPR_ISO_RQ);//它车3空压机隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,7,TC3_FLL_ISO_RQ);//它车3轮缘润滑隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,0,TC3_BOGIE1_ISO_REL_RQ);//它车3转向架1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,1,TC3_4Q1_ISO_REL_RQ);//它车3整流器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,2,TC3_4Q2_ISO_REL_RQ);//它车3整流器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,3,TC3_AXLE1_ISO_REL_RQ);//它车3逆变器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,4,TC3_AXLE2_ISO_REL_RQ);//它车3逆变器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,5,TC3_AUX1_ISO_REL_RQ);//它车3辅变流1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,6,TC3_BOGIE2_ISO_REL_RQ);//它车3转向架2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,7,TC3_4Q3_ISO_REL_RQ);//它车3整流器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,0,TC3_4Q4_ISO_REL_RQ);//它车3整流器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,1,TC3_AXLE3_ISO_REL_RQ);//它车3逆变器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,2,TC3_AXLE4_ISO_REL_RQ);//它车3逆变器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,3,TC3_AUX2_ISO_REL_RQ);//它车3辅变流2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,4,TC3_DAMAN_ISO_REL_RQ);//它车3无人警惕隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,5,TC3_EBRK_ISO_REL_RQ);//它车3电制动隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,6,TC3_CPR_ISO_REL_RQ);//它车3空压机隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,7,TC3_FLL_ISO_REL_RQ);//它车3轮缘润滑隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,1,TC1_PANTO_ISO_RQ);//它车1受电弓隔离
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,2,TC1_PANTO_ISO_REL_RQ);//它车1受电弓隔离取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,4,SIM_ON);//仿真开关
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,6,TC4_FAULT_RESET);//它车4故障复位
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,7,MILEAGE_RESET);//里程清零
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,0,TC2_PANTO_ISO_RQ);//它车2受电弓隔离
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,1,TC2_PANTO_ISO_REL_RQ);//它车2受电弓隔离取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,2,TC1_FAULT_RESET);//它车1故障复位
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,3,TC2_FAULT_RESET);//它车2故障复位
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,4,TC3_FAULT_RESET);//它车3故障复位
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,6,TC3_PANTO_ISO_RQ);//它车3受电弓隔离
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,7,TC3_PANTO_ISO_REL_RQ);//它车3受电弓隔离取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,0,LAMP_TEST);//指示灯测试
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,1,DAMAN_TEST);//无人警惕测试
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,2,FLL_TEST_START);//轮缘润滑测试开始
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,3,FLL_TEST_CANCEL);//轮缘润滑测试取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,4,CPR_TEST);//空压机测试
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,5,ANSC_TEST);//自动过分相测试
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,6,TC4_PANTO_ISO_RQ);//它车4受电弓隔离
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,7,TC4_PANTO_ISO_REL_RQ);//它车4受电弓隔离取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,0,DEPOT_380_ACT);//库内激活
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,1,DEPOT_380_DEACT);//库内激活关闭
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,3,SEQUENCE_TEST);//顺序试验激活
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,4,SAND_CUTDDU);//自动撒沙切除(1切除，0取消切除)
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,5,ELEC_AIR_CUTDDU);//空电联合切除(1切除，0取消切除)
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,6,LOAD_SET);//牵引吨位设置标志(持续5s)
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,7,FIR_ALARM_CONFIRM);//火灾报警确认
    CrrcMvb::getCrrcMvb()->setBool(0x300,31,6,P300CHECK0);//数据校验（固定发0）
    CrrcMvb::getCrrcMvb()->setBool(0x300,31,7,P300CHECK1);//数据校验（固定发1）
    CrrcMvb::getCrrcMvb()->setBool(0x301,20,0,WHEEL_DIA_SET);//轮径设置标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,20,1,FLL_SET);//轮缘润滑值设置标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,20,2,TIME_SET);//时间设置标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,20,3,ID_SET);//机车和Partner ID设定标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,20,4,DADMAN_SET);//无人警惕参数设置标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,20,5,NSC_DISTANCE1DDU);//常规线路过分相：170m模式
    CrrcMvb::getCrrcMvb()->setBool(0x301,20,6,NSC_DISTANCE2DDU);//货运专线过分相：265m模式
    CrrcMvb::getCrrcMvb()->setBool(0x301,20,7,NSC_SET);//过分相模式设定标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,21,0,NORMAL_MODEDDU);//普通模式
    CrrcMvb::getCrrcMvb()->setBool(0x301,21,1,SUMMER_MODEDDU);//夏天模式
    CrrcMvb::getCrrcMvb()->setBool(0x301,21,2,T_CHAR);//牵引特性设定，恒转矩
    CrrcMvb::getCrrcMvb()->setBool(0x301,21,4,DOUBLE_PG_ON);//双弓模式激活
    CrrcMvb::getCrrcMvb()->setBool(0x301,21,5,DOUBLE_PG_OFF);//双弓模式关闭
    CrrcMvb::getCrrcMvb()->setBool(0x301,24,0,VT_BM1_ST);//冷却塔风机1测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x301,24,1,VT_BM2_ST);//冷却塔风机2测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x301,24,2,VT_MT1_ST);//牵引风机1测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x301,24,3,VT_MT2_ST);//牵引风机2测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x301,24,4,VT_SM1_ST);//机械间风机1测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x301,24,5,VT_SM2_ST);//机械间风机2测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x301,31,6,P301CHECK0);//数据校验（固定发0）
    CrrcMvb::getCrrcMvb()->setBool(0x301,31,7,P301CHECK1);//数据校验（固定发1）
    CrrcMvb::getCrrcMvb()->setBool(0x302,31,6,P302CHECK0);//数据校验（固定发0）
    CrrcMvb::getCrrcMvb()->setBool(0x302,31,7,P302CHECK1);//数据校验（固定发1）

    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x300,0,SPEED_SET);//机车定速值
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x300,22,SIM_LINE_VOLT);//模拟网压
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x300,24,SIM_SPEED);//模拟机车速度
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x300,26,LOADDDU);//牵引吨位
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,0,LOCO_ID);//本机车号
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,2,PARTNER_IDDDU);//PARTNER ID
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,6,YEARDDU);//DDU发出的年份值
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,14,WHEEL_DIADDU);//轮径设定值 单位：mm
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,16,FLL_DIS);//轮缘润滑距离 单位：mm

    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x300,30,DDU_LIFE);//DDU生命信号
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,8,MONTHDDU);//DDU发出的月份值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,9,DAYDDU);//DDU发出的日期值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,10,HOURDDU);//DDU发出的小时值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,11,MINUTEDDU);//DDU发出的分钟值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,12,SECONDDDU);//DDU发出的秒钟值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,13,FLL_TIMEDDU);//轮缘润滑时间
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,18,DADMAN_TIMESPACEDDU);//无人警惕采样间隔时间
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,19,DADMAN_TIMEALARM);//无人警惕报警时间
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,22,DDU_VX);//DDU版本号x
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,23,DDU_VY);//DDU版本号y

}
