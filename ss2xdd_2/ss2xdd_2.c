// ==========================================================================
// Copyright(C) 2007
// DALIAN SEA SKY AUTOMATION CO. LTD
//							All Rights Reserved
//==========================================================================
// Products	: SSMV21DD
// Project	: MVB Client-Server Model (MVB Client Driver Software)
// Revision	: v1.00
// Date		: 2007.04.02
// Author	: 
// --------------------------------------------------------------------
// Abstract:
//   1. Test Application for MVB SSMV21DD--demo
// --------------------------------------------------------------------
//
// History :
// ==========================================================================

// ==========================================================================
//
//  Compiler Switches
//
// ==========================================================================
// O_PRINT                - makes printouts with "printw" (optional)
// O_DEBUG_PRINT          - additional debugging printouts
//                          (requires flag O_PRINT):
// O_DEBUG_ENDLESS        - endless loop instead of exit in case of an error
//                          (there you can put a debugging breakpoint)
// --------------------------------------------------------------------------
// O_CLT_DRV_WIN32_COM    - MVB Client Driver Software "win32_com":
//                          - 32-bit Windows operating system,
//                            e.g. Win 9x/NT/2K/XP
//                          - use Windows COM driver to access host interface
//                            of MVB interface product, i.e. UART device
// --------------------------------------------------------------------------
// DEVICE_BASE_ADDR          - Device Configuration (host interface of MVB
//                          interface product)
//                          NOTE:
//                          A MVB interface product (e.g. D113) behaves like
//                          a UART device in the host system.
//                          (1) In case flag O_CLT_DRV_WIN32_COM is set,
//                              then use use serial driver of Windows for
//                              communication over UART device
//                              -> COM number (16 bit, e.g. 3)
//                          (2) In case flag O_CLT_DRV_WIN32_COM is not set,
//                              then use direct access to registers of
//                              UART device
//                              -> IO base address (32 bit, e.g. 0x4F8)
// --------------------------------------------------------------------------
// O_RESTART              - restart the communication with the MVB server
//                          in case of an communication error
// --------------------------------------------------------------------------
// O_MD                   - MVB Message Date (general)
// O_MD_CALLER            - MVB Message Date Caller
// O_MD_REPLIER           - MVB Message Date Replier
// O_MD_TIMEOUT           - timeout for MVB Message communication
// ==========================================================================

///////////////////////////////////////////////////////////////////////
// Include Files
///////////////////////////////////////////////////////////////////////

// MVB Client API - Common Interface Definitions
#include "mvb_def.h"

// Standard Libraries
#include <curses.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// MVB Client API
#include "mvb_gf.h"
#include "mvb_lp.h"
#include "mvb_ap.h"
#include "mvb_md.h"
#include "mvb_dsw.h"

//#if defined(__cplusplus)
//extern "C"
//{
//#endif

///////////////////////////////////////////////////////////////////////
//  Calling convention for procedure "main"
///////////////////////////////////////////////////////////////////////
#ifdef O_CLT_DRV_WIN32_COM
#   define DeclMain    __cdecl
#else
#   define DeclMain
#endif

///////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////

#define O_PRINT_ERROR
#define O_PRINT
#include "ss2xdd_2.h"


///////////////////////////////////////////////////////////////////////
// PD_VAR_ACCESS : Type of variable access:
//                 - individual, i.e. procedure "ap_put/get_dataset"
//                 - set       , i.e. procedure "ap_put/get_set"
//                 - cluster   , i.e. procedure "ap_put/get_cluster"
///////////////////////////////////////////////////////////////////////
#define PD_VAR_ACCESS_INDIVIDUAL	0
#define PD_VAR_ACCESS_SET			1
#define PD_VAR_ACCESS_CLUSTER		2

///////////////////////////////////////////////////////////////////////
// Constants : PD_PORT_xxx
// Purpose   : Process Data Port Addresses
///////////////////////////////////////////////////////////////////////

#define PD_PORT_VAR1	0x001
#define PD_PORT_VAR2	0xE0B
#define PD_PORT_VAR3	0x320
#define PD_PORT_VAR4	0xA23
#define PD_PORT_VAR5	0x640

///////////////////////////////////////////////////////////////////////
// Internal Function Prototypes 
///////////////////////////////////////////////////////////////////////

static UNSIGNED16 pd_var_individual_put(void);
static UNSIGNED16 pd_var_individual_get(void);
static UNSIGNED16 pd_var_set_put(void);
static UNSIGNED16 pd_var_set_get(void);
static UNSIGNED16 pd_var_cluster_put(void);
static UNSIGNED16 pd_var_cluster_get(void);
static UNSIGNED16 pd_var_put_cycle(void);
static UNSIGNED16 pd_var_get_cycle(void);
static UNSIGNED16 lp_demo(void);
static UNSIGNED16 ap_demo(void);
static UNSIGNED16 md_demo(void);
static UNSIGNED16 mixed_demo(void);

///////////////////////////////////////////////////////////////////////
// Procedure Type
///////////////////////////////////////////////////////////////////////

typedef UNSIGNED16 (*PD_VAR_CYCLE)(void);
typedef UNSIGNED16 (*DEMO_CYCLE)(void);

///////////////////////////////////////////////////////////////////////
// Global Variables
///////////////////////////////////////////////////////////////////////

DEMO_CYCLE 	p_demo_cycle = NULL;
DEMO_CYCLE 	p_demo_cycle_group[4] = {lp_demo, ap_demo, md_demo, mixed_demo};
UNSIGNED8 	demo_type = 0;

UNSIGNED16	pd_var_access;
UNSIGNED8   pd_var_access_mode[3][11] = {"Individual", "Set", "Cluster"};

UNSIGNED16   pd_port_type;
PD_VAR_CYCLE p_pd_var_cycle = NULL;
PD_VAR_CYCLE pd_var_cycle_group[2][3] =
{
	{pd_var_individual_get, pd_var_set_get, pd_var_cluster_get},
	{pd_var_individual_put, pd_var_set_put, pd_var_cluster_put}
};

UNSIGNED8 md_demo_type;

// Process Data - Cluster Access of Variables (3 variable sets)
UNSIGNED8   pv_cluster_buf[sizeof(PV_CLUSTER) + (2 * sizeof(PV_SET*))];
PV_CLUSTER  *p_pv_cluster;

///////////////////////////////////////////////////////////////////////
// Process Data - Variables of "dataset1" (located in port PD_PORT_VAR2)
//
// Name  Type         Bit Offset  Remarks
// ----------------------------------------------------------------
// var1  BITSET16     0           not used in this demo application
// var2  CHARACTER8   16          not used in this demo application
// var3  BOOLEAN1     24          not used in this demo application
// var4  BOOLEAN1     25
// var5  ANTIVALENT2  26          not used in this demo application
// var6  ENUM4        28
///////////////////////////////////////////////////////////////////////

BOOLEAN1   ds1_var4_boolean1;
BOOLEAN1   ds1_var4_boolean1_last;

ENUM4      ds1_var6_enum4;
ENUM4      ds1_var6_enum4_last;

PV_NAME    ds1_var4_pv_name;
PV_NAME    ds1_var6_pv_name;

PV_LIST    ds1_pv_list[2];
PV_SET     ds1_pv_set;

UNSIGNED16 ds1_freshness;

///////////////////////////////////////////////////////////////////////
// Process Data - Variables of "dataset2" (located in port PD_PORT_VAR3)
//
// Name  Type         Bit Offset  Remarks
// ----------------------------------------------------------------
// var1  BITSET8      0           not used in this demo application
// var2  INTEGER8     8
// var3  UNSIGNED16   16
// var4  REAL32       32          not used in this demo application
///////////////////////////////////////////////////////////////////////

INTEGER8   ds2_var2_integer8;
INTEGER8   ds2_var2_integer8_last;

UNSIGNED16 ds2_var3_unsigned16;
UNSIGNED16 ds2_var3_unsigned16_last;
UNSIGNED8  ds2_var3_unsigned16_inc_step;

PV_NAME    ds2_var2_pv_name;
PV_NAME    ds2_var3_pv_name;

PV_LIST    ds2_pv_list[3];
PV_SET     ds2_pv_set;

UNSIGNED16 ds2_freshness;

///////////////////////////////////////////////////////////////////////
// Process Data - Variables of "dataset3" (located in port PD_PORT_VAR4)
//
//  Name  Type         Bit Offset  Remarks
//  ----------------------------------------------------------------
//  var1  UNSIGNED32   0           not used in this demo application
//  var2  BCD4         32          not used in this demo application
//  var3  ANTIVALENT2  36          used as check variable for "var8"
//                                 during individual access
//  var4  BOOLEAN1     38
//  var5  BOOLEAN1     39          not used in this demo application
//  var6  UNSIGNED8    40          not used in this demo application
//  var7  TIMEDATE48   48
//  var8  BITSET32     96
///////////////////////////////////////////////////////////////////////

ANTIVALENT2 ds3_var3_antivalent2;
ANTIVALENT2 ds3_var3_antivalent2_last;

BOOLEAN1    ds3_var4_boolean1;
BOOLEAN1    ds3_var4_boolean1_last;

TIMEDATE48  ds3_var7_timedate48;
TIMEDATE48  ds3_var7_timedate48_last;
UNSIGNED8   ds3_var7_timedate48_sec_inc_step;
UNSIGNED8   ds3_var7_timedate48_tic_inc_step;

BITSET32    ds3_var8_bitset32;
BITSET32    ds3_var8_bitset32_last;
UNSIGNED8   ds3_var8_bitset32_inc_step;

PV_NAME     ds3_var4_pv_name;
PV_NAME     ds3_var7_pv_name;
PV_NAME     ds3_var8_pv_name;

PV_LIST     ds3_pv_list[4];
PV_SET      ds3_pv_set;

UNSIGNED16  ds3_freshness;


///////////////////////////////////////////////////////////////////////
// Message Data
///////////////////////////////////////////////////////////////////////
#define MD_SIZE					0x1000
#define REPLY_MESSAGE_SIZE		100

#define MD_REPLIER_FUNCTION 	200
#define MD_CALLER_FUNCTION		100

#define MD_TIMEOUT				50
#define O_MD_TIME_CONSUMPTION

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
BITFIELD PD_src_port_address[PD_PORT_SRC_NO]={0, 0, 0, 0, 0};
//BITFIELD PD_src_port_address[PD_PORT_SRC_NO]={0x001, 0xE0B, 0x320, 0xA23, 0x640};
BITFIELD PD_src_port_size[PD_PORT_SRC_NO]={TS_PORT_SIZE_1,\
												TS_PORT_SIZE_2,\
												TS_PORT_SIZE_4,\
												TS_PORT_SIZE_8,\
												TS_PORT_SIZE_16};
BITFIELD PD_src_port_size_word[PD_PORT_SRC_NO];

BITFIELD PD_snk_port_address[PD_PORT_SRC_NO]={0, 0, 0, 0, 0};
//BITFIELD PD_snk_port_address[PD_PORT_SRC_NO]={0xFFF, 0x190, 0xC17, 0x4B0, 0x82F};
BITFIELD PD_snk_port_size[PD_PORT_SRC_NO]={TS_PORT_SIZE_16,\
												TS_PORT_SIZE_16,\
												TS_PORT_SIZE_2,\
												TS_PORT_SIZE_16,\
												TS_PORT_SIZE_4};
BITFIELD PD_snk_port_size_word[PD_PORT_SRC_NO];

UNSIGNED16 port_data_src[PD_PORT_SRC_NO][16];
UNSIGNED16 port_data_snk[PD_PORT_SNK_NO][16];

///////////////////////////////////////////////////////////////////////
//  Structured Type   : TT_MD_STATE
//
//  Purpose           : State of Message Data communication
//                      (Caller and Replier).
///////////////////////////////////////////////////////////////////////
typedef enum
{
	MD_STATE_IDLE                    = 0,
	MD_STATE_DO_CALL_REQUEST,
	MD_STATE_WAIT_FOR_CALL_CONFIRM,
	MD_STATE_PROCESS_CALL_CONFIRM,
	MD_STATE_WAIT_FOR_REPLIER,
	MD_STATE_DO_RECEIVE_REQUEST,
	MD_STATE_WAIT_FOR_RECEIVE_CONFIRM,
	MD_STATE_PROCESS_RECEIVE_CONFIRM,
	MD_STATE_DO_REPLY_REQUEST,
	MD_STATE_WAIT_FOR_REPLY_CONFIRM,
	MD_STATE_PROCESS_REPLY_CONFIRM
}	MD_STATE;

///////////////////////////////////////////////////////////////////////
//  Message Data - File
///////////////////////////////////////////////////////////////////////
// send file
FILE 		*fp_Send_File;
UNSIGNED32	Send_File_Size;
CHARACTER8	Send_File_Name[16];
CHARACTER8	*md_send_temp;
CHARACTER8  send_temp[1] = "A";
UNSIGNED32	FILE_START = 0xFF;
BOOLEAN1 	bend_of_file = FALSE;
UNSIGNED16 	send_num;
UNSIGNED32 	send_counter   = 0;

enum
	{
	SEND_FILE_STAT_START = 0,
	SEND_FILE_STAT_FILENAME,
	SEND_FILE_STAT_FILESIZE,
	SEND_FILE_STAT_FILE,
	SEND_FILE_STAT_IDLE,
	SEND_FILE_STAT_OVER
	} send_file_stat;

// receive file
FILE 		*fp_Rcv_File;
UNSIGNED32	Rcv_File_Size;
UNSIGNED32	Rcv_Counter = 0;
CHARACTER8	Rcv_File_Name[16];
BOOLEAN1	bDone_Rcv_File=FALSE;
BOOLEAN1 	bFinish_Rcv_File=FALSE;
enum
	{
	RCV_FILE_STAT_START = 0,
	RCV_FILE_STAT_FILENAME,
	RCV_FILE_STAT_FILESIZE,
	RCV_FILE_STAT_FILE,
	RCV_FILE_STAT_IDLE
	} rcv_file_stat;

///////////////////////////////////////////////////////////////////////
//  Message Data - Caller
///////////////////////////////////////////////////////////////////////
CHARACTER8		*md_caller_text_receive;
CHARACTER8		*md_caller_text_send;
MD_STATE		md_caller_state;
AM_RESULT		md_caller_status = AM_OK;
int				md_caller_ext_ref;

///////////////////////////////////////////////////////////////////////
//  Message Data - Replier
///////////////////////////////////////////////////////////////////////
CHARACTER8		*md_replier_text_receive;
CHARACTER8		*md_replier_text_send;
UNSIGNED8		md_replier_function;
MD_STATE		md_replier_state;
UNSIGNED8		md_replier_status = AM_OK;
void 			*md_replier_ref;
int				md_replier_ext_ref;
CHARACTER8 		md_receive_temp[MD_SIZE];
BOOLEAN1 		bwait_for_replier = FALSE;

///////////////////////////////////////////////////////////////////////
//  Message Data - Timeout
///////////////////////////////////////////////////////////////////////
#ifdef O_MD_TIMEOUT
	UNSIGNED32  md_time_start;
	UNSIGNED32  md_time_stop;
	UNSIGNED32  md_time_diff;
#endif 

///////////////////////////////////////////////////////////////////////
//  Message Data - Timecounter
///////////////////////////////////////////////////////////////////////
#ifdef O_MD_TIME_CONSUMPTION
	UNSIGNED32  md_send_time_start;
	UNSIGNED32  md_send_time_consumption;	
#endif

BOOLEAN1 b_refresh_flag = FALSE;

///////////////////////////////////////////////////////////////////////
// Internal Function Prototypes 
///////////////////////////////////////////////////////////////////////
void initial() 
{ 
	initscr(); 
	cbreak(); 
	nl(); 
	//noecho(); 
	//intrflush(stdscr,FALSE);
	//keypad(stdscr,TRUE); 
	//refresh(); 
} 

int kbhit(void)
{
    char ch;


    // Put getch into non-blocking mode
    nodelay(stdscr, TRUE);

    // getch will not echo characters
    noecho();

    // Get character
    ch = getch();

    // Restore getch into blocking mode
    nodelay(stdscr, FALSE);

    // Restore getch echo of characters
    echo();

    if (ch == ERR)
        return 0;

    // Put character back into input queue
    ungetch(ch);

    return 1;
}
// --------------------------------------------------------------------------
//  Procedure : get_file_size
// --------------------------------------------------------------------------
UNSIGNED32 get_file_size(FILE *fp)
{	
	UNSIGNED32 file_size;
	
	fseek(fp, 0L, SEEK_END);
	file_size = ftell(fp);
	rewind(fp);
	return file_size;
}

// --------------------------------------------------------------------------
// procedure: compare_file
// --------------------------------------------------------------------------
BOOLEAN1 compare_file(FILE *fp1, FILE *fp2)
{	
	UNSIGNED32 	file_size1, file_size2;
	UNSIGNED8 	buff_f1, buff_f2;
	BOOLEAN1 	result = TRUE;
	
	file_size1 = get_file_size(fp1);
	file_size2 = get_file_size(fp2);	
	if (file_size1 != file_size2) 
	{
		return FALSE;
	}			
	while(1)
	{
		if (feof(fp1) || feof(fp2))
		{
			break;
		}		
		fread((void *)&buff_f1, 1, 1, fp1);
		fread((void *)&buff_f2, 1, 1, fp2);
		if (buff_f1 != buff_f2)
		{
			result = FALSE;
			break;
		}
	}
	rewind(fp1);	
	rewind(fp2);	
	return result;
} //end of compare_file

// --------------------------------------------------------------------------
//  clear the dataset of geting or puting data for port
// --------------------------------------------------------------------------
void pd_prt_clear_dataset(UNSIGNED16 *dataset, UNSIGNED8 word_no) 
{
	UNSIGNED8 i;
	UNSIGNED16 *p_dataset;

	p_dataset = dataset;	
	for(i = 0; i < word_no; i ++)
	{
		*(p_dataset ++) = 0x0000;
	}
}

// --------------------------------------------------------------------------
//  Procedure : lp_prt_init
//
//  Purpose   : Sets up the MVB Traffic Store with Process Data Ports.
// --------------------------------------------------------------------------
UNSIGNED16
lp_prt_init (void)
{
	LP_RESULT lp_result;
	TS_CONFIG ts_config;
	TS_PORT_CONFIG ts_port_config[PD_PORT_NO];
	UNSIGNED16 c_ts_port_config;
	UNSIGNED16 i;
	
	// ----------------------------
	//  defines Process Data Ports
	// ----------------------------
	//	TS_PORT_SINK       0
	// 	TS_PORT_SOURCE     1
	// ----------------------------
	//init the port config 
	c_ts_port_config = 0;
    while(i<=PD_PORT_SRC_NO && PD_src_port_address[i] != 0){
		ts_port_config[c_ts_port_config].port_address = PD_src_port_address[i];
		ts_port_config[c_ts_port_config].port_size    = PD_src_port_size[i];
		ts_port_config[c_ts_port_config].port_type    = TS_PORT_SOURCE;

		PD_src_port_size_word[i] = 1<<PD_src_port_size[i];
		c_ts_port_config++;	
        i++;
	}
    i=0;
    while(i<= PD_PORT_SNK_NO && PD_snk_port_address[i] != 0){
		ts_port_config[c_ts_port_config].port_address = PD_snk_port_address[i];
		ts_port_config[c_ts_port_config].port_size    = PD_snk_port_size[i];
		ts_port_config[c_ts_port_config].port_type    = TS_PORT_SINK;

		PD_snk_port_size_word[i] = 1<<PD_snk_port_size[i];
		c_ts_port_config++;		
        i++;
	}

#ifdef CHECK_PORT_CONFIG
	if(PD_PORT_NO != c_ts_port_config)
	{
		printw("\nport config error! please check your config!\n");
		refresh();
	}
#endif
	ts_config.p_ts_port_config     = ts_port_config;
	ts_config.c_ts_port_config     = c_ts_port_config;
	ts_config.supervision_interval = 16;

	// ----------------------------
	//  initialises Process Data Ports
	// ----------------------------
#ifdef O_PRINT
	printw("lp_init()\n");
	refresh();
#endif
	lp_result = lp_init(0, &ts_config);
	if(lp_result != LP_OK)
	{
	#ifdef O_PRINT
		printw("ERROR: lp_init()=%u\n", lp_result);
	#endif
		return((UNSIGNED16)lp_result);
	} 
	return(0);
} 

// --------------------------------------------------------------------------
//  Procedure : lp_port_init
//
//  Purpose   : - sets up the MVB Traffic Store with Process Data Ports
//              - sets up data structures for Process Variables of datasets
// --------------------------------------------------------------------------
UNSIGNED16
lp_port_init (void)
{
	UNSIGNED16  result;

	// ----------------------------
	//  sets up the MVB Traffic Store with Process Data Ports
	// ----------------------------
#ifdef O_PRINT
	printw("lp_prt_init()\n");
	refresh();
#endif
	result = lp_prt_init();
	if(result != 0)
	{
	#ifdef O_PRINT
		printw("ERROR: lp_prt_init()=%u\n", result);
	#endif
		return(result);
	} 

    return(0);
} 

// --------------------------------------------------------------------------
//  Procedure : lp_demo
//
//  Purpose   : 
//              NOTE:
//              The dataset will be handled as an array of 16-bit values.
// --------------------------------------------------------------------------
static UNSIGNED16
lp_demo(void)
{
	LP_RESULT  lp_result;
	DS_NAME    ds_name;
	UNSIGNED16 dataset[16];	// NOTE: The dataset will be handled as
							//       an array of 16-bit values.    
	UNSIGNED16 freshness;
	UNSIGNED8  port_status[PD_PORT_SNK_NO];
	UNSIGNED16 port_freshness[PD_PORT_SNK_NO];
	BOOLEAN1   b_print = FALSE;
	UNSIGNED8  ch_temp, j, k;
	UNSIGNED16 i;
	BITFIELD 	temp_port_src_no= PD_PORT_SRC_NO, temp_port_snk_no= PD_PORT_SNK_NO;
    
        UNSIGNED8 loop=0;
	UNSIGNED16 value=0;

#ifdef READ_DSW
	// dsw read	
	DSW_NAME *dsw;
	UNSIGNED16 dsw_value = 0, dsw_value_back = 0, dsw_fress;
	UNSIGNED16 dsw_cnt = 0;
#endif

	// ----------------------------
	//  NOTE:
	//  The dataset will be handled as an array of 16-bit values.
	// ----------------------------

	// init data of the ports 
	for(i=0; i < PD_PORT_SRC_NO; i++)
	{
		pd_prt_clear_dataset(port_data_src[i], PD_src_port_size_word[i]);

	}
	for(i=0; i < PD_PORT_SNK_NO; i++)
	{
		pd_prt_clear_dataset(port_data_snk[i], PD_snk_port_size_word[i]);
		port_status[i]= 0;
		port_freshness[i] = 0;			
	}

	// default value of source ports
	for(i=0; i < PD_PORT_SRC_NO; i++)
	{
		for(j = 0; j < PD_src_port_size_word[i];j++)
		{
		//	port_data_src[i][j] = 0x1122 + 0x1111 * j;
                        port_data_src[i][j] = value;
		}
	}

#ifdef READ_DSW
	// Reading the DSW
	dsw->device_address = MVB_DEVICE_ADDRESS1;
	dsw->ts_id = 0;
	dsw_read(dsw, &dsw_value, &dsw_fress);
	dsw_value_back = dsw_value;
#endif

	// print info 
	// NOTE: the print data may be different with the data on MVB line because of the array print sequence
	clear();
	refresh();
	printw("******************************************************************************\n");
 	printw("port config                  port data                   status   freshness\n");
	printw("******************************************************************************\n");

	if(0 != temp_port_src_no)
	{
		printw("\n-- SOURCE PORT\n");
	}

	for(i = 0; i < PD_PORT_SRC_NO; i ++)
	{
		printw("0x%03X(%-03dbits)", PD_src_port_address[i],PD_src_port_size_word[i]*16);
		for(j = 0; j < PD_src_port_size_word[i]; j ++)
		{
			if(j == 8)
			{
				printw("\n              ");
			}
			printw(" %04X", port_data_src[i][j]);
		}
		printw("\n");
	}

	if(0 != temp_port_snk_no)
	{
		printw("\n-- SINK PORT\n");
	}

	for(i = 0; i < PD_PORT_SNK_NO; i ++)
	{
		printw("0x%03X(%-03dbits)", PD_snk_port_address[i],PD_snk_port_size_word[i]*16);
		printw(" waiting to receive data...                 00       null\n");
	}
	refresh();
	
#ifdef READ_DSW
	printw("\n#%05d#", dsw_cnt);
	printw("\nlocal device address: 0x%04x\t", MVB_DEVICE_ADDRESS1);
	printw("it's device status: 0x%04x\n", dsw_value);
	refresh();
#endif

	while(1)
	{
		// Exit if ESC is pressed
		if(kbhit())
		{
			ch_temp = getch();
			if(ch_temp == 27)
			{
				break;
			}
			
			for(i = 0; i < PD_PORT_SRC_NO; i++)
			{
				for(j=0;j < PD_src_port_size_word[i];j++)
				{
					if((ch_temp == 'a'+j) || (ch_temp == 'A'+j))
					{
						b_print = TRUE;
						port_data_src[i][PD_src_port_size_word[i]-1-j] = (++ port_data_src[i][PD_src_port_size_word[i]-1-j] % 0xFFFF);
						
					}
				}
			}
		}

		// ----------------------------
		//  put datasets.
		// ----------------------------
		for(i = 0; i<PD_PORT_SRC_NO; i++)
		{
			ds_name.ts_id = 0;
			ds_name.port_address = PD_src_port_address[i];
			lp_result = lp_put_dataset(&ds_name,&port_data_src[i][0]);
			if(lp_result != LP_OK)
			{
			#ifdef O_PRINT
				printw("ERROR: lp_put_dataset(0x%03X)=%u\n", \
					ds_name.port_address, lp_result);
			#endif
			    return((UNSIGNED16)lp_result);
			}	
		}

		// ----------------------------
		//  get datasets.
		// ----------------------------
		for(i = 0; i < PD_PORT_SNK_NO; i ++)
		{
			ds_name.ts_id        = 0;
			ds_name.port_address = PD_snk_port_address[i];
			lp_result = lp_get_dataset(&ds_name, dataset, &freshness);
			if(lp_result != LP_OK)
			{
			#ifdef O_PRINT
				printw("ERROR: lp_get_dataset(0x%03X)=%u\n", \
					ds_name.port_address, lp_result);
				refresh();
			#endif
				return((UNSIGNED16)lp_result);
			}
			
			for(j = 0; j < PD_snk_port_size_word[i]; j ++)
			{
				if(port_data_snk[i][j] != dataset[j])
				{
					break;
				}
			}
			if(j != PD_snk_port_size_word[i])
			{
				b_print = TRUE;
				for(k = 0; k < PD_snk_port_size_word[i]; k++)
				{
					port_data_snk[i][k] = dataset[k];
				}
			}

			if(port_freshness[i] != freshness)
			{
				port_freshness[i] = freshness;
			}
		}

#ifdef READ_DSW
		// ----------------------------
		// Reading the DSW
		// ----------------------------
		dsw_read(dsw, &dsw_value, &dsw_fress);
		if(dsw_value_back != dsw_value)
		{
			b_print = TRUE;
			if((dsw_value_back & 0x00FF) != (dsw_value & 0x00FF))
			{
				dsw_cnt ++;
			}
			dsw_value_back = dsw_value;
		}
#endif
		// print the info if necessary 
		if(b_print)
		{
			clear();
			refresh();
			printw("******************************************************************************\n");
			printw("port config                  port data                   status   freshness\n");
			printw("******************************************************************************\n");

			if(0 != temp_port_src_no)
			{
				printw("\n-- SOURCE PORT\n");
			}
			
			for(i = 0; i < PD_PORT_SRC_NO; i ++)
			{
				printw("0x%03X(%-03dbits)", PD_src_port_address[i],PD_src_port_size_word[i]*16);
				for(j = 0; j < PD_src_port_size_word[i]; j ++)
				{
					if(j == 8)
					{
						printw("\n              ");
					}
					printw(" %04X", port_data_src[i][j]);
				}
				printw("\n");
			}
			
			if(0 != temp_port_snk_no)
			{
				printw("\n-- SINK PORT\n");
			}

			for(i = 0; i < PD_PORT_SNK_NO; i ++)
			{
				printw("0x%03X(%-03dbits)", PD_snk_port_address[i],PD_snk_port_size_word[i]*16);
				for(j = 0; j < PD_snk_port_size_word[i]; j ++)
				{
					if(j == 8)
					{
						printw("\n              ");
					}
					printw(" %04X", port_data_snk[i][j]);
				}
				for(; j<8; j++)
				{
					printw("     ");
				}
				printw("    %02X",port_status[i]);
		 		printw("        ");
		 		printw("%04X",port_freshness[i]);
		  		printw("\n");
			}
#ifdef READ_DSW
			printw("#%05d#\n", dsw_cnt);
			printw("\nlocal device address: 0x%04x\t", MVB_DEVICE_ADDRESS1);
			printw("it's device status: 0x%04x\n", dsw_value);
			refresh();
#endif
			b_print = FALSE;
			refresh();

		}// if (b_print) 

                sleep(1);
		loop++;
		value = (loop<<8) + loop;
		for(i=0; i < PD_PORT_SRC_NO; i++)
		{
			for(j = 0; j < PD_src_port_size_word[i];j++)
        	        {
                                port_data_src[i][j] = value;
        	        }
		}

	}// while(1) 
			
    return(0);
} 

// --------------------------------------------------------------------
// [Name] ap_prt_init
//
// [Function]
//   Sets up the MVB Traffic Store with Process Data Ports.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   lp_result
// --------------------------------------------------------------------
static UNSIGNED16 ap_prt_init (void)
{
	LP_RESULT      lp_result;
	TS_CONFIG      ts_config;
	TS_PORT_CONFIG ts_port_config[7];
	UNSIGNED16     c_ts_port_config;

	// ---------------------------------------------------------------
	// defines Process Data Ports
	//
	//                   Size    SINK/
	// Port ID          (bytes)  SOURCE  Remarks
	// --------------------------------------------------------------
	// PD_PORT_VAR1         2    SOURCE  not used in this demo
	// PD_PORT_VAR2         4    SOURCE  hold "dataset1"
	// PD_PORT_VAR3         8    SOURCE  hold "dataset2"
	// PD_PORT_VAR4        16    SOURCE  hold "dataset3"
	// PD_PORT_VAR5        32    SOURCE  not used in this demo
	// ---------------------------------------------------------------
	c_ts_port_config = 0;

	ts_port_config[c_ts_port_config].port_address = PD_PORT_VAR1;
	ts_port_config[c_ts_port_config].port_size    = TS_PORT_SIZE_1;
	ts_port_config[c_ts_port_config].port_type    = pd_port_type;
	c_ts_port_config++;

	ts_port_config[c_ts_port_config].port_address = PD_PORT_VAR2;
	ts_port_config[c_ts_port_config].port_size    = TS_PORT_SIZE_2;
	ts_port_config[c_ts_port_config].port_type    = pd_port_type;
	c_ts_port_config++;

	ts_port_config[c_ts_port_config].port_address = PD_PORT_VAR3;
	ts_port_config[c_ts_port_config].port_size    = TS_PORT_SIZE_4;
	ts_port_config[c_ts_port_config].port_type    = pd_port_type;
	c_ts_port_config++;

	ts_port_config[c_ts_port_config].port_address = PD_PORT_VAR4;
	ts_port_config[c_ts_port_config].port_size    = TS_PORT_SIZE_8;
	ts_port_config[c_ts_port_config].port_type    = pd_port_type;
	c_ts_port_config++;

	ts_port_config[c_ts_port_config].port_address = PD_PORT_VAR5;
	ts_port_config[c_ts_port_config].port_size    = TS_PORT_SIZE_16;
	ts_port_config[c_ts_port_config].port_type    = pd_port_type;
	c_ts_port_config++;
	
#ifdef CHECK_PORT_CONFIG
	if(PD_PORT_NO != c_ts_port_config)
	{
		printw("\nport config error! please check your config!\n");
		refresh();
	}
#endif

	ts_config.p_ts_port_config     = ts_port_config;
	ts_config.c_ts_port_config     = c_ts_port_config;
	ts_config.supervision_interval = 16;

	// ----------------------------
	// initialises Process Data Ports
	// ----------------------------
#ifdef O_PRINT
	printw("lp_init()\n\r");
	refresh();
#endif
	lp_result = lp_init(0, &ts_config);
	if(lp_result != LP_OK)
	{
		printw("ERROR: lp_init() = %u\n\r", lp_result);
		return (UNSIGNED16)lp_result;
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_init_dataset1
//
// [Function]
//   Sets up data structures for Process Variables of "dataset1"
//   (individual and set access).
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   0
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_init_dataset1 (void)
{
	PV_LIST    *p_pv_list;
	UNSIGNED16 c_pv_list;

	// ---------------------------------------------------------------------
	// Process Data - Variables of "dataset1" (located in port PD_PORT_VAR2)
	//
	// Name  Type         Bit Offset  Remarks
	// ----------------------------------------------------------------
	// var1  BITSET16     0           not used in this demo application
	// var2  CHARACTER8   16          not used in this demo application
	// var3  BOOLEAN1     24          not used in this demo application
	// var4  BOOLEAN1     25
	// var5  ANTIVALENT2  26          not used in this demo application
	// var6  ENUM4        28
	// ---------------------------------------------------------------------

	p_pv_list = ds1_pv_list;
	c_pv_list = 0;

	// ----------------------------
	// ds1_var4_boolean1 (bit_offset=25)
	// ----------------------------
	ds1_var4_boolean1      = (BOOLEAN1)0;
	ds1_var4_boolean1_last = ds1_var4_boolean1;

	ds1_var4_pv_name.traffic_store_id = 0;
	ds1_var4_pv_name.port_address     = PD_PORT_VAR2;
	ds1_var4_pv_name.var_size         = AP_VAR_SIZE_8;
	ds1_var4_pv_name.var_octet_offset = 3;		// first octet has offset 0
	ds1_var4_pv_name.var_bit_number   = 6;		// counted from the right
	ds1_var4_pv_name.var_type         = AP_VAR_TYPE_BOOLEAN1;
	ds1_var4_pv_name.chk_octet_offset = 127;	// no check variable
	ds1_var4_pv_name.chk_bit_number   = 7;		// no check variable

	p_pv_list->p_variable             = (void*)&ds1_var4_boolean1;
	p_pv_list->derived_type           = AP_DERIVED_TYPE_BOOLEAN1;
	p_pv_list->array_count            = 1;
	p_pv_list->octet_offset           = 3;		// first octet has offset 0
	p_pv_list->bit_number             = 6;
	p_pv_list++;
	c_pv_list++;

	// ----------------------------
	//  ds1_var6_enum4 (bit_offset=28)
	// ----------------------------
	ds1_var6_enum4      = (ENUM4)1;
	ds1_var6_enum4_last = ds1_var6_enum4;

	ds1_var6_pv_name.traffic_store_id = 0;
	ds1_var6_pv_name.port_address     = PD_PORT_VAR2;
	ds1_var6_pv_name.var_size         = AP_VAR_SIZE_8;
	ds1_var6_pv_name.var_octet_offset = 3;		// first octet has offset 0
	ds1_var6_pv_name.var_bit_number   = 0;		// counted from the right
	ds1_var6_pv_name.var_type         = AP_VAR_TYPE_ENUM4;
	ds1_var6_pv_name.chk_octet_offset = 127;	// no check variable
	ds1_var6_pv_name.chk_bit_number   = 7;		// no check variable

	p_pv_list->p_variable             = (void*)&ds1_var6_enum4;
	p_pv_list->derived_type           = AP_DERIVED_TYPE_ENUM4;
	p_pv_list->array_count            = 1;
	p_pv_list->octet_offset           = 3;
	p_pv_list->bit_number             = 0;
	p_pv_list++;
	c_pv_list++;

	// ----------------------------
	// variable set of "dataset1"
	// ----------------------------
	ds1_pv_set.p_pv_list            = ds1_pv_list;
	ds1_pv_set.c_pv_list            = c_pv_list;
	ds1_pv_set.p_freshtime          = &ds1_freshness;
	ds1_pv_set.dataset.ts_id        = 0;
	ds1_pv_set.dataset.port_address = PD_PORT_VAR2;

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_init_dataset2
//
// [Function]
//   Sets up data structures for Process Variables of "dataset2"
//   (individual and set access).
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   0
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_init_dataset2 (void)
{
	PV_LIST    *p_pv_list;
	UNSIGNED16 c_pv_list;

	// ----------------------------------------------------------------------
	//  Process Data - Variables of "dataset2" (located in port PD_PORT_VAR3)
	//
	//  Name  Type         Bit Offset  Remarks
	//  ----------------------------------------------------------------
	//  var1  BITSET8      0           not used in this demo application
	//  var2  INTEGER8     8
	//  var3  UNSIGNED16   16
	//  var4  REAL32       32          not used in this demo application
	// ----------------------------------------------------------------------
	p_pv_list = ds2_pv_list;
	c_pv_list = 0;

	// ----------------------------
	// ds2_var2_integer8 (bit_offset=8)
	// ----------------------------
	ds2_var2_integer8      = (INTEGER8)0;
	ds2_var2_integer8_last = ds2_var2_integer8;

	ds2_var2_pv_name.traffic_store_id = 0;
	ds2_var2_pv_name.port_address     = PD_PORT_VAR3;
	ds2_var2_pv_name.var_size         = AP_VAR_SIZE_8;
	ds2_var2_pv_name.var_octet_offset = 1;		// first octet has offset 0
	ds2_var2_pv_name.var_bit_number   = 0;		// counted from the right
	ds2_var2_pv_name.var_type         = AP_VAR_TYPE_INTEGER8;
	ds2_var2_pv_name.chk_octet_offset = 127;	// no check variable
	ds2_var2_pv_name.chk_bit_number   = 7;		// no check variable

	p_pv_list->p_variable             = (void*)&ds2_var2_integer8;
	p_pv_list->derived_type           = AP_DERIVED_TYPE_INTEGER8;
	p_pv_list->array_count            = 1;
	p_pv_list->octet_offset           = 1;
	p_pv_list->bit_number             = 0;
	p_pv_list++;
	c_pv_list++;

	// ----------------------------
	// ds2_var3_unsigned16 (bit_offset=16)
	// ----------------------------
	ds2_var3_unsigned16          = (UNSIGNED16)0x0010;
	ds2_var3_unsigned16_last     = ds2_var3_unsigned16;
	ds2_var3_unsigned16_inc_step = 1;

	ds2_var3_pv_name.traffic_store_id = 0;
	ds2_var3_pv_name.port_address     = PD_PORT_VAR3;
	ds2_var3_pv_name.var_size         = AP_VAR_SIZE_16;
	ds2_var3_pv_name.var_octet_offset = 2;		// first octet has offset 0
	ds2_var3_pv_name.var_bit_number   = 0;		// counted from the right
	ds2_var3_pv_name.var_type         = AP_VAR_TYPE_UNSIGNED16;
	ds2_var3_pv_name.chk_octet_offset = 127;	// no check variable
	ds2_var3_pv_name.chk_bit_number   = 7;		// no check variable

	p_pv_list->p_variable             = (void*)&ds2_var3_unsigned16;
	p_pv_list->derived_type           = AP_DERIVED_TYPE_UNSIGNED16;
	p_pv_list->array_count            = 1;
	p_pv_list->octet_offset           = 2;
	p_pv_list->bit_number             = 0;
	p_pv_list++;
	c_pv_list++;

	// ----------------------------
	// variable set of "dataset2"
	// ----------------------------
	ds2_pv_set.p_pv_list            = ds2_pv_list;
	ds2_pv_set.c_pv_list            = c_pv_list;
	ds2_pv_set.p_freshtime          = &ds2_freshness;
	ds2_pv_set.dataset.ts_id        = 0;
	ds2_pv_set.dataset.port_address = PD_PORT_VAR3;

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_init_dataset3
//
// [Function]
//   Sets up data structures for Process Variables of "dataset3"
//   (individual and set access).
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   0
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_init_dataset3 (void)
{
	PV_LIST    *p_pv_list;
	UNSIGNED16 c_pv_list;

	// ----------------------------------------------------------------------
	//  Process Data - Variables of "dataset3" (located in port PD_PORT_VAR4)
	//
	//  Name  Type         Bit Offset  Remarks
	//  ----------------------------------------------------------------
	//  var1  UNSIGNED32   0           not used in this demo application
	//  var2  BCD4         32          not used in this demo application
	//  var3  ANTIVALENT2  36          used as check variable for "var8"
	//                                 during individual access
	//  var4  BOOLEAN1     38
	//  var5  BOOLEAN1     39          not used in this demo application
	//  var6  UNSIGNED8    40          not used in this demo application
	//  var7  TIMEDATE48   48
	//  var8  BITSET32     96
	// ----------------------------------------------------------------------
	p_pv_list = ds3_pv_list;
	c_pv_list = 0;

	// ----------------------------
	// ds3_var3_antivalent2 (bit_offset=36)
	// NOTE:
	// Used as check variable for "ds3_var8_bitset32" during individual access.
	// ----------------------------
	ds3_var3_antivalent2      = (ANTIVALENT2)1;	// the protect variable are correct
	ds3_var3_antivalent2_last = ds3_var3_antivalent2;

	p_pv_list->p_variable             = (void*)&ds3_var3_antivalent2;
	p_pv_list->derived_type           = AP_DERIVED_TYPE_ANTIVALENT2;
	p_pv_list->array_count            = 1;
	p_pv_list->octet_offset           = 4;
	p_pv_list->bit_number             = 2;
	p_pv_list++;
	c_pv_list++;

	// ----------------------------
	// ds3_var4_boolean1 (bit_offset=38)
	// ----------------------------
	ds3_var4_boolean1      = (BOOLEAN1)1;
	ds3_var4_boolean1_last = ds3_var4_boolean1;

	ds3_var4_pv_name.traffic_store_id = 0;
	ds3_var4_pv_name.port_address     = PD_PORT_VAR4;
	ds3_var4_pv_name.var_size         = AP_VAR_SIZE_8;
	ds3_var4_pv_name.var_octet_offset = 4;		// first octet has offset 0
	ds3_var4_pv_name.var_bit_number   = 1;		// counted from the right
	ds3_var4_pv_name.var_type         = AP_VAR_TYPE_BOOLEAN1;
	ds3_var4_pv_name.chk_octet_offset = 127;	// no check variable
	ds3_var4_pv_name.chk_bit_number   = 7;		// no check variable

	p_pv_list->p_variable             = (void*)&ds3_var4_boolean1;
	p_pv_list->derived_type           = AP_DERIVED_TYPE_BOOLEAN1;
	p_pv_list->array_count            = 1;
	p_pv_list->octet_offset           = 4;
	p_pv_list->bit_number             = 1;
	p_pv_list++;
	c_pv_list++;

	// ----------------------------
	// ds3_var7_timedate48 (bit_offset=48)
	// ----------------------------
	ds3_var7_timedate48.seconds      = (UNSIGNED32)0x00000030;
	ds3_var7_timedate48.ticks        = (UNSIGNED16)0x0400;
	ds3_var7_timedate48_last         = ds3_var7_timedate48;
	ds3_var7_timedate48_sec_inc_step = 1;
	ds3_var7_timedate48_tic_inc_step = 2;

	ds3_var7_pv_name.traffic_store_id = 0;
	ds3_var7_pv_name.port_address     = PD_PORT_VAR4;
	ds3_var7_pv_name.var_size         = AP_VAR_SIZE_48;
	ds3_var7_pv_name.var_octet_offset = 6;		// first octet has offset 0
	ds3_var7_pv_name.var_bit_number   = 0;		// counted from the right
	ds3_var7_pv_name.var_type         = AP_VAR_TYPE_TIMEDATE48;
	ds3_var7_pv_name.chk_octet_offset = 127;	// no check variable
	ds3_var7_pv_name.chk_bit_number   = 7;		// no check variable

	p_pv_list->p_variable             = (void*)&ds3_var7_timedate48;
	p_pv_list->derived_type           = AP_DERIVED_TYPE_TIMEDATE48;
	p_pv_list->array_count            = 1;
	p_pv_list->octet_offset           = 6;
	p_pv_list->bit_number             = 0;
	p_pv_list++;
	c_pv_list++;

	// ----------------------------
	// ds3_var8_bitset32 (bit_offset=96)
	// ----------------------------
	ds3_var8_bitset32          = (BITSET32)0x00005000;
	ds3_var8_bitset32_last     = ds3_var8_bitset32;
	ds3_var8_bitset32_inc_step = 3;

	ds3_var8_pv_name.traffic_store_id = 0;
	ds3_var8_pv_name.port_address     = PD_PORT_VAR4;
	ds3_var8_pv_name.var_size         = AP_VAR_SIZE_32;
	ds3_var8_pv_name.var_octet_offset = 12;		// first octet has offset 0
	ds3_var8_pv_name.var_bit_number   = 0;		// counted from the right
	ds3_var8_pv_name.var_type         = AP_VAR_TYPE_BITSET32;
	ds3_var8_pv_name.chk_octet_offset = 4;		// first octet has offset 0
	ds3_var8_pv_name.chk_bit_number   = 2;		// counted from the right

	p_pv_list->array_count            = 1;
	p_pv_list->octet_offset           = 4;
	p_pv_list->bit_number             = 2;

	p_pv_list->p_variable             = (void*)&ds3_var8_bitset32;
	p_pv_list->derived_type           = AP_DERIVED_TYPE_BITSET32;
	p_pv_list->array_count            = 1;
	p_pv_list->octet_offset           = 12;
	p_pv_list->bit_number             = 0;
	p_pv_list++;
	c_pv_list++;

	// ----------------------------
	// variable set of "dataset3"
	// ----------------------------
	ds3_pv_set.p_pv_list            = ds3_pv_list;
	ds3_pv_set.c_pv_list            = c_pv_list;
	ds3_pv_set.p_freshtime          = &ds3_freshness;
	ds3_pv_set.dataset.ts_id        = 0;
	ds3_pv_set.dataset.port_address = PD_PORT_VAR4;

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_init_cluster
//
// [Function]
//   Sets up data structures for Process Variables cluster access.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   0
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_init_cluster (void)
{

	p_pv_cluster = (PV_CLUSTER*)pv_cluster_buf;

	p_pv_cluster->ts_id       = 0;
	p_pv_cluster->c_pv_set    = 3;
	p_pv_cluster->p_pv_set[0] = &ds1_pv_set;
	p_pv_cluster->p_pv_set[1] = &ds2_pv_set;
	p_pv_cluster->p_pv_set[2] = &ds3_pv_set;

	return 0;
}

// --------------------------------------------------------------------
// [Name] ap_port_init
//
// [Function]
//   sets up the MVB Traffic Store with Process Data Ports
//   sets up data structures for Process Variables of datasets
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   result
// --------------------------------------------------------------------
static UNSIGNED16 ap_port_init (void)
{
	UNSIGNED16 result;

	// ----------------------------
	// sets up the MVB Traffic Store with Process Data Ports
	// ----------------------------
#ifdef O_PRINT
	printw("ap_prt_init()\n\r");
	refresh();
#endif
	result = ap_prt_init();
	if(result != 0)
	{
		printw("ERROR: ap_prt_init() = %u\n\r", result);
		return result;
	}

	// ----------------------------
	// sets up data structures for Process Variables of "dataset1"
	// ----------------------------
#ifdef O_PRINT
	printw("pd_var_init_dataset1()\n\r");
	refresh();
#endif
	result = pd_var_init_dataset1();
	if(result != 0)
	{
		printw("ERROR: pd_var_init_dataset1() = %u\n\r", result);
		return result;
	}

	// ----------------------------
	// sets up data structures for Process Variables of "dataset2"
	// ----------------------------
#ifdef O_PRINT
	printw("pd_var_init_dataset2()\n\r");
	refresh();
#endif
	result = pd_var_init_dataset2();
	if(result != 0)
	{
		printw("ERROR: pd_var_init_dataset2() = %u\n\r", result);
		return result;
	}

	// ----------------------------
	// sets up data structures for Process Variables of "dataset3"
	// ----------------------------
#ifdef O_PRINT
	printw("pd_var_init_dataset3()\n\r");
	refresh();
#endif
	result = pd_var_init_dataset3();
	if(result != 0)
	{
		printw("ERROR: pd_var_init_dataset3() = %u\n\r", result);
		return result;
	}

	// ----------------------------
	// sets up data structures for Process Variables cluster access
	// ----------------------------
#ifdef O_PRINT
	printw("pd_var_init_cluster()\n\r");
	refresh();
#endif
	result = pd_var_init_cluster();
	if(result != 0)
	{
		printw("ERROR: pd_var_init_cluster() = %u\n\r", result);
		return result;
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_inc
//
// [Function]
//   Increase variables increase for source ports.
// [INPUT]
//   ch: The key that is pressed to increase a variable
// [OUTPUT]
//   none
// [RETURN]
//   0
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_inc (UNSIGNED8 ch)
{
	switch(ch)
	{
		case 'a':
		case 'A':
			if(ds1_var4_boolean1 == (BOOLEAN1)0)
			{
				ds1_var4_boolean1 = (BOOLEAN1)1;
			}
			else if(ds1_var4_boolean1 == (BOOLEAN1)1)
			{
				ds1_var4_boolean1 = (BOOLEAN1)0;
			}
			break;
		case 'b':
		case 'B':
			if(ds1_var6_enum4 == 15)
			{
				ds1_var6_enum4 = 0;
			}
			else
			{
				ds1_var6_enum4++;
			}
			break;
		case 'c':
		case 'C':
			ds2_var2_integer8 ++;
			ds2_var2_integer8 %= 0xFF;
			break;
		case 'd':
		case 'D':
			ds2_var3_unsigned16 ++;
			ds2_var3_unsigned16 %= 0xFFFF;
			break;
		case 'e':
		case 'E':
			if(ds3_var4_boolean1 == (BOOLEAN1)0)
			{
				ds3_var4_boolean1 = (BOOLEAN1)1;
			}
			else if(ds3_var4_boolean1 == (BOOLEAN1)1)
			{
				ds3_var4_boolean1 = (BOOLEAN1)0;
			}
			break;
		case 'f':
		case 'F':
			{
				UNSIGNED16 *p_val16 = (UNSIGNED16 *)(&(ds3_var7_timedate48.seconds)) + 1;
				(*p_val16) ++;
				(*p_val16) %= 0xFFFF;
			}
			break;
		case 'g':
		case 'G':
			{
				UNSIGNED16 *p_val16 = (UNSIGNED16 *)(&(ds3_var7_timedate48.seconds));
				(*p_val16) ++;
				(*p_val16) %= 0xFFFF;
			}
			break;
		case 'h':
		case 'H':
			ds3_var7_timedate48.ticks = (++ ds3_var7_timedate48.ticks) % 0xFFFF;
			break;
		case 'i':
		case 'I':
			{
				UNSIGNED16 *p_val16 = (UNSIGNED16 *)(&(ds3_var8_bitset32)) + 1;
				(*p_val16) ++;
				(*p_val16) %= 0xFFFF;
			}
			break;
		case 'j':
		case 'J':
			{
				UNSIGNED16 *p_val16 = (UNSIGNED16 *)(&(ds3_var8_bitset32));
				(*p_val16) ++;
				(*p_val16) %= 0xFFFF;
			}
			break;
		default:
			break;
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_check
//
// [Function]
//   Check if the variables is changed for sink ports.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   TRUE : Some variables changed and need to be freshed on the screen
//   FALSE: No variable changed and needn't to be freshed
// --------------------------------------------------------------------
static BOOLEAN1 pd_var_check (void)
{

	// check if ds3_var8_bitset32 is valid
	if(ds3_var3_antivalent2 == 1)				// valid
	{
		if(ds3_var8_bitset32 != ds3_var8_bitset32_last)
		{
			ds3_var8_bitset32_last = ds3_var8_bitset32;
			return TRUE;
		}
	}
	else										// invalid
	{
		ds3_var8_bitset32 = ds3_var8_bitset32_last;
	}

	// check if ds1_var4_boolean1 has changed
	if(ds1_var4_boolean1 != ds1_var4_boolean1_last)
	{
		ds1_var4_boolean1_last = ds1_var4_boolean1;
		return TRUE;
	}

	// check if ds1_var6_enum4 has changed
	if(ds1_var6_enum4 != ds1_var6_enum4_last)
	{
		ds1_var6_enum4_last = ds1_var6_enum4;
		return TRUE;
	}

	// check if ds2_var2_integer8 has changed
	if(ds2_var2_integer8 != ds2_var2_integer8_last)
	{
		ds2_var2_integer8_last = ds2_var2_integer8;
		return TRUE;
	}

	// check if ds2_var3_unsigned16 has changed
	if(ds2_var3_unsigned16 != ds2_var3_unsigned16_last)
	{
		ds2_var3_unsigned16_last = ds2_var3_unsigned16;
		return TRUE;
	}

	// check if ds3_var4_boolean1 has changed
	if(ds3_var4_boolean1 != ds3_var4_boolean1_last)
	{
		ds3_var4_boolean1_last = ds3_var4_boolean1;
		return TRUE;
	}

	// check if ds3_var7_boolean1 has changed
	if(ds3_var7_timedate48.seconds != ds3_var7_timedate48_last.seconds)
	{
		ds3_var7_timedate48_last.seconds = ds3_var7_timedate48.seconds;
		return TRUE;
	}
	if(ds3_var7_timedate48.ticks != ds3_var7_timedate48_last.ticks)
	{
		ds3_var7_timedate48_last.ticks = ds3_var7_timedate48.ticks;
		return TRUE;
	}

	return FALSE;
}

// --------------------------------------------------------------------
// [Name] pd_var_individual_put
//
// [Function]
//   Put variables by using individual access.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   ap_result
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_individual_put (void)
{
	AP_RESULT  ap_result;

	// ----------------------------
	// put variable "ds1_var4_boolean1"
	// ----------------------------
	ap_result = ap_put_variable(&ds1_var4_pv_name, &ds1_var4_boolean1, NULL);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_variable(ds1_var4_boolean1) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// put variable "ds1_var6_enum4"
	// ----------------------------
	ap_result = ap_put_variable(&ds1_var6_pv_name, &ds1_var6_enum4, NULL);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_variable(ds1_var6_enum4) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// put variable "ds2_var2_integer8"
	// ----------------------------
	ap_result = ap_put_variable(&ds2_var2_pv_name, &ds2_var2_integer8, NULL);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_variable(ds2_var2_integer8) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// put variable "ds2_var3_unsigned16"
	// ----------------------------
	ap_result = ap_put_variable(&ds2_var3_pv_name, &ds2_var3_unsigned16, NULL);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_variable(ds2_var3_unsigned16) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// put variable "ds3_var4_boolean1"
	// ----------------------------
	ap_result = ap_put_variable(&ds3_var4_pv_name, &ds3_var4_boolean1, NULL);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_variable(ds3_var4_boolean1) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// put variable "ds3_var7_timedate48"
	// ----------------------------
	ap_result = ap_put_variable(&ds3_var7_pv_name, &ds3_var7_timedate48, NULL);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_variable(ds3_var7_timedate48) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// put variable "ds3_var8_bitset32"
	// ----------------------------
	ap_result = ap_put_variable(&ds3_var8_pv_name, &ds3_var8_bitset32, &ds3_var3_antivalent2);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_variable(ds3_var8_bitset32) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_individual_get
//
// [Function]
//   Get variables by using individual access.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   ap_result
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_individual_get (void)
{
	AP_RESULT ap_result;

	// ----------------------------
	// get variable "ds1_var4_boolean1"
	// ----------------------------
	ds1_var4_boolean1 = (BOOLEAN1)0;
	ap_result = ap_get_variable(&ds1_var4_pv_name, &ds1_var4_boolean1, NULL, &ds1_freshness);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_variable(ds1_var4_boolean1) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// get variable "ds1_var6_enum4"
	// ----------------------------
	ds1_var6_enum4 = (ENUM4)0;
	ap_result = ap_get_variable(&ds1_var6_pv_name, &ds1_var6_enum4, NULL, &ds1_freshness);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_variable(ds1_var6_enum4) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// get variable "ds2_var2_integer8"
	// ----------------------------
	ds2_var2_integer8 = (INTEGER8)0;
	ap_result = ap_get_variable(&ds2_var2_pv_name, &ds2_var2_integer8, NULL, &ds2_freshness);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_variable(ds2_var2_integer8) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// get variable "ds2_var3_unsigned16"
	// ----------------------------
	ds2_var3_unsigned16 = (UNSIGNED16)0;
	ap_result = ap_get_variable(&ds2_var3_pv_name, &ds2_var3_unsigned16, NULL, &ds2_freshness);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_variable(ds2_var3_unsigned16) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// get variable "ds3_var4_boolean1"
	// ----------------------------
	ds3_var4_boolean1 = (BOOLEAN1)0;
	ap_result = ap_get_variable(&ds3_var4_pv_name, &ds3_var4_boolean1, NULL, &ds3_freshness);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_variable(ds3_var4_boolean1) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// get variable "ds3_var7_timedate48"
	// ----------------------------
	ds3_var7_timedate48.seconds = (UNSIGNED32)0;
	ds3_var7_timedate48.ticks   = (UNSIGNED16)0;
	ap_result = ap_get_variable(&ds3_var7_pv_name, &ds3_var7_timedate48, NULL, &ds3_freshness);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_variable(ds3_var7_timedate48) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// get variable "ds3_var8_bitset32"
	// ----------------------------
	ds3_var8_bitset32 = (BITSET32)0;
	ap_result = ap_get_variable(&ds3_var8_pv_name, &ds3_var8_bitset32, &ds3_var3_antivalent2, &ds3_freshness);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_variable(ds3_var8_bitset32) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_set_put
//
// [Function]
//   Put variables by using set access.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   0
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_set_put (void)
{
	AP_RESULT ap_result;

	// ----------------------------
	// put variables of "dataset1"
	// ----------------------------
	ap_result = ap_put_set(&ds1_pv_set);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_set(ds1_pv_set) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// put variables of "dataset2"
	// ----------------------------
	ap_result = ap_put_set(&ds2_pv_set);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_set(ds2_pv_set) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	// put variables of "dataset3"
	// ----------------------------
	ap_result = ap_put_set(&ds3_pv_set);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_set(ds3_pv_set) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_set_get
//
// [Function]
//   Get variables by using set access
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   0
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_set_get (void)
{
	AP_RESULT ap_result;

	// ----------------------------
	//  get variables from "dataset1"
	// ----------------------------
	ap_result = ap_get_set(&ds1_pv_set);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_set(ds1_pv_set) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	//  get variables from "dataset2"
	// ----------------------------
	ap_result = ap_get_set(&ds2_pv_set);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_set(ds2_pv_set) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	// ----------------------------
	//  get variables from "dataset3"
	// ----------------------------
	ap_result = ap_get_set(&ds3_pv_set);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_set(ds3_pv_set) = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_cluster_put
//
// [Function]
//   Put all variables by using cluster access.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   ap_result
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_cluster_put (void)
{
	AP_RESULT ap_result;

	ap_result = ap_put_cluster(p_pv_cluster);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_put_cluster() = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_cluster_get
//
// [Function]
//   Get all variables by using cluster access.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   ap_result
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_cluster_get (void)
{
	AP_RESULT ap_result;

	ap_result = ap_get_cluster(p_pv_cluster);
	if(ap_result != AP_OK)
	{
		printw("\n\rERROR: ap_get_cluster() = %u\n\r", ap_result);
		return (UNSIGNED16)ap_result;
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_put_cycle
//
// [Function]
//   Put variables to the source ports.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   result
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_put_cycle (void)
{
	UNSIGNED16 result;
	UNSIGNED8  ch;
	BOOLEAN1   b_print = FALSE;

	p_pd_var_cycle = pd_var_cycle_group[pd_port_type][pd_var_access];

	// ----------------------------
	// print info
	// NOTE: the print data may be different with the data on MVB line because of the array print sequence
	// ----------------------------
	clear();
	refresh();
	printw(" ******************** Process Data Variable Interface (AP) ********************\n\n");
	printw(" Device address: 0x%03x\n", (UNSIGNED16)MVB_DEVICE_ADDRESS1);
	printw(" Access mode   : %s\n", pd_var_access_mode[pd_var_access]);
	printw(" MVB Card is putting data ...\n\n");
	printw(" ------------------------------------------------------------------------------\n");
	printw(" DS     | dataset1 0xE0B | dataset2 0x320      | dataset3 0xA23\n\r");
	printw(" ------------------------------------------------------------------------------\n");
	printw(" VAR    | var4     var6  | var2     var3       | var4     var7         var8\n");
	printw(" offset | 25       28    | 8        16         | 38       48           96\n");
	printw(" type   | BOOLEAN1 ENUM4 | INTEGER8 UNSIGNED16 | BOOLEAN1 TIMEDATE48   BITSET32\n");
	printw(" ------------------------------------------------------------------------------\n");
	printw(" value    %1X        %1X       %02X       %04X         %1X        %08lX%04X %08lX", \
		ds1_var4_boolean1, ds1_var6_enum4, (unsigned char)ds2_var2_integer8, ds2_var3_unsigned16, ds3_var4_boolean1, \
		ds3_var7_timedate48.seconds, ds3_var7_timedate48.ticks, ds3_var8_bitset32);
	refresh();

	while(1)
	{
		if(kbhit())
		{
			ch = getch();
			if(ch == 27)				// press 'ESC' to exit
			{
				break;
			}
			else if(((ch >= 'a') && (ch <= 'j')) || ((ch >= 'A') && (ch <= 'J')))
			{
				pd_var_inc(ch);
				b_print = TRUE;
			}
		}

		// ----------------------------
		// put variables to dataset
		// ----------------------------
		result = (*p_pd_var_cycle)();
		if(result != 0)
		{
			return result;
		}

		if(b_print == TRUE)
		{
			move(13,1);
			printw("value    %1X        %1X       %02X       %04X         %1X        %08lX%04X %08lX", \
				ds1_var4_boolean1, ds1_var6_enum4, (unsigned char)ds2_var2_integer8, ds2_var3_unsigned16, ds3_var4_boolean1, \
				ds3_var7_timedate48.seconds, ds3_var7_timedate48.ticks, ds3_var8_bitset32);

			b_print = FALSE;
			refresh();

		}
	}

	return 0;
}

// --------------------------------------------------------------------
// [Name] pd_var_get_cycle
//
// [Function]
//   Get variables from the sink ports.
// [INPUT & OUTPUT]
//   none
// [RETURN]
//   0
// --------------------------------------------------------------------
static UNSIGNED16 pd_var_get_cycle (void)
{
	UNSIGNED16 result;
	UNSIGNED8  ch;
	BOOLEAN1   b_print = FALSE;

	p_pd_var_cycle = pd_var_cycle_group[pd_port_type][pd_var_access];

	// ----------------------------
	// print info
	// NOTE: the print data may be different with the data on MVB line because of the array print sequence
	// ----------------------------
	clear();
	refresh();
	printw(" ******************** Process Data Variable Interface (AP) ********************\n\n");
	printw(" Device address: 0x%03x\n", (UNSIGNED16)MVB_DEVICE_ADDRESS1);
	printw(" Access mode   : %s\n", pd_var_access_mode[pd_var_access]);
	printw(" MVB Card is getting data ...\n\n");
	printw(" ------------------------------------------------------------------------------\n");
	printw(" DS     | dataset1 0xE0B | dataset2 0x320      | dataset3 0xA23\n\r");
	printw(" ------------------------------------------------------------------------------\n");
	printw(" VAR    | var4     var6  | var2     var3       | var4     var7         var8\n");
	printw(" offset | 25       28    | 8        16         | 38       48           96\n");
	printw(" type   | BOOLEAN1 ENUM4 | INTEGER8 UNSIGNED16 | BOOLEAN1 TIMEDATE48   BITSET32\n");
	printw(" ------------------------------------------------------------------------------\n");
	printw(" value    %1X        %1X       %02X       %04X         %1X        %08lX%04X %08lX", \
		ds1_var4_boolean1, ds1_var6_enum4, (unsigned char)ds2_var2_integer8, ds2_var3_unsigned16, ds3_var4_boolean1, \
		ds3_var7_timedate48.seconds, ds3_var7_timedate48.ticks, ds3_var8_bitset32);
	refresh();
	
	while(1)
	{
		if(kbhit())
		{
			ch = getch();
			if(ch == 27)					// press 'ESC' to exit
			{
				break;
			}
		}

		// ----------------------------
		// get variables from dataset
		// ----------------------------
		result = (*p_pd_var_cycle)();
		if(result != 0)
		{
			return result;
		}

		b_print = pd_var_check();
		if(b_print == TRUE)
		{
			move(13,1);
			printw("value    %1X        %1X       %02X       %04X         %1X        %08lX%04X %08lX", \
				ds1_var4_boolean1, ds1_var6_enum4, (unsigned char)ds2_var2_integer8, ds2_var3_unsigned16, ds3_var4_boolean1, \
				ds3_var7_timedate48.seconds, ds3_var7_timedate48.ticks, ds3_var8_bitset32);

			b_print = FALSE;	
			refresh();

		}
	}

	return 0;
}

static UNSIGNED16
ap_demo(void)
{
	UNSIGNED16  result = 0;
	// ----------------------------
	// Process Data - Variables
	// ----------------------------
	if(pd_port_type == TS_PORT_SINK)
	{
		result = pd_var_get_cycle();
		if(result != 0)
		{
			printw("\n\rERROR: pd_var_get_cycle() = %u\n\r", result);
			return result;
		}
	}
	else if(pd_port_type == TS_PORT_SOURCE)
	{
		result = pd_var_put_cycle();
		if(result != 0)
		{
			printw("\n\rERROR: pd_var_put_cycle() = %u\n\r", result);
			return result;
		}
	}

	return result;
}
// --------------------------------------------------------------------------
//  Procedure : send_call_confirm (Caller)
//
//  Purpose   : This procedure will be executed, when a Reply message
//              is complete received.
// --------------------------------------------------------------------------
static void send_call_confirm
(
	UNSIGNED8 			caller_function,   
	void 				*am_caller_ref,
	const AM_ADDRESS 	*replier,        
	void 				*in_msg_adr,        
	UNSIGNED32 			in_msg_size	,
	AM_RESULT 			status
)
{
	char * p;
	
	// avoid warning
	caller_function = caller_function;
	am_caller_ref = am_caller_ref;
	replier = replier; 
	in_msg_adr = in_msg_adr;
	in_msg_size	= in_msg_size;

	p = in_msg_adr;
	bwait_for_replier = FALSE;
	md_caller_status = (AM_RESULT)status;
	if ((md_caller_status != AM_OK)&&(md_caller_status != AM_NO_READY_INST_ERR))
	{
		printw("ERROR:caller_status=%d\n",md_caller_status);
		refresh();
	}
	if (md_caller_status == AM_NO_READY_INST_ERR)
	{
		if ((send_file_stat <= SEND_FILE_STAT_FILE)&&(send_counter == 0))
		{
			send_file_stat --;
		}
		if ((send_file_stat == SEND_FILE_STAT_FILE)&&(send_counter > 0))
		{
			send_counter -= send_num;
		}
		if (send_file_stat == SEND_FILE_STAT_OVER)
		{
			send_counter -= send_num;
			send_file_stat = SEND_FILE_STAT_FILE;
			bend_of_file = FALSE;
		}
		bwait_for_replier = TRUE;
	}
	md_caller_state = MD_STATE_PROCESS_CALL_CONFIRM;
	if ((*p != 0)&&(bend_of_file==TRUE))                    
	{		
		printw("\nFile send finished\n");
#ifdef O_MD_TIME_CONSUMPTION
		md_send_time_consumption = (UNSIGNED32)time(NULL) - md_send_time_start;
		printw("Time consumption:%ld\n",md_send_time_consumption);
#endif			
	}


} //end of send_call_confirm 

// --------------------------------------------------------------------------
//  Procedure : send_do_call_request (Caller)
//
//  Purpose   : Requests to send a Call_Message.              
// --------------------------------------------------------------------------
static UNSIGNED16 send_do_call_request (void * md_caller_send, UNSIGNED32 send_size)
{
	UNSIGNED16	counter;
	UNSIGNED8	caller_function;
	AM_ADDRESS	md_replier;
	UNSIGNED32	out_msg_size;
	UNSIGNED32	in_msg_size;    

	// ----------------------------
	//  clear variable "md_caller_text_send" and "md_caller_text_receive"
	// ----------------------------
	for (counter=0; counter<REPLY_MESSAGE_SIZE; counter++)
	{
		md_caller_text_receive[counter] = 0;
	} 

	// ----------------------------
	//  sets up the data structures for sending the Call message
	//  (e.g. address of Replier)
	// ----------------------------
	caller_function = MD_CALLER_FUNCTION;
	md_replier.sg_node = AM_SAME_NODE;
	md_replier.func_or_stat = MD_REPLIER_FUNCTION;
	md_replier.next_station = MVB_DEVICE_ADDRESS2; 
	md_replier.topo_counter = AM_ANY_TOPO;
	in_msg_size = REPLY_MESSAGE_SIZE;
	out_msg_size = send_size;
	md_caller_state = MD_STATE_WAIT_FOR_CALL_CONFIRM;

	am_call_request                 \
	(                               \
		caller_function,            \
		&md_replier,                \
		md_caller_send,    			\
		out_msg_size,               \
		&md_caller_text_receive[0], \
		in_msg_size,                \
		0,                        \
		send_call_confirm,            \
		&md_caller_ext_ref          \
	);
	
	return(0);	
} //end of send_do_call_request 

// --------------------------------------------------------------------------
//  Procedure : send_receive_confirm (Replier)
//
//  Purpose   : This procedure will be executed, when a Call message
//              is complete received.
// --------------------------------------------------------------------------
static void
send_receive_confirm
(
	UNSIGNED8 			replier_function,   
	const AM_ADDRESS 	*caller,  
	void 				*in_msg_adr,
	UNSIGNED32 			in_msg_size,
	void 				*replier_ref   
)
{
	char * p;
	// avoid warnings 
	caller = caller;
	in_msg_adr  = in_msg_adr;
	in_msg_size = in_msg_size;

	p = in_msg_adr;
	md_replier_function = replier_function;
	md_replier_ref = replier_ref;
	md_replier_state = MD_STATE_PROCESS_RECEIVE_CONFIRM;
	switch(rcv_file_stat)
	{
		case RCV_FILE_STAT_FILENAME:
		{
			strcpy(Rcv_File_Name, p);   			
			rcv_file_stat ++;
			printw("File name: %s\n", p);
		}
			break;
		case RCV_FILE_STAT_FILESIZE:
		{
			Rcv_File_Size = *((UNSIGNED32 *) p);  			
			rcv_file_stat ++;
			if (Rcv_File_Size <= 0)                         
			{
				rcv_file_stat = RCV_FILE_STAT_IDLE;
			}
			printw("File size: %lu bytes\n", Rcv_File_Size);
			if ((fp_Rcv_File = fopen(Rcv_File_Name, "wb")) == NULL)
			{
				printw("Can not create file for receiving file.\n");
				refresh();
				rcv_file_stat = RCV_FILE_STAT_IDLE;
			}
		}
			break;
		case RCV_FILE_STAT_FILE:
		{
			printw("..");	
			if ( fwrite (p, in_msg_size, 1, fp_Rcv_File) != 1)  
			{
				printw("file write error\n");				
				if (fclose(fp_Rcv_File) != 0)
				{
					printw("close file error!\n");
				}
				Rcv_Counter = 0;
				rcv_file_stat = RCV_FILE_STAT_IDLE;
			}
			else                                                         
			{
				Rcv_Counter += in_msg_size;
				if (Rcv_Counter >= Rcv_File_Size)
				{
					printw("\nFile receive finished\n");
					bDone_Rcv_File = TRUE;            
					if (fclose(fp_Rcv_File) != 0)
					printw("close file error!\n");
				}
			}
		}
			break;
		case RCV_FILE_STAT_IDLE: 
		{
			if (0xFF == * ((int *)p))	
			{
				rcv_file_stat = RCV_FILE_STAT_FILENAME;
				printw("\nStart receiving file......\n");
			}
		}
			break;
		default:
			break;
	}
	if(bDone_Rcv_File == TRUE)
	{
		rcv_file_stat = RCV_FILE_STAT_IDLE;
	}
}//end of send_receive_confirm 

// --------------------------------------------------------------------------
//  Procedure : send_reply_confirm (Replier)
//
//  Purpose   : This procedure will be executed, when a Reply message
//              is complete send.
// --------------------------------------------------------------------------
static void send_reply_confirm
(
	UNSIGNED8 	replier_function,
	void 		*replier_ref
)
{
	//avoid warnings
	replier_function = replier_function;
	replier_ref = replier_ref;
	md_replier_state = MD_STATE_PROCESS_REPLY_CONFIRM;
} 

// --------------------------------------------------------------------------
//  Procedure : send_do_receive_request
//
//  Purpose   : Informs the Messenger, that the Replier is ready to receive
//              an incoming Call message.
// --------------------------------------------------------------------------
UNSIGNED16
send_do_receive_request (void)
{
	AM_RESULT 	am_result;
	UNSIGNED16 	counter;
	UNSIGNED8 	replier_function;
	UNSIGNED32 	in_msg_size;

	// ----------------------------
	//  clear variable "md_replier_text_send" and "md_replier_text_receive"
	// ----------------------------
	for (counter=0; counter<MD_SIZE; counter++)
	{
		md_replier_text_receive[counter] = 0;
	} 
	for (counter=0; counter<REPLY_MESSAGE_SIZE; counter++)
	{
		md_replier_text_send[counter] = 0;
	}

	// ----------------------------
	//  informs the Messenger, that the Replier is ready to receive
	//  an incoming Call message
	// ----------------------------
	replier_function = MD_REPLIER_FUNCTION;
	in_msg_size = MD_SIZE;
	md_replier_state = MD_STATE_WAIT_FOR_RECEIVE_CONFIRM;

	am_result =                             \
		am_receive_request                  \
		(                                   \
			replier_function,               \
			&md_replier_text_receive[0],    \
			in_msg_size,                    \
			&md_replier_ext_ref             \
		);
	if (am_result != AM_OK)
	{
		md_replier_state = MD_STATE_DO_RECEIVE_REQUEST;
		return((UNSIGNED16)am_result);
	} 
	
	return(0);
} //end of send_do_receive_request 

// --------------------------------------------------------------------------
//  Procedure : send_do_reply_request (Replier)
//
//  Purpose   : Requests to send a Reply message in response to a previously
//              received Call message.
// --------------------------------------------------------------------------
UNSIGNED16
send_do_reply_request (void)
{
	AM_RESULT 	am_result;
	UNSIGNED16 	counter;
	UNSIGNED32 	out_msg_size;
	UNSIGNED8 	status;
	
	// ----------------------------
	//  clear variable "md_replier_text_send"
	// ----------------------------
	for (counter=0; counter<REPLY_MESSAGE_SIZE; counter++)
	{
		md_replier_text_send[counter] = 0;
	} 

	// ----------------------------
	//  set variable "md_replier_text_send"
	// ----------------------------
	// always reply "OK!" in response to a previously received Call message
	// can change according to application
	md_replier_text_send[0] = 'O';
	md_replier_text_send[1] = 'K';
	md_replier_text_send[2] = '!';
	md_replier_text_send[3] = 0;

	// ----------------------------
	//  requests to send a Reply message in response to a previously
	//  received Call message
	// ----------------------------
	status = md_replier_status;
	out_msg_size = REPLY_MESSAGE_SIZE;    
	md_replier_state = MD_STATE_WAIT_FOR_REPLY_CONFIRM;

	am_result =                         \
		am_reply_request                \
		(                               \
			md_replier_function,        \
			&md_replier_text_send[0],   \
			out_msg_size,               \
			md_replier_ref,             \
			status                      \
		);
	if (am_result != AM_OK)
	{
		md_replier_state = MD_STATE_DO_REPLY_REQUEST;
		return((UNSIGNED16)am_result);
	} 
	
	return(0);
} // end of send_do_reply_request 

// --------------------------------------------------------------------------
//  Procedure : receive_call_confirm (Caller)
//
//  Purpose   : This procedure will be executed, when a Reply message
//              is complete received.
// --------------------------------------------------------------------------
void
receive_call_confirm
(
	UNSIGNED8 			caller_function,   
	void 				*am_caller_ref,
	const AM_ADDRESS 	*replier,        
	void 				*in_msg_adr,        
	UNSIGNED32 			in_msg_size	,
	AM_RESULT 			status
)
{
	// avoid warning
	caller_function = caller_function;
	am_caller_ref = am_caller_ref;
	replier = replier; 
	in_msg_adr = in_msg_adr;
	in_msg_size	= in_msg_size;

	bwait_for_replier = FALSE;
	md_caller_status = (AM_RESULT)status;
	if ((md_caller_status != AM_OK)&&(md_caller_status != AM_NO_READY_INST_ERR))
	{
		printw("ERROR:caller_status=%d\n",md_caller_status);
	}
	if (md_caller_status == AM_NO_READY_INST_ERR)
	{
		if ((send_file_stat<=SEND_FILE_STAT_FILE)&&(send_counter == 0))
		{
			send_file_stat --;
		}
		if ((send_file_stat == SEND_FILE_STAT_FILE)&&(send_counter > 0))
		{
			send_counter -= send_num;
		}
		if (send_file_stat == SEND_FILE_STAT_OVER)
		{
			send_counter -= send_num;
			send_file_stat = SEND_FILE_STAT_FILE;
			bend_of_file = FALSE;
		}
		bwait_for_replier = TRUE;
	}
	md_caller_state = MD_STATE_PROCESS_CALL_CONFIRM;
} //end of receive_call_confirm 

// --------------------------------------------------------------------------
//  Procedure : receive_do_call_request (Caller)
//
//  Purpose   : Requests to send a Call_Message.              
// --------------------------------------------------------------------------
UNSIGNED16
receive_do_call_request (void * md_caller_send, UNSIGNED32 send_size)
{
	UNSIGNED16	counter;
	UNSIGNED8	caller_function;
	AM_ADDRESS	md_replier;
	UNSIGNED32	out_msg_size;
	UNSIGNED32	in_msg_size;    

	// ----------------------------
	//  clear variable "md_caller_text_send" and "md_caller_text_receive"
	// ----------------------------
	for (counter=0; counter<REPLY_MESSAGE_SIZE; counter++)
	{		
	    	md_caller_text_receive[counter] = 0;
	} 

	// ----------------------------
	//  sets up the data structures for sending the Call message
	//  (e.g. address of Replier)
	// ----------------------------
	caller_function = MD_CALLER_FUNCTION;
	md_replier.sg_node = AM_SAME_NODE;
	md_replier.func_or_stat = MD_REPLIER_FUNCTION;
	md_replier.next_station = MVB_DEVICE_ADDRESS2; 
	md_replier.topo_counter = AM_ANY_TOPO;
	in_msg_size = REPLY_MESSAGE_SIZE;
	out_msg_size = send_size;
	md_caller_state = MD_STATE_WAIT_FOR_CALL_CONFIRM;
	
	am_call_request                 \
	(                               \
		caller_function,            \
		&md_replier,                \
		md_caller_send,             \
		out_msg_size,               \
		&md_caller_text_receive[0], \
		in_msg_size,                \
		100,                        \
		receive_call_confirm,            \
		&md_caller_ext_ref          \
	);	
	
	return(0);	
} //end of receive_do_call_request 

// --------------------------------------------------------------------------
//  Procedure : receive_receive_confirm (Replier)
//
//  Purpose   : This procedure will be executed, when a Call message
//              is complete received.
// --------------------------------------------------------------------------
static void
receive_receive_confirm
(
	UNSIGNED8 			replier_function,   
	const AM_ADDRESS 	*caller,  
	void 				*in_msg_adr,
	UNSIGNED32 			in_msg_size,
	void 				*replier_ref   
)
{
	char * p;
	// avoid warnings 
	caller = caller;
	in_msg_adr  = in_msg_adr;
	in_msg_size = in_msg_size;

	p = in_msg_adr;
	md_replier_function = replier_function;
	md_replier_ref = replier_ref;
	md_replier_state = MD_STATE_PROCESS_RECEIVE_CONFIRM;
	
	switch(rcv_file_stat)
	{
		case RCV_FILE_STAT_FILENAME:
		{
			strcpy(Rcv_File_Name, p);   
			Send_File_Name[0] = '1';
			Send_File_Name[1] = '_';
			Send_File_Name[2] = 0;
			strcat(Send_File_Name,Rcv_File_Name );	//send_file_name = 1_in_msg_adr
			rcv_file_stat ++;
			printw("File name: %s\n", p);
			refresh();
		}
			break;
		case RCV_FILE_STAT_FILESIZE:
		{
			Rcv_File_Size = *((UNSIGNED32 *) p);  
			Send_File_Size=Rcv_File_Size;
			rcv_file_stat ++;
			if (Rcv_File_Size <= 0)                         
			{
				rcv_file_stat = RCV_FILE_STAT_IDLE;
			}
			printw("File size: %lu bytes\n", Rcv_File_Size);
			refresh();
			if ((fp_Rcv_File = fopen(Rcv_File_Name, "wb")) == NULL)
			{
				printw("Can not create file for receiving file.\n");
				rcv_file_stat = RCV_FILE_STAT_IDLE;
			}
		}
			break;
		case RCV_FILE_STAT_FILE:
		{
			printw("..");
			refresh();	
			if ( fwrite (p, in_msg_size, 1, fp_Rcv_File) != 1)  
			{
				printw("file write error\n");				
				if (fclose(fp_Rcv_File) != 0)
				{
					printw("close file error!\n");
				}
				Rcv_Counter   = 0;
				rcv_file_stat = RCV_FILE_STAT_IDLE;
			}
			else                                                         
			{
				Rcv_Counter += in_msg_size;
				if (Rcv_Counter >= Rcv_File_Size)
				{
					printw("\nFile receive finished\n");
					bDone_Rcv_File = TRUE;            
					if (fclose(fp_Rcv_File) != 0)
					printw("close file error!\n");
					refresh();
				}
			}
		}
			break;
		case RCV_FILE_STAT_IDLE: 
		{
			if (0xFF == * ((int *)p))	
			{
				rcv_file_stat = RCV_FILE_STAT_FILENAME;
				printw("\nStart receiving file......\n");
				refresh();
			}
		}
			break;
		default:
			break;
	}
	if(bDone_Rcv_File == TRUE)
	{
		rcv_file_stat = RCV_FILE_STAT_IDLE;
	}
}// end of receive_receive_confirm 

// --------------------------------------------------------------------------
//  Procedure : receive_reply_confirm (Replier)
//
//  Purpose   : This procedure will be executed, when a Reply message
//              is complete send.
// --------------------------------------------------------------------------
static void
receive_reply_confirm
(
	UNSIGNED8 	replier_function,
	void 		*replier_ref
)
{
	//avoid warnings
	replier_function = replier_function;
	replier_ref = replier_ref;
	md_replier_state = MD_STATE_PROCESS_REPLY_CONFIRM;
} 

// --------------------------------------------------------------------------
//  Procedure : receive_do_receive_request
//
//  Purpose   : Informs the Messenger, that the Replier is ready to receive
//              an incoming Call message.
// --------------------------------------------------------------------------
UNSIGNED16
receive_do_receive_request (void)
{
	AM_RESULT 	am_result;
	UNSIGNED16 	counter;
	UNSIGNED8 	replier_function;
	UNSIGNED32 	in_msg_size;

	// ----------------------------
	//  clear variable "md_replier_text_send" and "md_replier_text_receive"
	// ----------------------------
	for (counter=0; counter<MD_SIZE; counter++)
	{
		md_replier_text_receive[counter] = 0;
	} 
	for (counter=0; counter<REPLY_MESSAGE_SIZE; counter++)
	{
		md_replier_text_send[counter] = 0;
	}

	// ----------------------------
	//  informs the Messenger, that the Replier is ready to receive
	//  an incoming Call message
	// ----------------------------
	replier_function = MD_REPLIER_FUNCTION;
	in_msg_size = MD_SIZE;
	md_replier_state = MD_STATE_WAIT_FOR_RECEIVE_CONFIRM;

	am_result =                             \
		am_receive_request                  \
		(                                   \
			replier_function,               \
			&md_replier_text_receive[0],    \
			in_msg_size,                    \
			&md_replier_ext_ref             \
		);
	if (am_result != AM_OK)
	{
		md_replier_state = MD_STATE_DO_RECEIVE_REQUEST;
		return((UNSIGNED16)am_result);
	}
	
	return(0);
} //end of receive_do_receive_request 

// --------------------------------------------------------------------------
//  Procedure : receive_do_reply_request (Replier)
//
//  Purpose   : Requests to send a Reply message in response to a previously
//              received Call message.
// --------------------------------------------------------------------------
UNSIGNED16
receive_do_reply_request (void)
{
	AM_RESULT 	am_result;
	UNSIGNED16 	counter;
	UNSIGNED32 	out_msg_size;
	UNSIGNED8 	status;

	// ----------------------------
	//  clear variable "md_replier_text_send"
	// ----------------------------
	for (counter=0; counter<REPLY_MESSAGE_SIZE; counter++)
	{
		md_replier_text_send[counter] = 0;
	} 

	// ----------------------------
	//  set variable "md_replier_text_send"
	// ----------------------------
	// always reply "OK!" in response to a previously received Call message
	// can change according to application
	md_replier_text_send[0] = 'O';
	md_replier_text_send[1] = 'K';
	md_replier_text_send[2] = '!';
	md_replier_text_send[3] = 0;
    
	// ----------------------------
	//  requests to send a Reply message in response to a previously
	//  received Call message
	// ----------------------------
	status = md_replier_status;
	out_msg_size = REPLY_MESSAGE_SIZE;    
	md_replier_state = MD_STATE_WAIT_FOR_REPLY_CONFIRM;

	am_result =							\
		am_reply_request				\
		(								\
			md_replier_function,		\
			&md_replier_text_send[0],	\
			out_msg_size,				\
			md_replier_ref,				\
			status						\
		);
	if (am_result != AM_OK)
	{
		md_replier_state = MD_STATE_DO_REPLY_REQUEST;
		return((UNSIGNED16)am_result);
	} 
	
	return(0);
} //end of receive_do_reply_request 

// --------------------------------------------------------------------------
//  Procedure : mixed_md_cycle
//
//  Purpose   : Perform Message Data communication.
// --------------------------------------------------------------------------
UNSIGNED16
receive_file_cycle (void)
{
	UNSIGNED16 	result = 0;
	UNSIGNED8 	char_temp; 	
	BOOLEAN1 	bopen_of_file  = TRUE;
	md_caller_state = MD_STATE_IDLE;
	md_replier_state = MD_STATE_DO_RECEIVE_REQUEST;
	
	send_file_stat = SEND_FILE_STAT_IDLE;      
	rcv_file_stat  = RCV_FILE_STAT_IDLE;         

		md_send_temp = (CHARACTER8 *)malloc(MD_SIZE);
	if (NULL == md_send_temp)
	{
		printw("No memory for md_send_temp\n");
	}
	md_caller_text_receive = (CHARACTER8 *)malloc(REPLY_MESSAGE_SIZE);
	if (NULL == md_caller_text_receive)
	{
		printw("No memory for md_caller_text_receive\n");
	}
	md_replier_text_receive = (CHARACTER8 *)malloc(MD_SIZE);
	if (NULL == md_replier_text_receive)
	{
		printw("No memory for md_replier_text_receive\n");
	}
	md_replier_text_send = (CHARACTER8 *)malloc(REPLY_MESSAGE_SIZE);
	if (NULL == md_replier_text_send)
	{
		printw("No memory for md_replier_text_send\n");
	}
	       
	while(1)
	{
		if ( kbhit() )
		{
			char_temp = getch();
			if (char_temp == 27)
			{
		       	break;
			}	
		}
		if ((send_file_stat == SEND_FILE_STAT_OVER)&&(md_caller_state == MD_STATE_IDLE))
		{
			if (fclose(fp_Rcv_File) != 0)
			{
				printw("close file error!\n");
			}
			printw("\nFile send finished\n");
			refresh();
			break;
		}
	   	   	 	
		// ----------------------------------------------------------------------
		//  handle Replier
		// ----------------------------------------------------------------------
		switch(md_replier_state)
		{
			case(MD_STATE_DO_RECEIVE_REQUEST):
				result = receive_do_receive_request();
				if (result != 0)
				{
					return(result);
				} 
				break;
			case(MD_STATE_WAIT_FOR_RECEIVE_CONFIRM):
				;
				break;
			case(MD_STATE_PROCESS_RECEIVE_CONFIRM):
				md_replier_state = MD_STATE_DO_REPLY_REQUEST;
				break;
			case(MD_STATE_DO_REPLY_REQUEST):
				result = receive_do_reply_request();
				if (result != 0)
				{
					return(result);
				} 
				break;
			case(MD_STATE_WAIT_FOR_REPLY_CONFIRM):
				;
				break;
			case(MD_STATE_PROCESS_REPLY_CONFIRM):
				if(bDone_Rcv_File==TRUE)
				{
					md_replier_state = MD_STATE_IDLE;
				}
				else
				{
					md_replier_state = MD_STATE_DO_RECEIVE_REQUEST;				
				}
				break;
			default:
				;
		} //end of switch(md_replier_state)

		if ((bDone_Rcv_File)&&(bopen_of_file))
		{
			if ((fp_Rcv_File = fopen(Rcv_File_Name, "rb")) == NULL)
			{
				printw("Can not create file for sending file.\n");
			}
			bopen_of_file=FALSE;
		}
     
		// ----------------------------------------------------------------------
		//  handle Caller
		// ----------------------------------------------------------------------
		switch(md_caller_state)
		{
			case(MD_STATE_DO_CALL_REQUEST):
				switch (send_file_stat)
				{
					case (SEND_FILE_STAT_START):
						result = receive_do_call_request(&FILE_START, 1);
						send_file_stat ++;
						break;
					case (SEND_FILE_STAT_FILENAME):
						if (!bwait_for_replier)
						{
							printw("File name: %s\n", Send_File_Name);
							refresh();
						}
						result = receive_do_call_request(&Send_File_Name, 16);
						send_file_stat ++;
						break;
					case (SEND_FILE_STAT_FILESIZE):
						if (!bwait_for_replier)
						{
							printw("File size: %lu bytes\n", Send_File_Size);
							refresh();
						}
						result = receive_do_call_request(&Send_File_Size, 4);
						send_file_stat ++;
						break;
					case (SEND_FILE_STAT_FILE):
						if ( bend_of_file == FALSE)
						{
							if (!bwait_for_replier)
							{
								fread ( md_send_temp, MD_SIZE, 1, fp_Rcv_File);
								printw("..");
								refresh();
							}
							if ((Send_File_Size - send_counter) < MD_SIZE)
							{
								send_num= Send_File_Size - send_counter;
							}
							else
							{
								send_num = MD_SIZE;
							}
							send_counter += send_num;
							if (send_counter >= Send_File_Size)
							{
								bend_of_file = TRUE;
							}
							result = receive_do_call_request ( md_send_temp,send_num);													
						}                                 
						if (bend_of_file==TRUE)
						{					
							send_file_stat ++;
							send_file_stat ++;
						}
						break;
					case (SEND_FILE_STAT_IDLE):
						if (bDone_Rcv_File)
						{
							send_file_stat=SEND_FILE_STAT_START;
							printw("\nStart sending file......\n");
							refresh();						
						}
						break;
					default:
						;
				}							
				if (result != 0)
				{
					return(result);
				}
#ifdef O_MD_TIMEOUT
				md_time_start = (UNSIGNED32)time(NULL);
#endif
				break;
			case(MD_STATE_WAIT_FOR_CALL_CONFIRM):
#ifdef O_MD_TIMEOUT	
				// ----------------------------------------------------------------------
				//  handle timeout
				// ----------------------------------------------------------------------
				md_time_stop = (UNSIGNED32)time(NULL);
				md_time_diff = (UNSIGNED32)(md_time_stop - md_time_start);
				if (md_time_diff > MD_TIMEOUT)
				{
#ifdef O_PRINT_ERROR
					printw("ERROR: timeout\n");
					printw("- md_caller_state =%d\n", md_caller_state);
					printw("- md_replier_state=%d\n", md_replier_state);
#endif 
					return(1);
				}
#endif

				break;
			case(MD_STATE_PROCESS_CALL_CONFIRM):
				md_caller_state = MD_STATE_IDLE;
				break;
			case(MD_STATE_IDLE):
				if (bDone_Rcv_File&&(md_replier_state == MD_STATE_IDLE))
				{
					md_caller_state = MD_STATE_DO_CALL_REQUEST;					
				}
				break;
			default:
				;
		}//end of switch(md_caller_state)
     
#ifdef O_OS_SINGLE
		{
			// ----------------------------------------------------------------------
			//  This procedure is not available and required for multi-threaded
			//  versions of the MVB Client Driver Software.
			//  Callback functions (i.e. device status callback procedure, message
			//  data confirmation procedures) are only processed, if this procedure
			//  is executed by the application.
			//  If a device status callback procedure is available at MVB client, it
			//  will be processed immediately.
			//
			//  max_package_number = 0:
			//  This procedure checks, if a message data confirmation procedure is
			//  available from MVB server. If so, then it will be transmitted from
			//  MVB server to MVB client and processed immediately.
			//
			//  max_package_number > 0:
			//  This procedure checks, if a message data confirmation procedure is
			//  available from MVB server. If so, then up to "max_package_number"
			//  packages will be transmitted from MVB server to MVB client. If the
			//  message data confirmation procedure is fully transmitted to the MVB
			//  client, then it will be processed immediately.
			//  Note: A message data confirmation procedure transmitted from MVB
			//        server to MVB client are divided into packages of 45 bytes
			//        (40 data bytes including parameters).
			//  Note: By specifying the parameter "max_package_number" the run-time
			//        of the procedure "gf_poll_callback" can be limited.
			//  Note: If a transmission of a message data callback procedure is in
			//        progress between MVB server and MVB client (indicated
			//        bCallbackBusy=TRUE), then no procedures of the Message Data
			//        Interface are allowed to be called.
			// ----------------------------------------------------------------------		
			GF_RESULT 	gf_result;
			UNSIGNED32 	max_package_number;
			BOOLEAN1 	bCallbackBusy;

			max_package_number = 0;
			bCallbackBusy = FALSE;
			gf_result = gf_poll_callback(max_package_number, &bCallbackBusy);
			if (gf_result != GF_OK)
			{
				return((UNSIGNED16)gf_result);
			} 
		}
#endif 


	}//end of while(1)
	
	free(md_send_temp);
	free(md_caller_text_receive);
	free(md_replier_text_receive);
	free(md_replier_text_send);
	
	return(0);	
} //end of mixed_md_cycle

// --------------------------------------------------------------------------
//  Procedure : send_file_cycle
//
//  Purpose   : Perform Message Data communication.
// --------------------------------------------------------------------------
UNSIGNED16
send_file_cycle (void)
{
	UNSIGNED16 	result = 0;
	UNSIGNED8 	char_temp; 	
	BOOLEAN1 	bclose_of_file = TRUE;
	BOOLEAN1 	bcompare_files = TRUE;
	
	md_replier_state = MD_STATE_IDLE;
	md_caller_state = MD_STATE_IDLE;

	send_file_stat = SEND_FILE_STAT_IDLE;      
	rcv_file_stat  = RCV_FILE_STAT_IDLE;         

	md_send_temp = (CHARACTER8 *)malloc(MD_SIZE);
	if(NULL == md_send_temp)
	{
		printw("No memory for md_send_temp\n");
	}
	md_caller_text_receive = (CHARACTER8 *)malloc(REPLY_MESSAGE_SIZE);
	if(NULL == md_caller_text_receive)
	{
		printw("No memory for md_caller_text_receive\n");
	}
	md_replier_text_receive = (CHARACTER8 *)malloc(MD_SIZE);
	if(NULL == md_replier_text_receive)
	{
		printw("No memory for md_replier_text_receive\n");
	}
	md_replier_text_send = (CHARACTER8 *)malloc(REPLY_MESSAGE_SIZE);
	if(NULL == md_replier_text_send)
	{
		printw("No memory for md_replier_text_send\n");
	}
	
	while(1)
	{
		printw("Please input the file name you want to send:");
		refresh();
		echo();		
		getstr(Send_File_Name); 
		noecho();			
		send_file_stat = SEND_FILE_STAT_START;
		if((fp_Send_File = fopen(Send_File_Name, "rb"))== NULL)
		{
			printw("Can not open file.\n");
			refresh();			
		}
		else 
		{
			break;
		}
	}
	
	Send_File_Size = get_file_size(fp_Send_File);
	printw("Start sending file......\n");
	printw("File size: %lu bytes\n", Send_File_Size);
	refresh();	
	       
	while(1)
	{
		if( kbhit() )
		{
			char_temp = getch();
			if(char_temp == 27)
			{
		       	break;
			}	
		}
		if((bDone_Rcv_File)&&(md_replier_state==MD_STATE_DO_RECEIVE_REQUEST))
		{
			break;
		}
	   	    	 	
		// ----------------------------
		//  handle Replier
		// ----------------------------
		switch(md_replier_state)
		{
			case(MD_STATE_DO_RECEIVE_REQUEST):
				result = send_do_receive_request();
				if (result != 0)
				{
					return(result);
				} 
				break;
			case(MD_STATE_WAIT_FOR_RECEIVE_CONFIRM):
				;
				break;
			case(MD_STATE_PROCESS_RECEIVE_CONFIRM):
				md_replier_state = MD_STATE_DO_REPLY_REQUEST;
				break;
			case(MD_STATE_DO_REPLY_REQUEST):
				result = send_do_reply_request();
				if (result != 0)
				{
					return(result);
				} 
				break;
			case(MD_STATE_WAIT_FOR_REPLY_CONFIRM):
				;
				break;
			case(MD_STATE_PROCESS_REPLY_CONFIRM):
				md_replier_state = MD_STATE_DO_RECEIVE_REQUEST;
				if(bDone_Rcv_File==TRUE)
				{
					bFinish_Rcv_File=TRUE;
				}
				break;
			case(MD_STATE_IDLE):
				if(bend_of_file==TRUE)
				{
					md_replier_state = MD_STATE_DO_RECEIVE_REQUEST;	
				}
			default:
				;
		} //end of switch(md_replier_state)
	         
		// ----------------------------
		//  handle Caller
		// ----------------------------
		switch(md_caller_state)
		{
			case(MD_STATE_DO_CALL_REQUEST):

				switch (send_file_stat)
				{
					case (SEND_FILE_STAT_START):
#ifdef O_MD_TIME_CONSUMPTION
						md_send_time_start = (UNSIGNED32)time(NULL);
#endif	
						result = send_do_call_request(&FILE_START, 1);
						send_file_stat ++;
						break;
					case (SEND_FILE_STAT_FILENAME):						
						result = send_do_call_request(&Send_File_Name, 16);
						send_file_stat ++;
						break;
					case (SEND_FILE_STAT_FILESIZE):						
						result = send_do_call_request(&Send_File_Size, 4);
						send_file_stat ++;
						break;
					case (SEND_FILE_STAT_FILE):
						if ( bend_of_file == FALSE)
						{
							if (!bwait_for_replier)
							{
								fread ( md_send_temp, MD_SIZE, 1, fp_Send_File);
								printw("..");
								refresh();
							}
							if ((Send_File_Size - send_counter) < MD_SIZE)
							{
								send_num= Send_File_Size - send_counter;
							}
							else
							{
								send_num = MD_SIZE;
							}
							send_counter += send_num;
							if (send_counter >= Send_File_Size)
							{
								bend_of_file = TRUE;
							}
							result = send_do_call_request ( md_send_temp,send_num);							
						}                                 
						if (bend_of_file==TRUE)
						{					
							send_file_stat ++;
							send_file_stat ++;
						}
						break;
					case (SEND_FILE_STAT_IDLE):						
						break;
					default:
						;
				}							
				if (result != 0)
				{
					return(result);
				}
#ifdef O_MD_TIMEOUT
				md_time_start = (UNSIGNED32)time(NULL);
#endif				
				break;
			case(MD_STATE_WAIT_FOR_CALL_CONFIRM):
#ifdef O_MD_TIMEOUT	
				// ----------------------------------------------------------------------
				//  handle timeout
				// ----------------------------------------------------------------------
				md_time_stop = (UNSIGNED32)time(NULL);
				md_time_diff = (UNSIGNED32)(md_time_stop - md_time_start);
				if (md_time_diff > MD_TIMEOUT)
				{
#ifdef O_PRINT_ERROR
					printw("ERROR: timeout\n");
					printw("- md_caller_state =%d\n", md_caller_state);
					printw("- md_replier_state=%d\n", md_replier_state);
					refresh();
#endif 
					return(1);
				}
#endif
				break;
			case(MD_STATE_PROCESS_CALL_CONFIRM):
				md_caller_state = MD_STATE_IDLE;
				break;
			case(MD_STATE_IDLE):				
				md_caller_state = MD_STATE_DO_CALL_REQUEST;									
				break;
			default:
				;
		}//end of switch(md_caller_state)
     
#ifdef O_OS_SINGLE
		{
			// ----------------------------------------------------------------------
			//  This procedure is not available and required for multi-threaded
			//  versions of the MVB Client Driver Software.
			//  Callback functions (i.e. device status callback procedure, message
			//  data confirmation procedures) are only processed, if this procedure
			//  is executed by the application.
			//  If a device status callback procedure is available at MVB client, it
			//  will be processed immediately.
			//
			//  max_package_number = 0:
			//  This procedure checks, if a message data confirmation procedure is
			//  available from MVB server. If so, then it will be transmitted from
			//  MVB server to MVB client and processed immediately.
			//
			//  max_package_number > 0:
			//  This procedure checks, if a message data confirmation procedure is
			//  available from MVB server. If so, then up to "max_package_number"
			//  packages will be transmitted from MVB server to MVB client. If the
			//  message data confirmation procedure is fully transmitted to the MVB
			//  client, then it will be processed immediately.
			//  Note: A message data confirmation procedure transmitted from MVB
			//        server to MVB client are divided into packages of 45 bytes
			//        (40 data bytes including parameters).
			//  Note: By specifying the parameter "max_package_number" the run-time
			//        of the procedure "gf_poll_callback" can be limited.
			//  Note: If a transmission of a message data callback procedure is in
			//        progress between MVB server and MVB client (indicated
			//        bCallbackBusy=TRUE), then no procedures of the Message Data
			//        Interface are allowed to be called.
			// ----------------------------------------------------------------------		
			GF_RESULT 	gf_result;
			UNSIGNED32 	max_package_number;
			BOOLEAN1 	bCallbackBusy;

			max_package_number = 0;
			bCallbackBusy = FALSE;
			gf_result = gf_poll_callback(max_package_number, &bCallbackBusy);
			if (gf_result != GF_OK)
			{
				return((UNSIGNED16)gf_result);
			} 
		}
#endif 
		
		if ((send_file_stat==5)&&( bclose_of_file)&&(md_replier_state == MD_STATE_DO_RECEIVE_REQUEST))
		{  
			if (fclose(fp_Send_File) != 0)
			{ 
				printw("close file error!\n");
				refresh();
			}
			bclose_of_file =FALSE;      
		}
		
		// if send and receive file finished, compare files
		if((bFinish_Rcv_File)&&(bcompare_files))
		{			
			if ((fp_Rcv_File = fopen(Rcv_File_Name, "rb")) == NULL)
			{
				printw("open received file error!\n");
				return 1;
			}
			if ((fp_Send_File = fopen(Send_File_Name, "rb")) == NULL)
			{
				printw("open file error!\n");
				return 1;
			}

			//call compare function
			if(TRUE != compare_file(fp_Send_File, fp_Rcv_File))
			{
				printw("\nSend file and Received file do not match!\n");
				refresh();
			}
			else
			{
				printw("\nSend file and Received file match!\n");
			}
			
			fclose(fp_Send_File);
			fclose(fp_Rcv_File);
			bcompare_files=FALSE;
		}

	}//end of while(1)
	
	free(md_send_temp);
	free(md_caller_text_receive);
	free(md_replier_text_receive);
	free(md_replier_text_send);

	return(0);
} //end of mixed_md_cycle

// --------------------------------------------------------------------------
//  Procedure : md_demo
//
//  Purpose   : Perform Message Data communication.
// --------------------------------------------------------------------------
static UNSIGNED16
md_demo(void)
{
	UNSIGNED16 result;
	
	if(md_demo_type == 0)
	{
		p_demo_cycle = send_file_cycle;	
		clear();
		refresh();
		printw("******************************************************************************\n");
	 	printw("                               send  message \n");
		printw("******************************************************************************\n");
		result = (*p_demo_cycle)();
		if (result != 0)
		{
			free(md_send_temp);
			free(md_caller_text_receive);
			free(md_replier_text_receive);
			free(md_replier_text_send);
			
#ifdef O_PRINT_ERROR
			printw("ERROR: md_demo()=%u\n", result);
#endif
		} 
	}
	else
	{
		p_demo_cycle = receive_file_cycle;	
		clear();
		refresh();
		printw("******************************************************************************\n");
	 	printw("                             receive  message \n");
		printw("******************************************************************************\n");
		printw("Wait for receiving file....\n");
		refresh();
		
		result = (*p_demo_cycle)();
		if (result != 0)
		{
			free(md_send_temp);
			free(md_caller_text_receive);
			free(md_replier_text_receive);
			free(md_replier_text_send);		
		#ifdef O_PRINT_ERROR
			printw("ERROR: md_demo()=%u\n", result);
		#endif
		}

	}
	return result;
}

// --------------------------------------------------------------------------
//  Procedure : mixed_pd_prt_init
//
//  Purpose   : Sets up the MVB Traffic Store with Process Data Ports.
// --------------------------------------------------------------------------
UNSIGNED16
mixed_pd_prt_init (void)
{
	LP_RESULT lp_result;
	TS_CONFIG ts_config;
	TS_PORT_CONFIG ts_port_config[PD_PORT_NO];
	UNSIGNED16 c_ts_port_config;
	UNSIGNED16 i;
	
	// ----------------------------
	//  defines Process Data Ports
	// ----------------------------
	//	TS_PORT_SINK       0
	// 	TS_PORT_SOURCE     1
	// ----------------------------
	PD_src_port_address[0]=0xE0B;
	PD_src_port_size[0]=TS_PORT_SIZE_2;
	PD_snk_port_address[0]=0xC17;
	PD_snk_port_size[0]=TS_PORT_SIZE_4;

	// init the port config
	c_ts_port_config = 0;
	for(i = 0; i< PD_SRC_NO; i++)
	{
		ts_port_config[c_ts_port_config].port_address = PD_src_port_address[i];
		ts_port_config[c_ts_port_config].port_size    = PD_src_port_size[i];
		ts_port_config[c_ts_port_config].port_type    = TS_PORT_SOURCE;

		PD_src_port_size_word[i] = 1<<PD_src_port_size[i];
		c_ts_port_config++;
	}
	
	for(i = 0; i< PD_SNK_NO; i++)
	{
		ts_port_config[c_ts_port_config].port_address = PD_snk_port_address[i];
		ts_port_config[c_ts_port_config].port_size    = PD_snk_port_size[i];
		ts_port_config[c_ts_port_config].port_type    = TS_PORT_SINK;

		PD_snk_port_size_word[i] = 1<<PD_snk_port_size[i];
		c_ts_port_config++;
	}

#ifdef CHECK_PORT_CONFIG
	if(PD_PORT_NO != c_ts_port_config)
	{
		printw("\nport config error! please check your config!\n");
	}
#endif
	ts_config.p_ts_port_config     = ts_port_config;
	ts_config.c_ts_port_config     = c_ts_port_config;
	ts_config.supervision_interval = 16;

	// ----------------------------
	//  initialises Process Data Ports
	// ----------------------------
#ifdef O_PRINT
	printw("lp_init()\n");
	refresh();
#endif
	lp_result = lp_init(0, &ts_config);
	if(lp_result != LP_OK)
	{
	#ifdef O_PRINT
		printw("ERROR: lp_init()=%u\n", lp_result);
	#endif
		return((UNSIGNED16)lp_result);
	}

	return(0);
}

// --------------------------------------------------------------------------
//  Procedure : mixed_pd_init
//
//  Purpose   : - sets up the MVB Traffic Store with Process Data Ports
//              - sets up data structures for Process Variables of datasets
// --------------------------------------------------------------------------
UNSIGNED16
mixed_pd_init (void)
{
	UNSIGNED16  result;

	// ----------------------------
	//  sets up the MVB Traffic Store with Process Data Ports
	// ----------------------------
#ifdef O_PRINT
	printw("mixed_pd_prt_init()\n");
	refresh();
#endif
	result = mixed_pd_prt_init();
	if(result != 0)
	{
	#ifdef O_PRINT
		printw("ERROR: mixed_pd_prt_init()=%u\n", result);
	#endif
		return(result);
	}

    return(0);
} 

// --------------------------------------------------------------------------
//  Procedure : mixed_pd_cycle
//
//  Purpose   : 
//              NOTE:
//              The dataset will be handled as an array of 16-bit values.
// --------------------------------------------------------------------------
UNSIGNED16
mixed_pd_cycle (void)
{
	LP_RESULT  lp_result;
	DS_NAME    ds_name;
	UNSIGNED16 dataset[16];	// NOTE: The dataset will be handled as
							//       an array of 16-bit values.
	UNSIGNED16 freshness;
	UNSIGNED8  port_status[PD_SNK_NO] = {0};
	UNSIGNED16 port_freshness[PD_SNK_NO] = {0};
	BOOLEAN1   b_print = FALSE;
	UNSIGNED8  j, k;
	UNSIGNED16 i;
	static UNSIGNED16 count = 0;

#ifdef READ_DSW
	//dsw read	
	DSW_NAME *dsw;
	UNSIGNED16 dsw_value = 0, dsw_value_back = 0, dsw_fress;
	UNSIGNED16 dsw_cnt = 0;
#endif

	// ----------------------------
	//  NOTE:
	//  The dataset will be handled as an array of 16-bit values.
	// ----------------------------
#ifdef READ_DSW
	// Reading the DSW
	dsw->device_address = MVB_DEVICE_ADDRESS1;
	dsw->ts_id = 0;
	dsw_read(dsw, &dsw_value, &dsw_fress);
	dsw_value_back = dsw_value;
#endif

	if(count % 200 == 0)
	{
		b_print = TRUE;

		for(i = 0; i < PD_SRC_NO; i++)
		{
			for(j = 0; j < PD_src_port_size_word[i];j++)
			{
				port_data_src[i][j] = (++ port_data_src[i][j] % 0xFFFF);
			}
		}
        count = 0;
	}
    count ++;

	// ----------------------------
	//  put datasets.
	// ----------------------------
	for(i = 0; i<PD_SRC_NO; i++)
	{
		ds_name.ts_id = 0;
		ds_name.port_address = PD_src_port_address[i];
		lp_result = lp_put_dataset(&ds_name,&port_data_src[i][0]);
		if(lp_result != LP_OK)
		{
		#ifdef O_PRINT
			printw("ERROR: lp_put_dataset(0x%03X)=%u\n", \
				ds_name.port_address, lp_result);
		#endif
		    return((UNSIGNED16)lp_result);
		}
	}

	// ----------------------------
	//  get datasets.
	// ----------------------------
	for(i = 0; i < PD_SNK_NO; i ++)
	{
		ds_name.ts_id        = 0;
		ds_name.port_address = PD_snk_port_address[i];
		lp_result = lp_get_dataset(&ds_name, dataset, &freshness);
		if(lp_result != LP_OK)
		{
		#ifdef O_PRINT
			printw("ERROR: lp_get_dataset(0x%03X)=%u\n", \
				ds_name.port_address, lp_result);
		#endif
			return((UNSIGNED16)lp_result);
		}
		
		for(j = 0; j < PD_snk_port_size_word[i]; j ++)
		{
			if(port_data_snk[i][j] != dataset[j])
			{
				break;
			}
		}
		if(j != PD_snk_port_size_word[i])
		{
			b_print = TRUE;
			for(k = 0; k < PD_snk_port_size_word[i]; k++)
			{
				port_data_snk[i][k] = dataset[k];
			}
		}

		if(port_freshness[i] != freshness)
		{
			port_freshness[i] = freshness;
		}
	}

#ifdef READ_DSW
	// ----------------------------
	// Reading the DSW
	// ----------------------------
	dsw_read(dsw, &dsw_value, &dsw_fress);
	if(dsw_value_back != dsw_value)
	{
		b_print = TRUE;
		if((dsw_value_back & 0x00FF) != (dsw_value & 0x00FF))
		{
			dsw_cnt ++;
		}
		dsw_value_back = dsw_value;
	}
#endif

	// print the info if necessary
	if(b_print)
	{
		
		move(5,15);

		for(i = 0; i < PD_SRC_NO; i ++)
		{

			for(j = 0; j < PD_src_port_size_word[i]; j ++)
			{
				if(j == 8)
				{
					printw("\n              ");
				}
				printw(" %04X", port_data_src[i][j]);
			}
			printw("\n");
		}
		move(9,15);

		for(i = 0; i < PD_SNK_NO; i ++)
		{

			for(j = 0; j < PD_snk_port_size_word[i]; j ++)
			{
				if(j == 8)
				{
					printw("\n              ");
				}
				printw(" %04X", port_data_snk[i][j]);
			}
			for(; j<8; j++)
			{
				printw("     ");
			}
			printw("    %02X",port_status[i]);
	 		printw("        ");
	 		printw("%04X",port_freshness[i]);
	  		printw("\n");
		}
#ifdef READ_DSW
		printw("#%05d#\n", dsw_cnt);
		printw("\nlocal device address: 0x%04x\t", MVB_DEVICE_ADDRESS1);
		printw("it's device status: 0x%04x\n", dsw_value);		
		refresh();

#endif
		b_print = FALSE;
		refresh();

	}//if (b_print)
	
    return(0);
}

// --------------------------------------------------------------------------
//  Procedure : mixed_call_confirm (Caller)
//
//  Purpose   : This procedure will be executed, when a Reply message
//              is complete received.
// --------------------------------------------------------------------------
void
mixed_call_confirm
(
	UNSIGNED8 			caller_function,   
	void 				*am_caller_ref,
	const AM_ADDRESS 	*replier,        
	void 				*in_msg_adr,
	UNSIGNED32 			in_msg_size	,
	AM_RESULT 			status
)
{

	// avoid warning
	caller_function = caller_function;
	am_caller_ref = am_caller_ref;
	replier = replier;
	in_msg_adr = in_msg_adr;
	in_msg_size	= in_msg_size;
    bwait_for_replier = FALSE;
	md_caller_status = (AM_RESULT)status;
#ifdef O_PRINT_ERROR
	if ((md_caller_status != AM_OK)&&(md_caller_status != AM_NO_READY_INST_ERR))
	{
		move(19,1);
		printw("ERROR:caller_status=%d\n",md_caller_status);
	}
	if(md_caller_status == AM_OK)
	{
		move(19,1);
		printw("                            ");
	}
#endif
	if (md_caller_status == AM_NO_READY_INST_ERR)
	{
		if(send_temp[0] != 'A')
		{
			send_temp[0]--;
		}
        bwait_for_replier = TRUE;
	}
	md_caller_state = MD_STATE_PROCESS_CALL_CONFIRM;
} //end of mixed_call_confirm

// --------------------------------------------------------------------------
//  Procedure : mixed_do_call_request (Caller)
//
//  Purpose   : Requests to send a Call_Message.              
// --------------------------------------------------------------------------
UNSIGNED16
mixed_do_call_request (void *md_caller_send, UNSIGNED32 send_size)
{
	UNSIGNED16 	counter;
	UNSIGNED8 	caller_function;
	AM_ADDRESS 	md_replier;
	UNSIGNED32 	out_msg_size;
	UNSIGNED32 	in_msg_size;
	CHARACTER8  md_caller_string_receive[MD_SIZE];
	CHARACTER8  md_caller_string_send[MD_SIZE];

	// ----------------------------
	//  clear variable "md_caller_text_send" and "md_caller_text_receive"
	// ----------------------------
	for (counter=0; counter<MD_SIZE; counter++)
	{
		md_caller_string_send[counter] = 0;
		md_caller_string_receive[counter] = 0;
	}

	// ----------------------------
	//  sets up the data structures for sending the Call message
	//  (e.g. address of Replier)
	// ----------------------------
	caller_function = MD_CALLER_FUNCTION;
	md_replier.sg_node = AM_SAME_NODE;
	md_replier.func_or_stat = MD_REPLIER_FUNCTION;
	md_replier.next_station = MVB_DEVICE_ADDRESS2;
	md_replier.topo_counter = AM_ANY_TOPO;
	in_msg_size = MD_SIZE;
	out_msg_size = send_size;	
	md_caller_state = MD_STATE_WAIT_FOR_CALL_CONFIRM;

	am_call_request                 \
	(                               \
		caller_function,            \
		&md_replier,                \
		md_caller_send,    			\
		out_msg_size,               \
		&md_caller_string_receive[0], \
		in_msg_size,                \
		100,                        \
		mixed_call_confirm,            \
		&md_caller_ext_ref          \
	);

	return(0);
} //end of mixed_do_call_request

// --------------------------------------------------------------------------
//  Procedure : mixed_receive_confirm (Replier)
//
//  Purpose   : This procedure will be executed, when a Call message
//              is complete received.
// --------------------------------------------------------------------------
static void
mixed_receive_confirm
(
	UNSIGNED8 			replier_function,
	const AM_ADDRESS 	*caller,  
	void 				*in_msg_adr,
	UNSIGNED32 			in_msg_size,
	void 				*replier_ref
)
{
	// avoid warnings
	caller = caller;
	in_msg_adr  = in_msg_adr;
	in_msg_size = in_msg_size;

	md_replier_function = replier_function;
	md_replier_ref = replier_ref;
	md_replier_state = MD_STATE_PROCESS_RECEIVE_CONFIRM;    
	strcpy(md_receive_temp,in_msg_adr);
	b_refresh_flag=TRUE;   		
} //end of  mixed_receive_confirm

// --------------------------------------------------------------------------
//  Procedure : mixed_reply_confirm (Replier)
//
//  Purpose   : This procedure will be executed, when a Reply message
//              is complete send.
// --------------------------------------------------------------------------
static void
mixed_reply_confirm
(
	UNSIGNED8 	replier_function,
	void 		*replier_ref
)
{
	//avoid warnings
	replier_function = replier_function;
	replier_ref = replier_ref;
	md_replier_state = MD_STATE_PROCESS_REPLY_CONFIRM;
}

// --------------------------------------------------------------------------
//  Procedure : mixed_do_receive_request
//
//  Purpose   : Informs the Messenger, that the Replier is ready to receive
//              an incoming Call message.
// --------------------------------------------------------------------------
UNSIGNED16
mixed_do_receive_request (void)
{
	AM_RESULT 	am_result;
	UNSIGNED16 	counter;
	UNSIGNED8 	replier_function;
	UNSIGNED32 	in_msg_size;
	CHARACTER8  md_replier_string_receive[MD_SIZE];

	// ----------------------------
	//  clear variable "md_replier_text_send" and "md_replier_text_receive"
	// ----------------------------
	for (counter=0; counter<MD_SIZE; counter++)
	{
		md_replier_string_receive[counter] = 0;
	}
	
	// ----------------------------
	//  informs the Messenger, that the Replier is ready to receive
	//  an incoming Call message
	// ----------------------------
	replier_function = MD_REPLIER_FUNCTION;
	in_msg_size = MD_SIZE;
	md_replier_state = MD_STATE_WAIT_FOR_RECEIVE_CONFIRM;
	
	am_result =                             \
		am_receive_request                  \
		(                                   \
			replier_function,               \
			&md_replier_string_receive[0],    \
			in_msg_size,                    \
			&md_replier_ext_ref             \
		);
	if (am_result != AM_OK)
	{
		md_replier_state = MD_STATE_DO_RECEIVE_REQUEST;
		return((UNSIGNED16)am_result);
	} 
	
	return(0);
} //end of mixed_do_receive_request

// --------------------------------------------------------------------------
//  Procedure : mixed_do_reply_request (Replier)
//
//  Purpose   : Requests to send a Reply message in response to a previously
//              received Call message.
// --------------------------------------------------------------------------
UNSIGNED16
mixed_do_reply_request (void)
{
	AM_RESULT   	am_result;
	UNSIGNED16  	counter;
	UNSIGNED32  	out_msg_size;
	UNSIGNED8   	status;
	CHARACTER8      md_replier_string_send[MD_SIZE];

	// ----------------------------
	//  clear variable "md_replier_string_send"
	// ----------------------------
	for (counter=0; counter<MD_SIZE; counter++)
	{
		md_replier_string_send[counter] = 0;
	}

	// ----------------------------
	//  set variable "md_replier_string_send"
	// ----------------------------
	//always reply "OK!" in response to a previously received Call message
	//can change according to application
	md_replier_string_send[0] = 'O';
	md_replier_string_send[1] = 'K';
	md_replier_string_send[2] = '!';
	md_replier_string_send[3] = '\0';
	out_msg_size = 4;

	// ----------------------------
	//  requests to send a Reply message in response to a previously
	//  received Call message
	// ----------------------------
	status = md_replier_status;
	md_replier_state = MD_STATE_WAIT_FOR_REPLY_CONFIRM;

	am_result =                         \
		am_reply_request                \
		(                               \
			md_replier_function,        \
			&md_replier_string_send[0],   \
			out_msg_size,               \
			md_replier_ref,             \
			status                      \
		);
	if (am_result != AM_OK)
	{
		md_replier_state = MD_STATE_DO_REPLY_REQUEST;
		return((UNSIGNED16)am_result);
	} 

	return(0);
} //end of mixed_do_reply_request

// --------------------------------------------------------------------------
//  Procedure : mixed_md_cycle
//
//  Purpose   : Perform Message Data communication.
// --------------------------------------------------------------------------
UNSIGNED16
mixed_md_cycle (void)
{
 	UNSIGNED16  result;
	static time_t time1 = 0;
	static time_t time2 = 0;
	
    if(b_refresh_flag==TRUE)
	{
		move(14,12);
		printw("%s\n\n",md_receive_temp);
		refresh();
        b_refresh_flag = FALSE;
	}

	// ----------------------------
	//  handle Replier
	// ----------------------------
	switch(md_replier_state)
	{
		case(MD_STATE_DO_RECEIVE_REQUEST):
			result = mixed_do_receive_request();
			if (result != 0)
			{
				return(result);
			}
			break;
		case(MD_STATE_WAIT_FOR_RECEIVE_CONFIRM):
			;
			break;
		case(MD_STATE_PROCESS_RECEIVE_CONFIRM):
			md_replier_state = MD_STATE_DO_REPLY_REQUEST;
			break;
		case(MD_STATE_DO_REPLY_REQUEST):
			result = mixed_do_reply_request();
			if (result != 0)
			{
				return(result);
			}
			break;
		case(MD_STATE_WAIT_FOR_REPLY_CONFIRM):
			break;
		case(MD_STATE_PROCESS_REPLY_CONFIRM):
			md_replier_state = MD_STATE_DO_RECEIVE_REQUEST;
			break;
		case(MD_STATE_IDLE):
			break;
		default:
			break;
	} //end of switch(md_replier_state)

	// ----------------------------
	//  handle Caller
	// ----------------------------
	switch(md_caller_state)
	{
		case(MD_STATE_IDLE):
			break;
		case(MD_STATE_DO_CALL_REQUEST):
			result = mixed_do_call_request(send_temp, 1);
			if (result != 0)
			{
				return(result);
            }
            else
            {	
	            move(16,12);
				printw("%s",send_temp);
			}
#ifdef O_MD_TIMEOUT
			md_time_start = (UNSIGNED32)time(NULL);
#endif
			break;
		case(MD_STATE_WAIT_FOR_CALL_CONFIRM):
#ifdef O_MD_TIMEOUT
			// ----------------------------
			//  handle timeout
			// ----------------------------
			md_time_stop = (UNSIGNED32)time(NULL);
			md_time_diff = (UNSIGNED32)(md_time_stop - md_time_start);
			if (md_time_diff > MD_TIMEOUT)
			{
//                md_caller_state = MD_STATE_DO_CALL_REQUEST;
#ifdef O_PRINT_ERROR
					printw("ERROR: timeout\n");
					printw("- md_caller_state =%d\n", md_caller_state);
					printw("- md_replier_state=%d\n", md_replier_state);
					refresh();

#endif
					return(1);
			}
#endif

			break;
		case(MD_STATE_PROCESS_CALL_CONFIRM):
            if(!bwait_for_replier)
            {
				time2 = time(NULL);
	            if((time2 - time1) >= 2)
	            {
		            time1 = time2;
	                if((send_temp[0] >= 'Z')||(send_temp[0] <= 'A'))
	                {
	                    send_temp[0] = 'A';
	                }
					send_temp[0]++;

		         }
            }
			md_caller_state = MD_STATE_DO_CALL_REQUEST;
            break;
		case(MD_STATE_WAIT_FOR_REPLIER):
			md_caller_state = MD_STATE_DO_CALL_REQUEST;
			break;
		default:
			break;
	} //end of switch(md_caller_state)

#ifdef O_OS_SINGLE
	{
		// ----------------------------------------------------------------------
		//  This procedure is not available and required for multi-threaded
		//  versions of the MVB Client Driver Software.
		//  Callback functions (i.e. device status callback procedure, message
		//  data confirmation procedures) are only processed, if this procedure
		//  is executed by the application.
		//  If a device status callback procedure is available at MVB client, it
		//  will be processed immediately.
		//
		//  max_package_number = 0:
		//  This procedure checks, if a message data confirmation procedure is
		//  available from MVB server. If so, then it will be transmitted from
		//  MVB server to MVB client and processed immediately.
		//
		//  max_package_number > 0:
		//  This procedure checks, if a message data confirmation procedure is
		//  available from MVB server. If so, then up to "max_package_number"
		//  packages will be transmitted from MVB server to MVB client. If the
		//  message data confirmation procedure is fully transmitted to the MVB
		//  client, then it will be processed immediately.
		//  Note: A message data confirmation procedure transmitted from MVB
		//        server to MVB client are divided into packages of 45 bytes
		//        (40 data bytes including parameters).
		//  Note: By specifying the parameter "max_package_number" the run-time
		//        of the procedure "gf_poll_callback" can be limited.
		//  Note: If a transmission of a message data callback procedure is in
		//        progress between MVB server and MVB client (indicated
		//        bCallbackBusy=TRUE), then no procedures of the Message Data
		//        Interface are allowed to be called.
		// ----------------------------------------------------------------------
		GF_RESULT   	gf_result;
		UNSIGNED32  	max_package_number;
		BOOLEAN1    	bCallbackBusy;

		max_package_number = 0;
		bCallbackBusy = FALSE;
		gf_result = gf_poll_callback(max_package_number, &bCallbackBusy);
		if (gf_result != GF_OK)
		{
			return((UNSIGNED16)gf_result);
		}
	}
#endif

	return(0);
} //end of mixed_md_cycle

// --------------------------------------------------------------------------
//  Procedure : mixed_demo
//
//  Purpose   : Perform process data communication and Message Data communication .
// --------------------------------------------------------------------------
static UNSIGNED16
mixed_demo(void)
{
	UNSIGNED16 	result = 0;
	UNSIGNED8  	ch, i, j;
	BITFIELD temp_port_src_no= PD_SRC_NO, temp_port_snk_no= PD_SNK_NO;
	
	for(i=0; i < PD_SRC_NO; i++)
	{
		pd_prt_clear_dataset(port_data_snk[i], PD_snk_port_size_word[i]);

	}

	// default value of source ports
	for(i=0; i < PD_SRC_NO; i++)
	{
		for(j = 0; j < PD_src_port_size_word[i];j++)
		{
			port_data_src[i][j] = 0x1122 + 0x1111 * j;
		}
	}

	md_caller_state = MD_STATE_DO_CALL_REQUEST;
	md_caller_status = AM_OK;
	md_replier_state = MD_STATE_DO_RECEIVE_REQUEST;
	md_replier_status = AM_OK;

	clear();
	refresh();
    printw("============================================================================\n");
	printw("                                Process data\n");
 	printw("port config                  port data                   status   freshness\n");
    printw("----------------------------------------------------------------------------\n");

	if(0 != temp_port_src_no)
	{
		printw("-- SOURCE PORT\n");
	}
    printw("0x%03X(%-03dbits)", PD_src_port_address[0],PD_src_port_size_word[0]*16);
	move(8,1);
	if(0 != temp_port_snk_no)
	{
		printw("-- SINK PORT\n");
	}
    printw("0x%03X(%-03dbits)", PD_snk_port_address[0],PD_snk_port_size_word[0]*16);
    move(11,0);
    printw("============================================================================\n");
    printw("                                Message data\n");
    printw("----------------------------------------------------------------------------\n");
	printw("received: %s\n\n",md_receive_temp);
	printw("    send: \n");
	refresh();
	
	for(;;)
	{
 	   // Esc to abort
		if(kbhit())
		{
			ch = getch();
			if (ch == 27)
			{
				break;
			}
		}
		// ----------------------------
		//  Process Data 
		// ----------------------------
		result = mixed_pd_cycle();
		if(result != 0)
		{
		#ifdef O_PRINT
			printw("ERROR: mixed_pd_cycle()=%u\n", result);
		#endif
		} 
		
		// ----------------------------
		//  Message Data
		// ----------------------------
		result = mixed_md_cycle();
		if (result != 0)
		{
#ifdef O_PRINT_ERROR
			printw("ERROR: mixed_md_cycle()=%u\n", result);
#endif
		}
	}
	
	move(20,1);
	return(result);
}

// --------------------------------------------------------------------------
//  Procedure : md_init
//
//  Purpose   : General message data initialisation:
//              - initialises the Messenger
//              - announces the device's configuration for Message Data
//                communication
//              - makes a Replier known to the Messenger and connect
//                application specific indication (i.e. confirm) procedures
// --------------------------------------------------------------------------
UNSIGNED16
md_init (void)
{
	AM_RESULT   am_result;
	
	// ----------------------------
	//  initialises the Messenger
	// ----------------------------
	am_result = am_init();  
	if (am_result != AM_OK)
	{
#ifdef O_PRINT_ERROR
		printw("ERROR: am_init()=%u\n", am_result);
#endif
        return((UNSIGNED16)am_result);
	} 

	// ----------------------------
	//  announces the device's configuration for Message Data communication
	// ----------------------------
	am_result = am_announce_device(5, 5, 400, 7); 
	if (am_result != AM_OK)
	{
#ifdef O_PRINT_ERROR
		printw("ERROR: am_announce_device()=%u\n", am_result);
#endif
		return((UNSIGNED16)am_result);
	}

	// ----------------------------
	//  makes a Replier known to the Messenger and connect application
	//  specific indication (i.e. confirm) procedures
	// ----------------------------
	if(demo_type == 2)
	{
		if(md_demo_type == 0)
		{
		am_result =                 \
			am_bind_replier             \
			(                           \
				MD_REPLIER_FUNCTION	,   \
				send_receive_confirm,     \
				send_reply_confirm        \
			);
		}
		if(md_demo_type == 1)
		{
		am_result =                 \
			am_bind_replier             \
			(                           \
				MD_REPLIER_FUNCTION	,   \
				receive_receive_confirm,     \
				receive_reply_confirm        \
			);
		}
	}
	if(demo_type == 3)
	{
	am_result =                     \
		am_bind_replier             \
		(                           \
			MD_REPLIER_FUNCTION,    \
			mixed_receive_confirm,     \
			mixed_reply_confirm        \
		);
	}
	if (am_result != AM_OK)
	{
#ifdef O_PRINT_ERROR
		printw("ERROR: am_bind_replier()=%u\n", am_result);
#endif
		return((UNSIGNED16)am_result);
	} 

	return(0);
} //end of md_init 

// --------------------------------------------------------------------------
//  Procedure : dev_init
//
//  Purpose   : Initialises MVB device.
// --------------------------------------------------------------------------
UNSIGNED16
dev_init (void)
{
	UNSIGNED16         result;
	GF_RESULT          gf_result;
#ifdef GET_BOARD_INFO
	GF_SERVER_INFO     server_info;
	GF_HW_ID           hardware_id;
	GF_SW_ID           software_id;
	GF_SW_VERSION_INFO software_version_info;
#endif
	UNSIGNED16         device_address;
	GF_LINE_CONFIG     line_config;
	GF_REPLY_TIMEOUT   reply_timeout;
	
#ifdef READ_DSW
	DSW_TS_CONFIG *p_dsw_ts_config;
	UNSIGNED16 dsw_ts_config_list;
#endif

#ifdef O_BA_CONFIG_DYNAMIC
	GF_SERVICE_COMMAND service_command;
	UNSIGNED32 			size_of_data;
	void 				*p_data;
	FILE 				*fp;
#endif

	// ----------------------------
	// general device initialisation
	// ----------------------------
#ifdef O_PRINT
	printw("gf_init_device()\n");
	refresh();
#endif
	do
	{
		gf_result = gf_init_device();
		// NOTE: timeout must be implemented
	} while (gf_result != GF_OK);

#ifdef GET_BOARD_INFO
	// ----------------------------
	// determine version information
	// ----------------------------
#ifdef O_PRINT
	printw("gf_get_server_info()\n");
#endif
	gf_result = gf_get_server_info(&server_info);
	if (gf_result != GF_OK)
	{
		printw("\nERROR: gf_get_server_info() = %u\n", gf_result);
		return (UNSIGNED16)gf_result;
	}
#ifdef O_PRINT
	// target_number is not used for current version.
	// printw("- target_number    = %08X\n", server_info.target_number);
	// ident_number is not used for current version.
	printw("- info_boot_loader  = V%1u.%1u.%02u\n",	\
		server_info.info_boot_loader.version,	\
		server_info.info_boot_loader.release,	\
		server_info.info_boot_loader.update		\
		);
	printw("- info_pld_firmware = V%1u.%1u.%02u\n",	\
		server_info.info_pld_firmware.version,	\
		server_info.info_pld_firmware.release,	\
		server_info.info_pld_firmware.update	\
		);
	printw("- info_mvb_server   = V%1u.%1u.%02u\n",	\
		server_info.info_mvb_server.version,	\
		server_info.info_mvb_server.release,	\
		server_info.info_mvb_server.update		\
		);
#endif

#ifdef O_PRINT
	printw("gf_get_mvb_api_info()\n");
	refresh();
#endif
	gf_result =                     \
		gf_get_mvb_api_info         \
		(                           \
			&hardware_id,           \
			&software_id,           \
			&software_version_info  \
		);
	if (gf_result != GF_OK)
	{
		printw("\nERROR: gf_get_mvb_api_info() = %u\n", gf_result);
		return (UNSIGNED16)gf_result ;
	}
#ifdef O_PRINT
	printw("- hardware_id           = SSMV%04X", hardware_id);
	printw("\n");

	// do not print software_id
	// ident_number is not used for current version.
	printw("- software_version_info = V%u.%u.%02u\n",	\
		software_version_info.version,				\
		software_version_info.release,				\
		software_version_info.update				\
		);
#endif
#endif // GET_BOARD_INFO

	// ----------------------------
	// MVB device initialization:
	// - MVB device address
	// - MVB input lines
	// - MVB reply timeout
	// ----------------------------
	device_address = MVB_DEVICE_ADDRESS1;
	line_config    = GF_LINE_BOTH;
	reply_timeout  = GF_TREPLY_43US;

#ifdef O_PRINT
	printw("gf_mvb_init()\n");
		refresh();
#endif
	gf_result = gf_mvb_init(0, device_address, &line_config, &reply_timeout);
	if(gf_result != GF_OK)
	{
		printw("\nERROR: gf_mvb_init() = %u\n", gf_result);
		return (UNSIGNED16)gf_result;
	}

#ifdef READ_DSW
	// ----------------------------
	//  dsw_init
	// ----------------------------
	dsw_ts_config_list = 0x000; 	//only for the init value
	p_dsw_ts_config->c_dsw_ts_config_list = 1;
	p_dsw_ts_config->supervision_interval = 16;
	p_dsw_ts_config->p_dsw_ts_config_list = &dsw_ts_config_list;

#ifdef O_PRINT
	printw("dsw_init()\n");
	refresh();
#endif
	result = dsw_init(0, p_dsw_ts_config);
	if(result != 0)
	{
	#ifdef O_PRINT
		printw("ERROR: dsw_init()=%u\n", result);
	#endif
		return(result);
	}
#endif
    return GF_OK;
}

// --------------------------------------------------------------------------
//  Procedure : init_port
//
//  Purpose   : Init MVB Port soure and sink.
// --------------------------------------------------------------------------
UNSIGNED16 init_port()
{
    UNSIGNED16  result;
    GF_RESULT     gf_result;
	// ----------------------------
	// Process Data initialization
	// ----------------------------
	if(demo_type == 0)
	{
#ifdef O_PRINT
	printw("lp_port_init()\n");
	refresh();
#endif
		result = lp_port_init();
		if(result != 0)
		{
			printw("\nERROR: lp_port_init() = %u\n", result);
			return result;
		}
	}

	// ----------------------------
	// start MVB communication
	// ----------------------------
#ifdef O_PRINT
	printw("gf_mvb_start()\n");
	refresh();
#endif
	gf_result = gf_mvb_start(0);
	if(gf_result != GF_OK)
	{
		printw("\nERROR: gf_mvb_start() = %u\n", gf_result);
		return (UNSIGNED16)gf_result;
	}

#ifdef O_BA_CONFIG_DYNAMIC
	service_command = GF_SERVICE_COMMAND_BA_D2000_SERVER;       
	fp = fopen("DEVICE1.bin", "rb"); 
	if (fp == NULL)
	{
		printw("cannot open file!\n");
		gf_result = GF_CONFIG;
		return(gf_result);
	}
	size_of_data = get_file_size( fp);
	p_data = (void*)malloc(size_of_data);
	if (p_data == NULL)
	{
		printw("No memory for ba_config file\n");
		free(p_data);
		return(-1);
	}
	if (fread(p_data, 1, size_of_data, fp) != size_of_data)
	{
		printw("file read error!\n");
		free(p_data);
		return(-1);
	}

	gf_result = gf_service_command(service_command, p_data, &size_of_data);
	if (gf_result != GF_OK)
	{
		printw("ERROR: gf_service_command()=%u\n", gf_result);
		free(p_data);
		return(gf_result);
	}
	fclose(fp);
	free(p_data);
#endif

	return 0;
} 

// --------------------------------------------------------------------------
//  Procedure : demo
//
//  Purpose   : The demo application.
// --------------------------------------------------------------------------
UNSIGNED16
demo (void)
{
	UNSIGNED16  result = 0;

	// ----------------------------
	//  Initialises MVB device.
	// ----------------------------
	result = dev_init();
	if(result != 0)
	{
	#ifdef O_PRINT
		printw("ERROR: dev_init()=%u\n", result);
	#endif
		return(result);
	} 
	printw("Initialization finished successfully!\n\n");

	if(demo_type == 0)
	{
		p_demo_cycle = p_demo_cycle_group[demo_type];
		result = (*p_demo_cycle)();
		
		if(result != 0)
		{
		#ifdef O_PRINT
			printw("ERROR: lp_demo()=%u\n", result);
		#endif
		} 
	}
	if(demo_type == 1)
	{
		p_demo_cycle = p_demo_cycle_group[demo_type];
		result = (*p_demo_cycle)();
		
		if(result != 0)
		{
		#ifdef O_PRINT
			printw("ERROR: md_demo()=%u\n", result);
		#endif
		} 
	}
	if(demo_type == 2)
	{
		p_demo_cycle = p_demo_cycle_group[demo_type];
		result = (*p_demo_cycle)();
		if(result != 0)
		{
		#ifdef O_PRINT
			printw("ERROR: mixed_demo()=%u\n", result);
		#endif
		} 
	}
	if(demo_type == 3)
	{
		p_demo_cycle = p_demo_cycle_group[demo_type];
		result = (*p_demo_cycle)();
		if(result != 0)
		{
		#ifdef O_PRINT
			printw("ERROR: md_demo()=%u\n", result);
		#endif
		} 
	}
	
	return(result);
} 

// --------------------------------------------------------------------------
// Procedure : main
// --------------------------------------------------------------------------
int
//DeclMain main (void)
mvb_init(void)
{
	UNSIGNED16 result;
	GF_RESULT  gf_result;
#ifdef O_CLT_DRV_WIN32_COM
	UNSIGNED16 device_config;
#else
	UNSIGNED32 device_config;
#endif
	GF_DEVICE_ERROR device_error;
	GF_DEVICE_STATUS device_status;
 	UNSIGNED8 ch;
	
	initial();
	clear();
	printw("/**********************************************/\n");
	printw("                  SS2XDD demo                   \n");
	printw("         =============================          \n");
	printw(" Configuration of this NODE is as following:    \n");
	printw("    MASTER/SLAVE:   SLAVE                       \n");
	printw("           LINEs:   LINE_BOTH                   \n");
	printw("/**********************************************/\n\n");

	// get paremeters-- demo type
	printw("\nPlease choose demo type:\n");
	printw("0 --  Link Process Data Demo\n");
	printw("1 --  Application Process Data Demo\n");
	printw("2 --  Message Data Demo\n");
	printw("3 --  mixed demo\n");
	refresh();
	do
	{
		printw("\nPlease input:");
		refresh();
		echo();	
		ch = getch();
	} while (ch!='0' && ch!='1' && ch!='2' && ch!='3');
	
	printw("\n");
	demo_type = ch - '0';
	
	if(demo_type == 1)
	{
		// get paremeters -- access mode
		printw("Please select access mode:\n");
		printw("0 -- Individual\n");
		printw("1 -- Set\n");
		printw("2 -- Cluster\n");
		printw("Please input:");
		refresh();
		ch = getch();
		while(ch != '0' && ch != '1' && ch != '2')
		{
			printw("\nInput error!\nPlease input:");
			refresh();
			ch = getch();
		}
		printw("\n");

		pd_var_access = ch - '0';

		// get paremeters -- port type
		printw("Please select port type:\n");
		printw("0 -- sink\n");
		printw("1 -- source\n");
		printw("Please input:");
		refresh();
		ch = getch();
		while(ch != '0' && ch != '1')
		{
			printw("\nInput error!\nPlease input:");
			refresh();
			ch = getch();
		}
		printw("\n");
		pd_port_type = ch - '0';
	}
	if(demo_type == 2)
	{
		// get paremeters-- message demo type
		printw("\nPlease choose message demo type:\n");
		printw("0 -- Send File\n");
		printw("1 -- Receive File\n");
		do
		{
			printw("\nPlease input:");
			refresh();
			ch = getch();
		} while (ch!='0' && ch!='1');

		md_demo_type = ch - '0';
	} 
	noecho();
	
	// ----------------------------
	//  Device Configuration (host interface of MVB interface product)
	// ----------------------------
	device_config = DEVICE_BASE_ADDR;

#ifdef O_PRINT
	printw("gf_open_device()\n");
#endif
	do
	{
		gf_result = gf_open_device(&device_config, 0, &device_error);
		//NOTE: timeout must be implemented
	} while (gf_result != GF_OK);
#ifdef O_PRINT
	printw("gf_open_device()=%u\n", gf_result);
	refresh();
#endif

	// ----------------------------
	//  execute demo application
	// ----------------------------
	result = demo();
#ifdef O_PRINT
	printw("demo()=%u\n", result);
#endif
	if(result != 0)
	{
		gf_get_device_status(&device_status);
	#ifdef O_PRINT
		printw("ERROR: device_status=0x%04X\n", device_status);
	#endif
	} 

	// ----------------------------
	//  terminate demo application
	// ----------------------------
	gf_mvb_stop();
	gf_close_device();

	if(result != 0 )
	{
		printw("\n/**********************************************/\n");
		printw("\n    demo test ended with error!\n\n");
		printw("/**********************************************/\n");
		refresh();
	}
	if(result != 0)
	{
		
		refresh();
		endwin();
		return(-1);
	}

	refresh();
	endwin();
	return(0);
} 

//#if defined(__cplusplus)
//}
//#endif


