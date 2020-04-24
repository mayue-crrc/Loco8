#ifndef DATA_ACU_H
#define DATA_ACU_H

#include "qlist.h"

class Data_ACU
{
public:
    Data_ACU();
    QList<int>  m_ports;
    void updateData();

    bool    M1_A2_B_ANDEL[2]
    ;bool    M1_A2_B_ANISA[2]
    ;bool    M1_A2_B_ANISB[2]
    ;bool    M1_A2_B_DEMCB[2]
    ;bool    M1_A2_B_DISCHB[2]
    ;bool    M1_A2_B_DISCVS[2]
    ;bool    M1_A2_B_DSCVS[2]
    ;bool    M1_A2_B_DTRDEF[2]
    ;bool    M1_A2_B_ISO_REL_RQ[2]
    ;bool    M1_A2_B_ETATMPU[2]
    ;bool    M1_A2_B_ETATTCU[2]
    ;bool    M1_A2_B_1800OK[2]

    ;bool    M1_A2_B_ANSC_ST[2]
    ;bool    M1_A2_B_ANSC_END[2]
    ;bool    M1_A2_B_ANSC_CMPLT[2]
    ;bool    M1_A2_B_AMCVS[2]
    ;bool    M1_A2_B_DELES[2]
    ;bool    M1_A2_B_INUL[2]


    ;bool    M1_A2_B_C1_CPR[2]
    ;bool    M1_A2_B_C2_CPR[2]
    ;bool    M1_A2_B_C3_CPR[2]


    ;bool    M1_A2_B_VT_BM1_ST[2]
    ;bool    M1_A2_B_VT_BM2_ST[2]
    ;bool    M1_A2_B_VT_MT1_ST[2]
    ;bool    M1_A2_B_VT_MT2_ST[2]
    ;bool    M1_A2_B_VT_SM1_ST[2]
    ;bool    M1_A2_B_VT_SM2_ST[2]
    ;bool    M1_A2_B_ACU_FALUT33[2]
    ;bool    M1_A2_B_ACU_FALUT34[2]
    ;bool    M1_A2_B_ACU_FALUT35[2]
    ;bool    M1_A2_B_ACU_FALUT36[2]
    ;bool    M1_A2_B_4Q2_FAULT2[2]
    ;bool    M1_A2_B_4Q3_FAULT2[2]
    ;bool    M1_A2_B_DJ_VT_SM1[2]
    ;bool    M1_A2_B_DJ_VT_SM2[2]
    ;bool    M1_A2_B_Q_TH_VT_BM1[2]
    ;bool    M1_A2_B_Q_TH_VT_BM2[2]
    ;bool    M1_A2_B_Q_TH_VT_MT1[2]
    ;bool    M1_A2_B_Q_TH_VT_MT2[2]




    ;bool    M1_A2_B_P110CHECK0[2]
    ;bool    M1_A2_B_P110CHECK1[2];

    unsigned short int M1_A2_N_DT_YEAR[2];
    unsigned char	M1_A2_N_MPU_LIFE[2]
    ;unsigned char	M1_A2_N_DT_MONTH[2]
    ;unsigned char	M1_A2_N_DT_DAY[2]
    ;unsigned char	M1_A2_N_DT_HOUR[2]
    ;unsigned char	M1_A2_N_DT_MINUTE[2]
    ;unsigned char	M1_A2_N_DT_SECOND[2]
    ;unsigned char	M1_A2_N_FVT[2]
    ;unsigned char	M1_A2_N_MQUAIT[2]
    ;unsigned char	M1_A2_N_DEPOT_MODE[2];
};

#endif // DATA_ACU_H
