#ifndef DATA_ATO_H
#define DATA_ATO_H


class Data_ATO
{
public:
    Data_ATO();
    void updateData();

    bool	B_MSCT_T
    ;bool	B_MSCT_B
    ;bool	B_MODE_ATO
    ;bool	B_AUTOMODE_ACTIVE
    ;bool	B_AUTOMODE_EXIT
    ;bool	B_CAB1_ACTIVE
    ;bool	B_CAB2_ACTIVE
    ;bool	B_SAND_RQ1
    ;bool	B_ABH_RUN
    ;bool	B_ABH_MIN
    ;bool	B_ABH_SERV_Z
    ;bool	B_ABH_FULL_SERV
    ;bool	B_ABH_SUPPRESS
    ;bool	B_ABH_MU
    ;bool	B_ABH_EMG
    ;bool	B_AIH_RUN
    ;bool	B_AIH_SERV_Z
    ;bool	B_AIH_FULL_SERV
    ;bool	B_Bail_ACT
    ;bool	B_SAND_RQ2
    ;bool	B_PCHECK0
    ;bool	B_PCHECK1;

    unsigned short int 	N_MSCT_SAMPLE;
    unsigned short int	N_SPEED_SET;
    unsigned short int	B_BRAKE_ZIDONG;
    unsigned short int	B_BRAKE_DANDU;

    unsigned char	N_MODE_ATO;
    unsigned char	N_STATE;
    unsigned char	N_VERSION;
    unsigned char	N_LIFE_SELF;
    unsigned char	N_GW_VERSION;
    unsigned char	N_GW_LIFE;
};

#endif // DATA_ATO_H
