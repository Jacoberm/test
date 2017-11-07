/*
 * Copyright (c) 2012���MIT
 * All right reserved.
 *
 * ���������������data_struct.h
 * ���������������
 * ���    ���������������������������
 *
 * ���������������V1.0.3
 * ���    ������wilson
 * ���������������2012-10-08
 *
 * ���������������V1.0.2
 * ���������  ���wilson
 * ���������������2012-9-27
 *
 *  ���������������V1.0.1
 * ���������  ���wilson
 * ���������������2012-8-25
 *
 * ���������������V1.0.0
 * ���������  ���������
 * ���������������2012-08-23
 */

#ifndef DATA_STRUCT_H_
#define DATA_STRUCT_H_
#include "struct_type.h"
#include "dynamic_map.h"
#include "tms_module.h"
#include "ts_type.h"

//#define CONFIG_TEST_SND_IN_MULTI_THREAD   ///< debug for sound_card, 01-10

#ifdef  CONFIG_BCU_SYNC_FROM_CCU_NET
#include "bcu_get_data_from_ccu_type.h"
#endif

/** ���������������������������������������������
 *  ���������������������������������������������������������������������������������������
 */
typedef union
{
	occ_ann_t occ_announce;                 ///<occ������
	outer_3d5_ann_t outer_3d5_ann;			///<3d5������
	live_ann_t live_announce;   			///<������������
	emerg_ann_t emerg_announce;				///<������������������
	manual_ann_t manual_annnounce;			///<������������������
	tms_auto_ann_t tms_auto_announce;		///<tms������������������
	tms_manual_ann_t tms_manual_announce;	///<tms���������������������
	tms_live_ann_t tms_live_announce;   			///<tms������������
	station_information_t station_information; ///<������������
	line_info_t line_info;///<���������-���������������
	db_file_update_state_t db_file_state; ///< for changming
	pa_key_info_t pa_key_info;///<������������������
	clear_all_skip_station_t clear_all_skip_station;///<���������������������������
	device_state_t device_state;
	eamp_vol_info_t eamp_vol_info;
}event_infomation_ann_t;

/** ���������������������������������������������
 *  ���������������������������������������������������������������������������������������
 */
typedef union
{
	d2d_intercomm_t d2d_intercomm;			///<������������
	d2p_intercomm_t d2p_intercomm;			///<������������
}event_infomation_intercomm_t;


/** ������������������������������������������
 *	������������������������������������������������������
 */
typedef struct
{
	  char devices_name[DEVICE_NAME_LENGTH];					///<������������
	  int devices_no;												///<������������
	  unsigned char current_state_ann;							///<������������������������
	  event_infomation_ann_t event_infomation_ann;				///<������������������
	  unsigned char current_state_intercom;						///<������������������������
	  event_infomation_intercomm_t event_infomation_intercom;	///<������������������
	  int time;	///<������
	  unsigned int config_db_version;  ///<add, 2013
	  unsigned int ann_db_version;  ///<add, 2013	
	  unsigned char driver_key_inserted; ///<ach add, 2013
	  unsigned char is_db_server; ///<ach add, 2013
	  unsigned int state_count;  ///<add, 2013	 
}device_bcu_state_t;

/** ���������������������������������
 *	���������������������������������������������
 */
typedef struct
{
	  char devices_name[DEVICE_NAME_LENGTH];				///<������������
	  int devices_no;											///<������������
	  unsigned char current_state;							///<������������������
	  event_infomation_ann_t event_infomation_ann; 		///<������������������
	  int time;												///<������
	  unsigned int config_db_version;  ///<add, 2013
	  unsigned int ann_db_version;  ///<add, 2013	
	  unsigned char is_db_server; ///<ach add, 2013
	  unsigned int state_count;  ///<add, 2013
}device_eamp_state_t;

/** ������������������������������������������
 *	������������������������������������������������������
 */
typedef struct
{
	  char devices_name[DEVICE_NAME_LENGTH];						///<������������
	  int devices_no;													///<������������
	  unsigned char current_state_intercom;							///<������������������,wilson 2012-10-26 current_state->current_state_intercom
	  event_infomation_intercomm_t event_infomation_intercom;		///<������������������
	  unsigned char  request_sequence;														///<������
	  unsigned int config_db_version;  ///<add, 2013
	  unsigned int ann_db_version;  ///<add, 2013	
	  unsigned char is_db_server; ///<ach add, 2013
	  unsigned int state_count;  ///<add, 2013
}device_pcu_state_t;

/** ������������������������������������������
 *	������������������������������������������������������
 */
typedef struct
{
	  char devices_name[DEVICE_NAME_LENGTH];	///<������������
	  int devices_no;								///<������������
	  unsigned char current_state;				///<������������������
	  int time;									///<������
	  unsigned int config_db_version;  ///<add, 2013
	  unsigned int ann_db_version;  ///<add, 2013	
	  unsigned char is_db_server; ///<ach add, 2013
	  unsigned int state_count;  ///<add, 2013
}device_ccu_state_t;

//add begin, 2013
#define GD_VALUE_MAX_MACRO(a,b)	((a)>=(b)?(a):(b))
#define TMP_MAX_A (GD_VALUE_MAX_MACRO(sizeof(device_eamp_state_t), sizeof(device_pcu_state_t)))
#define TMP_MAX_B (GD_VALUE_MAX_MACRO(TMP_MAX_A, sizeof(device_bcu_state_t)))
#define TMP_MAX_C	(GD_VALUE_MAX_MACRO(TMP_MAX_B, sizeof(device_ccu_state_t)))

#ifdef CONFIG_BCU_SYNC_FROM_CCU_NET
#define GD_DEV_INFO_MAX_LEN	((GD_VALUE_MAX_MACRO(TMP_MAX_C, sizeof(bcu_get_db_data_from_ccu_t)))+4) ///< last 4 bytes are CRC
#else
#define GD_DEV_INFO_MAX_LEN	(TMP_MAX_C+4) ///< last 4 bytes are CRC
#endif

typedef struct
{
        unsigned int gd_sync_context_len;
        unsigned char gd_sync_req;
        unsigned char gd_sync_res;
        unsigned char gd_sync_mask; //config db sync;  station db sync;  audio file sync; global dev info sync; sys update
        unsigned char gd_sync_context[GD_DEV_INFO_MAX_LEN];
        unsigned char gd_source_ip[IP_NAME_LENGTH];
}gd_sync_cmd_t;

typedef union
{
      gd_sync_cmd_t  gd_sync_cmd_info;
}event_information_common_t;

typedef struct
{
	unsigned char event_type_common;                        ///< 
	event_information_common_t  event_info_common; ///< 
	unsigned int  sequence;                                             ///<
}pa_common_information_t;
//add end, 2013

typedef struct
{
	int pkg_number;
	int pkg_type; //0:���������������������������������������;1:������������������������������������; 2:������������
	//1:pa/l_pa start;2:pc/l_pc start;3:cc/l_cc start;4:pa/l_pa end;5:pc/l_pc end;6:cc/l_cc end .add by zhw-2014-5-4
	int cmd_type;
}cmu_cmd_t; //add by zhw-5-4

/** ������������������������������������������������
 *	���������������������������������������������������������
 *	���������������������������������������������������
 */
typedef struct
{
	void (*init)(void);								//������������������
	void (*setinformation)(unsigned char event_type,
								char *src_devices_name,
								unsigned char src_devices_no,
								unsigned char state_request,
								unsigned char request_or_over,
								unsigned char line_number,
								unsigned char region_number,
								unsigned int broadcast_sequence,
								unsigned char broadcast_times,
								unsigned char arrived_station,
								unsigned char current_station_code,
								unsigned char station_effective,
								unsigned char whether_pre_read,
								unsigned char dst_device_number
								);		///<������������������

	char src_devices_name[DEVICE_NAME_LENGTH];		///<������������
	unsigned char src_devices_no;					///<������������
	unsigned char event_ptt_state;
	unsigned char event_type_ann;			///<������������
	event_infomation_ann_t event_info_ann;	///<������������
	unsigned char event_type_intercom;				///<������������
	event_infomation_intercomm_t event_info_intercom;///<������������
	cmu_cmd_t line_status;
	
	unsigned char update_tcms_effective_flag;
	tcms_effective_flag_info_t tcms_effective_flag_info;
	int  sequence;                                 ///<���������������;
}send_infomation_t;

/*  ���������������������������������������������������������������������������
 *	������������������������������������������������������������������������������������
 *	������������������������������
 */
typedef struct
{
	char dst_devices_name[DEVICE_NAME_LENGTH];		///<���������������
	int  dst_devices_no;								///<���������������
	int  time;
	send_infomation_t send_information;				///<������������������������������
}network_send_package_t;

/** ������������������������������������������������������������
 *	���������������������������������������������������������
 *	���������������������������������������������������
 */
typedef struct
{
	void (*init)(void);
	void (*setglobalinfo)(send_infomation_t);

	device_bcu_state_t  device_bcu[CONFIG_BCU_NUM + 1];    ///<���������������������������
	device_ccu_state_t  device_ccu[CONFIG_CCU_NUM + 1];    ///<���������������������������
	device_eamp_state_t device_eamp[CONFIG_EAMP_NUM + 1];  ///<������������������
	device_pcu_state_t device_pcu[CONFIG_PECU_NUM + 1];   ///<���������������������������
}global_device_info_state_t;


// ���������������������������
typedef struct eamp_dev_ifo
{
	int set_online; // add by zhw-2014-11-24
	int reply;
	int dev_number;
	eamp_info_t eamp_info;
	struct eamp_dev_ifo *next;
}eamp_dev_info_t;

typedef struct bcu_dev_info
{
	int set_online;
	int reply;
	int dev_number;
	bcu_info_t bcu_info;
	struct bcu_dev_info *next;
}bcu_dev_info_t;

typedef struct ccu_dev_info
{
	int set_online;
	int reply;
	int dev_number;
	ccu_info_t ccu_info;
	struct ccu_dev_info *next;
}ccu_dev_info_t;

typedef struct pcu_dev_info
{
	int set_online;
	int reply;
	int dev_number;
	pcu_info_t pcu_info;
	struct pcu_dev_info *next;
}pcu_dev_info_t;

typedef struct cmu_dev_info
{
	int set_online;
	int reply;
	int dev_number;
	cmu_info_t cmu_info;
	struct cmu_dev_info *next;
}cmu_dev_info_t;

typedef struct
{
	eamp_dev_info_t *eamp_dev_info_head;
	bcu_dev_info_t *bcu_dev_info_head;
	ccu_dev_info_t *ccu_dev_info_head;
	pcu_dev_info_t *pcu_dev_info_head;
	cmu_dev_info_t *cmu_dev_info_head;
}dev_status_info_t;

typedef struct
{
	int package_type; //1���������������������������2���������������������������3������:;
	int package_number;//
	union dev_info
	{
		eamp_info_t eamp_info;
		bcu_info_t bcu_info;
		ccu_info_t ccu_info;
		pcu_info_t pcu_info;
		cmu_info_t cmu_info;
	}dev_info_u;
	current_time_t current_time; //add by zhw 2014-5-20,time info send to client which service get from TMCS;
}heart_package_t;

typedef struct PttStateType
{
    unsigned char dst_ptt;
    unsigned char src_ptt;
}ptt_state_t;

typedef struct device_volume_info
{
	char device_name[DEVICE_NAME_LENGTH];
	int device_no;
	int device_volume;
	int device_adjust_volume;
	int device_no_recept_timeout;
}ts_dev_volume_info_t;
typedef struct
{
	char monitor_speaker_state;
	char monitor_speaker_volume;
}monitor_speaker_control_t;

typedef struct
{
	unsigned char bcu_log_info[200];
}bcu_log_info_t;
typedef struct
{
	unsigned char intercomm_type;///< 0:d2d 1:d2p 2:d2d break up d2p
	unsigned char src_no;
	unsigned char dst_no;
	unsigned char begin_or_over;
}intercomm_audio_data_log_t;
typedef struct
{
	unsigned char pa_volume;
	unsigned char monitor_volume;
	unsigned char tcms_flag;///<add by wilson,inorder to tell eamp current tcms flag
	unsigned char key_info;
	current_time_t tcms_time;
	unsigned int velocity;	///<add by wds 20160811 for LED dispalying the velocity of train
	char tempture;	///<add by wds 20160811 for LED dispalying the tempture of cars
}eamp_heart_beta_t;
typedef struct
{
	unsigned char d2d_volume;
	unsigned char d2p_volume;
	unsigned char tcms_flag;///<add by wilson,inorder to tell eamp current tcms flag
}intercomm_volume_info_t;

typedef struct
{
	unsigned char speed;
	unsigned char door_status;	//0:���������������������������1������������������
	int whether_start_simulateddu_flag;
}simulate_ddu_t;

typedef struct
{
	unsigned char old_car_line_no;
	unsigned char state;
}cmu_car_type_t;

typedef struct
{
	unsigned char event_type;	///<1:PA 2:CC 3:������
	unsigned char state_flag;	//1:������ 0���������
}cmu_new_comm_type_t;

typedef struct
{
	unsigned char ack_state;
}cmu_ack_state_t;

typedef struct
{
	unsigned char get_or_set;
	unsigned char tcms_current_cmu_state;
}tcms_cmu_state_t;

typedef struct
{
	unsigned char pcu_refuse_no;
	unsigned char pcu_recept_no;
	unsigned char pa_volume;
	unsigned char monitor_volume;
	unsigned char d2d_volume;
	unsigned char d2p_volume;
	unsigned char pa_running_mode;
	unsigned char d2d_running_mode;
}monitor_control_info_t;

typedef union
{
//	heart_package_t heart_package;
	ptt_state_t   comm_ptt_state; ///< pkg_type = 3
	ts_dev_volume_info_t ts_dev_volume_info;///<pkg_type = 4
	monitor_speaker_control_t monitor_speaker_control;///< 5 speaker control ���������������
	intercomm_audio_data_log_t intercomm_audio_data_log;///< 8 intercomm auido data recording
	eamp_heart_beta_t eamp_heart_beta;
	intercomm_volume_info_t intercomm_volume_info;
	simulate_ddu_t simulate_ddu;	//TCMS������ddu������������
	cmu_car_type_t cmu_car_type;//COMMON_PACKAGE_TYPE_CMU_CAR_TYPE
	cmu_ack_state_t cmu_ack_state;//COMMON_PACKAGE_TYPE_ACK_STATE
	tcms_cmu_state_t tcms_cmu_state;//COMMON_PACKAGE_TYPE_TCMS_CMU_STATE
	cmu_new_comm_type_t cmu_new_comm_cmd;//COMMON_PACKAGE_TYPE_NEW_CMU_STATE 16
	monitor_control_info_t monitor_control_info; //COMMON_PACKAGE_TYPE_MONITOR_CONTROL_INFO 18
}common_data_t;

typedef struct
{
	char dst_dev_name[DEVICE_NAME_LENGTH];
	int dst_dev_number;
	char src_dev_name[DEVICE_NAME_LENGTH];
	int src_dev_number;
	int pkg_type; //1������:������������2������: ���3������: 10(TMS_PACKAGE_ID):TMS������;5:speaker control
	common_data_t common_data_u;
}common_package_t;

typedef struct
{
	char dst_dev_name[DEVICE_NAME_LENGTH];
	int dst_dev_number;
	char src_dev_name[DEVICE_NAME_LENGTH];
	int src_dev_number;
//	int pkg_type; //1������:������������2������: ���3������: 10(TMS_PACKAGE_ID):TMS������;5:speaker control
	heart_package_t heart_package;
}network_heart_package_t;

typedef struct
{//���������30 ������������������������������
	char get_or_set_version_info;///0:set 1:get
	char software_version[32];
	char software_date[32];
	char db_version_audio[32];
	char db_version_config[32];
}pa_software_version_t;

typedef struct
{
	unsigned char open_door_flag;	//1:effective; else:no
	unsigned char close_door_flag;  //1:effective; else:no
}door_prompt_t;

typedef union
{
	tms_to_ccu_t tms_to_ccu_info;//<pkg_type=1
	pa_common_information_t pa_common_cmd_info; ///< pkg_type=2
	bcu_log_info_t bcu_log_info;///< pkg_type=6
	g_dev_fault_info_t dev_falut_info;//pkg_type =8
	pa_software_version_t pa_software_version; //pkg_type =12
	door_prompt_t door_prompt_info; //pkg_type =22
}common_big_data_t;

typedef struct
{
	char dst_dev_name[DEVICE_NAME_LENGTH];
	int dst_dev_number;
	char src_dev_name[DEVICE_NAME_LENGTH];
	int src_dev_number;
	int pkg_type; //2������:pa_common_information_t
	common_big_data_t common_big_data_u;
}common_big_package_t;

typedef struct {
    int current_event;
    int audio_play_buffer_id;	
    int send_audio_buffer_id;
    int pending_audio_buffer_id;	
    unsigned char enable_play;
    unsigned char enable_sample;	
    unsigned char play_times;	
} audio_play_control_t;

typedef struct {	
    unsigned char dev_no;
    unsigned char play_waiting;
} eamp_audio_sync_t;


typedef enum { BCU,CCU, EAMP, PCU }DevType_t;
typedef enum { ProtocolTestStart,CommQualityTest, SystemReboot, DevFirmwareUpdate,
							OpenAtuo,CloseAtuo,OpenNetPrint,CloseNetPrint,ZhwFunc8,ZhwFunc9 } CmdType_t;
typedef enum { NL,MT,UD,VF,GV,FN } SubCmdType_t;
typedef enum { INVALID,VALID,FAIL,SUCCESS } DevStatus_t;

#pragma pack(4)
typedef struct
{
	int sub_cmd;	
	char dev_name[8];
	int dev_type;	
	int	dev_index;	
	int dev_status;	
	int file_crc;	
	char file_ver[32];
}dfu_info_t;

typedef struct
{
	int cmd;
	dfu_info_t dfu_info;
}network_shell_package_t;
#pragma pack()

/** BCUSendInfoInit������������
 *  ������������������BCU���������������������������������������������
 *
 *  @param   void
 *  @return  null
 */
void BCUSendInfoInit(void);

/** BCUSetInformation������������
 *  ������������������BCU���������������������������������������������
 *
 *  @param ������������
 *  @param ���������������
 *  @param ������������
 *  @param ������������(0)���������(1)
 *  @param ���������
 *  @param ���������������
 *  @param ������������
 *  @param ������������
 *  @param ���������
 *  @param ���������������������������������
 *  @return null
 *  @note ���������������������������������������������������������������������������������������������������������������������������������������������������������0���������������
 */
void BCUSetInformation(unsigned char,char *, unsigned char, unsigned char,unsigned char,unsigned char,
					  	unsigned int, unsigned char, unsigned char,unsigned char,int);

/** InitThreadCommunicationInfo������������
 *  ������������������BCU���������������������������-���������������������������������������������������
 *
 *  @param   void
 *  @return  null
 */
void InitThreadCommunicationInfo(void);		//modify  function name too long

/** SetThreadCommunicationInfo������������
 *  ������������������BCU���������������������������-���������������������������������������������������
 *
 *  @param   ������������
 *  @param   ������������
 *  @param   ���������������
 *  @param   ���������������
 *  @return  null
 */
void SetThreadCommunicationInfo(char *,unsigned char);		//modify


/** GlobalInfoInit������������
 *  ������������������BCU������������������������������������������������������
 *
 *  @param   void
 *  @return  null
 */
//extern void InitGlobalInfo(void);

/** GlobalInfoUpdate������������
 *  ������������������BCU���������������������������������������������������
 *
 *  @param   ���������������������������������
 *  @return  null
 */
//void UpdateGlobalInfo(send_infomation_t);

//������������������������������������
/** JudgeDeviceType������������
 *  ���������������������������������������������������������
 *
 *  @param   ���������
 *  @return  null
 */
//int JudgeDeviceType(char *devices_name);
int GetDeviceType(char *devices_name);			//modify



#endif /* DATA_STRUCT_H_ */
