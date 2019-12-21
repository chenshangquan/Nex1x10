/*=======================================================================
模块名      :SUS
文件名      :structconnectsus.h
相关文件    :
文件实现功能:ConnectSus结构体定义

作者        :
版本        : V1.0  Copyright(C) 2005-2010 Suzhou Keda Technology Co.Ltd
              All rights reserved.
--------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
2014/04/21  1.0                       创建
=======================================================================*/


#ifndef _STRUCT_CONNECT_SUS_H_
#define _STRUCT_CONNECT_SUS_H_

#include "osp.h"
#include "structsusdev.h"



//...........................................
#ifdef WIN32
#pragma pack( push )
#pragma pack( 1 )
#ifndef PACKED
#define PACKED
#endif
#endif//.....................................

//...........................................
#ifdef _LINUX_
#ifndef PACKED
#define PACKED __attribute__ ((packed))
#endif
#endif//.....................................




enum SusCallBackType
{
    em_SusCB_Begin                  = 0,

    em_SusCB_GetRecommendVerAck     = 1,  // 获取推荐版本成功，回调内容:CSusDevVerInfo
    em_SusCB_GetRecommendVerNack    = 2,  // 获取推荐版本失败，回调内容:错误码(u32)

    em_SusCB_LoadFileAck            = 3,  // 下载版本成功，回调内容:暂无
    em_SusCB_LoadFileNack           = 4,  // 下载版本失败，回调内容:错误码(u32)
    em_SusCB_LoadFileScheduleNtf    = 5,  // 下载进度通知，回调内容:CLoadFileSchedule

    em_SusCB_End
};

// 定义用于消息回发的回调函数指针
extern "C" typedef void (*SusMsgTransCallBackFunc)( SusCallBackType emType, const u8 *pMsgBody, u16 wMsgLen );
// 定义用于通知连接SUS状态的回调函数指针
extern "C" typedef void (*SusStateCallBackFunc)( BOOL32 bConnState/*, errid*/ ); // FALSE - 未连接； TRUE - 连接

// 回调函数指针结构
struct SusCallBackFunc
{
    SusCallBackFunc()
    {
        Init();
    }

    SusCallBackFunc(SusMsgTransCallBackFunc pMsgCallBack, SusStateCallBackFunc pStateCallBack)
    {
        MsgTranFunc = pMsgCallBack;
        ConnectSusStateFunc = pStateCallBack;
    }

    void Init()
    {
        MsgTranFunc = NULL;
        ConnectSusStateFunc = NULL;
    }

    SusMsgTransCallBackFunc MsgTranFunc;
    SusStateCallBackFunc    ConnectSusStateFunc;
};

class CSusLoadFileSchedule
{
public:
    CSusLoadFileSchedule()
    {
        Init();
    }

    void Init()
    {
        m_dwCurSize = 0;
        m_dwTotalSize = 0;
    }

    u32 GetCurSize() const { return m_dwCurSize; }
    void SetCurSize(u32 dwCurSize) { m_dwCurSize = dwCurSize; }
    u32 GetTotalSize() const { return m_dwTotalSize; }
    void SetTotalSize(u32 dwTotalSize) { m_dwTotalSize = dwTotalSize; }

private:
    u32 m_dwCurSize;
    u32 m_dwTotalSize;
};


class CSusNetParam
{
public:
    CSusNetParam(void)
    {
        Init();
    }

    void Init()
    {
        SetSusIp(0);
		SetSusPort(0);
        SetConnectByProxy(FALSE);
        memset(&m_tOspSock5Proxy, 0, sizeof(m_tOspSock5Proxy));
    }

    void SetSusIp(u32 dwSusIp/*网络序*/) { m_dwSusIp = dwSusIp; }
	void SetSusPort(u32 dwSusPort) { m_dwSusPort = dwSusPort; }
    u32 GetSusIp() const { return m_dwSusIp; }
	u32 GetSusPort() const { return m_dwSusPort; }

    //是否通过代理连接服务器  TRUE:代理模式  FLASE:普通模式
    void SetConnectByProxy(BOOL32 bConnectByProxy) { m_bConnectByProxy = bConnectByProxy; }
    BOOL32 IsConnectByProxy() const { return m_bConnectByProxy; }

    //设置Sock5Proxy, 代理模式下必须设置，普通模式无须设置
    void SetOspSock5Proxy(const TOspSock5Proxy &tProxyInfo) { m_tOspSock5Proxy = tProxyInfo; }
    TOspSock5Proxy GetOspSock5Proxy() const { return m_tOspSock5Proxy; }

private:
    u32  m_dwSusIp;
	u32  m_dwSusPort;
    BOOL32 m_bConnectByProxy;
    TOspSock5Proxy m_tOspSock5Proxy;
};


class CSusInitParam
{
public:
    CSusInitParam()
    {
        Init();
    }

    void Init()
    {
        m_tSusNetParm.Init();
        m_sCallBackFunc.Init();
        m_tDevLoginInfo.Init();
        memset(m_szInitLoadDir, 0, sizeof(m_szInitLoadDir));
    }

    CSusNetParam GetSusNetParm() const { return m_tSusNetParm; }
    void SetSusNetParm(const CSusNetParam &tNetParam) { m_tSusNetParm = tNetParam; }

    SusCallBackFunc GetCallBackFunc() const { return m_sCallBackFunc; }
    void SetCallBackFunc(const SusCallBackFunc &tCallBackFunc) { m_sCallBackFunc = tCallBackFunc; }

    CSusLoginInfo GetDevLoginInfo() const { return m_tDevLoginInfo; }
    void SetDevLoginInfo(const CSusLoginInfo &tLoginInfo) { m_tDevLoginInfo = tLoginInfo; }

    const s8 *GetInitLoadDir() const { return m_szInitLoadDir; }
    void SetInitLoadDir(const s8 *szDir)
    {
        if (NULL == szDir)
        {
            memset(m_szInitLoadDir, 0, sizeof(m_szInitLoadDir));
            return;
        }

        strncpy(m_szInitLoadDir, szDir, sizeof(m_szInitLoadDir) - 1);
        m_szInitLoadDir[sizeof(m_szInitLoadDir) - 1] = '\0';

        return;
    }

private:
    CSusNetParam m_tSusNetParm;     // 登陆Sus网络参数
    SusCallBackFunc m_sCallBackFunc;   // 回调函数集
    CSusLoginInfo m_tDevLoginInfo;   // 设备登录信息
    s8  m_szInitLoadDir[MAXLEN_SUS_FILENAME + 1]; // 记录上层应用初始路径
};


#ifdef WIN32
#pragma pack( pop )
#endif


#endif // _STRUCT_CONNECT_SUS_H_
// END FILE






