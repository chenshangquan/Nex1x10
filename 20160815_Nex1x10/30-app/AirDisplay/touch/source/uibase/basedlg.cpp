// BaseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "touch.h"
#include "BaseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDlg dialog


CBaseDlg::CBaseDlg(UINT nIDTemplate, CWnd* pParent /*=NULL*/)
	: CTransparentBaseDlg(nIDTemplate, pParent)
{
	//{{AFX_DATA_INIT(CBaseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CTransparentBaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBaseDlg, CTransparentBaseDlg)
	//{{AFX_MSG_MAP(CBaseDlg)
	//}}AFX_MSG_MAP
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDlg message handlers

BOOL CBaseDlg::OnInitDialog() 
{
	CTransparentBaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
//     typedef BOOL (WINAPI *MYFUNC)(HWND,COLORREF,BYTE,DWORD); 
//     MYFUNC SetLayeredWindowAttributes;
//     
//     HINSTANCE hInstUser32Lib = LoadLibrary( "User32.DLL" ); 
//     if ( NULL != hInstUser32Lib )
//     {
//         //ȡ��SetLayeredWindowAttributes����ָ�� 
//         SetLayeredWindowAttributes = (MYFUNC)GetProcAddress( hInstUser32Lib, "SetLayeredWindowAttributes" );
//         if ( NULL != SetLayeredWindowAttributes )
//         {
//             // ���ð�͸���Ի���
//             SetWindowLong( GetSafeHwnd(), GWL_EXSTYLE,
//                            GetWindowLong( GetSafeHwnd(), GWL_EXSTYLE ) ^ 0x80000 );
// 
//             SetLayeredWindowAttributes( GetSafeHwnd(), 0, 150, 2 ); // ����������AlphaֵΪ0������Ϊȫ͸������͸��ʱ�����ļ�ش��ڻ���˸
//         }
//         FreeLibrary( hInstUser32Lib );
// 	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

LRESULT CBaseDlg::OnNcHitTest(CPoint point)
{
	ScreenToClient (&point) ;
	if( point.y < 25)
		return HTCAPTION;
	else
	{
		return HTNOWHERE;
	}
}