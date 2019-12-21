/************************************************************************/
/*    �豸�澯����                                                */
/************************************************************************/
#define ALARM_NORMAL                    (u8)0x00        //�豸����
#define ALARM_GENERAL                   (u8)0x01        //��ͨ�澯
#define ALARM_IMPORTANT                 (u8)0x02        //��Ҫ�澯
#define ALARM_CRITICAL                  (u8)0x04        //���ظ澯
#define ALARM_UNKNOW                    (u8)0x05        //δ֪�澯

// �澯״̬
enum TnmStatusType
{
	TNM_STATUS_ALARM            = 0,        // ��ʾ����������ĸ澯״̬(�豸���ߵ�)
	TNM_STATUS_NORMAL           = 1,        // ��ʾ����������״̬(�豸���ߵ�)
};

// �澯��
enum EM_AlarmCode
{
	TNM_ALARM_CODE_DEV_OFFLINE             = 0,//�ն��豸������
	TNM_ALARM_CODE_DEV_CPU_STATUS          = 1,//�ն��豸CPUʹ���ʸ���ָ����ֵ�澯
	TNM_ALARM_CODE_DEV_LOSEPACKET_GENERIC  = 2,//�ն��豸��������һ�㶪��(�����ʳ���5%)
	TNM_ALARM_CODE_DEV_LOSEPACKET_BAD      = 3,//�ն��豸�����������ض���(�����ʳ���10%)
	TNM_ALARM_CODE_DEV_LOSEVIDEOSRC_STATUS = 4,//�ն��豸��ƵԴ��ʧ�澯
	TNM_ALARM_CODE_DEV_REGISTER_GK_FAIL    = 5,//�ն��豸ע��GKʧ��
	TNM_ALARM_CODE_DEV_VERSINO_LOW         = 6,//�ն��豸�汾����
	TNM_ALARM_CODE_DEV_EXCEPTIONAL_REBOOT  = 7,//�ն��豸�쳣����
};