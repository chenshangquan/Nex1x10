

/*****************************************************************************
   模块名      :
   文件名      : suserrcode.h
   相关文件    :
   文件实现功能: SUS错误码定义头文件
   作者        :
   版本        : V1.0  Copyright(C) 2006-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
   修改记录:
   日  期      版本        修改人      修改内容
   2013/03/01  1.0                     创建
******************************************************************************/


#ifndef _SUS_ERR_CODE_H_
#define _SUS_ERR_CODE_H_




/*------------------------------------------------------------------------------
  错误码
------------------------------------------------------------------------------*/

#define SUS_ERR_SUCC			                    (u32)(0)                            //成功
#define SUS_ERRORCODE_BGN_KDVP                      (u32)(20000)

//**************************************************************************************
//兼容2.5.2及以前版本的终端
//**************************************************************************************
#define SUS_ERR_DISK_ABNORMAL                       (SUS_ERRORCODE_BGN_KDVP + 1003)     //终端磁盘异常
#define SUS_ERR_MAX_SERVICE_SESSION                 (SUS_ERRORCODE_BGN_KDVP + 2000)     //服务器已达最大容量限制
#define SUS_ERR_TIMEOUT                             (SUS_ERRORCODE_BGN_KDVP + 2001)     //操作超时
#define SUS_ERR_NOT_PREPARED_NOW                    (SUS_ERRORCODE_BGN_KDVP + 2002)     //服务器尚未启动完毕
#define SUS_ERR_FILE_NOT_EXIST                      (SUS_ERRORCODE_BGN_KDVP + 2005)     //指定文件不存在
#define SUS_ERR_DEV_NOT_EXIST                       (SUS_ERRORCODE_BGN_KDVP + 2006)     //服务器中无此设备的版本
#define SUS_ERR_OEMREMARK_NOT_MATCH                 (SUS_ERRORCODE_BGN_KDVP + 3036)     //OEM标识不匹配
//***************************************************************************************

#define SUS_ERR_LOGIN_PARAM_INVAIL			        (SUS_ERRORCODE_BGN_KDVP + 2003)     //登陆参数错误
#define SUS_ERR_NOT_LOGIN_NOW       			    (SUS_ERRORCODE_BGN_KDVP + 2004)     //还未登陆，不能进行操作
#define SUS_ERR_UNZIP_FILE_FAIL       			    (SUS_ERRORCODE_BGN_KDVP + 2007)     //解压缩文件失败

#define SUS_ERR_SERVER_INSIDE_ERR			        (SUS_ERRORCODE_BGN_KDVP + 3001)     //服务器内部错误
#define SUS_ERR_DB_EXEC_FAIL				        (SUS_ERRORCODE_BGN_KDVP + 3002)     //数据库执行失败

#define SUS_ERR_CANNOT_DEL_RECOMMEND			    (SUS_ERRORCODE_BGN_KDVP + 4001)     //推荐版本不允许删除
#define SUS_ERR_MODIFY_INVAILD					    (SUS_ERRORCODE_BGN_KDVP + 4002)     //修改不合法
#define SUS_ERR_UPLOAD_VER_INVAILD				    (SUS_ERRORCODE_BGN_KDVP + 4003)     //上传的版本不合法
#define SUS_ERR_UPLOAD_VER_EXIST				    (SUS_ERRORCODE_BGN_KDVP + 4004)     //上传的版本已经存在
#define SUS_ERR_VER_TOO_MUCH			            (SUS_ERRORCODE_BGN_KDVP + 4005)     //此设备的版本数量超过最大限制
#define SUS_ERR_VERSION_FILE_INVAILD			    (SUS_ERRORCODE_BGN_KDVP + 4006)     //版本文件不合法（不存在或大型不匹配）
#define SUS_ERR_MOVEFILE_FAIL			            (SUS_ERRORCODE_BGN_KDVP + 4007)     //移动版本文件失败





#define SUS_ONE_TEXT(errcode,ChnStr)                        \
case errcode:                                               \
    return ChnStr;                                          \

static const s8* GetSusErrorStr(u32 wErrorID)
{   
    switch ( wErrorID )
    {
        SUS_ONE_TEXT( SUS_ERR_DISK_ABNORMAL, "终端磁盘异常!");
        SUS_ONE_TEXT( SUS_ERR_MAX_SERVICE_SESSION, "服务器已达最大容量限制，暂时无法提供服务，请稍候再试!");
        SUS_ONE_TEXT( SUS_ERR_TIMEOUT, "操作超时!");
        SUS_ONE_TEXT( SUS_ERR_NOT_PREPARED_NOW, "服务器尚未启动完毕!" );
        SUS_ONE_TEXT( SUS_ERR_FILE_NOT_EXIST, "指定文件不存在!" );
        SUS_ONE_TEXT( SUS_ERR_DEV_NOT_EXIST, "服务器中无此设备的版本，请稍后再试!" );
        SUS_ONE_TEXT( SUS_ERR_OEMREMARK_NOT_MATCH, "OEM标识不匹配!" );

        SUS_ONE_TEXT( SUS_ERR_LOGIN_PARAM_INVAIL, "登陆参数错误!" );
        SUS_ONE_TEXT( SUS_ERR_NOT_LOGIN_NOW, "还未登陆，不能进行操作!" ); 
        SUS_ONE_TEXT( SUS_ERR_UNZIP_FILE_FAIL, "解压缩文件失败!" ); 
    
        SUS_ONE_TEXT( SUS_ERR_SERVER_INSIDE_ERR, "服务器内部错误!" );
        SUS_ONE_TEXT( SUS_ERR_DB_EXEC_FAIL, "数据库执行失败!" ); 

        SUS_ONE_TEXT( SUS_ERR_CANNOT_DEL_RECOMMEND, "推荐版本不允许删除!" );
        SUS_ONE_TEXT( SUS_ERR_MODIFY_INVAILD, "修改不合法!" );
        SUS_ONE_TEXT( SUS_ERR_UPLOAD_VER_INVAILD, "上传的版本不合法!" );
        SUS_ONE_TEXT( SUS_ERR_UPLOAD_VER_EXIST, "上传的版本已经存在!" );
        SUS_ONE_TEXT( SUS_ERR_VER_TOO_MUCH, "此设备的版本数量超过最大限制!" );
        SUS_ONE_TEXT( SUS_ERR_VERSION_FILE_INVAILD, "版本文件不合法（不存在或大型不匹配）" );        
        SUS_ONE_TEXT( SUS_ERR_MOVEFILE_FAIL, "移动版本文件失败!" );        
    default:
        {
            return "未知错误";
        }
    }
}

#endif // _SUS_ERR_CODE_H_
// END FILE



