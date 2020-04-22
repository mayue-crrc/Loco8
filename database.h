#ifndef DATABASE_H
#define DATABASE_H
#include "MainGetDefaultPara.h"
#include <QList>
#include <QDateTime>
#include "global.h"
#include "data/data_ccu.h"
class Database
{
public:
    Database();
    int HMIPosition;
    void getHMISourceSinkPost(QList<unsigned short int> &ports);
    void updateData();
    Data_CCU* data_CCU;
private:
    QList<unsigned short int> HMISourceSinkPorts;

};

#endif // DATABASE_H
