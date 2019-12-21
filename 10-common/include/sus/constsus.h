
/*****************************************************************************
   模块名      : 
   文件名      : constsus.h
   相关文件    : 
   文件实现功能: SUS之间需要用到的一些常量
   作者        : 
   版本        : V1.0  Copyright(C) 2006-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
   修改记录:
   日  期      版本        修改人      修改内容
   2014/04/21  1.0				       创建
******************************************************************************/


#ifndef _CONST_SUS_COMMON_H_
#define _CONST_SUS_COMMON_H_

// sus侦听端口
#define SUSSRV_LISTEN_PORT              (u16)63000  
#define SUSMGR_LISTEN_PORT              (u16)63001  

#define MAXNUM_DB_CONNECT               (u32)6  //数据库连接数

//软件版本号文字最大长度
#define MAXLEN_SUS_SOFTVER			    (u32)(64)
#define MAXLEN_SUS_RELEASE_NOTES        (u32)(1024)
#define MAXLEN_SUS_FILENAME			    (u32)(256)
#define MAXLEN_SUS_E164LIST             (u32)(16*30)
#define MAXLEN_SUS_MOIDLIST             (u32)(40*30)

#define MAXLEN_SUS_IP_ADDR			    (u16)(32)
#define MAXLEN_SUS_DEV_NAME			    (u32)(64)
#define MAXLEN_SUS_E164NO			    (u32)(13)
#define MAXLEN_SUS_MODULE_NAME			(u32)(128)


#define MAXNUM_SUS_DEVVER				(u32)5
#define MAXNUM_SUS_DEVLOG				(u32)20
#define MAXNUM_SUS_MOID					(u16)50


#endif // _CONST_SUS_COMMON_H_
// END FILE



