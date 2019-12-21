/*******************************************************************************//**
*@file          mtapi_export.h
*@brief         提供mtapi生成Dll时对外导出的接口统一宏
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EXPORT_H_
#define _MTAPI_EXPORT_H_
/**@addtogroup common 公用
*@{
*/

/**@addtogroup exports 导出宏以及调用约定宏
*@{
*/

#if defined(_USRDLL) || defined(_KDV_MTAPI_IMP_)
	//动态库
	#if defined(_KDV_MTAPI_EXP_)
	#define KdvMtAPI extern "C" __declspec(dllexport)
	#else
	#define KdvMtAPI extern "C" __declspec(dllimport)
	#endif
#else
	//静态库
	#define  KdvMtAPI extern "C"
#endif


#define KdvMtCALL 

/**@}*/

/**@}*/
#endif //_MTAPI_EXPORT_H_