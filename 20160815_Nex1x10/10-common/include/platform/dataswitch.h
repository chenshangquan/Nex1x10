/*****************************************************************************
   ģ����      : DataSwitch
   �ļ���      : dataswitch.h
   ����ļ�    :
   �ļ�ʵ�ֹ���: DataSwitchģ��ӿں�������
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2005/03/18  4.0         ��־ҵ        ����
   2005/08/10  4.0         ��־ҵ        ʵ��3.6�������Ĺ���
   2014/06/20  5.0         ������        ʵ��rtpswitch����
   2014/10/09  5.1         ������        �ϲ�����kdv��movision��dataswitch
******************************************************************************/

#ifndef DATASWITCH_H
#define DATASWITCH_H

#define DSVERSION       "DataSwitch.TS.5.1.20141009"

#include "osp.h"
#include "rtp_endpoint_id.h"     //rtp��ʶ�Ķ���ͽӿ�

/* DataSwitch ��� */
#define DSID    u32

#define DSID_LEN          16
#define DSID_MASK         0xffff0000
#define RTPID_MASK        0x0000ffff

#define DS_GET_DSID(rtpId) \
    ((((rtpId) & DSID_MASK) >> DSID_LEN) + 1)

#define DS_GET_DSRTPID(rtpId) \
    ((rtpId) & RTPID_MASK)

/*DataSwitch ����ֵ*/
#define DSOK    1
#define DSERROR 0

#define INVALID_DSID  0xffffffff   /*��Ч�ľ��ֵ*/

#if (defined _MSC_VER)
#include <Winsock2.h>
#include <ws2tcpip.h>
//TODO: inet_pton�Ĺ����Ƶ�OSP�����
#ifndef inet_pton
#define inet_pton
#endif
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#endif

typedef struct tagDsGlobalParam
{
	tagDsGlobalParam()
	{
		m_dwRecvBuff = 2 * 1024 * 1024 ;
		m_dwSendBuff = 2 * 1024 * 1024 ;
	}

	u32	m_dwRecvBuff;
	u32	m_dwSendBuff;
} TDsGlobalparam;

API void dsSetGlobalParam(TDsGlobalparam tParam );

/*----------- ��ʼ����udpswitch ----------------------*/

/**
 * @func FilterFunc
 * @brief ���չ��˺���
 *
 * ÿ�����ս����һ�����˺��������˽����յ�UDP���ݰ�ʱִ�д˺�����
 * �����ݺ����ķ���ֵ������̬�ؾ����Ƿ�Դ����ݰ�ת����
 *
 * @param dwRecvIP        - ����IP
 * @param wRecvPort      - ����Port
 * @param dwSrcIP         - ԴIP
 * @param SrcPort       - ԴPort
 * @param pData          - [in, out]���ݰ��������޸ģ�
 * @param uLen           - [in, out]���ݰ����ȣ��޸ĺ�ĳ��Ȳ��ɳ������ֵ
 * @return 0, �����ݰ���Ч�� ����ֵ�������ݰ���Ч��
 */
typedef u32 (*FilterFunc)(u32 dwRecvIP, u16 wRecvPort,
                          u32 dwSrcIP, u16 wSrcPort,
                          u8* pData, u32 uLen);

#define SENDMEM_MAX_MODLEN        (u8)32        // ����ʱ���������޸ĳ���

/**
 * ���ݰ�ת��Ŀ�꣺ָ�������IP, port��
 * DS�����ƵĶ��IP���������ݰ���ת��Ӧ�ò�����Ӱ�졣Ҳ����˵�����
 * ������IP�����Խ�һ�����ݰ���ȷ�ĵ�ת����ȥ����ʹ����һ��IP��û��
 * ��ϵ�ġ����ԣ�ת������ӿ�IP�ǲ���Ҫ�ġ�
 */
typedef struct tagNetSndMember
{
    u32     dwIP;       /* ת��Ŀ��IP��ַ   */
    u16     wPort;      /* ת��Ŀ�Ķ˿ں�   */
    s32     lIdx;       /* �ӿ����� */
    u32     errNum;     /* �������*/
    s32     errNo;      /* ����� */
    void    *lpuser;    /* user info */
    /* Ϊʵ�ַ���ʱ�޸����ݶ����ӵĲ��� */
    u16     wOffset;    /* �޸Ĳ��ֵ���ʼλ��; Ŀǰδʹ�� */
    u16     wLen;       /* �޸Ĳ��ֵĳ��ȣ�����Ϊ4�ı�����Ϊ���ʾ���޸� */
    char    pNewData[SENDMEM_MAX_MODLEN];
    /* Ҫ�޸ĵ����� */
    void    *pAppData;  /* �û��Զ���Ļص������Ĳ��� */
} TNetSndMember;

typedef void (*SendCallback)(u32 dwRecvIP, u16 wRecvPort,
                             u32 dwSrcIP,  u16 wSrcPort,
                             TNetSndMember *ptSends,            // ת��Ŀ���б�
                             u16* pwSendNum,                    // ת��Ŀ�����
                             u8* pUdpData, u32* dwUdpLen);

/**********************************************************
 * ����: DsRemoveRtpExtension                             *
 * ����: ȥ��rtp���е���չ��Ϣ���Լ����⳧���豸          *
 * ���: ��                                               *
 * ����: N/A                                              *
 **********************************************************/
API void DsRemoveRtpExtension(u32 dwRecvIP, u16 wRecvPort,
                             u32 dwSrcIP,  u16 wSrcPort,
                             TNetSndMember *ptSends,            // ת��Ŀ���б�
                             u16* pwSendNum,                    // ת��Ŀ�����
                             u8* RtpPkt, u32* dwRtpLen);

API void dsSetApiTimeOut(s32 timeout);
/**********************************************************
 * ����: dsSetCapacity                                    *
 * ����: ��������(ֻ���ڴ�������ģ��֮ǰ����)             *
 * ����: dwMaxRcvGrp        - ����������                *
 *       dwMaxSndMmbPerRcvGrp  - ÿһ�����������Ŀ����   *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/
API u32 dsSetCapacity( u32 dwMaxRcvGrp, u32 dwMaxSndMmbPerRcvGrp );

/************************************************************
 * ��������dsCreate
 *
 * ���ܣ�  ����DataSwitchģ��
 *
 * ʵ��˵����
 * Dataswitch֧�֡����û�����ÿ�ε���dsCreate�ͻ᷵��һ��
 * �û���ʶ����ӡ�ɾ��ʱ��Ҫƥ���û���־��ת��ʱ�򲻿��ǡ�
 *
 * ����ֵ��
 * @return INVALID_DSID: ��ʾʧ�� ; ����ɹ�
 ************************************************************/
API DSID dsCreate( u32, u32 * );

/************************************************************
 * ��������dsDestroy
 *
 * ���ܣ� ��ֹDataSwitch������
 *
 * ʵ��˵����
 * һ��ɾ��һ���û���ֱ�������û���ɾ����������Դ��ȫ�ͷš�
 *
 * ����˵����
 * @param dsId  - �û���ʶ
 *
 * ����ֵ��
 ************************************************************/
API void dsDestroy( DSID dsId );

/************************************************************
 * �������� dsAdd
 *
 * ���ܣ� ����ת��Ŀ��Ψһ��ת������
 *
 * ʵ��˵����
 * ��ĿǰΨһ���ĺ����ǣ�����Ѿ����ڵĽ���������ת��Ŀ��
 * �뵱ǰ�������ͬ������ɾ����Щ����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwRecvIP      - ����IP�����������ݰ���Ŀ��IP
 * @param wRecvPort     - ����Port�����������ݰ���Ŀ��Port
 * @param dwInLocalIP   - �������ݰ�������ӿ�
 * @param dwSendtoIP    - ת��Ŀ��IP
 * @param wSendtoPort   - ת��Ŀ��Port
 * @param dwOutLocalIP  - ת�����ݰ����ñ���IP
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsAdd(DSID dsId,
              u32  dwRecvIP ,
              u16  wRecvPort,
              u32  dwInLocalIP,
              u32  dwSendtoIP,
              u16  wSendtoPort,
              u32  dwOutLocalIP = 0);

/************************************************************
 * ��������dsRemove
 *
 * ���ܣ� ɾ��ת��Ŀ��Ϊָ����ַ��ת������
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwSendtoIP    - ת��Ŀ��IP
 * @param wSendtoPort   - ת��Ŀ��Port
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsRemove(DSID dsId,
                 u32  dwSendtoIP,
                 u16  wSendtoPort);

/************************************************************
 * ��������dsAddDump
 *
 * ���ܣ� ����Dump����
 * DUMP���򣺴�ָ����ַ���յ����ݰ�����ת����
 * ���һ�����յ�ַֻ��DUMP��������յ����ݰ�����ת����
 * �����������ת������������������ת����
 *
 * ʵ��˵����
 * DUMP��������������Σ���Ϊ�������������ǿ��Բ���ģ�
 * ����������
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwRecvIP      - ����IP�����������ݰ���Ŀ��IP
 * @param wRecvPort     - ����Port�����������ݰ���Ŀ��Port
 * @param dwInLocalIP   - �������ݰ�������ӿ�
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsAddDump(DSID dsId, u32 dwRecvIP, u16 wRecvPort, u32 dwInLocalIP);

/************************************************************
 * ��������dsRemoveDump
 *
 * ���ܣ� ɾ��Dump����
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwRecvIP      - ����IP�����������ݰ���Ŀ��IP
 * @param wRecvPort     - ����Port�����������ݰ���Ŀ��Port
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsRemoveDump(DSID dsId, u32 dwRecvIP, u16 wRecvPort);

/************************************************************
 * ��������dsAddManyToOne
 *
 * ���ܣ� ���Ӷ��һ��ת������
 * ע�⣬����dsAdd�����������෴�����߻��ʹ��ʱҪС�ġ�
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwRecvIP      - ����IP�����������ݰ���Ŀ��IP
 * @param wRecvPort     - ����Port�����������ݰ���Ŀ��Port
 * @param dwInLocalIP   - �������ݰ�������ӿ�
 * @param dwSendtoIP    - ת��Ŀ��IP
 * @param wSendtoPort   - ת��Ŀ��Port
 * @param dwOutLocalIP  - ת�����ݰ����ñ���IP
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsAddManyToOne(DSID dsId ,
                       u32  dwRecvIP,
                       u16  wRecvPort,
                       u32  dwInLocalIP,
                       u32  dwSendtoIP,
                       u16  wSendtoPort,
                       u32  dwOutLocalIP = 0);

/************************************************************
 * ��������dsRemoveAllManyToOne
 *
 * ���ܣ� ɾ������ת��Ŀ��Ϊָ����ַ�Ķ��һ����
 *
 * ע�⣺����������dsRemove��ȫ��ͬ�����Դӽӿڲ�����֤����
 * �ṩ����ӿ���Ϊ�˲������಻ͬ����Ľӿڻ��ʹ�á�һ��
 * �����У�Ӧ��ʼ��ʹ��ĳһ��ӿڡ�
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwSendtoIP    - ת��Ŀ��IP
 * @param wSendtoPort   - ת��Ŀ��Port
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsRemoveAllManyToOne(DSID dsId ,
                             u32  dwSendtoIP,
                             u16  wSendtoPort);

/************************************************************
 * ��������dsRemoveManyToOne
 *
 * ���ܣ� ɾ��ָ���Ķ��һ����
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwRecvIP      - ����IP�����������ݰ���Ŀ��IP
 * @param wRecvPort     - ����Port�����������ݰ���Ŀ��Port
 * @param dwInLocalIP   - �������ݰ�������ӿ�
 * @param dwSendtoIP    - ת��Ŀ��IP
 * @param wSendtoPort   - ת��Ŀ��Port
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsRemoveManyToOne(DSID dsId ,
                          u32  dwRecvIP,
                          u16  wRecvPort,
                          u32  dwSendtoIP,
                          u16  wSendtoPort );

/************************************************************
 * ��������dsAddSrcSwitch
 *
 * ���ܣ� ���Ӱ�Դת���Ĺ���
 *
 * ��Դת����ʹ�ô˹���ʱ���������ݰ���Դ��ַ����������е�Դ
 * ��ַ��ȡ�ÿ��ת��ʱ����Ҫ�ȸ������ݰ��е�Դ��ַ����ת����
 * ������Ҳ�������ʹ��Ĭ��Դ��ַ����0@0����ת������
 * ע�⣺�ýӿ�֧�ֶ�㵽һ�㡣���dwSrcIP��wSrcPort��Ϊ�㣬
 * ������ȫ��ͬ��dsAddManyToOne��
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwRecvIP      - ����IP�����������ݰ���Ŀ��IP
 * @param wRecvPort     - ����Port�����������ݰ���Ŀ��Port
 * @param dwInLocalIP   - �������ݰ�������ӿ�
 * @param dwSrcIP       - �������ݰ���ԴIP
 * @param wSrcPort      - �������ݰ���ԴPort
 * @param dwSendtoIP    - ת��Ŀ��IP
 * @param wSendtoPort   - ת��Ŀ��Port
 * @param dwOutLocalIP  - ת�����ݰ����ñ���IP
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsAddSrcSwitch(DSID dsId ,
                       u32  dwRecvIP,
                       u16  wRecvPort,
                       u32  dwInLocalIP,
                       u32  dwSrcIP ,
                       u16  wSrcPort,
                       u32  dwSendtoIP,
                       u16  wSendtoPort,
                       u32  dwOutLocalIP = 0);

/************************************************************
 * ��������dsRemoveAllSrcSwitch
 *
 * ���ܣ� ɾ������ָ���İ�Դת������
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwRecvIP      - ����IP�����������ݰ���Ŀ��IP
 * @param wRecvPort     - ����Port�����������ݰ���Ŀ��Port
 * @param dwSrcIP       - �������ݰ���ԴIP
 * @param wSrcPort      - �������ݰ���ԴPort
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsRemoveAllSrcSwitch(DSID dsId,
                             u32  dwRecvIP,
                             u16  wRecvPort,
                             u32  dwSrcIP,
                             u16  wSrcPort);

/************************************************************
 * ��������dsRemoveSrcSwitch
 *
 * ���ܣ� ɾ��ָ���İ�Դת���Ĺ���
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwRecvIP      - ����IP�����������ݰ���Ŀ��IP
 * @param wRecvPort     - ����Port�����������ݰ���Ŀ��Port
 * @param dwSrcIP       - �������ݰ���ԴIP
 * @param wSrcPort      - �������ݰ���ԴPort
 * @param dwSendtoIP    - ת��Ŀ��IP
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsRemoveSrcSwitch(DSID dsId,
                          u32  dwRecvIP,
                          u16  wRecvPort,
                          u32  dwSrcIP,
                          u16  wSrcPort,
                          u32  dwSendtoIP,
                          u16  wSendtoPort);

API u32 dsSetUserData(DSID dsId,
                      u32  dwLocalIP,
                      u16  wLocalPort,
                      u32  dwLoalIfIP,
                      u32  dwSrcIP ,
                      u16  wSrcPort,
                      u32  dwDstIP,
                      u16  wDstPort,
                      u32  dwDstOutIfIP,
                      BOOL32 bSend,
                      u8* pbyUserData,
                      s32 nUserLen);

/************************************************************
 * ��������dsSetFilterFunc
 *
 * ���ܣ� ���ù��˺���
 *
 * ע�⣺����ָ�����Ϊ�գ���ʾ���ԭ�е����ã����⣬����
 * DataSwitch����������߳��е��ô˺����ģ�Ҫ���õĺ�����
 * ����ȫ�ֺ��������õĲ�����Ҳ������ȫ����Ч�ġ�
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param dwRecvIP      - ����IP�����������ݰ���Ŀ��IP
 * @param wRecvPort     - ����Port�����������ݰ���Ŀ��Port
 * @param ptFunc        - ���˺���ָ��
 * @param FuncParam     - Ϊ���˺������ݵĲ���
 *
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsSetFilterFunc(DSID dsId,
                        u32 dwRecvIP,
                        u16 wRecvPort,
                        FilterFunc ptFunc);

/************************************************************
 * ��������dsRemoveAll
 *
 * ���ܣ� ɾ�����е�ת������
 *
 * ʵ��˵����
 *
 * ����˵����
 * @param dsId          - �û���ʶ
 * @param bKeepDump     - �Ƿ������е�dump����Ĭ�ϲ�������VX�汾��δʵ�֣�
 * ����ֵ��
 * @return DSOK: ��ʾ�ɹ� ; DSERROR: ��ʾʧ�� ;
 ************************************************************/
API u32 dsRemoveAll( DSID dsId, BOOL32 bKeepDump = FALSE );

enum {
    DS_SKIP_POLICY_ROUTING = 0x1 << 0,  //��ֹ���ں˲���·�ɶ���
};

 /**********************************************************
 * ����: dsSetSpecifyFwdSrc                                *
 * ����: Ϊָ��Ŀ�ĵ�ַ����ת�����ݰ�������Դ��ַ        *
 * ����:
 * @param dsId          - DSID
 * @param dwLocalIP     - ����IP
 * @param wLocalPort    - ����Port
 * @param dwDstIP		- Ŀ��IP
 * @param wDstPort		- Ŀ�Ķ˿�
 * @param dwMappedIP    - ӳ��IP
 * @param wMappedPort   - ӳ��Port
 * @param dwSrcIP		- ԴIP
 * @param wSrcPort		- Դ�˿�
 * @dwflags: αװ�����flags�� �������ƹ�����·�ɵ�
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 * ˵��: �����Ҫȡ��Դ��ַ���ã���dwMappedIp��wMappedPort*
 *       ����Ϊ0                                          *
 **********************************************************/
API u32	dsSetSpecifyFwdSrc(DSID dsId,
                           u32 dwLocalIP, u16 wLocalPort,
						   u32 dwDstIP, u16 wDstPort ,
						   u32 dwMappedIP, u16 wMappedPort,
						   u32 dwSrcIP = 0, u16 wSrcPort = 0,
						   u32 dwflags = 0);

 /**********************************************************
 * ����: dsSetSendCallback                                *
 * ����: ���÷��ͻص�����                                 *
 *       ȡ��ʱ�����ú���ָ��ΪNULL����
 * ����: dsID           - ��������ģ��ʱ�ľ��            *
 *       dwLocalIp      - ���ؽ���IP                      *
 *       wLocalPort     - ���ؽ��ն˿ں�                  *
 *       dwSrcIP        - ת��Ŀ��IP��ַ                  *
 *       wSrcPort       - ת��Ŀ�Ķ˿ں�                  *
 *       pfCallback     - �ص�����
 * ���: ��                                               *
 * ����: ��                                               *
 **********************************************************/
API u32 dsSetSendCallback(DSID dsId,
                          u32 dwRecvIP,
                          u16 wRecvPort,
                          u32 dwSrcIP,
                          u16 wSrcPort,
                          SendCallback pfCallback);

 /*********************************************************
 * ����: dsSetAppDataForSend                              *
 * ����: Ϊ����Ŀ������һ���Զ����ָ��                   *
 *       ȡ��ʱ�����ú���ָ��ΪNULL����                   *
 * ����: dsID           - ��������ģ��ʱ�ľ��            *
 *       dwLocalIp      - ���ؽ���IP                      *
 *       wLocalPort     - ���ؽ��ն˿ں�                  *
 *       dwSrcIP        - ԴIP��ַ                        *
 *       wSrcPort       - Դ�˿ں�                        *
 *       dwDstIP        - ת��Ŀ��IP��ַ                  *
 *       wDstPort       - ת��Ŀ�Ķ˿ں�                  *
 *       pAppData       - �Զ���ָ��                      *
 * ���: ��                                               *
 * ����:
 *     DSOK:�ɹ� DSERROR:ʧ��                             *
 **********************************************************/
API u32 dsSetAppDataForSend(DSID dsId,
                u32 dwRecvIP,
                u16 wRecvPort,
                u32 dwSrcIP,
                u16 wSrcPort,
                u32 dwDstIP,
                u16 wDstPort,
                void *pAppData);

/*----------- ��������udpswitch ----------------------*/

/* �����ַ���壬Ӧ�÷ŵ�osp.h�У���ʱ�������� */
typedef union {
    struct sockaddr_in		v4addr;     //ipv4��ַ
    struct sockaddr_in6		v6addr;     //ipv6��ַ
    struct sockaddr_storage staddr;     //socket��ʾ�ĵ�ַ
    //socket�޷���ʾ��˽�е�ַ����
    u8  raw_addr[sizeof(struct sockaddr_storage)];
} dsNetAddr;

#define DS_IS_VALID_ADDR(netaddr)   \
    ((netaddr) &&   \
    (((netaddr)->v4addr.sin_family == AF_INET && (netaddr)->v4addr.sin_port) || \
    ((netaddr)->v6addr.sin6_family == AF_INET6 && (netaddr)->v6addr.sin6_port)))

#define DS_IS_VALID_LOCAL_ADDR(netaddr)   \
    ((netaddr) &&   \
    (((netaddr)->v4addr.sin_family == AF_INET && (netaddr)->v4addr.sin_port) || \
    ((netaddr)->v6addr.sin6_family == AF_INET6 && (netaddr)->v6addr.sin6_port)))

#define DS_IS_VALID_REMOTE_ADDR(netaddr)    \
    ((netaddr) &&   \
    (((netaddr)->v4addr.sin_family == AF_INET &&    \
        (netaddr)->v4addr.sin_addr.s_addr && (netaddr)->v4addr.sin_port) || \
    ((netaddr)->v6addr.sin6_family == AF_INET6 &&   \
        (netaddr)->v6addr.sin6_port)))

/* �ṩ�����ֽ����ַ���õ�dsNetAddr�ṹ�� */
#define DS_SET_NETADDR_ADDR(netaddr, type, address)    \
    do {    \
        switch(type) {    \
        case AF_INET:   \
            (netaddr)->v4addr.sin_family = (type);      \
            (netaddr)->v4addr.sin_addr.s_addr = (address);   \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)

/* �ṩ�����ַ�ַ������õ�dsNetAddr�ṹ�� */
#define DS_SET_NETADDR_ADDR_STR(netaddr, type, address)    \
    do {    \
        switch(type) {      \
        case AF_INET:       \
            (netaddr)->v4addr.sin_family = (type);      \
            if (address)    \
                OspPton(type, address, &((netaddr)->v4addr.sin_addr.s_addr));\
            else        \
                (netaddr)->v4addr.sin_addr.s_addr = INADDR_ANY;    \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            if (address)    \
                OspPton(type, address, &((netaddr)->v6addr.sin6_addr.s6_addr));  \
            else    \
                memcpy(&(netaddr)->v6addr.sin6_addr, &in6addr_any, sizeof(in6addr_any));  \
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)

/* �ṩ������˿ں����õ�dsNetAddr �� */
#define DS_SET_NETADDR_PORT(netaddr, type, port)    \
    do {    \
        switch(type) {    \
        case AF_INET:   \
            (netaddr)->v4addr.sin_family = (type);      \
            (netaddr)->v4addr.sin_port = htons(port);   \
            break;      \
        case AF_INET6:  \
            (netaddr)->v6addr.sin6_family = (type);     \
            (netaddr)->v6addr.sin6_port = htons(port);  \
            break;  \
        default:    \
            break;  \
        }   \
    } while(0)

/* -------------------- ��ʼ����rtpswitch -------------------*/
#define INVALID_RTPSWITCHID ((u32)-1)

//Ϊ�˶�ʵ���� DSRTPSID�����Ϊ 
/*
 *  31---------------------15-----------------------0
 *  |    DSID               | RTPID                 |
 *  -------------------------------------------------
 */
typedef u32		DSRTPSID;

#define DS_MAX_SECKEY_LEN (512)

//��Կ����
#define DS_SECKEY_LEN_AES_256_GCM (44)
#define DS_SECKEY_LEN_AES_128_GCM (28)
#define DS_SECKEY_LEN_AES_256_ICM (46)
#define DS_SECKEY_LEN_AES_128_ICM (30)
#define DS_SECKEY_LEN_SM4_128_CM  (30)

#define DS_SECKEY_LEN_AES_256_H235 (32)
#define DS_SECKEY_LEN_AES_192_H235 (28)
#define DS_SECKEY_LEN_AES_128_H235 (24)

typedef enum {
	DS_SECKEY_TYPE_UNDEFINED	= 0,
    DS_SECKEY_TYPE_STATIC		= 1, 
	DS_SECKEY_TYPE_QUANTUM		= 2, 
	DS_SECKEY_TYPE_DTLS			= 3,	
} dsSecKeyTypes;

typedef struct {
  u8        keytype;  
  u16		keylen;
  u8		key[DS_MAX_SECKEY_LEN];  
} dsSecKey; 

#define DS_CIPHER_ENABLE      ((u8)1)
#define DS_CIPHER_DISABLE     ((u8)0)

#define DS_CIPHERPOLICY_NONE  ((u8)0)
#define DS_CIPHERPOLICY_H235  ((u8)1)
#define DS_CIPHERPOLICY_SRTP  ((u8)2)

//�㷨����
typedef enum {
	DS_SEC_ALG_NONE		= 0,
	DS_SEC_ALG_AES_128	= 1,
	DS_SEC_ALG_AES_192	= 2,
	DS_SEC_ALG_AES_256	= 3,
	DS_SEC_ALG_SM_4     = 4,
}ds_Cipher_Alg_Id;

typedef enum {
	DS_AUTH_ALG_NONE		= 0,
	DS_AUTH_ALG_SHA1		= 1,	
}ds_Auth_Alg_Id;


//ģʽ
typedef enum {
    SRTP_AES_ICM	= 1, 
	SRTP_AES_GCM	= 2,
	
	H235_AES_CBC	= 3,
	H235_AES_ECB	= 4,
	H235_AES_CFB1	= 5,

	SRTP_SM4_CM     = 6,

	SRTP_UNDEFINED  = 0,
} dsSrtpCryptoTypes;


typedef struct {
  u8        enable;//�Ƿ����üӽ��� 1������ 0��������
  u8		policy;//ģʽ 0: none 1��H235 2: srtp 
  u8		isCipher;//�Ƿ�ӽ��� 1: �ӽ��� 0: ���ӽ���  
  u32		cipher_alg_id;//�㷨id   
  u8        cipher_mod;//���ܹ���ģʽ 
  //u8        ext_cipher;//�Ƿ������չͷ
  dsSecKey  seckey;//��Կ
  u8		isAuth;//�Ƿ���֤
  u32		auth_alg_id;//�㷨id
  u8        auth_tag_len;//auth tag ����
  dsSecKey  authKey;//��֤��Կ 
} dsCipher;

typedef enum {
    DS_RTP_FLAG_SSRC_FIXED = 0x00000001, //�̶�SSRC
	DS_RTP_FLAG_DUMP_RULE  = 0x00000002, //dump����
	DS_RTP_FLAG_DISABLE_FEC = 0x00000004, //��ֹFECת��,ֻ��Ŀ������
	DS_RTP_FLAG_UNDEFINED  = 0x00000000, 
} dsRtpModFlag;

#define DS_EP_ATTR_MAX_SIZE (2048)

//�ն�����
typedef union {
	u8 attr_data[DS_EP_ATTR_MAX_SIZE];
	void* align;
}dsEpAttr_t;

/* rtp�ն˵���Ϣ */
typedef struct {
    dsRtpEndpointId id;     //rtp �ն�id
    dsNetAddr addr;         //rtp �ն˵������ַ
    s32 ifindex;            //rtp �ն˵���������

	dsEpAttr_t attr;        //�ն�����,���Զ��
} dsRtpEndpoint;

#define DS_INIT_RTP_ENDPOINT(endpoint)  \
    do {    \
        (endpoint)->id = DS_RTP_ANY_ID; \
        (endpoint)->ifindex = -1;   \
        memset(&(endpoint)->addr, 0, sizeof((endpoint)->addr));  \
		memset(&(endpoint)->attr, 0, sizeof((endpoint)->attr));  \
    } while(0)

//�����ն˻ص���ʶ
API u32 dsAddEpAttr_ModFlag( dsRtpEndpoint * ep, dsRtpModFlag modflag );

//�����ն˼�������
API u32 dsAddEpAttr_Cipher( dsRtpEndpoint * ep, const dsCipher * const cipher );


/****************************************************************
 * ����: dsCreateRtpRtcpSwitch()
 * ����: ��ĳ��ip��ַ�Ͷ˿ڴ���rtpswitch
 * ����:
 *   dsid: dataswitch ʵ��id
 *   addr: Ҫ����rtpswitch�ĵ�ַ�Ͷ˿���Ϣ
 * ���:
 *   ����ֵdsrtpswitch id��������INVALID_RTPSWITCHID
 ****************************************************************/
API DSRTPSID dsCreateRtpRtcpSwitch(DSID dsid, dsNetAddr *addr);

/****************************************************************
 * ����: dsAddRtpSwitchRule() / dsAddRtcpSwitchRule()
 * ����: ��ĳ��rtpswitch�����rtp��������
 * ����:
 *   id: rtpswitch��id����ʶ�������յ�ip��ַ�Ͷ˿�
 *   src: ������Դ��Ϣ������ԭip��ַ�Ͷ˿ڣ�ԭendpoint id��Ϣ��
 *        ���������ip��ַ�Ͷ˿ڣ��򲻳���ƥ���ַ�Ͷ˿�
 *        ���������endpoint id��Ϣ����ƥ��endpoint id��Ϣ
 *        ���src == NULL, �յ������а���ƥ���������.
 *   modifier: ��������ת�����޸ĵ�Դ��Ϣ, ��� == NULL, ���޸�
 *   dst: ����ת������Ŀ����Ϣ������Ŀ��ip�Ͷ˿ڣ�Ŀ��endpoint��
 *   priority: ��������ȼ�(1~100), Խ�����ȼ�Խ�ߡ�
 * ���:
 *   ����ֵDSOK��DSERROR.
 ****************************************************************/
API u32 dsAddRtpSwitchRule(
    DSRTPSID id,
    dsRtpEndpoint *src,
    dsRtpEndpoint *modifier,
    dsRtpEndpoint *dst,
    u32 priority);

API u32 dsAddRtcpSwitchRule(
    DSRTPSID id,
    dsRtpEndpoint *src,
    dsRtpEndpoint *modifier,
    dsRtpEndpoint *dst,
    u32 priority);
/****************************************************************
 * ����: dsRemoveRtpSwitchRule() / dsRemoveRtcpSwitchRule()
 * ����: ��ĳ��rtpswitch��ɾ��rtp��������
 * ����:
 *   id: �������ڵ�rtpswitch��id.
 *   src: ������Դ��Ϣ������ԭip��ַ�Ͷ˿ڣ�ԭendpoint id��Ϣ��
 *        ���src == NULL, ƥ������Դ
 *   modifier: ��������ת�����޸ĵ�Դ��Ϣ, ��� == NULL, ���޸�
 *   dst: ����ת������Ŀ����Ϣ������Ŀ��ip�Ͷ˿ڣ�Ŀ��endpoint��
 * ���:
 *   ����ֵDSOK��DSERROR.
 ****************************************************************/
API u32 dsRemoveRtpSwitchRule(
    DSRTPSID id,
    dsRtpEndpoint *src,
    dsRtpEndpoint *modifier,
    dsRtpEndpoint *dst);

API u32 dsRemoveRtcpSwitchRule(
    DSRTPSID id,
    dsRtpEndpoint *src,
    dsRtpEndpoint *modifier,
    dsRtpEndpoint *dst);
/****************************************************************
 * ����: dsDestroyRtpSwitch()
 * ����: ���һ��rtpswitch
 * ����:
 *   dsid: dataswitch ʵ��id
 *   id:   rtp switch id
 * ���:
 *   ����ֵDSOK��DSERROR.
 ****************************************************************/
 API u32 dsDestroyRtpSwitch(DSID dsid, DSRTPSID id);

/*---------------- ����rtpswitch ���� -------------------------*/

/*---------------- ����sipswitch ��ʼ -------------------------*/
#define INVALID_SIPSWITCHID ((u32)-1)

 //Ϊ�˶�ʵ���� DSSIPSID�����Ϊ 
/*
 *  31---------------------15-----------------------0
 *  |    DSID               | SIPID                 |
 *  -------------------------------------------------
 */
 typedef u32		DSSIPSID;

#define DS_SIP_INVALID_ID   ((u8*)0x0)

enum
{
    /* for src match */
    DS_SRC_SIP_ANY_ID = 0x0,    //ת��ʱԴ��ƥ���κ���Ϣ
    DS_SRC_SIP_MATCH_ID = 0x1,  //ת��ʱԴ����ƥ��e164��callid

    /* for modifier action */
    DS_MOD_SIP_UNTOUCH_ID = 0x0, //ת��ʱ���޸İ��е�e164��callid��Ϣ
    DS_MOD_SIP_CHANGE_ID = 0x1,  //ת��ʱ�޸İ��е�e164��callid��Ϣ
    DS_MOD_SIP_REMOVE_ID = 0x2,  //ת��ʱȥ�����е�e164��callid��Ϣ

    /* for forward to destination */
    DS_DST_SIP_TO_IP = 0x0,     //ת����ָ����ip��ַ�Ͷ˿�
    DS_DST_SIP_TO_ID = 0x1,     //ת����ָ����e164�ź�callid�ն�
};

#define DS_MAX_E164_LEN     64
#define DS_MAX_CALLID_LEN   64

/* sip�ն˵���Ϣ */
typedef struct {
    u8 e164[DS_MAX_E164_LEN];
    u8 callId[DS_MAX_CALLID_LEN];
    u16 action;     //��ʶe164��callid�е���Ϣ���ʹ��
    s16 ifindex;            //sip �ն˵���������
    dsNetAddr addr;         //sip �ն˵������ַ
} dsSipEndpoint;

#define DS_INIT_SIP_ENDPOINT(endpoint)  \
    do {    \
        (endpoint)->action = 0x0; \
        (endpoint)->ifindex = -1;   \
        memset(&((endpoint)->e164[0]), 0, sizeof((endpoint)->e164)); \
        memset(&((endpoint)->callId[0]), 0, sizeof((endpoint)->callId)); \
        memset(&(endpoint)->addr, 0, sizeof((endpoint)->addr));  \
    } while(0)

/****************************************************************
 * ����: dsCreateSipSwitch()
 * ����: ��ĳ��ip��ַ�Ͷ˿ڴ���sipswitch
 * ����:
 *   dsid: dataswitch ʵ��id
 *   addr: Ҫ����sipswitch�ĵ�ַ�Ͷ˿���Ϣ
 * ���:
 *   ����ֵdssipswitch id��������INVALID_SIPSWITCHID
 ****************************************************************/
API DSSIPSID dsCreateSipSwitch(DSID dsid, dsNetAddr *addr);

/****************************************************************
 * ����: dsAddSipSwitchRule()
 * ����: ��ĳ��sipswitch�����sip��������
 * ����:
 *   id: sipswitch��id����ʶ�������յ�ip��ַ�Ͷ˿�
 *   src: ������Դ��Ϣ������ԭip��ַ�Ͷ˿ڣ�ԭendpoint id��Ϣ��
 *        ��������Դip��ַ�Ͷ˿�ת����
 *          ����addr��Ϣ����actionΪDS_SRC_SIP_ANY_ID
 *        ��������e164��callid��Ϣת����
 *          ����e164��callid����actionΪDS_SRC_SIP_MATCH_ID
 *        ���src == NULL, �յ������а���ƥ���������.
 *
 *   modifier: ��������ת�����޸ĵ�Դ��Ϣ, ��� == NULL, ���޸�
 *         ������޸ĸ����ݰ���Դip�Ͷ˿ڣ�����addr��Ϣ
 *         ������޸ĸ����ݰ���e164��callid��Ϣ������e164��callid����
 *          action����ΪDS_MOD_SIP_CHANGE_ID����DS_MOD_SIP_REMOVE_ID
 *
 *   dst: ����ת������Ŀ����Ϣ������Ŀ��ip�Ͷ˿ڣ�Ŀ��endpoint��
 *         ���Ŀ���豸�Ĺ���ip����֪����ͨ��nat��Խ����ȡ��addr���
 *         ���Ӧ��e164��callid�������յ�nat��Խ�����Զ�������������ĵ�ַ��
 *
 *   priority: ��������ȼ�(1~100), Խ�����ȼ�Խ�ߡ�
 * ���:
 *   ����ֵDSOK��DSERROR.
 ****************************************************************/
API u32 dsAddSipSwitchRule(
    DSSIPSID id,
    dsSipEndpoint *src,
    dsSipEndpoint *modifier,
    dsSipEndpoint *dst,
    u32 priority);

/****************************************************************
 * ����: dsRemoveSipSwitchRule()
 * ����: ��ĳ��sipswitch��ɾ��sip��������
 * ����:
 *   id: �������ڵ�sipswitch��id.
 *   src: ������Դ��Ϣ������ԭip��ַ�Ͷ˿ڣ�ԭendpoint id��Ϣ��
 *        ���src == NULL, ƥ������Դ
 *   modifier: ��������ת�����޸ĵ�Դ��Ϣ, ��� == NULL, ���޸�
 *   dst: ����ת������Ŀ����Ϣ������Ŀ��ip�Ͷ˿ڣ�Ŀ��endpoint��
 * ���:
 *   ����ֵDSOK��DSERROR.
 ****************************************************************/
API u32 dsRemoveSipSwitchRule(
    DSSIPSID id,
    dsSipEndpoint *src,
    dsSipEndpoint *modifier,
    dsSipEndpoint *dst);

/****************************************************************
 * ����: dsDestroySipSwitch()
 * ����: ���һ��sipswitch
 * ����:
 *   dsid: dataswitch ʵ��id
 *   id:   sip switch id
 * ���:
 *   ����ֵDSOK��DSERROR.
 ****************************************************************/
 API u32 dsDestroySipSwitch(DSID dsid, DSSIPSID id);

/*---------------- ����sipswitch ���� -------------------------*/

/**********************************************************
 * ����: dsGetRecvPktCount                                *
 * ����: ��ѯ�����ܰ���                                   *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwRecvIP   - ���ؽ���IP                          *
 *       wRecvPort  - ���ؽ��ն˿ں�                      *
 *       dwSrcIP     - ԴIP                               *
 *       wSrcPort    - Դ�˿ں�                           *
 *       dwRecvPktCount  - �����ܰ���                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/
API u32 dsGetRecvPktCount( DSID dsId, u32 dwRecvIP, u16 wRecvPort ,
						  u32 dwSrcIP, u16 wSrcPort, u32& dwRecvPktCount);

/**********************************************************
 * ����: dsGetSendPktCount                                *
 * ����: ��ѯ�����ܰ���                                   *
 * ����: dsID        - ��������ģ��ʱ�ľ��               *
 *       dwRecvIP   - ���ؽ���IP                         *
 *       wRecvPort  - ���ؽ��ն˿ں�                     *
 *       dwSrcIP     - ԴIP                               *
 *       wSrcPort    - Դ�˿ں�                           *
 *       dwSendtoIP     - ת��Ŀ��IP��ַ                     *
 *       wSendtoPort    - ת��Ŀ�Ķ˿ں�                     *
 *       dwSendPktCount  - �����ܰ���                     *
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/
API u32 dsGetSendPktCount( DSID dsId, u32 dwRecvIP, u16 wRecvPort ,
						  u32 dwSrcIP, u16 wSrcPort,
						  u32 dwSendtoIP, u16 wSendtoPort, u32& dwSendPktCount);

/**********************************************************
 * ����: dsGetRecvBytesCount	                          *
 * ����: ��ѯ�������ֽ���                                 *
 * ����:												  *
 * ���: ��                                               *
 * ����: ���ؼ�ʱ�����ֽ���								  *
 **********************************************************/
API s64 dsGetRecvBytesCount( );

/**********************************************************
 * ����: dsGetSendBytesCount	                          *
 * ����: ��ѯ�������ֽ���                                 *
 * ����:												  *
 * ���: ��                                               *
 * ����: ���ؼ�ʱ�ֽ���									  *
 **********************************************************/
API s64 dsGetSendBytesCount( );

/************************************************************
 * ������ dsinfo
 * ���ܣ� ��ʾ���е�ת�����򣬼��������ڼ����Ķ˿�
 * ���룺
 * �����
 * ���أ�
 ************************************************************/
API void dsinfo();

/************************************************************
 * ������ dsver
 * ���ܣ� ��ʾDataswitch�İ汾��Ϣ
 * ���룺
 * �����
 * ���أ�
 ************************************************************/
API void dsver();

/************************************************************
 * ������ dshelp
 * ���ܣ� ��ʾDataswitch���ṩ������İ�����Ϣ
 * ���룺
 * �����
 * ���أ�
 ************************************************************/
API void dshelp();

/*��ʾ��ʱ��*/
API void dsshowrtcptimer();

/************************************************************
 * ������ dedebug
 * ���ܣ� ��/�رյ�����Ϣ
 *
 * ���룺
 * @param op            - ָ�������û��������set, clear
 *                        (����WIN32��Ч)
 * �����
 * ���أ�
 ************************************************************/
API void dsdebug(const char* op = NULL);

/************************************************************
 * ������ dedebug
 * ���ܣ� ��/�رո���һ��������Ϣ
 * �������ô˺�������Ϊ������Ϣ��Ӱ����������
 *
 * ���룺
 * @param op            - ָ�������û��������set, clear
 *                        (����WIN32��Ч)
 * �����
 * ���أ�
 ************************************************************/
API void dsdebug2();

 API void dstrace(DSID dsId, s8* pszLocalIP, u16 wLocalPort, u32 dwTraceNum);

 /**********************************************************
 * ����: dsStartRtcpRR                               *
 * ����: ���÷���RR�����,������ڱ��ؽڵ�,��δ���ù�����RR��  *
 * ����:
 * @param dsId          - DSID
 * @param dwLocalIP     - ����IP
 * @param wLocalPort    - ����Port
 * @param dwDstIP		- Ŀ��IP
 * @param wDstPort		- Ŀ�Ķ˿�
 * @param dwInterval	- ���ʱ��(��λ:��)
 * @param dwRtcpIP		- ����rtcp��IP(Ĭ����RR����Ϣ��û��LSR DLSR��Ϣ)
 * @param wRtcpPort		- ����rtcp��Port
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/
API u32 dsStartRtcpRR(DSID dsId,
                      u32 dwLocalIP, u16 wLocalPort,
                      u32 dwDstIP, u16 wDstPort,
                      u32 dwInterval,
                      u32 dwRtcpIP = 0, u16 wRtcpPort = 0);

 /**********************************************************
 * ����: dsStartRtcpRR                               *
 * ����: ȡ�����÷���RR�������������ڱ��ؽڵ�,�����ù�����RR��  *
 * ����:
 * @param dsId          - DSID
 * @param dwLocalIP     - ����IP
 * @param wLocalPort    - ����Port
 * @param dwRtcpIP		- ����rtcp��IP(Ĭ����RR����Ϣ��û��LSR DLSR��Ϣ)
 * @param wRtcpPort		- ����rtcp��Port
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/
API u32 dsStopRtcpRR(DSID dsId,
                     u32 dwLocalIP, u16 wLocalPort,
                     u32 dwRtcpIP = 0, u16 wRtcpPort = 0);

 /**********************************************************
 * ����: DsGetUdpSocket                               *
 * ����: ��ȡһ��dataswitch�Ķ˿�ȥ��������, �ṩ��proxy   *
 *       clientʹ���Խ���޷�ʹ��raw socket�����⡣        *
 * ����:
 * @param dsId          - DSID
 * @param dwLocalIP     - ����IP
 * @param wLocalPort    - ����Port
 * ���: ��                                               *
 * ����: �ɹ�����socket ����invalid_socket                *
 **********************************************************/
API SOCKHANDLE DsGetUdpSocket(DSID dsId, u32 dwLocalIP, u16 wLocalPort);

 /**********************************************************
 * ����: DsReleaseUdpSocket                                *
 * ����: �ͷŻ�ȡ����dataswitch socket�� �ṩ��proxy       *
 *       clientʹ���Խ���޷�ʹ��raw socket�����⡣        *
 * ����:
 * @param SOCKHANDLE          - socket
 * ���: ��                                               *
 * ����: �ɹ�����DSOK ����DSERROR                         *
 **********************************************************/
API u32 DsReleaseUdpSocket(DSID dsId, SOCKHANDLE socket);
#endif
