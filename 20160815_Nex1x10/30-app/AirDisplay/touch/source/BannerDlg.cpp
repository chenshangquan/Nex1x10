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

//TimerId
#define HideTimerId 3
#define ShowTimerId 4
#define StatusBarTimerId 5

static bool LoadImageFromResource(IN CImage* pImage,
    IN INT nResID = 196, IN LPCWSTR lpTyp = L"RCPNG" )
{
    if ( pImage == NULL )
    {
        return false;
    }
    pImage->Destroy();

    //������Դ
    HRSRC hResource = FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(196), L"PNG");
    if ( hResource == NULL )
    {
        int res = GetLastError();
        PRINTMSG("FindResource Err:%d\r\n", res);
        return FALSE;
    }

    //������Դ
    HGLOBAL hImgData = ::LoadResource(AfxGetResourceHandle(), hResource);
    if ( hImgData == NULL )
    {
        int res = GetLastError();
        PRINTMSG("LoadResource Err:%d\r\n", res);
        ::FreeResource(hImgData);
        return false;
    }

    //�����ڴ��е�ָ����Դ
    LPVOID lpVoid = ::LockResource(hImgData);

    LPSTREAM pStream = NULL;
    DWORD dwSize = ::SizeofResource(AfxGetResourceHandle(), hResource);
    HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
    LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
    ::memcpy(lpByte, lpVoid, dwSize);

    //����ڴ��е�ָ����Դ
    ::GlobalUnlock(hNew);

    //��ָ���ڴ洴��������
    HRESULT ht = ::CreateStreamOnHGlobal(hNew, TRUE, &pStream);
    if (ht = S_OK)
    {
        GlobalFree(hNew);
    }
    else
    {
        //����ͼƬ
        pImage->Load(pStream);
        GlobalFree(hNew);
    }

    //�ͷ���Դ
    ::FreeResource(hImgData);
    return true;
}

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

    //m_btnBannerStatusBar.SetImage(IDB_STATUS_BAR, IDB_STATUS_BAR, IDB_STATUS_BAR, IDB_STATUS_BAR);

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
	DDX_Control(pDX, IDC_BTN_BANNER_CLOSE, m_btnBannerStatusBar );
	
}

BEGIN_MESSAGE_MAP(CBannerDlg, CBaseDlg/*CDialogEx*/)
	ON_BN_CLICKED(IDC_BTN_BANNER_CLOSE, OnBannerClose)
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
	int nWidthTmp = MULX(346);
	int nHeighTmp = MULY(35);

	int width = (GetSystemMetrics ( SM_CXSCREEN )-nWidthTmp)/2; 
	int height= (GetSystemMetrics ( SM_CYSCREEN )-nHeighTmp)/2; 
	CDialog::SetWindowPos( &wndTopMost, width, -m_dwEdgeHeight, nWidthTmp, nHeighTmp, SWP_HIDEWINDOW );

	m_staticBanner.SetWindowPos( NULL, MULX(25), MULY(10), MULX(296), MULY(16), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );
	//m_btnBannerClose.SetWindowPos( NULL, MULX(251), MULY(10), MULX(74), MULY(16), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );
    //m_btnBannerStatusBar.SetWindowPos( NULL, MULX(2), MULY(27), MULX(342), MULY(6), SWP_HIDEWINDOW/*SWP_NOSIZE*/ );

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
	m_dwEdgeWidth  = 10/* GetSystemMetrics(SM_CXFRAME)*/;

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
        //KillTimer(StatusBarTimerId);
        HDC hDc = ::GetDC( this->GetSafeHwnd() );
        HDC hDcMem =  CreateCompatibleDC( hDc);

        //CPaintDC dc(this);
        //CDC dcMem;
        //dcMem.CreateCompatibleDC(&dc);  //��������DC


        CDC *pDC = CDC::FromHandle(hDcMem);
        //CBitmap cbmp;
        //cbmp.LoadBitmap(IDB_STATUS_BAR);  //����λͼ

        //BITMAP bitmap;
        //cbmp.GetBitmap(&bitmap);  //��ȡλͼ��Ϣ
        //CRect rect;
        //PRINTMSG("bitmap: %ld, %ld", bitmap.bmWidth, bitmap.bmHeight);

        CImage ImageBg;
        if ( LoadImageFromResource(&ImageBg, IDB_STATUS_BAR, _T("RCPNG")) )
        {
            //Draw
            if (pDC != NULL)
            {
                //PRINTMSG("Res width:%d, height:%d\r\n", ImageBg.GetWidth(), ImageBg.GetHeight());
                ImageBg.Draw(pDC->m_hDC, 0, 30, 346, 4, 0, 0, 346,4);
                ImageBg.Destroy();
                ReleaseDC(pDC);
            }
        }


        //CBitmap *pbitold=dcMem.SelectObject(&cbmp);  //��λͼѡ��DC��
        //BitBlt(hDcMem, 1, 30, 344, 4,
        //    dcMem.GetSafeHdc(), 0, 0, SRCCOPY);  //��stretchBlt�ķ�ʽ���λͼ����Ӧ����

        //cbmp.DeleteObject();
        //dcMem.SelectObject(pbitold);
        //dcMem.DeleteDC();
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
        m_btnBannerStatusBar.ShowWindow(SW_SHOW);
        SetTimer(StatusBarTimerId,30,NULL);
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
    m_btnBannerStatusBar.ShowWindow(SW_HIDE);
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
