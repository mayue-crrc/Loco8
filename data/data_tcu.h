#ifndef DATA_TCU_H
#define DATA_TCU_H
#include "qlist.h"

class Data_TCU
{
public:
    Data_TCU();
    void updateData();
    bool    T1_B_AXLE_ISO_REL_ALLOW[4]
    ;bool    T1_B_EBRK_ISO_REL_ALLOW[4]
    ;bool    T1_B_INVT_SELT_TEST[4]
    ;bool    T1_B_TCU_SELT_TEST[4]
    ;bool    T1_B_ANTI_SLIP_SAND[4]
    ;bool    T1_B_ANTI_RACING_SAND[4]
    ;bool    T1_B_INVT_RUN[4]
    ;bool    T1_B_KA_PC_OK[4]
    ;bool    T1_B_4Q_OK[4]
    ;bool    T1_B_KA_WORK_OK[4]
    ;bool    T1_B_AXLE_DEGRADE[4]
    ;bool    T1_B_AXLE_EBRK_ISO[4]
    ;bool    T1_B_AXLE_ISO[4]
    ;bool    T1_B_AXLE_EBRK_OK[4]
    ;bool    T1_B_EBRK_ON[4]
    ;bool    T1_B_ANSC_PR_OK[4]
    ;bool    T1_B_ANSC_RE_OK[4]
    ;bool    T1_B_CARB_PPC_OK[4]
    ;bool    T1_B_NO_TB[4]
    ;bool    T1_B_4Q_ISO[4]
    ;bool    T1_B_T_CHAR[4]
    ;bool    T1_B_4Q_FAULT1[4]
    ;bool    T1_B_4Q_FAULT2[4]
    ;bool    T1_B_4Q_FAULT3[4]
    ;bool    T1_B_4Q_FAULT4[4]
    ;bool    T1_B_4Q_FAULT5[4]
    ;bool    T1_B_4Q_FAULT6[4]
    ;bool    T1_B_4Q_FAULT7[4]
    ;bool    T1_B_4Q_FAULT8[4]
    ;bool    T1_B_4Q_FAULT9[4]
    ;bool    T1_B_4Q_FAULT10[4]
    ;bool    T1_B_4Q_FAULT11[4]
    ;bool    T1_B_4Q_FAULT12[4]
    ;bool    T1_B_4Q_FAULT13[4]
    ;bool    T1_B_4Q_FAULT14[4]
    ;bool    T1_B_4Q_FAULT15[4]
    ;bool    T1_B_4Q_FAULT16[4]
    ;bool    T1_B_4Q_FAULT17[4]
    ;bool    T1_B_4Q_FAULT18[4]
    ;bool    T1_B_4Q_FAULT19[4]
    ;bool    T1_B_4Q_FAULT20[4]
    ;bool    T1_B_4Q_FAULT21[4]
    ;bool    T1_B_4Q_FAULT22[4]
    ;bool    T1_B_4Q_FAULT23[4]
    ;bool    T1_B_4Q_FAULT24[4]
    ;bool    T1_B_4Q_FAULT25[4]
    ;bool    T1_B_4Q_FAULT26[4]
    ;bool    T1_B_4Q_FAULT27[4]
    ;bool    T1_B_4Q_FAULT28[4]
    ;bool    T1_B_4Q_FAULT29[4]
    ;bool    T1_B_4Q_FAULT30[4]
    ;bool    T1_B_4Q_FAULT31[4]
    ;bool    T1_B_4Q_FAULT32[4]
    ;bool    T1_B_INVT_FAULT1[4]
    ;bool    T1_B_INVT_FAULT2[4]
    ;bool    T1_B_INVT_FAULT3[4]
    ;bool    T1_B_INVT_FAULT4[4]
    ;bool    T1_B_INVT_FAULT5[4]
    ;bool    T1_B_INVT_FAULT6[4]
    ;bool    T1_B_INVT_FAULT7[4]
    ;bool    T1_B_INVT_FAULT8[4]
    ;bool    T1_B_INVT_FAULT9[4]
    ;bool    T1_B_INVT_FAULT10[4]
    ;bool    T1_B_INVT_FAULT11[4]
    ;bool    T1_B_INVT_FAULT12[4]
    ;bool    T1_B_INVT_FAULT13[4]
    ;bool    T1_B_INVT_FAULT14[4]
    ;bool    T1_B_INVT_FAULT15[4]
    ;bool    T1_B_INVT_FAULT16[4]
    ;bool    T1_B_INVT_FAULT17[4]
    ;bool    T1_B_INVT_FAULT18[4]
    ;bool    T1_B_INVT_FAULT19[4]
    ;bool    T1_B_INVT_FAULT20[4]
    ;bool    T1_B_INVT_FAULT21[4]
    ;bool    T1_B_INVT_FAULT22[4]
    ;bool    T1_B_INVT_FAULT23[4]
    ;bool    T1_B_INVT_FAULT24[4]
    ;bool    T1_B_INVT_FAULT25[4]
    ;bool    T1_B_INVT_FAULT26[4]
    ;bool    T1_B_INVT_FAULT27[4]
    ;bool    T1_B_INVT_FAULT28[4]
    ;bool    T1_B_INVT_FAULT29[4]
    ;bool    T1_B_INVT_FAULT30[4]
    ;bool    T1_B_INVT_FAULT31[4]
    ;bool    T1_B_INVT_FAULT32[4]
    ;bool    T1_B_P400CHECK0[4]
    ;bool    T1_B_P400CHECK1[4]
    ;bool    T1_B_P401CHECK0[4]
    ;bool    T1_B_P401CHECK1[4];
    bool    T1_B_RLD[4];
    bool    T1_B_LAT[4];

    signed short int T1_N_MOT_TEMP[4];
    signed short int T1_N_AXLE_FORCE[4];

    signed short int    T1_N_4Q_IN_V[4]
    ;signed short int    T1_N_4Q_IN_C[4]
    ;signed short int    T1_N_INVT_IN_V[4]
    ;signed short int    T1_N_INVT_OUT_V[4]
    ;signed short int    T1_N_INVT_OUT_C[4]
    ;signed short int    T1_N_MOT_FREQ[4]
    ;signed short int    T1_N_NET_VOLT_SENS[4]
    ;signed short int    T1_N_SPEED[4]
    ;signed short int    T1_N_WATER_PRESS[4]
    ;signed short int    T1_N_WATER_TEMP[4];

    unsigned char	T1_N_TCU_LIFE[4];
    unsigned char	T1_N_GW_VER[4];
    unsigned char	T1_N_4Q_VER[4];
    unsigned char	T1_N_INVT_VER[4];
    unsigned char	T1_N_BAK_VER[4];
    unsigned char	T1_N_4Q_LIFE[4];
    unsigned char	T1_N_INVT_LIFE[4];
    QList<int>  m_ports;
};

#endif // DATA_TCU_H
