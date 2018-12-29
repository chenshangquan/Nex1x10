/*=============================================================================================
模块名   : mtport
文件名   : portkey.h
功能     : 定义端口的key
作者     : ruiyigen
版权     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
=============================================================================================*/
#ifndef _PORTKEY_H_
#define _PORTKEY_H_
#include <string>
#ifndef BUILD_PORT_MAP
#define ADD_PORT(strKey, wTcpCount, wUdpCount) const std::string strKey = #strKey
#endif

/////下面为tcp的端口策略

/*245起始端口分配1个，如果端口随机策略，设置245范围为20个，为[起始，起始+20]
                      如果端口固定策略，设置245范围为10个， 为[起始，起始+9]
					  后面323协议栈搞定2个端口，timewait状态后，再改回去
*/
ADD_PORT(PORTS_H323TcpPortRange, 10,0 );   

/* 225非标监听端口，如果标准，定死为1720
   如果端口固定策略， 就用下面的端口，
   如果端口随机策略，在[NONSTAND_H323CALLING_PORT, NONSTAND_H323CALLING_PORT_END]中找， 确保端口没有被占用
*/
ADD_PORT(PORTS_H323NonStandCallingPort, 1, 0);



///////udp 端口分配
ADD_PORT(PORTS_RecvAud0, 0, 2);            ///主音频接收， 也作为vod接收码流端口
ADD_PORT(PORTS_RecvVid0, 0, 2);            ///主视频接收， 也作为vod接收码流端口
ADD_PORT(PORTS_RecvAssVid, 0, 2);          ///暂时有1路 收视频辅流， 也作为vod 收辅视频流端口
ADD_PORT(PORTS_RecvAssAud, 0, 0);          ///暂时有0路 收音频辅流
ADD_PORT(PORTS_LocalAssV4Forword, 0, 2);   ///本地转发双流端口

ADD_PORT(PORTS_RecvFecc, 0, 1);            ////fecc 端口复用， 收发就用一个端口
ADD_PORT(PORTS_SendFecc, 0, 0);            ////fecc 端口不能复用
ADD_PORT(PORTS_BFCP, 1, 1);                ////bfcp只占用一个端口，后一个浪费掉了，


ADD_PORT(PORTS_SendAud0, 0, 2);       //如果端口复用，用recvaud的
ADD_PORT(PORTS_SendVid0, 0, 2);       //如果端口复用，用recvvid的
ADD_PORT(PORTS_SendAssVid, 0, 2);     //如果端口复用，用recvAssvid的
ADD_PORT(PORTS_SendAssAud, 0, 0);

////多流
ADD_PORT(PORTS_RecvVidMul,0, 2*(MAX_MAINVIDEO_NUM-1) );  ///多流
ADD_PORT(PORTS_SendVidMul, 0, 2*(MAX_MAINVIDEO_NUM-1) ); ///多流
ADD_PORT(PORTS_RecvAudMul,0, 2*(MAX_MAINAUDIO_NUM-1) );  ///多流
ADD_PORT(PORTS_SendAudMul, 0, 2*(MAX_MAINAUDIO_NUM-1) ); ///多流


ADD_PORT(PORTS_H323PXY, 0, MTH323PROXYPORTSIZE);   ////323代理用到的端口
ADD_PORT(PORTS_DisplayToRecvAss,0,2);              ///双流回显，本地用到的端口，skyshare也不用开端口

// 本地自环需要用到的端口，暂时只是硬终端用, 本地的， 不用开端口
ADD_PORT(PORTS_AudLoop, 0, 4*MAX_MAINAUDIO_NUM);
ADD_PORT(PORTS_VidLoop, 0, 8*MAX_MAINVIDEO_NUM);


/*mtmp 媒控 申请用到的端口,下面的端口 主要是用在mtmp内部转发用到的端口，
  暂时手机端没用到forward
*/
ADD_PORT(PORTS_EncAud_Forward, 0, 4);
ADD_PORT(PORTS_EncVid_Forward, 0, 4);
ADD_PORT(PORTS_EncAssVid_Forward, 0, 4);     ////暂时有1路 发视频辅编码器
ADD_PORT(PORTS_EncAssAud_Forward, 0, 0);     ////暂时有0路 发音频辅编码器

ADD_PORT(PORTS_DecAud_Forward, 0, 4);
ADD_PORT(PORTS_DecVid_Forward, 0, 4);
ADD_PORT(PORTS_DecAssVid_Forward, 0, 4);    ////暂时有1路 收视频辅编码器
ADD_PORT(PORTS_DecAssAud_Forward, 0, 0);    ////暂时有0路 发音频辅编码器




/*
    内置mc需要用到的端口,这里包括最多8个终端
*/
//本地ep对应的终端，其实就是自己，p2p->mc， 需要重新申请rtp,rtcp端口， 通道包括sendA,sendV,sendAssVid
ADD_PORT(PORTS_MTMC_LocalEPMt,0,2*6);

////内置mc中， netbuf需用用的端口, 每个netbuf用到4个端口， Audio,video, assvido 三个netbuf
ADD_PORT(PORTS_MTMC_InnerMCNetBuf,0, 4*3);

///内置mc中，转发端口， rtp， rtcp
ADD_PORT(PORTS_MTMC_InnerMCAvSW, 0, 2*3 );

///内置mc中，通道接收地址，如果讨论模式，接收地址，直接设置到合成器
ADD_PORT(PORTS_MTMC_InnerMcRcvAddr, 0, 8*2*2 );

ADD_PORT(PORT_MTMC_InnerMcAssRcvAddr,0, 2);

/////讨论模式， 设置合成器和混音发送地址todo






#ifndef BUILD_PORT_MAP
#undef ADD_PORT
#endif

#endif // _PORTKEY_H_