/*****************************************************************************
ģ����      : filetransflib
�ļ���      : ftlibconst.h
����ʱ��    : 2011�� 10�� 08��
ʵ�ֹ���    : 
����        : ���Ĳ�
�汾        : 
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/10/08  1.0         ���Ĳ�        ����
******************************************************************************/

#ifndef _EV_FTLIBCONST_H_
#define _EV_FTLIBCONST_H_

#include "osp.h"
#include "kdvdef.h"

/* APPID */

//�ļ�����APP ID
#define		AID_FTLIB_FILESEND			AID_FILETRANS_BGN
//�ļ����չ���APP ID
#define		AID_FTLIB_FILERCVMANAGR		AID_FILETRANS_BGN + 1
//�ļ�����APP ID ����10��λ��,�ļ������߳����Ϊ10��
#define		AID_FTLIB_FILERCV			AID_FILETRANS_BGN + 2



/* �������� */


//��󲢷��ļ����͸���
#define		FTLIB_MAXNUM_SENDFILE			100
//�ļ������߳�������
#define		FTLIB_MAXNUM_RCVFILE			10
//�ļ������߳�Ĭ�ϸ���
#define		FTLIB_DEFAULTNUM_RCVFILE		3
//�ļ�������
#define		FTLIB_MAXLEN_FILENAEM			128
//�ļ��洢·������(�ļ���ȫ·��)
#define		FTLIB_MAXLEN_FILEPATH			256
//�������Ĭ���ϱ�Ƶ��
#ifdef	_ANDROID_
#define     FTLIB_DEFAULTPERCENT_PROCESS    1
#else
#define     FTLIB_DEFAULTPERCENT_PROCESS    2
#endif
//��������ϱ�ʱ������
#define     FTLIB_UNIT_TIME                 10

//ÿ���ļ���С
#define		FTLIB_FILE_PACK_LENGTH		    (1024 * 10 )

//ÿ���������ݣ��������ظ�����
#define		FTLIB_FILE_PACK_NUM		        10


//�ļ�������Ӧ��ʱʱ��
#define		FTLIB_RCV_UPLOADFILE_TIMEOUT	(10 * 1000)
//Ĭ���ļ�����·��
#ifdef	_LINUX_
#define		FTLIB_DEFAULT_DOWNLOAD_PATH	(LPCSTR)("/opt/mcu/download")
#endif
#ifdef	WIN32
#define		FTLIB_DEFAULT_DOWNLOAD_PATH	(LPCSTR)(".\\download")
#endif

//��Ϣ�������
#define      FTLIB_MSG_LEN					0x7000  //��Ϣ����
#define      FTLIB_MSGHEAD_LEN              0x34   

// ��ӡ����
enum em_Ftlib_PrintLevel
{
    em_Ftlib_PrintNone = 0,
	em_Ftlib_PrintCommon,
	em_Ftlib_PrintDetail,
	em_Ftlib_Printend
};



#endif
