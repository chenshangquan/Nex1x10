#if !defined(_NVSERVICEHELP_H_)
#define _NVSERVICEHELP_H_
#include "osp.h"

//////////////////////////////////////////////////////////////////////////
enum EmNvserviceDumpEvent
{
	dump_showconfinfo = 0,
	dump_nvservice_ShowLastEvent = 99,
};

/**----------------------------------------------------------------------
* nvserviceregcmd
* 
* @brief   注册osp调试命令
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvserviceregcmd();

/**----------------------------------------------------------------------
* nvservicehelp
* 
* @brief   service模块命令帮助
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvservicehelp();

/**----------------------------------------------------------------------
* nvservicever
* 
* @brief   service版本号显示
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvservicever();

/**----------------------------------------------------------------------
* nvconfshow
* 
* @brief   service显示会议状态和选看的画面
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvconfshow();

/**----------------------------------------------------------------------
* nvstartdual
* 
* @brief   service开关双流
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvstartdual(BOOL32 bStart );

/**----------------------------------------------------------------------
* nvsetaudoutvol
* 
* @brief   service设置音频输出音量
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvsetaudoutvol(u32 dwVol);

/**----------------------------------------------------------------------
* nvsetaudquite
* 
* @brief   service设置音频静音
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvsetaudquite(BOOL32 bQuite);

/**----------------------------------------------------------------------
* nvsettv
* 
* @brief   service设置电视亮度、对比度、饱和度等
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvsettv( u8 byScreenType, u8 byType, u8 byVal );

/**----------------------------------------------------------------------
* nvsetscreennum
* 
* @brief   service设置屏幕个数
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvsetscreennum(u8 byNum);

/**----------------------------------------------------------------------
* nvsettimezone
* 
* @brief   service设置时区
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvsettimezone(u32 dwtime);

/**----------------------------------------------------------------------
* nvsetsysdatatime
* 
* @brief   service设置系统当前时间
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
//API void nvsetsysdatatime();

/**----------------------------------------------------------------------
* nvsetimixnet
* 
* @brief   service设置Imix 网络
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvsetimixnet(s8 *pip, s8 *pmask, s8 *pgateway, s8 *pdns);

/**----------------------------------------------------------------------
* nvgetcallstate
* 
* @brief   service获取当前的呼叫状态
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvgetcallstate();

/**----------------------------------------------------------------------
* nvsleep
* 
* @brief   service终端待机
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvsleep();

/**----------------------------------------------------------------------
* nvwakeup
* 
* @brief   service终端唤醒
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvwakeup();

/**----------------------------------------------------------------------
* nvreset
* 
* @brief   service终端唤醒
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvreset();

#endif // _NVSERVICEHELP_H_