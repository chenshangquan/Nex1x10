/*****************************************************************************
   模块名      : KDV system
   文件名      : eventid.h
   相关文件    : 
   文件实现功能: KDV事件号统一划分
   作者        : 李屹
   版本        : V0.9  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   修改记录:
   日  期      版本        修改人      修改内容
   2002/03/01  0.9         李屹        创建
   2004/03/11  3.0         魏治兵      增加地址簿消息
   2005/12/26  4.0	       zhangsh     增加DCS与MCU通讯消息
   2013/11/07  5.0         ruiyigen    行业企业头文件整合
******************************************************************************/
#ifndef _EVENT_ID_H_
#define _EVENT_ID_H_

#define EV_EVENT_BASE                  4000

//内部消息区间(4000-9999)
#define EV_INNER_BGN                   EV_EVENT_BASE
#define EV_INNER_END                   (EV_INNER_BGN + 5999)

//agw 内部消息(4001-4100)
#define EV_AGW_BGN                     (EV_INNER_BGN + 1)
#define EV_AGW_END                     (EV_AGW_BGN + 99)

//mtadp 内部消息(4051-4100)
// #define EV_MTADP_BGN                   (EV_AGW_END + 1)
// #define EV_MTADP_END                   (EV_MTADP_BGN + 49)

//文件升级服务器内部消息(4101-4250)
#define EV_SUS_BGN		               (EV_AGW_END + 1)
#define EV_SUS_END		               (EV_SUS_BGN + 149)

//SA内部通信消息(4251-4300)
#define EV_SA_BGN                      (EV_SUS_END + 1)
#define EV_SA_END                      (EV_SA_BGN + 49)

//CONNECTSA内部通信消息(4301-4320)
#define EV_CONNECTSA_BGN               (EV_SA_END + 1)
#define EV_CONNECTSA_END               (EV_CONNECTSA_BGN + 19)

//MTS模块内部消息(4321-4340)
#define EV_MTS_BGN                     (EV_CONNECTSA_END + 1)
#define EV_MTS_END                     (EV_MTS_BGN + 19)

//LGS模块内部消息(4341-4360)
#define EV_LGS_BGN                     (EV_MTS_END + 1)
#define EV_LGS_END                     (EV_LGS_BGN + 19)

//ZyGuard内部消息(4361-4370)
#define EV_ZYGUARD_BGN                 (EV_LGS_END + 1)
#define EV_ZYGUARD_END                 (EV_ZYGUARD_BGN  + 9)




#define EV_KDV_BASE                    10000

//网管客户端内部消息(10001-11000)
#define EV_NMC_BGN                     (EV_KDV_BASE + 1)
#define EV_NMC_END                     (EV_NMC_BGN + 999)

//网管客户端内部消息(10001-11000) 重定义名称，编译考虑
#define EV_CLT_BGN                     EV_NMC_BGN
#define EV_CLT_END                     EV_NMC_END

//会议控制台内部消息(11001-12000)
#define EV_MC_BGN                      (EV_NMC_END + 1)
#define EV_MC_END                      (EV_MC_BGN + 999)

//终端控制台内部消息(12001-13000)
#define EV_MTC_BGN                     (EV_MC_END + 1)
#define EV_MTC_END                     (EV_MTC_BGN + 999)

//网管客户端服务器接口消息(13001-14000)
#define EV_NMC_NMS_BGN                 (EV_MTC_END + 1)
#define EV_NMC_NMS_END                 (EV_NMC_NMS_BGN + 999)

//网管客户端服务器接口消息(13001-14000) 重定义名称，编译考虑
#define EV_CLTSVR_BGN                  EV_NMC_NMS_BGN
#define EV_CLTSVR_END                  EV_NMC_NMS_END

//网管服务器内部消息(14001-15000)
#define EV_NMS_BGN                    (EV_NMC_NMS_END + 1)
#define EV_NMS_END                    (EV_NMS_BGN + 999)

//网管服务器代理接口消息(15001-17000)
#define EV_DEVAGT_NMS_BGN             (EV_NMS_END + 1)
#define EV_DEVAGT_NMS_END             (EV_DEVAGT_NMS_BGN + 1999)

//2010/06/02刘晓静添加，网管服务器与3AS接口消息(17001-18000)
#define EV_NMS_3AS_BGN                (EV_DEVAGT_NMS_END + 1)
#define EV_NMS_3AS_END                (EV_NMS_3AS_BGN + 999)

//代理内部消息(18001-20000)
#define EV_AGT_BGN                    (EV_NMS_3AS_END + 1)
#define EV_AGT_END                    (EV_AGT_BGN + 1999)

//代理和业务接口消息(20001-22000)
#define EV_AGTSVC_BGN                 (EV_AGT_END + 1)
#define EV_AGTSVC_END                 (EV_AGTSVC_BGN + 1999)

//会议控制台和MCU业务接口消息(22001-23000)
#define EV_MCSVC_BGN                  (EV_AGTSVC_END + 1)
#define EV_MCSVC_END                  (EV_MCSVC_BGN + 999)

//终端控制台和MT业务接口消息(23001-24000)
#define EV_MTCSVC_BGN                 (EV_MCSVC_END + 1)
#define EV_MTCSVC_END                 (EV_MTCSVC_BGN + 999)

//MCU和MT间业务接口消息(25001-26000)
#define EV_MCUMT_BGN                  (EV_MTCSVC_END + 1001)
#define EV_MCUMT_END                  (EV_MCUMT_BGN + 999)

//MCU和外设间业务接口消息(26001-27000)
#define EV_MCUEQP_BGN                 (EV_MCUMT_END + 1)
#define EV_MCUEQP_END                 (EV_MCUEQP_BGN + 999)

//MPC与MPCD通信消息(27001-27130)
#define	EV_MPC_MPCD_BGN				  (EV_MCUEQP_END + 1)
#define	EV_MPC_MPCD_END				  (EV_MPC_MPCD_BGN + 129)

//AGW和MPCD通信消息(27131-27170)
#define EV_AGW_MPCD_BGN               (EV_MPC_MPCD_END + 1)
#define EV_AGW_MPCD_END               (EV_AGW_MPCD_BGN + 39)

//MPU和外设交互消息(27171-27270)
#define EV_MPUEQP_BGN				  (EV_AGW_MPCD_END + 1)
#define EV_MPUEQP_END				  (EV_MPUEQP_BGN + 99)

//MPS和MCU交互消息(27271-27470)
#define EV_MPUMCU_BGN				  (EV_MPUEQP_END + 1)
#define EV_MPUMCU_END				  (EV_MPUMCU_BGN + 199)

//MCU内部业务消息(28001-29000)*/
#define EV_MCU_BGN                    28001
#define EV_MCU_END                    (EV_MCU_BGN + 999)

//MT内部业务消息(29001-30000)
#define EV_MT_BGN                     (EV_MCU_END + 1)
#define EV_MT_END                     (EV_MT_BGN + 999)

//RECORDER内部业务消息(30001-30200)
#define EV_REC_BGN                    (EV_MT_END + 1)
#define EV_REC_END                    (EV_REC_BGN + 199)

//混音器内部业务消息(30201-30400)
#define EV_MIXER_BGN                  (EV_REC_END + 1)
#define EV_MIXER_END                  (EV_MIXER_BGN + 199)

//电视墙内部业务消息(30401-30500)
#define EV_TVWALL_BGN                 (EV_MIXER_END + 1)
#define EV_TVWALL_END                 (EV_TVWALL_BGN + 99)

//HDU内部业务消息(30501-30600)
#define EV_HDU_BGN                    (EV_TVWALL_END + 1)
#define EV_HDU_END                    (EV_HDU_BGN + 99)

//MP 消息(30601-30700)
#define EV_MCUMP_BGN                  (EV_HDU_END + 1)
#define EV_MCUMP_END                  (EV_MCUMP_BGN + 99)

//码率适配服务器内部业务消息(30701-30800)
#define EV_BAS_BGN                    (EV_MCUMP_END + 1)
#define EV_BAS_END                    (EV_BAS_BGN + 99)

//网守消息定义(30801 - 33900)
#define GKOSPEVENT_START              (EV_BAS_END + 1)
#define GKOSPEVENT_END                (GKOSPEVENT_START + 3099)

//modify by zhanghb 100609 GK的消息范围中划分出与3AS通信的消息号(33901 - 34900)
#define GK_3AS_EVENT_START            (GKOSPEVENT_END + 1)
#define GK_3AS_EVENT_END              (GK_3AS_EVENT_START + 999)

//会控和MPCD消息定义(34901-35050)
#define MPCD_MCC_EVENT_START          (GK_3AS_EVENT_END + 1)  
#define MPCD_MCC_EVENT_END            (MPCD_MCC_EVENT_START + 149)

// MPC与MMPU消息定义(35051-35070)
#define MMPU_MPC_EVENT_START          (MPCD_MCC_EVENT_END + 1)
#define MMPU_MPC_EVENT_END            (MMPU_MPC_EVENT_START + 19)

// MPU与MMPU消息定义(35071-35090)
#define MMPU_MPU_EVENT_START          (MMPU_MPC_EVENT_END + 1)
#define MMPU_MPU_EVENT_END            (MMPU_MPU_EVENT_START + 19)

// MPCD与MMPU消息定义(35091-35100)
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

//用户管理消息定义(34901 - 35000)
#define EV_UM_BGN                     34901
#define EV_UM_END                     (EV_UM_BGN + 99)

//地址簿消息定义(35001 - 35100)
#define EV_ADDRBOOK_BGN               (EV_UM_END + 1)
#define EV_ADDRBOOK_END               (EV_ADDRBOOK_BGN + 99)

//VAS消息定义(35101-36100)
#define EV_VAS_BGN                    (EV_ADDRBOOK_END + 1)
#define EV_VAS_END                    (EV_VAS_BGN + 999)

//RAS消息定义(36101-36200)
#define EV_RAS_BGN                    (EV_VAS_END + 1)
#define EV_RAS_END                    (EV_RAS_BGN + 99)

//DCServer和DCConsole之间业务接口消息(36201-37000)
#define EV_DCSDCC_BGN                 (EV_RAS_END + 1)
#define EV_DCSDCC_END                 (EV_DCSDCC_BGN + 799)

//MT外设控制消息(37001-37100)
#define EV_MTDEV_BGN                  (EV_DCSDCC_END + 1)
#define EV_MTDEV_END                  (EV_MTDEV_BGN + 99)

//DCServer和DCSGuard之间业务接口消息(37101-37200)
#define EV_DCSDCSGUARD_BGN            (EV_MTDEV_END + 1)
#define EV_DCSDCSGUARD_END            (EV_DCSDCSGUARD_BGN + 99)

//目录服务的业务消息(37201-37700)
#define EV_LDAP_BGN                   (EV_DCSDCSGUARD_END + 1)
#define EV_LDAP_END                   (EV_LDAP_BGN + 499)

//本消息段从卫星版本移植过来，与LDAP冲突，暂不予理睬
//MCU和Modem之间业务接口消息(37201-37300)
#define EV_MODEM_BGN                  (EV_DCSDCSGUARD_END + 1)
#define EV_MODEM_END                  (EV_DCSDCSGUARD_BGN + 99)

//数据会议终端业务消息(37701-38200)
#define EV_DCMT_BGN                   (EV_LDAP_END + 1)
#define EV_DCMT_END                   (EV_DCMT_BGN + 499)

//VOD业务消息(38201-38300)
#define EV_VOD_BGN                    (EV_DCMT_END + 1)
#define EV_VOD_END                    (EV_VOD_BGN + 99)

//DCSMCU业务消息(38301-38500)
#define EV_DCSMCU_BGN                 (EV_VOD_END + 1)
#define EV_DCSMCU_END                 (EV_DCSMCU_BGN + 199)

//mdsc hdsc watchdog 消息(38501-38600)
#define EV_DSCCONSOLE_BGN             (EV_DCSMCU_END + 1)
#define EV_DSCCONSOLE_END             (EV_DSCCONSOLE_BGN + 99)

//VMP 消息(38601-38700)
#define EV_VMP_BGN                    (EV_DSCCONSOLE_END + 1)
#define EV_VMP_END                    (EV_VMP_BGN + 99)

//PRS 消息(38701-38800)
#define EV_PRS_BGN                    (EV_VMP_END + 1)
#define EV_PRS_END                    (EV_PRS_BGN + 99)

//VMPTW 消息(38801-38900)
#define EV_VMPTW_BGN                  (EV_PRS_END + 1)
#define EV_VMPTW_END                  (EV_VMPTW_BGN + 99)

//MP 消息(38901-39000)
#define EV_MP_BGN                     (EV_VMPTW_END + 1)
#define EV_MP_END                     (EV_MP_BGN + 99)

//Radius计费业务 消息(39001-39100)
#define EV_RS_BGN                     (EV_MP_END + 1)
#define EV_RS_END                     (EV_RS_BGN + 99)

//文件升级服务器和设备(MCU/MT/单板)业务消息(39101-39200)
#define EV_FILESRVDEV_BGN			  (EV_RS_END + 1)
#define EV_FILESRVDEV_END			  (EV_FILESRVDEV_BGN + 99)

//文件升级服务器和客户端业务消息(39201-39400)
#define EV_SUSCLIENT_BGN		      (EV_FILESRVDEV_END + 1)
#define EV_SUSCLIENT_END			  (EV_SUSCLIENT_BGN + 199)

//SusSrv与SusMgr通信消息(39401-39600)
#define EV_SUS_SUS_BGN                (EV_SUSCLIENT_END + 1)
#define EV_SUS_SUS_END                (EV_SUS_SUS_BGN + 199)

//mpu业务消息分配 消息(39601-40000)
#define EV_MPU_BGN                    (EV_SUS_SUS_END + 1)
#define EV_MPU_END                    (EV_MPU_BGN + 399)

//MPS模块内部消息(39701-39750)
#define EV_MPS_BGN                    39701
#define EV_MPS_END                    (EV_MPS_BGN + 49)
  
//MPSMPU交互消息(39801-39850)
#define EV_MPSMPU_BGN                 39801
#define EV_MPSMPU_END                 (EV_MPSMPU_BGN + 49)
	
//MPUSSN内部消息(39851-39900)
#define EV_MPUSSN_BGN                 (EV_MPSMPU_END + 1)
#define EV_MPUSSN_END                 (EV_MPUSSN_BGN + 49)
		
//MPS和MCU交互消息(39951-40000)
#define EV_MPSMCU_BGN				  39951
#define EV_MPSMCU_END				  (EV_MPSMCU_BGN + 49)
		  
//TUI模块内部消息(40001-40050)
#define EV_TUI_BGN                    (EV_MPSMCU_END + 1)
#define EV_TUI_END                    (EV_TUI_BGN + 49)
			
//TUI和MCU交互消息(40051-40100)
#define EV_TUIMCU_BGN                 (EV_TUI_END + 1)
#define EV_TUIMCU_END                 (EV_TUIMCU_BGN + 49)

//外置服务器和控制台交互消息(40101-40150)
#define EV_SRVMCC_BGN                 (EV_TUIMCU_END + 1)
#define EV_SRVMCC_END                 (EV_SRVMCC_BGN + 49)

//LOG日志记录模块内部消息(40151-40170) 
#define EV_LOG_BGN					  (EV_SRVMCC_END + 1)
#define EV_LOG_END					  (EV_LOG_BGN + 19)

//SA和ConnectSA的通信消息(40151-40180)
#define EV_SACSA_BGN                  (EV_SRVMCC_END + 1)
#define EV_SACSA_END                  (EV_SACSA_BGN + 29)

//SA-3ASSsn和3AS的通信消息(40261-40310)
#define EV_SA3AS_BGN                  40261
#define EV_SA3AS_END                  (EV_SA3AS_BGN + 49)

//SA-LgsSsn和Lgs的通信消息(40311-40360)
#define EV_SALGS_BGN                  (EV_SA3AS_END + 1)
#define EV_SALGS_END                  (EV_SALGS_BGN + 49)

//服务器模块和SA的通信消息(40361-40410)
#define EV_MODULESA_BGN               (EV_SALGS_END + 1)
#define EV_MODULESA_END               (EV_MODULESA_BGN + 49)

//MTS和MCU的通信消息(40441-40470)
#define EV_MTSMCU_BGN				  40441
#define EV_MTSMCU_END				  (EV_MTSMCU_BGN + 29)

//LGS与SRV的通信消息(40541-40550)
#define EV_LGSSRV_BGN                 40541
#define EV_LGSSRV_END                 (EV_LGSSRV_BGN + 9)

//AudioAdapt、AduAdaptMgr的内部消息, AudioAdapt、AduAdaptMgr交互消息, Agw和AduAdaptMgr交互消息(40551-40600)
#define EV_SFACOM_BGN                 (EV_LGSSRV_END + 1)
#define EV_SFACOM_END                 (EV_SFACOM_BGN + 49)

//VCS和MCU通信消息(40102-40301)        
#define EV_VCSVC_BGN                  40102
#define EV_VCSVS_END                  (EV_VCSVC_BGN + 199)

//8000E WATCHDOG消息(40302- 40401)
#define EV_WD8000E_BGN                (EV_VCSVS_END + 1)
#define EV_WD8000E_END                (EV_WD8000E_BGN + 99)

//pcdv2和MT之间接口消息(40402-40600)
#define EV_MTPCDV2_BGN                (EV_WD8000E_END + 1)
#define EV_MTPCDV2_END                (EV_MTPCDV2_BGN + 198)

//文件传输消息(40601-40620)
#define EV_FILETRANSF_BGN			  (EV_MTPCDV2_END + 1)
#define EV_FILETRANSF_END			  (EV_FILETRANSF_BGN + 19)

//文件传输向上层业务反馈消息(40621-40640)
#define EV_FTLIBFEEDBACK_BGN		  (EV_FILETRANSF_END + 1)
#define	EV_FTLIBFEEDBACK_END		  (EV_FTLIBFEEDBACK_BGN + 19)


//FIXME: 从卫星版本移植过来，与NMC测试消息有冲突，不予理睬
// MT 与卫星网管通信消息，网管系统由第三方提供不可更改，其消息范围在 50200－502300*/
#define EV_SATMTNMS_BGN               50200
#define EV_SATMTNMS_END               50300

// MCU与卫星网管通信消息，网管系统由第三方提供不可更改，其消息范围在 50400－50500*/
#define EV_SATMCUNMS_BGN              51100
#define EV_SATMCUNMS_END              51200	

//MCU测试消息(52501-53500)
#define EV_TEST_MCU_BGN               52501
#define EV_TEST_MCU_END               (EV_TEST_MCU_BGN + 999)

//RECORDER测试消息(54501-54700)
#define EV_TEST_REC_BGN               54501
#define EV_TEST_REC_END               (EV_TEST_REC_BGN + 199)

//混音器测试消息(54701-54900)
#define EV_TEST_MIXER_BGN             (EV_TEST_REC_END + 1)
#define EV_TEST_MIXER_END             (EV_TEST_MIXER_BGN + 199)


#define EV_KDM_BASE                   50000

//3AC内部消息(50001-51000)
#define EV_3AC_BGN                    (EV_KDM_BASE + 1)
#define EV_3AC_END                    (EV_3AC_BGN + 999)

//3AS内部消息(51001-52000)
#define EV_3AS_BGN                    (EV_3AC_END + 1)
#define EV_3AS_END                    (EV_3AS_BGN + 999)

//////////////////////////////////////////////////////////////////////////
//  各模块间消息
//3AC与3AS接口消息(52001-53000)
#define EV_3AC_3AS_BGN                (EV_3AS_END + 1)
#define EV_3AC_3AS_END                (EV_3AC_3AS_BGN + 999)

//srv与3AS接口消息(53001-53200)
#define EV_SRV_3AS_BGN                (EV_3AC_3AS_END + 1)
#define EV_SRV_3AS_END                (EV_SRV_3AS_BGN + 199)

//MCU与3AS接口消息(53201-53400)
#define EV_MCU_3AS_BGN                (EV_SRV_3AS_END + 1)
#define EV_MCU_3AS_END                (EV_MCU_3AS_BGN + 199)

//DMS与3AS接口消息(53401-53500)
#define EV_DMS_3AS_BGN                (EV_MCU_3AS_END + 1)
#define EV_DMS_3AS_END                (EV_DMS_3AS_BGN + 99)

//DMS与MT的通信消息(53501-56500)
#define EV_DMS_MT_BGN                 (EV_DMS_3AS_END + 1)
#define EV_DMS_MT_END                 (EV_DMS_MT_BGN + 2999)

//DMS与NMS的通信消息(56501-56600)
#define EV_DMS_NMS_BGN                (EV_DMS_MT_END + 1)
#define EV_DMS_NMS_END                (EV_DMS_NMS_BGN + 99)

//DMS内部通信消息(56601-56000)
#define EV_DMS_DMS_BGN                (EV_DMS_NMS_END + 1)
#define EV_DMS_DMS_END                (EV_DMS_DMS_BGN + 399)

//AGW与3AS接口消息(55001-55100)
#define EV_AGW_3AS_BGN                (EV_DMS_DMS_END + 1)
#define EV_AGW_3AS_END                (EV_AGW_3AS_BGN + 99)

//ULS与3AS的通信消息 (55101-55170)
#define EV_ULS_3AS_BGN				  (EV_AGW_3AS_END + 1)
#define EV_ULS_3AS_END				  (EV_ULS_3AS_BGN + 69)

//ULC与ULS的通信消息 (55171-55200)
#define EV_ULC_ULS_BGN				  (EV_ULS_3AS_END + 1)
#define EV_ULC_ULS_END				  (EV_ULC_ULS_BGN + 29)

//ULC内部通信消息 (55201-55210)
#define EV_ULC_ULC_BGN				  (EV_ULC_ULS_END + 1)
#define EV_ULC_ULC_END				  (EV_ULC_ULC_BGN + 9)

//NMA与3AS的通信消息 (55211-55220)
#define EV_NMA_3AS_BGN                (EV_ULC_ULC_END + 1)
#define EV_NMA_3AS_END                (EV_NMA_3AS_BGN + 9)

//NMA内部通信消息 (55221-55240)
#define EV_NMA_NMA_BGN                (EV_NMA_3AS_END + 1)
#define EV_NMA_NMA_END                (EV_NMA_NMA_BGN + 19)

//DMA与3AS的通信消息 (55241-55250)
#define EV_DMA_3AS_BGN                (EV_NMA_NMA_END + 1)
#define EV_DMA_3AS_END                (EV_DMA_3AS_BGN + 19)

//DMA内部通信消息  (55251-55260)
#define EV_DMA_DMA_BGN                (EV_DMA_3AS_END + 1)
#define EV_DMA_DMA_END                (EV_DMA_DMA_BGN + 9)

//MPCD与3AS通信消息 (55261-55300)
#define	EV_MPCD_3AS_BGN				  (EV_DMA_DMA_END + 1)
#define	EV_MPCD_3AS_END				  (EV_MPCD_3AS_BGN + 49)

//H323GW消息定义(55301 - 55500)
#define H323GWOSPEVENT_START          55301
#define H323GWOSPEVENT_END            (H323GWOSPEVENT_START + 199)

#define EV_H323GW_3AS_BGN			  (H323GWOSPEVENT_END + 1)
#define EV_H323GW_3AS_END			  (EV_H323GW_3AS_BGN + 99)

//SUS与3AS通信消息 (55601-55650) 
#define	EV_SUS_3AS_BGN				  (EV_H323GW_3AS_END + 1)
#define	EV_SUS_3AS_END				  (EV_SUS_3AS_BGN + 49)

//OCS与MOS通信消息 (55651-55700) 
#define	EV_OCS_MOS_BGN				  (EV_SUS_3AS_END + 1)
#define	EV_OCS_MOS_END				  (EV_OCS_MOS_BGN + 49)

//NTS消息定义(55701-55750)
#define EV_NTS_BGN                    (EV_OCS_MOS_END + 1)
#define EV_NTS_END                    (EV_NTS_BGN + 49)

//CPAdapt消息定义(55751-55800)
#define EV_CPADAPT_BGN                (EV_NTS_END + 1)
#define EV_CPADAPT_END                (EV_CPADAPT_BGN + 49)

//capdapt与mpcd之间的消息定义(55801-55810)
#define MPCD_CPADAPT_EVENT_BGN        (EV_CPADAPT_END + 1)
#define MPCD_CPADAPT_EVENT_END        (MPCD_CPADAPT_EVENT_BGN + 9)

//srv与SCC通信消息定义(55811-55840)
#define EV_SRV_SCC_BGN                (MPCD_CPADAPT_EVENT_END + 1) 
#define EV_SRV_SCC_END                (EV_SRV_SCC_BGN + 29)

//SM和网管服务器接口消息(56001-57000)
#define EV_SM_NMS_BGN                 56001
#define EV_SM_NMS_END                 (EV_SM_NMS_BGN + 999)

//SM和网管客户端接口消息(57001-57500)
#define EV_SM_NMC_BGN                 (EV_SM_NMS_END + 1) 
#define EV_SM_NMC_END                 (EV_SM_NMC_BGN + 499)

// mtctrl 消息*/
#define EV_MTCTRL_BEG                 60000
#define EV_MTCTRL_END                 (EV_MTCTRL_BEG + 999)

//NV内部业务消息(61000-62000)
#define EV_NV_BGN                     (EV_MTCTRL_END + 1)
#define EV_NV_END                     (EV_NV_BGN + 999)

#endif // _EVENT_ID_H_ 

