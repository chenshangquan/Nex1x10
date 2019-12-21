

/*****************************************************************************
   ģ����      :
   �ļ���      : suserrcode.h
   ����ļ�    :
   �ļ�ʵ�ֹ���: SUS�����붨��ͷ�ļ�
   ����        :
   �汾        : V1.0  Copyright(C) 2006-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2013/03/01  1.0                     ����
******************************************************************************/


#ifndef _SUS_ERR_CODE_H_
#define _SUS_ERR_CODE_H_




/*------------------------------------------------------------------------------
  ������
------------------------------------------------------------------------------*/

#define SUS_ERR_SUCC			                    (u32)(0)                            //�ɹ�
#define SUS_ERRORCODE_BGN_KDVP                      (u32)(20000)

//**************************************************************************************
//����2.5.2����ǰ�汾���ն�
//**************************************************************************************
#define SUS_ERR_DISK_ABNORMAL                       (SUS_ERRORCODE_BGN_KDVP + 1003)     //�ն˴����쳣
#define SUS_ERR_MAX_SERVICE_SESSION                 (SUS_ERRORCODE_BGN_KDVP + 2000)     //�������Ѵ������������
#define SUS_ERR_TIMEOUT                             (SUS_ERRORCODE_BGN_KDVP + 2001)     //������ʱ
#define SUS_ERR_NOT_PREPARED_NOW                    (SUS_ERRORCODE_BGN_KDVP + 2002)     //��������δ�������
#define SUS_ERR_FILE_NOT_EXIST                      (SUS_ERRORCODE_BGN_KDVP + 2005)     //ָ���ļ�������
#define SUS_ERR_DEV_NOT_EXIST                       (SUS_ERRORCODE_BGN_KDVP + 2006)     //���������޴��豸�İ汾
#define SUS_ERR_OEMREMARK_NOT_MATCH                 (SUS_ERRORCODE_BGN_KDVP + 3036)     //OEM��ʶ��ƥ��
//***************************************************************************************

#define SUS_ERR_LOGIN_PARAM_INVAIL			        (SUS_ERRORCODE_BGN_KDVP + 2003)     //��½��������
#define SUS_ERR_NOT_LOGIN_NOW       			    (SUS_ERRORCODE_BGN_KDVP + 2004)     //��δ��½�����ܽ��в���
#define SUS_ERR_UNZIP_FILE_FAIL       			    (SUS_ERRORCODE_BGN_KDVP + 2007)     //��ѹ���ļ�ʧ��

#define SUS_ERR_SERVER_INSIDE_ERR			        (SUS_ERRORCODE_BGN_KDVP + 3001)     //�������ڲ�����
#define SUS_ERR_DB_EXEC_FAIL				        (SUS_ERRORCODE_BGN_KDVP + 3002)     //���ݿ�ִ��ʧ��

#define SUS_ERR_CANNOT_DEL_RECOMMEND			    (SUS_ERRORCODE_BGN_KDVP + 4001)     //�Ƽ��汾������ɾ��
#define SUS_ERR_MODIFY_INVAILD					    (SUS_ERRORCODE_BGN_KDVP + 4002)     //�޸Ĳ��Ϸ�
#define SUS_ERR_UPLOAD_VER_INVAILD				    (SUS_ERRORCODE_BGN_KDVP + 4003)     //�ϴ��İ汾���Ϸ�
#define SUS_ERR_UPLOAD_VER_EXIST				    (SUS_ERRORCODE_BGN_KDVP + 4004)     //�ϴ��İ汾�Ѿ�����
#define SUS_ERR_VER_TOO_MUCH			            (SUS_ERRORCODE_BGN_KDVP + 4005)     //���豸�İ汾���������������
#define SUS_ERR_VERSION_FILE_INVAILD			    (SUS_ERRORCODE_BGN_KDVP + 4006)     //�汾�ļ����Ϸ��������ڻ���Ͳ�ƥ�䣩
#define SUS_ERR_MOVEFILE_FAIL			            (SUS_ERRORCODE_BGN_KDVP + 4007)     //�ƶ��汾�ļ�ʧ��





#define SUS_ONE_TEXT(errcode,ChnStr)                        \
case errcode:                                               \
    return ChnStr;                                          \

static const s8* GetSusErrorStr(u32 wErrorID)
{   
    switch ( wErrorID )
    {
        SUS_ONE_TEXT( SUS_ERR_DISK_ABNORMAL, "�ն˴����쳣!");
        SUS_ONE_TEXT( SUS_ERR_MAX_SERVICE_SESSION, "�������Ѵ�����������ƣ���ʱ�޷��ṩ�������Ժ�����!");
        SUS_ONE_TEXT( SUS_ERR_TIMEOUT, "������ʱ!");
        SUS_ONE_TEXT( SUS_ERR_NOT_PREPARED_NOW, "��������δ�������!" );
        SUS_ONE_TEXT( SUS_ERR_FILE_NOT_EXIST, "ָ���ļ�������!" );
        SUS_ONE_TEXT( SUS_ERR_DEV_NOT_EXIST, "���������޴��豸�İ汾�����Ժ�����!" );
        SUS_ONE_TEXT( SUS_ERR_OEMREMARK_NOT_MATCH, "OEM��ʶ��ƥ��!" );

        SUS_ONE_TEXT( SUS_ERR_LOGIN_PARAM_INVAIL, "��½��������!" );
        SUS_ONE_TEXT( SUS_ERR_NOT_LOGIN_NOW, "��δ��½�����ܽ��в���!" ); 
        SUS_ONE_TEXT( SUS_ERR_UNZIP_FILE_FAIL, "��ѹ���ļ�ʧ��!" ); 
    
        SUS_ONE_TEXT( SUS_ERR_SERVER_INSIDE_ERR, "�������ڲ�����!" );
        SUS_ONE_TEXT( SUS_ERR_DB_EXEC_FAIL, "���ݿ�ִ��ʧ��!" ); 

        SUS_ONE_TEXT( SUS_ERR_CANNOT_DEL_RECOMMEND, "�Ƽ��汾������ɾ��!" );
        SUS_ONE_TEXT( SUS_ERR_MODIFY_INVAILD, "�޸Ĳ��Ϸ�!" );
        SUS_ONE_TEXT( SUS_ERR_UPLOAD_VER_INVAILD, "�ϴ��İ汾���Ϸ�!" );
        SUS_ONE_TEXT( SUS_ERR_UPLOAD_VER_EXIST, "�ϴ��İ汾�Ѿ�����!" );
        SUS_ONE_TEXT( SUS_ERR_VER_TOO_MUCH, "���豸�İ汾���������������!" );
        SUS_ONE_TEXT( SUS_ERR_VERSION_FILE_INVAILD, "�汾�ļ����Ϸ��������ڻ���Ͳ�ƥ�䣩" );        
        SUS_ONE_TEXT( SUS_ERR_MOVEFILE_FAIL, "�ƶ��汾�ļ�ʧ��!" );        
    default:
        {
            return "δ֪����";
        }
    }
}

#endif // _SUS_ERR_CODE_H_
// END FILE



