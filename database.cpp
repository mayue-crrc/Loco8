#include "database.h"

Database::Database()
{
    HMIPosition = MainGetDefaultPara::getInt("/Position/HMI");

    data_CCU = new Data_CCU();
    data_TCN = new Data_TCN();
    data_RIOM = new Data_RIOM();
//    data_ATO = new Data_ATO();
//    data_ACU = new Data_ACU();
//    data_ERM = new Data_ERM();
    data_TCU = new Data_TCU();
//    data_BCU = new Data_BCU();
}
void Database::getHMISourceSinkPost(QList<unsigned short int> &ports)
{
    //0~3 source ports 4~7 sink ports
    this->HMISourceSinkPorts = ports;
}
void Database::updateData()
{
    data_CCU->updateData();
    data_TCN->updateData();
    data_RIOM->updateData();
//    data_ATO->updateData();
//    data_ACU->updateData();
//    data_ERM->updateData();
    data_TCU->updateData();
//    data_BCU->updateData();
}
