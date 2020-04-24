#ifndef DATABASE_H
#define DATABASE_H
#include "MainGetDefaultPara.h"
#include <QList>
#include <QDateTime>
#include "global.h"
#include "data/data_ccu.h"
#include "data/data_tcn.h"
#include "data/data_tcu.h"
#include "data/data_riom.h"
#include "data/data_acu.h"
#include "data/data_bcu.h"
class Database
{
public:
    Database();
    int HMIPosition;
    void getHMISourceSinkPost(QList<unsigned short int> &ports);
    void updateData();
    Data_CCU* data_CCU;
    Data_TCN* data_TCN;
    Data_TCU* data_TCU;
    Data_RIOM* data_RIOM;
    Data_ACU* data_ACU;
    Data_BCU* data_BCU;

private:
    QList<unsigned short int> HMISourceSinkPorts;

};

#endif // DATABASE_H
