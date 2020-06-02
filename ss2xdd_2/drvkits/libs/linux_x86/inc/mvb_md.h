#if !defined (_MVB_MD_H_)
#define _MVB_MD_H_

///////////////////////////////////////////////////////////////////////
// Include Files
///////////////////////////////////////////////////////////////////////

#include "mvb_def.h"

#ifdef O_MD

#if defined(__cplusplus)
extern "C"
{
#endif

///////////////////////////////////////////////////////////////////////
// General Definitions
///////////////////////////////////////////////////////////////////////

// Error Codes
#define AM_OK					0
#define AM_FAILURE				1
#define AM_BUS_ERR				2
#define AM_REM_CONN_OVF			3
#define AM_CONN_TMO_ERR			4
#define AM_SEND_TMO_ERR			5
#define AM_REPLY_TMO_ERR		6
#define AM_ALIVE_TMO_ERR		7
#define AM_NO_LOC_MEM_ERR		8
#define AM_NO_REM_MEM_ERR		9
#define AM_REM_CANC_ERR			10
#define AM_ALREADY_USED			11
#define AM_ADDR_FMT_ERR			12
#define AM_NO_REPLY_EXP_ERR		13
#define AM_NR_OF_CALLS_OVF		14
#define AM_REPLY_LEN_OVF		15
#define AM_DUPL_LINK_ERR		16
#define AM_MY_DEV_UNKNOWN_ERR	17
#define AM_NO_READY_INST_ERR	18
#define AM_NR_OF_INST_OVF		19
#define AM_CALL_LEN_OVF			20
#define AM_UNKNOWN_DEST_ERR		21
#define AM_INAUG_ERR			22
#define AM_TRY_LATER_ERR		23
#define AM_FIN_NOT_REG_ERR		24
#define AM_GW_FIN_NOT_REG_ERR	25  
#define AM_GW_ORI_NOT_REG_ERR	26
#define AM_REPEAT_TMO_ERR		27
#define AM_MAX_ERR				31

// Address Constants
#define AM_SAME_STATION		0
#define AM_UNKNOWN			255
#define AM_MAX_BUSSES		1
#define AM_ROUTER_FCT		251
#define AM_DIRECTORY_FCT	252
#define AM_AGENT_FCT		253
#define AM_MANAGER_FCT		254
#define AM_SAME_NODE		0
#define AM_SYSTEM_ADDR		128
#define AM_ANY_TOPO			0

///////////////////////////////////////////////////////////////////////
// Type Definitions
///////////////////////////////////////////////////////////////////////

typedef UNSIGNED8	AM_RESULT;

typedef struct
{
   UNSIGNED8 sg_node;
   UNSIGNED8 func_or_stat;
   UNSIGNED8 next_station;
   UNSIGNED8 topo_counter;
}  AM_ADDRESS;

typedef struct
{
   UNSIGNED8 function;
   UNSIGNED8 station;
}  AM_DIR_ENTRY;

typedef struct
{
   UNSIGNED8  station;
   UNSIGNED8  next_station;
   ENUM8      bus_id;
   ENUM8      dummy;
   UNSIGNED32 device_adr;
}  AM_STADI_ENTRY;

typedef void (*AM_CALL_CONFIRM)
(
   UNSIGNED8        caller_function,
   void             *am_caller_ref,
   const AM_ADDRESS *replier,
   void             *in_msg_adr,
   UNSIGNED32       in_msg_size,
   AM_RESULT        status
);

typedef void (*AM_RECEIVE_CONFIRM)
(
   UNSIGNED8        replier_function,
   const AM_ADDRESS *caller,
   void             *in_msg_adr,
   UNSIGNED32       in_msg_size,
   void             *replier_ref
);

typedef void (*AM_REPLY_CONFIRM)
(
   UNSIGNED8 replier_function,
   void      *replier_ref
);

///////////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////////

AM_RESULT FunctionDef
   am_init(void);

AM_RESULT FunctionDef
   am_announce_device(UNSIGNED16 max_call_number,
                      UNSIGNED16 max_inst_number,
                      UNSIGNED16 default_reply_timeout,
                      UNSIGNED8  my_credit);

AM_RESULT FunctionDef
   am_set_current_tc(UNSIGNED8 this_topo);

AM_RESULT FunctionDef
   am_stadi_write(const AM_STADI_ENTRY entries[],
                  UNSIGNED8            nr_of_entries);
AM_RESULT FunctionDef
   am_stadi_read(AM_STADI_ENTRY entries[],
                 UNSIGNED8      nr_of_entries);

AM_RESULT FunctionDef
   am_clear_dir(void);
AM_RESULT FunctionDef
   am_insert_dir_entries(AM_DIR_ENTRY *function_list,
                         UNSIGNED8    number_of_entries);
AM_RESULT FunctionDef
   am_remove_dir_entries(AM_DIR_ENTRY *function_list,
                         UNSIGNED8    number_of_entries);
AM_RESULT FunctionDef
   am_get_dir_entry(UNSIGNED8 function,
                    UNSIGNED8 *station);

void FunctionDef
   am_call_request(UNSIGNED8        caller_function,
                   const AM_ADDRESS *replier,
                   void             *out_msg_adr,
                   UNSIGNED32       out_msg_size,
                   void             *in_msg_adr,
                   UNSIGNED32       in_msg_size,
                   UNSIGNED16       reply_timeout,
                   AM_CALL_CONFIRM  call_confirm,
                   void             *caller_ref);

AM_RESULT FunctionDef
   am_call_cancel(UNSIGNED8 caller_function, const AM_ADDRESS *replier);

AM_RESULT FunctionDef
   am_bind_replier(UNSIGNED8          replier_function,
                   AM_RECEIVE_CONFIRM receive_confirm,
                   AM_REPLY_CONFIRM   reply_confirm);

AM_RESULT FunctionDef
   am_unbind_replier(UNSIGNED8 replier_function);

AM_RESULT FunctionDef
   am_receive_request(UNSIGNED8  replier_function,
                      void 	     *in_msg_adr,
                      UNSIGNED32 in_msg_size,
                      void 	     *replier_ref);

AM_RESULT FunctionDef
   am_receive_cancel(UNSIGNED8 replier_function, void *replier_ref);

AM_RESULT FunctionDef
   am_reply_request(UNSIGNED8  replier_function,
                    void       *out_msg_adr,
                    UNSIGNED32 out_msg_size,
                    void       *replier_ref,
                    AM_RESULT  status);

AM_RESULT FunctionDef
   am_buffer_free(void *in_msg_adr, UNSIGNED32 size);

#if defined(__cplusplus)
}
#endif

#endif // #ifdef O_MD

#endif // !_MVB_MD_H_

