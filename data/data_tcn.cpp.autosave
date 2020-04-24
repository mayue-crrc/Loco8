#include "data_tcn.h"
#include "crrcmvb.h"
Data_TCN::Data_TCN()
{
    for(int i = 0;i<4;i++)
    {
        train[i] = new TrainBean();
    }
    //本车数据对象，命名和TCN-MPU一致。
    TrainLocal = new TrainBean();
}
void Data_TCN::updateData()
{

    //tcn->MPU


    QList<int >t_portlist,t_virtualportlist;
    t_portlist<<0x62b<<0x62c<<0x62d<<0x62e<<0x62f<<0x630<<0x631;
    t_virtualportlist<<0x162b<<0x162c<<0x162d<<0x162e<<0x162f<<0x1630<<0x1631
                     <<0x262b<<0x262c<<0x262d<<0x262e<<0x262f<<0x2630<<0x2631
                     <<0x362b<<0x362c<<0x632d<<0x362e<<0x362f<<0x3630<<0x3631;
    //fill TCN data
    for(int i = 0;i<4;i++)
    {
        train[i]->CMD_KEY = CrrcMvb::getCrrcMvb()->getBool(0x605,4+i*2,0);//它车1 电钥匙
        train[i]->STATE_QS_GHV = CrrcMvb::getCrrcMvb()->getBool(0x605,4+i*2,1);//它车1 接地开关状态
        train[i]->STATE_MA_SU_PT = CrrcMvb::getCrrcMvb()->getBool(0x605,4+i*2,2);//它车1 受电弓压力开关状态
        train[i]->STATE_MA1_CP = CrrcMvb::getCrrcMvb()->getBool(0x605,4+i*2,3);//它车1 总风压力开关
        train[i]->STATE_H_HT = CrrcMvb::getCrrcMvb()->getBool(0x605,4+i*2,4);//它车1 高压隔离开关状态
        train[i]->CMD_EMGE = CrrcMvb::getCrrcMvb()->getBool(0x605,4+i*2,5);//它车1 电控紧急
        train[i]->TCN_DIR_BIT0 = CrrcMvb::getCrrcMvb()->getBool(0x605,4+i*2,6);//它车1 TCN方向BIT0
        train[i]->TCN_DIR_BIT1 = CrrcMvb::getCrrcMvb()->getBool(0x605,4+i*2,7);//它车1 CN方向BIT1
        train[i]->CMD_T = CrrcMvb::getCrrcMvb()->getBool(0x605,5+i*2,0);//它车1 T满级位
        train[i]->CMD_T23 = CrrcMvb::getCrrcMvb()->getBool(0x605,5+i*2,1);//它车1 T2/3级位
        train[i]->CMD_T13 = CrrcMvb::getCrrcMvb()->getBool(0x605,5+i*2,2);//它车1 T1/3级位
        train[i]->CMD_B13 = CrrcMvb::getCrrcMvb()->getBool(0x605,5+i*2,3);//它车1 B1/3级位
        train[i]->CMD_B23 = CrrcMvb::getCrrcMvb()->getBool(0x605,5+i*2,4);//它车1 B2/3级位
        train[i]->CMD_B = CrrcMvb::getCrrcMvb()->getBool(0x605,5+i*2,5);//它车1 B满级位
        train[i]->GW_CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x605,5+i*2,6);//它车1 检查变量0
        train[i]->GW_CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x605,5+i*2,7);//它车1 检查变量1
        train[i]->CMD_PANTO_R = CrrcMvb::getCrrcMvb()->getBool(0x606,4+i*2,0);//它车1 升弓
        train[i]->CMD_PANTO_D = CrrcMvb::getCrrcMvb()->getBool(0x606,4+i*2,1);//它车1 降弓
        train[i]->CMD_QFM_K = CrrcMvb::getCrrcMvb()->getBool(0x606,4+i*2,2);//它车1 主断合
        train[i]->CMD_QFM_C = CrrcMvb::getCrrcMvb()->getBool(0x606,4+i*2,3);//它车1 主断保持
        train[i]->CMD_DIR_f = CrrcMvb::getCrrcMvb()->getBool(0x606,4+i*2,4);//它车1 向前
        train[i]->CMD_DIR_N = CrrcMvb::getCrrcMvb()->getBool(0x606,4+i*2,5);//它车1 方向零位
        train[i]->CMD_DIR_B = CrrcMvb::getCrrcMvb()->getBool(0x606,4+i*2,6);//它车1 向后
        train[i]->CMD_CONS = CrrcMvb::getCrrcMvb()->getBool(0x606,4+i*2,7);//它车1 定速
        train[i]->CMD_MSCT_N = CrrcMvb::getCrrcMvb()->getBool(0x606,5+i*2,0);//它车1 司控器零位
        train[i]->CMD_CPR_RUN = CrrcMvb::getCrrcMvb()->getBool(0x606,5+i*2,1);//它车1 压缩机运行
        train[i]->CMD_PUMP = CrrcMvb::getCrrcMvb()->getBool(0x606,5+i*2,2);//它车1 强泵
        train[i]->CMD_ANSC2 = CrrcMvb::getCrrcMvb()->getBool(0x606,5+i*2,3);//它车1 ANSC强断
        train[i]->CMD_ANSC1 = CrrcMvb::getCrrcMvb()->getBool(0x606,5+i*2,4);//它车1 ANSC预备恢复
        train[i]->CMD_MNSC = CrrcMvb::getCrrcMvb()->getBool(0x606,5+i*2,5);//它车1 手动过分相
        train[i]->P606CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x606,5+i*2,6);//检查变量0
        train[i]->P606CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x606,5+i*2,7);//检查变量1
        train[i]->CMD_BP_RESET = CrrcMvb::getCrrcMvb()->getBool(0x607,4+i*2,0);//它车1 复位按钮
        train[i]->CMD_CAB_CHANGE = CrrcMvb::getCrrcMvb()->getBool(0x607,4+i*2,1);//它车1换端
        train[i]->CMD_MA1_FD = CrrcMvb::getCrrcMvb()->getBool(0x607,4+i*2,2);//它车1 小闸压力开关
        train[i]->CMD_FLL_TEST_START = CrrcMvb::getCrrcMvb()->getBool(0x607,4+i*2,3);//它车1 轮缘润滑测试开始
        train[i]->CMD_FLL_TEST_CANCEL = CrrcMvb::getCrrcMvb()->getBool(0x607,4+i*2,4);//它车1 轮缘润滑测试取消
        train[i]->CMD_NSC_FAULT = CrrcMvb::getCrrcMvb()->getBool(0x607,4+i*2,5);//过分相故障
        train[i]->CMD_SAND_RQ = CrrcMvb::getCrrcMvb()->getBool(0x607,4+i*2,6);//撒砂请求
        train[i]->CMD_SAND_CUT = CrrcMvb::getCrrcMvb()->getBool(0x607,4+i*2,7);//撒砂切除
        train[i]->CMD_TC1_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,4+i*2,0);//它车1 它车1 整流器1隔离请求
        train[i]->CMD_TC1_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,4+i*2,1);//它车1 它车1 整流器2隔离请求
        train[i]->CMD_TC1_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,4+i*2,2);//它车1 它车1 整流器3隔离请求
        train[i]->CMD_TC1_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,4+i*2,3);//它车1 它车1 整流器4隔离请求
        train[i]->CMD_TC1_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,4+i*2,4);//它车1 它车1 轴1隔离请求
        train[i]->CMD_TC1_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,4+i*2,5);//它车1 它车1 轴2隔离请求
        train[i]->CMD_TC1_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,4+i*2,6);//它车1 它车1 轴3隔离请求
        train[i]->CMD_TC1_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,4+i*2,7);//它车1 它车1 轴4隔离请求
        train[i]->CMD_TC1_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,5+i*2,0);//它车1 它车1 辅变流1隔离请求
        train[i]->CMD_TC1_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,5+i*2,1);//它车1 它车1 辅变流2隔离请求
        train[i]->CMD_TC1_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,5+i*2,2);//它车1 它车1 无人警惕隔离请求
        train[i]->CMD_TC1_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,5+i*2,3);//它车1 它车1 电制动隔离请求
        train[i]->CMD_TC1_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,5+i*2,4);//它车1 它车1 空压机隔离请求
        train[i]->CMD_TC1_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,5+i*2,5);//它车1 它车1 受电弓隔离请求
        train[i]->CMD_TC1_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x609,5+i*2,6);//它车1 它车1 轮缘润滑隔离请求
        train[i]->CMD_DDU_RESET = CrrcMvb::getCrrcMvb()->getBool(0x609,5+i*2,7);//它车1 DDU故障复位命令
        train[i]->CMD_TC1_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,4+i*2,0);//它车1 它车1 整流器1隔离取消请求
        train[i]->CMD_TC1_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,4+i*2,1);//它车1 它车1 整流器2隔离取消请求
        train[i]->CMD_TC1_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,4+i*2,2);//它车1 它车1 整流器3隔离取消请求
        train[i]->CMD_TC1_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,4+i*2,3);//它车1 它车1 整流器4隔离取消请求
        train[i]->CMD_TC1_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,4+i*2,4);//它车1 它车1 轴1隔离取消请求
        train[i]->CMD_TC1_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,4+i*2,5);//它车1 它车1 轴2隔离取消请求
        train[i]->CMD_TC1_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,4+i*2,6);//它车1 它车1 轴3隔离取消请求
        train[i]->CMD_TC1_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,4+i*2,7);//它车1 它车1 轴4隔离取消请求
        train[i]->CMD_TC1_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,5+i*2,0);//它车1 它车1 辅变流1隔离取消请求
        train[i]->CMD_TC1_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,5+i*2,1);//它车1 它车1 辅变流2隔离取消请求
        train[i]->CMD_TC1_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,5+i*2,2);//它车1 它车1 无人警惕隔离取消请求
        train[i]->CMD_TC1_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,5+i*2,3);//它车1 它车1 电制动隔离取消请求
        train[i]->CMD_TC1_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,5+i*2,4);//它车1 它车1 空压机隔离取消请求
        train[i]->CMD_TC1_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,5+i*2,5);//它车1 它车1 受电弓隔离取消请求
        train[i]->CMD_TC1_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60A,5+i*2,6);//它车1 它车1 轮缘润滑隔离取消请求
        train[i]->ELEC_AIR_CUT = CrrcMvb::getCrrcMvb()->getBool(0x60A,5+i*2,7);//空电切除
        train[i]->CMD_TC2_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,4+i*2,0);//它车1 它车2 整流器1隔离请求
        train[i]->CMD_TC2_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,4+i*2,1);//它车1 它车2 整流器2隔离请求
        train[i]->CMD_TC2_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,4+i*2,2);//它车1 它车2 整流器3隔离请求
        train[i]->CMD_TC2_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,4+i*2,3);//它车1 它车2 整流器4隔离请求
        train[i]->CMD_TC2_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,4+i*2,4);//它车1 它车2 轴1隔离请求
        train[i]->CMD_TC2_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,4+i*2,5);//它车1 它车2 轴2隔离请求
        train[i]->CMD_TC2_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,4+i*2,6);//它车1 它车2 轴3隔离请求
        train[i]->CMD_TC2_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,4+i*2,7);//它车1 它车2 轴4隔离请求
        train[i]->CMD_TC2_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,5+i*2,0);//它车1 它车2 辅变流1隔离请求
        train[i]->CMD_TC2_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,5+i*2,1);//它车1 它车2 辅变流2隔离请求
        train[i]->CMD_TC2_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,5+i*2,2);//它车1 它车2 无人警惕隔离请求
        train[i]->CMD_TC2_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,5+i*2,3);//它车1 它车2 电制动隔离请求
        train[i]->CMD_TC2_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,5+i*2,4);//它车1 它车2 空压机隔离请求
        train[i]->CMD_TC2_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,5+i*2,5);//它车1 它车2 受电弓隔离请求
        train[i]->CMD_TC2_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60B,5+i*2,6);//它车1 它车2 轮缘润滑隔离请求
        train[i]->CMD_T_CHAR_H = CrrcMvb::getCrrcMvb()->getBool(0x60B,5+i*2,7);//它车1 恒转矩设定命令
        train[i]->CMD_TC2_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,4+i*2,0);//它车1 它车2 整流器1隔离取消请求
        train[i]->CMD_TC2_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,4+i*2,1);//它车1 它车2 整流器2隔离取消请求
        train[i]->CMD_TC2_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,4+i*2,2);//它车1 它车2 整流器3隔离取消请求
        train[i]->CMD_TC2_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,4+i*2,3);//它车1 它车2 整流器4隔离取消请求
        train[i]->CMD_TC2_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,4+i*2,4);//它车1 它车2 轴1隔离取消请求
        train[i]->CMD_TC2_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,4+i*2,5);//它车1 它车2 轴2隔离取消请求
        train[i]->CMD_TC2_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,4+i*2,6);//它车1 它车2 轴3隔离取消请求
        train[i]->CMD_TC2_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,4+i*2,7);//它车1 它车2 轴4隔离取消请求
        train[i]->CMD_TC2_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,5+i*2,0);//它车1 它车2 辅变流1隔离取消请求
        train[i]->CMD_TC2_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,5+i*2,1);//它车1 它车2 辅变流2隔离取消请求
        train[i]->CMD_TC2_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,5+i*2,2);//它车1 它车2 无人警惕隔离取消请求
        train[i]->CMD_TC2_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,5+i*2,3);//它车1 它车2 电制动隔离取消请求
        train[i]->CMD_TC2_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,5+i*2,4);//它车1 它车2 空压机隔离取消请求
        train[i]->CMD_TC2_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,5+i*2,5);//它车1 它车2 受电弓隔离取消请求
        train[i]->CMD_TC2_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60C,5+i*2,6);//它车1 它车2 轮缘润滑隔离取消请求
        train[i]->CMD_SUMMER_MODE = CrrcMvb::getCrrcMvb()->getBool(0x60C,5+i*2,7);//它车1 夏季模式
        train[i]->CMD_TC3_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,4+i*2,0);//它车1 它车3 整流器1隔离请求
        train[i]->CMD_TC3_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,4+i*2,1);//它车1 它车3 整流器2隔离请求
        train[i]->CMD_TC3_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,4+i*2,2);//它车1 它车3 整流器3隔离请求
        train[i]->CMD_TC3_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,4+i*2,3);//它车1 它车3 整流器4隔离请求
        train[i]->CMD_TC3_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,4+i*2,4);//它车1 它车3 轴1隔离请求
        train[i]->CMD_TC3_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,4+i*2,5);//它车1 它车3 轴2隔离请求
        train[i]->CMD_TC3_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,4+i*2,6);//它车1 它车3 轴3隔离请求
        train[i]->CMD_TC3_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,4+i*2,7);//它车1 它车3 轴4隔离请求
        train[i]->CMD_TC3_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,5+i*2,0);//它车1 它车3 辅变流1隔离请求
        train[i]->CMD_TC3_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,5+i*2,1);//它车1 它车3 辅变流2隔离请求
        train[i]->CMD_TC3_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,5+i*2,2);//它车1 它车3 无人警惕隔离请求
        train[i]->CMD_TC3_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,5+i*2,3);//它车1 它车3 电制动隔离请求
        train[i]->CMD_TC3_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,5+i*2,4);//它车1 它车3 空压机隔离请求
        train[i]->CMD_TC3_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,5+i*2,5);//它车1 它车3 受电弓隔离请求
        train[i]->CMD_TC3_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60D,+i*2,6);//它车1 它车3 轮缘润滑隔离请求
        train[i]->CMD_T_CHAR_Z = CrrcMvb::getCrrcMvb()->getBool(0x60D,5+i*2,7);//它车1 准恒速设定命令
        train[i]->CMD_TC3_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,4+i*2,0);//它车1 它车3 整流器1隔离取消请求
        train[i]->CMD_TC3_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,4+i*2,1);//它车1 它车3 整流器2隔离取消请求
        train[i]->CMD_TC3_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,4+i*2,2);//它车1 它车3 整流器3隔离取消请求
        train[i]->CMD_TC3_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,4+i*2,3);//它车1 它车3 整流器4隔离取消请求
        train[i]->CMD_TC3_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,4+i*2,4);//它车1 它车3 轴1隔离取消请求
        train[i]->CMD_TC3_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,4+i*2,5);//它车1 它车3 轴2隔离取消请求
        train[i]->CMD_TC3_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,4+i*2,6);//它车1 它车3 轴3隔离取消请求
        train[i]->CMD_TC3_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,4+i*2,7);//它车1 它车3 轴4隔离取消请求
        train[i]->CMD_TC3_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,5+i*2,0);//它车1 它车3 辅变流1隔离取消请求
        train[i]->CMD_TC3_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,5+i*2,1);//它车1 它车3 辅变流2隔离取消请求
        train[i]->CMD_TC3_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,5+i*2,2);//它车1 它车3 无人警惕隔离取消请求
        train[i]->CMD_TC3_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,5+i*2,3);//它车1 它车3 电制动隔离取消请求
        train[i]->CMD_TC3_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,5+i*2,4);//它车1 它车3 空压机隔离取消请求
        train[i]->CMD_TC3_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,5+i*2,5);//它车1 它车3 受电弓隔离取消请求
        train[i]->CMD_TC3_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x60E,5+i*2,6);//它车1 它车3 轮缘润滑隔离取消请求
        train[i]->CMD_WINTER_MODE = CrrcMvb::getCrrcMvb()->getBool(0x60E,5+i*2,7);//它车1 冬季模式
        train[i]->STATE_CAB_ACT = CrrcMvb::getCrrcMvb()->getBool(0x60F,4+i*2,0);//它车1 电钥匙激活
        train[i]->STATE_QFM_ON = CrrcMvb::getCrrcMvb()->getBool(0x60F,4+i*2,1);//它车1 主断合
        train[i]->STATE_QFM_K = CrrcMvb::getCrrcMvb()->getBool(0x60F,4+i*2,2);//它车1 主断预备
        train[i]->STATE_QFM_OFF = CrrcMvb::getCrrcMvb()->getBool(0x60F,4+i*2,3);//它车1 主断断开
        train[i]->STATE_QFM_ISO = CrrcMvb::getCrrcMvb()->getBool(0x60F,4+i*2,4);//它车1 主断隔离
        train[i]->STATE_PANTO_DN = CrrcMvb::getCrrcMvb()->getBool(0x60F,4+i*2,5);//它车1 受电弓降下
        train[i]->STATE_PANTO_RG = CrrcMvb::getCrrcMvb()->getBool(0x60F,4+i*2,6);//它车1 受电弓升弓
        train[i]->STATE_PANTO_RD = CrrcMvb::getCrrcMvb()->getBool(0x60F,4+i*2,7);//它车1 受电弓升起
        train[i]->STATE_PANTO_ISO = CrrcMvb::getCrrcMvb()->getBool(0x60F,5+i*2,0);//它车1 受电弓隔离
        train[i]->STATE_EMG_BRK_ON = CrrcMvb::getCrrcMvb()->getBool(0x60F,5+i*2,1);//它车1 紧急制动施加
        train[i]->STATE_EMG_BRK_I = CrrcMvb::getCrrcMvb()->getBool(0x60F,5+i*2,2);//它车1 紧急制动隔离
        train[i]->STATE_PARK_BRK_ON = CrrcMvb::getCrrcMvb()->getBool(0x60F,5+i*2,3);//它车1 停放制动施加
        train[i]->STATE_PARK_BRK_I = CrrcMvb::getCrrcMvb()->getBool(0x60F,5+i*2,4);//它车1 停放制动隔离
        train[i]->STATE_AIR_BRK1_ON = CrrcMvb::getCrrcMvb()->getBool(0x60F,5+i*2,5);//它车1 空气制动1施加
        train[i]->STATE_AIR_BRK1_I = CrrcMvb::getCrrcMvb()->getBool(0x60F,5+i*2,6);//它车1 空气制动1隔离
        train[i]->STATE_AIR_BRK2_ON = CrrcMvb::getCrrcMvb()->getBool(0x60F,5+i*2,7);//它车1 空气制动2施加
        train[i]->STATE_AIR_BRK2_I = CrrcMvb::getCrrcMvb()->getBool(0x610,4+i*2,0);//它车1 空气制动2隔离
        train[i]->STATE_C_BAU1 = CrrcMvb::getCrrcMvb()->getBool(0x610,4+i*2,1);//它车1 辅助1接触器状态
        train[i]->STATE_C_BAU2 = CrrcMvb::getCrrcMvb()->getBool(0x610,4+i*2,2);//它车1 辅助2接触器状态
        train[i]->STATE_C_SEC = CrrcMvb::getCrrcMvb()->getBool(0x610,4+i*2,3);//它车1 辅变流降级接触器状态
        train[i]->QFM_OFF_PROTECT = CrrcMvb::getCrrcMvb()->getBool(0x610,4+i*2,4);//它车1断主断保护
        train[i]->STATE_RB_IS_FS = CrrcMvb::getCrrcMvb()->getBool(0x610,4+i*2,5);//它车1 停放制动隔离阀状态
        train[i]->STATE_RB_EMG = CrrcMvb::getCrrcMvb()->getBool(0x610,4+i*2,6);//它车1 紧急制动隔离阀状态
        train[i]->STATE_RB_IS_CF1 = CrrcMvb::getCrrcMvb()->getBool(0x610,4+i*2,7);//它车1 制动缸1隔离阀状态
        train[i]->STATE_RB_IS_CF2 = CrrcMvb::getCrrcMvb()->getBool(0x610,5+i*2,0);//它车1 制动缸2隔离阀状态
        train[i]->STATE_C1_CPR = CrrcMvb::getCrrcMvb()->getBool(0x610,5+i*2,1);//它车1 压缩机接触器1状态
        train[i]->STATE_C2_CPR = CrrcMvb::getCrrcMvb()->getBool(0x610,5+i*2,2);//它车1 压缩机接触器2状态
        train[i]->STATE_C3_CPR = CrrcMvb::getCrrcMvb()->getBool(0x610,5+i*2,3);//它车1 压缩机接触器3状态
        train[i]->STATE_Q_TH_VT_BM1 = CrrcMvb::getCrrcMvb()->getBool(0x610,5+i*2,4);//它车1 冷却塔风机1热继状态
        train[i]->STATE_Q_TH_VT_BM2 = CrrcMvb::getCrrcMvb()->getBool(0x610,5+i*2,5);//它车1 冷却塔风机2热继状态
        train[i]->STATE_C_VT_BM1 = CrrcMvb::getCrrcMvb()->getBool(0x610,5+i*2,6);//它车1 冷却塔风机1接触器状态
        train[i]->STATE_C_VT_BM2 = CrrcMvb::getCrrcMvb()->getBool(0x610,5+i*2,7);//它车1 冷却塔风机2接触器状态
        train[i]->STATE_C_VT_MT1 = CrrcMvb::getCrrcMvb()->getBool(0x611,4+i*2,0);//它车1 牵引风机1接触器状态
        train[i]->STATE_C_VT_MT2 = CrrcMvb::getCrrcMvb()->getBool(0x611,4+i*2,1);//它车1 牵引风机2接触器状态
        train[i]->STATE_C_VT_SM1 = CrrcMvb::getCrrcMvb()->getBool(0x611,4+i*2,2);//它车1 机械间风机1接触器状态
        train[i]->STATE_C_VT_SM2 = CrrcMvb::getCrrcMvb()->getBool(0x611,4+i*2,3);//它车1 机械间风机2接触器状态
        train[i]->STATE_DJ_PE1 = CrrcMvb::getCrrcMvb()->getBool(0x611,4+i*2,4);//它车1 水泵1断路器状态
        train[i]->STATE_DJ_PE2 = CrrcMvb::getCrrcMvb()->getBool(0x611,4+i*2,5);//它车1 水泵2断路器状态
        train[i]->STATE_DJ_PE3 = CrrcMvb::getCrrcMvb()->getBool(0x611,4+i*2,6);//它车1 水泵3断路器状态
        train[i]->STATE_DJ_PE4 = CrrcMvb::getCrrcMvb()->getBool(0x611,4+i*2,7);//它车1 水泵4断路器状态
        train[i]->STATE_DJ_PH1 = CrrcMvb::getCrrcMvb()->getBool(0x611,5+i*2,0);//它车1 油泵1断路器状态
        train[i]->STATE_DJ_PH2 = CrrcMvb::getCrrcMvb()->getBool(0x611,5+i*2,1);//它车1 油泵2断路器状态
        train[i]->STATE_DJ_VT_SM1 = CrrcMvb::getCrrcMvb()->getBool(0x611,5+i*2,2);//它车1 机械间风机1断路器状态
        train[i]->STATE_DJ_VT_SM2 = CrrcMvb::getCrrcMvb()->getBool(0x611,5+i*2,3);//它车1 机械间风机2断路器状态
        train[i]->STATE_Q_TH_CPR = CrrcMvb::getCrrcMvb()->getBool(0x611,5+i*2,4);//它车1 压缩机热保护继电器状态
        train[i]->STATE_Q_REC = CrrcMvb::getCrrcMvb()->getBool(0x611,5+i*2,5);//它车1 压缩机低温保护继电器状态
        train[i]->STATE_Q_TH_VT_MT1 = CrrcMvb::getCrrcMvb()->getBool(0x611,5+i*2,6);//它车1 牵引风机1热继状态
        train[i]->STATE_Q_TH_VT_MT2 = CrrcMvb::getCrrcMvb()->getBool(0x611,5+i*2,7);//它车1 牵引风机2热继状态
        train[i]->NSC_DISTANCE1 = CrrcMvb::getCrrcMvb()->getBool(0x632,4+i*2,0);//常规线路过分相：170m模式
        train[i]->NSC_DISTANCE2 = CrrcMvb::getCrrcMvb()->getBool(0x632,4+i*2,1);//货运专线过分相：265m模式
        train[i]->Bail_ACT = CrrcMvb::getCrrcMvb()->getBool(0x632,5+i*2,0);//BCU-MPU Bit 6: Bail Activates
        train[i]->Bail_NULL = CrrcMvb::getCrrcMvb()->getBool(0x632,5+i*2,1);//BCU-MPU Bit 7: Bail has been nullified by CCB
        train[i]->FREIGHT_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(0x632,5+i*2,2);//货车/投入
        train[i]->PSG_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(0x632,5+i*2,3);//客车/投入
        train[i]->ABH_MIN  = CrrcMvb::getCrrcMvb()->getBool(0x632,5+i*2,4);//大闸Minimum
        train[i]->ABH_SERV_Z = CrrcMvb::getCrrcMvb()->getBool(0x632,5+i*2,5);//大闸Service_Zone
        train[i]->ABH_FULL_SERV = CrrcMvb::getCrrcMvb()->getBool(0x632,5+i*2,6);//大闸Full_Service
        train[i]->STATE_T_CHAR = CrrcMvb::getCrrcMvb()->getBool(0x632,5+i*2,7);//牵引特性反馈0：恒转矩1：准恒速
        train[i]->TACU_FAULT1 = CrrcMvb::getCrrcMvb()->getBool(0x633,4+i*2,0);//
        train[i]->TACU_FAULT2 = CrrcMvb::getCrrcMvb()->getBool(0x633,4+i*2,1);//
        train[i]->TACU_FAULT3 = CrrcMvb::getCrrcMvb()->getBool(0x633,4+i*2,2);//
        train[i]->TACU_FAULT4 = CrrcMvb::getCrrcMvb()->getBool(0x633,4+i*2,3);//
        train[i]->TACU_FAULT5 = CrrcMvb::getCrrcMvb()->getBool(0x633,4+i*2,4);//
        train[i]->TACU_FAULT6 = CrrcMvb::getCrrcMvb()->getBool(0x633,4+i*2,5);//
        train[i]->TACU_FAULT7 = CrrcMvb::getCrrcMvb()->getBool(0x633,4+i*2,6);//
        train[i]->TACU_FAULT8 = CrrcMvb::getCrrcMvb()->getBool(0x633,4+i*2,7);//
        train[i]->TACU_FAULT9 = CrrcMvb::getCrrcMvb()->getBool(0x633,5+i*2,0);//
        train[i]->TACU_FAULT10 = CrrcMvb::getCrrcMvb()->getBool(0x633,5+i*2,1);//
        train[i]->TACU_FAULT11 = CrrcMvb::getCrrcMvb()->getBool(0x633,5+i*2,2);//
        train[i]->TACU_FAULT12 = CrrcMvb::getCrrcMvb()->getBool(0x633,5+i*2,3);//
        train[i]->TACU_FAULT13 = CrrcMvb::getCrrcMvb()->getBool(0x633,5+i*2,4);//
        train[i]->TACU_FAULT14 = CrrcMvb::getCrrcMvb()->getBool(0x633,5+i*2,5);//
        train[i]->TACU_FAULT15 = CrrcMvb::getCrrcMvb()->getBool(0x633,5+i*2,6);//
        train[i]->TACU_FAULT16 = CrrcMvb::getCrrcMvb()->getBool(0x633,5+i*2,7);//
        train[i]->TACU_FAULT17 = CrrcMvb::getCrrcMvb()->getBool(0x634,4+i*2,0);//
        train[i]->TACU_FAULT18 = CrrcMvb::getCrrcMvb()->getBool(0x634,4+i*2,1);//
        train[i]->TACU_FAULT19 = CrrcMvb::getCrrcMvb()->getBool(0x634,4+i*2,2);//
        train[i]->TACU_FAULT20 = CrrcMvb::getCrrcMvb()->getBool(0x634,4+i*2,3);//
        train[i]->TACU_FAULT21 = CrrcMvb::getCrrcMvb()->getBool(0x634,4+i*2,4);//
        train[i]->TACU_FAULT22 = CrrcMvb::getCrrcMvb()->getBool(0x634,4+i*2,5);//
        train[i]->TACU_FAULT23 = CrrcMvb::getCrrcMvb()->getBool(0x634,4+i*2,6);//
        train[i]->TACU_FAULT24 = CrrcMvb::getCrrcMvb()->getBool(0x634,4+i*2,7);//
        train[i]->TACU_FAULT25 = CrrcMvb::getCrrcMvb()->getBool(0x634,5+i*2,0);//
        train[i]->TACU_FAULT26 = CrrcMvb::getCrrcMvb()->getBool(0x634,5+i*2,1);//
        train[i]->TACU_FAULT27 = CrrcMvb::getCrrcMvb()->getBool(0x634,5+i*2,2);//
        train[i]->TACU_FAULT28 = CrrcMvb::getCrrcMvb()->getBool(0x634,5+i*2,3);//
        train[i]->TACU_FAULT29 = CrrcMvb::getCrrcMvb()->getBool(0x634,5+i*2,4);//
        train[i]->TACU_FAULT30 = CrrcMvb::getCrrcMvb()->getBool(0x634,5+i*2,5);//
        train[i]->TACU_FAULT31 = CrrcMvb::getCrrcMvb()->getBool(0x634,5+i*2,6);//
        train[i]->TACU_FAULT32 = CrrcMvb::getCrrcMvb()->getBool(0x634,5+i*2,7);//
        train[i]->TACU_FAULT33 = CrrcMvb::getCrrcMvb()->getBool(0x635,4+i*2,0);//
        train[i]->TACU_FAULT34 = CrrcMvb::getCrrcMvb()->getBool(0x635,4+i*2,1);//
        train[i]->TACU_FAULT35 = CrrcMvb::getCrrcMvb()->getBool(0x635,4+i*2,2);//
        train[i]->TACU_FAULT36 = CrrcMvb::getCrrcMvb()->getBool(0x635,4+i*2,3);//
        train[i]->TACU_FAULT37 = CrrcMvb::getCrrcMvb()->getBool(0x635,4+i*2,4);//
        train[i]->TACU_FAULT38 = CrrcMvb::getCrrcMvb()->getBool(0x635,4+i*2,5);//
        train[i]->TACU_FAULT39 = CrrcMvb::getCrrcMvb()->getBool(0x635,4+i*2,6);//
        train[i]->TACU_FAULT40 = CrrcMvb::getCrrcMvb()->getBool(0x635,4+i*2,7);//
        train[i]->TACU_FAULT41 = CrrcMvb::getCrrcMvb()->getBool(0x635,5+i*2,0);//
        train[i]->TACU_FAULT42 = CrrcMvb::getCrrcMvb()->getBool(0x635,5+i*2,1);//
        train[i]->TACU_FAULT43 = CrrcMvb::getCrrcMvb()->getBool(0x635,5+i*2,2);//
        train[i]->TACU_FAULT44 = CrrcMvb::getCrrcMvb()->getBool(0x635,5+i*2,3);//
        train[i]->TACU_FAULT45 = CrrcMvb::getCrrcMvb()->getBool(0x635,5+i*2,4);//
        train[i]->TACU_FAULT46 = CrrcMvb::getCrrcMvb()->getBool(0x635,5+i*2,5);//
        train[i]->TACU_FAULT47 = CrrcMvb::getCrrcMvb()->getBool(0x635,5+i*2,6);//
        train[i]->TACU_FAULT48 = CrrcMvb::getCrrcMvb()->getBool(0x635,5+i*2,7);//
        train[i]->TACU_FAULT49 = CrrcMvb::getCrrcMvb()->getBool(0x636,4+i*2,0);//
        train[i]->TACU_FAULT50 = CrrcMvb::getCrrcMvb()->getBool(0x636,4+i*2,1);//
        train[i]->TACU_FAULT51 = CrrcMvb::getCrrcMvb()->getBool(0x636,4+i*2,2);//
        train[i]->TACU_FAULT52 = CrrcMvb::getCrrcMvb()->getBool(0x636,4+i*2,3);//
        train[i]->TACU_FAULT53 = CrrcMvb::getCrrcMvb()->getBool(0x636,4+i*2,4);//
        train[i]->TACU_FAULT54 = CrrcMvb::getCrrcMvb()->getBool(0x636,4+i*2,5);//
        train[i]->TACU_FAULT55 = CrrcMvb::getCrrcMvb()->getBool(0x636,4+i*2,6);//
        train[i]->TACU_FAULT56 = CrrcMvb::getCrrcMvb()->getBool(0x636,4+i*2,7);//
        train[i]->TACU_FAULT57 = CrrcMvb::getCrrcMvb()->getBool(0x636,5+i*2,0);//
        train[i]->TACU_FAULT58 = CrrcMvb::getCrrcMvb()->getBool(0x636,5+i*2,1);//
        train[i]->TACU_FAULT59 = CrrcMvb::getCrrcMvb()->getBool(0x636,5+i*2,2);//
        train[i]->TACU_FAULT60 = CrrcMvb::getCrrcMvb()->getBool(0x636,5+i*2,3);//
        train[i]->TACU_FAULT61 = CrrcMvb::getCrrcMvb()->getBool(0x636,5+i*2,4);//
        train[i]->TACU_FAULT62 = CrrcMvb::getCrrcMvb()->getBool(0x636,5+i*2,5);//
        train[i]->TACU_FAULT63 = CrrcMvb::getCrrcMvb()->getBool(0x636,5+i*2,6);//
        train[i]->TACU_FAULT64 = CrrcMvb::getCrrcMvb()->getBool(0x636,5+i*2,7);//
        train[i]->CMD_TC4_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,4+i*2,0);//它车1 它车4 整流器1隔离请求
        train[i]->CMD_TC4_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,4+i*2,1);//它车1 它车4 整流器2隔离请求
        train[i]->CMD_TC4_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,4+i*2,2);//它车1 它车4 整流器3隔离请求
        train[i]->CMD_TC4_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,4+i*2,3);//它车1 它车4 整流器4隔离请求
        train[i]->CMD_TC4_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,4+i*2,4);//它车1 它车4 轴1隔离请求
        train[i]->CMD_TC4_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,4+i*2,5);//它车1 它车4 轴2隔离请求
        train[i]->CMD_TC4_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,4+i*2,6);//它车1 它车4 轴3隔离请求
        train[i]->CMD_TC4_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,4+i*2,7);//它车1 它车4 轴4隔离请求
        train[i]->CMD_TC4_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,5+i*2,0);//它车1 它车4 辅变流1隔离请求
        train[i]->CMD_TC4_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,5+i*2,1);//它车1 它车4 辅变流2隔离请求
        train[i]->CMD_TC4_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,5+i*2,2);//它车1 它车4 无人警惕隔离请求
        train[i]->CMD_TC4_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,5+i*2,3);//它车1 它车4 电制动隔离请求
        train[i]->CMD_TC4_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,5+i*2,4);//它车1 它车4 空压机隔离请求
        train[i]->CMD_TC4_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,5+i*2,5);//它车1 它车4 受电弓隔离请求
        train[i]->CMD_TC4_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x637,5+i*2,6);//它车1 它车4 轮缘润滑隔离请求
        train[i]->CMD_TRACK_BLOCK = CrrcMvb::getCrrcMvb()->getBool(0x637,5+i*2,7);//它车1 切除牵引命令
        train[i]->CMD_TC4_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,4+i*2,0);//它车1 它车4 整流器1隔离取消请求
        train[i]->CMD_TC4_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,4+i*2,1);//它车1 它车4 整流器2隔离取消请求
        train[i]->CMD_TC4_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,4+i*2,2);//它车1 它车4 整流器3隔离取消请求
        train[i]->CMD_TC4_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,4+i*2,3);//它车1 它车4 整流器4隔离取消请求
        train[i]->CMD_TC4_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,4+i*2,4);//它车1 它车4 轴1隔离取消请求
        train[i]->CMD_TC4_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,4+i*2,5);//它车1 它车4 轴2隔离取消请求
        train[i]->CMD_TC4_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,4+i*2,6);//它车1 它车4 轴3隔离取消请求
        train[i]->CMD_TC4_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,4+i*2,7);//它车1 它车4 轴4隔离取消请求
        train[i]->CMD_TC4_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,5+i*2,0);//它车1 它车4 辅变流1隔离取消请求
        train[i]->CMD_TC4_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,5+i*2,1);//它车1 它车4 辅变流2隔离取消请求
        train[i]->CMD_TC4_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,5+i*2,2);//它车1 它车4 无人警惕隔离取消请求
        train[i]->CMD_TC4_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,5+i*2,3);//它车1 它车4 电制动隔离取消请求
        train[i]->CMD_TC4_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,5+i*2,4);//它车1 它车4 空压机隔离取消请求
        train[i]->CMD_TC4_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,5+i*2,5);//它车1 它车4 受电弓隔离取消请求
        train[i]->CMD_TC4_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x638,5+i*2,6);//它车1 它车4 轮缘润滑隔离取消请求
        train[i]->CMD_FIRE_ALARM_CONFIRM = CrrcMvb::getCrrcMvb()->getBool(0x638,5+i*2,7);//它车1 火灾报警确认

        train[i]->LOCO_NO = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x602,4+i*2);//它车1 编号
        train[i]->DATE_TIME1 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x603,4+i*2);//它车1 日期时间1
        train[i]->DATE_TIME2 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x604,4+i*2);//它车1 日期时间2
        train[i]->TOTAL_TE_ACTUAL = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x608,4+i*2);//它车1 总的牵引/制动力，单位KN 将数值加1000 乘10
        train[i]->LOAD_VALUE = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x613,4+i*2);//它车1 牵引吨位
        train[i]->Q4Q1_PRIM_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x614,4+i*2);//它车1 四象限1输入电压
        train[i]->Q4Q2_PRIM_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x615,4+i*2);//它车1 四象限2输入电压
        train[i]->Q4Q3_PRIM_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x616,4+i*2);//它车1 四象限3输入电压
        train[i]->Q4Q4_PRIM_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x617,4+i*2);//它车1 四象限4输入电压
        train[i]->Q4Q1_PRIM_C = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x618,4+i*2);//它车1 四象限1输入电流
        train[i]->Q4Q2_PRIM_C = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x619,4+i*2);//它车1 四象限2输入电流
        train[i]->Q4Q3_PRIM_C = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x61A,4+i*2);//它车1 四象限3输入电流
        train[i]->Q4Q4_PRIM_C = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x61B,4+i*2);//它车1 四象限4输入电流
        train[i]->Q4Q1_DC_LINK_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x61C,4+i*2);//它车1 四象限1直流母线电压
        train[i]->Q4Q2_DC_LINK_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x61D,4+i*2);//它车1 四象限2直流母线电压
        train[i]->Q4Q3_DC_LINK_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x61E,4+i*2);//它车1 四象限3直流母线电压
        train[i]->Q4Q4_DC_LINK_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x61F,4+i*2);//它车1 四象限4直流母线电压
        train[i]->CMD_MSCT_GRD = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x624,4+i*2);//它车1 司控器极位 + 100 发
        train[i]->ACTUAL_SPEED = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x63C,4+i*2);//它车1 机车速度
        train[i]->BCU_EBRAKE = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x63D,4+i*2);//它车1 BCU ED brake demand

        train[i]->CMD_CS_VALUE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x607,5+i*2);//它车1 定速值
        train[i]->NET_VOLT = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x612,4+i*2);//它车1 主变压器原边电压（除以128传送）
        train[i]->NET_CURRENT = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x612,5+i*2);//它车1 主变压器原边电流*0.5
        train[i]->MOT1_C = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x620,4+i*2);//它车1 牵引电机1电流*0.5
        train[i]->MOT2_C = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x620,5+i*2);//它车1 牵引电机2电流*0.5
        train[i]->MOT3_C = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x621,4+i*2);//它车1 牵引电机3电流*0.5
        train[i]->MOT4_C = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x621,5+i*2);//它车1 牵引电机4电流*0.5
        train[i]->TE_AXLE1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x622,4+i*2);//它车1 轴1实际牵引力/制动力，单位kN  将数值加100
        train[i]->TE_AXLE2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x622,5+i*2);//它车1 轴2实际牵引力/制动力，单位kN  将数值加100
        train[i]->TE_AXLE3 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x623,4+i*2);//它车1 轴3实际牵引力/制动力，单位kN  将数值加100
        train[i]->TE_AXLE4 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x623,5+i*2);//它车1 轴4实际牵引力/制动力，单位kN  将数值加100
        train[i]->TRANS_TEMP1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x625,4+i*2);//它车1 (主变压器温度1 + 50) * 0.5
        train[i]->TRANS_TEMP2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x625,5+i*2);//它车1 (主变压器温度2 + 50) * 0.5
        train[i]->MOT1_TEMP = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x626,4+i*2);//它车1 (牵引电机1温度 + 50) * 0.5
        train[i]->MOT2_TEMP = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x626,5+i*2);//它车1 (牵引电机2温度 + 50) * 0.5
        train[i]->MOT3_TEMP = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x627,4+i*2);//它车1 (牵引电机2温度 + 50) * 0.5
        train[i]->MOT4_TEMP = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x627,5+i*2);//它车1 (牵引电机2温度 + 50) * 0.5
        train[i]->WATER_PRES1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x628,4+i*2);//它车1 冷却液压力1 * 0.25
        train[i]->WATER_PRES2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x628,5+i*2);//它车1 冷却液压力2 * 0.25
        train[i]->WATER_TEMP1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x629,4+i*2);//它车1 冷却液温度1 + 50
        train[i]->WATER_TEMP2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x629,5+i*2);//它车1 冷却液温度2 + 50
        train[i]->ACU1_FREQ = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x62A,4+i*2);//它车1 辅助1频率
        train[i]->ACU2_FREQ = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x62A,5+i*2);//它车1 辅助2频率
        train[i]->TCMS_FLT_F1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x62B,5+i*2);//故障分时发送标志位1=1,2,3
        train[i]->TCMS_FLT_F2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x62C,5+i*2);//故障分时发送标志位2=1,2,3
        train[i]->TCMS_FLT_F3 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x62D,5+i*2);//故障分时发送标志位3=1,2,3
        train[i]->TCMS_FLT_F4 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x62E,5+i*2);//故障分时发送标志位4=1,2,3
        train[i]->TCMS_FLT_F5 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x62F,5+i*2);//故障分时发送标志位5=1,2,3
        train[i]->TCMS_FLT_F6 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x630,5+i*2);//故障分时发送标志位6=1,2,3
        train[i]->TCMS_FLT_F7 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x631,5+i*2);//故障分时发送标志位7=1,2,3
        train[i]->WATER_PRES3 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x63A,4+i*2);//它车1 冷却液压力3 * 0.25
        train[i]->WATER_PRES4 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x63A,5+i*2);//它车1 冷却液压力4 * 0.25
        train[i]->WATER_TEMP3 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x63B,4+i*2);//它车1 冷却液温度3 + 50
        train[i]->WATER_TEMP4 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x63B,5+i*2);//它车1 冷却液温度4 + 50
        train[i]->MPU_LIFE2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x63E,4+i*2);//它车1 MPU生命信号

        for(int j = 0;j<7;j++)
        {
            //对分时标志位做判断
            switch (CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(j),5+2*i))
            {
            case 1:
                CrrcMvb::getCrrcMvb()->setUnsignedChar(t_virtualportlist.at(j),4+2*i,CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(j),4+2*i));//对virtual port 分别copy数据
                break;
            case 2:
                CrrcMvb::getCrrcMvb()->setUnsignedChar(t_virtualportlist.at(j+7),4+2*i,CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(j),4+2*i));//对virtual port 分别copy数据
                break;
            case 3:
                CrrcMvb::getCrrcMvb()->setUnsignedChar(t_virtualportlist.at(j+14),4+2*i,CrrcMvb::getCrrcMvb()->getUnsignedChar(t_portlist.at(j),4+2*i));//对virtual port 分别copy数据
                break;
            default:
                // clear??
                break;
            }
        }

    }

    //MPU->GW

    {
        TrainLocal->CMD_KEY = CrrcMvb::getCrrcMvb()->getBool(0x700,6,0);//电钥匙
        TrainLocal->STATE_QS_GHV = CrrcMvb::getCrrcMvb()->getBool(0x700,6,1);//接地开关状态
        TrainLocal->STATE_MA_SU_PT = CrrcMvb::getCrrcMvb()->getBool(0x700,6,2);//受电弓压力开关状态
        TrainLocal->STATE_MA1_CP = CrrcMvb::getCrrcMvb()->getBool(0x700,6,3);//总风压力开关
        TrainLocal->STATE_H_HT = CrrcMvb::getCrrcMvb()->getBool(0x700,6,4);//高压隔离开关
        TrainLocal->CMD_EMGE = CrrcMvb::getCrrcMvb()->getBool(0x700,6,5);//电控紧急
        TrainLocal->TCN_DIR_BIT0 = CrrcMvb::getCrrcMvb()->getBool(0x700,6,6);//TCN方向BIT0
        TrainLocal->TCN_DIR_BIT1 = CrrcMvb::getCrrcMvb()->getBool(0x700,6,7);//TCN方向BIT1
        TrainLocal->CMD_T = CrrcMvb::getCrrcMvb()->getBool(0x700,7,0);//T满级位
        TrainLocal->CMD_T23 = CrrcMvb::getCrrcMvb()->getBool(0x700,7,1);//T2/3级位
        TrainLocal->CMD_T13 = CrrcMvb::getCrrcMvb()->getBool(0x700,7,2);//T1/3级位
        TrainLocal->CMD_B13 = CrrcMvb::getCrrcMvb()->getBool(0x700,7,3);//B1/3级位
        TrainLocal->CMD_B23 = CrrcMvb::getCrrcMvb()->getBool(0x700,7,4);//B2/3级位
        TrainLocal->CMD_B = CrrcMvb::getCrrcMvb()->getBool(0x700,7,5);//B满级位
        TrainLocal->GW_CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x700,7,6);//检查变量0
        TrainLocal->GW_CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x700,7,7);//检查变量1
        TrainLocal->CMD_PANTO_R = CrrcMvb::getCrrcMvb()->getBool(0x700,8,0);//升弓
        TrainLocal->CMD_PANTO_D = CrrcMvb::getCrrcMvb()->getBool(0x700,8,1);//降弓
        TrainLocal->CMD_QFM_K = CrrcMvb::getCrrcMvb()->getBool(0x700,8,2);//主断合
        TrainLocal->CMD_QFM_C = CrrcMvb::getCrrcMvb()->getBool(0x700,8,3);//主断保持
        TrainLocal->CMD_DIR_f = CrrcMvb::getCrrcMvb()->getBool(0x700,8,4);//向前
        TrainLocal->CMD_DIR_N = CrrcMvb::getCrrcMvb()->getBool(0x700,8,5);//方向零位
        TrainLocal->CMD_DIR_B = CrrcMvb::getCrrcMvb()->getBool(0x700,8,6);//向后
        TrainLocal->CMD_CONS = CrrcMvb::getCrrcMvb()->getBool(0x700,8,7);//定速
        TrainLocal->CMD_MSCT_N = CrrcMvb::getCrrcMvb()->getBool(0x700,9,0);//司控器零位
        TrainLocal->CMD_CPR_RUN = CrrcMvb::getCrrcMvb()->getBool(0x700,9,1);//压缩机运行
        TrainLocal->CMD_PUMP = CrrcMvb::getCrrcMvb()->getBool(0x700,9,2);//强泵
        TrainLocal->CMD_ANSC2 = CrrcMvb::getCrrcMvb()->getBool(0x700,9,3);//ANSC强断
        TrainLocal->CMD_ANSC1 = CrrcMvb::getCrrcMvb()->getBool(0x700,9,4);//ANSC预备恢复
        TrainLocal->CMD_MNSC = CrrcMvb::getCrrcMvb()->getBool(0x700,9,5);//手动过分相
        TrainLocal->P606CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x700,9,6);//检查变量0
        TrainLocal->P606CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x700,9,7);//检查变量1
        TrainLocal->CMD_BP_RESET = CrrcMvb::getCrrcMvb()->getBool(0x700,10,0);//复位按钮
        TrainLocal->CMD_CAB_CHANGE = CrrcMvb::getCrrcMvb()->getBool(0x700,10,1);//换端
        TrainLocal->CMD_MA1_FD = CrrcMvb::getCrrcMvb()->getBool(0x700,10,2);//小闸压力开关
        TrainLocal->CMD_FLL_TEST_START = CrrcMvb::getCrrcMvb()->getBool(0x700,10,3);//轮缘润滑测试开始
        TrainLocal->CMD_FLL_TEST_CANCEL = CrrcMvb::getCrrcMvb()->getBool(0x700,10,4);//
        TrainLocal->CMD_NSC_FAULT = CrrcMvb::getCrrcMvb()->getBool(0x700,10,5);//过分相故障
        TrainLocal->CMD_SAND_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,10,6);//撒砂请求
        TrainLocal->CMD_SAND_CUT = CrrcMvb::getCrrcMvb()->getBool(0x700,10,7);//撒砂切除
        TrainLocal->CMD_TC1_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,14,0);//它车1 整流器1隔离请求
        TrainLocal->CMD_TC1_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,14,1);//它车1 整流器2隔离请求
        TrainLocal->CMD_TC1_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,14,2);//它车1 整流器3隔离请求
        TrainLocal->CMD_TC1_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,14,3);//它车1 整流器4隔离请求
        TrainLocal->CMD_TC1_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,14,4);//它车1 轴1隔离请求
        TrainLocal->CMD_TC1_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,14,5);//它车1 轴2隔离请求
        TrainLocal->CMD_TC1_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,14,6);//它车1 轴3隔离请求
        TrainLocal->CMD_TC1_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,14,7);//它车1 轴4隔离请求
        TrainLocal->CMD_TC1_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,15,0);//它车1 辅变流1隔离请求
        TrainLocal->CMD_TC1_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,15,1);//它车1 辅变流2隔离请求
        TrainLocal->CMD_TC1_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,15,2);//它车1 无人警惕隔离请求
        TrainLocal->CMD_TC1_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,15,3);//它车1 电制动隔离请求
        TrainLocal->CMD_TC1_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,15,4);//它车1 空压机隔离请求
        TrainLocal->CMD_TC1_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,15,5);//它车1 受电弓隔离请求
        TrainLocal->CMD_TC1_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,15,6);//它车1 轮缘润滑隔离请求
        TrainLocal->CMD_DDU_RESET = CrrcMvb::getCrrcMvb()->getBool(0x700,15,7);//DDU故障复位命令
        TrainLocal->CMD_TC1_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,16,0);//它车1 整流器1隔离取消请求
        TrainLocal->CMD_TC1_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,16,1);//它车1 整流器2隔离取消请求
        TrainLocal->CMD_TC1_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,16,2);//它车1 整流器3隔离取消请求
        TrainLocal->CMD_TC1_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,16,3);//它车1 整流器4隔离取消请求
        TrainLocal->CMD_TC1_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,16,4);//它车1 轴1隔离取消请求
        TrainLocal->CMD_TC1_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,16,5);//它车1 轴2隔离取消请求
        TrainLocal->CMD_TC1_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,16,6);//它车1 轴3隔离取消请求
        TrainLocal->CMD_TC1_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,16,7);//它车1 轴4隔离取消请求
        TrainLocal->CMD_TC1_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,17,0);//它车1 辅变流1隔离取消请求
        TrainLocal->CMD_TC1_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,17,1);//它车1 辅变流2隔离取消请求
        TrainLocal->CMD_TC1_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,17,2);//它车1 无人警惕隔离取消请求
        TrainLocal->CMD_TC1_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,17,3);//它车1 电制动隔离取消请求
        TrainLocal->CMD_TC1_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,17,4);//它车1 空压机隔离取消请求
        TrainLocal->CMD_TC1_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,17,5);//它车1 受电弓隔离取消请求
        TrainLocal->CMD_TC1_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,17,6);//它车1 轮缘润滑隔离取消请求
        TrainLocal->ELEC_AIR_CUT = CrrcMvb::getCrrcMvb()->getBool(0x700,17,7);//空电切除
        TrainLocal->CMD_TC2_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,18,0);//它车2 整流器1隔离请求
        TrainLocal->CMD_TC2_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,18,1);//它车2 整流器2隔离请求
        TrainLocal->CMD_TC2_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,18,2);//它车2 整流器3隔离请求
        TrainLocal->CMD_TC2_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,18,3);//它车2 整流器4隔离请求
        TrainLocal->CMD_TC2_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,18,4);//它车2 轴1隔离请求
        TrainLocal->CMD_TC2_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,18,5);//它车2 轴2隔离请求
        TrainLocal->CMD_TC2_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,18,6);//它车2 轴3隔离请求
        TrainLocal->CMD_TC2_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,18,7);//它车2 轴4隔离请求
        TrainLocal->CMD_TC2_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,19,0);//它车2 辅变流1隔离请求
        TrainLocal->CMD_TC2_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,19,1);//它车2 辅变流2隔离请求
        TrainLocal->CMD_TC2_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,19,2);//它车2 无人警惕隔离请求
        TrainLocal->CMD_TC2_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,19,3);//它车2 电制动隔离请求
        TrainLocal->CMD_TC2_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,19,4);//它车2 空压机隔离请求
        TrainLocal->CMD_TC2_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,19,5);//它车2 受电弓隔离请求
        TrainLocal->CMD_TC2_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,19,6);//它车2 轮缘润滑隔离请求
        TrainLocal->CMD_T_CHAR_H = CrrcMvb::getCrrcMvb()->getBool(0x700,19,7);//牵引特性设定：恒转矩
        TrainLocal->CMD_TC2_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,20,0);//它车2 整流器1隔离取消请求
        TrainLocal->CMD_TC2_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,20,1);//它车2 整流器2隔离取消请求
        TrainLocal->CMD_TC2_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,20,2);//它车2 整流器3隔离取消请求
        TrainLocal->CMD_TC2_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,20,3);//它车2 整流器4隔离取消请求
        TrainLocal->CMD_TC2_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,20,4);//它车2 轴1隔离取消请求
        TrainLocal->CMD_TC2_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,20,5);//它车2 轴2隔离取消请求
        TrainLocal->CMD_TC2_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,20,6);//它车2 轴3隔离取消请求
        TrainLocal->CMD_TC2_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,20,7);//它车2 轴4隔离取消请求
        TrainLocal->CMD_TC2_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,21,0);//它车2 辅变流1隔离取消请求
        TrainLocal->CMD_TC2_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,21,1);//它车2 辅变流2隔离取消请求
        TrainLocal->CMD_TC2_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,21,2);//它车2 无人警惕隔离取消请求
        TrainLocal->CMD_TC2_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,21,3);//它车2 电制动隔离取消请求
        TrainLocal->CMD_TC2_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,21,4);//它车2 空压机隔离取消请求
        TrainLocal->CMD_TC2_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,21,5);//它车2 受电弓隔离取消请求
        TrainLocal->CMD_TC2_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,21,6);//它车2 轮缘润滑隔离取消请求
        TrainLocal->CMD_SUMMER_MODE = CrrcMvb::getCrrcMvb()->getBool(0x700,21,7);//夏季模式
        TrainLocal->CMD_TC3_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,22,0);//它车3 整流器1隔离请求
        TrainLocal->CMD_TC3_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,22,1);//它车3 整流器2隔离请求
        TrainLocal->CMD_TC3_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,22,2);//它车3 整流器3隔离请求
        TrainLocal->CMD_TC3_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,22,3);//它车3 整流器4隔离请求
        TrainLocal->CMD_TC3_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,22,4);//它车3 轴1隔离请求
        TrainLocal->CMD_TC3_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,22,5);//它车3 轴2隔离请求
        TrainLocal->CMD_TC3_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,22,6);//它车3 轴3隔离请求
        TrainLocal->CMD_TC3_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,22,7);//它车3 轴4隔离请求
        TrainLocal->CMD_TC3_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,23,0);//它车3 辅变流1隔离请求
        TrainLocal->CMD_TC3_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,23,1);//它车3 辅变流2隔离请求
        TrainLocal->CMD_TC3_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,23,2);//它车3 无人警惕隔离请求
        TrainLocal->CMD_TC3_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,23,3);//它车3 电制动隔离请求
        TrainLocal->CMD_TC3_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,23,4);//它车3 空压机隔离请求
        TrainLocal->CMD_TC3_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,23,5);//它车3 受电弓隔离请求
        TrainLocal->CMD_TC3_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,23,6);//它车3 轮缘润滑隔离请求
        TrainLocal->CMD_T_CHAR_H = CrrcMvb::getCrrcMvb()->getBool(0x700,23,7);//牵引特性设定：准恒速
        TrainLocal->CMD_TC3_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,24,0);//它车3 整流器1隔离取消请求
        TrainLocal->CMD_TC3_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,24,1);//它车3 整流器2隔离取消请求
        TrainLocal->CMD_TC3_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,24,2);//它车3 整流器3隔离取消请求
        TrainLocal->CMD_TC3_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,24,3);//它车3 整流器4隔离取消请求
        TrainLocal->CMD_TC3_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,24,4);//它车3 轴1隔离取消请求
        TrainLocal->CMD_TC3_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,24,5);//它车3 轴2隔离取消请求
        TrainLocal->CMD_TC3_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,24,6);//它车3 轴3隔离取消请求
        TrainLocal->CMD_TC3_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,24,7);//它车3 轴4隔离取消请求
        TrainLocal->CMD_TC3_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,25,0);//它车3 辅变流1隔离取消请求
        TrainLocal->CMD_TC3_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,25,1);//它车3 辅变流2隔离取消请求
        TrainLocal->CMD_TC3_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,25,2);//它车3 无人警惕隔离取消请求
        TrainLocal->CMD_TC3_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,25,3);//它车3 电制动隔离取消请求
        TrainLocal->CMD_TC3_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,25,4);//它车3 空压机隔离取消请求
        TrainLocal->CMD_TC3_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,25,5);//它车3 受电弓隔离取消请求
        TrainLocal->CMD_TC3_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x700,25,6);//它车3 轮缘润滑隔离取消请求
        TrainLocal->CMD_WINTER_MODE = CrrcMvb::getCrrcMvb()->getBool(0x700,25,7);//冬季模式
        TrainLocal->STATE_CAB_ACT = CrrcMvb::getCrrcMvb()->getBool(0x700,26,0);//电钥匙激活
        TrainLocal->STATE_QFM_ON = CrrcMvb::getCrrcMvb()->getBool(0x700,26,1);//主断合
        TrainLocal->STATE_QFM_K = CrrcMvb::getCrrcMvb()->getBool(0x700,26,2);//主断预备
        TrainLocal->STATE_QFM_OFF = CrrcMvb::getCrrcMvb()->getBool(0x700,26,3);//主断断开
        TrainLocal->STATE_QFM_ISO = CrrcMvb::getCrrcMvb()->getBool(0x700,26,4);//主断隔离
        TrainLocal->STATE_PANTO_DN = CrrcMvb::getCrrcMvb()->getBool(0x700,26,5);//受电弓降下
        TrainLocal->STATE_PANTO_RG = CrrcMvb::getCrrcMvb()->getBool(0x700,26,6);//受电弓升弓
        TrainLocal->STATE_PANTO_RD = CrrcMvb::getCrrcMvb()->getBool(0x700,26,7);//受电弓升起
        TrainLocal->STATE_PANTO_ISO = CrrcMvb::getCrrcMvb()->getBool(0x700,27,0);//受电弓隔离
        TrainLocal->STATE_EMG_BRK_ON = CrrcMvb::getCrrcMvb()->getBool(0x700,27,1);//紧急制动施加
        TrainLocal->STATE_EMG_BRK_I = CrrcMvb::getCrrcMvb()->getBool(0x700,27,2);//紧急制动隔离
        TrainLocal->STATE_PARK_BRK_ON = CrrcMvb::getCrrcMvb()->getBool(0x700,27,3);//停放制动施加
        TrainLocal->STATE_PARK_BRK_I = CrrcMvb::getCrrcMvb()->getBool(0x700,27,4);//停放制动隔离
        TrainLocal->STATE_AIR_BRK1_ON = CrrcMvb::getCrrcMvb()->getBool(0x700,27,5);//空气制动1施加
        TrainLocal->STATE_AIR_BRK1_I = CrrcMvb::getCrrcMvb()->getBool(0x700,27,6);//空气制动1隔离
        TrainLocal->STATE_AIR_BRK2_ON = CrrcMvb::getCrrcMvb()->getBool(0x700,27,7);//空气制动2施加
        TrainLocal->STATE_AIR_BRK2_I = CrrcMvb::getCrrcMvb()->getBool(0x700,28,0);//空气制动2隔离
        TrainLocal->STATE_C_BAU1 = CrrcMvb::getCrrcMvb()->getBool(0x700,28,1);//辅助1接触器状态
        TrainLocal->STATE_C_BAU2 = CrrcMvb::getCrrcMvb()->getBool(0x700,28,2);//辅助2接触器状态
        TrainLocal->STATE_C_SEC = CrrcMvb::getCrrcMvb()->getBool(0x700,28,3);//辅变流降级接触器状态
        TrainLocal->QFM_OFF_PROTECT = CrrcMvb::getCrrcMvb()->getBool(0x700,28,4);//断主断保护
        TrainLocal->STATE_RB_IS_FS = CrrcMvb::getCrrcMvb()->getBool(0x700,28,5);//停放制动隔离阀状态
        TrainLocal->STATE_RB_EMG = CrrcMvb::getCrrcMvb()->getBool(0x700,28,6);//紧急制动隔离阀状态
        TrainLocal->STATE_RB_IS_CF1 = CrrcMvb::getCrrcMvb()->getBool(0x700,28,7);//制动缸1隔离阀状态
        TrainLocal->STATE_RB_IS_CF2 = CrrcMvb::getCrrcMvb()->getBool(0x700,29,0);//制动缸2隔离阀状态
        TrainLocal->STATE_C1_CPR = CrrcMvb::getCrrcMvb()->getBool(0x700,29,1);//压缩机接触器1状态
        TrainLocal->STATE_C2_CPR = CrrcMvb::getCrrcMvb()->getBool(0x700,29,2);//压缩机接触器2状态
        TrainLocal->STATE_C3_CPR = CrrcMvb::getCrrcMvb()->getBool(0x700,29,3);//压缩机接触器3状态
        TrainLocal->STATE_Q_TH_VT_BM1 = CrrcMvb::getCrrcMvb()->getBool(0x700,29,4);//冷却塔风机1热继状态
        TrainLocal->STATE_Q_TH_VT_BM2 = CrrcMvb::getCrrcMvb()->getBool(0x700,29,5);//冷却塔风机2热继状态
        TrainLocal->STATE_C_VT_BM1 = CrrcMvb::getCrrcMvb()->getBool(0x700,29,6);//冷却塔风机1接触器状态
        TrainLocal->STATE_C_VT_BM2 = CrrcMvb::getCrrcMvb()->getBool(0x700,29,7);//冷却塔风机2接触器状态
        TrainLocal->STATE_C_VT_MT1 = CrrcMvb::getCrrcMvb()->getBool(0x700,30,0);//牵引风机1接触器状态
        TrainLocal->STATE_C_VT_MT2 = CrrcMvb::getCrrcMvb()->getBool(0x700,30,1);//牵引风机2接触器状态
        TrainLocal->STATE_C_VT_SM1 = CrrcMvb::getCrrcMvb()->getBool(0x700,30,2);//机械间风机1接触器状态
        TrainLocal->STATE_C_VT_SM2 = CrrcMvb::getCrrcMvb()->getBool(0x700,30,3);//机械间风机2接触器状态
        TrainLocal->STATE_DJ_PE1 = CrrcMvb::getCrrcMvb()->getBool(0x700,30,4);//水泵1断路器状态
        TrainLocal->STATE_DJ_PE2 = CrrcMvb::getCrrcMvb()->getBool(0x700,30,5);//水泵2断路器状态
        TrainLocal->STATE_DJ_PE3 = CrrcMvb::getCrrcMvb()->getBool(0x700,30,6);//水泵3断路器状态
        TrainLocal->STATE_DJ_PE4 = CrrcMvb::getCrrcMvb()->getBool(0x700,30,7);//水泵4断路器状态
        TrainLocal->STATE_DJ_PH1 = CrrcMvb::getCrrcMvb()->getBool(0x700,31,0);//油泵1断路器状态
        TrainLocal->STATE_DJ_PH2 = CrrcMvb::getCrrcMvb()->getBool(0x700,31,1);//油泵2断路器状态
        TrainLocal->STATE_DJ_VT_SM1 = CrrcMvb::getCrrcMvb()->getBool(0x700,31,2);//机械间风机1断路器状态
        TrainLocal->STATE_DJ_VT_SM2 = CrrcMvb::getCrrcMvb()->getBool(0x700,31,3);//机械间风机2断路器状态
        TrainLocal->STATE_Q_TH_CPR = CrrcMvb::getCrrcMvb()->getBool(0x700,31,4);//压缩机热保护继电器状态
        TrainLocal->STATE_Q_REC = CrrcMvb::getCrrcMvb()->getBool(0x700,31,5);//压缩机低温保护继电器状态
        TrainLocal->STATE_Q_TH_VT_MT1 = CrrcMvb::getCrrcMvb()->getBool(0x700,31,6);//牵引风机1热继状态
        TrainLocal->STATE_Q_TH_VT_MT2 = CrrcMvb::getCrrcMvb()->getBool(0x700,31,7);//牵引风机2热继状态
        TrainLocal->TCMS_FAULT1 = CrrcMvb::getCrrcMvb()->getBool(0x702,18,0);//MPU1故障/RIOM1_DI1通信故障/辅助压力低
        TrainLocal->TCMS_FAULT2 = CrrcMvb::getCrrcMvb()->getBool(0x702,18,1);//MPU2故障/RIOM1_DI2通信故障/空调故障
        TrainLocal->TCMS_FAULT3 = CrrcMvb::getCrrcMvb()->getBool(0x702,18,2);//UIC网关1通信故障/RIOM1_DI3通信故障/一级欠压
        TrainLocal->TCMS_FAULT4 = CrrcMvb::getCrrcMvb()->getBool(0x702,18,3);//UIC网关2通信故障/RIOM1_DO1通信故障/干燥器故障
        TrainLocal->TCMS_FAULT5 = CrrcMvb::getCrrcMvb()->getBool(0x702,18,4);//BCU通信故障/RIOM1_AX1通信故障/受电弓隔离阀隔离位
        TrainLocal->TCMS_FAULT6 = CrrcMvb::getCrrcMvb()->getBool(0x702,18,5);//DDU通信故障/RIOM2网关通信故障/四象限2未正常启动
        TrainLocal->TCMS_FAULT7 = CrrcMvb::getCrrcMvb()->getBool(0x702,18,6);//RIOM1网关1通信故障/RIOM2_DI1通信故障/四象限3未正常启动
        TrainLocal->TCMS_FAULT8 = CrrcMvb::getCrrcMvb()->getBool(0x702,18,7);//RIOM1网关2通信故障/RIOM2_DI2通信故障/火灾报警
        TrainLocal->TCMS_FAULT9 = CrrcMvb::getCrrcMvb()->getBool(0x702,20,0);//RIOM2_DI3通信故障/油流1故障/受电弓未在60秒内升起
        TrainLocal->TCMS_FAULT10 = CrrcMvb::getCrrcMvb()->getBool(0x702,20,1);//RIOM2_DI4通信故障/油流2故障/读取车号失败
        TrainLocal->TCMS_FAULT11 = CrrcMvb::getCrrcMvb()->getBool(0x702,20,2);//RIOM2_DI5通信故障/油流1和油流2故障/控制回路接地
        TrainLocal->TCMS_FAULT12 = CrrcMvb::getCrrcMvb()->getBool(0x702,20,3);//RIOM2_DI6通信故障/紧急制动隔离/水泵3过载保护
        TrainLocal->TCMS_FAULT13 = CrrcMvb::getCrrcMvb()->getBool(0x702,20,4);//RIOM2_DO1通信故障/停放制动隔离/水泵4过载保护
        TrainLocal->TCMS_FAULT14 = CrrcMvb::getCrrcMvb()->getBool(0x702,20,5);//RIOM2_DO2通信故障/受电弓压力开关异常/油泵1过载保护
        TrainLocal->TCMS_FAULT15 = CrrcMvb::getCrrcMvb()->getBool(0x702,20,6);//RIOM2_DO3通信故障/二级欠压/油泵2过载保护
        TrainLocal->TCMS_FAULT16 = CrrcMvb::getCrrcMvb()->getBool(0x702,20,7);//司控器故障/主变压器原边过流/压缩机过载保护
        TrainLocal->TCMS_FAULT17 = CrrcMvb::getCrrcMvb()->getBool(0x702,22,0);//主变压器温度保护/无法识别本车或重联车通信信息/牵引风机1过载保护
        TrainLocal->TCMS_FAULT18 = CrrcMvb::getCrrcMvb()->getBool(0x702,22,1);//主变压器压力保护/自动换端失败/牵引风机2过载保护
        TrainLocal->TCMS_FAULT19 = CrrcMvb::getCrrcMvb()->getBool(0x702,22,2);//BCU故障DI信号/压缩机接触器1卡分/冷却塔风机1过载保护
        TrainLocal->TCMS_FAULT20 = CrrcMvb::getCrrcMvb()->getBool(0x702,22,3);//紧急制动：车长阀/压缩机接触器2卡分/冷却塔风机2过载保护
        TrainLocal->TCMS_FAULT21 = CrrcMvb::getCrrcMvb()->getBool(0x702,22,4);//紧急制动：电控紧急按钮/压缩机接触器3卡分/机械间风机1过载保护
        TrainLocal->TCMS_FAULT22 = CrrcMvb::getCrrcMvb()->getBool(0x702,22,5);//紧急制动：LKJ/压缩机接触器1卡合/机械间风机2过载保护
        TrainLocal->TCMS_FAULT23 = CrrcMvb::getCrrcMvb()->getBool(0x702,22,6);//无人警惕惩罚制动/压缩机接触器2卡合/水泵1过载保护
        TrainLocal->TCMS_FAULT24 = CrrcMvb::getCrrcMvb()->getBool(0x702,22,7);//重联车WTB网关或WTB线缆故障/压缩机接触器3卡合/水泵2过载保护
        TrainLocal->TCMS_FAULT25 = CrrcMvb::getCrrcMvb()->getBool(0x702,24,0);//紧急制动：列车管紧急放风阀/整流器3手动隔离/主断卡合故障
        TrainLocal->TCMS_FAULT26 = CrrcMvb::getCrrcMvb()->getBool(0x702,24,1);//紧急制动：BCU/整流器4手动隔离/主断卡分故障
        TrainLocal->TCMS_FAULT27 = CrrcMvb::getCrrcMvb()->getBool(0x702,24,2);//整流器1隔离/逆变器1隔离/网压异常降功率
        TrainLocal->TCMS_FAULT28 = CrrcMvb::getCrrcMvb()->getBool(0x702,24,3);//整流器2隔离/逆变器2隔离/预留
        TrainLocal->TCMS_FAULT29 = CrrcMvb::getCrrcMvb()->getBool(0x702,24,4);//整流器3隔离/逆变器3隔离/预留
        TrainLocal->TCMS_FAULT30 = CrrcMvb::getCrrcMvb()->getBool(0x702,24,5);//整流器4隔离/逆变器4隔离/预留
        TrainLocal->TCMS_FAULT31 = CrrcMvb::getCrrcMvb()->getBool(0x702,24,6);//整流器1手动隔离/逆变器1手动隔离/预留
        TrainLocal->TCMS_FAULT32 = CrrcMvb::getCrrcMvb()->getBool(0x702,24,7);//整流器2手动隔离/逆变器2手动隔离/预留
        TrainLocal->TCMS_FAULT33 = CrrcMvb::getCrrcMvb()->getBool(0x702,26,0);//逆变器3手动隔离/ACU1反馈频率与MPU请求频率不一致/预留
        TrainLocal->TCMS_FAULT34 = CrrcMvb::getCrrcMvb()->getBool(0x702,26,1);//逆变器4手动隔离/空压机手动隔离/预留
        TrainLocal->TCMS_FAULT35 = CrrcMvb::getCrrcMvb()->getBool(0x702,26,2);//辅变流1隔离/警惕装置隔离/预留
        TrainLocal->TCMS_FAULT36 = CrrcMvb::getCrrcMvb()->getBool(0x702,26,3);//辅变流2隔离/TCU1网关通信故障/预留
        TrainLocal->TCMS_FAULT37 = CrrcMvb::getCrrcMvb()->getBool(0x702,26,4);//辅变流1手动隔离/TCU2网关通信故障/预留
        TrainLocal->TCMS_FAULT38 = CrrcMvb::getCrrcMvb()->getBool(0x702,26,5);//辅变流2手动隔离/TCU3网关通信故障/预留
        TrainLocal->TCMS_FAULT39 = CrrcMvb::getCrrcMvb()->getBool(0x702,26,6);//动力制动隔离/TCU4网关通信故障/预留
        TrainLocal->TCMS_FAULT40 = CrrcMvb::getCrrcMvb()->getBool(0x702,26,7);//动力制动手动隔离/整流器1故障/预留
        TrainLocal->TCMS_FAULT41 = CrrcMvb::getCrrcMvb()->getBool(0x702,28,0);//整流器2故障/ACU1通信故障/预留
        TrainLocal->TCMS_FAULT42 = CrrcMvb::getCrrcMvb()->getBool(0x702,28,1);//整流器3故障/ACU2通信故障/预留
        TrainLocal->TCMS_FAULT43 = CrrcMvb::getCrrcMvb()->getBool(0x702,28,2);//整流器4故障/蓄电池电压过高故障/预留
        TrainLocal->TCMS_FAULT44 = CrrcMvb::getCrrcMvb()->getBool(0x702,28,3);//逆变器1故障/过分相装置故障/预留
        TrainLocal->TCMS_FAULT45 = CrrcMvb::getCrrcMvb()->getBool(0x702,28,4);//逆变器2故障/预留/预留
        TrainLocal->TCMS_FAULT46 = CrrcMvb::getCrrcMvb()->getBool(0x702,28,5);//逆变器3故障/24V模块故障/预留
        TrainLocal->TCMS_FAULT47 = CrrcMvb::getCrrcMvb()->getBool(0x702,28,6);//逆变器4故障/ACU2反馈频率与MPU请求频率不一致/预留
        TrainLocal->TCMS_FAULT48 = CrrcMvb::getCrrcMvb()->getBool(0x702,28,7);//网关3通信故障/制动缸1隔离/预留
        TrainLocal->TCMS_FAULT49 = CrrcMvb::getCrrcMvb()->getBool(0x702,30,0);//制动缸2隔离/机车停放制动不一致/1轴电机速度传感器A路信号异常
        TrainLocal->TCMS_FAULT50 = CrrcMvb::getCrrcMvb()->getBool(0x702,30,1);//压缩机低温保护/运行中停放制动施加/1轴电机速度传感器B路信号异常
        TrainLocal->TCMS_FAULT51 = CrrcMvb::getCrrcMvb()->getBool(0x702,30,2);//轮缘润滑隔离/转向架1/2制动缸压力异常/2轴电机速度传感器A路信号异常
        TrainLocal->TCMS_FAULT52 = CrrcMvb::getCrrcMvb()->getBool(0x702,30,3);//受电弓隔离/主变压器冷却回路异常/2轴电机速度传感器B路信号异常
        TrainLocal->TCMS_FAULT53 = CrrcMvb::getCrrcMvb()->getBool(0x702,30,4);//WTB线路A故障/牵引变流器冷却回路异常/3轴电机速度传感器A路信号异常
        TrainLocal->TCMS_FAULT54 = CrrcMvb::getCrrcMvb()->getBool(0x702,30,5);//WTB线路B故障/牵引电机冷却回路异常/3轴电机速度传感器B路信号异常
        TrainLocal->TCMS_FAULT55 = CrrcMvb::getCrrcMvb()->getBool(0x702,30,6);//MVB线路A故障/操作端冲突/4轴电机速度传感器A路信号异常
        TrainLocal->TCMS_FAULT56 = CrrcMvb::getCrrcMvb()->getBool(0x702,30,7);//MVB线路B故障/总风压力低/4轴电机速度传感器B路信号异常
        TrainLocal->NSC_DISTANCE1 = CrrcMvb::getCrrcMvb()->getBool(0x703,0,0);//常规线路过分相：170m模式
        TrainLocal->NSC_DISTANCE2 = CrrcMvb::getCrrcMvb()->getBool(0x703,0,1);//货运专线过分相：265m模式
        TrainLocal->Bail_ACT = CrrcMvb::getCrrcMvb()->getBool(0x703,1,0);//BCU-MPU Bit 6: Bail Activates
        TrainLocal->Bail_NULL = CrrcMvb::getCrrcMvb()->getBool(0x703,1,1);//BCU-MPU Bit 7: Bail has been nullified by CCB
        TrainLocal->FREIGHT_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(0x703,1,2);//货车/投入
        TrainLocal->PSG_CUT_IN = CrrcMvb::getCrrcMvb()->getBool(0x703,1,3);//客车/投入
        TrainLocal->ABH_MIN  = CrrcMvb::getCrrcMvb()->getBool(0x703,1,4);//大闸Minimum
        TrainLocal->ABH_SERV_Z = CrrcMvb::getCrrcMvb()->getBool(0x703,1,5);//大闸Service_Zone
        TrainLocal->ABH_FULL_SERV = CrrcMvb::getCrrcMvb()->getBool(0x703,1,6);//大闸Full_Service
        TrainLocal->STATE_T_CHAR = CrrcMvb::getCrrcMvb()->getBool(0x703,1,7);//牵引特性反馈0：恒转矩1：准恒速
        TrainLocal->TACU_FAULT1 = CrrcMvb::getCrrcMvb()->getBool(0x703,2,0);//
        TrainLocal->TACU_FAULT2 = CrrcMvb::getCrrcMvb()->getBool(0x703,2,1);//
        TrainLocal->TACU_FAULT3 = CrrcMvb::getCrrcMvb()->getBool(0x703,2,2);//
        TrainLocal->TACU_FAULT4 = CrrcMvb::getCrrcMvb()->getBool(0x703,2,3);//
        TrainLocal->TACU_FAULT5 = CrrcMvb::getCrrcMvb()->getBool(0x703,2,4);//
        TrainLocal->TACU_FAULT6 = CrrcMvb::getCrrcMvb()->getBool(0x703,2,5);//
        TrainLocal->TACU_FAULT7 = CrrcMvb::getCrrcMvb()->getBool(0x703,2,6);//
        TrainLocal->TACU_FAULT8 = CrrcMvb::getCrrcMvb()->getBool(0x703,2,7);//
        TrainLocal->TACU_FAULT9 = CrrcMvb::getCrrcMvb()->getBool(0x703,3,0);//
        TrainLocal->TACU_FAULT10 = CrrcMvb::getCrrcMvb()->getBool(0x703,3,1);//
        TrainLocal->TACU_FAULT11 = CrrcMvb::getCrrcMvb()->getBool(0x703,3,2);//
        TrainLocal->TACU_FAULT12 = CrrcMvb::getCrrcMvb()->getBool(0x703,3,3);//
        TrainLocal->TACU_FAULT13 = CrrcMvb::getCrrcMvb()->getBool(0x703,3,4);//
        TrainLocal->TACU_FAULT14 = CrrcMvb::getCrrcMvb()->getBool(0x703,3,5);//分时标志：bit0
        TrainLocal->TACU_FAULT15 = CrrcMvb::getCrrcMvb()->getBool(0x703,3,6);//分时标志：bit1
        TrainLocal->TACU_FAULT16 = CrrcMvb::getCrrcMvb()->getBool(0x703,3,7);//分时标志：bit2
        TrainLocal->TACU_FAULT17 = CrrcMvb::getCrrcMvb()->getBool(0x703,4,0);//
        TrainLocal->TACU_FAULT18 = CrrcMvb::getCrrcMvb()->getBool(0x703,4,1);//
        TrainLocal->TACU_FAULT19 = CrrcMvb::getCrrcMvb()->getBool(0x703,4,2);//
        TrainLocal->TACU_FAULT20 = CrrcMvb::getCrrcMvb()->getBool(0x703,4,3);//
        TrainLocal->TACU_FAULT21 = CrrcMvb::getCrrcMvb()->getBool(0x703,4,4);//
        TrainLocal->TACU_FAULT22 = CrrcMvb::getCrrcMvb()->getBool(0x703,4,5);//
        TrainLocal->TACU_FAULT23 = CrrcMvb::getCrrcMvb()->getBool(0x703,4,6);//
        TrainLocal->TACU_FAULT24 = CrrcMvb::getCrrcMvb()->getBool(0x703,4,7);//
        TrainLocal->TACU_FAULT25 = CrrcMvb::getCrrcMvb()->getBool(0x703,5,0);//
        TrainLocal->TACU_FAULT26 = CrrcMvb::getCrrcMvb()->getBool(0x703,5,1);//
        TrainLocal->TACU_FAULT27 = CrrcMvb::getCrrcMvb()->getBool(0x703,5,2);//
        TrainLocal->TACU_FAULT28 = CrrcMvb::getCrrcMvb()->getBool(0x703,5,3);//
        TrainLocal->TACU_FAULT29 = CrrcMvb::getCrrcMvb()->getBool(0x703,5,4);//
        TrainLocal->TACU_FAULT30 = CrrcMvb::getCrrcMvb()->getBool(0x703,5,5);//分时标志：bit0
        TrainLocal->TACU_FAULT31 = CrrcMvb::getCrrcMvb()->getBool(0x703,5,6);//分时标志：bit1
        TrainLocal->TACU_FAULT32 = CrrcMvb::getCrrcMvb()->getBool(0x703,5,7);//分时标志：bit2
        TrainLocal->TACU_FAULT33 = CrrcMvb::getCrrcMvb()->getBool(0x703,6,0);//
        TrainLocal->TACU_FAULT34 = CrrcMvb::getCrrcMvb()->getBool(0x703,6,1);//
        TrainLocal->TACU_FAULT35 = CrrcMvb::getCrrcMvb()->getBool(0x703,6,2);//
        TrainLocal->TACU_FAULT36 = CrrcMvb::getCrrcMvb()->getBool(0x703,6,3);//
        TrainLocal->TACU_FAULT37 = CrrcMvb::getCrrcMvb()->getBool(0x703,6,4);//
        TrainLocal->TACU_FAULT38 = CrrcMvb::getCrrcMvb()->getBool(0x703,6,5);//
        TrainLocal->TACU_FAULT39 = CrrcMvb::getCrrcMvb()->getBool(0x703,6,6);//
        TrainLocal->TACU_FAULT40 = CrrcMvb::getCrrcMvb()->getBool(0x703,6,7);//
        TrainLocal->TACU_FAULT41 = CrrcMvb::getCrrcMvb()->getBool(0x703,7,0);//
        TrainLocal->TACU_FAULT42 = CrrcMvb::getCrrcMvb()->getBool(0x703,7,1);//
        TrainLocal->TACU_FAULT43 = CrrcMvb::getCrrcMvb()->getBool(0x703,7,2);//
        TrainLocal->TACU_FAULT44 = CrrcMvb::getCrrcMvb()->getBool(0x703,7,3);//
        TrainLocal->TACU_FAULT45 = CrrcMvb::getCrrcMvb()->getBool(0x703,7,4);//
        TrainLocal->TACU_FAULT46 = CrrcMvb::getCrrcMvb()->getBool(0x703,7,5);//分时标志：bit0
        TrainLocal->TACU_FAULT47 = CrrcMvb::getCrrcMvb()->getBool(0x703,7,6);//分时标志：bit1
        TrainLocal->TACU_FAULT48 = CrrcMvb::getCrrcMvb()->getBool(0x703,7,7);//分时标志：bit2
        TrainLocal->TACU_FAULT49 = CrrcMvb::getCrrcMvb()->getBool(0x703,8,0);//
        TrainLocal->TACU_FAULT50 = CrrcMvb::getCrrcMvb()->getBool(0x703,8,1);//
        TrainLocal->TACU_FAULT51 = CrrcMvb::getCrrcMvb()->getBool(0x703,8,2);//
        TrainLocal->TACU_FAULT52 = CrrcMvb::getCrrcMvb()->getBool(0x703,8,3);//
        TrainLocal->TACU_FAULT53 = CrrcMvb::getCrrcMvb()->getBool(0x703,8,4);//
        TrainLocal->TACU_FAULT54 = CrrcMvb::getCrrcMvb()->getBool(0x703,8,5);//
        TrainLocal->TACU_FAULT55 = CrrcMvb::getCrrcMvb()->getBool(0x703,8,6);//
        TrainLocal->TACU_FAULT56 = CrrcMvb::getCrrcMvb()->getBool(0x703,8,7);//
        TrainLocal->TACU_FAULT57 = CrrcMvb::getCrrcMvb()->getBool(0x703,9,0);//
        TrainLocal->TACU_FAULT58 = CrrcMvb::getCrrcMvb()->getBool(0x703,9,1);//
        TrainLocal->TACU_FAULT59 = CrrcMvb::getCrrcMvb()->getBool(0x703,9,2);//
        TrainLocal->TACU_FAULT60 = CrrcMvb::getCrrcMvb()->getBool(0x703,9,3);//
        TrainLocal->TACU_FAULT61 = CrrcMvb::getCrrcMvb()->getBool(0x703,9,4);//
        TrainLocal->TACU_FAULT62 = CrrcMvb::getCrrcMvb()->getBool(0x703,9,5);//分时标志：bit0
        TrainLocal->TACU_FAULT63 = CrrcMvb::getCrrcMvb()->getBool(0x703,9,6);//分时标志：bit1
        TrainLocal->TACU_FAULT64 = CrrcMvb::getCrrcMvb()->getBool(0x703,9,7);//分时标志：bit2
        TrainLocal->CMD_TC4_4Q1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,10,0);//它车4 整流器1隔离请求
        TrainLocal->CMD_TC4_4Q2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,10,1);//它车4 整流器2隔离请求
        TrainLocal->CMD_TC4_4Q3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,10,2);//它车4 整流器3隔离请求
        TrainLocal->CMD_TC4_4Q4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,10,3);//它车4 整流器4隔离请求
        TrainLocal->CMD_TC4_AXLE1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,10,4);//它车4 轴1隔离请求
        TrainLocal->CMD_TC4_AXLE2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,10,5);//它车4 轴2隔离请求
        TrainLocal->CMD_TC4_AXLE3_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,10,6);//它车4 轴3隔离请求
        TrainLocal->CMD_TC4_AXLE4_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,10,7);//它车4 轴4隔离请求
        TrainLocal->CMD_TC4_AUX1_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,11,0);//它车4 辅变流1隔离请求
        TrainLocal->CMD_TC4_AUX2_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,11,1);//它车4 辅变流2隔离请求
        TrainLocal->CMD_TC4_DAMAN_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,11,2);//它车4 无人警惕隔离请求
        TrainLocal->CMD_TC4_EBRK_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,11,3);//它车4 电制动隔离请求
        TrainLocal->CMD_TC4_CPR_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,11,4);//它车4 空压机隔离请求
        TrainLocal->CMD_TC4_PANTO_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,11,5);//它车4 受电弓隔离请求
        TrainLocal->CMD_TC4_FLL_ISO_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,11,6);//它车4 轮缘润滑隔离请求
        TrainLocal->CMD_TRACK_BLOCK = CrrcMvb::getCrrcMvb()->getBool(0x703,11,7);//切除牵引
        TrainLocal->CMD_TC4_4Q1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,12,0);//它车4 整流器1隔离取消请求
        TrainLocal->CMD_TC4_4Q2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,12,1);//它车4 整流器2隔离取消请求
        TrainLocal->CMD_TC4_4Q3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,12,2);//它车4 整流器3隔离取消请求
        TrainLocal->CMD_TC4_4Q4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,12,3);//它车4 整流器4隔离取消请求
        TrainLocal->CMD_TC4_AXLE1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,12,4);//它车4 轴1隔离取消请求
        TrainLocal->CMD_TC4_AXLE2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,12,5);//它车4 轴2隔离取消请求
        TrainLocal->CMD_TC4_AXLE3_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,12,6);//它车4 轴3隔离取消请求
        TrainLocal->CMD_TC4_AXLE4_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,12,7);//它车4 轴4隔离取消请求
        TrainLocal->CMD_TC4_AUX1_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,13,0);//它车4 辅变流1隔离取消请求
        TrainLocal->CMD_TC4_AUX2_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,13,1);//它车4 辅变流2隔离取消请求
        TrainLocal->CMD_TC4_DAMAN_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,13,2);//它车4 无人警惕隔离取消请求
        TrainLocal->CMD_TC4_EBRK_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,13,3);//它车4 电制动隔离取消请求
        TrainLocal->CMD_TC4_CPR_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,13,4);//它车4 空压机隔离取消请求
        TrainLocal->CMD_TC4_PANTO_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,13,5);//它车4 受电弓隔离取消请求
        TrainLocal->CMD_TC4_FLL_ISO_REL_RQ = CrrcMvb::getCrrcMvb()->getBool(0x703,13,6);//它车4 轮缘润滑隔离取消请求
        TrainLocal->CMD_FIRE_ALARM_CONFIRM = CrrcMvb::getCrrcMvb()->getBool(0x703,13,7);//火灾报警确认

        TrainLocal->LOCO_NO = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x700,0);//本车编号
        TrainLocal->DATE_TIME1 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x700,2);//日期时间1
        TrainLocal->DATE_TIME2 = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x700,4);//日期时间2
        TrainLocal->TOTAL_TE_ACTUAL = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x700,12);//总的牵引/制动力，单位KN 将数值加1000 乘10
        TrainLocal->LOAD_VALUE = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,2);//牵引吨位
        TrainLocal->Q4Q1_PRIM_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,4);//四象限1输入电压
        TrainLocal->Q4Q2_PRIM_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,6);//四象限2输入电压
        TrainLocal->Q4Q3_PRIM_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,8);//四象限3输入电压
        TrainLocal->Q4Q4_PRIM_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,10);//四象限4输入电压
        TrainLocal->Q4Q1_PRIM_C = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,12);//四象限1输入电流
        TrainLocal->Q4Q2_PRIM_C = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,14);//四象限2输入电流
        TrainLocal->Q4Q3_PRIM_C = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,16);//四象限3输入电流
        TrainLocal->Q4Q4_PRIM_C = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,18);//四象限4输入电流
        TrainLocal->Q4Q1_DC_LINK_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,20);//四象限1直流母线电压
        TrainLocal->Q4Q2_DC_LINK_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,22);//四象限2直流母线电压
        TrainLocal->Q4Q3_DC_LINK_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,24);//四象限3直流母线电压
        TrainLocal->Q4Q4_DC_LINK_V = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x701,26);//四象限4直流母线电压
        TrainLocal->CMD_MSCT_GRD = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x702,4);//司控器极位 + 100 发
        TrainLocal->ACTUAL_SPEED = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x703,18);//机车速度kmh
        TrainLocal->BCU_EBRAKE = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x703,20);//BCU ED brake demand

        TrainLocal->CMD_CS_VALUE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x700,11);//定速值
        TrainLocal->NET_VOLT = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x701,0);//主变压器原边电压 除以128传送
        TrainLocal->NET_CURRENT = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x701,1);//主变压器原边电流*0.5
        TrainLocal->MOT1_C = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x701,28);//牵引电机1电流*0.5
        TrainLocal->MOT2_C = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x701,29);//牵引电机2电流*0.5
        TrainLocal->MOT3_C = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x701,30);//牵引电机3电流*0.5
        TrainLocal->MOT4_C = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x701,31);//牵引电机4电流*0.5
        TrainLocal->TE_AXLE1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,0);//轴1实际牵引力/制动力，单位kN  将数值加100
        TrainLocal->TE_AXLE2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,1);//轴2实际牵引力/制动力，单位kN  将数值加100
        TrainLocal->TE_AXLE3 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,2);//轴3实际牵引力/制动力，单位kN  将数值加100
        TrainLocal->TE_AXLE4 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,3);//轴4实际牵引力/制动力，单位kN  将数值加100
        TrainLocal->TRANS_TEMP1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,6);//(主变压器温度1 + 50)
        TrainLocal->TRANS_TEMP2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,7);//(主变压器温度2 + 50)
        TrainLocal->MOT1_TEMP = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,8);//(牵引电机1温度 + 50) * 0.5
        TrainLocal->MOT2_TEMP = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,9);//(牵引电机2温度 + 50) * 0.5
        TrainLocal->MOT3_TEMP = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,10);//(牵引电机2温度 + 50) * 0.5
        TrainLocal->MOT4_TEMP = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,11);//(牵引电机2温度 + 50) * 0.5
        TrainLocal->WATER_PRES1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,12);//冷却液压力1 * 0.25
        TrainLocal->WATER_PRES2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,13);//冷却液压力2 * 0.25
        TrainLocal->WATER_TEMP1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,14);//冷却液温度1 + 50
        TrainLocal->WATER_TEMP2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,15);//冷却液温度2 + 50
        TrainLocal->ACU1_FREQ = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,16);//辅助1频率
        TrainLocal->ACU2_FREQ = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,17);//辅助2频率
        TrainLocal->TCMS_FLT_F1 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,19);//故障分时发送标志位1=1,2,3
        TrainLocal->TCMS_FLT_F2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,21);//故障分时发送标志位2=1,2,3
        TrainLocal->TCMS_FLT_F3 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,23);//故障分时发送标志位3=1,2,3
        TrainLocal->TCMS_FLT_F4 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,25);//故障分时发送标志位4=1,2,3
        TrainLocal->TCMS_FLT_F5 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,27);//故障分时发送标志位5=1,2,3
        TrainLocal->TCMS_FLT_F6 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,29);//故障分时发送标志位6=1,2,3
        TrainLocal->TCMS_FLT_F7 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,31);//故障分时发送标志位7=1,2,3
        TrainLocal->WATER_PRES3 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x703,14);//冷却液压力3 * 0.25
        TrainLocal->WATER_PRES4 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x703,15);//冷却液压力4 * 0.25
        TrainLocal->WATER_TEMP3 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x703,16);//冷却液温度3 + 50
        TrainLocal->WATER_TEMP4 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x703,17);//冷却液温度4 + 50
        TrainLocal->MPU_LIFE2 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x703,22);//MPU_LIFE2

        for(int j = 0;j<7;j++)
        {
            //对分时标志位做判断
            switch (CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,19+2*j))
            {
            case 1:
                CrrcMvb::getCrrcMvb()->setUnsignedChar(0x1702,18+2*j,CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,18+2*j));//对virtual port 分别copy数据
                break;
            case 2:
                CrrcMvb::getCrrcMvb()->setUnsignedChar(0x2702,18+2*j,CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,18+2*j));//对virtual port 分别copy数据
                break;
            case 3:
                CrrcMvb::getCrrcMvb()->setUnsignedChar(0x3702,18+2*j,CrrcMvb::getCrrcMvb()->getUnsignedChar(0x702,18+2*j));//对virtual port 分别copy数据
                break;
            default:
                // clear??
                break;
            }
        }
    }
    //本项目无法从TCN端口读取本车TCN数据，在此把本车数据赋给train数组对象。方便调用
    if(CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,18) < 5 && CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,18)>0)
    {
        train[CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,18)-1] = TrainLocal;
    }
}
