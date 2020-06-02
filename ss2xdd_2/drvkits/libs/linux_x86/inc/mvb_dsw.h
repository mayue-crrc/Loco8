#if !defined (_MVB_DSW_H_)
#define _MVB_DSW_H_

///////////////////////////////////////////////////////////////////////
// Include Files
///////////////////////////////////////////////////////////////////////

#include "mvb_def.h"

#ifdef O_BA

#if defined(__cplusplus)
extern "C"
{
#endif

///////////////////////////////////////////////////////////////////////
// General Definitions
///////////////////////////////////////////////////////////////////////

// Error Codes
#define DSW_OK			0
#define DSW_PASSIVE		1
#define DSW_ERROR		2
#define DSW_CONFIG		3
#define DSW_MEMORY		4
#define DSW_UNKNOWN_TS	5
#define DSW_RANGE		6
#define DSW_DATA_TYPE	7

///////////////////////////////////////////////////////////////////////
// Type Definitions
///////////////////////////////////////////////////////////////////////

typedef UNSIGNED16	DSW_RESULT;

typedef struct
{
   UNSIGNED16 *p_dsw_ts_config_list;
   UNSIGNED16 c_dsw_ts_config_list;
   UNSIGNED16 supervision_interval;
}  DSW_TS_CONFIG;

typedef struct
{
#if defined (O_LE)
   BITFIELD device_address : 12;
   BITFIELD ts_id          : 4;
#else
   BITFIELD ts_id          : 4;
   BITFIELD device_address : 12;
#endif
}  DSW_NAME;

///////////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////////

DSW_RESULT FunctionDef
   dsw_init(ENUM8 ts_id, DSW_TS_CONFIG *p_dsw_ts_config);

DSW_RESULT FunctionDef
   dsw_read(DSW_NAME *dsw, void *p_value, void *p_fresh);

#if defined(__cplusplus)
}
#endif

#endif // #ifdef O_BA

#endif // !_MVB_DSW_H_ 
