#ifndef _NVQUICKSHARE_H_
#define _NVQUICKSHARE_H_

#include "nvstruct.h"
#include "nvmacro.h"

#ifdef __cplusplus
extern "C" {
#endif

	/** ************************************************************
	* 
	* @brief    启动无线投屏入口函数
	*
	* @param	
	* @return	无
	* @note     启动无线投屏入口函数
	*
	************************************************************* */
	API void StartNvQuickShare( );



	/** ************************************************************
	* 
	* @brief    结束无线投屏入口函数
	*
	* @param	无
	* @return	无
	* @note     结束无线投屏入口函数
	*
	************************************************************* */
	API void stopquickshare();

#ifdef __cplusplus
}



#endif


#endif	// _NVQUICKSHARE_H_