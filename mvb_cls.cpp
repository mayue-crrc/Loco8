#include "mvb_cls.h"
#ifndef     USER_DEBUG_MODE

#include <curses.h>
#endif
//#define MUE_APP_PRINT



//初始化mvb设备
MUE_RESULT c_mvbSock::MVB_Init()
{
    GF_RESULT  gf_result;
    UNSIGNED32 device_config = DEVICE_BASE_ADDR;
    GF_DEVICE_ERROR device_error;
    int time_out = 1000;
#ifndef     USER_DEBUG_MODE

    initial();
    do{
        gf_result = gf_open_device(&device_config, 0, &device_error);
        usleep(1000*10);
        //NOTE: timeout must be implemented
    } while ((gf_result != GF_OK) && ((time_out--)>0));

    gf_result = dev_init ();
#endif

    if(gf_result != LP_OK){
        qDebug("dev_init err = %d \n",gf_result);
    }

    if(time_out > 0 && gf_result == LP_OK){
		MVBisOpen = true;
        return MUE_RESULT_OK;
    }else{
		MVBisOpen = false;
        return MUE_RESULT_ERROR;
	}
}

void c_mvbSock::AddPortDaddrToMVB(UNSIGNED16 port, int size, INTEGER8 type, UNSIGNED16 cycle)
{
    static int clean_data_buf = 0;
#ifndef     USER_DEBUG_MODE

    if(clean_data_buf == 0){
        memset(PD_snk_port_address,0,sizeof(PD_snk_port_address));
        memset(PD_src_port_address,0,sizeof(PD_src_port_address));
        sink_port_num = 0;
        soure_port_num = 0;
        clean_data_buf = 1;
    }

    if(type == TS_PORT_SINK){
        PD_snk_port_address[sink_port_num] = port;
        PD_snk_port_size[sink_port_num] = size;
        if(sink_port_num >= PD_PORT_SNK_NO){
            return;
        }else {
                    sink_port_num++;
        }
    }else if(type == TS_PORT_SOURCE){
        PD_src_port_address[soure_port_num] = port;
        PD_src_port_size[soure_port_num] = size;
        if(soure_port_num >= PD_PORT_SRC_NO){
            return;
        }else{
            soure_port_num++;
        }
    }
#endif

}

void c_mvbSock::MVB_Set_Rev_Port(UNSIGNED16 port_addr)
{

}

void c_mvbSock::MVB_Set_Put_Port(UNSIGNED16 port_addr)
{

}
#ifdef DU_GENG
//初始化端口
MUE_RESULT c_mvbSock::MVB_init_port(void *p_bus_ctrl,UNSIGNED32 port_dir,UNSIGNED32 port_addr,UNSIGNED32 size)
{
    BITSET16    pd_port_config;
    MUE_RESULT  result = MUE_RESULT_OK;
    pd_port_config = (BITSET16)(port_addr | size | port_dir);
    //result = mue_app_init_port (p_bus_ctrl,  pd_port_config );

    if(result != MUE_RESULT_OK){
        return MUE_RESULT_ERROR;
    }
    return MUE_RESULT_OK;
}
#endif
//开始mvb工作
int c_mvbSock::MVB_Start()
{
    int res;
#ifndef     USER_DEBUG_MODE

       res = init_port();
       isStop = false;
#endif

       return res;
}

//通过mvb端口获取数据
UNSIGNED16 c_mvbSock::MVB_Get_Data(WORD16 port_addr,UNSIGNED8 *status,WORD8 *data,UNSIGNED16 *cycle)
{
    DS_NAME ds_name;
    LP_RESULT lp_result;
    memset(&ds_name,0,sizeof(ds_name));
    ds_name.ts_id = 0;
    ds_name.port_address = port_addr;

    if(isStop == true){
        return LP_ERROR;
    }
#ifndef     USER_DEBUG_MODE

    lp_result = lp_get_dataset(&ds_name,data,cycle);
    *status = (UNSIGNED8)lp_result;
#endif

    return lp_result;
}
//mvb发送数据
UNSIGNED16 c_mvbSock::MVB_Put_Data(WORD16 port_addr,WORD8 *data)
{
    DS_NAME ds_name;
    LP_RESULT lp_result;
    if(isStop == true)
        return LP_ERROR;
    ds_name.ts_id = 0;
    ds_name.port_address = port_addr;
#ifndef     USER_DEBUG_MODE

    lp_result = lp_put_dataset(&ds_name,data);
#endif

    return lp_result;
}

void c_mvbSock::_MVBClose()
{
#ifndef     USER_DEBUG_MODE
        isStop = true;
	gf_mvb_stop();
	gf_close_device();
#endif

}
