#ifndef DATA_BCU_H
#define DATA_BCU_H


class Data_BCU
{
public:
    Data_BCU();
    void updateData();

    ;bool	BP_Valid
    ;bool	MR_Valid
    ;bool	ER_Valid
    ;bool	BC1_Valid
    ;bool	E_BRAKE_Valid
    ;bool	BCU_Penalty_ACT
    ;bool	CAB_STATE
    ;bool	BCU_STATE1
    ;bool	BCU_STATE2
    ;bool	BCU_EB_ACT
    ;bool	BC2_Valid
    ;bool	ATP_Penalty_ACT
    ;bool	TRA_BLK_ACT
    ;bool	Bail_ACT
    ;bool	Bail_NULL
    ;bool	STATE_DBI1
    ;bool	STATE_DBI2
    ;bool	ABC_MOVED
    ;bool	EMG_BRK_ISO
    ;bool	PARK_BRK_ISO
    ;bool	BRK_CYL_ISO
    ;bool	ABH_RUN
    ;bool	ABH_MIN
    ;bool	ABH_SERV_Z
    ;bool	ABH_FULL_SERV
    ;bool	ABH_SUPPRESS
    ;bool	ABH_MU
    ;bool	ABH_EMG
    ;bool	BCU_FAULT1
    ;bool	BCU_FAULT2
    ;bool	BCU_FAULT3
    ;bool	BCU_FAULT4
    ;bool	BCU_FAULT5
    ;bool	BCU_FAULT6
    ;bool	BCU_FAULT7
    ;bool	BCU_FAULT8
    ;bool	BCU_FAULT9
    ;bool	BCU_FAULT10
    ;bool	BCU_FAULT11
    ;bool	BCU_FAULT12
    ;bool	BCU_FAULT13
    ;bool	BCU_FAULT14
    ;bool	BCU_FAULT15
    ;bool	BCU_FAULT16
    ;bool	BCU_FAULT17
    ;bool	BCU_FAULT18
    ;bool	BCU_FAULT19
    ;bool	BCU_FAULT20
    ;bool	BCU_FAULT21
    ;bool	BCU_FAULT22
    ;bool	BCU_FAULT23
    ;bool	BCU_FAULT24
    ;bool	BCU_FAULT25
    ;bool	BCU_FAULT26
    ;bool	BCU_FAULT27
    ;bool	BCU_FAULT28
    ;bool	AIH_RUN
    ;bool	AIH_SERV_Z
    ;bool	AIH_FULL_SERV;
    ;unsigned short int	BP_PRES
    ;unsigned short int	MR_PRES
    ;unsigned short int	ER_PRES
    ;unsigned short int	BC1_PRES
    ;unsigned short int	BC2_PRES
    ;unsigned short int	EG_PRES
    ;unsigned short int	FLOW
    ;unsigned short int	EBRAKE
    ;unsigned short int	Version;
    unsigned char BCU_LIFE;

    ;bool	LocoSpeedValid

    ;bool	PenaltyBrakeRQ
    ;bool	EmerBrakeRQ
    ;bool	TRAIL
    ;bool	DBI1_RQ
    ;bool	DBI2_RQ
    ;bool	Cab_Act;

    unsigned char	LocoSpeed;
    unsigned char	MPU_LIFE;
    unsigned int DateTime;

};

#endif // DATA_BCU_H
