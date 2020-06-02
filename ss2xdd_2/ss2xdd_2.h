#ifndef SS2XDD_2_H
#define SS2XDD_2_H
#include "mvb_def.h"

//  Purpose   : Enable Bus Administrator
//#define O_BA_CONFIG_DYNAMIC

// MVB Device Address
#define MVB_DEVICE_ADDRESS1  0x011
#define MVB_DEVICE_ADDRESS2  0x010

///////////////////////////////////////////////////////////////////////
//  Constants : PD_PORT_xxx
//
//  Purpose   : Process Data Port numbers
///////////////////////////////////////////////////////////////////////
#define PD_PORT_NO 		10
#define PD_PORT_SRC_NO 	5000						// process data test
#define PD_PORT_SNK_NO 	5000
#define PD_SRC_NO 		1						// mixed test
#define PD_SNK_NO 		1
///////////////////////////////////////////////////////////////////////
// the order is from small size to big,
// ----------------------------------------------------------------------
//  defines Process Data Ports
//  --------------------------------------------------------------
//  TS_PORT_SIZE_1		0
//  TS_PORT_SIZE_2		1
//  TS_PORT_SIZE_4		2
//  TS_PORT_SIZE_8		3
//  TS_PORT_SIZE_16		4
///////////////////////////////////////////////////////////////////////
extern BITFIELD PD_src_port_address[PD_PORT_SRC_NO];
//BITFIELD PD_src_port_address[PD_PORT_SRC_NO]={0x001, 0xE0B, 0x320, 0xA23, 0x640};
extern BITFIELD PD_src_port_size[PD_PORT_SRC_NO];
extern BITFIELD PD_src_port_size_word[PD_PORT_SRC_NO];

extern BITFIELD PD_snk_port_address[PD_PORT_SRC_NO];
//BITFIELD PD_snk_port_address[PD_PORT_SRC_NO]={0xFFF, 0x190, 0xC17, 0x4B0, 0x82F};
extern BITFIELD PD_snk_port_size[PD_PORT_SRC_NO];
extern BITFIELD PD_snk_port_size_word[PD_PORT_SRC_NO];

extern UNSIGNED16 port_data_src[PD_PORT_SRC_NO][16];
extern UNSIGNED16 port_data_snk[PD_PORT_SNK_NO][16];
///////////////////////////////////////////////////////////////////////
// Internal Function Prototypes
///////////////////////////////////////////////////////////////////////
void initial();
// --------------------------------------------------------------------------
//  Procedure : dev_init
//
//  Purpose   : Initialises MVB device.
// --------------------------------------------------------------------------
UNSIGNED16 dev_init (void);
// --------------------------------------------------------------------------
//  Procedure : init_port
//
//  Purpose   : Init MVB Port soure and sink.
// --------------------------------------------------------------------------
UNSIGNED16 init_port();
#endif
