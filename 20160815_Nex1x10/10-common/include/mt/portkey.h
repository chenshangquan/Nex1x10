/*=============================================================================================
ģ����   : mtport
�ļ���   : portkey.h
����     : ����˿ڵ�key
����     : ruiyigen
��Ȩ     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
=============================================================================================*/
#ifndef _PORTKEY_H_
#define _PORTKEY_H_
#include <string>
#ifndef BUILD_PORT_MAP
#define ADD_PORT(strKey, wTcpCount, wUdpCount) const std::string strKey = #strKey
#endif

/////����Ϊtcp�Ķ˿ڲ���

/*245��ʼ�˿ڷ���1��������˿�������ԣ�����245��ΧΪ20����Ϊ[��ʼ����ʼ+20]
                      ����˿ڹ̶����ԣ�����245��ΧΪ10���� Ϊ[��ʼ����ʼ+9]
					  ����323Э��ջ�㶨2���˿ڣ�timewait״̬���ٸĻ�ȥ
*/
ADD_PORT(PORTS_H323TcpPortRange, 10,0 );   

/* 225�Ǳ�����˿ڣ������׼������Ϊ1720
   ����˿ڹ̶����ԣ� ��������Ķ˿ڣ�
   ����˿�������ԣ���[NONSTAND_H323CALLING_PORT, NONSTAND_H323CALLING_PORT_END]���ң� ȷ���˿�û�б�ռ��
*/
ADD_PORT(PORTS_H323NonStandCallingPort, 1, 0);



///////udp �˿ڷ���
ADD_PORT(PORTS_RecvAud0, 0, 2);            ///����Ƶ���գ� Ҳ��Ϊvod���������˿�
ADD_PORT(PORTS_RecvVid0, 0, 2);            ///����Ƶ���գ� Ҳ��Ϊvod���������˿�
ADD_PORT(PORTS_RecvAssVid, 0, 2);          ///��ʱ��1· ����Ƶ������ Ҳ��Ϊvod �ո���Ƶ���˿�
ADD_PORT(PORTS_RecvAssAud, 0, 0);          ///��ʱ��0· ����Ƶ����
ADD_PORT(PORTS_LocalAssV4Forword, 0, 2);   ///����ת��˫���˿�

ADD_PORT(PORTS_RecvFecc, 0, 1);            ////fecc �˿ڸ��ã� �շ�����һ���˿�
ADD_PORT(PORTS_SendFecc, 0, 0);            ////fecc �˿ڲ��ܸ���
ADD_PORT(PORTS_BFCP, 1, 1);                ////bfcpֻռ��һ���˿ڣ���һ���˷ѵ��ˣ�


ADD_PORT(PORTS_SendAud0, 0, 2);       //����˿ڸ��ã���recvaud��
ADD_PORT(PORTS_SendVid0, 0, 2);       //����˿ڸ��ã���recvvid��
ADD_PORT(PORTS_SendAssVid, 0, 2);     //����˿ڸ��ã���recvAssvid��
ADD_PORT(PORTS_SendAssAud, 0, 0);

////����
ADD_PORT(PORTS_RecvVidMul,0, 2*(MAX_MAINVIDEO_NUM-1) );  ///����
ADD_PORT(PORTS_SendVidMul, 0, 2*(MAX_MAINVIDEO_NUM-1) ); ///����
ADD_PORT(PORTS_RecvAudMul,0, 2*(MAX_MAINAUDIO_NUM-1) );  ///����
ADD_PORT(PORTS_SendAudMul, 0, 2*(MAX_MAINAUDIO_NUM-1) ); ///����


ADD_PORT(PORTS_H323PXY, 0, MTH323PROXYPORTSIZE);   ////323�����õ��Ķ˿�
ADD_PORT(PORTS_DisplayToRecvAss,0,2);              ///˫�����ԣ������õ��Ķ˿ڣ�skyshareҲ���ÿ��˿�

// �����Ի���Ҫ�õ��Ķ˿ڣ���ʱֻ��Ӳ�ն���, ���صģ� ���ÿ��˿�
ADD_PORT(PORTS_AudLoop, 0, 4*MAX_MAINAUDIO_NUM);
ADD_PORT(PORTS_VidLoop, 0, 8*MAX_MAINVIDEO_NUM);


/*mtmp ý�� �����õ��Ķ˿�,����Ķ˿� ��Ҫ������mtmp�ڲ�ת���õ��Ķ˿ڣ�
  ��ʱ�ֻ���û�õ�forward
*/
ADD_PORT(PORTS_EncAud_Forward, 0, 4);
ADD_PORT(PORTS_EncVid_Forward, 0, 4);
ADD_PORT(PORTS_EncAssVid_Forward, 0, 4);     ////��ʱ��1· ����Ƶ��������
ADD_PORT(PORTS_EncAssAud_Forward, 0, 0);     ////��ʱ��0· ����Ƶ��������

ADD_PORT(PORTS_DecAud_Forward, 0, 4);
ADD_PORT(PORTS_DecVid_Forward, 0, 4);
ADD_PORT(PORTS_DecAssVid_Forward, 0, 4);    ////��ʱ��1· ����Ƶ��������
ADD_PORT(PORTS_DecAssAud_Forward, 0, 0);    ////��ʱ��0· ����Ƶ��������




/*
    ����mc��Ҫ�õ��Ķ˿�,����������8���ն�
*/
//����ep��Ӧ���նˣ���ʵ�����Լ���p2p->mc�� ��Ҫ��������rtp,rtcp�˿ڣ� ͨ������sendA,sendV,sendAssVid
ADD_PORT(PORTS_MTMC_LocalEPMt,0,2*6);

////����mc�У� netbuf�����õĶ˿�, ÿ��netbuf�õ�4���˿ڣ� Audio,video, assvido ����netbuf
ADD_PORT(PORTS_MTMC_InnerMCNetBuf,0, 4*3);

///����mc�У�ת���˿ڣ� rtp�� rtcp
ADD_PORT(PORTS_MTMC_InnerMCAvSW, 0, 2*3 );

///����mc�У�ͨ�����յ�ַ���������ģʽ�����յ�ַ��ֱ�����õ��ϳ���
ADD_PORT(PORTS_MTMC_InnerMcRcvAddr, 0, 8*2*2 );

ADD_PORT(PORT_MTMC_InnerMcAssRcvAddr,0, 2);

/////����ģʽ�� ���úϳ����ͻ������͵�ַtodo






#ifndef BUILD_PORT_MAP
#undef ADD_PORT
#endif

#endif // _PORTKEY_H_