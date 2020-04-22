#include "database.h"

Database::Database()
{
    HMIPosition = MainGetDefaultPara::getInt("/Position/HMI");

    data_CCU = new Data_CCU();

}
void Database::getHMISourceSinkPost(QList<unsigned short int> &ports)
{
    //0~3 source ports 4~7 sink ports
    this->HMISourceSinkPorts = ports;
}
void Database::updateData()
{
    data_CCU->updateData();
}
