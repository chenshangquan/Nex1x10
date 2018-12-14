#if !defined(_NMSCOMMON_H_)
#define _NMSCOMMON_H_

//NMS的监听端口
#define NMS_LISENT_PORT							(u16)1727

/************************************************************************/
/* 设备类型                                                             */
/************************************************************************/
// 业务类型定义
enum TnmServiceType
{
  //未知业务类型
  TNM_SERVICE_UNKNOW = 0,
		
	//
	TNM_SUPER_SERVICE_3AS = 1,
	TNM_SUPER_SERVICE_NMS_MANAGER = 2,
	
	//行业终端
	TNM_SERVICE_KDV_MT_BEGIN =     10,
	TNM_SERVICE_KDV_MT_KDV7620,  	//11
	TNM_SERVICE_KDV_MT_KDV7610,		//12
	TNM_SERVICE_KDV_MT_KDV7210,		//13
	TNM_SERVICE_KDV_MT_TS6610,		//14
	TNM_SERVICE_KDV_MT_TS5610,		//15
	TNM_SERVICE_KDV_MT_KDV8010A,	//16
	TNM_SERVICE_KDV_MT_8010 ,			//17
	TNM_SERVICE_KDV_MT_8010A,			//18
	TNM_SERVICE_KDV_MT_8010C,			//19
	TNM_SERVICE_KDV_MT_8000H_M,		//20
	TNM_SERVICE_KDV_MT_RBS2KC,		//21
	TNM_SERVICE_KDV_MT_RBS2K,			//22
	TNM_SERVICE_KDV_MT_RBS2KE,		//23
	TNM_SERVICE_KDV_MT_TS6000,		//24
	TNM_SERVICE_KDV_MT_TS5000,		//25
	TNM_SERVICE_KDV_MT_7820_A,		//26
	TNM_SERVICE_KDV_MT_7820_B,		//27
	TNM_SERVICE_KDV_MT_7920_A,		//28
	TNM_SERVICE_KDV_MT_7920_B,		//29
	TNM_SERVICE_KDV_MT_7921_H,		//30
	TNM_SERVICE_KDV_MT_7921_L,		//31
	TNM_SERVICE_KDV_MT_KDV7810,		//32
	TNM_SERVICE_KDV_MT_KDV7910,		//33
	TNM_SERVICE_KDV_MT_KDV7920,		//34
	TNM_SERVICE_KDV_MT_KDV7820,		//35
	TNM_SERVICE_KDV_MT_KDV7921,		//36
	TNM_SERVICE_KDV_MT_KDV1000,		//37
	TNM_SERVICE_KDV_MT_H600,			//38
	TNM_SERVICE_KDV_MT_H600_L,		//39
	TNM_SERVICE_KDV_MT_H700,			//40
	TNM_SERVICE_KDV_MT_H800 ,			//41
	TNM_SERVICE_KDV_MT_H900,			//42
	TNM_SERVICE_KDV_MT_PCMT,			//43
	TNM_SERVICE_KDV_MT_END,				//44

	//TS终端
	TNM_SERVICE_TS_MT_BEGIN =     80,
	TNM_SERVICE_TS_MT_IPAD,    		//81
	TNM_SERVICE_TS_MT_5610,    		//82
	TNM_SERVICE_TS_MT_H323MT,  		//83
	TNM_SERVICE_TS_MT_6610,    		//84
	TNM_SERVICE_TS_MT_TRUELINK,		//85
	TNM_SERVICE_TS_MT_H323AUTH,		//86 
	TNM_SERVICE_TS_MT_3610,    		//87
	TNM_SERVICE_TS_MT_HD1000,  		//88
	TNM_SERVICE_TS_MT_HD100,   		//89
	TNM_SERVICE_TS_MT_HD100S,  		//90
	TNM_SERVICE_TS_MT_WD1000,  		//91
	TNM_SERVICE_TS_MT_IPHONE,  		//92
	TNM_SERVICE_TS_MT_ANDROID_PAD,   //93
	TNM_SERVICE_TS_MT_ANDROID_PHONE, //94
	TNM_SERVICE_TS_MT_WINDOWS_PAD,   //95
	TNM_SERVICE_TS_MT_END,     //96
	
	//TS服务器
	TNM_SERVICE_TS_SVR_BEGIN =   100,
	TNM_SERVICE_TS_SVR_MPC,     //101
	TNM_SERVICE_TS_SVR_MPU,     //102
	TNM_SERVICE_TS_SVR_CSU,     //103
	TNM_SERVICE_TS_SVR_MTS,     //104
	TNM_SERVICE_TS_SVR_XAP,     //105
	TNM_SERVICE_TS_SVR_LGS,     //106
	TNM_SERVICE_TS_SVR_AGW,     //107
	TNM_SERVICE_TS_SVR_SUS,     //108
	TNM_SERVICE_TS_SVR_H323GW,  //109
	TNM_SERVICE_TS_SVR_MPCD,    //110
	TNM_SERVICE_TS_SRV_NMSSRV,  //111
	TNM_SERVICE_TS_SRV_NMA,     //112
	TNM_SERVICE_TS_SRV_LVS,     //113
	TNM_SERVICE_TS_SRV_LBS,     //114
	TNM_SERVICE_TS_SRV_MEMCACHE, 	//115
	TNM_SERVICE_TS_SRV_XNU,     	//116
	TNM_SERVICE_TS_SRV_ZKS,     	//117
	TNM_SERVICE_TS_SRV_MOOOO,   	//118
	TNM_SERVICE_TS_SRV_MOVISION,	//119
	TNM_SERVICE_TS_SRV_GFS,     	//120
	TNM_SERVICE_TS_SRV_MYSQL,   	//121
	TNM_SERVICE_TS_SRV_MOS,     	//122
	TNM_SERVICE_TS_SRV_OCS,     	//123
	TNM_SERVICE_TS_SRV_NTS,     	//124
	TNM_SERVICE_TS_SRV_MMPU,    	//125
	TNM_SERVICE_TS_SVR_SUSMGR,  	//126
	TNM_SERVICE_TS_SVR_END,
	
	//行业服务器(待完善)
	
	TNM_MO_SERVICE_ALL = 200,          // 所有业务类型
};




/************************************************************************/
/* 原因码定义                                                           */
/************************************************************************/
#define TNM_REASONCODE_SUCCESS             (u16)0   //Success Status
#define TNM_REASONCODE_FINISHED            (u16)1   //Too Big Data, Finished
#define TNM_REASONCODE_NOFINISHED          (u16)2   //Too Big Data, Not Finished
#define TNM_REASONCODE_GENERAL_ERROR       (u16)3   //General Error
#define TNM_REASONCODE_RESOURCE_UNAVAIL    (u16)4   //New or malloc Failed
#define TNM_REASONCODE_INTERNAL_ERROR      (u16)5   //Unexpected internal error
#define TNM_REASONCODE_UNSUPPORTED         (u16)6   //Unsupported function


/************************************************************************/
/*          设备状态定义                                                */
/************************************************************************/
#define TNM_STATE_OFFLINE                   0x00   	//设备离线
#define TNM_STATE_MULT_CONF                 0x01  	//设备在多点会议中
#define TNM_STATE_P2P_CONF                  0x02   	//设备在点对点会议中
#define TNM_STATE_ONLINE                    0x04   	//设备正常在线
#define TNM_STATE_NO_DISTURBING             0x08   	//免打扰状态
#define TNM_STATE_BUSY                      0x10   	//忙碌状态

#endif // _NMSCOMMON_H_