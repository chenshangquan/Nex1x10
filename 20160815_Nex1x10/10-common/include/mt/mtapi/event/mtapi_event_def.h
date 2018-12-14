/*******************************************************************************//**
*@file          mtapi_event_def.h
*@brief         ʵ��MTAPI��UI(�۲���)���¼�֪ͨ�ķֶζ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_DEF_H_
#define _MTAPI_EVENT_DEF_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup defevent �¼�ID��Χ����
*@{
*/

#include "kdvtype.h"

/**MTAPI ��UI�¼��������ʼֵ*/
#define EV_MTAPI_EVENT_BGN  1024

/**BaseSdk ����BaseSdk*/
enum EmMtApiEvSeg
{
/**BaseSdk ����BaseSdk*/
EVSEG_MTAPI_BASE_BGN          =  EV_MTAPI_EVENT_BGN,
EVSEG_MTAPI_BASE_END          = (EVSEG_MTAPI_BASE_BGN + 1000),

/**VideoConfSdk �������*/
EVSEG_MTAPI_VC_BGN,
EVSEG_MTAPI_VC_END            = (EVSEG_MTAPI_VC_BGN + 1000),


/**mtvncsdk ���湲��*/
EVSEG_MTAPI_VNC_BGN,
EVSEG_MTAPI_VNC_END           = (EVSEG_MTAPI_VNC_BGN + 1000),


/**mtmeetingmgrsdk �����ճ�*/
EVSEG_MTAPI_MG_BGN,
EVSEG_MTAPI_MG_END            = (EVSEG_MTAPI_MG_BGN + 1000),

/**mtimsdk ��ʱ����*/
EVSEG_MTAPI_IM_BGN,
EVSEG_MTAPI_IM_END            = (EVSEG_MTAPI_IM_BGN + 1000),

/**mtcontactmgrsdk ��ϵ�˹���*/
EVSEG_MTAPI_CM_BGN,
EVSEG_MTAPI_CM_END            = (EVSEG_MTAPI_CM_BGN + 1000),

/**mtdiagnosesdk ���*/
EVSEG_MTAPI_DIAGNOSE_BGN,
EVSEG_MTAPI_DIAGNOSE_END      = (EVSEG_MTAPI_DIAGNOSE_BGN + 1000),
EVSEG_MTAPI_DCS_BGN,
EVSEG_MTAPI_DCS_END            = (EVSEG_MTAPI_DCS_BGN + 1000)
};

#define EV_UI_BGN(SEG) EV_##SEG##_BGN
#define EV_UI_END(SEG) EV_##SEG##_END

/**@}*/

/**@}*/
#endif //_MTAPI_EVENT_DEF_H_

