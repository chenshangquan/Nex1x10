/*****************************************************************************
ģ����      : filetransflib
�ļ���      : evfiletransfer.h
����ʱ��    : 2011�� 09�� 21��
ʵ�ֹ���    : 
����        : ���Ĳ�
�汾        : 
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/09/21  1.0         ���Ĳ�        ����
******************************************************************************/

#ifndef _EV_FTLIBFEEDBACK_H_
#define _EV_FTLIBFEEDBACK_H_

#include "osp.h"
#include "eventid.h"

// �ļ����ͽ��֪ͨ	��Ϣ�壺TTransFileState
OSPEVENT( FTLIB_SENDFILE_RESULT_NTF,			EV_FTLIBFEEDBACK_BGN );
// �ļ����ͽ���֪ͨ
OSPEVENT( FTLIB_SENDFILE_PROGRESS_NTF,		    EV_FTLIBFEEDBACK_BGN + 1 );
// �ļ���������		��Ϣ�壺u32(������node) + u32(�ļ�������) + u8*(�ļ���)
OSPEVENT( FTLIB_FILE_RECEIVE_REQ,				EV_FTLIBFEEDBACK_BGN + 2 );
// ͬ������ļ�
OSPEVENT( FTLIB_FILE_RECEIVE_ACK,				EV_FTLIBFEEDBACK_BGN + 3 );
// �ܾ��ļ�����
OSPEVENT( FTLIB_FILE_RECEIVE_NACK,			    EV_FTLIBFEEDBACK_BGN + 4 );
// �ļ����ս���֪ͨ
OSPEVENT( FTLIB_FILE_RECEIVE_PROGRESS_NTF,	    EV_FTLIBFEEDBACK_BGN + 5 );
// �ļ����ս��֪ͨ	��Ϣ�壺TTransFileState
OSPEVENT( FTLIB_FILE_RECEIVE_RESULT_NTF,		EV_FTLIBFEEDBACK_BGN + 6 );






#endif
