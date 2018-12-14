/**===========================================================================
 * @file    $Id$
 * @brief   ����NVCONFҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVCONF_H_
#define _NVERRORCODE_NVCONF_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** NVCONFҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_NVCONF
{
    emErrSubModNvConf_Call = 0,              ///< confģ�� ���в���
	emErrSubModNvConf_Chan = 1,              ///< confģ�� ͨ��������
	emErrSubModNvConf_ConfCtrl = 2,          ///< confģ�� ��ز���
	emErrSubModNvConf_Reg = 3,               ///< confģ�� ע�Ჿ��
	emErrSubModNvConf_Nvpa = 4,              ///< nvpaģ�����
	
};

//////////////////////////////////////////////////////////// Call //////////////////////////////////////////////////////////////////////////////////////
/** nvconfҵ��ģ����в��ִ����붨�� */
#define  ERR_NVCONF_Call_WrongState                         (u32)1                           ///< ����״̬������
#define  ERR_NVCONF_Call_JoinConfWithNoE164                 (u32)2                           ///< �μӻ��飬����e164��Ϊ�գ� ����û��
#define  ERR_NVCONF_Call_CreateConfWithNoE164               (u32)3                           ///< ��û�յ�mcu�� conf e164�Ļ�Ӧ, Ȼ���յ�callincoming
#define  ERR_NVCONF_Call_MakeCallSateNoP2P                  (u32)4                           ///< �����ն�ô��p2pȨ�ޣ�����   
/////////////////////////////////////////////////  END DEFINE/////////////////////////////////////////////////

//////////////////////////////////////////////////////////// Chan //////////////////////////////////////////////////////////////////////////////////////
/** nvconfҵ��ģ����в��ִ����붨�� */
#define  ERR_NVCONF_Chan_WrongState                         (u32)1                           ///< chan״̬���ԣ� �޷�����ͨ������
#define  ERR_NVCONF_Chan_GetNullChan                        (u32)2                           ///< ��ÿյ�chan���� �޷�����ͨ������
#define  ERR_NVCONF_Chan_GetWrongChan                       (u32)3                           ///< ��ô����chan���� �޷�����ͨ������
/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////


//////////////////////////////////////////////////////////// Nvpa ////////////////////////////////////////////
/*nvpaģ����д�����*/
#define  ERR_NVCONF_NVPA_InVaildCall                         (u32)1                          ///<���о�����ԣ������޷����� 
 
/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////
#endif // _NVERRORCODE_NVCONF_H_