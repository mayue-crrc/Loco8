#ifndef MVB_CLS_H
#define MVB_CLS_H
// MVB Client API
#include "mvb_gf.h"
#include "mvb_lp.h"
#include "mvb_ap.h"
#include "mvb_md.h"
#include "mvb_dsw.h"
#include <QObject>
extern "C"{
#include "ss2xdd_2/ss2xdd_2.h"
}
typedef enum
{
    MUE_RESULT_OK                 = 0, /* correct termination         */
    MUE_RESULT_ERROR              = 1, /* unspecified error           */
    MUE_RESULT_INIT               = 2, /* error during initialisation */
    MUE_RESULT_CLOSE              = 3, /* error during close          */
    MUE_RESULT_CLEAN_UP           = 4, /* error during clean-up       */
    MUE_RESULT_TRANSMIT_ACCESS    = 5, /* transmit access  error      */
    MUE_RESULT_TRANSMIT_TIMEOUT   = 6, /* transmit timeout error      */
    MUE_RESULT_RECEIVE_ACCESS     = 7, /* receive  access  error      */
    MUE_RESULT_RECEIVE_TIMEOUT    = 8  /* receive  timeout error      */
}   MUE_RESULT;


class  c_mvbSock
{
public:
    void *p_bus_ctrl;
    bool MVBisOpen;
    bool isStop ;
    int soure_port_num;
    int sink_port_num;
    MUE_RESULT MVB_Init();
    void AddPortDaddrToMVB(UNSIGNED16 port, int size, INTEGER8 type, UNSIGNED16 cycle);
    void MVB_Set_Rev_Port(UNSIGNED16 port_addr);
    void MVB_Set_Put_Port(UNSIGNED16 port_addr);
    MUE_RESULT MVB_init_port(void *p_bus_ctrl,UNSIGNED32 port_dir,UNSIGNED32 port_addr,UNSIGNED32 size);
    int MVB_Start();
    UNSIGNED16 MVB_Get_Data(WORD16 port_addr,UNSIGNED8 *status,WORD8 *data,UNSIGNED16 *cycle);
    UNSIGNED16 MVB_Put_Data(WORD16 port_addr,WORD8 *data);
    void _MVBClose();
};
class M_MVBData
{
public:
    UNSIGNED16 No;
    bool MVBisOK;
};
#endif // MVB_CLS_H
