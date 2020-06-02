#include "crrcmvb.h"

#ifndef     USER_DEBUG_MODE
#include <curses.h>
#endif
#include "ss2xdd_2/ss2xdd_2.h"
#define CRRC_MVB_DEBUG_MODE

CrrcMvb::CrrcMvb()
{
}

CrrcMvb* CrrcMvb::crrcMvb = NULL;

CrrcMvb* CrrcMvb::getCrrcMvb()
{
    if (crrcMvb == NULL)
    {
        return crrcMvb = new CrrcMvb();
    }
    else
    {
        return crrcMvb;
    }
}
bool CrrcMvb::initializeMvb()
{
#ifndef     USER_DEBUG_MODE
    result = M_MVB.MVB_Init();//初始化
#endif
    if(M_MVB.MVBisOpen == false)
    {
        qDebug("Open MVB is Error");
        return false;
    }
    qDebug("dugon init ok");
}
bool CrrcMvb::InitReadPortData()
{
    M_MVB.MVB_Start();
    Msg.MVBisOK = true;
}
bool CrrcMvb::setMvbStop()
{
    //._MVBClose();
}

bool CrrcMvb::addPort(unsigned short port, FCode size, int type, unsigned short cycle)
{
    if (port > 0x0FFF && type != MVB_Virtual)
    {
        qDebug() << "port" << port << " is a invalid, please check it";

        return false;
    }

    int t_size;
    switch (size)
    {
        case MVB_FCode4:
        t_size = TS_PORT_SIZE_16;
        break;
        case MVB_FCode3:
        t_size = TS_PORT_SIZE_8;
        break;
        case MVB_FCode2:
        t_size = TS_PORT_SIZE_4;
        break;
        case MVB_FCode1:
        t_size = TS_PORT_SIZE_2;
        break;
        case MVB_FCode0:
        t_size = TS_PORT_SIZE_1;
        break;

    default:
        qDebug() << "the port is error"<< __FILE__ << __LINE__;;
        return false;
        break;
    }

    if (this->portData.contains(port) == false)
    {
        this->portData.insert(port, new crrc_port_data(cycle));
        this->portConfigure << new struct crrc_port(port, t_size, type, cycle);
        M_MVB.AddPortDaddrToMVB(port, t_size, type, cycle);
    }
    else{
        qDebug() << "the port has already been in the port list"<< __FILE__ << __LINE__;;
    }
}

bool CrrcMvb::addSourcePort(unsigned short port, enum FCode size, unsigned short cycle)
{
    return this->addPort(port, size, TS_PORT_SOURCE, cycle);
}

bool CrrcMvb::addSinkPort(unsigned short port, enum FCode size, unsigned short cycle)
{
    return this->addPort(port, size, TS_PORT_SINK, cycle);
}

bool CrrcMvb::addVirtualPort(unsigned short port, FCode size)
{
    return this->addPort(port, size, MVB_Virtual, 65535);
}

void CrrcMvb::synchronizeMvbData()
{


    foreach (struct crrc_port *pointer, this->portConfigure)
    {

        if (portData.contains(pointer->port) == false)
        {
            qDebug() << "there is not port" << pointer->port << "in the list, please add it before use";
        }

        if (MVB_Sink == pointer->type)
        {
#ifndef     USER_DEBUG_MODE
            result = M_MVB.MVB_Get_Data((WORD16)pointer->port,&portData[pointer->port]->status,portData[pointer->port]->data,&portData[pointer->port]->cycle);
#endif
            //检测读取是否成功
            if(result != LP_OK)
            {
                //qDebug(" Read Error code = %d \n",result);
                return;
            }else
            {
                printf("\n Read Port = %d OK,result = %d cycle = %d",pointer->port,portData[pointer->port]->status,portData[pointer->port]->cycle);
                for(int i = 0;i<32;i++){
                    printf(" %2x ",portData[pointer->port]->data[i]);
                }
		printf("\n");
            }

        }
        else if (MVB_Source == pointer->type)
        {
		static unsigned int i = 0;
		i++;	
		memcpy(portData[pointer->port]->data,&i,sizeof(unsigned int));
#ifndef USER_DEBUG_MODE
        result = M_MVB.MVB_Put_Data((WORD16)pointer->port,portData[pointer->port]->data);
#endif
            //检测写取是否成功
        if(result != LP_OK){
                qDebug("dugon Write Error");
                return;
            }else
            {
                qDebug("dugon Write OK");

            }
        }
    }
}


// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
// unsigned short int bitOffset: the bit offset in data stream
bool CrrcMvb::getBool(unsigned short int port, unsigned short int byteOffset, unsigned short int bitOffset)
{
    unsigned char *pointer = NULL, value = 0;

    if (this->portData.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            value = *(pointer + byteOffset - 1);
        }
        else
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            value = *(pointer + byteOffset + 1);
        }
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;

        return false;
    }

    if (bitOffset < 8)
    {
        value = value & (0x80 >> bitOffset);
    }
    else
    {
        qDebug() << "the bit offset is too long" << port;

        return false;
    }

    if (value == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
unsigned char CrrcMvb::getUnsignedChar(unsigned short int port, unsigned short int byteOffset)
{
    unsigned char *pointer = NULL, value = 0;

    if (this->portData.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            value = *(pointer + byteOffset - 1);
        }
        else
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            value = *(pointer + byteOffset + 1);
        }

        return value;
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
signed char CrrcMvb::getSignedChar(unsigned short int port, unsigned short int byteOffset)
{
    unsigned char *pointer = NULL;
    signed char value = 0;

    if (this->portData.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            value = *(signed char *)(pointer + byteOffset - 1);
        }
        else
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            value = *(signed char *)(pointer + byteOffset + 1);
        }

        return value;
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}
// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
unsigned short int CrrcMvb::getUnsignedInt(unsigned short int port, unsigned short int byteOffset)
{
    unsigned char *pointer = NULL;
    unsigned short int value = 0;

    if (this->portData.contains(port) && byteOffset < 31)
    {
        pointer = (unsigned char *)(this->portData[port]->data);
        value = *(unsigned short int *)(pointer + byteOffset);

        return value;
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
quint32 CrrcMvb::getUnsignedInt32(unsigned short int port, unsigned short int byteOffset)
{
    // unsigned char *pointer = NULL;
    // quint32 value = 0;

    if (this->portData.contains(port) && byteOffset < 29)
    {
        // pointer = (unsigned char *)(this->portData[port]->data);
        // value = *(quint32 *)(pointer + byteOffset);
        unsigned short int temp[2] = {0};

        temp[0] = this->getUnsignedInt(port, byteOffset + 2);
        temp[1] = this->getUnsignedInt(port, byteOffset);

        return *(quint32 *)temp;
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
qint32 CrrcMvb::getSignedInt32(unsigned short int port, unsigned short int byteOffset)
{
    // unsigned char *pointer = NULL;
    // qint32 value = 0;

    if (this->portData.contains(port) && byteOffset < 31)
    {
        // pointer = (unsigned char *)(this->portData[port]->data);
        // value = *(qint32 *)(pointer + byteOffset);
        unsigned short int temp[2] = {0};

        temp[0] = this->getUnsignedInt(port, byteOffset + 2);
        temp[1] = this->getUnsignedInt(port, byteOffset);

        return *(qint32 *)temp;
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
signed short int CrrcMvb::getSignedInt(unsigned short int port, unsigned short int byteOffset)
{
    unsigned char *pointer = NULL;
    signed short int value = 0;

    if (this->portData.contains(port) && byteOffset < 31)
    {
        pointer = (unsigned char *)(this->portData[port]->data);
        value = *(signed short int *)(pointer + byteOffset);

        return value;
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;

        return 0;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
// unsigned short int bitOffset: the bit offset in data stream
// bool signal: the signal would be sent on mvb bus
void CrrcMvb::setBool(unsigned short int port, unsigned short int byteOffset, unsigned short int bitOffset, bool signal)
{
    unsigned char *pointer = NULL;

    if (this->portData.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            pointer = pointer + byteOffset - 1;
        }
        else
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            pointer = pointer + byteOffset + 1;
        }
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;
        return ;
    }

    if (bitOffset > 8)
    {
        qDebug() << "the bit offset is too long" << port;

        return;
    }

    if (true == signal)
    {
        *pointer = *pointer | (0x80 >> bitOffset);
    }
    else
    {
        *pointer = *pointer & ~(0x80 >> bitOffset);
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
// unsigned char signal: the signal would be sent on mvb bus
void CrrcMvb::setUnsignedChar(unsigned short int port, unsigned short int byteOffset, unsigned char signal)
{
    unsigned char *pointer = NULL;

    if (this->portData.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            *(pointer + byteOffset - 1) = signal;
        }
        else
        {
            pointer = (unsigned char *)(this->portData[port]->data);
            *(pointer + byteOffset + 1) = signal;
        }
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;
        return ;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
// signed char signal: the signal would be sent on mvb bus
void CrrcMvb::setSignedChar(unsigned short int port, unsigned short int byteOffset, signed char signal)
{
    signed char *pointer = NULL;

    if (this->portData.contains(port) && byteOffset < 32)
    {
        // pixy is a little endian device
        if (byteOffset % 2 == 1)
        {
            pointer = (signed char *)(this->portData[port]->data);
            *(pointer + byteOffset - 1) = signal;
        }
        else
        {
            pointer = (signed char *)(this->portData[port]->data);
            *(pointer + byteOffset + 1) = signal;
        }
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;
        return ;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
// signed short int signal: the signal would be sent on mvb bus
void CrrcMvb::setUnsignedInt(unsigned short int port, unsigned short int byteOffset, unsigned short int signal)
{
    unsigned char *pointer = NULL;

    if (this->portData.contains(port) && byteOffset < 31)
    {
        pointer = (unsigned char *)(this->portData[port]->data);
        *(unsigned short int *)(pointer + byteOffset) = signal;
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;
        return ;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
// signed short int signal: the signal would be sent on mvb bus
void CrrcMvb::setSignedInt(unsigned short int port, unsigned short int byteOffset, signed short int signal)
{
    unsigned char *pointer = NULL;

    if (this->portData.contains(port) && byteOffset < 31)
    {
        pointer = (unsigned char *)(this->portData[port]->data);
        *(signed short int *)(pointer + byteOffset) = signal;
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;
        return ;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
// signed short int signal: the signal would be sent on mvb bus
void CrrcMvb::setSignedInt32(unsigned short int port, unsigned short int byteOffset, qint32 signal)
{
    // unsigned char *pointer = NULL;

    if (this->portData.contains(port) && byteOffset < 29)
    {
        // pointer = (unsigned char *)(this->portData[port]->data);
        // *(qint32 *)(pointer + byteOffset) = signal;
        this->setUnsignedInt(port, byteOffset, *((unsigned short int *)(&signal) + 1));
        this->setUnsignedInt(port, byteOffset + 2, *(unsigned short int *)(&signal));
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;
        return ;
    }
}

// paramerters
// unsigned short int port: the port in data stream
// unsigned short int byteOffset: the byte offset in data stream
// signed short int signal: the signal would be sent on mvb bus
void CrrcMvb::setUnsignedInt32(unsigned short int port, unsigned short int byteOffset, quint32 signal)
{
    // unsigned char *pointer = NULL;

    if (this->portData.contains(port) && byteOffset < 29)
    {
        // pointer = (unsigned char *)(this->portData[port]->data);
        // *(quint32 *)(pointer + byteOffset) = signal;
        this->setUnsignedInt(port, byteOffset, *((unsigned short int *)(&signal) + 1));
        this->setUnsignedInt(port, byteOffset + 2, *(unsigned short int *)(&signal));
    }
    else
    {
        qDebug() << "there no port in the databse or byte offset is too long" << port;
        return ;
    }
}

// no parameter
unsigned short int CrrcMvb::getPortSum()
{
    return this->portConfigure.size();
}

unsigned short int CrrcMvb::getPortCycle(unsigned short int port)
{
    if (this->portData.contains(port) == false)
    {
        qDebug() << "the port" << port << "is not in the list, please check it";

        return 65535;
    }
    else
    {
        return this->portData[port]->cycle;
    }
}

bool CrrcMvb::isPortTimeout(unsigned short int port)
{
    if (this->portData.contains(port) == false)
    {
        qDebug() << "the port" << port << "is not in the list, please check it";

        return false;
    }
    else
    {
        int res = 0;
        for(int i=0;i<this->portConfigure.size();i++)
        {
            if(this->portConfigure[i]->port == port)
            {
                res = i;
                break;
            }else
            {
                res = 0;
            }
        }

        return (this->portData[port]->cycle) > (this->portConfigure[res]->cycle) ? true:false;
    }
}

QString CrrcMvb::getVersion()
{
    return QString::number(_CRRC_MVB_VERSION);
}

bool CrrcMvb::getportexist(unsigned short port)
{
    if(this->portData.contains(port))
    {
        return true;
    }else
    {
        return false;
    }
}
QList<unsigned short int> CrrcMvb::getAllPorts()
{
    QList<unsigned short int> res;
    for(int i = 0;i<this->portConfigure.size();i++)
    {
        if(portConfigure.at(i)->type == MVB_Sink)
        {
            res.push_back(portConfigure.at(i)->port);
        }

    }
    return res;
}
void CrrcMvb::copyPort(unsigned short int sink, unsigned short int source)
{
    for (int i = 0; i < 32; i ++)
    {
        this->setUnsignedChar(sink, i, this->getUnsignedChar(source, i));
    }
}
