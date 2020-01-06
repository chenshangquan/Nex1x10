/*****************************************************************************
模块名      : filetransflib
文件名      : ftlibconst.h
创建时间    : 2011年 10月 08日
实现功能    : 
作者        : 陈文灿
版本        : 
-----------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2011/10/08  1.0         陈文灿        创建
******************************************************************************/

#ifndef _EV_FTLIBCONST_H_
#define _EV_FTLIBCONST_H_

#include "osp.h"
#include "kdvdef.h"

/* APPID */

//文件发送APP ID
#define		AID_FTLIB_FILESEND			AID_FILETRANS_BGN
//文件接收管理APP ID
#define		AID_FTLIB_FILERCVMANAGR		AID_FILETRANS_BGN + 1
//文件接收APP ID 保留10个位置,文件接收线程最多为10个
#define		AID_FTLIB_FILERCV			AID_FILETRANS_BGN + 2



/* 常量定义 */


//最大并发文件发送个数
#define		FTLIB_MAXNUM_SENDFILE			100
//文件接收线程最大个数
#define		FTLIB_MAXNUM_RCVFILE			10
//文件接收线程默认个数
#define		FTLIB_DEFAULTNUM_RCVFILE		3
//文件名长度
#define		FTLIB_MAXLEN_FILENAEM			128
//文件存储路径长度(文件的全路径)
#define		FTLIB_MAXLEN_FILEPATH			256
//传输进度默认上报频率
#ifdef	_ANDROID_
#define     FTLIB_DEFAULTPERCENT_PROCESS    1
#else
#define     FTLIB_DEFAULTPERCENT_PROCESS    2
#endif
//传输进度上报时间限制
#define     FTLIB_UNIT_TIME                 10

//每包文件大小
#define		FTLIB_FILE_PACK_LENGTH		    (1024 * 10 )

//每次请求数据，服务器回复几包
#define		FTLIB_FILE_PACK_NUM		        10


//文件接收响应超时时间
#define		FTLIB_RCV_UPLOADFILE_TIMEOUT	(10 * 1000)
//默认文件接收路径
#ifdef	_LINUX_
#define		FTLIB_DEFAULT_DOWNLOAD_PATH	(LPCSTR)("/opt/mcu/download")
#endif
#ifdef	WIN32
#define		FTLIB_DEFAULT_DOWNLOAD_PATH	(LPCSTR)(".\\download")
#endif

//消息长度相关
#define      FTLIB_MSG_LEN					0x7000  //消息长度
#define      FTLIB_MSGHEAD_LEN              0x34   

// 打印级别
enum em_Ftlib_PrintLevel
{
    em_Ftlib_PrintNone = 0,
	em_Ftlib_PrintCommon,
	em_Ftlib_PrintDetail,
	em_Ftlib_Printend
};



#endif
