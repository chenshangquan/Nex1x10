/**===========================================================================
 * @file    nvmsg.h
 * @brief   消息编解码处理
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

/** 消息体索引 */
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
 * @brief   protobuf 消息编解码类
 * @author  ruiyigen
 * @date    20140404
 ---------------------------------------------------------------------------*/
class NVCBB_API CNvMsg
{	
	struct TBodyItem
	{
		BOOL32 bDelete; ///<CNvMsg内部使用，用于决定是否在CNvMsg对象销毁时delete tBody
		google::protobuf::Message* pcBody;  ///<消息体
	};

public:
	CNvMsg();
	~CNvMsg();

	/**----------------------------------------------------------------------
	* SetMsgID
	* 
	* @brief   设置消息ID
	* 
	* @param   [in] strMsgId 消息ID
	* @return  void
	------------------------------------------------------------------------*/
	void SetMsgID(const std::string strMsgId);

	/**----------------------------------------------------------------------
	* GetMsgID
	* 
	* @brief   获取消息ID
	* 
	* @param   void
	* @return  const std::string& ：消息ID
	------------------------------------------------------------------------*/
	const std::string& GetMsgID();

	/**----------------------------------------------------------------------
	* SetSessionID
	* 
	* @brief   设置会话ID
	* 
	* @param   [in] strSessionId 会话ID
	* @return  void
	------------------------------------------------------------------------*/
	void SetSessionID(const std::string strSessionId);

	/**----------------------------------------------------------------------
	* GetSessionID
	* 
	* @brief   获取会话ID
	* 
	* @param   void
	* @return  const std::string& ：会话ID
	------------------------------------------------------------------------*/
	const std::string& GetSessionID();

	/**----------------------------------------------------------------------
	* SetSequenceID
	* 
	* @brief   设置序列号
	* 
	* @param   [in] dwSequenceId 序列号
	* @return  void
	------------------------------------------------------------------------*/
	void SetSequenceID(u32 dwSequenceId);

	/**----------------------------------------------------------------------
	* GetSequenceID
	* 
	* @brief   获取序列号
	* 
	* @param   void
	* @return  u32 ：序列号
	------------------------------------------------------------------------*/
	u32 GetSequenceID();

	/**----------------------------------------------------------------------
	* SetUserData
	* 
	* @brief   设置用户自定义数据（CNvMsg仅透传该字段，该字段的含义由用户自己解释）
	* 
	* @param   [in] strUserData 用户自定义数据
	* @return  void
	------------------------------------------------------------------------*/
	void SetUserData(const std::string strUserData);

	/**----------------------------------------------------------------------
	* GetUserData
	* 
	* @brief   获取用户自定义数据
	* 
	* @param   void
	* @return  const std::string& ：用户自定义数据
	------------------------------------------------------------------------*/
	const std::string& GetUserData();

	/**----------------------------------------------------------------------
	* GetReqPath
	* 
	* @brief   获取Req消息的路径
	* 
	* @param   void
	* @return  const std::vector<std::string> ：Req消息的路径
	------------------------------------------------------------------------*/
	const std::vector<std::string>& GetReqPath();

	/**----------------------------------------------------------------------
	* SetReqPath
	* 
	* @brief   设置Req消息的路径
	* 
	* @param   [in] vctReqPath Req消息的路径
	* @return  void
	------------------------------------------------------------------------*/
	void SetReqPath(const std::vector<std::string> &vctReqPath);

	/**----------------------------------------------------------------------
	* PushReqPath
	* 
	* @brief   在请求路径栈顶端加入一个请求路径
	* 
	* @param   [in] strReqPath Req消息的路径，需要注意的是若参数为空串，则自动对m_strSessionId进行push
	* @return  void
	------------------------------------------------------------------------*/
	void PushReqPath(const std::string strReqPath = "");

	/**----------------------------------------------------------------------
	* PopReqPath
	* 
	* @brief   弹出在请求路径栈顶端的请求路径,若请求路径栈空则返回空串""
	* 
	* @param   void
	* @return  std::string ：Req消息的路径
	------------------------------------------------------------------------*/
	std::string PopReqPath();

	/**----------------------------------------------------------------------
	* AddMsgBody
	* 
	* @brief   添加一个消息体
	* 
	* @param   [in] pcMsgBody 消息体
	* @return  void
	------------------------------------------------------------------------*/
	void AddMsgBody(google::protobuf::Message *pcMsgBody);

	/**----------------------------------------------------------------------
	* InsertMsgBody
	* 
	* @brief   在索引dwInsertBefore对应的消息体前插入一个消息体（慎用，性能不如AddMsgBody）
	* 
	* @param   [in] pcMsgBody 消息体
	* @param   [in] dwInsertBefore 消息体索引,从0开始
	* @return  BOOL32 ：插入是否成功
	------------------------------------------------------------------------*/
	BOOL32 InsertMsgBody(google::protobuf::Message *pcMsgBody, u32 dwInsertBefore);

	/**----------------------------------------------------------------------
	* GetMsgBody
	* 
	* @brief   获取指定的消息体
	* 
	* @param   [in] dwIndex 消息体索引号, 从0开始
	* @return  Message* ：消息体指针，失败返回NULL
	------------------------------------------------------------------------*/
	google::protobuf::Message* GetMsgBody(u32 dwIndex = 0);

	/**----------------------------------------------------------------------
	* Encode
	* 
	* @brief   编码
	* 
	* @param   [inout] pbyBuf 存放编码后数据的内存块
	* @param   [inout] wBufLen 内存块大小
	* @return  BOOL32 成功返回TRUE，失败返回FALSE
	------------------------------------------------------------------------*/
	BOOL32 Encode(u8 *pbyBuf, u16 &wBufLen);

	/**----------------------------------------------------------------------
	* Decode
	* 
	* @brief   解码
	* 
	* @param   [in] pbyBuf 存放待解码数据的内存块
	* @param   [in] wBufLen 内存块大小
	* @return  BOOL32 成功返回TRUE，失败返回FALSE
	------------------------------------------------------------------------*/
	BOOL32 Decode(u8 *pbyBuf, u16 wBufLen);

	/**----------------------------------------------------------------------
	* Clear
	* 
	* @brief   清空对象
	* 
	* @param   void
	* @return  void
	------------------------------------------------------------------------*/
	void Clear();

private:
	std::string              m_strMsgId;      ///<消息ID
	std::string              m_strSessionId;  ///<会话ID
	u32                      m_dwSequenceId;  ///<序列号		
	std::string              m_strUserData;   ///<用户自定义数据
	std::vector<std::string> m_vctReqPath;    ///<req消息的接力路径，req消息每经过一个发送者都要将此发送者加入req_path中，以便rsp消息按原路返回，当返回rsp消息时要逐个去掉
	std::vector<TBodyItem>   m_vctBodys;      ///<消息体
};

/**----------------------------------------------------------------------
* InitNvMsgLib
* 
* @brief   初始化消息编解码库
* 
* @param   void
* @return  BOOL32 成功返回TRUE，失败返回FALSE
------------------------------------------------------------------------*/
//lint -esym(714, nvmsg::InitNvMsgLib)
NVCBB_API BOOL32 InitNvMsgLib();

/**----------------------------------------------------------------------
* UnInitNvMsgLib
* 
* @brief   退出消息编解码库
* 
* @param   void
* @return  BOOL32 成功返回TRUE，失败返回FALSE
------------------------------------------------------------------------*/
//lint -esym(714, nvmsg::UnInitNvMsgLib)
NVCBB_API BOOL32 UnInitNvMsgLib();

/**----------------------------------------------------------------------
* GetEnumVauleName
* 
* @brief   获取枚举值得名称
* 
* @param   [in] T 枚举类型
* @param   [in] nValue 枚举值
* @return  s8* ：枚举值的名称 失败返回空字串""
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
* @brief   判断消息类型是否是命令
* 
* @param   [in] strMsgId 消息ID
* @return  BOOL32 TRUE:是命令类型， FALSE:不是命令类型
------------------------------------------------------------------------*/
NVCBB_API BOOL32 IsCmdMsg(std::string strMsgId);

/**----------------------------------------------------------------------
* IsNtfMsg
* 
* @brief   判断消息类型是否是通知
* 
* @param   [in] strMsgId 消息ID
* @return  BOOL32 TRUE:是通知类型， FALSE:不是通知类型
------------------------------------------------------------------------*/
NVCBB_API BOOL32 IsNtfMsg(std::string strMsgId);

/**----------------------------------------------------------------------
* IsReqMsg
* 
* @brief   判断消息类型是否是请求
* 
* @param   [in] strMsgId 消息ID
* @return  BOOL32 TRUE:是请求类型， FALSE:不是请求类型
------------------------------------------------------------------------*/
NVCBB_API BOOL32 IsReqMsg(std::string strMsgId);

/**----------------------------------------------------------------------
* IsRspMsg
* 
* @brief   判断消息类型是否是响应
* 
* @param   [in] strMsgId 消息ID
* @return  BOOL32 TRUE:是响应类型， FALSE:不是响应类型
------------------------------------------------------------------------*/
NVCBB_API BOOL32 IsRspMsg(std::string strMsgId);

}

#endif