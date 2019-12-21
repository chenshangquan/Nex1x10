#ifndef _NVXMLRPCEX_H_
#define _NVXMLRPCEX_H_

#include "XmlRpc.h"
#include "nvlog.h"

# ifdef _LINUX_P_
class CNVXmlRpcErrorHandler : public XmlRpc::XmlRpcErrorHandler
{
public:	
	CNVXmlRpcErrorHandler( BOOL32 bAuto = TRUE )
	{
		m_pcDefaultRpcErrorHanlder = XmlRpc::XmlRpcErrorHandler::getErrorHandler();
		m_bAuto = bAuto;
		if ( TRUE == m_bAuto )
		{
			Init();
		}
	}
	~CNVXmlRpcErrorHandler()
	{
		if ( TRUE == m_bAuto )
		{
			Exit();
		}
	}
	virtual void error(const char* msg)
	{
		NVLOG::NvLogErr( MDL_XMLRPC, msg );
	}

	void Init()
	{
		m_pcDefaultRpcErrorHanlder = XmlRpc::XmlRpcErrorHandler::getErrorHandler();
		XmlRpc::XmlRpcErrorHandler::setErrorHandler( this );
	}

	void Exit()
	{
		XmlRpc::XmlRpcErrorHandler::setErrorHandler( m_pcDefaultRpcErrorHanlder );
	}

protected:
	XmlRpc::XmlRpcErrorHandler *m_pcDefaultRpcErrorHanlder;
	BOOL32 m_bAuto;
};
#else
class CNVXmlRpcErrorHandler
{
public:
	CNVXmlRpcErrorHandler( BOOL32 bAuto = TRUE )
	{
	}
	void Init()
	{
	}

	void Exit()
	{
	}
};
#endif

#endif // _NVXMLRPCEX_H_