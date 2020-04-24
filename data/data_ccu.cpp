#include "data_ccu.h"
#include "crrcmvb.h"

Data_CCU::Data_CCU()
{
    B_NORMAL_MODE = false;
    B_LOAD_SET = false;

    N_LOAD = 0;

}
void Data_CCU::updateData()
{
    //DDU-MPU
    //0x300
    CrrcMvb::getCrrcMvb()->setBool(0x300,0,0,B_TC1_BOGIE1_ISO_RQ);//车1 转向架1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,0,1,B_TC1_4Q1_ISO_RQ);//车1 整流器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,0,2,B_TC1_4Q2_ISO_RQ);//车1 整流器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,0,3,B_TC1_AXLE1_ISO_RQ);//车1 逆变器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,0,4,B_TC1_AXLE2_ISO_RQ);//车1 逆变器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,0,5,B_TC1_AXLE3_ISO_RQ);//车1 逆变器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,0,6,B_TC1_AUX1_ISO_RQ);//车1 辅变流1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,0,7,B_TC1_BOGIE2_ISO_RQ);//车1 转向架2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,1,0,B_TC1_4Q3_ISO_RQ);//车1 整流器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,1,1,B_TC1_4Q4_ISO_RQ);//车1 整流器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,1,2,B_TC1_AXLE4_ISO_RQ);//车1 逆变器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,1,5,B_TC1_AUX2_ISO_RQ);//车1 辅变流2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,1,6,B_TC1_QA_HV_ON);//车1 高压隔离开关开（5s高电平）
    CrrcMvb::getCrrcMvb()->setBool(0x300,1,7,B_TC1_QA_HV_OFF);//车1 高压隔离开关关（5s高电平）
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,0,B_TC1_BOGIE1_ISO_REL_RQ);//车1 转向架1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,1,B_TC1_4Q1_ISO_REL_RQ);//车1 整流器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,2,B_TC1_4Q2_ISO_REL_RQ);//车1 整流器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,3,B_TC1_AXLE1_ISO_REL_RQ);//车1 逆变器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,4,B_TC1_AXLE2_ISO_REL_RQ);//车1 逆变器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,5,B_TC1_AXLE3_ISO_REL_RQ);//车1 逆变器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,6,B_TC1_AUX1_ISO_REL_RQ);//车1 辅变流1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,2,7,B_TC1_BOGIE2_ISO_REL_RQ);//车1 转向架2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,0,B_TC1_4Q3_ISO_REL_RQ);//车1 整流器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,1,B_TC1_4Q4_ISO_REL_RQ);//车1 整流器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,2,B_TC1_AXLE4_ISO_REL_RQ);//车1 逆变器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,3,5,B_TC1_AUX2_ISO_REL_RQ);//车1 辅变流2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,0,B_TC1_DAMAN_ISO_RQ);//车1 无人警惕隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,1,B_TC1_EBRK_ISO_RQ);//车1 电制动隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,2,B_TC1_CPR_ISO_RQ);//车1 空压机隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,4,B_TC1_FLL_ISO_RQ);//车1 轮缘润滑隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,5,B_TC1_PANTO_ISO_RQ);//车1 受电弓隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,4,7,B_TC1_FAULT_RESET);//车1 故障复位
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,0,B_TC1_DAMAN_ISO_REL_RQ);//车1 无人警惕隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,1,B_TC1_EBRK_ISO_REL_RQ);//车1 电制动隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,2,B_TC1_CPR_ISO_REL_RQ);//车1 空压机隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,4,B_TC1_FLL_ISO_REL_RQ);//车1 轮缘润滑隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,5,5,B_TC1_PANTO_ISO_REL_RQ);//车1 受电弓隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,0,B_TC2_BOGIE1_ISO_RQ);//车2 转向架1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,1,B_TC2_4Q1_ISO_RQ);//车2 整流器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,2,B_TC2_4Q2_ISO_RQ);//车2 整流器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,3,B_TC2_AXLE1_ISO_RQ);//车2 逆变器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,4,B_TC2_AXLE2_ISO_RQ);//车2 逆变器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,5,B_TC2_AXLE3_ISO_RQ);//车2 逆变器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,6,B_TC2_AUX1_ISO_RQ);//车2 辅变流1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,6,7,B_TC2_BOGIE2_ISO_RQ);//车2 转向架2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,0,B_TC2_4Q3_ISO_RQ);//车2 整流器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,1,B_TC2_4Q4_ISO_RQ);//车2 整流器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,2,B_TC2_AXLE4_ISO_RQ);//车2 逆变器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,5,B_TC2_AUX2_ISO_RQ);//车2 辅变流2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,6,B_TC2_QA_HV_ON);//车2 高压隔离开关开（5s高电平）
    CrrcMvb::getCrrcMvb()->setBool(0x300,7,7,B_TC2_QA_HV_OFF);//车2 高压隔离开关关（5s高电平）
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,0,B_TC2_BOGIE1_ISO_REL_RQ);//车2 转向架1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,1,B_TC2_4Q1_ISO_REL_RQ);//车2 整流器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,2,B_TC2_4Q2_ISO_REL_RQ);//车2 整流器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,3,B_TC2_AXLE1_ISO_REL_RQ);//车2 逆变器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,4,B_TC2_AXLE2_ISO_REL_RQ);//车2 逆变器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,5,B_TC2_AXLE3_ISO_REL_RQ);//车2 逆变器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,6,B_TC2_AUX1_ISO_REL_RQ);//车2 辅变流1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,8,7,B_TC2_BOGIE2_ISO_REL_RQ);//车2 转向架2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,0,B_TC2_4Q3_ISO_REL_RQ);//车2 整流器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,1,B_TC2_4Q4_ISO_REL_RQ);//车2 整流器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,2,B_TC2_AXLE4_ISO_REL_RQ);//车2 逆变器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,9,5,B_TC2_AUX2_ISO_REL_RQ);//车2 辅变流2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,0,B_TC2_DAMAN_ISO_RQ);//车2 无人警惕隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,1,B_TC2_EBRK_ISO_RQ);//车2 电制动隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,2,B_TC2_CPR_ISO_RQ);//车2 空压机隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,4,B_TC2_FLL_ISO_RQ);//车2 轮缘润滑隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,5,B_TC2_PANTO_ISO_RQ);//车2 受电弓隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,10,7,B_TC2_FAULT_RESET);//车2 故障复位
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,0,B_TC2_DAMAN_ISO_REL_RQ);//车2 无人警惕隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,1,B_TC2_EBRK_ISO_REL_RQ);//车2 电制动隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,2,B_TC2_CPR_ISO_REL_RQ);//车2 空压机隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,4,B_TC2_FLL_ISO_REL_RQ);//车2 轮缘润滑隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,11,5,B_TC2_PANTO_ISO_REL_RQ);//车2 受电弓隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,0,B_TC3_BOGIE1_ISO_RQ);//车3 转向架1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,1,B_TC3_4Q1_ISO_RQ);//车3 整流器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,2,B_TC3_4Q2_ISO_RQ);//车3 整流器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,3,B_TC3_AXLE1_ISO_RQ);//车3 逆变器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,4,B_TC3_AXLE2_ISO_RQ);//车3 逆变器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,5,B_TC3_AXLE3_ISO_RQ);//车3 逆变器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,6,B_TC3_AUX1_ISO_RQ);//车3 辅变流1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,12,7,B_TC3_BOGIE2_ISO_RQ);//车3 转向架2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,0,B_TC3_4Q3_ISO_RQ);//车3 整流器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,1,B_TC3_4Q4_ISO_RQ);//车3 整流器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,2,B_TC3_AXLE4_ISO_RQ);//车3 逆变器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,5,B_TC3_AUX2_ISO_RQ);//车3 辅变流2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,6,B_TC3_QA_HV_ON);//车3 高压隔离开关开（5s高电平）
    CrrcMvb::getCrrcMvb()->setBool(0x300,13,7,B_TC3_QA_HV_OFF);//车3 高压隔离开关关（5s高电平）
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,0,B_TC3_BOGIE1_ISO_REL_RQ);//车3 转向架1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,1,B_TC3_4Q1_ISO_REL_RQ);//车3 整流器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,2,B_TC3_4Q2_ISO_REL_RQ);//车3 整流器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,3,B_TC3_AXLE1_ISO_REL_RQ);//车3 逆变器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,4,B_TC3_AXLE2_ISO_REL_RQ);//车3 逆变器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,5,B_TC3_AXLE3_ISO_REL_RQ);//车3 逆变器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,6,B_TC3_AUX1_ISO_REL_RQ);//车3 辅变流1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,14,7,B_TC3_BOGIE2_ISO_REL_RQ);//车3 转向架2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,0,B_TC3_4Q3_ISO_REL_RQ);//车3 整流器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,1,B_TC3_4Q4_ISO_REL_RQ);//车3 整流器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,2,B_TC3_AXLE4_ISO_REL_RQ);//车3 逆变器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,15,5,B_TC3_AUX2_ISO_REL_RQ);//车3 辅变流2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,0,B_TC3_DAMAN_ISO_RQ);//车3 无人警惕隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,1,B_TC3_EBRK_ISO_RQ);//车3 电制动隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,2,B_TC3_CPR_ISO_RQ);//车3 空压机隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,4,B_TC3_FLL_ISO_RQ);//车3 轮缘润滑隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,5,B_TC3_PANTO_ISO_RQ);//车3 受电弓隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,16,7,B_TC3_FAULT_RESET);//车3 故障复位
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,0,B_TC3_DAMAN_ISO_REL_RQ);//车3 无人警惕隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,1,B_TC3_EBRK_ISO_REL_RQ);//车3 电制动隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,2,B_TC3_CPR_ISO_REL_RQ);//车3 空压机隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,4,B_TC3_FLL_ISO_REL_RQ);//车3 轮缘润滑隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,17,5,B_TC3_PANTO_ISO_REL_RQ);//车3 受电弓隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,0,B_TC4_BOGIE1_ISO_RQ);//车4 转向架1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,1,B_TC4_4Q1_ISO_RQ);//车4 整流器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,2,B_TC4_4Q2_ISO_RQ);//车4 整流器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,3,B_TC4_AXLE1_ISO_RQ);//车4 逆变器1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,4,B_TC4_AXLE2_ISO_RQ);//车4 逆变器2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,5,B_TC4_AXLE3_ISO_RQ);//车4 逆变器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,6,B_TC4_AUX1_ISO_RQ);//车4 辅变流1隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,18,7,B_TC4_BOGIE2_ISO_RQ);//车4 转向架2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,0,B_TC4_4Q3_ISO_RQ);//车4 整流器3隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,1,B_TC4_4Q4_ISO_RQ);//车4 整流器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,2,B_TC4_AXLE4_ISO_RQ);//车4 逆变器4隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,5,B_TC4_AUX2_ISO_RQ);//车4 辅变流2隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,6,B_TC4_QA_HV_ON);//车4 高压隔离开关开（5s高电平）
    CrrcMvb::getCrrcMvb()->setBool(0x300,19,7,B_TC4_QA_HV_OFF);//车4 高压隔离开关关（5s高电平）
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,0,B_TC4_BOGIE1_ISO_REL_RQ);//车4 转向架1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,1,B_TC4_4Q1_ISO_REL_RQ);//车4 整流器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,2,B_TC4_4Q2_ISO_REL_RQ);//车4 整流器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,3,B_TC4_AXLE1_ISO_REL_RQ);//车4 逆变器1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,4,B_TC4_AXLE2_ISO_REL_RQ);//车4 逆变器2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,5,B_TC4_AXLE3_ISO_REL_RQ);//车4 逆变器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,6,B_TC4_AUX1_ISO_REL_RQ);//车4 辅变流1隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,20,7,B_TC4_BOGIE2_ISO_REL_RQ);//车4 转向架2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,0,B_TC4_4Q3_ISO_REL_RQ);//车4 整流器3隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,1,B_TC4_4Q4_ISO_REL_RQ);//车4 整流器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,2,B_TC4_AXLE4_ISO_REL_RQ);//车4 逆变器4隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,21,5,B_TC4_AUX2_ISO_REL_RQ);//车4 辅变流2隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,22,0,B_TC4_DAMAN_ISO_RQ);//车4 无人警惕隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,22,1,B_TC4_EBRK_ISO_RQ);//车4 电制动隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,22,2,B_TC4_CPR_ISO_RQ);//车4 空压机隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,22,4,B_TC4_FLL_ISO_RQ);//车4 轮缘润滑隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,22,5,B_TC4_PANTO_ISO_RQ);//车4 受电弓隔离请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,22,7,B_TC4_FAULT_RESET);//车4 故障复位
    CrrcMvb::getCrrcMvb()->setBool(0x300,23,0,B_TC4_DAMAN_ISO_REL_RQ);//车4 无人警惕隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,23,1,B_TC4_EBRK_ISO_REL_RQ);//车4 电制动隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,23,2,B_TC4_CPR_ISO_REL_RQ);//车4 空压机隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,23,4,B_TC4_FLL_ISO_REL_RQ);//车4 轮缘润滑隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,23,5,B_TC4_PANTO_ISO_REL_RQ);//车4 受电弓隔离取消请求
    CrrcMvb::getCrrcMvb()->setBool(0x300,24,0,B_LAMP_TEST);//指示灯测试
    CrrcMvb::getCrrcMvb()->setBool(0x300,24,1,B_FLL_TEST_START);//轮缘润滑测试开始
    CrrcMvb::getCrrcMvb()->setBool(0x300,24,2,B_FLL_TEST_CANCEL);//轮缘润滑测试取消
    CrrcMvb::getCrrcMvb()->setBool(0x300,24,3,B_DEPOT_380_ACT);//库内模式 激活
    CrrcMvb::getCrrcMvb()->setBool(0x300,24,4,B_DEPOT_380_DEACT);//库内模式 关闭
    CrrcMvb::getCrrcMvb()->setBool(0x300,24,6,B_CPR_TEST);//空压机测试
    CrrcMvb::getCrrcMvb()->setBool(0x300,24,7,B_VT_BM1_ST);//冷却塔风机1测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x300,25,0,B_VT_BM2_ST);//冷却塔风机2测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x300,25,1,B_SIM_ON);//仿真开关
    CrrcMvb::getCrrcMvb()->setBool(0x300,25,3,B_NORMAL_MODE);//普通模式
    CrrcMvb::getCrrcMvb()->setBool(0x300,25,4,B_SUMMER_MODE);//夏天模式
    CrrcMvb::getCrrcMvb()->setBool(0x300,25,6,B_AXLE_23TON);//轴重23吨
    CrrcMvb::getCrrcMvb()->setBool(0x300,25,7,B_AXLE_25TON);//轴重25吨
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x300,26,N_SIM_SPEED);//模拟机车速度 单位：km/h
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x300,28,N_SIM_LINE_VOLT);//模拟网压 单位：V
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x300,30,N_DDU_LIFE);//DDU生命信号 （0~255递增）
    CrrcMvb::getCrrcMvb()->setBool(0x300,31,0,B_VT_MT1_ST);//牵引风机1测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x300,31,1,B_VT_MT2_ST);//牵引风机2测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x300,31,4,B_VT_SM1_ST);//机械间风机1测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x300,31,5,B_VT_SM2_ST);//机械间风机2测试：1测试，0停止
    CrrcMvb::getCrrcMvb()->setBool(0x300,31,6,B_P300CHECK0);//数据校验（固定发0）
    CrrcMvb::getCrrcMvb()->setBool(0x300,31,7,B_P300CHECK1);//数据校验（固定发1）
    //0x301
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,0,N_YEAR);//DDU发出的年份值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,2,N_MONTH);//DDU发出的月份值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,3,N_DAY);//DDU发出的日期值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,4,N_HOUR);//DDU发出的小时值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,5,N_MINUTE);//DDU发出的分钟值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,6,N_SECOND);//DDU发出的秒钟值
    CrrcMvb::getCrrcMvb()->setBool(0x301,8,0,B_FLL_SET);//轮缘润滑值设置标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,8,1,B_TIME_SET);//日期时间设置标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,8,2,B_BRK_CHAR_Z);//制动特性设定：恒转矩
    CrrcMvb::getCrrcMvb()->setBool(0x301,8,3,B_WHEEL_DIA_SET);//轮径设置标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,8,4,B_TRAC_CHAR_H);//牵引特性设定，恒转矩
    CrrcMvb::getCrrcMvb()->setBool(0x301,8,5,B_TRAC_CHAR_Z);//牵引特性设定，准恒速
    CrrcMvb::getCrrcMvb()->setBool(0x301,8,6,B_BRK_CHAR_H);//制动特性：准恒速
    CrrcMvb::getCrrcMvb()->setBool(0x301,8,7,B_LOCO_NO_SET);//机车编号设置标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,9,0,B_PARTNER_ID_SET);//内重联车编号设置标志
    CrrcMvb::getCrrcMvb()->setBool(0x301,9,1,B_SEQUENCE_TEST);//顺序试验激活
    CrrcMvb::getCrrcMvb()->setBool(0x301,9,2,B_AIR_ELE_SET_LOCK);//空电联合设定：空电连锁
    CrrcMvb::getCrrcMvb()->setBool(0x301,9,3,B_AIR_ELE_SET_UNION);//空电联合设定：空电联合
    CrrcMvb::getCrrcMvb()->setBool(0x301,9,4,B_SAND_CUT);//自动撒砂切除
    CrrcMvb::getCrrcMvb()->setBool(0x301,9,5,B_DIS_SET);//总里程设置
    CrrcMvb::getCrrcMvb()->setBool(0x301,9,6,B_MILEAGE_RESET);//单次里程清零
    CrrcMvb::getCrrcMvb()->setBool(0x301,9,7,B_SAND_CUT_REL);//自动撒砂切除取消
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,10,N_SPEED_SET);//机车定速值 单位：km/h
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,12,N_WHEEL_DIA);//轴2车轮直径值 单位：mm
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,16,N_LOAD);//牵引吨位 单位：吨
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,18,N_FLL_DIS);//轮缘润滑距离 单位：m
    CrrcMvb::getCrrcMvb()->setUnsignedInt(0x301,20,N_FLL_TIME);//轮缘润滑时间 单位：秒
    CrrcMvb::getCrrcMvb()->setUnsignedInt32(0x301,24,N_DIS_VALUE);//里程设置值
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,28,N_DDU_VX);//DDU版本号x
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,29,N_DDU_VY);//DDU版本号y
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x301,30,N_DDU_VZ);//DDU版本号z
    CrrcMvb::getCrrcMvb()->setBool(0x301,31,0,B_FIR_ALARM_CONFIRM);//火灾报警确认
    CrrcMvb::getCrrcMvb()->setBool(0x301,31,1,B_LOAD_SET);//牵引吨位设置标志(持续5s)
    CrrcMvb::getCrrcMvb()->setBool(0x301,31,2,B_DAMAN_TEST);//无人警惕测试
    CrrcMvb::getCrrcMvb()->setBool(0x301,31,3,B_ANSC_TEST);//自动过分相测试
    CrrcMvb::getCrrcMvb()->setBool(0x301,31,4,B_MSCT_BOXING_SET);//司控器正常、跛行选择:0-正常，1-跛行
    CrrcMvb::getCrrcMvb()->setBool(0x301,31,6,B_P301CHECK0);//数据校验（固定发0）
    CrrcMvb::getCrrcMvb()->setBool(0x301,31,7,B_P301CHECK1);//数据校验（固定发1）
    //0x302
    CrrcMvb::getCrrcMvb()->setBool(0x302,0,0,B_NSC_DISTANCE1);//常规线路过分相：170m模式
    CrrcMvb::getCrrcMvb()->setBool(0x302,0,1,B_NSC_DISTANCE2);//货运专线过分相：265m模式
    CrrcMvb::getCrrcMvb()->setBool(0x302,0,2,B_NSC_SET);//过分相模式设定标志
    CrrcMvb::getCrrcMvb()->setBool(0x302,0,3,B_DOUBLE_PG);//双弓测试模式设定:0-正常，1-测试
    CrrcMvb::getCrrcMvb()->setBool(0x302,0,4,B_TRAILER_MODE);//挂车模式:0-正常，1-挂车
    CrrcMvb::getCrrcMvb()->setBool(0x302,0,5,B_DADMAN_SET);//无人警惕设置标志
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x302,2,N_DADMAN_TIMESAPCE);//无人警惕采样时间
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x302,3,N_DADMAN_TIMEALARM);//无人警惕报警时间
    CrrcMvb::getCrrcMvb()->setUnsignedInt32(0x302,4,N_LOCO_ID);//机车编号 单位：1
    CrrcMvb::getCrrcMvb()->setUnsignedInt32(0x302,8,N_PARTNER_ID);//内重联车编号 单位：1
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x302,29,N_TRAILER_MODE_SPEED);//挂车模式速度设定
    CrrcMvb::getCrrcMvb()->setUnsignedChar(0x302,30,N_DOUBLE_PG_SPEED);//双弓测试模式速度设定
    CrrcMvb::getCrrcMvb()->setBool(0x302,31,6,B_P302CHECK0);//数据校验（固定发0）
    CrrcMvb::getCrrcMvb()->setBool(0x302,31,7,B_P302CHECK1);//数据校验（固定发1）
    //MPU-DDU
    //0x710
    M1_D1_N_BAT_VOLT = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,0);//蓄电池电压,小数点后1位，将数值乘以10
    M1_D1_N_TEBE_EFFORT = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,2);//总牵引力/制动百分比 小数点后1位，将数值加100后乘以10
    M1_D1_N_ACTUAL_SPEED = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,4);//机车速度kmh 乘以10后发给显示屏
    M1_D1_N_SET_SPEED = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,6);//设定速度，单位km/h
    M1_D1_N_MSCT_GRD = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,8);//司控器级位*10 加200后发给DDU,"*"为255
    M1_D1_N_WHEEL_DIA = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x710,10);//轴2的车轮直径 单位：mm
    M1_D1_N_BAT_TMP = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,12);//蓄电池温度，50=0度，正表示零上，负表示零下
    M1_D1_N_RULOCO_NO = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,14);//重联机车数
    M1_D1_N_UIC_ADDR = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,15) == 0?1:CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,15);//UIC地址
    M1_D1_N_OTHERUIC_ADDR = M1_D1_N_UIC_ADDR == 1?2:1;//内重联他车UIC ID

    M1_D1_B_NSC_START = CrrcMvb::getCrrcMvb()->getBool(0x710,16,0);//过分相开始
    M1_D1_B_NSC_END = CrrcMvb::getCrrcMvb()->getBool(0x710,16,1);//过分相结束
    M1_D1_B_STATE_CAB_ACTIVE = CrrcMvb::getCrrcMvb()->getBool(0x710,16,2);//有司机室激活
    M1_D1_B_SANDING = CrrcMvb::getCrrcMvb()->getBool(0x710,16,4);//撒砂激活
    M1_D1_B_RACING = CrrcMvb::getCrrcMvb()->getBool(0x710,16,5);//空转
    M1_D1_B_SLIP = CrrcMvb::getCrrcMvb()->getBool(0x710,16,6);//滑行
    M1_D1_B_SPEED_CTL = CrrcMvb::getCrrcMvb()->getBool(0x710,16,7);//定速模式
    M1_D1_B_SIM_MODE = CrrcMvb::getCrrcMvb()->getBool(0x710,17,1);//仿真模式
    M1_D1_B_NORMAL_MODE = CrrcMvb::getCrrcMvb()->getBool(0x710,17,2);//普通模式
    M1_D1_B_SUMMER_MODE = CrrcMvb::getCrrcMvb()->getBool(0x710,17,3);//夏天模式
    M1_D1_B_AXLE_23TON = CrrcMvb::getCrrcMvb()->getBool(0x710,17,4);//轴重23吨
    M1_D1_B_AXLE_25TON = CrrcMvb::getCrrcMvb()->getBool(0x710,17,5);//轴重25吨
    M1_D1_B_DEPOT_SIM = CrrcMvb::getCrrcMvb()->getBool(0x710,17,6);//库内测试
    M1_D1_B_DEPOT_MOVE = CrrcMvb::getCrrcMvb()->getBool(0x710,17,7);//库内动车
    M1_D1_B_LEAD_CUTIN = CrrcMvb::getCrrcMvb()->getBool(0x710,18,0);//本务投入
    M1_D1_B_LEAD_CUTOUT = CrrcMvb::getCrrcMvb()->getBool(0x710,18,1);//本务切除
    M1_D1_B_TRAIL_CUTOUT = CrrcMvb::getCrrcMvb()->getBool(0x710,18,2);//补机切除
    M1_D1_B_SAND_CUT = CrrcMvb::getCrrcMvb()->getBool(0x710,18,3);//自动撒砂切除状态
    M1_D1_B_STATE_FORWARD = CrrcMvb::getCrrcMvb()->getBool(0x710,18,4);//向前
    M1_D1_B_STATE_BACK = CrrcMvb::getCrrcMvb()->getBool(0x710,18,5);//向后
    M1_D1_B_STATE_NEUTRAL = CrrcMvb::getCrrcMvb()->getBool(0x710,18,6);//零位
    M1_D1_B_AXLE2_MOVE = CrrcMvb::getCrrcMvb()->getBool(0x710,19,0);//2轴动车
    M1_D1_B_STATE_T_CHAR = CrrcMvb::getCrrcMvb()->getBool(0x710,19,1);//牵引特性：0-恒转矩，1-准恒速
    M1_D1_B_DADMAN_ALARM = CrrcMvb::getCrrcMvb()->getBool(0x710,19,2);//无人警惕报警
    M1_D1_B_HEAT = CrrcMvb::getCrrcMvb()->getBool(0x710,19,3);//预加热
    M1_D1_B_SEQ_TEST = CrrcMvb::getCrrcMvb()->getBool(0x710,19,4);//顺序试验激活
    M1_D1_B_CAB_CHANGE = CrrcMvb::getCrrcMvb()->getBool(0x710,19,5);//换端开始
    M1_D1_B_BRK_CHAR_SET = CrrcMvb::getCrrcMvb()->getBool(0x710,19,6);//制动特性：1-恒转矩，0-准恒速
    M1_D1_B_AIR_ELE = CrrcMvb::getCrrcMvb()->getBool(0x710,19,7);//空电联合状态：1-空点连锁，0-空电联合
    M1_D1_B_CUR_MPU1 = CrrcMvb::getCrrcMvb()->getBool(0x710,20,0);//当前为MPU1
    M1_D1_B_CUR_MPU2 = CrrcMvb::getCrrcMvb()->getBool(0x710,20,1);//当前为MPU2
    M1_D1_B_MPU1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,20,2);//MPU1在线
    M1_D1_B_MPU2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,20,3);//MPU2在线
    M1_D1_B_ACU1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,20,4);//ACU1 在线
    M1_D1_B_ACU2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,20,5);//ACU2 在线
    M1_D1_B_TCU1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,20,6);//TCU1 在线
    M1_D1_B_TCU2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,20,7);//TCU2 在线
    M1_D1_B_BCU_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,21,0);//BCU 在线
    M1_D1_B_DDU_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,21,1);//DDU在线
    M1_D1_B_TCU3_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,21,2);//TCU3 在线
    M1_D1_B_RIOM1_GW_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,21,3);//RIOM1在线
    M1_D1_B_RIOM2_GW_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,21,4);//RIOM2在线
    M1_D1_B_TCU4_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,21,5);//TCU4 在线
    M1_D1_B_UIC_GW1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,21,6);//GW1在线
    M1_D1_B_UIC_GW2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,21,7);//GW2在线
    M1_D1_B_6A_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,22,0);//6A在线
    M1_D1_B_RIOM1_DI1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,22,1);//RIOM1_DI1在线
    M1_D1_B_RIOM1_DI2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,22,2);//RIOM1_DI2在线
    M1_D1_B_RIOM1_DO1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,22,4);//RIOM1_DO1在线
    M1_D1_B_RIOM1_AX1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,22,5);//RIOM1_AX1在线
    M1_D1_B_ERM_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,22,6);//ERM在线
    M1_D1_B_GW1_MAS = CrrcMvb::getCrrcMvb()->getBool(0x710,22,7);//网关1首选
    M1_D1_B_GW2_MAS = CrrcMvb::getCrrcMvb()->getBool(0x710,23,0);//网关2首选
    M1_D1_B_Batt_Low = CrrcMvb::getCrrcMvb()->getBool(0x710,23,1);//控制电压低
    M1_D1_B_CP_650kp = CrrcMvb::getCrrcMvb()->getBool(0x710,23,2);//总风风压低
    M1_D1_B_NSC_DISTANCE1 = CrrcMvb::getCrrcMvb()->getBool(0x710,23,3);//常规线路过分相：170m模式
    M1_D1_B_NSC_DISTANCE2 = CrrcMvb::getCrrcMvb()->getBool(0x710,23,4);//货运专线过分相：265m模式
    M1_D1_B_DOUBLE_PG = CrrcMvb::getCrrcMvb()->getBool(0x710,23,5);//双弓模式激活反馈
    M1_D1_B_TRAILER_MODE = CrrcMvb::getCrrcMvb()->getBool(0x710,23,6);//挂车模式反馈
    M1_D1_B_RIOM2_DI1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,24,0);//RIOM2_DI1在线
    M1_D1_B_RIOM2_DI2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,24,1);//RIOM2_DI2在线
    M1_D1_B_RIOM2_DI3_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,24,2);//RIOM2_DI3在线
    M1_D1_B_RIOM2_DI4_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,24,3);//RIOM2_DI4在线
    M1_D1_B_RIOM2_DI5_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,24,4);//RIOM2_DI5在线
    M1_D1_B_RIOM2_DO1_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,24,6);//RIOM2_DO1在线
    M1_D1_B_RIOM2_DO2_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,24,7);//RIOM2_DO2在线
    M1_D1_B_RIOM2_DO3_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,25,0);//RIOM2_DO3在线
    M1_D1_B_RIOM2_DO4_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,25,1);//RIOM2_DO4在线
    M1_D1_B_GW3_ONLINE = CrrcMvb::getCrrcMvb()->getBool(0x710,25,5);//GW3在线
    M1_D1_N_MCB_ON_COUNTER = CrrcMvb::getCrrcMvb()->getUnsignedInt32(0x710,26);//主断闭合次数
    M1_D1_N_MPU_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x710,30);//MPU生命信号（0～255递增）
    M1_D1_B_P710CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x710,31,6);//数据校验(固定发0)
    M1_D1_B_P710CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x710,31,7);//数据校验(固定发1)
    //0x711
    M1_D1_N_LOAD = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,0);//牵引吨位 单位：吨
    M1_D1_N_FLL_DIS = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,2);//轮缘润滑距离 单位：m
    M1_D1_N_FLL_SECONDS = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,4);//轮缘润滑返回秒数
    M1_D1_N_YEAR = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,6);//系统时间（年）
    M1_D1_N_MONTH = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,8);//系统时间（月）
    M1_D1_N_DATE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,9);//系统时间（日）
    M1_D1_N_HOUR = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,10);//系统时间（时）
    M1_D1_N_MINUTE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,11);//系统时间（分）
    M1_D1_N_SECOND = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,12);//系统时间（秒）
    M1_D1_N_DEVICE_NO = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,13);//网络设备编号(循环发送)
    M1_D1_N_VERSION_A = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,14);//alpha revision(A.x.y.z)
    M1_D1_N_VERSION_X = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,15);//value of x
    M1_D1_N_VERSION_Y = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,16);//value of y
    M1_D1_N_VERSION_Z = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,17);//value of z
    M1_D1_N_TRIP_COUNTER = CrrcMvb::getCrrcMvb()->getUnsignedInt32(0x711,18);//清零后运行公里数
    M1_D1_N_TOTAL_DISTANCE = CrrcMvb::getCrrcMvb()->getUnsignedInt32(0x711,22);//总公里数
    M1_D1_N_DADMAN_TIME = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,26);//无人警惕倒计时
    M1_D1_N_FLL_TIME = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x711,27);//轮缘润滑设定时间
    M1_D1_N_PARTNER_ID = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x711,28);//内重联车ID
    M1_D1_B_P711CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x711,31,6);//数据校验(固定发0)
    M1_D1_B_P711CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x711,31,7);//数据校验(固定发1)
    //0x712
    M1_D1_N_DADMAN_TIMESPACE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,0);//无人警惕采样间隔时间返回值
    M1_D1_N_DADMAN_ALARMTIME = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,1);//无人警惕报警时间返回值
    M1_D1_N_PARTNER_ID = CrrcMvb::getCrrcMvb()->getUnsignedInt32(0x712,2);//内重联车ID
    M1_D1_ATO_N_MSCT_GRD = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x712,6);//牵引时，3750=13级；制动时，3750=12级
    M1_D1_ATO_N_MODE_ATO = CrrcMvb::getCrrcMvb()->getBool(0x712,8,0);//1=自动驾驶，0=非自动驾驶
    M1_D1_N_MESG_FLAG = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x712,9);//提示信息分时标志
    //分时数据
    M1_D1_B_MESG_BYTE1_BIT0 = CrrcMvb::getCrrcMvb()->getBool(0x712,10,0);//(1)本节受电弓隔离               (2)总风压力低牵引封锁                    (3)正准备库内动车                (4)牵引电机1温度高降功运行
    M1_D1_B_MESG_BYTE1_BIT1 = CrrcMvb::getCrrcMvb()->getBool(0x712,10,1);//(1)内重联车受电弓隔离            (2)带闸启动，时速超过10公里牵引封锁        (3)库内动车正在进行              (4) 主变压器温度高降功运行
    M1_D1_B_MESG_BYTE1_BIT2 = CrrcMvb::getCrrcMvb()->getBool(0x712,10,2);//(1)本节高压隔离开关隔离          (2)停放制动未缓解，机车牵引封锁            (3)正准备辅机测试                (4)变流器1自检未完成禁止合主断
    M1_D1_B_MESG_BYTE1_BIT3 = CrrcMvb::getCrrcMvb()->getBool(0x712,10,3);//(1)内重联车高压隔离开关隔离       (2)制动使TCU卸载                        (3)辅机测试正在进行              (4)牵引电机2温度高降功运行
    M1_D1_B_MESG_BYTE1_BIT4 = CrrcMvb::getCrrcMvb()->getBool(0x712,10,4);//(1)双弓模式激活                 (2)制动缸1隔离塞门关闭                   (3)后备制动                     (4)牵引电机3温度高降功运行
    M1_D1_B_MESG_BYTE1_BIT5 = CrrcMvb::getCrrcMvb()->getBool(0x712,10,5);//(1)挂车模式激活                 (2)空电联合速度小于3km/h电制封锁          (3)挂车模式速度大于设定速度牵引封锁 (4)牵引电机4温度高降功运行
    M1_D1_B_MESG_BYTE1_BIT6 = CrrcMvb::getCrrcMvb()->getBool(0x712,10,6);//(1)无人警惕报警                 (2)辅助风缸隔离塞门关闭                   (3)提示信息预留3276             (4)主变压器温度高降功运行
    M1_D1_B_MESG_BYTE1_BIT7 = CrrcMvb::getCrrcMvb()->getBool(0x712,10,7);//(1)双弓模式时速大于5公里牵引封锁   (2)紧急隔离塞门关闭                      (3)提示信息预留3277             (4)变流器2自检未完成禁止合主断
    M1_D1_B_MESG_BYTE2_BIT0 = CrrcMvb::getCrrcMvb()->getBool(0x712,11,0);//(1)辅助风压低，升弓请启动辅助压缩机 (2)无人警惕惩罚制动                      (3)方向手柄不在零位主断不预备     (4)提示信息预留4282
    M1_D1_B_MESG_BYTE2_BIT1 = CrrcMvb::getCrrcMvb()->getBool(0x712,11,1);//(1)过分相“自动启动”              (2)电制动工况                           (3)司控器不在中立位主断不预备     (4)提示信息预留4283
    M1_D1_B_MESG_BYTE2_BIT2 = CrrcMvb::getCrrcMvb()->getBool(0x712,11,2);//(1)过分相“手动启动”              (2)自动换端进行中                       (3)无人警惕设置更改              (4)提示信息预留4282
    M1_D1_B_MESG_BYTE2_BIT3 = CrrcMvb::getCrrcMvb()->getBool(0x712,11,3);//(1)过分相“主断路器断开”           (2)紧急制动工况                         (3)轮径设置更改                 (4)提示信息预留4283
    M1_D1_B_MESG_BYTE2_BIT4 = CrrcMvb::getCrrcMvb()->getBool(0x712,11,4);//(1)过分相“成功通过”              (2)方向手柄处于零位，机车牵引封锁          (3)机车车号设置更改              (4)提示信息预留4284
    M1_D1_B_MESG_BYTE2_BIT5 = CrrcMvb::getCrrcMvb()->getBool(0x712,11,5);//(1)油流1故障降功率               (2)带闸启动工况                          (3)提示信息预留3285            (4)提示信息预留4285
    M1_D1_B_MESG_BYTE2_BIT6 = CrrcMvb::getCrrcMvb()->getBool(0x712,11,6);//(1)油流2故障降功率               (2)空电联合工况                          (3)提示信息预留3286            (4)提示信息预留4286
    M1_D1_B_MESG_BYTE2_BIT7 = CrrcMvb::getCrrcMvb()->getBool(0x712,11,7);//(1)小闸压力开关大于90KPa牵引封锁   (2)操作端冲突，请将电钥匙拔出后重新选择操纵端 (3)提示信息预留3287            (4)提示信息预留4287


    M1_D1_B_P712CHECK0 = CrrcMvb::getCrrcMvb()->getBool(0x712,31,6);//数据校验(固定发0)
    M1_D1_B_P712CHECK1 = CrrcMvb::getCrrcMvb()->getBool(0x712,31,7);//数据校验(固定发1)

}
