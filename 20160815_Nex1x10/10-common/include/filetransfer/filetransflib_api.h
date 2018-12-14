/*****************************************************************************
ģ����      : filetransflib
�ļ���      : filetransflib_api.h
����ʱ��    : 2011�� 09�� 21��
ʵ�ֹ���    : 
����        : ���Ĳ�
�汾        : 
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/09/21  1.0         ���Ĳ�        ����
******************************************************************************/
#ifndef _FILETRANSFLIB_H_
#define _FILETRANSFLIB_H_

#include "osp.h"
#include "kdvtype.h"
#include "ftlibconst.h"

#pragma warning( disable : 4996 )

#ifdef FT_DLL_EXPORT
	#define FT_API   __declspec( dllexport )
#else
	#define FT_API
#endif	//WIN32




//��������

//Э��֧������
#define		FTLIB_PROTOCOL_TCP			0x0001
#define		FTLIB_PROTOCOL_UDP			0x0002


//�ļ����ͻص���Ϣ֪ͨ����
enum Ftlib_CallBackMsg
{
    em_FTLIB_SUCCESS = 0,
	em_FTLIB_FAILED,
    em_FTLIB_NOIDLEINST,
	em_FTLIB_FILENOTEXIST,
	em_FTLIB_REFUSE,
	em_FTLIB_TIMEOUT,
    em_FTLIB_DISK_ABNORMAL,   //�����쳣
};



/* ������ݽṹ���� */

//�ļ����չ�����Ϣ
struct TFileRcvMgrData
{
	u8	m_byThreadCount;					//�����̸߳���
	u32 m_dwMsgNtfAppId;					//��Ϣ֪ͨ��APP IID
	BOOL32 m_bSupportResume;				//�Ƿ�֧�ֶϵ�����
	s8	m_acDownloadPath[FTLIB_MAXLEN_FILEPATH];	//Ĭ���ļ�����·��

	TFileRcvMgrData()
	{
		clear();
	}
	
	void clear()
	{
		m_byThreadCount = 0;
		m_dwMsgNtfAppId = 0;
		m_bSupportResume = FALSE;	//Ĭ�ϲ�֧������
		memset( m_acDownloadPath, 0, sizeof(m_acDownloadPath) );
	}

    const s8* GetDownloadPath() const { return m_acDownloadPath; }
    void SetDownloadPath(const s8* szPath) 
    { 
        if (NULL == szPath)
        {
            memset( m_acDownloadPath, 0, sizeof(m_acDownloadPath) );
            return;
        }

        strncpy(m_acDownloadPath, szPath, sizeof(m_acDownloadPath)-1);
        m_acDownloadPath[sizeof(m_acDownloadPath)-1] = '\0';
        
        return;
    }

};



struct TTransFileState
{
	TTransFileState()
	{
		m_dwFileSize = 0;
		m_dwTransedSize = 0;
		m_dwNodeID = 0;
		m_emTransResult = em_FTLIB_SUCCESS;
		memset( m_achFileName, 0, sizeof(m_achFileName) );
	}

	~TTransFileState(){;}

private:
	u32		m_dwFileSize;			//��������ļ���С
	u32		m_dwTransedSize;		//�Ѿ�����Ĵ�С
	u32		m_dwNodeID;				//�Զ�NODE ID
	Ftlib_CallBackMsg m_emTransResult;		//���ͽ��
	s8		m_achFileName[FTLIB_MAXLEN_FILEPATH];	//�����ļ���( ȫ·�� )

public:
	void clear()
	{
		m_dwFileSize = 0;
		m_dwTransedSize = 0;
		m_dwNodeID = 0;
		m_emTransResult = em_FTLIB_SUCCESS;
		memset( m_achFileName, 0, sizeof(m_achFileName) );
	}

	void SetFileSize( u32 dwFileSize )
	{
		m_dwFileSize = dwFileSize;
	}
	u32 GetFileSize( void )
	{
		return m_dwFileSize;
	}

	void SetTransedSize( u32 dwTransedSize )
	{
		m_dwTransedSize = dwTransedSize;
	}
	u32 GetTransedSize( void )
	{
		return m_dwTransedSize;
	}

	void SetDstNode( u32 dwNode )
	{
		m_dwNodeID = dwNode;
	}
	u32 GetDstNode( void )
	{
		return m_dwNodeID;
	}

	void SetTransResult( Ftlib_CallBackMsg byResult )
	{
		m_emTransResult = byResult;
	}
	Ftlib_CallBackMsg GetTransResult( void )
	{
		return m_emTransResult;
	}

	void SetFileName( const s8* pchFileName, u16 wLen ) 
    { 
        if ( NULL == pchFileName )
        {
            memset( m_achFileName, 0, sizeof(m_achFileName) );
        }
        else
        {
			u16 wCopyLen = wLen > FTLIB_MAXLEN_FILEPATH ? FTLIB_MAXLEN_FILEPATH : wLen;
            strncpy( m_achFileName, pchFileName, wCopyLen );

        }

        return;
    }
	
    const s8* GetFileName(void) const
	{
		return m_achFileName;
	}

	u16 GetFileNameLen( void )
	{
		return strlen(m_achFileName);
	}
	
	void Print( void )
	{
		OspPrintf( TRUE, FALSE, "DstNode is %d\n", m_dwNodeID );
		OspPrintf( TRUE, FALSE, "File Name is %s\n", m_achFileName );
		OspPrintf( TRUE, FALSE, "File Size is %d, Transed Size is %d\n", m_dwFileSize, m_dwTransedSize );
		
		return ;
	}
};




typedef void (*MsgCallBackFunc)(u16 wEvent,u8 * pMsgBody,u16 wMsgLen );


FT_API BOOL32 FileSendAppInit( MsgCallBackFunc pfMsgCallBackFunc );

FT_API BOOL32 FileRcvAppInit( u8 byProtocol, TFileRcvMgrData* ptRcvMgrData );

FT_API u8 SendFileToDst( u32 dwDstNode, const s8* szFileName, const s8* szUniqueId = NULL);
FT_API u8 SendFileToDst( u32 dwDstNode, const s8* pacFileName, u8 byFileNameLen, const s8* pacUniqueId = NULL, u8 byUniqueIdLen = 0 );

FT_API void FileSendAppQuit( );

FT_API void FileRcvAppQuit( );




#endif //_FILETRANSFLIB_H_





