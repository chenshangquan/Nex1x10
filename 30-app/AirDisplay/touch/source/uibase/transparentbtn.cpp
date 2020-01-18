// TransparentBtn.cpp : implementation file
//

#include "stdafx.h"
#include "TransparentBtn.h"
#include "Utility.h"
#include "ControlButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransparentBtn

CTransparentBtn::CTransparentBtn()
{
    m_emStatus = emStatusNormal;
    m_emTextAlign = emAlignmentCenter;

    m_hParent = NULL;

    m_dwNormalResID = 0;
	m_dwOverResID = 0;
    m_dwPressResID = 0;
    m_dwDisableResID = 0;

    m_pImgNormal = NULL;
	m_pImgOver = NULL;
    m_pImgPress = NULL;
    m_pImgDisable = NULL;

	m_hTargetWnd = NULL;

    m_bShowText = FALSE;
    m_bShowBk = FALSE;
    m_bShowEdge  =FALSE;

    m_cPoint = CPoint( 0, 0 );

	m_bPressed = FALSE;
	m_bTracking = false;
	m_bButtonDown = false;

    wcscpy( m_awszFontName, _T("Arial") );
	m_dwFontSize = 18;
	
	m_wOffset = 0;
    m_bScale = FALSE;
	m_bAjustSize = FALSE;

	for (int i=0; i<4; i++)
	{
		m_cColor[i] = Color( 255, 255, 255 );
        m_cBkColor[i] = Color( 255, 255, 255 );
        m_cEdgeColor[i] = Color( 255, 255, 255 );
	}
}

CTransparentBtn::~CTransparentBtn()
{
	if ( m_bScale == TRUE )
	{
		if ( NULL != m_pImgNormal )
		{
			delete m_pImgNormal;
		}
		if ( NULL != m_pImgPress )
		{
			delete m_pImgPress;
		}
		if ( NULL != m_pImgOver )
		{
			delete m_pImgOver;
		}
		if ( NULL != m_pImgDisable )
		{
			delete m_pImgDisable;
		}
	}
}


BEGIN_MESSAGE_MAP(CTransparentBtn, CButton)
	//{{AFX_MSG_MAP(CTransparentBtn)
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSELEAVE()
	//}}AFX_MSG_MAP
    ON_MESSAGE( WM_REDRAW_UI, OnRedrawUI )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransparentBtn message handlers

int CTransparentBtn::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CButton::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here

	return 0;
}

LRESULT CTransparentBtn::OnRedrawUI( WPARAM wParam, LPARAM lParam )
{
    m_hParent = (HWND)lParam;
	
    if ( IsWindowVisible() == FALSE )
    {
        return S_FALSE;
    }
	
#ifdef _DEBUG
    CString strWindowText;
    GetWindowText( strWindowText );
#endif // _DEBUG
	
    /*if ( 0 == m_dwNormalResID )
    {
        return S_FALSE;
    }*/
	
    if ( NULL == m_pImgNormal && 0 != m_dwNormalResID )
    {
        m_pImgNormal = CUtility::GetImage( m_dwNormalResID, _T("PNG") );
    }
    if ( NULL == m_pImgPress && 0 != m_dwPressResID )
    {
        m_pImgPress = CUtility::GetImage( m_dwPressResID, _T("PNG") );
    }
	if ( NULL == m_pImgOver && 0 != m_dwOverResID )
	{
		m_pImgOver = CUtility::GetImage( m_dwOverResID, _T("PNG") );
	}
    if ( NULL == m_pImgDisable && 0 != m_dwDisableResID )
    {
        m_pImgDisable = CUtility::GetImage( m_dwDisableResID, _T("PNG") );
    }
	
    Graphics *pGraphics = (Graphics*)wParam;
	
    CRect cRect;
    GetWindowRect( &cRect );
    if ( TRUE == m_bScale && m_bAjustSize == FALSE )
    {
        /*if ( cRect.Width() != CUtility::GetScreenScaleWidth( m_pImgNormal->GetWidth() )
			|| cRect.Height() != CUtility::GetScreenScaleHeight( m_pImgNormal->GetHeight() ) )
        {
            cRect.right = cRect.left + CUtility::GetScreenScaleWidth( cRect.Width() );
            cRect.bottom = cRect.top + CUtility::GetScreenScaleHeight( cRect.Height() );
			
            SetWindowPos( NULL, 0, 0, CUtility::GetScreenScaleWidth( m_pImgNormal->GetWidth() ), 
				CUtility::GetScreenScaleHeight( m_pImgNormal->GetHeight() ), SWP_NOMOVE );
        }*/
			m_pImgNormal = CUtility::ScaleBitmap( m_pImgNormal, CUtility::GetScreenScaleWidth( m_pImgNormal->GetWidth() ), 
				CUtility::GetScreenScaleHeight( m_pImgNormal->GetHeight() ) );

			m_pImgPress = CUtility::ScaleBitmap( m_pImgPress, CUtility::GetScreenScaleWidth( m_pImgPress->GetWidth() ), 
				CUtility::GetScreenScaleHeight( m_pImgPress->GetHeight() ) );

			m_pImgDisable = CUtility::ScaleBitmap( m_pImgDisable, CUtility::GetScreenScaleWidth( m_pImgDisable->GetWidth() ), 
				CUtility::GetScreenScaleHeight( m_pImgDisable->GetHeight() ) );
		m_bAjustSize = TRUE;	
    }
    else
    {
        if ( 0 == m_dwNormalResID )
        {
            cRect.right = cRect.left + cRect.Width();
            cRect.bottom = cRect.top + cRect.Height();
        }
        else if ( cRect.Width() != m_pImgNormal->GetWidth()
			|| cRect.Height() != m_pImgNormal->GetHeight() )
        {
            cRect.right = cRect.left + cRect.Width();
            cRect.bottom = cRect.top + cRect.Height();
        }
    }
    POINT point = cRect.TopLeft();
	
    ::ScreenToClient( m_hParent, &point );
	
    Image *pImage = NULL;
    switch ( m_emStatus )
    {
    case emStatusNormal:
        pImage = m_pImgNormal;
        break;
    case emStatusBtnDown:
        pImage = m_pImgPress;
        break;
	case emStatusOver:
		pImage = m_pImgOver;
		break;
    }
	
    if ( FALSE == IsWindowEnabled() )
    {
        pImage = m_pImgDisable;
    }
	
    //draw image
    if ( NULL != pImage )
    {
        pGraphics->DrawImage( pImage, point.x, point.y, cRect.Width(), cRect.Height() );
	}

    //draw backcolor
    if ( TRUE == m_bShowBk )
    {
        Color colorBk;
        colorBk = m_cBkColor[m_emStatus];
        SolidBrush BkBrush(colorBk);
        pGraphics->FillRectangle(&BkBrush, point.x-1, point.y-1, cRect.Width()+1, cRect.Height()+1);;
    }

    //draw edge
    if ( TRUE == m_bShowEdge )
    {
        Color colorEdge;
        colorEdge = m_cEdgeColor[m_emStatus];
        pGraphics->DrawRectangle(new Pen(colorEdge), point.x-1, point.y-1, cRect.Width()+1, cRect.Height()+1);
        //pGraphics->DrawRectangle(new Pen(colorEdge), point.x, point.y, cRect.Width()-1, cRect.Height()-1);//innerBounds
        //pGraphics->DrawRectangle(new Pen(colorEdge), point.x-1, point.y-1, cRect.Width()+1, cRect.Height()+1);//outerBounds
    }

    //draw string
    if ( TRUE == m_bShowText )
    {
        FontFamily fontFamily( m_awszFontName );
        Gdiplus::Font font( &fontFamily, m_dwFontSize );
        
        Color colorText;
        if ( TRUE == m_bPressed )
        {
            colorText = Color( 19, 171, 218 );
        }
        else
        {
            colorText = m_cColor[m_emStatus];
        }
        
        SolidBrush brush( colorText ); // ������ɫ��ʵ��ˢ��д�ַ����ã�
        pGraphics->SetTextRenderingHint( TextRenderingHint( TextRenderingHintAntiAlias ) );
        
        CString strText;
        GetWindowText( strText );
        
        StringFormat sf;
        sf.SetLineAlignment( StringAlignmentCenter );
        if ( emAlignmentUserDef == m_emTextAlign )
        {
            pGraphics->DrawString( strText, -1, &font, RectF( (float)point.x + m_cPoint.x, (float)point.y, cRect.Width(), cRect.Height() ), &sf, &brush );
        }
        else
        {
            if ( emAlignmentLeft == m_emTextAlign )
            {
                sf.SetAlignment( StringAlignmentNear );
            }
            else if ( emAlignmentCenter == m_emTextAlign )
            {
                sf.SetAlignment( StringAlignmentCenter );
            }
            else
            {
                sf.SetAlignment( StringAlignmentFar );
            }
            
            /*if ( TRUE == m_bScale )
            {
                pGraphics->DrawString( pwszText, -1, &font, RectF( (float)point.x, (float)point.y, 
                    m_pImgNormal->GetWidth(),  m_pImgNormal->GetHeight() ), 
                    &sf, &brush );
            }
            else
            {*/
            pGraphics->DrawString( strText, -1, &font, RectF( (float)point.x, (float)point.y, cRect.Width(), cRect.Height() ), &sf, &brush );
                //pGraphics->DrawString( strText, -1, &font, RectF( (float)point.x, (float)point.y, m_pImgNormal->GetWidth(), m_pImgNormal->GetHeight() ), &sf, &brush );
            //}
        }
	}
		

	/*if ( cRect.Width() != m_pImgNormal->GetWidth()
		|| cRect.Height() != m_pImgNormal->GetHeight() )
	{
		cRect.right = cRect.left + cRect.Width();
		cRect.bottom = cRect.top + cRect.Height();
		
		SetWindowPos( NULL, 0, 0, m_pImgNormal->GetWidth(), m_pImgNormal->GetHeight(), SWP_NOMOVE );
	}*/
		//     if ( cRect.Width() != m_pImgNormal->GetWidth() / 1.05
		//          || cRect.Height() != m_pImgNormal->GetHeight() / 1.17 )
		//     {
		//         SetWindowPos( NULL, 0, 0, m_pImgNormal->GetWidth() / 1.05, m_pImgNormal->GetHeight() / 1.17, SWP_NOMOVE );
		//     }
		
	return S_OK;    
}

void CTransparentBtn::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (!m_bTracking)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(TRACKMOUSEEVENT);
		tme.dwFlags = TME_LEAVE;
		tme.hwndTrack = this->m_hWnd;
		tme.dwHoverTime = 0;

		if (::_TrackMouseEvent(&tme))
		{
			m_bTracking = true;
			if ( m_hParent != NULL )
			{
				if (m_bButtonDown )
				{
					m_emStatus = emStatusBtnDown;
				}
				else
				{
					m_emStatus = emStatusOver;
				}
		
				::SendMessage( m_hParent, WM_REDRAW_UI, NULL, NULL );
			}
		}
	}

	CButton::OnMouseMove(nFlags, point);
}

void CTransparentBtn::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if ( m_hParent != NULL )
    {
        m_emStatus = emStatusBtnDown;

        ::SendMessage( m_hParent, WM_REDRAW_UI, NULL, NULL );
    }

	m_bButtonDown = true;
	CButton::OnLButtonDown(nFlags, point);
}

void CTransparentBtn::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if( NULL != m_hTargetWnd )
	{
		::SendMessage(m_hTargetWnd, WM_BTN_CLICKME, (WPARAM) this, 0);
	}

	if ( m_hParent != NULL )
    {
        m_emStatus = emStatusNormal;

        ::SendMessage( m_hParent, WM_REDRAW_UI, NULL, NULL );
    }

	m_bButtonDown = false;
	CButton::OnLButtonUp(nFlags, point);
}

void CTransparentBtn::OnMouseLeave()
{
	if ( m_hParent != NULL )
	{
		m_emStatus = emStatusNormal;

		::SendMessage( m_hParent, WM_REDRAW_UI, NULL, NULL );
	}

	m_bTracking = false;
	CButton::OnMouseLeave();
}

void CTransparentBtn::SetTextColor( Color colorNormal, Color colorPress, Color colorHover, Color colorDisable )
{
	m_cColor[emStatusNormal] = colorNormal;
	m_cColor[emStatusBtnDown] = colorPress;
	m_cColor[emStatusOver] = colorHover;
	m_cColor[emStatusBtnDisable] = colorDisable;
}

void CTransparentBtn::SetBkColor( Color colorNormal, Color colorPress, Color colorHover, Color colorDisable )
{
    m_cBkColor[emStatusNormal] = colorNormal;
    m_cBkColor[emStatusBtnDown] = colorPress;
    m_cBkColor[emStatusOver] = colorHover;
    m_cBkColor[emStatusBtnDisable] = colorDisable;
}

void CTransparentBtn::SetEdgeColor( Color colorNormal, Color colorPress, Color colorHover, Color colorDisable )
{
    m_cEdgeColor[emStatusNormal] = colorNormal;
    m_cEdgeColor[emStatusBtnDown] = colorPress;
    m_cEdgeColor[emStatusOver] = colorHover;
    m_cEdgeColor[emStatusBtnDisable] = colorDisable;
}