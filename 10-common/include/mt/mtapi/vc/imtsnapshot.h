/**===========================================================================
 * @file    $Id$
 * @brief   ���������ع��ܽӿڶ���
 * @author   ��־Զ
 * @date    2015-02-09
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_SNAPSHOT_H_
#define _I_SNAPSHOT_H_


#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"

/**===========================================================================
 * @file    Interface IMtAudio
 * @brief   ���������ع��ܽӿڶ���
 * @author   ��־Զ
 * @date    2015-02-09
 * @note    
============================================================================*/

class IMtSnapShot: public IMtApiIF
{
public:
	//�����������
	virtual	u32 SnapshotReq(const EmCodecComponent_Api emCodecType,const EmCodecComponentIndex_Api emCodecIdx) = 0;
	//��ѯ��������ļ�����
	virtual	u32 SnapshotQueryLatestFileReq (void) = 0;
	//����ftp��������
	virtual	u32 FtpSnapshotCmd(const EmCodecComponent_Api emCodecType,const EmCodecComponentIndex_Api emCodecIdx) = 0;
	//��ѯ�����ļ��б���Ϣ����
	virtual u32 SnapshotQueryFileListReq(void) = 0;
	//ɾ��һ�ſ�������
	virtual u32 SnapshotDelOneFileReq( const TSnapshotFileInfo_Api& tSnapshotFileInfo) = 0;
	//ɾ�����п����ļ�����
	virtual u32 SnapshotDelAllFileReq(void) = 0;
	//����һ�ſ����ļ�����
	virtual u32 SnapshotExportOneFileReq( const TSnapshotFileInfo_Api& tSnapshotFileInfo, const s8 *pchDstPath ) = 0;
	//�������п����ļ����� 
	virtual u32 SnapshotExportAllFileReq(const s8 *pchDstPath) = 0;
    virtual u32 SnapshotFileRenameReq(const TSnapshotFileInfo_Api& tSrcInfo, const TSnapshotFileInfo_Api& tDstInfo) = 0;
    virtual u32 StopExportAllSnapshotFilesCmd() = 0;
    virtual u32 CodecOsdSnapshotCmd() = 0;
};




#endif // _I_SNAPSHOT_H_