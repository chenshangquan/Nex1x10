#pragma once
#include "dynamicwnd.h"
#include "transtatic.h"
#include "afxwin.h"
#include "afxcmn.h"


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CBaseDlg//CDialogEx
{
public:
	//CAboutDlg();
	CAboutDlg(CWnd* pParent = NULL); 

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };
	
	static void GetBuildVersion(s8 achVersion[MAX_VER_LEN]);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
    LRESULT OnNcHitTest(CPoint point);//������ڵ�����λ�ö���ʾ
	afx_msg void OnNMClickSyslinkCompany(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBtnClose();
	DECLARE_MESSAGE_MAP()

	void InitUI();

private:
	CTransparentBtn	m_btnClose;

	CTransparentStatic m_stPicLog;

	CTransparentStatic m_staticName;
	CTransparentStatic m_staticCompany;
	CTransparentStatic m_staticDes;
	CTransparentStatic m_staticVer;
	CTransparentSysLink m_linkCompany;
	
};