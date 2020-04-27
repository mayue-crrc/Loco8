#include "data_erm.h"
#include "crrcmvb.h"
Data_ERM::Data_ERM()
{

}
void Data_ERM::updateData()
{
   LifeSign_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,0);//生命信号
   VerX_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,1);//软件版本X
   VerY_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,2);//软件版本Y
   VerZ_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,3);//软件版本Z
   HWVerX_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,4);//固件版本X
   HWVerY_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,5);//固件版本Y
   HWVerZ_U8 = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,6);//固件版本Z
   CycleTime = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,7);//ERM循环周期
   CycleCount = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,8);//ERM周期跳变次数
   ERM_TimeCheck = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x610,9);//ERM校时次数

  P610Check0 = CrrcMvb::getCrrcMvb()->getBool(0x610,31,6);//检测变量0
  P610Check1 = CrrcMvb::getCrrcMvb()->getBool(0x610,31,7);//检测变量1

}
