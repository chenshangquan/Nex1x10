#ifndef _MTMSGID_H_
#define _MTMSGID_H_

#include "kdvtype.h"

//ʹ��protocol buffer�������Ϣ����Ϣid����Ϣ�������һ��buffer�У���ӦCMtMsg����ʹ��OSP����CMtMsg�����bufferʱ��OspPost�ӿڵ�event������������ΪEv_MtOsp_ProtoBufMsg��
#define EV_MT_PBMSG_BGN 1000
enum EmMtProtoBufEvSegs
{
//ϵͳ������Ϣ��
EVSEG_SYSCTRL_BGN          = (EV_MT_PBMSG_BGN),
EVSEG_SYSCTRL_END          = (EVSEG_SYSCTRL_BGN + 100),

//h323Э����Ϣ��
EVSEG_H323_BGN,
EVSEG_H323_END             = (EVSEG_H323_BGN + 1000),

//����Э����Ϣ��
EVSEG_SAT_BGN,
EVSEG_SAT_END              = (EVSEG_SAT_BGN + 1000),

//Э��������Ϣ��
EVSEG_MTPA_BGN,
EVSEG_MTPA_END             = (EVSEG_MTPA_BGN + 1000),

//IM��Ϣ��
EVSEG_IM_BGN,
EVSEG_IM_END               = (EVSEG_IM_BGN + 500),

//MEETING��Ϣ��
EVSEG_MEETING_BGN,
EVSEG_MEETING_END          = (EVSEG_MEETING_BGN + 500),

//AGENT��Ϣ��
EVSEG_AGENT_BGN,
EVSEG_AGENT_END            = (EVSEG_AGENT_BGN + 300),

//����Эͬ��Ϣ��
EVSEG_DATASERVICE_BGN,
EVSEG_DATASERVICE_END      = (EVSEG_DATASERVICE_BGN + 500),

//΢����Ϣ��
EVSEG_MICROBLOG_BGN,
EVSEG_MICROBLOG_END        = (EVSEG_MICROBLOG_BGN + 500),

//�豸������Ϣ��
EVSEG_DEVICE_BGN,
EVSEG_DEVICE_END           = (EVSEG_DEVICE_BGN + 500),

//ϵͳ������Ϣ��
EVSEG_UPGRADE_BGN,
EVSEG_UPGRADE_END          = (EVSEG_UPGRADE_BGN + 200),

//ͨѶ¼��Ϣ��
EVSEG_CONTACT_BGN,
EVSEG_CONTACT_END          = (EVSEG_CONTACT_BGN + 500),

//misc��Ϣ��
EVSEG_MISC_BGN,
EVSEG_MISC_END             = (EVSEG_MISC_BGN + 500),

//���������Ϣ��
EVSEG_NETWORK_BGN,
EVSEG_NETWORK_END          = (EVSEG_NETWORK_BGN + 200),

//��������¼��Ϣ��
EVSEG_LOGSERVER_BGN,
EVSEG_LOGSERVER_END        = (EVSEG_LOGSERVER_BGN + 200),

//MP��ƽ̨ͨ����Ϣ��
EVSEG_MPCOMMON_BGN,
EVSEG_MPCOMMON_END         = (EVSEG_MPCOMMON_BGN + 200),

//MP windowsƽ̨��Ϣ��
EVSEG_MPWIN_BGN,
EVSEG_MPWIN_END            = (EVSEG_MPWIN_BGN + 200),

//MP Ӳ�ն�ƽ̨(linux,android)��Ϣ��
EVSEG_MPEMBED_BGN,
EVSEG_MPEMBED_END          = (EVSEG_MPEMBED_BGN + 300),

//MP �ƶ�ƽ̨��android��ios����Ϣ��
EVSEG_MPMOBILE_BGN,
EVSEG_MPMOBILE_END         = (EVSEG_MPMOBILE_BGN + 200),

//������Ϣ�Σ���Key��Ӧ��
EVSEG_CONFIG_BGN,
EVSEG_CONFIG_END        = (EVSEG_CONFIG_BGN + 2000),

//��չ������Ϣ�Σ�����һ��/���/�������ã�
EVSEG_CONFIG_EX_BGN,
EVSEG_CONFIG_EX_END     = (EVSEG_CONFIG_EX_BGN + 200),

//��Ϣ�ַ�ģ����Ϣ��
EVSEG_DISPATCH_BGN,
EVSEG_DISPATCH_END         = (EVSEG_DISPATCH_BGN + 100),

//�ն˿ͻ��˽���ģ����Ϣ��
EVSEG_ACCESS_BGN,
EVSEG_ACCESS_END           = (EVSEG_ACCESS_BGN + 200),

//�㲥ģ����Ϣ��
EVSEG_MTVOD_BGN,
EVSEG_MTVOD_END           = (EVSEG_MTVOD_BGN + 200),

//restģ����Ϣ��
EVSEG_REST_BGN,
EVSEG_REST_END           = (EVSEG_REST_BGN + 200),

//recordģ����Ϣ��
EVSEG_RECORD_BGN,
EVSEG_RECORD_END           = (EVSEG_RECORD_BGN + 200),

//���������Ϣ��
EVSEG_REST_MEETING_BGN,
EVSEG_REST_MEETING_END           = (EVSEG_REST_MEETING_BGN + 200),

//rest���������Ϣ��
EVSEG_REST_ROSTER_BGN,
EVSEG_REST_ROSTER_END           = (EVSEG_REST_ROSTER_BGN + 200),

//����mcģ����Ϣ��
EVSEG_MTMCSERVICE_BGN,
EVSEG_MTMCSERVICE_END           = (EVSEG_MTMCSERVICE_BGN + 500),


// �����Ϣ��
EVSEG_DIAGNOSE_BGN,
EVSEG_DIAGNOSE_END			   = (EVSEG_DIAGNOSE_BGN + 10),


// ���̨����Ļ��Ϣ��
EVSEG_TEXTIMAGE_BGN,
EVSEG_TEXTIMAGE_END			   = (EVSEG_TEXTIMAGE_BGN + 50),

// mtsecure��Ϣ��
EVSEG_MTSECURE_BGN,
EVSEG_MTSECURE_END			   = (EVSEG_MTSECURE_BGN + 50),

EVSEG_MTAIMSG_BGN,
EVSEG_MTAIMSG_END   =  (EVSEG_MTAIMSG_BGN + 50),


//////////////////////////////////////////////////////////////////////////
// �������������������������������������ָ��ߡ�������������������������������//
//																	    //
//     ������BLL��Ϣ�Ρ�����sdk��mtservice��ͨѶ���޹���Ϣ��������         //
//////////////////////////////////////////////////////////////////////////
#define EV_MT_BLLPBMSG_BGN 0x00070000

//BLLϵͳ������Ϣ��
EVSEG_BLL_SYSCTRL_BGN          = (EV_MT_BLLPBMSG_BGN),
EVSEG_BLL_SYSCTRL_END          = (EVSEG_BLL_SYSCTRL_BGN + 100),

//BLL������Ϣ��
EVSEG_BLL_CONF_BGN,
EVSEG_BLL_CONF_END             = (EVSEG_BLL_CONF_BGN + 1000),

//BLLIM��Ϣ��
EVSEG_BLL_IM_BGN,
EVSEG_BLL_IM_END               = (EVSEG_BLL_IM_BGN + 500),

//BLL MEETING��Ϣ��
EVSEG_BLL_MEETING_BGN,
EVSEG_BLL_MEETING_END          = (EVSEG_BLL_MEETING_BGN + 500),

//BLL AGENT��Ϣ��
EVSEG_BLL_AGENT_BGN,
EVSEG_BLL_AGENT_END            = (EVSEG_BLL_AGENT_BGN + 300),

//BLL����Эͬ��Ϣ��
EVSEG_BLL_DATASERVICE_BGN,
EVSEG_BLL_DATASERVICE_END      = (EVSEG_BLL_DATASERVICE_BGN + 500),

//BLL΢����Ϣ��
EVSEG_BLL_MICROBLOG_BGN,
EVSEG_BLL_MICROBLOG_END        = (EVSEG_BLL_MICROBLOG_BGN + 500),

//BLL�豸������Ϣ��
EVSEG_BLL_DEVICE_BGN,
EVSEG_BLL_DEVICE_END           = (EVSEG_BLL_DEVICE_BGN + 500),

//BLLϵͳ������Ϣ��
EVSEG_BLL_UPGRADE_BGN,
EVSEG_BLL_UPGRADE_END          = (EVSEG_BLL_UPGRADE_BGN + 200),

//BLL�����Ϣ��
EVSEG_BLL_DIAGNOSE_BGN,
EVSEG_BLL_DIAGNOSE_END         = (EVSEG_BLL_DIAGNOSE_BGN + 100),

//BLLͨѶ¼��Ϣ��
EVSEG_BLL_CONTACT_BGN,
EVSEG_BLL_CONTACT_END          = (EVSEG_BLL_CONTACT_BGN + 500),

//BLL misc��Ϣ��
EVSEG_BLL_MISC_BGN,
EVSEG_BLL_MISC_END             = (EVSEG_BLL_MISC_BGN + 500),

//BLL���������Ϣ��
EVSEG_BLL_NETWORK_BGN,
EVSEG_BLL_NETWORK_END          = (EVSEG_BLL_NETWORK_BGN + 200),

//BLL��������¼��Ϣ��
EVSEG_BLL_LOGSERVER_BGN,
EVSEG_BLL_LOGSERVER_END        = (EVSEG_BLL_LOGSERVER_BGN + 200),

//BLLMP��ƽ̨ͨ����Ϣ��
EVSEG_BLL_MPCOMMON_BGN,
EVSEG_BLL_MPCOMMON_END         = (EVSEG_BLL_MPCOMMON_BGN + 200),

//BLLMP windowsƽ̨��Ϣ��
EVSEG_BLL_MPWIN_BGN,
EVSEG_BLL_MPWIN_END            = (EVSEG_BLL_MPWIN_BGN + 200),

//BLL MP Ӳ�ն�ƽ̨(linux,android)��Ϣ��
EVSEG_BLL_MPEMBED_BGN,
EVSEG_BLL_MPEMBED_END          = (EVSEG_BLL_MPEMBED_BGN + 300),

//BLL MP �ƶ�ƽ̨��android��ios����Ϣ��
EVSEG_BLL_MPMOBILE_BGN,
EVSEG_BLL_MPMOBILE_END         = (EVSEG_BLL_MPMOBILE_BGN + 200),

//BLL������Ϣ�Σ���Key��Ӧ��
EVSEG_BLL_CONFIG_BGN,
EVSEG_BLL_CONFIG_END        = (EVSEG_BLL_CONFIG_BGN + 2000),

//BLL ��չ������Ϣ�Σ�����һ��/���/�������ã�
EVSEG_BLL_CONFIG_EX_BGN,
EVSEG_BLL_CONFIG_EX_END     = (EVSEG_BLL_CONFIG_EX_BGN + 200),

//BLL�ն˿ͻ��˽���ģ����Ϣ��
EVSEG_BLL_ACCESS_BGN,
EVSEG_BLL_ACCESS_END           = (EVSEG_BLL_ACCESS_BGN + 200),

//BLL�㲥ģ����Ϣ��
EVSEG_BLL_MTVOD_BGN,
EVSEG_BLL_MTVOD_END           = (EVSEG_BLL_MTVOD_BGN + 200),

//BLL restģ����Ϣ��
EVSEG_BLL_REST_BGN,
EVSEG_BLL_REST_END           = (EVSEG_BLL_REST_BGN + 200),

//BLL recordģ����Ϣ��
EVSEG_BLL_RECORD_BGN,
EVSEG_BLL_RECORD_END           = (EVSEG_BLL_RECORD_BGN + 200),

//BLL ���������Ϣ��
EVSEG_BLL_REST_MEETING_BGN,
EVSEG_BLL_REST_MEETING_END           = (EVSEG_BLL_REST_MEETING_BGN + 200),

//BLL rest���������Ϣ��
EVSEG_BLL_REST_ROSTER_BGN,
EVSEG_BLL_REST_ROSTER_END           = (EVSEG_BLL_REST_ROSTER_BGN + 200),

//BLL����mcģ����Ϣ��
EVSEG_BLL_MTMCSERVICE_BGN,
EVSEG_BLL_MTMCSERVICE_END           = (EVSEG_BLL_MTMCSERVICE_BGN + 500),

//BLL����secģ����Ϣ��
EVSEG_BLL_MTSEC_BGN,
EVSEG_BLL_MTSEC_END           = (EVSEG_BLL_MTSEC_BGN + 500),

//BLL dcsģ����Ϣ��
EVSEG_BLL_DCS_BGN,
EVSEG_BLL_DCS_END           = (EVSEG_BLL_DCS_BGN + 200),

EVSEG_BLL_MTAIMSG_BGN,
EVSEG_BLL_MTAIMSG_END   =  (EVSEG_BLL_MTAIMSG_BGN + 50),

};

#define EV_BGN(SEG) EV_##SEG##_BGN
#define EV_END(SEG) EV_##SEG##_END

#define EV_BLL_BGN(SEG) EV_##SEG##_BLL_BGN
#define EV_BLL_END(SEG) EV_##SEG##_BLL_END


#if !defined(_MESSAGE_HELP_)
#define MESSAGE(m) m,
#define BODY(T, dscrpt)  //T:��Ϣ������ dscrpt:��Ϣ������
#endif

#endif