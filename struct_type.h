/*
 * Copyright (c) 2012���MIT
 * All right reserved.
 *
 * ���������������struct_type.h
 * ���������������
 * ���    ���������������������������
 *
 * ���������������V1.0.3
 * ���    ������wilson
 * ���������������2012-10-08
 *
 * ���������������V1.0.2
 * ���������  ���wilson
 * ���������������2012-09-27
 *
 * ���������������V1.0.1
 * ���������  ���wilson
 * ���������������2012-08-25
 */

#ifndef STRUCT_TYPE_H_
#define STRUCT_TYPE_H_

#define CONFIG_CCU_VIDEOLINK ///< add,2016

#define TRUE	1
#define FALSE	0

#define LEFT_A	1	///<1������������������A���
#define RIGHT_B	2	///<2������������������B���

#define LINE_NO_A	3	///<���������
#define LOOP_A	0	///<0=������������1=������
#define MAX_STATION_NUMBER	17	///<������������
#define SIDE_MODE	0	///<0=���������������������������������������1=���������������TC1,���������������A���������������������B���
#define ATO_TRIGGER_TYPE	0	///<ATO������������0=���������������������1=������������������

///<���������������������������������
#define WELCOME_CH	"������������5������"
#define WELCOME_EN	"Welcome to line 5"


#define Print
#ifndef Print
   #define debug_print(s)
	#define ts_debug_print(s) //diag_printf s
	#define tms_debug_print(s) //diag_printf
#else
    #define debug_print(s)    //diag_printf s
    #define debug_print2(s)   // diag_printf s
    #define debug_print5(s)    //diag_printf s
    #define debug_simulat_print(s)     //diag_printf s
 	#define debug_print_z(s)     //diag_printf s
	#define ts_debug_print(s)  //diag_printf s
	#define tms_debug_print(s) //diag_printf s
	#define sd_debug_print(s)  //diag_printf s
    #define fs_debug_print(s)  //diag_printf s
	#define sd_debug_print(s)  //diag_printf s
    #define intercomm_debug_print(s) //diag_printf s
    #define thread_debug_print(s) //diag_printf s
	#define debug_test_print(s)     //diag_printf s
	#define debug_printf_qc(s) 	//diag_printf s
	 #define dfu_debug_print(s)   //diag_printf s
#endif

/**
 * ������������������
 */
#define CONFIG_BCU_NUM   2			///<���������������������
#define CONFIG_CCU_NUM   2			///<���������������������
#define CONFIG_PECU_NUM  12			///<���������������������
#define CONFIG_EAMP_NUM  6			///<������������

/**
 * ������������������
 */
#define TYPE_OF_BCU  0x10    			///<���������������
#define TYPE_OF_CCU  0x20 				///<���������������
#define TYPE_OF_EAMP 0x30				///<������
#define TYPE_OF_PECU 0x40				///<���������������


/**
 * ������������������
 */
#define OPERATE_STATE_REQUEST  (1<<0)	///<������
#define OPERATE_STATE_RESPONSE (1<<1)	///<������
#define OPERATE_STATE_OVER     (1<<2)	///<������
/**
 * ������������
 */
#define CMD_STATE_CMD  (1<<0)			///<������������
#define CMD_STATE_DATA (1<<1)			///<������������

/**
 * ������������������
 */
#define OCC_EVENT 1					///<OCC
#define LIVE_ANN_EVENT 2				///<������
#define EMERG_ANN_EVENT 3				///<������������
#define MANUAL_ANN_EVENT 4			///<������������
#define TMS_MANUAL_ANN_EVENT 5		///<���������������
#define D2D_INTERCOMM_EVENT 7		///<������������������������
#define TMS_AUTO_ANN_EVENT 6			///<������������
#define D2P_INTERCOMM_EVENT 8		///<������������������������
#define D2D_HANGUP_D2P_EVENT 9		///���������������������������   //wilson 2012-10-17
#define D2P_INTERCOM_PENDING 10		///������������������  	   //wilson 2012-10-26
#define LINE_NUMBER_CHANGE_EVENT 11

#define EVENT_TYPE_OPEN_DOOR_PROMPT (22)	///������17������������������������

#define MIC_3D5_OUTER_EVENT 12

#define SKIP_STATION 50				///<������������
#define PA_KEY_INFORMATION 51 ///<PA-BCU������������
#define CLEAR_ALL_SKIP_STATION 52///< ������������������������
#define DEVICE_UPDATE_STATE 53///< ������������������
#define EAMP_GET_BCU_ANN_STATE 54///<������������BCU���������������������
#define AUTO_EAMP_SYNC_SIGNAL 55///<������������������������
#define TWO_CARS_CONNECT_STATE 56///<������������
#define EVENT_NO_PCU_REQUEST 57///<������������PCU������
#define BCU_ANN_IDLE_TO_EAMP 58///< EAMP���������������������������BCU���������������ANN IDLE���
#define BCU_ANN_ANA_LINK_TO_EAMP  59
#define LINE_NUMBER_CHANGE_CCU_SYNC_EVENT  60
#define LINE_NUMBER_CHANGE_CCU_SYNC_RESPONSE_EVENT  61
#define STATION_INFO_CCU_SYNC_EVENT  62

#define EVENT_TYPE_DB_UPDATE_QUERY  248 ///<add for db sync query, 2013
#define EVENT_TYPE_AUDIO_PLAY_SYNC  249 ///<add for audio play sync, 2013
#define EVENT_TYPE_SYS_IMAGE_UPDATE  250 ///<add for system program update, 2013
#define EVENT_TYPE_SYS_UPDATE_SYNC   251 ///<add for db/dev sync, 2013
#define EVENT_TYPE_SYS_UPDATE_SYNC_END 252
#define EVENT_TYPE_DEV_DEAD   253  ///< device is not online, probably it doesn't work
#define ANN_IDLE 254					///<������������������       //wilson 2012-10-23
#define INTERCOM_IDLE 255				///<������������������       //wilson 2012-10-23

#define BCU_6W5_DB12    1
#define BCU_6W5_DB16    2
#define BCU_6W5_DB23    3
#define BCU_6W5_DB36    4

#define SET_MIC_AUDIO    0 //1///<������MIC

#define SET_HD_AUDIO     1 //2///<������

#define SET_OCC_AUDIO     3///<OCC

#define SET_MEDIA_AUDIO    2

//event type for common, ach add begin, 2013
#define SUBEVENT_TYPE_DB_VERSION_SYNC_CCU (1)
#define SUBEVENT_TYPE_DB_VERSION_SYNC_BEP  (2) 
#define SUBEVENT_TYPE_DB_SERVER_CHANGED   (3)
#define SUBEVENT_TYPE_DEV_INFO_SYNC_CCU      (4)
#define SUBEVENT_TYPE_DEV_INFO_SYNC_BEP      (5)
#define SUBEVENT_TYPE_LINE_STATION_TABLE_SYNC     (17)
#define SUBEVENT_TYPE_LINE_SECTION_TABLE_SYNC     (19)
#define SUBEVENT_TYPE_DEFAULT_LINE_TABLE_SYNC     (21)
#define SUBEVENT_TYPE_EMERG_TABLE_SYNC     (22)
#define SUBEVENT_TYPE_IP_TABLE_SYNC     (23)
#define SUBEVENT_TYPE_ANN_VERSION_TABLE_SYNC     (24)
#define SUBEVENT_TYPE_CONFIG_VERSION_TABLE_SYNC     (25)
#define SUBEVENT_TYPE_PRIORITY_TABLE_SYNC     (26)
#define SUBEVENT_TYPE_DEV_NUMBER_TABLE_SYNC     (27)
#define SUBEVENT_TYPE_RECORD_PATH_TABLE_SYNC     (28)
#define SUBEVENT_TYPE_LOG_PATH_TABLE_SYNC     (29)
#define SUBEVENT_TYPE_STATION_DOOR_SIDE_SYNC     (30)
#define SUBEVENT_TYPE_STATION_BCU_VOLUME_SYNC     (31)
#define SUBEVENT_TYPE_STATION_BCU_TS_PASSWORD (32)

#define SUBEVENT_TYPE_ALL_DEV_VERSION  (128) ///< add, 1010
#define SUBEVENT_TYPE_PCU_UPDATED                         (250)
#define SUBEVENT_TYPE_PCU_UPDATING                         (251)
#define SUBEVENT_TYPE_EAMP_UPDATED                         (252)
#define SUBEVENT_TYPE_EAMP_UPDATING                         (253)

#define SUBEVENT_TYPE_READY_SYNC_REQ                       (254)
#define SUBEVENT_TYPE_END_SYNC                                       (255)
//event type for common, ach add end, 2013


#define CONFIG_CCU_VERSION_STRING_LEN 32
#define MAX_STATIONS_NUMBER 32
#define MAX_EMERG_CONTENT_LENGTH 300

#define EMERG_DEBUG_FORTS_TOTAL_ITEMS (8)
#define LINE3_DEFULT_REGIONS_NUMBER (8)
#define LINE4_DEFULT_REGIONS_NUMBER (8)


#define MAX_LINE_NUMBER 20

//���������������������������������������,���������������  9-26
#define CONFIG_DEVICE_NAME_LEN  32		///<������������������
#define DEVICE_NAME_LENGTH 30			///<���������������
#define IP_NAME_LENGTH 20					///<IP������
#define MUL_DST_NO 230				   ///<���������������������
#define MUL_SYNC_DST_NO 251
#define LIVE_DST_NO 231				   ///<���������������������
#define BCU_CMU_CAR_CONNECT_PACKAGE 231   ///<���������������
#define AUDIO_DST_NO 231
#define AUDIO_BUF_SIZE 1024

///#define AUDIO_FILE_NAME_LENGTH 30   ///<the length of audio file name
#define AUDIO_FILE_NAME_LENGTH 64   ///<���������������������������,2013-06-27 modify

#define FILE_PATH_LENGTH 32   ///<���������������������������,2013-06-27 add
#define EMERG_CONTENT_LENGTH 1000//256///<������������������������,2013-06-27 add--2015-4-23 modify
#define EMERG_CONTENT_LENGTH_BETWEEN_BCU_CCU 256
#define EMERG_NAME_LENGTH 32///������������������������,2013-06-27 add
#define STATION_NAME_LENGTH 32///<������������,2013-06-27 add
#define MAC_ADD_LENGTH 20  ///<MAC���������������2013-06-27 add
#define TIME_LENGTH 32    ///<������������ ���2013-06-27 add
#define EVENT_TYPE_LENGTH 32 ///<���������������������2013-06-27 add
#define FILE_SHORT_NAME_LENGTH 32
#define LOCAL_AUDIO_DATA_BUFFER_SIZE (1024*8)


#define CONFIG_BCU_SYNC_FROM_CCU_NET  ///<only for bcu
#define CONFIG_CCU_VERSION_STRING_LEN  32


///<���������������
#define TMS_PACKAGE_ID 10   ///<tms���������
#define COMMON_PACKAGE_TYPE_SYNC_GD  (2)  ///<
#define COMMON_PACKAGE_TYPE_PTT_STATE  (3)  ///< ptt status
#define COMMON_PACKAGE_TYPE_DEVICE_INFO (4)  ///< dev volume
#define COMMON_PACKAGE_TYPE_MONITOR_SPEAKER_CONTROL (5)  ///< speaker control
#define COMMON_PACKAGE_TYPE_BCU_LOG_INFO (6)  ///< bcu log info
#define COMMON_PACKAGE_TYPE_PCU_STATE (7)  ///<pcu state
#define COMMON_PACKAGE_TYPE_INTERCOMM_LOG (8)  ///<intercomm auido data recording
#define COMMON_PACKAGE_TYPE_EAMP_NET_STATE (9)///<eamp network state
#define COMMON_PACKAGE_TYPE_ALL_DEV_STATE (8)///<all dsev state
#define COMMON_PACKAGE_TYPE_DDU_SIMULATE (11)///<ddu simulate
#define COMMON_PACKAGE_TYPE_SOFTWARE_VERSION (12)///software version
#define COMMON_PACKAGE_TYPE_CMU_CAR_TYPE (13)//���������������������
#define COMMON_PACKAGE_TYPE_ACK_STATE (14)//CMU ACK������
#define COMMON_PACKAGE_TYPE_TCMS_CMU_STATE (15)//TCMS CMU������
#define COMMON_PACKAGE_TYPE_NEW_CMU_STATE (16)//CMU 2.0������
#define COMMON_PACKAGE_TYPE_INTERCOMM_FROM_CCU_TO_BCU (17)///<intercomm volume from ccu to bcu
#define COMMON_PACKAGE_RUNNING_MODE_INFO (18)
#define COMMON_PACKAGE_TYPE_VOLUME_ADJ_INFO (19)
#define COMMON_PACKAGE_TYPE_PCU_CONTROL (20)
#define COMMON_PACKAGE_TYPE_ANN_SPEAKER_ANA_CONTROL (21)
#define EVENT_TYPE_OPEN_DOOR_PROMPT (22)





#define BUFFER_TYPE_RECV_FROM_NET  (1)  ///<
#define BUFFER_TYPE_SEND_TO_NET  (2)  ///<
#define BUFFER_TYPE_COMMON_BIG  (2)  ///<
#define BUFFER_TYPE_COMMON_NORMAL  (1)  ///<

#define WITH_DB ///< 2013-12-19
#define PCU_ALARM

///<������������������
#define DEFAULT_MONITOR_VOLUME (2)
#define DEFAULT_CAR_VOLUME (92)
#define DEFAULT_INTERCOMM_VOLUME (3)

//add by zhw 2014-5-20;
typedef struct
{
	unsigned char year;
	unsigned char month;
	unsigned char date;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
}current_time_t;//������������������

typedef struct
{
	unsigned char outer_sider_led1_failure_info;
	unsigned char outer_sider_led2_failure_info;
	unsigned char in_sider_led1_failure_info;
	unsigned char in_sider_led2_failure_info;
	unsigned char nd1_failure_info;
	unsigned char nd2_failure_info;
	unsigned char in_sider_sdu1_failure_info;
	unsigned char in_sider_sdu2_failure_info;
	unsigned char dm_failure_info;	///<������������
}eamp_per_dev_failure_t;//eamp������������������

typedef struct
{
  unsigned char fdu_failure_info;
}ccu_per_dev_failure_t;




////>>>>>>>>>>>>>>>>>>state machine define begin>>>>>>>>>>>>>>>>>>>>>>>>
/** ���������������������������occ������
 *	���������������������������OCC���������������������
 */
typedef struct
{
	unsigned char occ_active;		///<OCC������������
	unsigned char occ_begin_or_over;		///<OCC���������������
	unsigned char occ_response;	///<OCC������,���������������������������������������������
}occ_ann_t;

/** ���������������������������������
 *	���������������������������������������������
 */
typedef struct
{
	unsigned char live_active;	///<live������������
	unsigned char live_begin_or_over;		///<���������������������
	unsigned char live_response;	///<������������
}live_ann_t;

typedef struct
{
	unsigned char live_active;	///<live������������
	unsigned char live_begin_or_over;		///<���������������������
	unsigned char live_response;	///<������������
}tms_live_ann_t;

/** ���������������������3d5������
 *	���������������������������3d5������������
 */
typedef struct
{
	unsigned char outer_3d5_active;	///<outer_3d5������������
	unsigned char outer_3d5_begin_or_over;		///<outer_3d5���������������
	unsigned char outer_3d5_response;	///<outer_3d5������
}outer_3d5_ann_t;

/** ���������������������������������������
 *	���������������������������������������������������
 */
typedef struct
{
	unsigned char emerg_active;		///<������������������������
	unsigned char emerg_begin_or_over;	///<���������������������������
	unsigned char emerg_response;	///<������������������
	unsigned char emerg_times;		///<������������������:1���3������������
	unsigned char emerg_sequence;	///<���������������������������������
}emerg_ann_t;

/** ���������������������������������������
 *	���������������������������������������������������
 */
typedef struct
{
	unsigned char manual_active;					///<������������������������
	unsigned char manual_pre_read;			///<������������������
	unsigned char manual_begin_or_over;					///<���������������������������
	unsigned char manual_response;				///<������������������
	unsigned char line_number;					///<������������3���4������
	unsigned char up_down;						///<������������������������ 0:������ 1���������
	unsigned char stop_or_leave;					///<������������ 0:��������� 1���������;������������������
	unsigned short int start_station_code;		///<���������
	unsigned short int current_station_code;	///<���������
	unsigned short int next_station_code;		///<���������
	unsigned short int end_station_code;		///<���������
	unsigned char door_side;						///<���������
	unsigned char key_side;						///<���������
}manual_ann_t;

/** ���������������������tms������������������
 *	���������������������������������������������������
 */
typedef	 struct
{
	unsigned char tms_auto_active;				///<������������������������
	unsigned char tms_auto_pre_read;			///<������������������
	unsigned char tms_auto_begin_or_over;				///<���������������������������
	unsigned char tms_auto_response;				///<������������������
	unsigned char line_number;					///<������������3���4������
	unsigned char up_down;						///<������������������������ 0:������ 1���������
	unsigned char stop_or_leave;						///<������������ 0:��������� 1���������
	unsigned short int start_station_code;		///<���������
	unsigned short int current_station_code;	///<���������
	unsigned short int next_station_code;		///<���������
	unsigned short int end_station_code;		///<���������
	unsigned char door_side;						///<���������
	unsigned char door_state;						///<������������
	unsigned short int train_speed;				///<������������
	unsigned short int train_distance;			///<������������
	unsigned char key_side;						///<���������
	unsigned char tms_emerg_times;		///<������������������:1���3������������
	unsigned char tms_emerg_sequence;	///<���������������������������������
	unsigned char tms_type_flag;///<1:tms auto  2:tms half auto  3:tms manual  4:tms emerg
	unsigned char tms_ato_effective;
}tms_auto_ann_t;

/** ���������������������tms������������������������������tms���������������������������������
 *	���������������������������������������������������
 */
typedef	 struct
{
	unsigned char tms_manual_active;				///<������������������������
	unsigned char tms_manual_begin_or_over;				///<���������������������������
	unsigned char tms_manual_response;			///<������������������
	unsigned char line_number;					///<������������3���4������
	unsigned char up_down;						///<������������������������ 0:������ 1���������
	unsigned char ann_type;						///<������������ 0:��������� 1���������
	unsigned short int start_station_code;		///<���������
	unsigned short int current_station_code;	///<���������
	unsigned short int next_station_code;		///<���������
	unsigned short int end_station_code;		///<���������
	unsigned char door_side;						///<���������
	unsigned char door_state;						///<������������
	unsigned short int train_speed;				///<������������
	unsigned short int train_distance;			///<������������
	unsigned char key_side;						//���������
}tms_manual_ann_t;

/** ������������������������������������������������
 *	���������������������������������������������
 */
typedef struct
{
	unsigned char d2d_intercomm_active;				///<������������������
	unsigned char d2d_intercomm_request_or_over;			///<���������������������
	unsigned char d2d_intercomm_response;			///<������������
	unsigned char d2d_intercomm_bcu_device_no;		///<���������������������
	unsigned char d2d_ppt_state;                   ///<ppt��������� 0:������  1:������
}d2d_intercomm_t;

/** ������������������������������������������������
 *	���������������������������������������������
 */
typedef struct
{
	unsigned char d2p_intercomm_active;				///<������������������
	unsigned char d2p_intercomm_request_or_over;			///<���������������������
	unsigned char d2p_intercomm_pending;           ///<������������
	unsigned char d2p_intercomm_response;			///<������������
	unsigned char d2p_intercomm_bcu_device_no;		///<���������������������
	unsigned char d2p_intercomm_pcu_device_no;		///<���������������������
	unsigned char d2p_intercomm_whether_is_connecting;///<wilson 2014-02-28
}d2p_intercomm_t;

////<<<<<<<<<<<<<<<<state machine define over<<<<<<<<<<<<<<<<<<<</

////>>>>>>>>>>>>>>>>>>>>>>>>device info define begin>>>>>>>>>>>>>>>>>>>>>>/
/** ������������������������������������
 *	������������������������������������������
 */
typedef struct
{
	char *name;			///<���������
	int device_no;			///<���������
	char *ip_addr;			///<IP������
}device_info_t;

/** ���������������������������������IP���
 *	���������������������������������������IP
 */
typedef struct
{
	char *ip_addr;			///<IP
}local_device_info_t;		//modify

/** ������������������������������������������������������������������
 */
typedef struct
{
	char *name;			///<���������
	int io_no;				///<IO ���������
}device_name_t;

/** Struct function���identify device name,id and car number
 */
typedef struct
{
	char device_name[DEVICE_NAME_LENGTH];			///<���������
	char device_no;				                  ///<���������
	char device_car_no;								///<���������
	int dev_type;
}device_id_info_t;

typedef struct eamp_info
{
	unsigned char online;//EAMP������������
	eamp_per_dev_failure_t eamp_per_dev_failure_info;//EAMP���������������������
}eamp_info_t;

typedef struct bcu_info
{
	unsigned char online;//BCU������������
}bcu_info_t;

typedef struct ccu_info
{
	unsigned char online;//CCU������������
	ccu_per_dev_failure_t ccu_per_dev_failure_info;//CCU���������������������
	unsigned char tcms_effective_flag;//wilson-2015-5-25
	unsigned char key_status[2];
}ccu_info_t;

typedef struct pcu_info
{
	unsigned char online;//PCU������������
}pcu_info_t;

typedef struct cmu_info
{
	unsigned char online;//CMU������������
}cmu_info_t;

typedef struct g_dev_info
{
	eamp_info_t eamp_info[6];
	bcu_info_t bcu_info[2];
	ccu_info_t ccu_info[2];
	pcu_info_t pcu_info[12];
	cmu_info_t cmu_info[2];
}g_dev_fault_info_t;//������������������������
/////<<<<<<<<<<<<<<<<<<<<<<<<<<device info define over<<<<<<<<<<<<<<<<<<<<<<<<<<<</


///////////>>>>>>>>>>>>>>>>>>>>>>>thread communication define beign>>>>>>>>>>>>>>>>>>>>>>>
/** ���������������������������������������������������������������
 *	������������������������������������������������������������
 *	������������������������������������������
 */
typedef struct
{
	char device_name[DEVICE_NAME_LENGTH];	///<���������������
	unsigned char device_no;					///<���������������
}threads_communication_type_t;
//////<<<<<<<<<<<<<<<<<<<<<<<<<<thread communication define over<<<<<<<<<<<<<<<<<<<<<<<<<<

typedef struct
{
	unsigned char get_or_set_key_info;//������������������������������
	unsigned char line_no;//���������
	unsigned char region_no;//���������
	unsigned char bcu_status[2];//������������
}pa_key_info_t;//������������

typedef struct
{
	unsigned char get_or_set_tcms_effective_flag;//0������������1������TCMS������������
	unsigned char tms_effective_flag;//TCMS������������
}tcms_effective_flag_info_t;//TCMS���������������������

typedef struct
{
	unsigned char line_no;//���������
}clear_all_skip_station_t;//���������������������������

typedef struct
{
	unsigned char device_state;///<0:nomal 1:updating
}device_state_t;//������������

typedef struct
{
	unsigned char desire_eamp_voulme;//EAMP������������
}eamp_vol_info_t;


////////>>>>>>>>>>>>>>>>>>>>>>>running info define begin>>>>>>>>>>>>>>>>>>>>>>>
typedef struct
{
	unsigned char line_no;//���������
	unsigned char region_no;//���������
	unsigned char region_update_type;///<0:according to the region_no 1:otherwise
	unsigned char start_station_no;//���������
	unsigned char terminal_station_no;//���������
	unsigned char up_or_down;//���������
	unsigned char whether_the_cycle;//������������
	unsigned char get_or_set;///<0:want to require the line info 1:set the line info
	unsigned char current_station_no;//add 2015-7-14 wilson
}line_info_t;//���������������

//struct REGIONSTATION
typedef struct
{
	unsigned char line_no;
	unsigned char region_no;
	unsigned char running_direction;//1���������-������  2���������-������
	unsigned char whether_the_cycle_bus;
	unsigned char start_station_no;
	unsigned char over_station_no;
	unsigned char current_region_flag;
    unsigned char start_time[10];
    unsigned char end_time[10];
}region_station_t;//������������

//This struct is used to record the effective of station
typedef struct
{
	unsigned char line_number;//���������
	unsigned char station_no;//���������
	unsigned char effective;//������������
	char station_chinese_name[STATION_NAME_LENGTH];//������������������
	char station_english_name[STATION_NAME_LENGTH * 2];//������������������
	unsigned char station_audio[100];
	void *p_station_info;//������������������������������
	unsigned char open_door_side[2];///<2014-08-15 ���������������
}station_information_t;//���������
///////<<<<<<<<<<<<<<<<<<<<<<<<<<running info define over<<<<<<<<<<<<<<<<<<<<<<<<<<


////////>>>>>>>>>>>>>>>>>>>>>>>failure info define begin>>>>>>>>>>>>>>>>>>>>>>>
typedef struct FailureInfoTableType
{
       int fail_code;
       char *description;
       char *resolution;
}failure_info_table_t;
////<<<<<<<<<<<<<<<<<<<<<<<<<<failure info define over<<<<<<<<<<<<<<<<<<<<<<<<<<

///<add  by wilson,2013-10-15
typedef struct
{
	unsigned char version_one;
	unsigned char version_two;
	unsigned char version_three;
}device_software_version_t;//���������

typedef struct {
	unsigned char update_state; ///< <0>: not be updated; <1>: updating; <2>: updated
	unsigned char reserve_one;
	unsigned char reserve_two;
	unsigned char reserve_three;	
} db_file_update_state_t;

#define CONFIG_EAMP_PRIOR_SWTICH ///<

///<changed by wds 20160802 begin
/****************************************************************************/
/*
 * ���������������������TCMS������������
 * ���������������������������TCMS������PIS���������������
 */
typedef struct
{
	unsigned short int life_signal;	
	unsigned short int train_no;	///<���������������������������������������
	current_time_t tcms_time;	///<���������������������������
	unsigned short int velocity;	///<������������
	char temperture;	///<������������������
	unsigned char cmu_flag;	///<1=TC1���������2=TC2������
	unsigned char host_flag;	///<1=TC1���������2=TC2������
	unsigned char door_action;	///<1=���������������2=������������
	unsigned char broadcast_mode;	///<0=���������������������1=ATO������������������2=PIS������������������3=HMI���������������4=PIS������������
	unsigned char whether_cycle;	///<1=���������2=���������
	unsigned char up_or_down;	///<1=���������������2=������������
	unsigned char last_train;///<1=���������2=���������
}TCMS_common_t;


/** ���������������������tms������������������
 *	���������������������������������������������������
 */
typedef	 struct
{
	unsigned short int life_signal;
	unsigned short int start_station_code;	///<���������,ATC���������ID���������������������ID���������������ID
	unsigned short int current_station_code;	///<���������
	unsigned short int next_station_code;		///<���������
	unsigned short int end_station_code;
	unsigned char door_side;///<1=������������2=������������3=���������������������4=���������������������������������5=������������������������������
	unsigned char broadcast_type;///<1=������������2=���������3=������������4=������
	unsigned short int distance;	///<���������������������������������
	unsigned char trigger_type;	///<���������������1=���������������������2=������������������
	unsigned char up_down;						///<������������������������ 1:������ 2���������

	///<reserved
	/*
	unsigned char tms_auto_active;				///<������������������������
	unsigned char tms_auto_pre_read;			///<������������������
	unsigned char tms_auto_begin_or_over;				///<���������������������������
	unsigned char tms_auto_response;				///<������������������
	unsigned char line_number;					///<������������3���4������
	
	unsigned char stop_or_leave;						///<������������ 0:��������� 1���������
	unsigned char door_state;						///<������������
	unsigned short int train_speed;				///<������������
	unsigned short int train_distance;			///<������������
	unsigned char key_side;						///<���������
	unsigned char tms_emerg_times;		///<������������������:1���3������������
	unsigned char tms_emerg_sequence;	///<���������������������������������
	unsigned char tms_type_flag;///<1:tms auto  2:tms half auto  3:tms manual  4:tms emerg
	unsigned char tms_ato_effective;
	*/
}ATC_auto_ann_t;

/*
 * ���������������������tms������������������������������tms���������������������������������
 * ���������������������������������������������������
 */
typedef	 struct
{
	unsigned short int start_station_code;		///<���������
	unsigned short int current_station_code;	///<���������
	//unsigned short int next_station_code;	///<���������,������������������������������������������������������������������������������������
	unsigned short int end_station_code;
	
	unsigned short int skip_station_map0;	///<���������������������������(1-16)���������������������������������������0���������������������
	unsigned short int skip_station_map1;	///<���������������������������(17-32)���������������������������������������0���������������������
	unsigned short int skip_station_map2;	///<���������������������������(33-48)���������������������������������������0���������������������
	unsigned char HMI_set_confirm;	///<1=���������0=������
	/*
	unsigned char tms_manual_active;				///<������������������������
	unsigned char tms_manual_begin_or_over;				///<���������������������������
	unsigned char tms_manual_response;			///<������������������
	unsigned char line_number;					///<������������3���4������
	unsigned char up_down;						///<������������������������ 0:������ 1���������
	unsigned char ann_type;						///<������������ 0:��������� 1���������
	unsigned char door_side;						///<���������
	unsigned char door_state;						///<������������
	unsigned short int train_speed;				///<������������
	unsigned short int train_distance;			///<������������
	unsigned char key_side;						//���������
	*/
}PIS_auto_ann_t;

/*
 * ���������������������������������������
 * ���������������������������������������������������
 */
typedef struct
{
	unsigned short int station_code;
	unsigned char broadcast_type;	///<1=������������������2=���������3=���������4=���������������5������������
	unsigned char trigger_confirm;	///<������������������������������
	
	///<reserved
	/*
	unsigned char manual_active;					///<������������������������
	unsigned char manual_pre_read;			///<������������������
	unsigned char manual_begin_or_over;					///<���������������������������
	unsigned char manual_response;				///<������������������
	unsigned char line_number;					///<������������3���4������
	unsigned char up_down;						///<������������������������ 0:������ 1���������
	unsigned char stop_or_leave;					///<������������ 0:��������� 1���������;������������������
	unsigned short int start_station_code;		///<���������
	unsigned short int current_station_code;	///<���������
	unsigned short int next_station_code;		///<���������
	unsigned short int end_station_code;		///<���������
	unsigned char door_side;						///<���������
	unsigned char key_side;						///<���������
	*/
}HMI_manual_ann_t;


/*
 * ���������������������������������������
 * ���������������������������������������������������
 */
typedef struct
{
	unsigned short int emerg_sequence;	///<���������������������������������
	unsigned char emerg_begin_or_over;	///<���������������������������,1=���������2=������
	unsigned char emerg_times;		///<������������������:1���3������������

	///<reserved
	/*
	unsigned char emerg_active;		///<������������������������
	unsigned char emerg_response;	///<������������������
	*/
}HMI_emerg_ann_t;


/*
 * ���������������������TCMS to PIS ������������������
 * ���������������������������TCMS������PIS������������������������������:
 * TCMS������������
 * ATC���������������������
 * PIS���������������������
 * HMI������������������
 * HMI������������������
 */
typedef struct
{
	TCMS_common_t		common;
	ATC_auto_ann_t		atc_auto;
	PIS_auto_ann_t		pis_auto;
	HMI_manual_ann_t	manual;
	HMI_emerg_ann_t		emerg;
}TCMSToPIS_t;


/****************************************************************************/

typedef struct
{
	unsigned char dev_no;	///<������������������1���2���3���4���5���6���7���8.
	unsigned char online;	///<1=������
	///<���������2bits������PCU���4bits���������������������10bits���
	///<LED���������2bits������LED���������4bits������LED���������2bits���
	///<1=���������0=������
	unsigned char sub_dev_fault[3];
}eamp_fault_t;

typedef struct
{
	unsigned char dev_no;	///<ccu������������1���2
	unsigned char online;	///<1=ccu������
	unsigned char head_led;	///<1=������������
}ccu_fault_t;

typedef struct 
{
	unsigned char dev_no;	///<������������������������1���2
	unsigned char online;	///<1=������
	
	///<1=���������0=������
	///<TC1������������������1������0bit������TC1������������������2������1bit������TC1���������������������2bit���
	///<TC2������������������1������3bit������TC2������������������2������4bit������TC2���������������������5bit���
	unsigned char driver_camera;	
	
	///<1=���������0=������
	///<���������������8������������������������������8���������������������������������8���������������
	unsigned char car_camera[8];

}monitor_fault_t;

typedef struct 
{
	unsigned char dev_no;	///<������������������������1���2
	unsigned char online;	///<1=������
	
	///<1=���������0=������
	///<���������������8���TV���������������������������8������������������8���TV���������������������8���������������
	unsigned char TV_fault[8];	
}media_fault_t;

/*
 * ���������������������PIS���������������������
 * ������������������������������PIS���������������������
 */
typedef struct
{
	unsigned char fault_level;	///<1=���������������2=���������������3=������������
	///<���������2bits������PCU���4bits���������������������10bits������ LED���������2bits������LED���������4bits������LED���������2bits���
	eamp_fault_t eamp1;
	eamp_fault_t eamp2;
	eamp_fault_t eamp3;
	eamp_fault_t eamp4;
	eamp_fault_t eamp5;
	eamp_fault_t eamp6;
	eamp_fault_t eamp7;
	eamp_fault_t eamp8;
	ccu_fault_t ccu1;
	ccu_fault_t ccu2;
	unsigned char bcu1;		///<BCU,1=������
	unsigned char bcu2;		///<BCU,1=������
	monitor_fault_t monitor1;	
	monitor_fault_t monitor2;
	media_fault_t media1;
	media_fault_t media2;
}PIS_fault_t;

/*
 * ���������������������PIS������TCMS������������������������
 * ���������������������PIS���������������������������
 */
typedef struct
{
	unsigned short int life_signal;	///<PIS������������
	unsigned char host_flag;	///<1=TC1���������2=TC2������
	unsigned char broadcast_volume;	///<������������
	unsigned char live_volume;	///<������������
	unsigned char media_volume;	///<������������
	unsigned char D2D_volume;	///<������������������
	unsigned char D2P_volume;	///<������������������������������
	unsigned char monitoring_volume;	///<������������
	unsigned char broadcast_mode;	///<���������������������1=ATO������������������2=PIS������������������3=HMI���������������4=PIS������������
	unsigned short int start_station_code;		///<���������
	unsigned short int current_station_code;	///<���������
	unsigned short int next_station_code;	///<���������
	unsigned short int end_station_code;	///<���������
	unsigned char PCU_request[4];	///<PCU������������������������������4���PCU���������������������������������PCU
	unsigned char PCU_connect[4];	///<PCU������������������������������4���PCU���������������������������������PCU
	unsigned short int broadcast_version;	///<���������������������������Vx.y.z(8.4.4������),x������bit15-bit8���y������bit7-bit4���z������bit3-bit0���
	unsigned short int monitor_version;	///<������������������������
	unsigned short int media_version;	///<������������������������
	unsigned char running_over;	///<1=������������
}PIS_state_and_version_t;

/*
 * ���������������������PIS to TCMS ������������������
 * ���������������������������PIS���������PIS������������������������������:
 * PIS������������������
 * PIS���������������������������
 */
typedef struct
{
	PIS_fault_t	fault;
	PIS_state_and_version_t	state_and_version;
}PISToTCMS_t;

/****************************************************************************/
///<changed by wds 20160802 end


#endif /* STRUCT_TYPE_H_ */

