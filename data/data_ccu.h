#ifndef DATA_CCU_H
#define DATA_CCU_H
#include "qdatetime.h"
class Data_CCU
{
public:
    Data_CCU();
    void updateData();
    bool CCUOnline;
    QDateTime HMI_DateTime_foruse;
    //DDU-MPU
    //0x300
    ;bool	HEATING
    ;bool	NSC_START
    ;bool	NSC_END
    ;bool	AXLE2_MOVE
    ;bool	Z_ZSEC
    ;bool	DADMAN_ALARM
    ;bool	SANDING
    ;bool	RACING
    ;bool	SLIP
    ;bool	SPEED_CTL
    ;bool	PENALTY_BRK
    ;bool	SIM_MODE
    ;bool	QS_GHV
    ;bool	DEPOT_SIM
    ;bool	DEPOT_MOVE
    ;bool	LEAD
    ;bool	TRAIL
    ;bool	PSG_CUT_IN
    ;bool	FREIGHT_CUT_IN
    ;bool	CUT_OUT
    ;bool	NORMAL_MODE
    ;bool	SUMMER_MODE
    ;bool	STATE_T_CHAR
    ;bool	STATE_FORWARD
    ;bool	STATE_BACK
    ;bool	STATE_NEUTRAL
    ;bool	DJ_QUAI
    ;bool	Q_PP_QUAI
    ;bool	C_QUAI
    ;bool	C_PC_QUAI
    ;bool	C_IS_QUAI
    ;bool	NSC_DISTANCE1
    ;bool	NSC_DISTANCE2
    ;bool	DOUBLE_PG
    ;bool	STATE_PANTO_DN
    ;bool	STATE_PANTO_RG
    ;bool	STATE_PANTO_RD
    ;bool	STATE_PANTO_ISO
    ;bool	STATE_CAB_ACTIVE
    ;bool	SAND_CUT
    ;bool	ELEC_AIR_CUT
    ;bool	CAB_CHANGE_START
    ;bool	STATE_QFM_ON
    ;bool	STATE_QFM_ON_2
    ;bool	STATE_QFM_K
    ;bool	STATE_QFM_OFF
    ;bool	STATE_QFM_ISO
    ;bool	P710CHECK0
    ;bool	P710CHECK1
    ;bool	MPU1_ONLINE
    ;bool	MPU2_ONLINE
    ;bool	ACU1_ONLINE
    ;bool	ACU2_ONLINE
    ;bool	TCU1_ONLINE
    ;bool	TCU2_ONLINE
    ;bool	TCU3_ONLINE
    ;bool	TCU4_ONLINE
    ;bool	BCU_ONLINE
    ;bool	DDU_ONLINE
    ;bool	RIOM1_ONLINE
    ;bool	RIOM2_ONLINE
    ;bool	UIC_GW1_ONLINE
    ;bool	UIC_GW2_ONLINE
    ;bool	GW3_ONLINE
    ;bool	ONLINE6A;
    ;bool	CUR_MPU1
    ;bool	CUR_MPU2
    ;bool	BCV1_KM_WORK1
    ;bool	BCV1_KM_WORK2
    ;bool	BCV2_KM_WORK1
    ;bool	BCV2_KM_WORK2
    ;bool	BCV1_KM_PC1
    ;bool	BCV1_KM_PC2
    ;bool	BCV2_KM_PC1
    ;bool	BCV2_KM_PC2
    ;bool	P711CHECK0
    ;bool	P711CHECK1
    ;bool	TCMS_FAULT121
    ;bool	TCMS_FAULT122
    ;bool	TCMS_FAULT123
    ;bool	TCMS_FAULT124
    ;bool	TCMS_FAULT125
    ;bool	TCMS_FAULT126
    ;bool	TCMS_FAULT127
    ;bool	TCMS_FAULT128
    ;bool	TCMS_FAULT129
    ;bool	TCMS_FAULT130
    ;bool	TCMS_FAULT131
    ;bool	TCMS_FAULT132
    ;bool	TCMS_FAULT133
    ;bool	TCMS_FAULT134
    ;bool	TCMS_FAULT135
    ;bool	TCMS_FAULT136
    ;bool	TCMS_FAULT137
    ;bool	TCMS_FAULT138
    ;bool	TCMS_FAULT139
    ;bool	TCMS_FAULT140
    ;bool	TCMS_FAULT141
    ;bool	TCMS_FAULT142
    ;bool	TCMS_FAULT143
    ;bool	TCMS_FAULT144
    ;bool	TCMS_FAULT145
    ;bool	TCMS_FAULT146
    ;bool	TCMS_FAULT147
    ;bool	TCMS_FAULT148
    ;bool	TCMS_FAULT149
    ;bool	TCMS_FAULT150
    ;bool	TCMS_FAULT151
    ;bool	TCMS_FAULT152
    ;bool	P712CHECK0
    ;bool	P712CHECK1
    ;bool	MODE_ATO
    ;bool	P713CHECK0
    ;bool	P713CHECK1;

    unsigned short int	LINE_VOLT
    ;unsigned short int	BAT_VOLT
    ;unsigned short int	PRIM_C
    ;unsigned short int	MSCT_GRD
    ;unsigned short int	PARTNER_ID
    ;unsigned short int	TE_AXLE_SET
    ;unsigned short int	TEBE_EFFORT
    ;unsigned short int	SET_SPEED
    ;unsigned short int	ACTUAL_SPEED
    ;unsigned short int	BAT_TMP
    ;unsigned short int	FLL_DIS_STRAIGHT
    ;unsigned short int	FLL_SECONDS
    ;unsigned short int	WHEEL_DIA
    ;unsigned short int	LOAD
    ;unsigned short int	TE_AXLE1_ACTUAL
    ;unsigned short int	TE_AXLE2_ACTUAL
    ;unsigned short int	TE_AXLE3_ACTUAL
    ;unsigned short int	TE_AXLE4_ACTUAL
    ;unsigned short int	SPD_AXLE1
    ;unsigned short int	SPD_AXLE2
    ;unsigned short int	SPD_AXLE3
    ;unsigned short int	SPD_AXLE4
    ;unsigned short int	YEAR
    ;unsigned short int	MSCT_GRD_ATO;

    ;unsigned int	MCB_ON_COUNTER
    ;unsigned int	TRIP_COUNTER
    ;unsigned int	TOTAL_DISTANCE
    ;unsigned int	CPR_RUN_TIME;
    unsigned char OTHERUIC_ADDR;
    ;unsigned char	UIC_ADDR
    ;unsigned char	AUX1_FREQ
    ;unsigned char	AUX2_FREQ
    ;unsigned char	MPU_LIFE
    ;unsigned char	RULOCO_NO
    ;unsigned char	MCB_OFF_CODE
    ;unsigned char	FLL_TIME
    ;unsigned char	MONTH
    ;unsigned char	DATE
    ;unsigned char	HOUR
    ;unsigned char	MINUTE
    ;unsigned char	SECOND
    ;unsigned char	DADMAN_TIME
    ;unsigned char	DEVICE_NO
    ;unsigned char	VERSION_X
    ;unsigned char	VERSION_Y
    ;unsigned char	VERSION_Z
    ;unsigned char	DADMAN_TIMESPACE
    ;unsigned char	DADMAN_ALARMTIME;


    //DDU-MPU
    ;bool	TC4_BOGIE1_ISO_RQ
    ;bool	TC4_4Q1_ISO_RQ
    ;bool	TC4_4Q2_ISO_RQ
    ;bool	TC4_AXLE1_ISO_RQ
    ;bool	TC4_AXLE2_ISO_RQ
    ;bool	TC4_AUX1_ISO_RQ
    ;bool	TC4_BOGIE2_ISO_RQ
    ;bool	TC4_4Q3_ISO_RQ
    ;bool	TC4_4Q4_ISO_RQ
    ;bool	TC4_AXLE3_ISO_RQ
    ;bool	TC4_AXLE4_ISO_RQ
    ;bool	TC4_AUX2_ISO_RQ
    ;bool	TC4_DAMAN_ISO_RQ
    ;bool	TC4_EBRK_ISO_RQ
    ;bool	TC4_CPR_ISO_RQ
    ;bool	TC4_FLL_ISO_RQ
    ;bool	TC4_BOGIE1_ISO_REL_RQ
    ;bool	TC4_4Q1_ISO_REL_RQ
    ;bool	TC4_4Q2_ISO_REL_RQ
    ;bool	TC4_AXLE1_ISO_REL_RQ
    ;bool	TC4_AXLE2_ISO_REL_RQ
    ;bool	TC4_AUX1_ISO_REL_RQ
    ;bool	TC4_BOGIE2_ISO_REL_RQ
    ;bool	TC4_4Q3_ISO_REL_RQ
    ;bool	TC4_4Q4_ISO_REL_RQ
    ;bool	TC4_AXLE3_ISO_REL_RQ
    ;bool	TC4_AXLE4_ISO_REL_RQ
    ;bool	TC4_AUX2_ISO_REL_RQ
    ;bool	TC4_DAMAN_ISO_REL_RQ
    ;bool	TC4_EBRK_ISO_REL_RQ
    ;bool	TC4_CPR_ISO_REL_RQ
    ;bool	TC4_FLL_ISO_REL_RQ
    ;bool	TC1_BOGIE1_ISO_RQ
    ;bool	TC1_4Q1_ISO_RQ
    ;bool	TC1_4Q2_ISO_RQ
    ;bool	TC1_AXLE1_ISO_RQ
    ;bool	TC1_AXLE2_ISO_RQ
    ;bool	TC1_AUX1_ISO_RQ
    ;bool	TC1_BOGIE2_ISO_RQ
    ;bool	TC1_4Q3_ISO_RQ
    ;bool	TC1_4Q4_ISO_RQ
    ;bool	TC1_AXLE3_ISO_RQ
    ;bool	TC1_AXLE4_ISO_RQ
    ;bool	TC1_AUX2_ISO_RQ
    ;bool	TC1_DAMAN_ISO_RQ
    ;bool	TC1_EBRK_ISO_RQ
    ;bool	TC1_CPR_ISO_RQ
    ;bool	TC1_FLL_ISO_RQ
    ;bool	TC1_BOGIE1_ISO_REL_RQ
    ;bool	TC1_4Q1_ISO_REL_RQ
    ;bool	TC1_4Q2_ISO_REL_RQ
    ;bool	TC1_AXLE1_ISO_REL_RQ
    ;bool	TC1_AXLE2_ISO_REL_RQ
    ;bool	TC1_AUX1_ISO_REL_RQ
    ;bool	TC1_BOGIE2_ISO_REL_RQ
    ;bool	TC1_4Q3_ISO_REL_RQ
    ;bool	TC1_4Q4_ISO_REL_RQ
    ;bool	TC1_AXLE3_ISO_REL_RQ
    ;bool	TC1_AXLE4_ISO_REL_RQ
    ;bool	TC1_AUX2_ISO_REL_RQ
    ;bool	TC1_DAMAN_ISO_REL_RQ
    ;bool	TC1_EBRK_ISO_REL_RQ
    ;bool	TC1_CPR_ISO_REL_RQ
    ;bool	TC1_FLL_ISO_REL_RQ
    ;bool	TC2_BOGIE1_ISO_RQ
    ;bool	TC2_4Q1_ISO_RQ
    ;bool	TC2_4Q2_ISO_RQ
    ;bool	TC2_AXLE1_ISO_RQ
    ;bool	TC2_AXLE2_ISO_RQ
    ;bool	TC2_AUX1_ISO_RQ
    ;bool	TC2_BOGIE2_ISO_RQ
    ;bool	TC2_4Q3_ISO_RQ
    ;bool	TC2_4Q4_ISO_RQ
    ;bool	TC2_AXLE3_ISO_RQ
    ;bool	TC2_AXLE4_ISO_RQ
    ;bool	TC2_AUX2_ISO_RQ
    ;bool	TC2_DAMAN_ISO_RQ
    ;bool	TC2_EBRK_ISO_RQ
    ;bool	TC2_CPR_ISO_RQ
    ;bool	TC2_FLL_ISO_RQ
    ;bool	TC2_BOGIE1_ISO_REL_RQ
    ;bool	TC2_4Q1_ISO_REL_RQ
    ;bool	TC2_4Q2_ISO_REL_RQ
    ;bool	TC2_AXLE1_ISO_REL_RQ
    ;bool	TC2_AXLE2_ISO_REL_RQ
    ;bool	TC2_AUX1_ISO_REL_RQ
    ;bool	TC2_BOGIE2_ISO_REL_RQ
    ;bool	TC2_4Q3_ISO_REL_RQ
    ;bool	TC2_4Q4_ISO_REL_RQ
    ;bool	TC2_AXLE3_ISO_REL_RQ
    ;bool	TC2_AXLE4_ISO_REL_RQ
    ;bool	TC2_AUX2_ISO_REL_RQ
    ;bool	TC2_DAMAN_ISO_REL_RQ
    ;bool	TC2_EBRK_ISO_REL_RQ
    ;bool	TC2_CPR_ISO_REL_RQ
    ;bool	TC2_FLL_ISO_REL_RQ
    ;bool	TC3_BOGIE1_ISO_RQ
    ;bool	TC3_4Q1_ISO_RQ
    ;bool	TC3_4Q2_ISO_RQ
    ;bool	TC3_AXLE1_ISO_RQ
    ;bool	TC3_AXLE2_ISO_RQ
    ;bool	TC3_AUX1_ISO_RQ
    ;bool	TC3_BOGIE2_ISO_RQ
    ;bool	TC3_4Q3_ISO_RQ
    ;bool	TC3_4Q4_ISO_RQ
    ;bool	TC3_AXLE3_ISO_RQ
    ;bool	TC3_AXLE4_ISO_RQ
    ;bool	TC3_AUX2_ISO_RQ
    ;bool	TC3_DAMAN_ISO_RQ
    ;bool	TC3_EBRK_ISO_RQ
    ;bool	TC3_CPR_ISO_RQ
    ;bool	TC3_FLL_ISO_RQ
    ;bool	TC3_BOGIE1_ISO_REL_RQ
    ;bool	TC3_4Q1_ISO_REL_RQ
    ;bool	TC3_4Q2_ISO_REL_RQ
    ;bool	TC3_AXLE1_ISO_REL_RQ
    ;bool	TC3_AXLE2_ISO_REL_RQ
    ;bool	TC3_AUX1_ISO_REL_RQ
    ;bool	TC3_BOGIE2_ISO_REL_RQ
    ;bool	TC3_4Q3_ISO_REL_RQ
    ;bool	TC3_4Q4_ISO_REL_RQ
    ;bool	TC3_AXLE3_ISO_REL_RQ
    ;bool	TC3_AXLE4_ISO_REL_RQ
    ;bool	TC3_AUX2_ISO_REL_RQ
    ;bool	TC3_DAMAN_ISO_REL_RQ
    ;bool	TC3_EBRK_ISO_REL_RQ
    ;bool	TC3_CPR_ISO_REL_RQ
    ;bool	TC3_FLL_ISO_REL_RQ
    ;bool	TC1_PANTO_ISO_RQ
    ;bool	TC1_PANTO_ISO_REL_RQ
    ;bool	SIM_ON
    ;bool	TC4_FAULT_RESET
    ;bool	MILEAGE_RESET
    ;bool	TC2_PANTO_ISO_RQ
    ;bool	TC2_PANTO_ISO_REL_RQ
    ;bool	TC1_FAULT_RESET
    ;bool	TC2_FAULT_RESET
    ;bool	TC3_FAULT_RESET
    ;bool	TC3_PANTO_ISO_RQ
    ;bool	TC3_PANTO_ISO_REL_RQ
    ;bool	LAMP_TEST
    ;bool	DAMAN_TEST
    ;bool	FLL_TEST_START
    ;bool	FLL_TEST_CANCEL
    ;bool	CPR_TEST
    ;bool	ANSC_TEST
    ;bool	TC4_PANTO_ISO_RQ
    ;bool	TC4_PANTO_ISO_REL_RQ
    ;bool	DEPOT_380_ACT
    ;bool	DEPOT_380_DEACT
    ;bool	SEQUENCE_TEST
    ;bool	SAND_CUTDDU
    ;bool	ELEC_AIR_CUTDDU
    ;bool	LOAD_SET
    ;bool	FIR_ALARM_CONFIRM
    ;bool	P300CHECK0
    ;bool	P300CHECK1
    ;bool	WHEEL_DIA_SET
    ;bool	FLL_SET
    ;bool	TIME_SET
    ;bool	ID_SET
    ;bool	DADMAN_SET
    ;bool	NSC_DISTANCE1DDU
    ;bool	NSC_DISTANCE2DDU
    ;bool	NSC_SET
    ;bool	NORMAL_MODEDDU
    ;bool	SUMMER_MODEDDU
    ;bool	T_CHAR
    ;bool	DOUBLE_PG_ON
    ;bool	DOUBLE_PG_OFF
    ;bool	VT_BM1_ST
    ;bool	VT_BM2_ST
    ;bool	VT_MT1_ST
    ;bool	VT_MT2_ST
    ;bool	VT_SM1_ST
    ;bool	VT_SM2_ST
    ;bool	P301CHECK0
    ;bool	P301CHECK1
    ;bool	P302CHECK0
    ;bool	P302CHECK1;

    ;unsigned short int	SPEED_SET
    ;unsigned short int	SIM_LINE_VOLT
    ;unsigned short int	SIM_SPEED
    ;unsigned short int	LOADDDU
    ;unsigned short int	LOCO_ID
    ;unsigned short int	PARTNER_IDDDU
    ;unsigned short int	YEARDDU
    ;unsigned short int	WHEEL_DIADDU
    ;unsigned short int	FLL_DIS;

    ;unsigned char	DDU_LIFE
    ;unsigned char	MONTHDDU
    ;unsigned char	DAYDDU
    ;unsigned char	HOURDDU
    ;unsigned char	MINUTEDDU
    ;unsigned char	SECONDDDU
    ;unsigned char	FLL_TIMEDDU
    ;unsigned char	DADMAN_TIMESPACEDDU
    ;unsigned char	DADMAN_TIMEALARM
    ;unsigned char	DDU_VX
    ;unsigned char	DDU_VY;

    bool CheckLifesignal(unsigned char lifeSignal);

};

#endif // DATA_CCU_H
