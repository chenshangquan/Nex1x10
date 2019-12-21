/**===========================================================================
 * @file    $Id$
 * @brief   负责MTDATASHARE业务模块的错误码定义
 * @author  钱霖
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTDATASHARE_H_
#define _MTERRORCODE_MTDATASHARE_H_
#include "kdvtype.h"
#include "mterrcode_api.h"
#include "mterrcode_def.h"
/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** MTDATASHARE业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_MTDATASHARE
{
    emErrSubModMtDS_Client = 0,          ///< 数据共享客户端
	emErrSubModMtDS_ShmMgr,              ///< 数据共享共享内存管理
	emErrSubModMtDS_Server,              ///< 数据共享服务器
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** DataShareClient基本错误码定义 */
enum EmMtDscErrorId
{
	ERR_MT_DSC_Success = 0,
	ERR_MT_DSC_Error,
	ERR_MT_DSC_Alloc_Shm,
	ERR_MT_DSC_Invalid_Param,
	ERR_MT_DSC_Input_Size_TooSmall,
	ERR_MT_DSC_Input_Size_TooLarge,
	ERR_MT_DSC_Space_Not_Enough,
	ERR_MT_DSC_NULL_Ptr,
	ERR_MT_DSC_Sem_Ptr_NULL,
	ERR_MT_DSC_Mgr_Invalid,
	ERR_MT_DSC_Key_Invalid,
	ERR_MT_DSC_Key_mismatch,
	ERR_MT_DSC_Subkey_mismatch,
	ERR_MT_DSC_Load_Smp_Err,
	ERR_MT_DSC_Invalid_smp,
	ERR_MT_DSC_RBTree_Invalid,
	ERR_MT_DSC_RBTree_Insert_Fail,
	ERR_MT_DSC_RBTree_Insert_Dup,
	ERR_MT_DSC_RBTree_Delete_Fail,
	ERR_MT_DSC_RBTree_StrKeyTooLong,
	ERR_MT_DSC_RBTree_No_Record,
	ERR_MT_DSC_RBTree_Released,
	ERR_MT_DSC_Next_Node_Exist,
	ERR_MT_DSC_END,
};
/** SharedMemMgr基本错误码定义 */
enum EmShmErrorId
{
	ERR_MT_SHM_Success = 0,
	ERR_MT_SHM_Error,
	ERR_MT_SHM_Size_Zero,
	ERR_MT_SHM_To_Large,
	ERR_MT_SHM_NULL_Ptr,
	ERR_MT_SHM_IPC_SEM_Take,
	ERR_MT_SHM_IPC_SEM_Give,
	ERR_MT_SHM_Empty_Page_List,
	ERR_MT_SHM_Id_Invalid,
	ERR_MT_SHM_Id_Dup,
	ERR_MT_SHM_Id_Not_Find,
	ERR_MT_SHM_New_Object_Fail,
	ERR_MT_SHM_Mgr_Invalid,
	ERR_MT_SHM_Page_Blk_Full,
	ERR_MT_SHM_Frag_Blk_Full,
	ERR_MT_SHM_LOAD_SMP_ERROR,
	ERR_MT_SHM_Invalid_smp,
	ERR_MT_SHM_Load_Smp_Err,
	ERR_MT_SHM_END,
};
/** DataShareServer基本错误码定义 */
enum EmDssErrorId
{
	ERR_MT_DSS_Success = 0,
	ERR_MT_DSS_Error,
	ERR_MT_DSS_NULL_Ptr,
	ERR_MT_DSS_END,
};



/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTDATASHARE_H_