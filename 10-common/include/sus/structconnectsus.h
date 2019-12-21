/*=======================================================================
ģ����      :SUS
�ļ���      :structconnectsus.h
����ļ�    :
�ļ�ʵ�ֹ���:ConnectSus�ṹ�嶨��

����        :
�汾        : V1.0  Copyright(C) 2005-2010 Suzhou Keda Technology Co.Ltd
              All rights reserved.
--------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2014/04/21  1.0                       ����
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

    em_SusCB_GetRecommendVerAck     = 1,  // ��ȡ�Ƽ��汾�ɹ����ص�����:CSusDevVerInfo
    em_SusCB_GetRecommendVerNack    = 2,  // ��ȡ�Ƽ��汾ʧ�ܣ��ص�����:������(u32)

    em_SusCB_LoadFileAck            = 3,  // ���ذ汾�ɹ����ص�����:����
    em_SusCB_LoadFileNack           = 4,  // ���ذ汾ʧ�ܣ��ص�����:������(u32)
    em_SusCB_LoadFileScheduleNtf    = 5,  // ���ؽ���֪ͨ���ص�����:CLoadFileSchedule

    em_SusCB_End
};

// ����������Ϣ�ط��Ļص�����ָ��
extern "C" typedef void (*SusMsgTransCallBackFunc)( SusCallBackType emType, const u8 *pMsgBody, u16 wMsgLen );
// ��������֪ͨ����SUS״̬�Ļص�����ָ��
extern "C" typedef void (*SusStateCallBackFunc)( BOOL32 bConnState/*, errid*/ ); // FALSE - δ���ӣ� TRUE - ����

// �ص�����ָ��ṹ
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

    void SetSusIp(u32 dwSusIp/*������*/) { m_dwSusIp = dwSusIp; }
	void SetSusPort(u32 dwSusPort) { m_dwSusPort = dwSusPort; }
    u32 GetSusIp() const { return m_dwSusIp; }
	u32 GetSusPort() const { return m_dwSusPort; }

    //�Ƿ�ͨ���������ӷ�����  TRUE:����ģʽ  FLASE:��ͨģʽ
    void SetConnectByProxy(BOOL32 bConnectByProxy) { m_bConnectByProxy = bConnectByProxy; }
    BOOL32 IsConnectByProxy() const { return m_bConnectByProxy; }

    //����Sock5Proxy, ����ģʽ�±������ã���ͨģʽ��������
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
    CSusNetParam m_tSusNetParm;     // ��½Sus�������
    SusCallBackFunc m_sCallBackFunc;   // �ص�������
    CSusLoginInfo m_tDevLoginInfo;   // �豸��¼��Ϣ
    s8  m_szInitLoadDir[MAXLEN_SUS_FILENAME + 1]; // ��¼�ϲ�Ӧ�ó�ʼ·��
};


#ifdef WIN32
#pragma pack( pop )
#endif


#endif // _STRUCT_CONNECT_SUS_H_
// END FILE






