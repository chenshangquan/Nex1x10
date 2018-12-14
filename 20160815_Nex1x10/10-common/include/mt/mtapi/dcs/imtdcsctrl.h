/**===========================================================================
 * @file    $Id$
 * @brief   负责MtDcsAPi 会管日程相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTDCSCTRL_H_
#define _I_MTDCSCTRL_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
//#include "mtapi_event_mg.h"
#include "mtapi_struct.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtDcsCtrl
 * @brief    负责MtDcsMgrAPi 会管日程相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtDcsCtrl : public IMtApiIF
{
public:

	// 获取会议列表请求
//	virtual u32 RestGetMeetingListReq(const TMTMeetingList_Api& tMtMeetingList_Api) = 0;
//	virtual u32 DCSLoginConnectCmd(const TDCSConnect_Api& tConnect_Api) = 0;

//	virtual u32 DCSConfConnectCmd(const TDCSConnect_Api& tConnect_Api) = 0;

	virtual u32 DCSLoginSrvReq(const TDCSRegInfo_Api& tRegInfo_Api) = 0;

	virtual u32 DCSLogoutReq() = 0;

	virtual u32 DCSCreateConfReq(const TDCSCreateConf_Api& tConf_Api) = 0;

	virtual u32 DCSGetConfInfoReq() = 0;

//	virtual u32 DCSGetConfAddrReq(const s8 *pchConfE164) = 0;

//	virtual u32 DCSJoinConfReq(const s8 *pchConfE164) = 0;

//	virtual u32 DCSRejectJoinConfCmd(const TDCSRejectJoinConf_Api& tRejectJoinConf_Api) = 0;

	virtual u32 DCSQuitConfReq(const s8 *pchConfE164, const u32 dwForceFlag) = 0;

	virtual u32 DCSReleaseConfReq(const s8 *pchConfE164) = 0;

	virtual u32 DCSAddMemberReq(const TDCSMemberInfo_Api& tMemInfo_Api) = 0;

	virtual u32 DCSDelMemberReq(const TDCSMemberInfo_Api& tMemInfo_Api) = 0;

	virtual u32 DCSSetConfInfoReq(const TDCSConfInfo_Api& tConfInfo_Api) = 0;

	virtual u32 DCSAddOperatorReq(const TDCSOperator_Api& tAdpOperator_Api) = 0;

	virtual u32 DCSDelOperatorReq(const TDCSOperator_Api& tAdpOperator_Api) = 0;

	virtual u32 DCSApplyOperReq(const s8 *pchConfE164) = 0;

	virtual u32 DCSCancelOperReq(const s8 *pchConfE164) = 0;

	virtual u32 DCSGetUserListReq(const s8 *pchConfE164) = 0;

	virtual u32 DCSNewWhiteBoardReq(const TDCSNewWhiteBoard_Api& tBoard_Api) = 0;

	virtual u32 DCSDelWhiteBoardReq(const s8 *pchConfE164, const s8 *pchIndex) = 0;

	virtual u32 DCSDelAllWhiteBoardReq(const s8 *pchConfE164) = 0;

	virtual u32 DCSGetAllWhiteBoardReq(const s8 *pchConfE164) = 0;

	virtual u32 DCSGetWhiteBoardReq(const s8 *pchConfE164, const s8 *pchIndex) = 0;

	virtual u32 DCSGetCurWhiteBoardReq(const s8 *pchConfE164) = 0;

	virtual u32 DCSSwitchReq(const TDCSSwitchReq_Api& tSwitch_Api) = 0;

	virtual u32 DCSOperLineOperInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbLineOperInfo_Api& tLineOperInfo_Api) = 0;

	virtual u32 DCSOperCircleOperInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbCircleOperInfo_Api& tCircleOperInfo_Api) = 0;

	virtual u32 DCSOperRectangleOperInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbRectangleOperInfo_Api& tRectangleOperInfo_Api) = 0;

	virtual u32 DCSOperPencilOperInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbPencilOperInfo_Api& tPencilOperInfo_Api) = 0;

	virtual u32 DCSOperColorPenOperInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbColorPenOperInfo_Api& tColorPenOperInfo_Api) = 0;

	virtual u32 DCSOperImageOperInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbImageOperInfo_Api& tImageOperInfo_Api) = 0;

//	virtual u32 DCSOperRemovePageIdInfoCmd(const TDCSWbRemovePageIdInfo_Api& tRemovePageIdInfo_Api) = 0;

//	virtual u32 DCSOperTabPageInfoCmd(const TDCSWbTabPageInfo_Api& tTabPageInfo_Api) = 0;

	virtual u32 DCSOperAddSubPageInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbAddSubPageInfo_Api& tAddSubPageInfo_Api) = 0;

//	virtual u32 DCSOperSwitchPageInfoCmd(const TDCSWbSwitchPageInfo_Api& tSwitchPageInfo_Api) = 0;

//	virtual u32 DCSOperReqPageImageCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbReqPageImage_Api& tReqPageImage_Api) = 0;

	virtual u32 DCSOperEraseOperInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbEraseOperInfo_Api& tEraseOperInfo_Api) = 0;

	virtual u32 DCSOperZoomInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbZoomInfo_Api& tZoomInfo_Api) = 0;

//	virtual u32 DCSSendImgFileInfoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbSendImgFileInfo_Api& tSendImgFileInfo_Api) = 0;

	virtual u32 DCSOperUndoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbTabPageIdInfo_Api& tTabPageIdInfo_Api) = 0;

	virtual u32 DCSOperRedoCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbTabPageIdInfo_Api& tTabPageIdInfo_Api) = 0;

	virtual u32 DCSOperRotateLeftCmd(const TDCSOperReq_Api& tOperReq_Api) = 0;

	virtual u32 DCSOperRotateRightCmd(const TDCSOperReq_Api& tOperReq_Api) = 0;

	virtual u32 DCSOperClearScreenCmd(const TDCSOperReq_Api& tOperReq_Api) = 0;

	virtual u32 DCSOperScrollScreenCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSScrollScreenInfo_Api& tScrollScreenInfo_Api) = 0;

	virtual u32 DCSOperFullScreenCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbDisPlayInfo_Api& tDisPlayInfo_Api) = 0;

	virtual u32 DCSOper100ProportionScreenCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbDisPlayInfo_Api& tDisPlayInfo_Api) = 0;

	virtual u32 DCSOperReginEraseCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbReginEraseOperInfo_Api& tReginEraseOperInfo_Api) = 0;

	virtual u32 DCSOperInsertPicCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbInsertPicOperInfo_Api& tInsertPicOperInfo_Api) = 0;

	virtual u32 DCSOperPitchPicZoomCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbPitchPicOperInfo_Api& tPitchPicOperInfo_Api) = 0;

	virtual u32 DCSOperPitchPicRotateCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbPitchPicOperInfo_Api& tPitchPicOperInfo_Api) = 0;

	virtual u32 DCSOperPitchPicDragCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbPitchPicOperInfo_Api& tPitchPicOperInfo_Api) = 0;

	virtual u32 DCSOperPitchPicDelCmd(const TDCSOperReq_Api& tOperReq_Api, const TDCSWbDelPicOperInfo_Api& tDelPicOperInfo_Api) = 0;

	virtual u32 DCSDownloadImageReq(const TDCSImageUrl_Api& tImageUrl_Api) = 0;

	virtual u32 DCSUploadImageReq(const TDCSImageUrl_Api& tImageUrl_Api) = 0;

    virtual u32 DCSUploadFileCmd( const s8* pchUploadUrl_Api, const TDCSFileInfo_Api& tFileInfo_Api/*const s8* pchFilePathName*/ ) = 0;

	virtual u32 DCSRejectOperatorCmd(const TDCSOperator_Api& tOperator_Api) = 0;

	virtual u32 DCSJoinConfDomainRsp(const TDCSConfAddr_Api& tConfAddr_Api) = 0;

    virtual u32 DCSDownloadFileReq( const s8* pchDownloadUrl_Api, const TDCSFileInfo_Api& tFileInfo_Api/*const s8* pchFilePathName*/ ) = 0;
};

#endif // _I_MTDCSCTRL_H_