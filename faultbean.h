#ifndef FAULTBEAN_H
#define FAULTBEAN_H

#include "QString"
enum Directions{
    forward = 1,
    backword,
    zero,
    nullp
};
class FaultBean
{
public:
    FaultBean();
public:
    int ID;
    QString StartTime;
    QString EndTime;
    int HistoryID;
    bool IsConfirm;

    float Speed;
    float Voltage;
    float Current;
    unsigned char Direction;
    float Grade;

};

#endif // FAULTBEAN_H
