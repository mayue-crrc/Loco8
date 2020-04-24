#ifndef DATA_ERM_H
#define DATA_ERM_H


class Data_ERM
{
public:
    Data_ERM();
    void updateData();
    unsigned char    LifeSign_U8;
    unsigned char    VerX_U8;
    unsigned char    VerY_U8;
    unsigned char    VerZ_U8;
    unsigned char    HWVerX_U8;
    unsigned char    HWVerY_U8;
    unsigned char    HWVerZ_U8;
    unsigned char    CycleTime;
    unsigned char    CycleCount;
    unsigned char    ERM_TimeCheck;

    bool	P610Check0;
    bool	P610Check1;


};

#endif // DATA_ERM_H
