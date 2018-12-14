#ifndef _TRANSPARENTGIF_H_
#define _TRANSPARENTGIF_H_

#include "Utility.h"
#include "uicommon.h"

class CTransparentGif : public CStatic
{
public:
	CTransparentGif();
	~CTransparentGif();

	void SetImage( UINT dwResID);
	void SetTimerDelay(UINT nDelay = 300);//���ö�ʱ�������ͨ��������ԴID���ʹ��

	BOOL SetImage( LPCTSTR szFileName);
	
	void ShowGif();
	void StopGif();

protected:
	afx_msg LRESULT OnRedrawUI( WPARAM wParam, LPARAM lParam );
	afx_msg void OnTimer(UINT nIDEvent);
	DECLARE_MESSAGE_MAP()

protected:
	void ThreadAnimation();
	static UINT WINAPI _ThreadAnimation(LPVOID pParam);
	void GetImageFromSource(UINT nID, Image*& image, LPCTSTR lpszType);


	HWND    m_hParent;
	UINT    m_dwResID;

	Image   *m_pImage;
	UINT    m_FrameCount;			//֡��
	int	    m_nFramePos;			//����һ����ʱ���ͱ���
	GUID    m_guid;
	Graphics *m_pGraphics;
	UINT	m_nDelay;			    //��ʱ�����,�ο�PictureEx�е�WaitForSingleObject���

	HANDLE m_hThread;
	volatile BOOL m_bExitThread;
	HANDLE m_hExitEvent;
	POINT m_point;
	HGLOBAL m_hMem;
	bool m_bIsPlaying;//�Ƿ�������ʾgif
	
};


#endif//_TRANSPARENTGIF_H_