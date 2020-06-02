#if !defined (_MCS_CLCH_H_)
#define _MCS_CLCH_H_

///////////////////////////////////////////////////////////////////////
// Include Files 
///////////////////////////////////////////////////////////////////////

#include "mcs_def.h"

#if defined(__cplusplus)
extern "C"
{
#endif

///////////////////////////////////////////////////////////////////////
// General Definitions 
///////////////////////////////////////////////////////////////////////

// Error Codes 
#define CLCH_OK					0
#define CLCH_ERROR				1
#define CLCH_NOT_ENOUGH_MEMORY	2
#define CLCH_ALLOCATE_MEMORY	3

// Default Instance Number 
#define CLCH_INSTANCE_NUMBER_DEFAULT	0

///////////////////////////////////////////////////////////////////////
// Global Variables 
///////////////////////////////////////////////////////////////////////

extern UNSIGNED8 clch_return_number;

///////////////////////////////////////////////////////////////////////
// Type Definitions 
///////////////////////////////////////////////////////////////////////

typedef UNSIGNED16   CLCH_RESULT;

///////////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////////

void        clch_init(void);

void        clch_channel_open(UNSIGNED16 channel_number);
void        clch_channel_close(UNSIGNED16 channel_number);
void        clch_channel_send_byte(UNSIGNED16 channel_number, UNSIGNED8 data_byte);
void        clch_channel_send_word(UNSIGNED16 channel_number, const UNSIGNED16 *p_data);
void        clch_channel_send_long(UNSIGNED16 channel_number, const UNSIGNED32 *p_data);
CLCH_RESULT clch_channel_send_array_byte(UNSIGNED16 channel_number, const UNSIGNED8 *p_data, UNSIGNED32 number_data);
void        clch_channel_send_array_word(UNSIGNED16 channel_number, const UNSIGNED16 *p_data, UNSIGNED16 number_data);
CLCH_RESULT clch_channel_send_package(UNSIGNED16 channel_number, BOOLEAN1 bFirstPackage, BOOLEAN1 bLastPackage);

UNSIGNED8   clch_channel_receive(UNSIGNED8 *p_return_number, UNSIGNED8 *p_package_size);
CLCH_RESULT clch_wait_for_receive(UNSIGNED8 return_number);
CLCH_RESULT clch_wait_for_receive_dynamic(UNSIGNED8 *package_size);

void        clch_receive_byte(UNSIGNED8 *p_data);
void        clch_receive_word(UNSIGNED16 *p_data);
void        clch_receive_long(UNSIGNED32 *p_data);
void        clch_receive_array_byte(UNSIGNED8 *p_data, UNSIGNED32 number_data);
void        clch_receive_array_word(UNSIGNED16 *p_data, UNSIGNED32 number_data);
CLCH_RESULT clch_receive_check_crc (void);

#if defined(__cplusplus)
}
#endif

#endif // !_MCS_CLCH_H_ 
