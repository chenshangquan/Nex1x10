/*****************************************************************************
   ģ����      : KDV system
   �ļ���      : eventid.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: KDV�¼���ͳһ����
   ����        : ����
   �汾        : V0.9  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2002/03/01  0.9         ����        ����
   2004/03/11  3.0         κ�α�      ���ӵ�ַ����Ϣ
   2005/12/26  4.0	       zhangsh     ����DCS��MCUͨѶ��Ϣ
   2013/11/07  5.0         ruiyigen    ��ҵ��ҵͷ�ļ�����
******************************************************************************/
#ifndef _EVENT_ID_H_
#define _EVENT_ID_H_

#define EV_EVENT_BASE                  4000

//�ڲ���Ϣ����(4000-9999)
#define EV_INNER_BGN                   EV_EVENT_BASE
#define EV_INNER_END                   (EV_INNER_BGN + 5999)

//agw �ڲ���Ϣ(4001-4100)
#define EV_AGW_BGN                     (EV_INNER_BGN + 1)
#define EV_AGW_END                     (EV_AGW_BGN + 99)

//mtadp �ڲ���Ϣ(4051-4100)
// #define EV_MTADP_BGN                   (EV_AGW_END + 1)
// #define EV_MTADP_END                   (EV_MTADP_BGN + 49)

//�ļ������������ڲ���Ϣ(4101-4250)
#define EV_SUS_BGN		               (EV_AGW_END + 1)
#define EV_SUS_END		               (EV_SUS_BGN + 149)

//SA�ڲ�ͨ����Ϣ(4251-4300)
#define EV_SA_BGN                      (EV_SUS_END + 1)
#define EV_SA_END                      (EV_SA_BGN + 49)

//CONNECTSA�ڲ�ͨ����Ϣ(4301-4320)
#define EV_CONNECTSA_BGN               (EV_SA_END + 1)
#define EV_CONNECTSA_END               (EV_CONNECTSA_BGN + 19)

//MTSģ���ڲ���Ϣ(4321-4340)
#define EV_MTS_BGN                     (EV_CONNECTSA_END + 1)
#define EV_MTS_END                     (EV_MTS_BGN + 19)

//LGSģ���ڲ���Ϣ(4341-4360)
#define EV_LGS_BGN                     (EV_MTS_END + 1)
#define EV_LGS_END                     (EV_LGS_BGN + 19)

//ZyGuard�ڲ���Ϣ(4361-4370)
#define EV_ZYGUARD_BGN                 (EV_LGS_END + 1)
#define EV_ZYGUARD_END                 (EV_ZYGUARD_BGN  + 9)




#define EV_KDV_BASE                    10000

//���ܿͻ����ڲ���Ϣ(10001-11000)
#define EV_NMC_BGN                     (EV_KDV_BASE + 1)
#define EV_NMC_END                     (EV_NMC_BGN + 999)

//���ܿͻ����ڲ���Ϣ(10001-11000) �ض������ƣ����뿼��
#define EV_CLT_BGN                     EV_NMC_BGN
#define EV_CLT_END                     EV_NMC_END

//�������̨�ڲ���Ϣ(11001-12000)
#define EV_MC_BGN                      (EV_NMC_END + 1)
#define EV_MC_END                      (EV_MC_BGN + 999)

//�ն˿���̨�ڲ���Ϣ(12001-13000)
#define EV_MTC_BGN                     (EV_MC_END + 1)
#define EV_MTC_END                     (EV_MTC_BGN + 999)

//���ܿͻ��˷������ӿ���Ϣ(13001-14000)
#define EV_NMC_NMS_BGN                 (EV_MTC_END + 1)
#define EV_NMC_NMS_END                 (EV_NMC_NMS_BGN + 999)

//���ܿͻ��˷������ӿ���Ϣ(13001-14000) �ض������ƣ����뿼��
#define EV_CLTSVR_BGN                  EV_NMC_NMS_BGN
#define EV_CLTSVR_END                  EV_NMC_NMS_END

//���ܷ������ڲ���Ϣ(14001-15000)
#define EV_NMS_BGN                    (EV_NMC_NMS_END + 1)
#define EV_NMS_END                    (EV_NMS_BGN + 999)

//���ܷ���������ӿ���Ϣ(15001-17000)
#define EV_DEVAGT_NMS_BGN             (EV_NMS_END + 1)
#define EV_DEVAGT_NMS_END             (EV_DEVAGT_NMS_BGN + 1999)

//2010/06/02��������ӣ����ܷ�������3AS�ӿ���Ϣ(17001-18000)
#define EV_NMS_3AS_BGN                (EV_DEVAGT_NMS_END + 1)
#define EV_NMS_3AS_END                (EV_NMS_3AS_BGN + 999)

//�����ڲ���Ϣ(18001-20000)
#define EV_AGT_BGN                    (EV_NMS_3AS_END + 1)
#define EV_AGT_END                    (EV_AGT_BGN + 1999)

//�����ҵ��ӿ���Ϣ(20001-22000)
#define EV_AGTSVC_BGN                 (EV_AGT_END + 1)
#define EV_AGTSVC_END                 (EV_AGTSVC_BGN + 1999)

//�������̨��MCUҵ��ӿ���Ϣ(22001-23000)
#define EV_MCSVC_BGN                  (EV_AGTSVC_END + 1)
#define EV_MCSVC_END                  (EV_MCSVC_BGN + 999)

//�ն˿���̨��MTҵ��ӿ���Ϣ(23001-24000)
#define EV_MTCSVC_BGN                 (EV_MCSVC_END + 1)
#define EV_MTCSVC_END                 (EV_MTCSVC_BGN + 999)

//MCU��MT��ҵ��ӿ���Ϣ(25001-26000)
#define EV_MCUMT_BGN                  (EV_MTCSVC_END + 1001)
#define EV_MCUMT_END                  (EV_MCUMT_BGN + 999)

//MCU�������ҵ��ӿ���Ϣ(26001-27000)
#define EV_MCUEQP_BGN                 (EV_MCUMT_END + 1)
#define EV_MCUEQP_END                 (EV_MCUEQP_BGN + 999)

//MPC��MPCDͨ����Ϣ(27001-27130)
#define	EV_MPC_MPCD_BGN				  (EV_MCUEQP_END + 1)
#define	EV_MPC_MPCD_END				  (EV_MPC_MPCD_BGN + 129)

//AGW��MPCDͨ����Ϣ(27131-27170)
#define EV_AGW_MPCD_BGN               (EV_MPC_MPCD_END + 1)
#define EV_AGW_MPCD_END               (EV_AGW_MPCD_BGN + 39)

//MPU�����轻����Ϣ(27171-27270)
#define EV_MPUEQP_BGN				  (EV_AGW_MPCD_END + 1)
#define EV_MPUEQP_END				  (EV_MPUEQP_BGN + 99)

//MPS��MCU������Ϣ(27271-27470)
#define EV_MPUMCU_BGN				  (EV_MPUEQP_END + 1)
#define EV_MPUMCU_END				  (EV_MPUMCU_BGN + 199)

//MCU�ڲ�ҵ����Ϣ(28001-29000)*/
#define EV_MCU_BGN                    28001
#define EV_MCU_END                    (EV_MCU_BGN + 999)

//MT�ڲ�ҵ����Ϣ(29001-30000)
#define EV_MT_BGN                     (EV_MCU_END + 1)
#define EV_MT_END                     (EV_MT_BGN + 999)

//RECORDER�ڲ�ҵ����Ϣ(30001-30200)
#define EV_REC_BGN                    (EV_MT_END + 1)
#define EV_REC_END                    (EV_REC_BGN + 199)

//�������ڲ�ҵ����Ϣ(30201-30400)
#define EV_MIXER_BGN                  (EV_REC_END + 1)
#define EV_MIXER_END                  (EV_MIXER_BGN + 199)

//����ǽ�ڲ�ҵ����Ϣ(30401-30500)
#define EV_TVWALL_BGN                 (EV_MIXER_END + 1)
#define EV_TVWALL_END                 (EV_TVWALL_BGN + 99)

//HDU�ڲ�ҵ����Ϣ(30501-30600)
#define EV_HDU_BGN                    (EV_TVWALL_END + 1)
#define EV_HDU_END                    (EV_HDU_BGN + 99)

//MP ��Ϣ(30601-30700)
#define EV_MCUMP_BGN                  (EV_HDU_END + 1)
#define EV_MCUMP_END                  (EV_MCUMP_BGN + 99)

//��������������ڲ�ҵ����Ϣ(30701-30800)
#define EV_BAS_BGN                    (EV_MCUMP_END + 1)
#define EV_BAS_END                    (EV_BAS_BGN + 99)

//������Ϣ����(30801 - 33900)
#define GKOSPEVENT_START              (EV_BAS_END + 1)
#define GKOSPEVENT_END                (GKOSPEVENT_START + 3099)

//modify by zhanghb 100609 GK����Ϣ��Χ�л��ֳ���3ASͨ�ŵ���Ϣ��(33901 - 34900)
#define GK_3AS_EVENT_START            (GKOSPEVENT_END + 1)
#define GK_3AS_EVENT_END              (GK_3AS_EVENT_START + 999)

//��غ�MPCD��Ϣ����(34901-35050)
#define MPCD_MCC_EVENT_START          (GK_3AS_EVENT_END + 1)  
#define MPCD_MCC_EVENT_END            (MPCD_MCC_EVENT_START + 149)

// MPC��MMPU��Ϣ����(35051-35070)
#define MMPU_MPC_EVENT_START          (MPCD_MCC_EVENT_END + 1)
#define MMPU_MPC_EVENT_END            (MMPU_MPC_EVENT_START + 19)

// MPU��MMPU��Ϣ����(35071-35090)
#define MMPU_MPU_EVENT_START          (MMPU_MPC_EVENT_END + 1)
#define MMPU_MPU_EVENT_END            (MMPU_MPU_EVENT_START + 19)

// MPCD��MMPU��Ϣ����(35091-35100)
#define MMPU_MPCD_EVENT_START         (MMPU_MPU_EVENT_END + 1)
#define MMPU_MPCD_EVENT_END           (MMPU_MPCD_EVENT_START + 9)

//(35101 - 35600)
#define GK_TS_EVENT_START             (MMPU_MPCD_EVENT_END + 1)
#define GK_TS_EVENT_END               (GK_TS_EVENT_START + 499)

//(35601 - 35700)
#define GK_MCU_EVENT_START            (GK_TS_EVENT_END + 1)
#define GK_MCU_EVENT_END              (GK_MCU_EVENT_START + 99)

//(35701 - 35800)
#define NU_MAU_EVENT_START           (GK_MCU_EVENT_END + 1)
#define NU_MAU_EVENT_END             (NU_MAU_EVENT_START + 99)

//�û�������Ϣ����(34901 - 35000)
#define EV_UM_BGN                     34901
#define EV_UM_END                     (EV_UM_BGN + 99)

//��ַ����Ϣ����(35001 - 35100)
#define EV_ADDRBOOK_BGN               (EV_UM_END + 1)
#define EV_ADDRBOOK_END               (EV_ADDRBOOK_BGN + 99)

//VAS��Ϣ����(35101-36100)
#define EV_VAS_BGN                    (EV_ADDRBOOK_END + 1)
#define EV_VAS_END                    (EV_VAS_BGN + 999)

//RAS��Ϣ����(36101-36200)
#define EV_RAS_BGN                    (EV_VAS_END + 1)
#define EV_RAS_END                    (EV_RAS_BGN + 99)

//DCServer��DCConsole֮��ҵ��ӿ���Ϣ(36201-37000)
#define EV_DCSDCC_BGN                 (EV_RAS_END + 1)
#define EV_DCSDCC_END                 (EV_DCSDCC_BGN + 799)

//MT���������Ϣ(37001-37100)
#define EV_MTDEV_BGN                  (EV_DCSDCC_END + 1)
#define EV_MTDEV_END                  (EV_MTDEV_BGN + 99)

//DCServer��DCSGuard֮��ҵ��ӿ���Ϣ(37101-37200)
#define EV_DCSDCSGUARD_BGN            (EV_MTDEV_END + 1)
#define EV_DCSDCSGUARD_END            (EV_DCSDCSGUARD_BGN + 99)

//Ŀ¼�����ҵ����Ϣ(37201-37700)
#define EV_LDAP_BGN                   (EV_DCSDCSGUARD_END + 1)
#define EV_LDAP_END                   (EV_LDAP_BGN + 499)

//����Ϣ�δ����ǰ汾��ֲ��������LDAP��ͻ���ݲ������
//MCU��Modem֮��ҵ��ӿ���Ϣ(37201-37300)
#define EV_MODEM_BGN                  (EV_DCSDCSGUARD_END + 1)
#define EV_MODEM_END                  (EV_DCSDCSGUARD_BGN + 99)

//���ݻ����ն�ҵ����Ϣ(37701-38200)
#define EV_DCMT_BGN                   (EV_LDAP_END + 1)
#define EV_DCMT_END                   (EV_DCMT_BGN + 499)

//VODҵ����Ϣ(38201-38300)
#define EV_VOD_BGN                    (EV_DCMT_END + 1)
#define EV_VOD_END                    (EV_VOD_BGN + 99)

//DCSMCUҵ����Ϣ(38301-38500)
#define EV_DCSMCU_BGN                 (EV_VOD_END + 1)
#define EV_DCSMCU_END                 (EV_DCSMCU_BGN + 199)

//mdsc hdsc watchdog ��Ϣ(38501-38600)
#define EV_DSCCONSOLE_BGN             (EV_DCSMCU_END + 1)
#define EV_DSCCONSOLE_END             (EV_DSCCONSOLE_BGN + 99)

//VMP ��Ϣ(38601-38700)
#define EV_VMP_BGN                    (EV_DSCCONSOLE_END + 1)
#define EV_VMP_END                    (EV_VMP_BGN + 99)

//PRS ��Ϣ(38701-38800)
#define EV_PRS_BGN                    (EV_VMP_END + 1)
#define EV_PRS_END                    (EV_PRS_BGN + 99)

//VMPTW ��Ϣ(38801-38900)
#define EV_VMPTW_BGN                  (EV_PRS_END + 1)
#define EV_VMPTW_END                  (EV_VMPTW_BGN + 99)

//MP ��Ϣ(38901-39000)
#define EV_MP_BGN                     (EV_VMPTW_END + 1)
#define EV_MP_END                     (EV_MP_BGN + 99)

//Radius�Ʒ�ҵ�� ��Ϣ(39001-39100)
#define EV_RS_BGN                     (EV_MP_END + 1)
#define EV_RS_END                     (EV_RS_BGN + 99)

//�ļ��������������豸(MCU/MT/����)ҵ����Ϣ(39101-39200)
#define EV_FILESRVDEV_BGN			  (EV_RS_END + 1)
#define EV_FILESRVDEV_END			  (EV_FILESRVDEV_BGN + 99)

//�ļ������������Ϳͻ���ҵ����Ϣ(39201-39400)
#define EV_SUSCLIENT_BGN		      (EV_FILESRVDEV_END + 1)
#define EV_SUSCLIENT_END			  (EV_SUSCLIENT_BGN + 199)

//SusSrv��SusMgrͨ����Ϣ(39401-39600)
#define EV_SUS_SUS_BGN                (EV_SUSCLIENT_END + 1)
#define EV_SUS_SUS_END                (EV_SUS_SUS_BGN + 199)

//mpuҵ����Ϣ���� ��Ϣ(39601-40000)
#define EV_MPU_BGN                    (EV_SUS_SUS_END + 1)
#define EV_MPU_END                    (EV_MPU_BGN + 399)

//MPSģ���ڲ���Ϣ(39701-39750)
#define EV_MPS_BGN                    39701
#define EV_MPS_END                    (EV_MPS_BGN + 49)
  
//MPSMPU������Ϣ(39801-39850)
#define EV_MPSMPU_BGN                 39801
#define EV_MPSMPU_END                 (EV_MPSMPU_BGN + 49)
	
//MPUSSN�ڲ���Ϣ(39851-39900)
#define EV_MPUSSN_BGN                 (EV_MPSMPU_END + 1)
#define EV_MPUSSN_END                 (EV_MPUSSN_BGN + 49)
		
//MPS��MCU������Ϣ(39951-40000)
#define EV_MPSMCU_BGN				  39951
#define EV_MPSMCU_END				  (EV_MPSMCU_BGN + 49)
		  
//TUIģ���ڲ���Ϣ(40001-40050)
#define EV_TUI_BGN                    (EV_MPSMCU_END + 1)
#define EV_TUI_END                    (EV_TUI_BGN + 49)
			
//TUI��MCU������Ϣ(40051-40100)
#define EV_TUIMCU_BGN                 (EV_TUI_END + 1)
#define EV_TUIMCU_END                 (EV_TUIMCU_BGN + 49)

//���÷������Ϳ���̨������Ϣ(40101-40150)
#define EV_SRVMCC_BGN                 (EV_TUIMCU_END + 1)
#define EV_SRVMCC_END                 (EV_SRVMCC_BGN + 49)

//LOG��־��¼ģ���ڲ���Ϣ(40151-40170) 
#define EV_LOG_BGN					  (EV_SRVMCC_END + 1)
#define EV_LOG_END					  (EV_LOG_BGN + 19)

//SA��ConnectSA��ͨ����Ϣ(40151-40180)
#define EV_SACSA_BGN                  (EV_SRVMCC_END + 1)
#define EV_SACSA_END                  (EV_SACSA_BGN + 29)

//SA-3ASSsn��3AS��ͨ����Ϣ(40261-40310)
#define EV_SA3AS_BGN                  40261
#define EV_SA3AS_END                  (EV_SA3AS_BGN + 49)

//SA-LgsSsn��Lgs��ͨ����Ϣ(40311-40360)
#define EV_SALGS_BGN                  (EV_SA3AS_END + 1)
#define EV_SALGS_END                  (EV_SALGS_BGN + 49)

//������ģ���SA��ͨ����Ϣ(40361-40410)
#define EV_MODULESA_BGN               (EV_SALGS_END + 1)
#define EV_MODULESA_END               (EV_MODULESA_BGN + 49)

//MTS��MCU��ͨ����Ϣ(40441-40470)
#define EV_MTSMCU_BGN				  40441
#define EV_MTSMCU_END				  (EV_MTSMCU_BGN + 29)

//LGS��SRV��ͨ����Ϣ(40541-40550)
#define EV_LGSSRV_BGN                 40541
#define EV_LGSSRV_END                 (EV_LGSSRV_BGN + 9)

//AudioAdapt��AduAdaptMgr���ڲ���Ϣ, AudioAdapt��AduAdaptMgr������Ϣ, Agw��AduAdaptMgr������Ϣ(40551-40600)
#define EV_SFACOM_BGN                 (EV_LGSSRV_END + 1)
#define EV_SFACOM_END                 (EV_SFACOM_BGN + 49)

//VCS��MCUͨ����Ϣ(40102-40301)        
#define EV_VCSVC_BGN                  40102
#define EV_VCSVS_END                  (EV_VCSVC_BGN + 199)

//8000E WATCHDOG��Ϣ(40302- 40401)
#define EV_WD8000E_BGN                (EV_VCSVS_END + 1)
#define EV_WD8000E_END                (EV_WD8000E_BGN + 99)

//pcdv2��MT֮��ӿ���Ϣ(40402-40600)
#define EV_MTPCDV2_BGN                (EV_WD8000E_END + 1)
#define EV_MTPCDV2_END                (EV_MTPCDV2_BGN + 198)

//�ļ�������Ϣ(40601-40620)
#define EV_FILETRANSF_BGN			  (EV_MTPCDV2_END + 1)
#define EV_FILETRANSF_END			  (EV_FILETRANSF_BGN + 19)

//�ļ��������ϲ�ҵ������Ϣ(40621-40640)
#define EV_FTLIBFEEDBACK_BGN		  (EV_FILETRANSF_END + 1)
#define	EV_FTLIBFEEDBACK_END		  (EV_FTLIBFEEDBACK_BGN + 19)


//FIXME: �����ǰ汾��ֲ��������NMC������Ϣ�г�ͻ���������
// MT ����������ͨ����Ϣ������ϵͳ�ɵ������ṩ���ɸ��ģ�����Ϣ��Χ�� 50200��502300*/
#define EV_SATMTNMS_BGN               50200
#define EV_SATMTNMS_END               50300

// MCU����������ͨ����Ϣ������ϵͳ�ɵ������ṩ���ɸ��ģ�����Ϣ��Χ�� 50400��50500*/
#define EV_SATMCUNMS_BGN              51100
#define EV_SATMCUNMS_END              51200	

//MCU������Ϣ(52501-53500)
#define EV_TEST_MCU_BGN               52501
#define EV_TEST_MCU_END               (EV_TEST_MCU_BGN + 999)

//RECORDER������Ϣ(54501-54700)
#define EV_TEST_REC_BGN               54501
#define EV_TEST_REC_END               (EV_TEST_REC_BGN + 199)

//������������Ϣ(54701-54900)
#define EV_TEST_MIXER_BGN             (EV_TEST_REC_END + 1)
#define EV_TEST_MIXER_END             (EV_TEST_MIXER_BGN + 199)


#define EV_KDM_BASE                   50000

//3AC�ڲ���Ϣ(50001-51000)
#define EV_3AC_BGN                    (EV_KDM_BASE + 1)
#define EV_3AC_END                    (EV_3AC_BGN + 999)

//3AS�ڲ���Ϣ(51001-52000)
#define EV_3AS_BGN                    (EV_3AC_END + 1)
#define EV_3AS_END                    (EV_3AS_BGN + 999)

//////////////////////////////////////////////////////////////////////////
//  ��ģ�����Ϣ
//3AC��3AS�ӿ���Ϣ(52001-53000)
#define EV_3AC_3AS_BGN                (EV_3AS_END + 1)
#define EV_3AC_3AS_END                (EV_3AC_3AS_BGN + 999)

//srv��3AS�ӿ���Ϣ(53001-53200)
#define EV_SRV_3AS_BGN                (EV_3AC_3AS_END + 1)
#define EV_SRV_3AS_END                (EV_SRV_3AS_BGN + 199)

//MCU��3AS�ӿ���Ϣ(53201-53400)
#define EV_MCU_3AS_BGN                (EV_SRV_3AS_END + 1)
#define EV_MCU_3AS_END                (EV_MCU_3AS_BGN + 199)

//DMS��3AS�ӿ���Ϣ(53401-53500)
#define EV_DMS_3AS_BGN                (EV_MCU_3AS_END + 1)
#define EV_DMS_3AS_END                (EV_DMS_3AS_BGN + 99)

//DMS��MT��ͨ����Ϣ(53501-56500)
#define EV_DMS_MT_BGN                 (EV_DMS_3AS_END + 1)
#define EV_DMS_MT_END                 (EV_DMS_MT_BGN + 2999)

//DMS��NMS��ͨ����Ϣ(56501-56600)
#define EV_DMS_NMS_BGN                (EV_DMS_MT_END + 1)
#define EV_DMS_NMS_END                (EV_DMS_NMS_BGN + 99)

//DMS�ڲ�ͨ����Ϣ(56601-56000)
#define EV_DMS_DMS_BGN                (EV_DMS_NMS_END + 1)
#define EV_DMS_DMS_END                (EV_DMS_DMS_BGN + 399)

//AGW��3AS�ӿ���Ϣ(55001-55100)
#define EV_AGW_3AS_BGN                (EV_DMS_DMS_END + 1)
#define EV_AGW_3AS_END                (EV_AGW_3AS_BGN + 99)

//ULS��3AS��ͨ����Ϣ (55101-55170)
#define EV_ULS_3AS_BGN				  (EV_AGW_3AS_END + 1)
#define EV_ULS_3AS_END				  (EV_ULS_3AS_BGN + 69)

//ULC��ULS��ͨ����Ϣ (55171-55200)
#define EV_ULC_ULS_BGN				  (EV_ULS_3AS_END + 1)
#define EV_ULC_ULS_END				  (EV_ULC_ULS_BGN + 29)

//ULC�ڲ�ͨ����Ϣ (55201-55210)
#define EV_ULC_ULC_BGN				  (EV_ULC_ULS_END + 1)
#define EV_ULC_ULC_END				  (EV_ULC_ULC_BGN + 9)

//NMA��3AS��ͨ����Ϣ (55211-55220)
#define EV_NMA_3AS_BGN                (EV_ULC_ULC_END + 1)
#define EV_NMA_3AS_END                (EV_NMA_3AS_BGN + 9)

//NMA�ڲ�ͨ����Ϣ (55221-55240)
#define EV_NMA_NMA_BGN                (EV_NMA_3AS_END + 1)
#define EV_NMA_NMA_END                (EV_NMA_NMA_BGN + 19)

//DMA��3AS��ͨ����Ϣ (55241-55250)
#define EV_DMA_3AS_BGN                (EV_NMA_NMA_END + 1)
#define EV_DMA_3AS_END                (EV_DMA_3AS_BGN + 19)

//DMA�ڲ�ͨ����Ϣ  (55251-55260)
#define EV_DMA_DMA_BGN                (EV_DMA_3AS_END + 1)
#define EV_DMA_DMA_END                (EV_DMA_DMA_BGN + 9)

//MPCD��3ASͨ����Ϣ (55261-55300)
#define	EV_MPCD_3AS_BGN				  (EV_DMA_DMA_END + 1)
#define	EV_MPCD_3AS_END				  (EV_MPCD_3AS_BGN + 49)

//H323GW��Ϣ����(55301 - 55500)
#define H323GWOSPEVENT_START          55301
#define H323GWOSPEVENT_END            (H323GWOSPEVENT_START + 199)

#define EV_H323GW_3AS_BGN			  (H323GWOSPEVENT_END + 1)
#define EV_H323GW_3AS_END			  (EV_H323GW_3AS_BGN + 99)

//SUS��3ASͨ����Ϣ (55601-55650) 
#define	EV_SUS_3AS_BGN				  (EV_H323GW_3AS_END + 1)
#define	EV_SUS_3AS_END				  (EV_SUS_3AS_BGN + 49)

//OCS��MOSͨ����Ϣ (55651-55700) 
#define	EV_OCS_MOS_BGN				  (EV_SUS_3AS_END + 1)
#define	EV_OCS_MOS_END				  (EV_OCS_MOS_BGN + 49)

//NTS��Ϣ����(55701-55750)
#define EV_NTS_BGN                    (EV_OCS_MOS_END + 1)
#define EV_NTS_END                    (EV_NTS_BGN + 49)

//CPAdapt��Ϣ����(55751-55800)
#define EV_CPADAPT_BGN                (EV_NTS_END + 1)
#define EV_CPADAPT_END                (EV_CPADAPT_BGN + 49)

//capdapt��mpcd֮�����Ϣ����(55801-55810)
#define MPCD_CPADAPT_EVENT_BGN        (EV_CPADAPT_END + 1)
#define MPCD_CPADAPT_EVENT_END        (MPCD_CPADAPT_EVENT_BGN + 9)

//srv��SCCͨ����Ϣ����(55811-55840)
#define EV_SRV_SCC_BGN                (MPCD_CPADAPT_EVENT_END + 1) 
#define EV_SRV_SCC_END                (EV_SRV_SCC_BGN + 29)

//SM�����ܷ������ӿ���Ϣ(56001-57000)
#define EV_SM_NMS_BGN                 56001
#define EV_SM_NMS_END                 (EV_SM_NMS_BGN + 999)

//SM�����ܿͻ��˽ӿ���Ϣ(57001-57500)
#define EV_SM_NMC_BGN                 (EV_SM_NMS_END + 1) 
#define EV_SM_NMC_END                 (EV_SM_NMC_BGN + 499)

// mtctrl ��Ϣ*/
#define EV_MTCTRL_BEG                 60000
#define EV_MTCTRL_END                 (EV_MTCTRL_BEG + 999)

//NV�ڲ�ҵ����Ϣ(61000-62000)
#define EV_NV_BGN                     (EV_MTCTRL_END + 1)
#define EV_NV_END                     (EV_NV_BGN + 999)

#endif // _EVENT_ID_H_ 

