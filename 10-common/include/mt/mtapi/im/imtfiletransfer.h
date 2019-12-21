/**===========================================================================
 * @file    $Id$
 * @brief   负责MtImAPi 文件传输相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTFILETRANSFER_H_
#define _I_MTFILETRANSFER_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_im.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtFileTransfer
 * @brief   负责MtImAPi 文件传输相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtFileTransfer : public IMtApiIF
{
public:
	//文件/文件夹传输请求
	virtual u32 ImSendFileReq( const u32 dwHandle, const TImFileShareReq_Api& tImFileShareReq_Api ) = 0;

	//接受/拒绝对端的文件/文件夹传输请求
	virtual u32 ImAcceptFileReq( const u32 dwHandle, const u32 dwSessionID, const BOOL32 bRecv, const BOOL32 bSetSavePath, const char * pachPath ) = 0;

	//中断文件/文件夹传输请求
	virtual u32 ImCancelFileReq( const u32 dwHandle, const u32 dwSessionID ) = 0;

	//设置文件保存路径请求
	virtual u32 ImSetFileSavePathReq( const u32 dwHandle, const char * pachPath ) = 0;

	//多人文件/文件夹传输请求
	virtual u32 ImSendGroupChatFileCmd( const u32 dwHandle, const TImGroupChatFileShareReq_Api& tImGroupChatFileShareReq_Api ) = 0;

	//ios系统请求设置临时目录Req(只用于IOS系统)
	virtual u32 ImIosSetTempPathCmd( const u32 dwHandle, const char * pachPath ) = 0;

	//设置文件传输带宽请求
	virtual u32 ImSetFileTransferBitRateReq( const u32 dwRate ) = 0;

private:

};

#endif // _I_MTFILETRANSFER_H_