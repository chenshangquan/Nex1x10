#ifndef _MESSAGESTRUCT_H_
#define _MESSAGESTRUCT_H_

#include "umconst.h"
#include "osp.h"
#include "md5.h"
#include "protocolcommonpublic.h"

#ifdef WIN32
    #pragma pack( push )
    #pragma pack( 1 )
#endif
API void umver();
class CLoginRequest
{
private:
	char		m_achname[MAX_CHARLENGTH + 1]; //用户名
	char		m_achpassword[MAX_CHARLENGTH + 1];//密码
	CMD5Encrypt m_cMd5;
public:
	CLoginRequest()
	{
		memset(m_achname,0,MAX_CHARLENGTH + 1 );
		memset(m_achpassword,0,MAX_CHARLENGTH + 1 );
	}
	//设置和得到用户名
	char* GetName()
	{
		return m_achname;
	}
	void  SetName(char* pchbuf)
	{
		if(pchbuf == NULL)
		{
			return;
		}
		memset(m_achname,0,MAX_CHARLENGTH + 1);
		int nlength = (strlen(pchbuf) >= MAX_CHARLENGTH ? MAX_CHARLENGTH: strlen(pchbuf));
		memcpy(m_achname,pchbuf,nlength);
		m_achname[nlength] = '\0';
	};
	//设置和得到密码
	char* GetPassword()
	{
		return m_achpassword;
	}
	//输入密码为明文
	void  SetPassword(char* pchbuf)
	{
		
		m_cMd5.GetEncrypted(pchbuf,m_achpassword);
		m_achpassword[MAX_CHARLENGTH]='\0';
	}
	//输入的密码已经加密了
	void SetEncryptedPassword(char* pchbuf)
	{
		if(pchbuf == NULL)
		{
			return;
		}
		memset(m_achpassword,0,MAX_CHARLENGTH + 1);
		int nlength = (strlen(pchbuf) >= MAX_CHARLENGTH ? MAX_CHARLENGTH: strlen(pchbuf));
		memcpy(m_achpassword,pchbuf,nlength);
		m_achpassword[nlength]='\0';
	}
	void Empty()
	{
		memset(m_achname,0,MAX_CHARLENGTH+1);
		memset(m_achpassword,0,MAX_CHARLENGTH+1);
	}
}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
;

class PROTO_API CUserFullInfo
{
// private:
public: // 方便计算成员大小 [pengguofeng 5/9/2013]
	CMD5Encrypt m_cMd5;
public:
	u32         m_dwGuid;	//每个名字唯一对应一个guid
	char		m_achname[MAX_CHARLENGTH+1]; //用户名
	char		m_achpassword[MAX_CHARLENGTH+1];//密码
	u8			m_byActor;//权限
	char		m_achfullname[MAX_CHARLENGTH+1];//完整用户名
	char		m_achdiscription[2*MAX_CHARLENGTH+1];//用户描述
public:
	CUserFullInfo()
	{
		Empty();
	}
	~CUserFullInfo(){};
	//得到用户名
	char* GetName()
	{
		m_achname[MAX_CHARLENGTH] = '\0';
		return m_achname;
	}
	//设置用户名
	void  SetName(char* pchbuf)
	{
		if(pchbuf == NULL)return;
		memset(m_achname,0,MAX_CHARLENGTH+1);
		int nlength = (strlen(pchbuf) >= MAX_CHARLENGTH ? MAX_CHARLENGTH: strlen(pchbuf));
		memcpy(m_achname,pchbuf,nlength);
		m_achname[nlength] = '\0';
	}
	//得到密码
	char* GetPassword()
	{
		return m_achpassword;
	}
	//设置密码
	void  SetPassword(char* pchbuf)
	{
		m_cMd5.GetEncrypted(pchbuf,m_achpassword);
		m_achpassword[MAX_CHARLENGTH]='\0';
	}
	//已经加密的密码
	void  SetEncryptedPassword(char* pchbuf)
	{
		memcpy(m_achpassword,pchbuf,MAX_CHARLENGTH+1);
		m_achpassword[MAX_CHARLENGTH]='\0';
	}
	//得到用户完整名
	char* GetFullName()
	{
		return m_achfullname;
	}
	//设置用户完整名
	void SetFullName(char* pchbuf)
	{
		if(pchbuf == NULL)return;
		memset(m_achfullname,0,MAX_CHARLENGTH+1);
		int nlength = (strlen(pchbuf) >= MAX_CHARLENGTH ? MAX_CHARLENGTH: strlen(pchbuf));
		memcpy(m_achfullname,pchbuf,nlength);
		m_achfullname[nlength] = '\0';
	}
	//得到用户描述
	char* GetDiscription()
	{
		return m_achdiscription;
	}
	
	//设置用户描述
	void SetDiscription(char* pchbuf)
	{
		if(pchbuf == NULL)return;
		memset(m_achdiscription,0, 2*MAX_CHARLENGTH+1);
		int nlength = (strlen(pchbuf) >= 2*MAX_CHARLENGTH ?  2*MAX_CHARLENGTH: strlen(pchbuf));
		memcpy(m_achdiscription,pchbuf,nlength);
		m_achdiscription[nlength] = '\0';
	}
	//得到权限
	unsigned char   GetActor(){return m_byActor;}
	//设置权限
	void  SetActor(unsigned char byActor){ m_byActor = byActor;}
	//对象赋值
	const CUserFullInfo& operator=(const CUserFullInfo& cNewInfo)
	{
		if (this != &cNewInfo)
		{
			memcpy(this, &cNewInfo, sizeof(CUserFullInfo));
		}
		return *this;
	}

	// 取所有成员的长度 [pengguofeng 5/14/2013]
	unsigned char GetMemLen( const unsigned char &byMemId )
	{
		u8 byRet = 0;
		switch ( byMemId)
		{
		case 0:
			byRet = sizeof(m_cMd5.context.state);
			break;
		case 1:
			byRet = sizeof(m_cMd5.context.count);
			break;
		case 2:
			byRet = sizeof(m_cMd5.context.buffer);
			break;
		case 3:
			byRet = sizeof(m_achname);
			break;
		case 4:
			byRet = sizeof(m_achpassword);
			break;
		case 5:
			byRet = sizeof(m_byActor);
			break;
		case 6:
			byRet = sizeof(m_achfullname);
			break;
		case 7:
			byRet = sizeof(m_achdiscription);
			break;
		case 8:
			byRet = sizeof(m_dwGuid);
			break;
		case 9:
//			byRet = sizeof(add2);
			break;
		default:
			break;
		}

		return byRet;
	}
	//判断某一个成员是否为字符串,0 1 2都是MD5的信息，不作修改
	bool IsMemString(const unsigned char &byMemId)
	{
		if ( byMemId == 3
			|| byMemId == 4
			|| byMemId == 6
			|| byMemId == 7
		/*	|| byMemId == 8
			|| byMemId == 9
		*/
			)
		{
			return TRUE;
		}
		return FALSE;
	}
	//判断用户名是否相同
	bool IsEqualName(char* cNewName)
	{
		if (strlen(m_achname) != strlen(cNewName) || strlen(cNewName) == 0 )
			return FALSE;
		for (unsigned int dwIndex=0 ; dwIndex< strlen(m_achname) ; dwIndex++)
		{
			if (m_achname[dwIndex] != cNewName[dwIndex])
				return FALSE;
		}
		return TRUE;
	}	
	//判断口令是否相同
	bool IsPassWordEqual(char* pchNewPass)
	{
		size_t dwLen = strlen( pchNewPass );
		if ( dwLen > strlen(m_achpassword) )
		{
			dwLen = strlen(m_achpassword);
		}
		for (size_t i=0 ; i< dwLen; i++)
		{
			if (m_achpassword[i] != pchNewPass[i])
				return FALSE;
		}
		return TRUE;
	}
	//找到空的
	bool IsEmpty()
	{
		if ( strlen(m_achpassword) > 16 )
		      return FALSE;
		return TRUE;
	}
	//清空
	void Empty()
	{
		memset(this, 0, sizeof(CUserFullInfo));
		m_byActor = UM_OPERATOR;
	}	

}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
;
class CLongMessage
{
public:
	u8 m_uTotal; //信息总帧数
	u8 m_uCurr;  //当前帧指示
	u8 m_uNumUsr;//当前帧中的用户数
public:
	CLongMessage()
	{
		Reset();
	}
	~CLongMessage(){};
public:
	void Reset()
	{
		m_uTotal = 0;
		m_uCurr =  0;
		m_uNumUsr = 0;
	}
}
#if defined(_VXWORKS_) || defined(_LINUX_)
__attribute__ ( (packed) ) 
#endif // _VXWORKS_
;
#ifdef WIN32
#pragma pack( pop )
#endif
#endif
