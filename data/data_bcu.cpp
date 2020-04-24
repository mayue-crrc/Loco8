#include "data_bcu.h"
#include "crrcmvb.h"
Data_BCU::Data_BCU()
{

}
void Data_BCU::updateData()
{
    B_BC2_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,13,0);//Signal State of B1_M1_N_BC2
    B_BRAKE_BACK = CrrcMvb::getCrrcMvb()->getBool(0x136,13,1);//
    B_DBI1_FEEDBACK = CrrcMvb::getCrrcMvb()->getBool(0x136,13,2);//
    B_DBI2_FEEDBACK = CrrcMvb::getCrrcMvb()->getBool(0x136,13,3);//
    B_FREIGHT_PASSENGER = CrrcMvb::getCrrcMvb()->getBool(0x136,13,4);//
    B_BP_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,16,0);//Signal State of B1_M1_N_BP
    B_MR_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,16,1);//Signal State of B1_M1_N_MR
    B_ER_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,16,2);//Signal State of B1_M1_N_ER
    B_BC1_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,16,3);//Signal State of B1_M1_N_BC1
    B_E_BRAKE_Valid = CrrcMvb::getCrrcMvb()->getBool(0x136,16,4);//Signal State of B1_M1_N_E_BRAKE
    B_BCU_Penalty_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,16,5);//Bit 5: BCU Penalty brake active.
    B_CAB_STATE = CrrcMvb::getCrrcMvb()->getBool(0x136,16,6);//Bit 6: Cab Active
    B_CAB2_STATE = CrrcMvb::getCrrcMvb()->getBool(0x136,16,7);//
    B_BCU_STATE1 = CrrcMvb::getCrrcMvb()->getBool(0x136,17,0);//Bit0, Bit1: BCU State
    B_BCU_STATE2 = CrrcMvb::getCrrcMvb()->getBool(0x136,17,1);//Bit0, Bit1: BCU State
    B_BCU_EB_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,17,2);//Bit 2: BCU emergency brake activated
    B_LOCO_EBRAKE_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,17,3);//
    B_ATP_Penalty_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,17,4);//Bit 4: ATP penalty brake activated
    B_TRA_BLK_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,17,5);//Bit 5: Traction Blocking active from BCU
    B_Bail_ACT = CrrcMvb::getCrrcMvb()->getBool(0x136,17,6);//Bit 6: Bail Activates
    B_Bail_NULL = CrrcMvb::getCrrcMvb()->getBool(0x136,17,7);//Bit 7: Bail has been nullified by CCB
    B_ABH_RUN = CrrcMvb::getCrrcMvb()->getBool(0x136,18,0);//BCUF_Run_Auto
    B_ABH_MIN = CrrcMvb::getCrrcMvb()->getBool(0x136,18,1);//BCUF_Min_Auto
    B_ABH_SERV_Z = CrrcMvb::getCrrcMvb()->getBool(0x136,18,2);//BCUF_Zoneservice_Auto
    B_ABH_FULL_SERV = CrrcMvb::getCrrcMvb()->getBool(0x136,18,3);//BCUF_Fullservice_Auto
    B_ABH_SUPPRESS = CrrcMvb::getCrrcMvb()->getBool(0x136,18,4);//BCUF_SUP_Auto
    B_ABH_MU = CrrcMvb::getCrrcMvb()->getBool(0x136,18,5);//BCUF_Muti_Auto
    B_ABH_EMG = CrrcMvb::getCrrcMvb()->getBool(0x136,18,6);//BCUF_Emergency_Auto
    B_AIH_RUN = CrrcMvb::getCrrcMvb()->getBool(0x136,19,0);//AIH_RUN
    B_AIH_SERV_Z = CrrcMvb::getCrrcMvb()->getBool(0x136,19,1);//AIH_SERV_Z
    B_AIH_FULL_SERV = CrrcMvb::getCrrcMvb()->getBool(0x136,19,2);//AIH_FULL_SERV
    B_BCU_FAULT1 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,0);//Fault in Eurotrol system
    B_BCU_FAULT2 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,1);//Eurotrol out of use
    B_BCU_FAULT3 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,2);//BP control out of use
    B_BCU_FAULT4 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,3);//Transducer MP Fault
    B_BCU_FAULT5 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,4);//Brake controller cabin 1 Fault
    B_BCU_FAULT6 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,5);//
    B_BCU_FAULT7 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,6);//Flow meeter Fault
    B_BCU_FAULT8 = CrrcMvb::getCrrcMvb()->getBool(0x136,24,7);//VE-Q(P)FR1 Fault
    B_BCU_FAULT9 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,0);//BP isolation Fault
    B_BCU_FAULT10 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,1);//VE-Q(P)FR Fault
    B_BCU_FAULT11 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,2);//Emergency FT valve Fault
    B_BCU_FAULT12 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,3);//Bail Off Fault
    B_BCU_FAULT13 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,4);//Back-up BP control Fault
    B_BCU_FAULT14 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,5);//EPM Distr Fault
    B_BCU_FAULT15 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,6);//Independent Brake Fault
    B_BCU_FAULT16 = CrrcMvb::getCrrcMvb()->getBool(0x136,25,7);//Locotrol Fault
    B_BCU_FAULT17 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,0);//Emergency Valves Defect
    B_BCU_FAULT18 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,1);//EQ Pipe control Fault
    B_BCU_FAULT19 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,2);//Lead/Trail Function Fault
    B_BCU_FAULT20 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,3);//Cylinder pressure transducer Fault
    B_BCU_FAULT21 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,4);//Brake Display Fault
    B_BCU_FAULT22 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,5);//Parking Brake Transducer Fault
    B_BCU_FAULT23 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,6);//BP Control Fault
    B_BCU_FAULT24 = CrrcMvb::getCrrcMvb()->getBool(0x136,26,7);//Can Bus Fault
    B_BCU_FAULT25 = CrrcMvb::getCrrcMvb()->getBool(0x136,27,0);//MP Transducer Fault
    B_BCU_FAULT26 = CrrcMvb::getCrrcMvb()->getBool(0x136,27,1);//BCU Start UP Fault
    B_BCU_FAULT27 = CrrcMvb::getCrrcMvb()->getBool(0x136,27,2);//MVB Communication Fault
    B_BCU_FAULT28 = CrrcMvb::getCrrcMvb()->getBool(0x136,27,3);//Maintain Function Fault

   N_BP_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,0);//BP Pressure
   N_MR_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,2);//MR Pressure
   N_ER_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,4);//ER Pressure
   N_BC1_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,6);//BC1 Pressure
   N_EBRAKE = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,8);//ED brake demand
   N_FLOW = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,10);//Indicate the flow in the CP
   N_BC2_PRES = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,14);//BC2 Pressure
   N_Version = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,20);//software version number
   N_RCR = CrrcMvb::getCrrcMvb()->getUnsignedInt(0x136,28);//CRC校验

   N_BCU_ID = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x136,12);//
   N_BCU_LIFE = CrrcMvb::getCrrcMvb()->getUnsignedChar(0x136,23);//UNSIGNED 8(Life signal) 生命信号



}
