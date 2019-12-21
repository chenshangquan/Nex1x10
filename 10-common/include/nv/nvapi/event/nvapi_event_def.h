/*******************************************************************************//**
*@file          nvapi_event_def.h
*@brief         ʵ��NVAPI��UI(�۲���)���¼�֪ͨ�ķֶζ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_EVENT_DEF_H_
#define _NVAPI_EVENT_DEF_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup defevent �¼�ID��Χ����
*@{
*/

#include "kdvtype.h"

/**NVAPI ��UI�¼��������ʼֵ*/
#define EV_NVAPI_EVENT_BGN  1024

/**BaseSdk ����BaseSdk*/
enum EmNvApiEvSeg
{
/**BaseSdk ����BaseSdk*/
EVSEG_NVAPI_BASE_BGN          =  EV_NVAPI_EVENT_BGN,
EVSEG_NVAPI_BASE_END          = (EVSEG_NVAPI_BASE_BGN + 1000),

/**VideoConfSdk �������*/
EVSEG_NVAPI_VC_BGN,
EVSEG_NVAPI_VC_END            = (EVSEG_NVAPI_VC_BGN + 1000),


/**nvvncsdk ���湲��*/
EVSEG_NVAPI_VNC_BGN,
EVSEG_NVAPI_VNC_END           = (EVSEG_NVAPI_VNC_BGN + 1000),


/**nvmeetingmgrsdk �����ճ�*/
EVSEG_NVAPI_MG_BGN,
EVSEG_NVAPI_MG_END            = (EVSEG_NVAPI_MG_BGN + 1000),

/**nvimsdk ��ʱ����*/
EVSEG_NVAPI_IM_BGN,
EVSEG_NVAPI_IM_END            = (EVSEG_NVAPI_IM_BGN + 1000),

/**nvcontactmgrsdk ��ϵ�˹���*/
EVSEG_NVAPI_CM_BGN,
EVSEG_NVAPI_CM_END            = (EVSEG_NVAPI_CM_BGN + 1000),

/**nvdiagnosesdk ���*/
EVSEG_NVAPI_DIAGNOSE_BGN,
EVSEG_NVAPI_DIAGNOSE_END      = (EVSEG_NVAPI_DIAGNOSE_BGN + 1000),

/**quickshare sdk*/
EVSEG_NVAPI_QUICKSHARE_BGN,
EVSEG_NVAPI_QUICKSHARE_END      = (EVSEG_NVAPI_QUICKSHARE_BGN + 1000),
};

#define EV_UI_BGN(SEG) EV_##SEG##_BGN
#define EV_UI_END(SEG) EV_##SEG##_END

/**@}*/

/**@}*/
#endif //_NVAPI_EVENT_DEF_H_

