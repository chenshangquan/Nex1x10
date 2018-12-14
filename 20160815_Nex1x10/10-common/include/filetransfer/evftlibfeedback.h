/*****************************************************************************
模块名      : filetransflib
文件名      : evfiletransfer.h
创建时间    : 2011年 09月 21日
实现功能    : 
作者        : 陈文灿
版本        : 
-----------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2011/09/21  1.0         陈文灿        创建
******************************************************************************/

#ifndef _EV_FTLIBFEEDBACK_H_
#define _EV_FTLIBFEEDBACK_H_

#include "osp.h"
#include "eventid.h"

// 文件发送结果通知	消息体：TTransFileState
OSPEVENT( FTLIB_SENDFILE_RESULT_NTF,			EV_FTLIBFEEDBACK_BGN );
// 文件发送进度通知
OSPEVENT( FTLIB_SENDFILE_PROGRESS_NTF,		    EV_FTLIBFEEDBACK_BGN + 1 );
// 文件接收请求		消息体：u32(发送者node) + u32(文件名长度) + u8*(文件名)
OSPEVENT( FTLIB_FILE_RECEIVE_REQ,				EV_FTLIBFEEDBACK_BGN + 2 );
// 同意接收文件
OSPEVENT( FTLIB_FILE_RECEIVE_ACK,				EV_FTLIBFEEDBACK_BGN + 3 );
// 拒绝文件接收
OSPEVENT( FTLIB_FILE_RECEIVE_NACK,			    EV_FTLIBFEEDBACK_BGN + 4 );
// 文件接收进度通知
OSPEVENT( FTLIB_FILE_RECEIVE_PROGRESS_NTF,	    EV_FTLIBFEEDBACK_BGN + 5 );
// 文件接收结果通知	消息体：TTransFileState
OSPEVENT( FTLIB_FILE_RECEIVE_RESULT_NTF,		EV_FTLIBFEEDBACK_BGN + 6 );






#endif
