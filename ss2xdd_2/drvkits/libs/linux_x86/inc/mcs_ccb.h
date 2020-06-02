#if !defined (_MCS_CCB_H_)
#define _MCS_CCB_H_

///////////////////////////////////////////////////////////////////////
// Include Files
///////////////////////////////////////////////////////////////////////

#include "mcs_def.h"

#ifdef O_MD

#if defined(__cplusplus)
extern "C"
{
#endif

///////////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////////

void       ccb_init(void);

void       ccb_clear_callback(void);
BOOLEAN1   ccb_call_confirm(UNSIGNED8 package_size);
BOOLEAN1   ccb_receive_confirm(UNSIGNED8 package_size);
void       ccb_reply_confirm(void);

UNSIGNED32 ccb_get_package_counter(void);

#if defined(__cplusplus)
}
#endif

#endif // #ifdef O_MD

#endif //if !_MCS_CCB_H_

