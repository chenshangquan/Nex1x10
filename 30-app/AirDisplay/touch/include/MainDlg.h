#pragma once
#include "dynamicwnd.h"
#include "transtatic.h"
#include "afxwin.h"


typedef enum _emCONNECT_STATUS
{
	CONNECT_SUCESS = 0,
	CONNECT_FAIL,
	CONNECTING,
	CONNECT_SCREEN_PROJECTING,      //投屏中
	CONNECT_BUSINESS_FAIL,          //业务挂掉
    CONNECT_OVER_RESOLUTION_LIMIT,  //超出限制分辨率投屏
    CONNECT_NT30_MT_NONSUPPORT,     //商密终端不支持投屏
    CONNECT_NT30_PAIR_HELP,         //配对帮助
}CONNECT_STATUS;


// CMainDlg 对话框

class CMainDlg : public CBaseDlg
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainDlg();

// 对话框数据
	enum { IDD = IDD_MAINFRAME };
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//显示连接状态
	void ShowConnectStatus(NET_STATUS emNetStatus);
	//显示连接的图片
	void ShowConnectPicture(CONNECT_STATUS emConnectStatus);
	//显示升级控件
	void ShowUpgradeControl( bool bShow );
	//隐藏升级界面
	void HideUpgradeControlUI();
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	LRESULT OnNcHitTest(CPoint point);//点击窗口的任意位置都显示
	afx_msg void OnBnMin();
	afx_msg void OnBtnInfo();
	afx_msg void OnBtnClose();
    afx_msg void OnBtnIgnoreUpgrade();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedBtnUpgrade();
	afx_msg void OnNMClickSyslinkIgnore(NMHDR *pNMHDR, LRESULT *pResult);
	
	DECLARE_MESSAGE_MAP()

private:
	void InitUI();

private:
	Image   *m_pImgBK;

	CTransparentStatic	m_stTitle;
	CTransparentStatic	m_stTip;
	CTransparentStatic	m_stTipDes;
	CTransparentBtn	m_btnMin;
	CTransparentBtn	m_btnClose;
	CTransparentBtn	m_btnPicBk;
	CTransparentBtn	m_btnPicConnectFail;
    CTransparentBtn m_btnPicStatus;
	CTranStatic	m_staticPic;
	CTransparentGif m_stGifConnectSuccess;
	CTransparentGif m_stGifConnecting;
	//升级提示相关
	CTransparentBtn m_btnIgnoreUpgrade;
	/*CTransparentStatic	m_stUpgradeTip1;
	CTransparentStatic	m_stUpgradeTip2;
	CTransparentSysLink m_linkIgnore;*/

	bool m_bIsShowUpgrade;//升级控件是否已经显示

};
