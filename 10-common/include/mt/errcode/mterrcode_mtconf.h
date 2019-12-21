/**===========================================================================
 * @file    $Id$
 * @brief   ����MTCONFҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTCONF_H_
#define _MTERRORCODE_MTCONF_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** MTCONFҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_MTCONF
{
    emErrSubModMtConf_Call = 0,              ///< confģ�� ���в���
	emErrSubModMtConf_Chan = 1,              ///< confģ�� ͨ��������
	emErrSubModMtConf_ConfCtrl = 2,          ///< confģ�� ��ز���
	emErrSubModMtConf_Reg = 3,               ///< confģ�� ע�Ჿ��
	emErrSubModMtConf_Mtpa = 4,              ///< mtpaģ�����
	
};

//////////////////////////////////////////////////////////// Call //////////////////////////////////////////////////////////////////////////////////////
/** mtconfҵ��ģ����в��ִ����붨�� */
#define  ERR_MTCONF_Call_WrongState                         (u32)1                           ///< ����״̬������
#define  ERR_MTCONF_Call_JoinConfWithNoE164                 (u32)2                           ///< �μӻ��飬����e164��Ϊ�գ� ����û��
#define  ERR_MTCONF_Call_CreateConfWithNoE164               (u32)3                           ///< ��û�յ�mcu�� conf e164�Ļ�Ӧ, Ȼ���յ�callincoming
#define  ERR_MTCONF_Call_MakeCallSateNoP2P                  (u32)4                           ///< �����ն�ô��p2pȨ�ޣ�����   
/////////////////////////////////////////////////  END DEFINE/////////////////////////////////////////////////

//////////////////////////////////////////////////////////// Chan //////////////////////////////////////////////////////////////////////////////////////
/** mtconfҵ��ģ����в��ִ����붨�� */
#define  ERR_MTCONF_Chan_WrongState                         (u32)1                           ///< chan״̬���ԣ� �޷�����ͨ������
#define  ERR_MTCONF_Chan_GetNullChan                        (u32)2                           ///< ��ÿյ�chan���� �޷�����ͨ������
#define  ERR_MTCONF_Chan_GetWrongChan                       (u32)3                           ///< ��ô����chan���� �޷�����ͨ������
/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////


//////////////////////////////////////////////////////////// Mtpa ////////////////////////////////////////////
/*mtpaģ����д�����*/
#define  ERR_MTCONF_MTPA_InVaildCall                         (u32)1                          ///<���о�����ԣ������޷����� 
 
/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////
#endif // _MTERRORCODE_MTCONF_H_