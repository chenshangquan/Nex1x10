/**===========================================================================
 * @file    nvmsg.h
 * @brief   ��Ϣ����봦��
 * @author  ruiyigen
 * @date    20140408
 * @version 1.0 
 * (c)1995-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
============================================================================*/
#ifndef _NVMSG_H_
#define _NVMSG_H_

#include <vector>
#include <string>
#include <google/protobuf/message.h>
#include <google/protobuf/generated_enum_reflection.h>
#include "kdvtype.h"
#include "nvmacro.h"

namespace nvmsg {

/** ��Ϣ������ */
enum EmBodyIndex
{
	em1stBody = 0,
	em2ndBody = 1,
	em3rdBody = 2,
	em4thBody = 3,
	em5thBody = 4,
	em6thBody = 5,
	em7thBody = 6,
	em8thBody = 7,
	em9thBody = 8,
};

/**---------------------------------------------------------------------------
 * @class   CNvMsg
 * @brief   protobuf ��Ϣ�������
 * @author  ruiyigen
 * @date    20140404
 ---------------------------------------------------------------------------*/
class NVCBB_API CNvMsg
{	
	struct TBodyItem
	{
		BOOL32 bDelete; ///<CNvMsg�ڲ�ʹ�ã����ھ����Ƿ���CNvMsg��������ʱdelete tBody
		google::protobuf::Message* pcBody;  ///<��Ϣ��
	};

public:
	CNvMsg();
	~CNvMsg();

	/**----------------------------------------------------------------------
	* SetMsgID
	* 
	* @brief   ������ϢID
	* 
	* @param   [in] strMsgId ��ϢID
	* @return  void
	------------------------------------------------------------------------*/
	void SetMsgID(const std::string strMsgId);

	/**----------------------------------------------------------------------
	* GetMsgID
	* 
	* @brief   ��ȡ��ϢID
	* 
	* @param   void
	* @return  const std::string& ����ϢID
	------------------------------------------------------------------------*/
	const std::string& GetMsgID();

	/**----------------------------------------------------------------------
	* SetSessionID
	* 
	* @brief   ���ûỰID
	* 
	* @param   [in] strSessionId �ỰID
	* @return  void
	------------------------------------------------------------------------*/
	void SetSessionID(const std::string strSessionId);

	/**----------------------------------------------------------------------
	* GetSessionID
	* 
	* @brief   ��ȡ�ỰID
	* 
	* @param   void
	* @return  const std::string& ���ỰID
	------------------------------------------------------------------------*/
	const std::string& GetSessionID();

	/**----------------------------------------------------------------------
	* SetSequenceID
	* 
	* @brief   �������к�
	* 
	* @param   [in] dwSequenceId ���к�
	* @return  void
	------------------------------------------------------------------------*/
	void SetSequenceID(u32 dwSequenceId);

	/**----------------------------------------------------------------------
	* GetSequenceID
	* 
	* @brief   ��ȡ���к�
	* 
	* @param   void
	* @return  u32 �����к�
	------------------------------------------------------------------------*/
	u32 GetSequenceID();

	/**----------------------------------------------------------------------
	* SetUserData
	* 
	* @brief   �����û��Զ������ݣ�CNvMsg��͸�����ֶΣ����ֶεĺ������û��Լ����ͣ�
	* 
	* @param   [in] strUserData �û��Զ�������
	* @return  void
	------------------------------------------------------------------------*/
	void SetUserData(const std::string strUserData);

	/**----------------------------------------------------------------------
	* GetUserData
	* 
	* @brief   ��ȡ�û��Զ�������
	* 
	* @param   void
	* @return  const std::string& ���û��Զ�������
	------------------------------------------------------------------------*/
	const std::string& GetUserData();

	/**----------------------------------------------------------------------
	* GetReqPath
	* 
	* @brief   ��ȡReq��Ϣ��·��
	* 
	* @param   void
	* @return  const std::vector<std::string> ��Req��Ϣ��·��
	------------------------------------------------------------------------*/
	const std::vector<std::string>& GetReqPath();

	/**----------------------------------------------------------------------
	* SetReqPath
	* 
	* @brief   ����Req��Ϣ��·��
	* 
	* @param   [in] vctReqPath Req��Ϣ��·��
	* @return  void
	------------------------------------------------------------------------*/
	void SetReqPath(const std::vector<std::string> &vctReqPath);

	/**----------------------------------------------------------------------
	* PushReqPath
	* 
	* @brief   ������·��ջ���˼���һ������·��
	* 
	* @param   [in] strReqPath Req��Ϣ��·������Ҫע�����������Ϊ�մ������Զ���m_strSessionId����push
	* @return  void
	------------------------------------------------------------------------*/
	void PushReqPath(const std::string strReqPath = "");

	/**----------------------------------------------------------------------
	* PopReqPath
	* 
	* @brief   ����������·��ջ���˵�����·��,������·��ջ���򷵻ؿմ�""
	* 
	* @param   void
	* @return  std::string ��Req��Ϣ��·��
	------------------------------------------------------------------------*/
	std::string PopReqPath();

	/**----------------------------------------------------------------------
	* AddMsgBody
	* 
	* @brief   ���һ����Ϣ��
	* 
	* @param   [in] pcMsgBody ��Ϣ��
	* @return  void
	------------------------------------------------------------------------*/
	void AddMsgBody(google::protobuf::Message *pcMsgBody);

	/**----------------------------------------------------------------------
	* InsertMsgBody
	* 
	* @brief   ������dwInsertBefore��Ӧ����Ϣ��ǰ����һ����Ϣ�壨���ã����ܲ���AddMsgBody��
	* 
	* @param   [in] pcMsgBody ��Ϣ��
	* @param   [in] dwInsertBefore ��Ϣ������,��0��ʼ
	* @return  BOOL32 �������Ƿ�ɹ�
	------------------------------------------------------------------------*/
	BOOL32 InsertMsgBody(google::protobuf::Message *pcMsgBody, u32 dwInsertBefore);

	/**----------------------------------------------------------------------
	* GetMsgBody
	* 
	* @brief   ��ȡָ������Ϣ��
	* 
	* @param   [in] dwIndex ��Ϣ��������, ��0��ʼ
	* @return  Message* ����Ϣ��ָ�룬ʧ�ܷ���NULL
	------------------------------------------------------------------------*/
	google::protobuf::Message* GetMsgBody(u32 dwIndex = 0);

	/**----------------------------------------------------------------------
	* Encode
	* 
	* @brief   ����
	* 
	* @param   [inout] pbyBuf ��ű�������ݵ��ڴ��
	* @param   [inout] wBufLen �ڴ���С
	* @return  BOOL32 �ɹ�����TRUE��ʧ�ܷ���FALSE
	------------------------------------------------------------------------*/
	BOOL32 Encode(u8 *pbyBuf, u16 &wBufLen);

	/**----------------------------------------------------------------------
	* Decode
	* 
	* @brief   ����
	* 
	* @param   [in] pbyBuf ��Ŵ��������ݵ��ڴ��
	* @param   [in] wBufLen �ڴ���С
	* @return  BOOL32 �ɹ�����TRUE��ʧ�ܷ���FALSE
	------------------------------------------------------------------------*/
	BOOL32 Decode(u8 *pbyBuf, u16 wBufLen);

	/**----------------------------------------------------------------------
	* Clear
	* 
	* @brief   ��ն���
	* 
	* @param   void
	* @return  void
	------------------------------------------------------------------------*/
	void Clear();

private:
	std::string              m_strMsgId;      ///<��ϢID
	std::string              m_strSessionId;  ///<�ỰID
	u32                      m_dwSequenceId;  ///<���к�		
	std::string              m_strUserData;   ///<�û��Զ�������
	std::vector<std::string> m_vctReqPath;    ///<req��Ϣ�Ľ���·����req��Ϣÿ����һ�������߶�Ҫ���˷����߼���req_path�У��Ա�rsp��Ϣ��ԭ·���أ�������rsp��ϢʱҪ���ȥ��
	std::vector<TBodyItem>   m_vctBodys;      ///<��Ϣ��
};

/**----------------------------------------------------------------------
* InitNvMsgLib
* 
* @brief   ��ʼ����Ϣ������
* 
* @param   void
* @return  BOOL32 �ɹ�����TRUE��ʧ�ܷ���FALSE
------------------------------------------------------------------------*/
//lint -esym(714, nvmsg::InitNvMsgLib)
NVCBB_API BOOL32 InitNvMsgLib();

/**----------------------------------------------------------------------
* UnInitNvMsgLib
* 
* @brief   �˳���Ϣ������
* 
* @param   void
* @return  BOOL32 �ɹ�����TRUE��ʧ�ܷ���FALSE
------------------------------------------------------------------------*/
//lint -esym(714, nvmsg::UnInitNvMsgLib)
NVCBB_API BOOL32 UnInitNvMsgLib();

/**----------------------------------------------------------------------
* GetEnumVauleName
* 
* @brief   ��ȡö��ֵ������
* 
* @param   [in] T ö������
* @param   [in] nValue ö��ֵ
* @return  s8* ��ö��ֵ������ ʧ�ܷ��ؿ��ִ�""
------------------------------------------------------------------------*/
template<class T>
NVCBB_API const s8* GetEnumVauleName(s32 nValue)
{
	const google::protobuf::EnumValueDescriptor *pemDes = google::protobuf::GetEnumDescriptor<T>()->FindValueByNumber(nValue);
	if (pemDes != NULL)
	{
		return pemDes->name().c_str();
	}
	else
	{
		return "";
	}	
}

/**----------------------------------------------------------------------
* IsCmdMsg
* 
* @brief   �ж���Ϣ�����Ƿ�������
* 
* @param   [in] strMsgId ��ϢID
* @return  BOOL32 TRUE:���������ͣ� FALSE:������������
------------------------------------------------------------------------*/
NVCBB_API BOOL32 IsCmdMsg(std::string strMsgId);

/**----------------------------------------------------------------------
* IsNtfMsg
* 
* @brief   �ж���Ϣ�����Ƿ���֪ͨ
* 
* @param   [in] strMsgId ��ϢID
* @return  BOOL32 TRUE:��֪ͨ���ͣ� FALSE:����֪ͨ����
------------------------------------------------------------------------*/
NVCBB_API BOOL32 IsNtfMsg(std::string strMsgId);

/**----------------------------------------------------------------------
* IsReqMsg
* 
* @brief   �ж���Ϣ�����Ƿ�������
* 
* @param   [in] strMsgId ��ϢID
* @return  BOOL32 TRUE:���������ͣ� FALSE:������������
------------------------------------------------------------------------*/
NVCBB_API BOOL32 IsReqMsg(std::string strMsgId);

/**----------------------------------------------------------------------
* IsRspMsg
* 
* @brief   �ж���Ϣ�����Ƿ�����Ӧ
* 
* @param   [in] strMsgId ��ϢID
* @return  BOOL32 TRUE:����Ӧ���ͣ� FALSE:������Ӧ����
------------------------------------------------------------------------*/
NVCBB_API BOOL32 IsRspMsg(std::string strMsgId);

}

#endif