/*=============================================================================
ģ   ��   ��: touch
��   ��   ��: Language.h
�� ��  �� ��: ��
�ļ�ʵ�ֹ���: ˫��
��        ��: chenshangquan
��        ��: V1.0  Copyright(C) 2003-2006 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���              �޸�����
2018/09/28  1.0     chenshangquan       ����
=============================================================================*/

#ifndef __LANGUAGE_HEADER_
#define __LANGUAGE_HEADER_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern EMLangID g_emLanType; //��������

#define TRANSLATE(text)     \
     CString( g_emLanType == enumLangIdCHN ? text##CHN : text##ENG )

    #define NET_STATUS_CONNECTING_CHN               "���������豸"
    #define NET_STATUS_CONNECTING_ENG               "Connecting"
#define STRING_NET_STATUS_CONNECTING                TRANSLATE(NET_STATUS_CONNECTING_)

    #define NET_STATUS_CONNECTED_CHN                "������"//nt yt
    #define NET_STATUS_CONNECTED_ENG                "Connected"
#define STRING_NET_STATUS_CONNECTED                 TRANSLATE(NET_STATUS_CONNECTED_)
    #define DES_NET_STATUS_CONNECTED_CHN            "��ѹ����Ͷ����������ʼͶ�����ٴΰ�ѹ����Ͷ��"
    #define DES_NET_STATUS_CONNECTED_ENG            "Press NT30 for Projecting, Press Again to Stop"
#define STRING_DES_NET_STATUS_CONNECTED             TRANSLATE(DES_NET_STATUS_CONNECTED_)

    #define NET_STATUS_DISCONNECTED_CHN             "�����ѶϿ�"
    #define NET_STATUS_DISCONNECTED_ENG             "Disconnected"
#define STRING_NET_STATUS_DISCONNECTED              TRANSLATE(NET_STATUS_DISCONNECTED_)
    #define DES_NET_STATUS_DISCONNECTED_CHN         "�뽫����Ͷ�������������豸USB�ӿڣ��������"
    #define DES_NET_STATUS_DISCONNECTED_ENG         "Please Plug NT30 to USB on the equipment for Pairing"
#define STRING_DES_NET_STATUS_DISCONNECTED          TRANSLATE(DES_NET_STATUS_DISCONNECTED_)

    #define NET_STATUS_FIND_TER_FAIL_CHN            "���������豸"//nt yt
    #define NET_STATUS_FIND_TER_FAIL_ENG            "Cannot Find the equipment"
#define STRING_NET_STATUS_FIND_TER_FAIL             TRANSLATE(NET_STATUS_FIND_TER_FAIL_)
    #define DES_NET_STATUS_FIND_TER_FAIL_CHN        "�豸�쳣����ȴ��������豸"
    #define DES_NET_STATUS_FIND_TER_FAIL_ENG        "Equipment abnormal, Please waiting or reboot"
#define STRING_DES_NET_STATUS_FIND_TER_FAIL         TRANSLATE(DES_NET_STATUS_FIND_TER_FAIL_)

    #define NET_STATUS_NO_MATCH_CHN                 "δ����Ƶ�����豸���"
    #define NET_STATUS_NO_MATCH_ENG                 "Not paired"
#define STRING_NET_STATUS_NO_MATCH                  TRANSLATE(NET_STATUS_NO_MATCH_)
    #define DES_NET_STATUS_NO_MATCH_CHN             "�뽫����Ͷ����������������Ƶ�����豸��USB�ӿڣ�������"
    #define DES_NET_STATUS_NO_MATCH_ENG             "Please Plug NT30 to USB on the equipment for Pairing"
#define STRING_DES_NET_STATUS_NO_MATCH              TRANSLATE(DES_NET_STATUS_NO_MATCH_)

    #define NET_STATUS_FIND_SSID_FAIL_CHN           "���ӳ�ʱ"
    #define NET_STATUS_FIND_SSID_FAIL_ENG           "Connection Timeout"
#define STRING_NET_STATUS_FIND_SSID_FAIL            TRANSLATE(NET_STATUS_FIND_SSID_FAIL_)
    #define DES_NET_STATUS_FIND_SSID_FAIL_CHN       "�뽫����Ͷ�������������豸USB�ӿڣ��������"
    #define DES_NET_STATUS_FIND_SSID_FAIL_ENG       "Please Plug NT30 to USB on the equipment for Pairing"
#define STRING_DES_NET_STATUS_FIND_SSID_FAIL        TRANSLATE(DES_NET_STATUS_FIND_SSID_FAIL_)

    #define NET_STATUS_ENOUGHNUM_CHN                "������������"
    #define NET_STATUS_ENOUGHNUM_ENG                "Connection Quantity Limited"
#define STRING_NET_STATUS_ENOUGHNUM                 TRANSLATE(NET_STATUS_ENOUGHNUM_)
    #define DES_NET_STATUS_ENOUGHNUM_CHN            "��ʾ�����֧������8������Ͷ��������"
    #define DES_NET_STATUS_ENOUGHNUM_ENG            "Maxmium Quantity is 8"
#define STRING_DES_NET_STATUS_ENOUGHNUM             TRANSLATE(DES_NET_STATUS_ENOUGHNUM_)

    #define NET_STATUS_RESETQUICKSHARE_CHN          "�޷������豸"//nt yt
    #define NET_STATUS_RESETQUICKSHARE_ENG          "Can not connect to the equipment"
#define STRING_NET_STATUS_RESETQUICKSHARE           TRANSLATE(NET_STATUS_RESETQUICKSHARE_)
    #define DES_NET_STATUS_RESETQUICKSHARE_CHN      "��ε�����Ͷ�������������½������"
    #define DES_NET_STATUS_RESETQUICKSHARE_ENG      "Please Remove NT30 and Replug it to your PC"
#define STRING_DES_NET_STATUS_RESETQUICKSHARE       TRANSLATE(DES_NET_STATUS_RESETQUICKSHARE_)

    #define NET_STATUS_TER_DISCONNECTED_CHN         "�����ѶϿ�"
    #define NET_STATUS_TER_DISCONNECTED_ENG         "Disconnected"
#define STRING_NET_STATUS_TER_DISCONNECTED          TRANSLATE(NET_STATUS_TER_DISCONNECTED_)
    #define DES_NET_STATUS_TER_DISCONNECTED_CHN     "���������У����Ժ򡭡�"
    #define DES_NET_STATUS_TER_DISCONNECTED_ENG     "Reconnecting to the Network..."
#define STRING_DES_NET_STATUS_TER_DISCONNECTED      TRANSLATE(DES_NET_STATUS_TER_DISCONNECTED_)
    #define NET_STATUS_RECONNECTTER_FAIL_CHN        "�����ѶϿ�"
    #define NET_STATUS_RECONNECTTER_FAIL_ENG        "Disconnected"
#define STRING_NET_STATUS_RECONNECTTER_FAIL         TRANSLATE(NET_STATUS_RECONNECTTER_FAIL_)
    #define DES_NET_STATUS_RECONNECTTER_FAIL_CHN    "������Žϴ����Ż����绷��"
    #define DES_NET_STATUS_RECONNECTTER_FAIL_ENG    "Network interference, Please optimize your network environment"
#define STRING_DES_NET_STATUS_RECONNECTTER_FAIL     TRANSLATE(DES_NET_STATUS_RECONNECTTER_FAIL_)

    #define SHOW_UPGRADE_CHN                        "�����°汾"
    #define SHOW_UPGRADE_ENG                        "New Version Released"
#define STRING_SHOW_UPGRADE                         TRANSLATE(SHOW_UPGRADE_)

    #define SHOW_UPGRADE_TIP1_CHN                   "�뽫����Ͷ����������������ʾ�˵�"
    #define SHOW_UPGRADE_TIP1_ENG                   "Please Plug NT30 to USB on"
#define STRING_SHOW_UPGRADE_TIP1                    TRANSLATE(SHOW_UPGRADE_TIP1_)

    #define SHOW_UPGRADE_TIP2_CHN                   "USB�ӿڽ�������"
    #define SHOW_UPGRADE_TIP2_ENG                   "the equipment for Upgrading"
#define STRING_SHOW_UPGRADE_TIP2                    TRANSLATE(SHOW_UPGRADE_TIP2_)

    #define SHOW_LINK_IGNORE_CHN                    "<a href=\"�ݲ�����,����Ͷ��\">�ݲ�����,����Ͷ��</a>"
    #define SHOW_LINK_IGNORE_ENG                    "<a href=\"Optional: Decide later\">Optional: Decide later</a>"
#define STRING_SHOW_LINK_IGNORE                     TRANSLATE(SHOW_LINK_IGNORE_)

    #define CONNECT_BUSINESS_FAIL_CHN               "������ҵ������쳣"
    #define CONNECT_BUSINESS_FAIL_ENG               "Business Process Exception"
#define STRING_CONNECT_BUSINESS_FAIL                TRANSLATE(CONNECT_BUSINESS_FAIL_)
    #define DES_CONNECT_BUSINESS_FAIL_CHN           "��ε�����Ͷ�������������½������"
    #define DES_CONNECT_BUSINESS_FAIL_ENG           "Please Remove NT30 and Replug it to your PC"
#define STRING_DES_CONNECT_BUSINESS_FAIL            TRANSLATE(DES_CONNECT_BUSINESS_FAIL_)

    #define CONNECT_RESOLUTION_LIMITED_CHN          "Ͷ��ʧ��"
    #define CONNECT_RESOLUTION_LIMITED_ENG          "Projecting Failed"
#define STRING_CONNECT_RESOLUTION_LIMITED           TRANSLATE(CONNECT_RESOLUTION_LIMITED_)
    #define DES_CONNECT_RESOLUTION_LIMITED_CHN      "��֧�ֵ�ǰ����ֱ���Ͷ��"
    #define DES_CONNECT_RESOLUTION_LIMITED_ENG      "Desktop Resolution Disabled"
#define STRING_DES_CONNECT_RESOLUTION_LIMITED       TRANSLATE(DES_CONNECT_RESOLUTION_LIMITED_)

    #define CONNECT_NT30_MT_NONSUPPORT_CHN         "Ͷ��ʧ��"
    #define CONNECT_NT30_MT_NONSUPPORT_ENG         "Projecting Failed"
#define STRING_CONNECT_NT30_MT_NONSUPPORT          TRANSLATE(CONNECT_NT30_MT_NONSUPPORT_)
    #define DES_CONNECT_NT30_MT_NONSUPPORT_CHN     "�����ն˲�֧��Ͷ��"
    #define DES_CONNECT_NT30_MT_NONSUPPORT_ENG     "The special encryption is enabled"
#define STRING_DES_CONNECT_NT30_MT_NONSUPPORT      TRANSLATE(DES_CONNECT_NT30_MT_NONSUPPORT_)

    #define PROJECTING_CHN                          " ����Ͷ��"
    #define PROJECTING_ENG                          " Projecting"
#define STRING_PROJECTING                           TRANSLATE(PROJECTING_)

    #define STOP_PROJECTING_CHN                     "ֹͣͶ��"
    #define STOP_PROJECTING_ENG                     "Stop"
#define STRING_STOP_PROJECTING                      TRANSLATE(STOP_PROJECTING_)

#endif//__LANGUAGE_HEADER_
