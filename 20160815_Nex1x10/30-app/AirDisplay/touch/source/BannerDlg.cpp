// MainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "touch.h"
#include "BannerDlg.h"
#include "afxdialogex.h"
#include "touchDlg.h"
#include "language.h"

extern CtouchDlg * g_dlg;
// CBannerDlg �Ի���

#define CM_ELAPSE   200 //�������Ƿ��뿪���ڵ�ʱ����
#define HS_ELAPSE   5   //���ػ���ʾ����ÿ����ʱ����
#define HS_STEPS    10  //���ػ���ʾ���̷ֳɶ��ٲ�

#define INTERVAL    20  //����ճ��ʱ�������Ļ�߽����С���,��λΪ����
#define INFALTE     10  //��������ʱ����봰�ڱ߽����С���,��λΪ����
#define MINCX       200 //������С���
#define MINCY       400 //������С�߶�

#define STTBAR_LEN  342 //״̬������

//TimerId
#define HideTimerId 3
#define ShowTimerId 4
#define StatusBarTimerId 5

CBannerDlg::CBannerDlg(CWnd* pParent /*=NULL*/)
	: CBaseDlg(CBannerDlg::IDD, pParent)
{
	m_dwBkResourceID = IDB_BANNER_BK;
	//m_btnBannerClose.SetImage( IDB_BANNER_STOP, IDB_BANNER_STOP, IDB_BANNER_STOP, IDB_BANNER_STOP);
	
	m_staticBanner.SetFont(9, g_achDefaultFont);
	m_staticBanner.SetTextColor(Color(0,0,0));
	m_staticBanner.SetTextAlign(CTransparentStatic::emAlignmentCenter);
	m_staticBanner.SetOverShow(true, StringTrimmingEllipsisPath);

	/*m_btnBannerClose.SetFont(9, g_achDefaultFont);
	m_btnBannerClose.ShowText(TRUE);
	m_btnBannerClose.SetTextColor(Color(0,0,0), Color(30,148,218), Color(30,148,218), Color(0,0,0));
	m_btnBannerClose.SetTextPoint(CPoint(MULX(23), 0));*/

    m_pImgStatusBar = CUtility::GetImage( IDB_STATUS_BAR, _T("PNG") );
    m_staPicStatusBar.SetBkImage( m_pImgStatusBar );

	m_bIsSetTimer = FALSE;
	m_bIsFinished = TRUE;
	m_bIsHiding = FALSE;

	m_dwEdgeHeight = 0;
	m_dwEdgeWidth  =0;

    m_bShowStatusBar = FALSE;
}

void CBannerDlg::DoDataExchange(CDataExchange* pDX)
{
	//CDialogEx::DoDataExchange(pDX);
	CBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BANNER, m_staticBanner);
    //DDX_Control(pDX, IDC_BTN_BANNER_CLOSE, m_btnBannerClose );
	DDX_Control(pDX, IDC_STATUS_BAR, m_staPicStatusBar );
	
}

BEGIN_MESSAGE_MAP(CBannerDlg, CBaseDlg/*CDialogEx*/)
	//ON_BN_CLICKED(IDC_BTN_BANNER_CLOSE, OnBannerClose)
	ON_WM_TIMER()
	ON_WM_NCHITTEST()
	ON_WM_CREATE()
END_MESSAGE_MAP()

BOOL CBannerDlg::OnInitDialog()
{
	CBaseDlg::OnInitDialog();
	InitUI();
	SetWindowText(_T(DEF_TELNET_NAME));

	return TRUE;
}

BOOL CBannerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
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

void CBannerDlg::InitUI()
{
	int nWidthTmp = MULX(342+16);
	int nHeighTmp = MULY(32+8);

	int width = (GetSystemMetrics ( SM_CXSCREEN )-nWidthTmp)/2; 
	int height= (GetSystemMetrics ( SM_CYSCREEN )-nHeighTmp)/2; 
	CDialog::SetWindowPos( &wndTopMost, width, -m_dwEdgeHeight, nWidthTmp, nHeighTmp, SWP_HIDEWINDOW );

	m_staticBanner.SetWindowPos( NULL, MULX(57), MULY(8), MULX(244), MULY(16), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );
	//m_btnBannerClose.SetWindowPos( NULL, MULX(251), MULY(10), MULX(74), MULY(16), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );
    m_staPicStatusBar.SetWindowPos( NULL, MULX(8), MULY(36), MULX(342), MULY(4), SWP_HIDEWINDOW/*SWP_NOSIZE*/ );

	CString strName;
	if ( g_dlg != NULL )
	{
		strName = g_dlg->m_strSysUserName;
	}
	
	CString strDes = strName + STRING_PROJECTING;
	m_staticBanner.SetWindowText(strDes);

	//m_btnBannerClose.SetWindowText(STRING_STOP_PROJECTING);
	
}

void CBannerDlg::OnBannerClose()
{
	PRINTMSG_TIME("\r\n���ֹͣͶ����ť\r\n");
	g_dlg->StopProjectScreen(true);
}

int CBannerDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here

	//��ñ�Ե�߶ȺͿ��
	m_dwEdgeHeight = GetSystemMetrics(SM_CYEDGE);
	m_dwEdgeWidth  = 3/* GetSystemMetrics(SM_CXFRAME)*/;

	//�����������ȡ�ϴιرպ󱣴�Ĵ�С

	return 0;
}

LRESULT CBannerDlg::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bIsSetTimer &&
		//��ֹ��곬����Ļ�ұ�ʱ���ұ����������˸
		point.x < GetSystemMetrics(SM_CXSCREEN) + INFALTE)
	{   //������ʱ,����Ǵ�����״̬����ʾ״̬����Timer
		//SetTimer(HideTimerId,CM_ELAPSE,NULL);

        //����״̬��
        KillTimer(StatusBarTimerId);
        m_staPicStatusBar.SetStatusBarDraw(FALSE);
        m_staPicStatusBar.ShowWindow(SW_HIDE);

		m_bIsSetTimer = TRUE;

		m_bIsFinished = FALSE;
		m_bIsHiding = FALSE;
		SetTimer(ShowTimerId,HS_ELAPSE,NULL); //������ʾ����
	}
	return CDialog::OnNcHitTest(point);
}

void CBannerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == HideTimerId )
	{
		POINT curPos;
		GetCursorPos(&curPos);

		CRect tRect;
		//��ȡ��ʱ���ڴ�С
		GetWindowRect(tRect);
		//����tRect,�Դﵽ����뿪���ڱ���һ������Ŵ����¼�
		tRect.InflateRect(INFALTE,INFALTE); 

		if(!tRect.PtInRect(curPos)) //�������뿪���������
		{
			KillTimer(HideTimerId); //�رռ�����Timer
			m_bIsSetTimer = FALSE;

			m_bIsFinished = FALSE;			
			m_bIsHiding = TRUE;
			SetTimer(ShowTimerId,HS_ELAPSE,NULL); //������������
		}
	}

	if(nIDEvent == ShowTimerId)
	{
		if(m_bIsFinished) //�����������ʾ���������ر�Timer	  
		{
			KillTimer(ShowTimerId);
			//չ��״̬�ſ���5s�Զ�����
			if (!m_bIsHiding)
			{
				g_dlg->SetBannerAutoHide(); //5s�Զ�����
			}
		}
		else
		{	
			m_bIsHiding ? Hide() : Show();
		}
	}

    if (nIDEvent == StatusBarTimerId)
    {
        m_staPicStatusBar.RedrawStatusBar();
    }

	CDialog::OnTimer(nIDEvent);
}

void CBannerDlg::DoHide()
{
	SetTimer(HideTimerId,CM_ELAPSE,NULL);//SetTimer(HideTimerId, CM_ELAPSE, NULL);
}

void CBannerDlg::StopAutoHide()
{
	KillTimer(ShowTimerId);
	KillTimer(HideTimerId);
}

BOOL CBannerDlg::SetWindowPos(const CWnd* pWndInsertAfter, LPCRECT pCRect, UINT nFlags)
{
    if (m_bShowStatusBar)
    {
        u32 dwSliceNum = m_pImgStatusBar->GetWidth()/STTBAR_LEN;
        m_staPicStatusBar.SetStatusBarDraw(TRUE, dwSliceNum);
        m_staPicStatusBar.ShowWindow(SW_SHOW);
        SetTimer(StatusBarTimerId,100,NULL);
    }

	return CDialog::SetWindowPos(pWndInsertAfter,pCRect->left, pCRect->top,
		pCRect->right - pCRect->left, pCRect->bottom - pCRect->top, nFlags);
}

void CBannerDlg::Hide()
{
	CRect tRect;
	GetWindowRect(tRect);

	INT height = tRect.Height();
	INT width  = tRect.Width();

	INT steps = 0;

	steps = height/HS_STEPS;
	tRect.bottom -= steps;
	if(tRect.bottom <= m_dwEdgeWidth)
	{   //����԰�����һ���滻����� ...+=|-=steps �ﵽȡ������Ч��
		//���õİ취����Ӹ�BOOLֵ������,����caseͬ��.
		tRect.bottom = m_dwEdgeWidth;
		m_bIsFinished = TRUE;  //������ع���
        m_bShowStatusBar = TRUE;
	}
	tRect.top = tRect.bottom - height; 

	SetWindowPos(&wndTopMost,tRect);
}

void CBannerDlg::Show()
{
    m_bShowStatusBar = FALSE;

	CRect tRect;
	GetWindowRect(tRect);
	INT height = tRect.Height();
	INT width  = tRect.Width();

	INT steps = 0;
	steps = height/HS_STEPS;
	tRect.top += steps;
	if(tRect.top >= -m_dwEdgeHeight)
	{   //����԰�����һ���滻����� ...+=|-=steps �ﵽȡ������Ч��
		//���õİ취����Ӹ�BOOLֵ������,����caseͬ��.
		tRect.top = -m_dwEdgeHeight;
		m_bIsFinished = TRUE;  //�����ʾ����
	}
	tRect.bottom = tRect.top + height;

	SetWindowPos(&wndTopMost,tRect);
}
