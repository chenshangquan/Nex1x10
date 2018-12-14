#pragma once
#include "dynamicwnd.h"
#include "transtatic.h"


// ����Ӧ�ó��򡰹��ڡ��˵���� CBannerDlg �Ի���

class CBannerDlg : public CBaseDlg//CDialogEx
{
public:
	//CBannerDlg();
	CBannerDlg(CWnd* pParent = NULL); 

	// �Ի�������
	enum { IDD = IDD_BANNER_DLG };
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	void DoHide();
	void StopAutoHide();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	virtual void OnBannerClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	
	BOOL SetWindowPos(const CWnd* pWndInsertAfter,LPCRECT pCRect, UINT nFlags = SWP_SHOWWINDOW);
	void Hide();
	void Show();

	DECLARE_MESSAGE_MAP()

private:
	void InitUI();

private:
	CTransparentBtn m_btnBannerClose;
	CTransparentStatic m_staticBanner;

	BOOL m_bIsSetTimer;      //�Ƿ������˼������Timer
	int  m_dwEdgeHeight;     //��Ե�߶�
	int  m_dwEdgeWidth;      //��Ե���
	BOOL m_bIsFinished;      //���ػ���ʾ�����Ƿ����
	BOOL m_bIsHiding;        //�ò���ֻ����!m_hsFinished����Ч,��:��������,��:������ʾ
};