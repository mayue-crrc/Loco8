#if !defined (_MVB_GF_H_)
#define _MVB_GF_H_

///////////////////////////////////////////////////////////////////////
// Include Files
///////////////////////////////////////////////////////////////////////

#include "mvb_def.h"

#if defined(__cplusplus)
extern "C"
{
#endif

///////////////////////////////////////////////////////////////////////
// General Definitions
///////////////////////////////////////////////////////////////////////

// Error Codes
#define GF_OK				0
#define GF_ERROR			2
#define GF_CONFIG			3
#define GF_MEMORY			4
#define GF_UNKNOWN_TS		5
#define GF_RANGE			6

#define GF_DEVICE_ADDRESS	8
#define GF_LINE				9
#define GF_TREPLY			10

// Device Errors
#define GF_DEVICE_ERROR_OK							0
#define GF_DEVICE_ERROR_SERVER_MISSING				1
#define GF_DEVICE_ERROR_SERVER_FAILED				2
#define GF_DEVICE_ERROR_RETURN_INSTANCE				10
#define GF_DEVICE_ERROR_HW							50  // ERROR HW  > 50  
#define GF_DEVICE_ERROR_PIL							100 // ERROR PIL > 100 

// Device Status
#define GF_DEVICE_STATUS_OK							0x0000

#define GF_DEVICE_STATUS_CLIENT_LIFESIGN_TIMEOUT	0x0001
#define GF_DEVICE_STATUS_SERVER_RECEIVE_CHANNEL		0x0002
#define GF_DEVICE_STATUS_SERVER_RECEIVE_CRC			0x0004
#define GF_DEVICE_STATUS_MVBD_OVERTEMPERATURE		0x0010

#define GF_DEVICE_STATUS_SERVER_MISSING				0x0100
#define GF_DEVICE_STATUS_SERVER_FAILED				0x0200
#define GF_DEVICE_STATUS_CLIENT_RECEIVE_CHANNEL		0x0400
#define GF_DEVICE_STATUS_CLIENT_RECEIVE_CRC			0x0800
#define GF_DEVICE_STATUS_CLIENT_RECEIVE_TIMEOUT		0x1000
#define GF_DEVICE_STATUS_CLIENT_SEND_CHANNEL		0x2000
#define GF_DEVICE_STATUS_CLIENT_SEND_TIMEOUT		0x4000

// Hardware IDs
#define GF_HW_ID_UNKNOWN 				0xFFFF
// LOCAL_BUS_INTERFACE
#define GF_HW_ID_LBI_RS485				0x1
#define GF_HW_ID_LBI_PC104				0x2
#define GF_HW_ID_LBI_ISA				0x3
#define GF_HW_ID_LBI_PCI				0x4
#define GF_HW_ID_LBI_CPCI				0x5
#define GF_HW_ID_LBI_EMBEDED_IN			0x6
// MVB_PHYSICAL_LAYER
#define GF_HW_ID_PHL_ESD				0x0
#define GF_HW_ID_PHL_EMD				0x1
#define GF_HW_ID_PHL_OGF				0x2
// SERVER MODE
#define GF_HW_ID_SRV_PDFULL				0xA
#define GF_HW_ID_SRV_PDFULL_BA			0xB
#define GF_HW_ID_SRV_MDFULL				0xC
#define GF_HW_ID_SRV_MDFULL_BA			0xD

// Software IDs
#define GF_SW_ID_UNKNOWN							0
#define GF_SW_ID_PASSIVE							1
#define GF_SW_ID_ACTIVE								2

// Service Commands
#define GF_SERVICE_COMMAND_RESTART_BOARD			1
#define GF_SERVICE_COMMAND_BOOT_LOADER_SERVICE_MODE	2
#define GF_SERVICE_COMMAND_RESTART_APPLICATION		3
#define GF_SERVICE_COMMAND_BA_TCN					10
#define GF_SERVICE_COMMAND_BA_D2000					11
#define GF_SERVICE_COMMAND_BA_D2000_SERVER			12

// MVB Input Lines
#define GF_LINE_A				1		
#define GF_LINE_B				0
#define GF_LINE_BOTH			2

// MVB Reply Timeouts
#define GF_TREPLY_21US			0
#define GF_TREPLY_43US			1
#define GF_TREPLY_64US			2
#define GF_TREPLY_85US			3

// MVB Configuration - Types
#define GF_MVB_CONFIG_TYPE_NSDB	1

// MVB Configuration - Errors

#define GF_MVB_CONFIG_ERROR_NONE							0

// MVB API function calls, which cause an error 
#define GF_MVB_CONFIG_ERROR_MVB_API_GF_MVB_INIT				1
#define GF_MVB_CONFIG_ERROR_MVB_API_LP_INIT					3
#define GF_MVB_CONFIG_ERROR_MVB_API_AM_INIT					5
#define GF_MVB_CONFIG_ERROR_MVB_API_AM_ANNOUNCE_DEVICE		6
#define GF_MVB_CONFIG_ERROR_MVB_API_AM_INSERT_DIR_ENTRIES	7

// General Errors 
#define GF_MVB_CONFIG_ERROR_TS_PORT_CONFIG_MEM_ALLOC		10
#define GF_MVB_CONFIG_ERROR_GF_MVB_CONFIG_INFO_MEM_ALLOC	11

// NSDB Errors (only if "GF_MVB_CONFIG_TYPE_NSDB") 
#define GF_MVB_CONFIG_ERROR_NSDB_HEADER_ENTRY_MISSING		20
#define GF_MVB_CONFIG_ERROR_NSDB_END_OF_NSDB_ENTRY_MISSING	21
#define GF_MVB_CONFIG_ERROR_NSDB_CHECKSUM_WRONG				22
#define GF_MVB_CONFIG_ERROR_NSDB_ENTRY_START_AT_ODD_ADDRESS	23
#define GF_MVB_CONFIG_ERROR_NSDB_ENTRY_ID_UNKNOWN			24
#define GF_MVB_CONFIG_ERROR_NSDB_DEVICE_ADDRESS_IS_0		25
#define GF_MVB_CONFIG_ERROR_NSDB_NS_MVBC_INIT_ENTRY_MISSING	26

// MVB Configuration - Port Configuration
#define GF_MVB_CONFIG_INFO_TS_PORT_SIZE_1					0
#define GF_MVB_CONFIG_INFO_TS_PORT_SIZE_2					1
#define GF_MVB_CONFIG_INFO_TS_PORT_SIZE_4					2
#define GF_MVB_CONFIG_INFO_TS_PORT_SIZE_8					3
#define GF_MVB_CONFIG_INFO_TS_PORT_SIZE_16					4

#define GF_MVB_CONFIG_INFO_TS_PORT_SINK						0
#define GF_MVB_CONFIG_INFO_TS_PORT_SOURCE					1

///////////////////////////////////////////////////////////////////////
// Type Definitions
///////////////////////////////////////////////////////////////////////

typedef UNSIGNED16	GF_RESULT;

typedef UNSIGNED16	GF_DEVICE_ERROR;

typedef UNSIGNED16	GF_DEVICE_STATUS;

typedef UNSIGNED16	GF_HW_ID;

typedef UNSIGNED16	GF_SW_ID;

typedef struct
{
   UNSIGNED32 ident_number[2];
   UNSIGNED16 version;
   UNSIGNED16 release;
   UNSIGNED16 update;
}  GF_SW_VERSION_INFO;

typedef struct
{
   UNSIGNED32         target_number;
   GF_SW_VERSION_INFO info_boot_loader;
   GF_SW_VERSION_INFO info_pld_firmware;
   GF_SW_VERSION_INFO info_mvb_server;
}  GF_SERVER_INFO;

typedef UNSIGNED16	GF_SERVICE_COMMAND;

typedef UNSIGNED16	GF_LINE_CONFIG;

typedef UNSIGNED16	GF_REPLY_TIMEOUT;

typedef UNSIGNED16	GF_MVB_CONFIG_TYPE;
typedef UNSIGNED16	GF_MVB_CONFIG_ERROR;
typedef struct
{
   ENUM8            ts_id;
   UNSIGNED16       device_address;
   GF_LINE_CONFIG   line_config;
   GF_REPLY_TIMEOUT reply_timeout;
}  GF_MVB_CONFIG_INFO_GF;
typedef struct
{
#if defined (O_LE)
   BITFIELD port_address : 12;
   BITFIELD port_size    : 3;
   BITFIELD port_type    : 1;
#else
   BITFIELD port_type    : 1;
   BITFIELD port_size    : 3;
   BITFIELD port_address : 12;
#endif
}  GF_MVB_CONFIG_INFO_TS_PORT_CONFIG;
typedef struct
{
   GF_MVB_CONFIG_INFO_TS_PORT_CONFIG *p_ts_port_config;
   UNSIGNED16                        c_ts_port_config;
   UNSIGNED16                        supervision_interval;
}  GF_MVB_CONFIG_INFO_TS_CONFIG;
typedef struct
{
   GF_MVB_CONFIG_INFO_TS_CONFIG ts_config;
}  GF_MVB_CONFIG_INFO_LP;
typedef struct
{
   UNSIGNED8 function;
   UNSIGNED8 station;
}  GF_MVB_CONFIG_INFO_AM_DIR_ENTRY;
typedef struct
{
   // am_announce_device 
   UNSIGNED16 max_call_number;
   UNSIGNED16 max_inst_number;
   UNSIGNED16 default_reply_timeout;
   UNSIGNED8  my_credit;
   // am_insert_dir_entries 
   UNSIGNED8                       number_of_entries;
   GF_MVB_CONFIG_INFO_AM_DIR_ENTRY *p_function_list;
}  GF_MVB_CONFIG_INFO_AM;
typedef struct
{
   GF_MVB_CONFIG_INFO_GF mvb_config_info_gf;
   GF_MVB_CONFIG_INFO_LP mvb_config_info_lp;
   GF_MVB_CONFIG_INFO_AM mvb_config_info_am;
}  GF_MVB_CONFIG_INFO;

typedef void (*GF_DEVICE_STATUS_CALLBACK)
(
   GF_DEVICE_STATUS device_status
);

typedef struct
{
   UNSIGNED16 *p_ba_config_list;
   UNSIGNED16 c_ba_config_list;
}  GF_BA_CONFIG;

///////////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////////

#if defined (O_INIT_GLOBAL_DATA)
void FunctionDef gf_init_global_data(void);
#endif

GF_RESULT FunctionDef gf_open_device(void            *p_device_config,
                                     UNSIGNED32      client_life_sign_timeout,
                                     GF_DEVICE_ERROR *device_error);
GF_RESULT FunctionDef gf_init_device(void);
GF_RESULT FunctionDef gf_close_device(void);

GF_RESULT FunctionDef
   gf_get_device_status(GF_DEVICE_STATUS *device_status);

#ifdef O_MD
GF_RESULT FunctionDef
   gf_set_device_status_callback(GF_DEVICE_STATUS_CALLBACK device_status_callback);
#endif

GF_RESULT FunctionDef
   gf_get_hardware_info(GF_HW_ID   *hardware_id,
                        UNSIGNED16 *software_version,
                        UNSIGNED16 *software_release,
                        UNSIGNED16 *software_update);
GF_RESULT FunctionDef
   gf_get_software_info(GF_SW_ID   *software_id,
                        UNSIGNED16 *software_version,
                        UNSIGNED16 *software_release,
                        UNSIGNED16 *software_update);
GF_RESULT FunctionDef
   gf_get_mvb_api_info(GF_HW_ID 		        *hardware_id,
                       GF_SW_ID  		       *software_id,
                       GF_SW_VERSION_INFO *software_version_info);

GF_RESULT FunctionDef
   gf_get_server_info(GF_SERVER_INFO *server_info);

#ifdef O_BA
GF_RESULT FunctionDef
   gf_service_command(GF_SERVICE_COMMAND service_command,
                      void 			           *p_data,
                      UNSIGNED32 		      *p_size_of_data);
#endif

GF_RESULT FunctionDef
   gf_get_device_memory(UNSIGNED32 address,
                        void       *p_data,
                        UNSIGNED32 size);

GF_RESULT FunctionDef
   gf_mvb_init(ENUM8            ts_id,
               UNSIGNED16       device_address,
               GF_LINE_CONFIG   *p_line_config,
               GF_REPLY_TIMEOUT *p_reply_timeout);

GF_RESULT FunctionDef gf_mvb_start(ENUM8 ts_id);

GF_RESULT FunctionDef gf_mvb_stop(void);

#ifdef O_BA
GF_RESULT FunctionDef
   gf_mvb_set_config(GF_MVB_CONFIG_TYPE  mvb_config_type,
                     void                *p_mvb_config,
                     GF_MVB_CONFIG_ERROR *mvb_config_error,
                     GF_MVB_CONFIG_INFO  **p_mvb_config_info);
#endif

GF_RESULT FunctionDef gf_buffer_free(void *p_buffer);

#if defined (O_OS_SINGLE) && defined (O_MD)

// Only for single task operation system:
GF_RESULT FunctionDef gf_poll_callback(UNSIGNED32 max_package_number, BOOLEAN1 *bCallbackBusy);
#endif

#ifdef O_BA
GF_RESULT FunctionDef
	gf_ba_setup(ENUM8 ts_id, GF_BA_CONFIG * p_ba_config);
#endif

#ifdef O_REPEATER
GF_RESULT FunctionDef 
	gf_put_other_config(ENUM8 ts_id,
						UNSIGNED8 mix_config, 
						UNSIGNED16 t_reply, 
						UNSIGNED16 t_ignore, 
						UNSIGNED16 t_ms);
GF_RESULT FunctionDef 
	gf_get_other_config(ENUM8 ts_id,
						UNSIGNED8* p_mix_config, 
						UNSIGNED16* p_t_reply, 
						UNSIGNED16* p_t_ignore, 
						UNSIGNED16* p_t_ms);
#endif

#if defined(__cplusplus)
}
#endif

#endif // !_MVB_GF_H_ 
