#if !defined (_MVB_LP_H_)
#define _MVB_LP_H_

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
#define LP_OK							0
#define LP_PRT_PASSIVE					1
#define LP_ERROR						2
#define LP_CONFIG						3
#define LP_MEMORY						4
#define LP_UNKNOWN_TS					5
#define LP_RANGE						6
#define LP_DATA_TYPE					7

// Port Configuration
#define TS_PORT_SIZE_1					0
#define TS_PORT_SIZE_2					1
#define TS_PORT_SIZE_4					2
#define TS_PORT_SIZE_8					3
#define TS_PORT_SIZE_16					4

#define TS_PORT_SINK					0
#define TS_PORT_SOURCE					1

// Dataset Commands
#define LP_CMD_PUT_DATASET				1
#define LP_CMD_GET_DATASET				2
#define LP_CMD_PUT_MASKED_DATASET		11

#define LP_CMD_FORCE_DATASET			21
#define LP_CMD_UNFORCE_DATASET			22
#define LP_CMD_UNFORCE_ALL_DATASET		23

#define LP_CMD_PUT_DATASET_MF           31
#define LP_CMD_GET_DATASET_MF			32
#define LP_CMD_PUT_MASKED_DATASET_MF	33

///////////////////////////////////////////////////////////////////////
// Type Definitions
///////////////////////////////////////////////////////////////////////

typedef UNSIGNED16	LP_RESULT;

typedef UNSIGNED16	TS_PORT_SIZE;

typedef UNSIGNED16	TS_PORT_TYPE;

typedef UNSIGNED8	LP_CMD;

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
}  TS_PORT_CONFIG;

typedef struct
{
   TS_PORT_CONFIG *p_ts_port_config;
   UNSIGNED16     c_ts_port_config;
   UNSIGNED16     supervision_interval;
}  TS_CONFIG;

typedef struct
{
#if defined (O_LE)
   BITFIELD port_address : 12;
   BITFIELD ts_id        : 4;
#else
   BITFIELD ts_id        : 4;
   BITFIELD port_address : 12;
#endif
}  DS_NAME;

///////////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////////

LP_RESULT FunctionDef
   lp_init(ENUM8 ts_id, TS_CONFIG *p_descriptor);

LP_RESULT FunctionDef
   lp_put_dataset(DS_NAME *dataset, void *p_value);
LP_RESULT FunctionDef
   lp_get_dataset(DS_NAME *dataset, void *p_value, void *p_fresh);

LP_RESULT FunctionDef
   lp_cmd_dataset(LP_CMD command, DS_NAME *dataset, void *p_value, void *p_mask, void *p_fresh);

#if defined(__cplusplus)
}
#endif

#endif // !_MVB_LP_H_
