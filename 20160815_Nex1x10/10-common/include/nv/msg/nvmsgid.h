#ifndef _NVMSGID_H_
#define _NVMSGID_H_

#include "kdvtype.h"

//ʹ��protocol buffer�������Ϣ����Ϣid����Ϣ�������һ��buffer�У���ӦCNvMsg����ʹ��OSP����CNvMsg�����bufferʱ��OspPost�ӿڵ�event������������ΪEv_NvOsp_ProtoBufMsg��
#define EV_NV_PBMSG_BGN 1000
enum EmNvProtoBufEvSegs
{
//ϵͳ������Ϣ��
EVSEG_SYSCTRL_BGN          = (EV_NV_PBMSG_BGN),
EVSEG_SYSCTRL_END          = (EVSEG_SYSCTRL_BGN + 100),

//�豸������Ϣ��
EVSEG_DEVICE_BGN,
EVSEG_DEVICE_END           = (EVSEG_DEVICE_BGN + 500),

//ϵͳ������Ϣ��
EVSEG_UPGRADE_BGN,
EVSEG_UPGRADE_END          = (EVSEG_UPGRADE_BGN + 200),

//���������Ϣ��
EVSEG_NETWORK_BGN,
EVSEG_NETWORK_END          = (EVSEG_NETWORK_BGN + 200),

//��������¼��Ϣ��
EVSEG_LOGSERVER_BGN,
EVSEG_LOGSERVER_END        = (EVSEG_LOGSERVER_BGN + 200),

//MP��ƽ̨ͨ����Ϣ��
EVSEG_MPCOMMON_BGN,
EVSEG_MPCOMMON_END         = (EVSEG_MPCOMMON_BGN + 200),

//MP Ӳ�ն�ƽ̨(linux,android)��Ϣ��
EVSEG_MPEMBED_BGN,
EVSEG_MPEMBED_END          = (EVSEG_MPEMBED_BGN + 300),

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

//X500�ն˽���ģ����Ϣ��
EVSEG_TERINTERFACE_BGN,
EVSEG_TERINTERFACE_END           = (EVSEG_TERINTERFACE_BGN + 200),

//ϵͳ������������Ϣ��
EVSEG_UPGRADESERVER_BGN,
EVSEG_UPGRADESERVER_END          = (EVSEG_UPGRADESERVER_BGN + 200),
//////////////////////////////////////////////////////////////////////////
// �������������������������������������ָ��ߡ�������������������������������//
//																	    //
//     ������BLL��Ϣ�Ρ�����sdk��nvservice��ͨѶ���޹���Ϣ��������         //
//////////////////////////////////////////////////////////////////////////
#define EV_NV_BLLPBMSG_BGN 0x00070000

//BLLϵͳ������Ϣ��
EVSEG_BLL_SYSCTRL_BGN          = (EV_NV_BLLPBMSG_BGN),
EVSEG_BLL_SYSCTRL_END          = (EVSEG_BLL_SYSCTRL_BGN + 100),


//BLL�豸������Ϣ��
EVSEG_BLL_DEVICE_BGN,
EVSEG_BLL_DEVICE_END           = (EVSEG_BLL_DEVICE_BGN + 500),

//BLLϵͳ������Ϣ��
EVSEG_BLL_UPGRADE_BGN,
EVSEG_BLL_UPGRADE_END          = (EVSEG_BLL_UPGRADE_BGN + 200),

//BLL���������Ϣ��
EVSEG_BLL_NETWORK_BGN,
EVSEG_BLL_NETWORK_END          = (EVSEG_BLL_NETWORK_BGN + 200),

//BLL��������¼��Ϣ��
EVSEG_BLL_LOGSERVER_BGN,
EVSEG_BLL_LOGSERVER_END        = (EVSEG_BLL_LOGSERVER_BGN + 200),

//BLLMP��ƽ̨ͨ����Ϣ��
EVSEG_BLL_MPCOMMON_BGN,
EVSEG_BLL_MPCOMMON_END         = (EVSEG_BLL_MPCOMMON_BGN + 200),

//BLL MP Ӳ�ն�ƽ̨(linux,android)��Ϣ��
EVSEG_BLL_MPEMBED_BGN,
EVSEG_BLL_MPEMBED_END          = (EVSEG_BLL_MPEMBED_BGN + 300),

//BLL������Ϣ�Σ���Key��Ӧ��
EVSEG_BLL_CONFIG_BGN,
EVSEG_BLL_CONFIG_END        = (EVSEG_BLL_CONFIG_BGN + 2000),

//BLL ��չ������Ϣ�Σ�����һ��/���/�������ã�
EVSEG_BLL_CONFIG_EX_BGN,
EVSEG_BLL_CONFIG_EX_END     = (EVSEG_BLL_CONFIG_EX_BGN + 200),

//BLL�ն˿ͻ��˽���ģ����Ϣ��
EVSEG_BLL_ACCESS_BGN,
EVSEG_BLL_ACCESS_END           = (EVSEG_BLL_ACCESS_BGN + 200),

//BLL misc��Ϣ��
EVSEG_BLL_MISC_BGN,
EVSEG_BLL_MISC_END             = (EVSEG_BLL_MISC_BGN + 500),


//BLL������Ϣ��
EVSEG_BLL_CONF_BGN,
EVSEG_BLL_CONF_END             = (EVSEG_BLL_CONF_BGN + 1000),

//BLL X500�ն˽���ģ����Ϣ��
EVSEG_BLL_TERINTERFACE_BGN,
EVSEG_BLL_TERINTERFACE_END           = (EVSEG_BLL_TERINTERFACE_BGN + 200),

//BLLϵͳ������������Ϣ��
EVSEG_BLL_UPGRADESERVER_BGN,
EVSEG_BLL_UPGRADESERVER_END          = (EVSEG_BLL_UPGRADESERVER_BGN + 200),
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