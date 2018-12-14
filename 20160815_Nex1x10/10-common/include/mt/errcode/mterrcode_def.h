/**===========================================================================
 * @file    $Id$
 * @brief   �����ն˴�����ͳһ���������
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_DEF_H_
#define _MTERRORCODE_DEF_H_

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
*@brief ���������(10���Ʊ�ʾ)
*	 99                   99                    9             9999
*	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
*(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
*/

/**������ģ��ID����, emErrorModuleUI = 30���֮ǰ�ĸ�MTCBBʹ�ã�
��û�г���30ʱ�����Զ��嵽emErrorModuleUI֮ǰ�������Ժ�������ģ�鶨��ֻ������׷�� */
enum EM_ERROR_MODULE
{
    emErrorModuleGlobal = 0,        ///< �ն�ȫ�ִ�����
    emErrorModuleMTAPI,             ///< �ն�MTAPI ϸ����
    emErrorModuleMTSDK,             ///< �ն�MTSDK ������
    emErrorModuleDispatch,          ///< �ն˵���ģ��
    emErrorModuleMTSysCtrl,         ///< �ն�ϵͳ������ϵͳ
	emErrorModuleDataShare,         ///< �ն����ݹ���ģ��
    emErrorModuleIM,                ///< �ն�IM��ϵͳ
    emErrorModuleDataConf,          ///< �ն�����Эͬ��ϵͳ
    emErrorModuleMeetingMgr,        ///< �ն˻���ճ���ϵͳ
	emErrorModuleMTMP,              ///< �ն�ý��ҵ����ϵͳ
	emErrorModuleSNMP,              ///< �ն�����ҵ����ϵͳ
	emErrorModuleDevice,            ///< �ն��豸������ϵͳ
	emErrorModuleUpdate,            ///< �ն�����ҵ����ϵͳ
	emErrorModuleNetworkService,    ///< �ն�������������ϵͳ
	emErrorModuleServerLogin,      ///< �ն˷�������¼��ϵͳ
	emErrorModuleMisc,              ///< �ն�Сҵ����ϵͳ
	emErrorModuleDiagnose,          ///< �ն����ҵ����ϵͳ
	emErrorModuleToolApi,           ///< �ն˹�����APIʵ�ֿ�
	emErrorModuleAccess,            ///< �ն˽���ģ��
	emErrorModuleMtConf,            ///< �ն˻�����ϵͳ
	emErrorModuleMtVod,            ///< �ն˵㲥��ϵͳ
	emErrorModuleMtpa,              ///<
	emErrorModuleMtmc,              ///<����mcģ��

	                                ///< ����30�����ٴ�ǰ�����MTCBBģ�����չ
	emErrorModuleUI = 30,           ///< �ն�UI(������UI) 
	emErrorModuleMediaCtrl,         ///< ý�����ģ��(������ý����)
	emErrorModuleProtocol,          ///< ����Э��ģ��(����������Э����)
	emErrorModuleDriverCtrl,        ///< Ӳ������ģ��(������������)
	emErrorModuleHardWare,          ///< Ӳ���豸ģ��(������Ӳ����)
};

/** ������ȼ�����, �����ȼ�����ֻ������׷�� */
enum EM_ERROR_LEVEL
{
    emErrorLevelInfo = 0,           ///< ��Ϣ��ʾ��
    emErrorLevelWarning,            ///< ������
    emErrorLevelError,              ///< ������
    emErrorLevelSysError,           ///< ���ش�����(ϵͳ�����) 
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_DEF_H_