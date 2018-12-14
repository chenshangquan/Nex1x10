/**===========================================================================
 * @file    $Id$
 * @brief   负责NVDATASHARE业务模块的错误码定义
 * @author  钱霖
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVDATASHARE_H_
#define _NVERRORCODE_NVDATASHARE_H_
#include "kdvtype.h"
#include "nverrcode_api.h"
#include "nverrcode_def.h"
/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** NVDATASHARE业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_NVDATASHARE
{
    emErrSubModNvDS_Client = 0,          ///< 数据共享客户端
	emErrSubModNvDS_ShmMgr,              ///< 数据共享共享内存管理
	emErrSubModNvDS_Server,              ///< 数据共享服务器
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** DataShareClient基本错误码定义 */
enum EmNvDscErrorId
{
	ERR_NV_DSC_Success = 0,
	ERR_NV_DSC_Error,
	ERR_NV_DSC_Alloc_Shm,
	ERR_NV_DSC_Invalid_Param,
	ERR_NV_DSC_Input_Size_TooSmall,
	ERR_NV_DSC_Input_Size_TooLarge,
	ERR_NV_DSC_Space_Not_Enough,
	ERR_NV_DSC_NULL_Ptr,
	ERR_NV_DSC_Sem_Ptr_NULL,
	ERR_NV_DSC_Mgr_Invalid,
	ERR_NV_DSC_Key_Invalid,
	ERR_NV_DSC_Key_mismatch,
	ERR_NV_DSC_Subkey_mismatch,
	ERR_NV_DSC_Load_Smp_Err,
	ERR_NV_DSC_Invalid_smp,
	ERR_NV_DSC_RBTree_Invalid,
	ERR_NV_DSC_RBTree_Insert_Fail,
	ERR_NV_DSC_RBTree_Insert_Dup,
	ERR_NV_DSC_RBTree_Delete_Fail,
	ERR_NV_DSC_RBTree_StrKeyTooLong,
	ERR_NV_DSC_RBTree_No_Record,
	ERR_NV_DSC_RBTree_Released,
	ERR_NV_DSC_Next_Node_Exist,
	ERR_NV_DSC_END,
};
/** SharedMemMgr基本错误码定义 */
enum EmShmErrorId
{
	ERR_NV_SHM_Success = 0,
	ERR_NV_SHM_Error,
	ERR_NV_SHM_Size_Zero,
	ERR_NV_SHM_To_Large,
	ERR_NV_SHM_NULL_Ptr,
	ERR_NV_SHM_IPC_SEM_Take,
	ERR_NV_SHM_IPC_SEM_Give,
	ERR_NV_SHM_Empty_Page_List,
	ERR_NV_SHM_Id_Invalid,
	ERR_NV_SHM_Id_Dup,
	ERR_NV_SHM_Id_Not_Find,
	ERR_NV_SHM_New_Object_Fail,
	ERR_NV_SHM_Mgr_Invalid,
	ERR_NV_SHM_Page_Blk_Full,
	ERR_NV_SHM_Frag_Blk_Full,
	ERR_NV_SHM_LOAD_SMP_ERROR,
	ERR_NV_SHM_Invalid_smp,
	ERR_NV_SHM_Load_Smp_Err,
	ERR_NV_SHM_END,
};
/** DataShareServer基本错误码定义 */
enum EmDssErrorId
{
	ERR_NV_DSS_Success = 0,
	ERR_NV_DSS_Error,
	ERR_NV_DSS_NULL_Ptr,
	ERR_NV_DSS_END,
};



/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVDATASHARE_H_