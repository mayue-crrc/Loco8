#ifndef DATABASE_H
#define DATABASE_H
#include "MainGetDefaultPara.h"
#include <QList>
#include <QDateTime>
#include "global.h"
#include "data/data_ccu.h"
#include "data/data_tcn.h"

class Database
{
public:
    Database();
    int HMIPosition;
    void getHMISourceSinkPost(QList<unsigned short int> &ports);
    void updateData();
    Data_CCU* data_CCU;
    Data_TCN* data_TCN;

private:
    QList<unsigned short int> HMISourceSinkPorts;

};

#endif // DATABASE_H
