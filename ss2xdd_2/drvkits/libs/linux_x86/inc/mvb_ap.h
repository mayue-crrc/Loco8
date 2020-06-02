#if !defined (_MVB_AP_H_)
#define _MVB_AP_H_

///////////////////////////////////////////////////////////////////////
// Include Files
///////////////////////////////////////////////////////////////////////

#include "mvb_def.h"

#ifdef O_AP

#include "mvb_lp.h"

 #if defined(__cplusplus)
extern "C"
{
#endif

///////////////////////////////////////////////////////////////////////
// General Definitions
///////////////////////////////////////////////////////////////////////
 
// Error Codes
#define AP_OK			0
#define AP_PRT_PASSIVE	1
#define AP_ERROR		2
#define AP_CONFIG		3
#define AP_MEMORY		4
#define AP_UNKNOWN_TS	5
#define AP_RANGE		6
#define AP_DATA_TYPE	7

// Variable Type (PV_NAME)
 
//primitive process variables with size less than one 16-bit word            
#define AP_VAR_TYPE_BOOLEAN1			0x0
#define AP_VAR_TYPE_ANTIVALENT2			0x1
#define AP_VAR_TYPE_BCD4				0x2
#define AP_VAR_TYPE_ENUM4				0x2
#define AP_VAR_TYPE_BITSET8				0x4
#define AP_VAR_TYPE_WORD8				0x5
#define AP_VAR_TYPE_ENUM8				0x5
#define AP_VAR_TYPE_UNSIGNED8			0x5
#define AP_VAR_TYPE_INTEGER8			0x6
#define AP_VAR_TYPE_CHARACTER8			0x7

// primitive process variables with size of one 16-bit word                   
#define AP_VAR_TYPE_BITSET16			0x4
#define AP_VAR_TYPE_WORD16				0x5
#define AP_VAR_TYPE_ENUM16				0x5
#define AP_VAR_TYPE_UNSIGNED16			0x5
#define AP_VAR_TYPE_INTEGER16			0x6
#define AP_VAR_TYPE_BIPOLAR2_16			0x8
#define AP_VAR_TYPE_UNIPOLAR2_16		0x9
#define AP_VAR_TYPE_BIPOLAR4_16			0xA

// primitive process variables with size of two 16-bit word                   
#define AP_VAR_TYPE_REAL32				0x3
#define AP_VAR_TYPE_BITSET32			0x4
#define AP_VAR_TYPE_WORD32				0x5
#define AP_VAR_TYPE_ENUM32				0x5
#define AP_VAR_TYPE_UNSIGNED32			0x5
#define AP_VAR_TYPE_INTEGER32			0x6

// primitive process variables with size of three 16-bit word                 
#define AP_VAR_TYPE_TIMEDATE48			0x2

// primitive process variables with size of four 16-bit word                  
#define AP_VAR_TYPE_BITSET64			0x4
#define AP_VAR_TYPE_WORD64				0x5
#define AP_VAR_TYPE_ENUM64				0x5
#define AP_VAR_TYPE_UNSIGNED64			0x5
#define AP_VAR_TYPE_INTEGER64			0x6

// structured process variables                                               
#define AP_VAR_TYPE_ARRAY_WORD8_ODD		0x7
#define AP_VAR_TYPE_ARRAY_WORD8_EVEN	0xF
#define AP_VAR_TYPE_ARRAY_UNSIGNED16	0xD
#define AP_VAR_TYPE_ARRAY_INTEGER16		0xE
#define AP_VAR_TYPE_ARRAY_UNSIGNED32	0xB
#define AP_VAR_TYPE_ARRAY_INTEGER32		0xC

// Variable Size (PV_NAME)

// basic sizes of primitive process variables (number means number of bits)   
#define AP_VAR_SIZE_8				0x0
#define AP_VAR_SIZE_16				0x1
#define AP_VAR_SIZE_32				0x2
#define AP_VAR_SIZE_48				0x3
#define AP_VAR_SIZE_64				0x4

// primitive process variables with size less than one 16-bit word            
#define AP_VAR_SIZE_BOOLEAN1		0x0
#define AP_VAR_SIZE_ANTIVALENT2		0x0
#define AP_VAR_SIZE_BCD4			0x0
#define AP_VAR_SIZE_ENUM4			0x0
#define AP_VAR_SIZE_BITSET8			0x0
#define AP_VAR_SIZE_WORD8			0x0
#define AP_VAR_SIZE_ENUM8			0x0
#define AP_VAR_SIZE_UNSIGNED8		0x0
#define AP_VAR_SIZE_INTEGER8		0x0
#define AP_VAR_SIZE_CHARACTER8		0x0

// primitive process variables with size of one 16-bit word                   
#define AP_VAR_SIZE_BITSET16		0x1
#define AP_VAR_SIZE_WORD16			0x1
#define AP_VAR_SIZE_ENUM16			0x1
#define AP_VAR_SIZE_UNSIGNED16		0x1
#define AP_VAR_SIZE_INTEGER16		0x1
#define AP_VAR_SIZE_BIPOLAR2_16		0x1
#define AP_VAR_SIZE_UNIPOLAR2_16	0x1
#define AP_VAR_SIZE_BIPOLAR4_16		0x1

// primitive process variables with size of two 16-bit word                   
#define AP_VAR_SIZE_REAL32			0x2
#define AP_VAR_SIZE_BITSET32		0x2
#define AP_VAR_SIZE_WORD32			0x2
#define AP_VAR_SIZE_ENUM32			0x2
#define AP_VAR_SIZE_UNSIGNED32		0x2
#define AP_VAR_SIZE_INTEGER32		0x2

// primitive process variables with size of three 16-bit word                 
#define AP_VAR_SIZE_TIMEDATE48		0x3

// primitive process variables with size of four 16-bit word                  
#define AP_VAR_SIZE_BITSET64		0x4
#define AP_VAR_SIZE_WORD64			0x4
#define AP_VAR_SIZE_ENUM64			0x4
#define AP_VAR_SIZE_UNSIGNED64		0x4
#define AP_VAR_SIZE_INTEGER64		0x4

// structured process variables - array of 8-bit values                       
#define AP_VAR_SIZE_A8_1			0x0
#define AP_VAR_SIZE_A8_2			0x0
#define AP_VAR_SIZE_A8_3			0x1
#define AP_VAR_SIZE_A8_4			0x1
#define AP_VAR_SIZE_A8_5			0x2
#define AP_VAR_SIZE_A8_6			0x2
#define AP_VAR_SIZE_A8_7			0x3
#define AP_VAR_SIZE_A8_8			0x3
#define AP_VAR_SIZE_A8_9			0x4
#define AP_VAR_SIZE_A8_10			0x4
#define AP_VAR_SIZE_A8_11			0x5
#define AP_VAR_SIZE_A8_12			0x5
#define AP_VAR_SIZE_A8_13			0x6
#define AP_VAR_SIZE_A8_14			0x6
#define AP_VAR_SIZE_A8_15			0x7
#define AP_VAR_SIZE_A8_16			0x7
#define AP_VAR_SIZE_A8_17			0x8
#define AP_VAR_SIZE_A8_18			0x8
#define AP_VAR_SIZE_A8_19			0x9
#define AP_VAR_SIZE_A8_20			0x9
#define AP_VAR_SIZE_A8_21			0xA
#define AP_VAR_SIZE_A8_22			0xA
#define AP_VAR_SIZE_A8_23			0xB
#define AP_VAR_SIZE_A8_24			0xB
#define AP_VAR_SIZE_A8_25			0xC
#define AP_VAR_SIZE_A8_26			0xC
#define AP_VAR_SIZE_A8_27			0xD
#define AP_VAR_SIZE_A8_28			0xD
#define AP_VAR_SIZE_A8_29			0xE
#define AP_VAR_SIZE_A8_30			0xE
#define AP_VAR_SIZE_A8_31			0xF
#define AP_VAR_SIZE_A8_32			0xF

// structured process variables - array of 16-bit values                      
#define AP_VAR_SIZE_A16_1			0x0
#define AP_VAR_SIZE_A16_2			0x1
#define AP_VAR_SIZE_A16_3			0x2
#define AP_VAR_SIZE_A16_4			0x3
#define AP_VAR_SIZE_A16_5			0x4
#define AP_VAR_SIZE_A16_6			0x5
#define AP_VAR_SIZE_A16_7			0x6
#define AP_VAR_SIZE_A16_8			0x7
#define AP_VAR_SIZE_A16_9			0x8
#define AP_VAR_SIZE_A16_10			0x9
#define AP_VAR_SIZE_A16_11			0xA
#define AP_VAR_SIZE_A16_12			0xB
#define AP_VAR_SIZE_A16_13			0xC
#define AP_VAR_SIZE_A16_14			0xD
#define AP_VAR_SIZE_A16_15			0xE
#define AP_VAR_SIZE_A16_16			0xF

// structured process variables - array of 32-bit values                      
#define AP_VAR_SIZE_A32_1			0x1
#define AP_VAR_SIZE_A32_2			0x3
#define AP_VAR_SIZE_A32_3			0x5
#define AP_VAR_SIZE_A32_4			0x7
#define AP_VAR_SIZE_A32_5			0x9
#define AP_VAR_SIZE_A32_6			0xB
#define AP_VAR_SIZE_A32_7			0xD
#define AP_VAR_SIZE_A32_8			0xF

// Derived Variable Type (PV_LIST)

// primitive process variables with size less than one 16-bit word            
#define AP_DERIVED_TYPE_BOOLEAN1			1
#define AP_DERIVED_TYPE_ANTIVALENT2			2
#define AP_DERIVED_TYPE_BCD4				3
#define AP_DERIVED_TYPE_ENUM4				3
#define AP_DERIVED_TYPE_BITSET8				11
#define AP_DERIVED_TYPE_WORD8				12
#define AP_DERIVED_TYPE_ENUM8				12
#define AP_DERIVED_TYPE_UNSIGNED8			12
#define AP_DERIVED_TYPE_INTEGER8			13
#define AP_DERIVED_TYPE_CHARACTER8			14

// primitive process variables with size of one 16-bit word                   
#define AP_DERIVED_TYPE_BITSET16			21
#define AP_DERIVED_TYPE_WORD16				22
#define AP_DERIVED_TYPE_ENUM16				22
#define AP_DERIVED_TYPE_UNSIGNED16			22
#define AP_DERIVED_TYPE_INTEGER16			23
#define AP_DERIVED_TYPE_BIPOLAR2_16			24
#define AP_DERIVED_TYPE_UNIPOLAR2_16		25
#define AP_DERIVED_TYPE_BIPOLAR4_16			26

// primitive process variables with size of two 16-bit word                   
#define AP_DERIVED_TYPE_REAL32				31
#define AP_DERIVED_TYPE_BITSET32			32
#define AP_DERIVED_TYPE_WORD32				33
#define AP_DERIVED_TYPE_ENUM32				33
#define AP_DERIVED_TYPE_UNSIGNED32			33
#define AP_DERIVED_TYPE_INTEGER32			34

// primitive process variables with size of three 16-bit word                 
#define AP_DERIVED_TYPE_TIMEDATE48			41

// primitive process variables with size of four 16-bit word                  
#define AP_DERIVED_TYPE_BITSET64			51
#define AP_DERIVED_TYPE_WORD64				52
#define AP_DERIVED_TYPE_ENUM64				52
#define AP_DERIVED_TYPE_UNSIGNED64			52
#define AP_DERIVED_TYPE_INTEGER64			53

// structured process variables                                               
#define AP_DERIVED_TYPE_ARRAY_WORD8_ODD		61
#define AP_DERIVED_TYPE_ARRAY_WORD8_EVEN	62
#define AP_DERIVED_TYPE_ARRAY_UNSIGNED16	71
#define AP_DERIVED_TYPE_ARRAY_INTEGER16		72
#define AP_DERIVED_TYPE_ARRAY_UNSIGNED32	81
#define AP_DERIVED_TYPE_ARRAY_INTEGER32		82

///////////////////////////////////////////////////////////////////////
// Type Definitions
///////////////////////////////////////////////////////////////////////

typedef UNSIGNED16	AP_RESULT;

// PV_NAME 
typedef struct
{
#if defined (O_LE)
   BITFIELD chk_bit_number   : 3;
   BITFIELD chk_octet_offset : 7;
   BITFIELD var_type         : 6;
   BITFIELD var_bit_number   : 3;
   BITFIELD var_octet_offset : 7;
   BITFIELD var_size         : 6;
   BITFIELD port_address     : 12;
   BITFIELD traffic_store_id : 4;
#else
   BITFIELD traffic_store_id : 4;
   BITFIELD port_address     : 12;
   BITFIELD var_size         : 6;
   BITFIELD var_octet_offset : 7;
   BITFIELD var_bit_number   : 3;
   BITFIELD var_type         : 6;
   BITFIELD chk_octet_offset : 7;
   BITFIELD chk_bit_number   : 3;
#endif
}  PV_NAME;

// PV_LIST
typedef struct
{
   void      *p_variable;
   UNSIGNED8 derived_type;
   UNSIGNED8 array_count;
   UNSIGNED8 octet_offset;
   UNSIGNED8 bit_number;
}  PV_LIST;

// PV_SET
typedef struct
{
   PV_LIST    *p_pv_list;
   UNSIGNED16 c_pv_list;
   UNSIGNED16 *p_freshtime;
   DS_NAME    dataset;
}  PV_SET;

// PV_CLUSTER
typedef struct
{
   UNSIGNED8 ts_id;
   UNSIGNED8 c_pv_set;
   PV_SET    *p_pv_set[1]; // array of pointers to PV_SET 
}  PV_CLUSTER;

///////////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////////

AP_RESULT FunctionDef
   ap_put_variable(PV_NAME *ts_variable, void *p_value, void *p_check);
AP_RESULT FunctionDef
   ap_get_variable(PV_NAME *ts_variable, void *p_value, void *p_check, void *p_fresh);

AP_RESULT FunctionDef
   ap_put_set(PV_SET *pv_set);
AP_RESULT FunctionDef
   ap_get_set(PV_SET *pv_set);

AP_RESULT FunctionDef
   ap_put_cluster(PV_CLUSTER *pv_cluster);
AP_RESULT FunctionDef
   ap_get_cluster(PV_CLUSTER *pv_cluster);

#if defined(__cplusplus)
}
#endif

#endif // #ifdef O_AP

#endif //!_MVB_AP_H_ 

