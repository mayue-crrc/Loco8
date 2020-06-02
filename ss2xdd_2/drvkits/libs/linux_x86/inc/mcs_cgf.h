#if !defined (_MCS_CGF_H_)
#define _MCS_CGF_H_

///////////////////////////////////////////////////////////////////////
// Include Files 
///////////////////////////////////////////////////////////////////////

#include "mcs_def.h"

// Application Interface 
#include "mvb_gf.h"

#if defined(__cplusplus)
extern "C"
{
#endif

///////////////////////////////////////////////////////////////////////
// General Definitions 
///////////////////////////////////////////////////////////////////////

// Server Status 
#define CGF_SERVER_STATUS_STOP			0
#define CGF_SERVER_STATUS_RUN			1
#define CGF_SERVER_STATUS_ERROR			2
#define CGF_SERVER_STATUS_ERROR_DYNAMIC	3

// Service Commands
#define CGF_SERVICE_COMMAND_RESTART_BOARD				1
#define CGF_SERVICE_COMMAND_BOOT_LOADER_SERVICE_MODE	2
#define CGF_SERVICE_COMMAND_RESTART_APPLICATION			3

///////////////////////////////////////////////////////////////////////
// Global Variables 
///////////////////////////////////////////////////////////////////////

extern UNSIGNED16 cgf_device_address;

extern UNSIGNED8  cgf_server_status;

extern BOOLEAN1   bDone_gf_open_device;
extern BOOLEAN1   bDone_gf_init_device;
extern BOOLEAN1   bDone_gf_close_device;
extern BOOLEAN1   bDone_gf_mvb_init;
extern BOOLEAN1   bDone_gf_mvb_start;
extern BOOLEAN1   bDone_lp_init;
extern BOOLEAN1   bDone_am_init;
extern BOOLEAN1   bDone_am_announce_device;
extern BOOLEAN1   bDone_dsw_init;
extern BOOLEAN1   bDone_ba_init;

///////////////////////////////////////////////////////////////////////
// Function Prototypes 
///////////////////////////////////////////////////////////////////////

void cgf_supervisor(void);

void cgf_put_device_status(UNSIGNED16 device_status);

#ifdef O_MD
	GF_RESULT cgf_poll_server_callback(UNSIGNED32 max_package_number, BOOLEAN1 *bNoCallbacks, BOOLEAN1 *bCallbackBusy);
#endif

#if defined(__cplusplus)
}
#endif

#endif // !_MCS_CGF_H_ 
