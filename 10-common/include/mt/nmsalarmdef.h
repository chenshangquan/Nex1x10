/************************************************************************/
/*    设备告警级别                                                */
/************************************************************************/
#define ALARM_NORMAL                    (u8)0x00        //设备正常
#define ALARM_GENERAL                   (u8)0x01        //普通告警
#define ALARM_IMPORTANT                 (u8)0x02        //重要告警
#define ALARM_CRITICAL                  (u8)0x04        //严重告警
#define ALARM_UNKNOW                    (u8)0x05        //未知告警

// 告警状态
enum TnmStatusType
{
	TNM_STATUS_ALARM            = 0,        // 表示各种有问题的告警状态(设备掉线等)
	TNM_STATUS_NORMAL           = 1,        // 表示各种正常的状态(设备上线等)
};

// 告警码
enum EM_AlarmCode
{
	TNM_ALARM_CODE_DEV_OFFLINE             = 0,//终端设备上下线
	TNM_ALARM_CODE_DEV_CPU_STATUS          = 1,//终端设备CPU使用率高于指定阀值告警
	TNM_ALARM_CODE_DEV_LOSEPACKET_GENERIC  = 2,//终端设备码流接收一般丢包(丢包率超过5%)
	TNM_ALARM_CODE_DEV_LOSEPACKET_BAD      = 3,//终端设备码流接收严重丢包(丢包率超过10%)
	TNM_ALARM_CODE_DEV_LOSEVIDEOSRC_STATUS = 4,//终端设备视频源丢失告警
	TNM_ALARM_CODE_DEV_REGISTER_GK_FAIL    = 5,//终端设备注册GK失败
	TNM_ALARM_CODE_DEV_VERSINO_LOW         = 6,//终端设备版本过低
	TNM_ALARM_CODE_DEV_EXCEPTIONAL_REBOOT  = 7,//终端设备异常重启
};