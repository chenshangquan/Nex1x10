#ifndef _MTDSCAPI_H_
#define _MTDSCAPI_H_
#include "mtdsc.h"

/*********************************************************/
/*******************扩展接口（data改变为protomsg）************/
/*********************************************************/
#include <google/protobuf/message.h>

/*!**********************************************************
*
* @brief   获取数据共享中的配置数据
* @param   [in]   emKey    配置数据类型
* @param   [out]  ptBufOut 返回的配置数据
*
* @return  DSE_OK:成功  DSE_ERROR:失败
*          
*************************************************************/
MTCBB_API u32 mtDscGetData(KEY emKey, google::protobuf::Message *ptBufOut);


/*!**********************************************************
*
* @brief   设置数据共享中的配置数据
* @param   [in]  emKey  配置数据类型
* @param   [in]  ptData 要存储的配置数据
*
* @return  DSE_OK:成功  DSE_ERROR:失败
*          
*************************************************************/
MTCBB_API u32 mtDscSetData(KEY emKey, google::protobuf::Message *ptData);

#endif // _MTDSCAPI_H_