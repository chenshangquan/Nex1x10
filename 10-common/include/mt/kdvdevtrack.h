// kdv�豸̽�⹤�߽ӿ��ļ�

#ifndef KDVDEVTRACK__H__
#define KDVDEVTRACK__H__

#include "kdvtype.h"

//////////////////////////////////////////////////////////////////////////
// ��������
//////////////////////////////////////////////////////////////////////////

// �㲥��Ϣ'KDT1'-KDV Device Track 1.0 ͷ
#define DT_MAGIC	"KDT1"

const u32 DT_LEN_MAGIC = 4;
#define DT_LEN_MACADDR   6
#define DT_LEN_NAME	64

const u32 DT_ERR_OK = 0;
const u32 DT_ERR_SET_IP_FAILED = 1;

const u16 DT_SERVER_PORT = 8878;
const u16 DT_CLIENT_PORT = 8868;

//////////////////////////////////////////////////////////////////////////
// ��ϢID����
//////////////////////////////////////////////////////////////////////////

#define DECLARE_MESSAGE(m, id) const u16 m = id;

// �㲥��Ϣ
DECLARE_MESSAGE(NC_DEV_TRACK_REQ_CAST,		0x0001)	// �豸̽��㲥��Ϣ
// ���յ������豸��Ϣ���豸����ʱ����
DECLARE_MESSAGE(DEV_NC_TRACK_ACK_CAST,		0x0002)	// �豸��Ϣ֪ͨ��Ϣ��TDTHeader+TDTDevInfo

DECLARE_MESSAGE(NC_DEV_MODADDR_REQ_CAST,	0x0003)	// �޸��豸��ַ��Ϣ: TDTHeader+TDTDevAddr
// �޸��豸��ɣ�����ǰ���ʹ���Ϣ
DECLARE_MESSAGE(DEV_NC_MODADDR_ACK_CAST,	0x0004)	// �޸��豸��ַ��Ϣ: TDTHeader+u32(ErrorCode)

DECLARE_MESSAGE(NC_DEV_REBOOT_REQ_CAST,	0x0005)		// �����豸��Ϣ

//////////////////////////////////////////////////////////////////////////
// �ṹ�嶨��
//////////////////////////////////////////////////////////////////////////

// Windows OS���ֽڽ�������
#ifdef WIN32
	#pragma pack( push )
	#pragma pack( 1 )
#else
	#include <netinet/in.h>
#endif

struct TDTHeader
{
	u8  abyMacSrc[DT_LEN_MACADDR];	// ������MAC��ַ(CHAR[12])  
	u8  abyMacDst[DT_LEN_MACADDR];	// ������MAC��ַ(CHAR[12]) 	
	u16 wMsgID;		// ��ϢID
}
#ifndef WIN32
__attribute__ ( (packed) ) 
#endif
;

struct TDTDevAddr
{
	// DHCP���������ͣ���һ�ֽ�: 0-û��DHCP���� 1-��������2-�ͻ��� 
	// �ڶ��ֽ�: 0-�ر� 1-���������磺0x0000��ʾû�з�������0x0201��ʾ�ͻ���(����)
	u16 wDHCPOpen;	// 0-�ر� 1-����DHCP
	u32 dwIpaddr;		// IP��ַ��������
	u32 dwNetmask;		// �������룬������
	u32 dwGateWay;		// Ĭ�����أ�������
}
#ifndef WIN32
__attribute__ ( (packed) )
#endif
;

struct TDTDevInfo
{
	struct TDTDevAddr tAddr;	// IP��MASK��GW
	u32 dwTickCount;	// ����ʱ��
	u32 dwBrdID;		// �豸����ID
	s8 achDevName[DT_LEN_NAME+1];	// �豸����
}
#ifndef WIN32
__attribute__ ( (packed) )
#endif
;

// Windows OS���ֽڽ�������
#ifdef WIN32
	#pragma pack( pop )
#endif

#endif // KDVDEVTRACK__H__
