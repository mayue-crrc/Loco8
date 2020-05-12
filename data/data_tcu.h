#ifndef DATA_TCU_H
#define DATA_TCU_H
#include "qlist.h"

class Data_TCU
{
public:
    Data_TCU();
    void updateData();
     bool	AXLE_ISO_REL_ALLOW[4]
    ;bool	EBRK_ISO_REL_ALLOW[4]


    ;bool	INVT_SELT_TEST[4]
    ;bool	TCU_SELT_TEST[4]
    ;bool	ANTI_SLIP_SAND[4]
    ;bool	ANTI_RACING_SAND[4]
    ;bool	INVT_RUN[4]
    ;bool	KA_PC_OK[4]

    ;bool	Q4Q_OK[4]

    ;bool	KA_WORK_OK[4]

    ;bool	AXLE_DEGRADE[4]
    ;bool	AXLE_EBRK_ISO[4]
    ;bool	AXLE_ISO[4]
    ;bool	AXLE_EBRK_OK[4]
    ;bool	EBRK_ON[4]
    ;bool	ANSC_PR_OK[4]
    ;bool	ANSC_RE_OK[4]
    ;bool	CARB_PPC_OK[4]

    ;bool	NO_TB[4]
    ;bool	Q4Q_ISO[4]





    ;bool	T_CHAR[4]
    ;bool	Q4Q_FAULT1[4]
    ;bool	Q4Q_FAULT2[4]
    ;bool	Q4Q_FAULT3[4]
    ;bool	Q4Q_FAULT4[4]
    ;bool	Q4Q_FAULT5[4]
    ;bool	Q4Q_FAULT6[4]
    ;bool	Q4Q_FAULT7[4]
    ;bool	Q4Q_FAULT8[4]
    ;bool	Q4Q_FAULT9[4]
    ;bool	Q4Q_FAULT10[4]
    ;bool	Q4Q_FAULT11[4]
    ;bool	Q4Q_FAULT12[4]
    ;bool	Q4Q_FAULT13[4]
    ;bool	Q4Q_FAULT14[4]
    ;bool	Q4Q_FAULT15[4]
    ;bool	Q4Q_FAULT16[4]
    ;bool	Q4Q_FAULT17[4]
    ;bool	Q4Q_FAULT18[4]
    ;bool	Q4Q_FAULT19[4]
    ;bool	Q4Q_FAULT20[4]
    ;bool	Q4Q_FAULT21[4]
    ;bool	Q4Q_FAULT22[4]
    ;bool	Q4Q_FAULT23[4]
    ;bool	Q4Q_FAULT24[4]
    ;bool	Q4Q_FAULT25[4]
    ;bool	Q4Q_FAULT26[4]
    ;bool	Q4Q_FAULT27[4]
    ;bool	Q4Q_FAULT28[4]
    ;bool	Q4Q_FAULT29[4]
    ;bool	Q4Q_FAULT30[4]
    ;bool	Q4Q_FAULT31[4]
    ;bool	Q4Q_FAULT32[4]
    ;bool	INVT_FAULT1[4]
    ;bool	INVT_FAULT2[4]
    ;bool	INVT_FAULT3[4]
    ;bool	INVT_FAULT4[4]
    ;bool	INVT_FAULT5[4]
    ;bool	INVT_FAULT6[4]
    ;bool	INVT_FAULT7[4]
    ;bool	INVT_FAULT8[4]
    ;bool	INVT_FAULT9[4]
    ;bool	INVT_FAULT10[4]
    ;bool	INVT_FAULT11[4]
    ;bool	INVT_FAULT12[4]
    ;bool	INVT_FAULT13[4]
    ;bool	INVT_FAULT14[4]
    ;bool	INVT_FAULT15[4]
    ;bool	INVT_FAULT16[4]
    ;bool	INVT_FAULT17[4]
    ;bool	INVT_FAULT18[4]
    ;bool	INVT_FAULT19[4]
    ;bool	INVT_FAULT20[4]
    ;bool	INVT_FAULT21[4]
    ;bool	INVT_FAULT22[4]
    ;bool	INVT_FAULT23[4]
    ;bool	INVT_FAULT24[4]
    ;bool	INVT_FAULT25[4]
    ;bool	INVT_FAULT26[4]
    ;bool	INVT_FAULT27[4]
    ;bool	INVT_FAULT28[4]
    ;bool	INVT_FAULT29[4]
    ;bool	INVT_FAULT30[4]
    ;bool	INVT_FAULT31[4]
    ;bool	INVT_FAULT32[4]
    ;bool	RLD[4]
    ;bool	LAT[4]
    ;bool	P400CHECK0[4]
    ;bool	P400CHECK1[4]
    ;bool	P401CHECK0[4]
    ;bool	P401CHECK1[4];
    signed short int	MOT_TEMP[4];
    signed short int	AXLE_FORCE[4];

    unsigned short int	Q4Q_IN_V[4];
    unsigned short int	Q4Q_IN_C[4];
    unsigned short int	INVT_IN_V[4];
    unsigned short int	INVT_OUT_V[4];
    unsigned short int	INVT_OUT_C[4];
    unsigned short int	MOT_FREQ[4];
    unsigned short int	NET_VOLT_SENS[4];
    unsigned short int	SPEED[4];
    unsigned short int	WATER_PRESS[4];
    unsigned short int	WATER_TEMP[4];
    unsigned short int	TCU1_PulseBlock[4];

    unsigned char	TCU_LIFE[4];
    unsigned char	GW_VER[4];
    unsigned char	Q4Q_VER[4];
    unsigned char	INVT_VER[4];
    unsigned char	BAK_VER[4];
    unsigned char	Q4Q_LIFE[4];
    unsigned char	INVT_LIFE[4];



     bool	AXLE1_ISO_RQ
    ;bool	AXLE2_ISO_RQ
    ;bool	AXLE3_ISO_RQ
    ;bool	AXLE4_ISO_RQ
    ;bool	AXLE1_ISO_REL_RQ
    ;bool	AXLE2_ISO_REL_RQ
    ;bool	AXLE3_ISO_REL_RQ
    ;bool	AXLE4_ISO_REL_RQ

    ;bool	MCNVT_UNLOAD
    ;bool	QFM_DIS
    ;bool	QFM_C
    ;bool	PANTO_R
    ;bool	CS_MODE
    ;bool	ANSC_ST
    ;bool	ANSC_END
    ;bool	ANSC_CMPLT
    ;bool	ANSC_FORCE_OFF

    ;bool	FAULT_RESET
    ;bool	AUX1_ISO
    ;bool	AUX2_ISO
    ;bool	EBRAKE
    ;bool	EMGBRK
    ;bool	AXLE1_EBRK_ISO_RQ
    ;bool	AXLE1_EBRK_REL_ISO_RQ
    ;bool	AXLE2_EBRK_ISO_RQ
    ;bool	AXLE2_EBRK_REL_ISO_RQ
    ;bool	AXLE3_EBRK_ISO_RQ
    ;bool	AXLE3_EBRK_REL_ISO_RQ
    ;bool	AXLE4_EBRK_ISO_RQ
    ;bool	AXLE4_EBRK_REL_ISO_RQ

    ;bool	SEQUENCE_TEST
    ;bool	H_HT
    ;bool	AXLE2_MOVE
    ;bool	T_CAHR;

    bool	Q4Q1_ISO_RQ
    ;bool	Q4Q2_ISO_RQ
    ;bool	Q4Q3_ISO_RQ
    ;bool	Q4Q4_ISO_RQ
    ;bool	Q4Q1_REL_ISO_RQ
    ;bool	Q4Q2_REL_ISO_RQ
    ;bool	Q4Q3_REL_ISO_RQ
    ;bool	Q4Q4_REL_ISO_RQ

    ;bool	P530CHECK0
    ;bool	P530CHECK1
    ;bool	DJ_PE1
    ;bool	DJ_PE2
    ;bool	DJ_PE3
    ;bool	DJ_PE4
    ;bool	DJ_PH1
    ;bool	DJ_PH2
    ;bool	DJ_VT_SM1
    ;bool	DJ_VT_SM2

    ;bool	P531CHECK0
    ;bool	P531CHECK1;
     unsigned short int	WHEEL_DIA_AXLE2
    ;unsigned short int	MSCT_GRD
    ;unsigned short int	CS_VALUE
    ;unsigned short int	LOAD
    ;unsigned short int	SPEEDCCU
    ;unsigned short int	NET_VOLT
    ;unsigned short int	DT_YEAR
    ;unsigned short int	ACU1_OUTP
    ;unsigned short int	ACU2_OUTP;

     unsigned char	CARB_MODE
    ;unsigned char	DIR_N
    ;unsigned char	DIR_B
    ;unsigned char	DIR_F
    ;unsigned char	MSCT_N
    ;unsigned char	IS_THIS_A
    ;unsigned char	MPU_LIFE
    ;unsigned char	DT_MONTH
    ;unsigned char	DT_DAY
    ;unsigned char	DT_HOUR
    ;unsigned char	DT_MINUTE
    ;unsigned char	DT_SECOND;
    QList<int>  m_ports;
};

#endif // DATA_TCU_H
