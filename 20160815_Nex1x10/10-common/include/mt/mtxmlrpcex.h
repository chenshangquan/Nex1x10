#ifndef _MTXMLRPCEX_H_
#define _MTXMLRPCEX_H_

#include "XmlRpc.h"
#include "mtlog.h"

# ifdef _LINUX_P_
class CMTXmlRpcErrorHandler : public XmlRpc::XmlRpcErrorHandler
{
public:	
	CMTXmlRpcErrorHandler( BOOL32 bAuto = TRUE )
	{
		m_pcDefaultRpcErrorHanlder = XmlRpc::XmlRpcErrorHandler::getErrorHandler();
		m_bAuto = bAuto;
		if ( TRUE == m_bAuto )
		{
			Init();
		}
	}
	~CMTXmlRpcErrorHandler()
	{
		if ( TRUE == m_bAuto )
		{
			Exit();
		}
	}
	virtual void error(const char* msg)
	{
		MTLOG::MtLogErr( MDL_XMLRPC, msg );
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
class CMTXmlRpcErrorHandler
{
public:
	CMTXmlRpcErrorHandler( BOOL32 bAuto = TRUE )
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

#endif // _MTXMLRPCEX_H_