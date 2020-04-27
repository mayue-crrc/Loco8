#ifndef DATA_BCU_H
#define DATA_BCU_H


class Data_BCU
{
public:
    Data_BCU();
    void updateData();

    ;bool    B_BC2_Valid
    ;bool    B_BRAKE_BACK
    ;bool    B_DBI1_FEEDBACK
    ;bool    B_DBI2_FEEDBACK
    ;bool    B_FREIGHT_PASSENGER
    ;bool    B_BP_Valid
    ;bool    B_MR_Valid
    ;bool    B_ER_Valid
    ;bool    B_BC1_Valid
    ;bool    B_E_BRAKE_Valid
    ;bool    B_BCU_Penalty_ACT
    ;bool    B_CAB_STATE
    ;bool    B_CAB2_STATE
    ;bool    B_BCU_STATE1
    ;bool    B_BCU_STATE2
    ;bool    B_BCU_EB_ACT
    ;bool    B_LOCO_EBRAKE_ACT
    ;bool    B_ATP_Penalty_ACT
    ;bool    B_TRA_BLK_ACT
    ;bool    B_Bail_ACT
    ;bool    B_Bail_NULL
    ;bool    B_ABH_RUN
    ;bool    B_ABH_MIN
    ;bool    B_ABH_SERV_Z
    ;bool    B_ABH_FULL_SERV
    ;bool    B_ABH_SUPPRESS
    ;bool    B_ABH_MU
    ;bool    B_ABH_EMG
    ;bool    B_AIH_RUN
    ;bool    B_AIH_SERV_Z
    ;bool    B_AIH_FULL_SERV
    ;bool    B_BCU_FAULT1
    ;bool    B_BCU_FAULT2
    ;bool    B_BCU_FAULT3
    ;bool    B_BCU_FAULT4
    ;bool    B_BCU_FAULT5
    ;bool    B_BCU_FAULT6
    ;bool    B_BCU_FAULT7
    ;bool    B_BCU_FAULT8
    ;bool    B_BCU_FAULT9
    ;bool    B_BCU_FAULT10
    ;bool    B_BCU_FAULT11
    ;bool    B_BCU_FAULT12
    ;bool    B_BCU_FAULT13
    ;bool    B_BCU_FAULT14
    ;bool    B_BCU_FAULT15
    ;bool    B_BCU_FAULT16
    ;bool    B_BCU_FAULT17
    ;bool    B_BCU_FAULT18
    ;bool    B_BCU_FAULT19
    ;bool    B_BCU_FAULT20
    ;bool    B_BCU_FAULT21
    ;bool    B_BCU_FAULT22
    ;bool    B_BCU_FAULT23
    ;bool    B_BCU_FAULT24
    ;bool    B_BCU_FAULT25
    ;bool    B_BCU_FAULT26
    ;bool    B_BCU_FAULT27
    ;bool    B_BCU_FAULT28;

    unsigned short int N_BP_PRES
    ;unsigned short int N_MR_PRES
    ;unsigned short int N_ER_PRES
    ;unsigned short int N_BC1_PRES
    ;unsigned short int N_EBRAKE
    ;unsigned short int N_FLOW
    ;unsigned short int N_BC2_PRES
    ;unsigned short int N_Version
    ;unsigned short int N_RCR;
    unsigned char 	N_BCU_ID;
    unsigned char 	N_BCU_LIFE;

};

#endif // DATA_BCU_H
