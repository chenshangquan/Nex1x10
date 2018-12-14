// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "touch.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "touchDlg.h"

extern CtouchDlg * g_dlg;
// CMainDlg 对话框

IMPLEMENT_DYNAMIC(CMainDlg, CBaseDlg)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CBaseDlg(CMainDlg::IDD, pParent)
{
	m_dwBkResourceID = IDB_MAINBK;
	m_btnMin.SetImage( IDR_BTN_MIN_NORMAL, IDR_BTN_MIN_PRESS, IDR_BTN_MIN_HOVER, IDR_BTN_MIN_NORMAL);
	m_btnClose.SetImage( IDR_BTN_CLOSE_NORMAL, IDR_BTN_CLOSE_PRESS, IDR_BTN_CLOSE_HOVER, IDR_BTN_CLOSE_NORMAL);
	m_btnPicBk.SetImage( IDB_CONNECT_BK, IDB_CONNECT_BK, IDB_CONNECT_BK,IDB_CONNECT_BK);
	m_btnPicConnectFail.SetImage( IDB_CONNECT_FAIL, IDB_CONNECT_FAIL,IDB_CONNECT_FAIL,IDB_CONNECT_FAIL);
	m_btnPicBkUpgrade.SetImage( IDB_UPGRADE_BK, IDB_UPGRADE_BK, IDB_UPGRADE_BK,IDB_UPGRADE_BK);
	m_pImgBK = CUtility::GetImage( IDB_MAINBK, _T("PNG") );
	m_staticPic.SetBkImage( m_pImgBK );

	m_stTitle.SetFont(11, g_achDefaultFont);
	m_stTitle.SetTextColor(DEFAULT_FONT_COLOR);
	
	m_stTip.SetFont(13, g_achDefaultFont);
	m_stTip.SetTextColor(DEFAULT_FONT_COLOR);
	m_stTip.SetTextAlign(CTransparentStatic::emAlignmentCenter);

	m_stTipDes.SetFont(10, g_achDefaultFont);
	m_stTipDes.SetTextColor(TIP_DES_FONT_COLOR);
	m_stTipDes.SetTextAlign(CTransparentStatic::emAlignmentCenter);

	m_stUpgradeTip1.SetFont(11, g_achDefaultFont);
	m_stUpgradeTip1.SetTextColor(DEFAULT_FONT_COLOR);
	
	m_stUpgradeTip2.SetFont(11, g_achDefaultFont);
	m_stUpgradeTip2.SetTextColor(DEFAULT_FONT_COLOR);
	
	m_linkIgnore.SetFont(10, g_achDefaultFont);
	m_linkIgnore.SetTextColor(UPGRADE_FONT_COLOR);

	m_bIsShowUpgrade = false;
}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TITLE, m_stTitle);
	DDX_Control(pDX, IDC_STATIC_TIP, m_stTip);
	DDX_Control(pDX, IDC_STATIC_TIP_DES, m_stTipDes);
	DDX_Control(pDX, IDC_BTNMIN, m_btnMin);
	DDX_Control(pDX, IDC_BTNCLOSE, m_btnClose);
	DDX_Control(pDX, IDC_BTN_PIC_BK, m_btnPicBk);
	DDX_Control(pDX, IDC_PIC_MAIN, m_staticPic);
	DDX_Control(pDX, IDC_BTN_PIC_FAIL, m_btnPicConnectFail);
	DDX_Control(pDX, IDC_PIC_CONNECT_SUCCESS, m_stGifConnectSuccess);
	DDX_Control(pDX, IDC_PIC_CONNECTING, m_stGifConnecting);
	DDX_Control(pDX, IDC_BTN_PIC_UPGRADE, m_btnPicBkUpgrade);
	DDX_Control(pDX, IDC_STATIC_UPGRADE_TIP1, m_stUpgradeTip1);
	DDX_Control(pDX, IDC_STATIC_UPGRADE_TIP2, m_stUpgradeTip2);
	DDX_Control(pDX, IDC_SYSLINK_IGNORE, m_linkIgnore);
}

BEGIN_MESSAGE_MAP(CMainDlg, CBaseDlg)
	ON_BN_CLICKED(IDC_BTNMIN, &CMainDlg::OnBnMin)
	ON_BN_CLICKED(IDC_BTNCLOSE, &CMainDlg::OnBtnClose)
	ON_WM_PAINT()
	ON_WM_NCHITTEST()
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK_IGNORE, &CMainDlg::OnNMClickSyslinkIgnore)
END_MESSAGE_MAP()

// CMainDlg 消息处理程序

BOOL CMainDlg::OnInitDialog()
{
	int nWidthTmp = MULX(500);
	int nHeighTmp = MULY(300);
	int width = (GetSystemMetrics ( SM_CXSCREEN )-nWidthTmp)/2; 
	int height= (GetSystemMetrics ( SM_CYSCREEN )-nHeighTmp)/2; 
	SetWindowPos( NULL, width, height, nWidthTmp, nHeighTmp, SWP_SHOWWINDOW/*SWP_NOMOVE*/ );

	CBaseDlg::OnInitDialog();
	InitUI();
	SetWindowText(_T("touch"));
	
	ShowConnectStatus(NET_STATUS_CONNECTING);

	return TRUE;
}


BOOL CMainDlg::PreTranslateMessage( MSG* pMsg )
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if ( VK_RETURN == pMsg->wParam
			|| VK_SPACE == pMsg->wParam
			|| VK_ESCAPE == pMsg->wParam)
		{
			return TRUE;
		}
	}
	return CBaseDlg::PreTranslateMessage(pMsg);
}

void CMainDlg::InitUI()
{
	m_stTitle.SetWindowPos( NULL, MULX(16), MULY(15), 0, MULY(16), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );
	m_btnMin.SetWindowPos( NULL, MULX(431), MULY(1), MULX(30), MULY(35), SWP_HIDEWINDOW/*SWP_NOSIZE*/ );
	m_btnClose.SetWindowPos( NULL, MULX(463),MULY(1), MULX(30), MULY(35), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );

	m_stTip.SetWindowPos( NULL, 0, MULY(64), MULX(500), MULY(18), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );
	
	int nTipDesTop = MULY(64 + 18 + 8);
	m_stTipDes.SetWindowPos( NULL, 0, nTipDesTop, MULX(500), MULY(16), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );

	m_btnPicBk.SetWindowPos( NULL, MULX(45), MULY(115), MULX(410), MULY(130), SWP_HIDEWINDOW );
	m_stGifConnecting.SetWindowPos( NULL, MULX(215), MULY(187), MULX(70), MULY(6), SWP_HIDEWINDOW );
	m_btnPicConnectFail.SetWindowPos( NULL, MULX(215), MULY(179), MULX(70), MULY(22), SWP_HIDEWINDOW );
	m_stGifConnectSuccess.SetWindowPos( NULL, MULX(45), MULY(115), MULX(410), MULY(130), SWP_HIDEWINDOW );
	m_btnPicBkUpgrade.SetWindowPos( NULL, MULX(50), MULY(135), MULX(204), MULY(115), SWP_HIDEWINDOW );
	m_stUpgradeTip1.SetWindowPos( NULL, MULX(260), MULY(135), MULX(235), MULY(16), SWP_HIDEWINDOW );
	m_stUpgradeTip2.SetWindowPos( NULL, MULX(267), MULY(161), MULX(225), MULY(16), SWP_HIDEWINDOW );
	m_linkIgnore.SetWindowPos( NULL, MULX(295), MULY(201), MULX(200), MULY(16), SWP_HIDEWINDOW );

	m_stGifConnectSuccess.SetImage(IDR_GIF_CONNECT_SUCCESS);
	m_stGifConnectSuccess.SetTimerDelay(50);

	m_stGifConnecting.SetImage(IDR_GIF_CONNECTING);
}

LRESULT CMainDlg::OnNcHitTest(CPoint point)
{
	return HTCAPTION;
}

void CMainDlg::OnBnMin()
{
	g_dlg->OnMini();
}

void CMainDlg::OnBtnInfo()
{
	g_dlg->OnAbout();
}

void CMainDlg::OnBtnClose()
{
	g_dlg->OnHide();
}

void CMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here
	//RedrawUI( &dc );
}

void CMainDlg::ShowConnectStatus(NET_STATUS emNetStatus)
{
	if ( m_bIsShowUpgrade )
	{
		return;
	}

	switch (emNetStatus)
	{
	case NET_STATUS_CONNECTING:
		{
			m_stTip.SetWindowText(_T("正在连接显示端"));
			m_stTipDes.SetWindowText(_T(""));
			ShowConnectPicture(CONNECTING);
		}
		break;
	case NET_STATUS_CONNECTED:
		{
			m_stTip.SetWindowText(_T("已连接显示端"));
			m_stTipDes.SetWindowText(_T("按压无线投屏发射器开始投屏，再次按压结束投屏"));
			ShowConnectPicture(CONNECT_SUCESS);
		}
		break;
	case NET_STATUS_DISCONNECTED:
		{
			m_stTip.SetWindowText(_T("连接已断开"));
			m_stTipDes.SetWindowText(_T("请检查会议热点网络"));
			ShowConnectPicture(CONNECT_FAIL);
		}
		break;
	case NET_STATUS_NO_NETWORK:
		{
			m_stTip.SetWindowText(_T("搜索不到热点"));
			m_stTipDes.SetWindowText(_T("请检查网络连接"));
			ShowConnectPicture(CONNECT_FAIL);
		}
		break;
	case NET_STATUS_NO_MATCH:
		{
			m_stTip.SetWindowText(_T("未与显示端配对"));
			m_stTipDes.SetWindowText(_T("请将无线投屏发射器，插入显示端的USB1或者USB2接口，完成配对"));
			ShowConnectPicture(CONNECT_FAIL);
		}
		break;
	case NET_STATUS_ENOUGHNUM:
		{
			m_stTip.SetWindowText(_T("连接失败"));
			m_stTipDes.SetWindowText(_T("当前接收端已达到8方投屏连接限制"));
			ShowConnectPicture(CONNECT_FAIL);
		}
		break;
	case NET_STATUS_RESETQUICKSHARE:
		{
			m_stTip.SetWindowText(_T("无法连接显示端"));
			m_stTipDes.SetWindowText(_T("请拔掉无线投屏发射器，重新接入电脑"));
			ShowConnectPicture(CONNECT_FAIL);
		}
		break;
	case NET_STATUS_RESETWIFI:
		{
			m_stTip.SetWindowText(_T("连接已断开"));
			m_stTipDes.SetWindowText(_T("网络重连中，请稍候..."));
			ShowConnectPicture(CONNECT_FAIL);
		}
		break;

	}
}

void CMainDlg::ShowConnectPicture(CONNECT_STATUS emConnectStatus)
{
	ShowUpgradeControl( false );

	switch (emConnectStatus)
	{
	case CONNECT_SUCESS:
		{
			m_stGifConnectSuccess.ShowGif();
			m_stGifConnectSuccess.ShowWindow(SW_SHOW);

			m_btnPicBk.ShowWindow(SW_HIDE);
			m_btnPicConnectFail.ShowWindow(SW_HIDE);
		    m_stGifConnecting.StopGif();
			m_stGifConnecting.ShowWindow(SW_HIDE);
		}
		break;
	case CONNECT_FAIL:
		{
			m_btnPicBk.ShowWindow(SW_SHOW);
			m_btnPicConnectFail.ShowWindow(SW_SHOW);

			m_stGifConnecting.StopGif();
			m_stGifConnecting.ShowWindow(SW_HIDE);
			m_stGifConnectSuccess.StopGif();
			m_stGifConnectSuccess.ShowWindow(SW_HIDE);
		}
		break;
	case CONNECTING:
		{
			m_btnPicBk.ShowWindow(SW_SHOW);
			m_stGifConnecting.ShowGif();
			m_stGifConnecting.ShowWindow(SW_SHOW);

			m_btnPicConnectFail.ShowWindow(SW_HIDE);
			m_stGifConnectSuccess.StopGif();
			m_stGifConnectSuccess.ShowWindow(SW_HIDE);
		}
		break;
	case CONNECT_BUSINESS_FAIL:
		{
			m_stTip.SetWindowText(_T("发射器业务进程异常"));
			m_stTipDes.SetWindowText(_T("请将无线投屏发射器重新插入PC"));
			
			m_btnPicBk.ShowWindow(SW_SHOW);
			m_btnPicConnectFail.ShowWindow(SW_SHOW);

			m_stGifConnecting.StopGif();
			m_stGifConnecting.ShowWindow(SW_HIDE);
			m_stGifConnectSuccess.StopGif();
			m_stGifConnectSuccess.ShowWindow(SW_HIDE);
		}
		break;
	}
}

void CMainDlg::ShowUpgradeControl( bool bShow )
{
	m_bIsShowUpgrade = bShow;

	int nShow = SW_HIDE;
	if ( bShow )
	{
		nShow = SW_SHOW;
		m_stTip.SetWindowText(_T("发现无线投屏器新版本"));
		m_stTipDes.SetWindowText(_T(""));

		m_btnPicBk.ShowWindow(SW_HIDE);
		m_btnPicConnectFail.ShowWindow(SW_HIDE);
		m_stGifConnecting.StopGif();
		m_stGifConnecting.ShowWindow(SW_HIDE);
		m_stGifConnectSuccess.StopGif();
		m_stGifConnectSuccess.ShowWindow(SW_HIDE);
	}

	m_stUpgradeTip1.ShowWindow(nShow);
	m_stUpgradeTip2.ShowWindow(nShow);
	m_linkIgnore.ShowWindow(nShow);
	m_btnPicBkUpgrade.ShowWindow(nShow);
}

void CMainDlg::OnNMClickSyslinkIgnore( NMHDR *pNMHDR, LRESULT *pResult )
{
	*pResult = 0;
	
	if ( g_dlg != NULL )
	{
		m_bIsShowUpgrade = false;
		ShowConnectStatus(g_dlg->m_bCurConnetStatus);
	}
}

void CMainDlg::HideUpgradeControlUI()
{
	if ( m_bIsShowUpgrade )
	{
		m_bIsShowUpgrade = false;
		ShowConnectStatus(g_dlg->m_bCurConnetStatus);
	}
}
