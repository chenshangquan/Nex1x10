/*******************************************************************************//**
*@file          nvapi_export.h
*@brief         提供nvapi生成Dll时对外导出的接口统一宏
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_EXPORT_H_
#define _NVAPI_EXPORT_H_
/**@addtogroup common 公用
*@{
*/

/**@addtogroup exports 导出宏以及调用约定宏
*@{
*/

#if defined(_USRDLL) || defined(_KDV_NVAPI_IMP_)
	//动态库
	#if defined(_KDV_NVAPI_EXP_)
	#define KdvNvAPI extern "C" __declspec(dllexport)
	#else
	#define KdvNvAPI extern "C" __declspec(dllimport)
	#endif
#else
	//静态库
	#define  KdvNvAPI extern "C"
#endif


#define KdvNvCALL 

/**@}*/

/**@}*/
#endif //_NVAPI_EXPORT_H_