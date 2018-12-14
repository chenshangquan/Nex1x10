#ifndef _NVBLLUPGRADSERVEREMSG_H_
#define _NVBLLUPGRADESERVERMSG_H_

#include "nvmsgid.h"
#include "nvenum.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLUpgradeServerMsg
{
    EV_BLL_BGN(UPGRADESERVER) = EVSEG_BLL_UPGRADESERVER_BGN,
#endif
	
	/*<<远端向升级服务器发出登录请求>>
	*nv::TNVLocalDevInfo      远端版本信息
	* sdk->upgradeserver 
	*/
    MESSAGE(ev_NV_BLL_CnLogin_UpdateSer_Req)
	BODY(nv::TNVLocalDevInfo, verinfo) 
	
	/*<<远端主动发出升级请求>>
	*nv::TNVLocalDevInfo      远端版本信息
	* sdk->upgradeserver 
	*/
    MESSAGE(ev_NV_BLL_UpdateSystem_Req)
	BODY(nv::TNVLocalDevInfo, verinfo) 
	
	/*<<远端收到升级服务器请求登录的回复消息>>
	**nv::TS32 登录是否成功
	* upgradeserver -> sdk 
	*/
    MESSAGE(ev_NV_BLL_CnLogin_UpdateSer_Rsp)
	BODY(nv::TS32, result) 
	
	
	/*<<远端收到升级服务器发送的升级回应消息>>
	*nv::TNVDevUpgrade 远端版本信息
	* upgradeserver -> sdk 
	*/
    MESSAGE(ev_NV_BLL_UpdateSystem_Rsp)
	BODY(nv::TNVDevUpgrade, devlist) 
	BODY(nv::TNVDevUpgrade, devlist2)
	
	/*<<远端收到升级服务器发出的通知升级消息>>
	*nv::TNVDevUpgrade 远端版本信息
	* upgradeserver -> sdk
	*/
    MESSAGE(ev_NV_BLL_UpdateSystem_Nty)
	BODY(nv::TNVDevUpgrade, devlist) 
	BODY(nv::TNVDevUpgrade, devlist2)
	
	/*<<无线投屏收到升级服务器发出的通知升级消息>>
	*nv::TNVDevUpgrade 远端版本信息
	* upgradeserver -> sdk
	*/
    MESSAGE(ev_NV_BLL_UpdateSystem2QuickShare_Nty)
	BODY(nv::TNVDevUpgrade, tDevUpgrade) 
	
	/*<<命令reload 加载本地配置文件>>
	* upgradeserver -> upgradeserver
	*/
    MESSAGE(ev_NV_BLL_ReloadCfg_Req)

	/*<<无配置文件提醒>>
	*nv::TNVDevUpgrade 远端版本信息
	* upgradeserver -> sdk 
	*/
    MESSAGE(ev_NV_BLL_NoConfig_Nty)	
	BODY(nv::TS32, tType)
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(UPGRADESERVER) = EVSEG_BLL_UPGRADESERVER_END
};
#endif

#define Is_BLL_UpdradeServer_Msg(m) ((m) >= EV_BLL_BGN(UPGRADESERVER) && (m) <= EV_BLL_END(UPGRADESERVER))

#endif // _NVUPGRADEMSG_H_