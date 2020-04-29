#ifndef DATA_TCN_H
#define DATA_TCN_H

#include "trainbean.h"
class Data_TCN
{
public:
    Data_TCN();
    void updateData();
    TrainBean* train[4],*TrainLocal;
private:
};

#endif // DATA_TCN_H
