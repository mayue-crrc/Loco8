#if !defined (_MVB_DEF_H_)
#define _MVB_DEF_H_

#if defined(__cplusplus)
extern "C"
{
#endif

///////////////////////////////////////////////////////////////////////
// General Definitions
///////////////////////////////////////////////////////////////////////

#ifndef NULL
	#define NULL	0
#endif

#ifndef TRUE
	#define TRUE	(1==1)
#endif

#ifndef FALSE
	#define FALSE	(1!=1)
#endif

///////////////////////////////////////////////////////////////////////
// Data Type Definitions
///////////////////////////////////////////////////////////////////////

typedef unsigned int	BITFIELD;
typedef unsigned char	BOOLEAN1;
typedef unsigned char	ANTIVALENT2;
typedef unsigned char	BCD4;
typedef unsigned char	ENUM4;

typedef unsigned char	BITSET8;
typedef unsigned char	WORD8;
typedef unsigned char	ENUM8;
typedef unsigned char	UNSIGNED8;
typedef char			INTEGER8;
typedef char			CHARACTER8;

typedef unsigned short	BITSET16;
typedef unsigned short	WORD16;
typedef unsigned short	ENUM16;
typedef unsigned short	UNSIGNED16;
typedef unsigned short	UNIPOLAR2_16;
typedef unsigned short	BIPOLAR2_16;
typedef unsigned short	BIPOLAR4_16;
typedef short			INTEGER16;

typedef float			REAL32;
typedef unsigned long	BITSET32;
typedef unsigned long	WORD32;
typedef unsigned long	ENUM32;
typedef unsigned long	UNSIGNED32;
typedef long			INTEGER32;

typedef struct
{
	UNSIGNED32 seconds;
	UNSIGNED16 ticks;
}   TIMEDATE48;

typedef struct
{
	CHARACTER8 character[32];
}   STRING32;

// Software Version Information
 
// Identification Number, do not use for current.
#define MVB_API_SW_IDENT1	0x000000
#define MVB_API_SW_IDENT2	0x000000

// General Version Number, e.g. V0.1.00
#define MVB_API_SW_VERSION	0
#define MVB_API_SW_RELEASE	1
#define MVB_API_SW_UPDATE	0

// Compiler Switches

// MVB Client Driver Software
#ifndef FunctionDef
#   define FunctionDef
#endif

#ifndef O_LE
#   define O_LE
#endif

// Demo Application 

//#define O_PRINT
#ifdef _DEBUG
#   define O_DEBUG_ENDLESS
#endif

#define O_AP

#define O_MD
#define O_MD_CALLER
#define O_MD_REPLIER
#define O_MD_TIMEOUT
//#define TCN_HW_PCI
#define _LINUX
#define O_BA
//#define O_REPEATER

#define DEVICE_BASE_ADDR	0x4F8

#define O_INIT_GLOBAL_DATA

#if defined (TCN_HW_PCI)

// thest values must be same with values setted in EEPROM
#define PCI_LCR_REMAP_BASE 0x4F0
#define PCI_BASE 0x01c		// current: use PCI9050_PCI_BASE_3
#define PCI_BUS_TYPE BitSize8			// current: 8 bits bus

#define PCI_LCR_REMAP_BASE_OFFSET (DEVICE_BASE_ADDR - PCI_LCR_REMAP_BASE)

#endif

#if defined(__cplusplus)
}
#endif

#endif // !_MVB_DEF_H_ 
