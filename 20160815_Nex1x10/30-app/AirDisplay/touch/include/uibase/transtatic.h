#if !defined(AFX_VIDSTATIC_H__813CA1AF_B1AA_4705_9F84_28513FD8A46B__INCLUDED_)
#define AFX_VIDSTATIC_H__813CA1AF_B1AA_4705_9F84_28513FD8A46B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// vidstatic.h : header file
//


class CTranStatic : public CStatic
{
// Construction
public:
	CTranStatic();

// Attributes
public:
	s8					m_chVidType;
	BOOL32				m_bSwap;		//标识该控件是否参与交换

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVidStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTranStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CVidStatic)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
    afx_msg LRESULT OnRedrawUI( WPARAM wParam, LPARAM lParam );
	DECLARE_MESSAGE_MAP()

public:

    void MoveWindow( LPCRECT lpRect, BOOL bRepaint = TRUE );
    void MoveWindow( int x, int y, int nWidth, int nHeight, BOOL bRepaint = TRUE );

	void DrawBk( HWND hWnd, Graphics *pGraphics );
	void SetBkImage( Image *pImgBk )
    {
        m_pImgBk = pImgBk;
    }
    void SetStatusBarDraw(BOOL bSttBarDraw, u32 dwSttBarDrawNum = 0)
    {
        m_bSttBarDraw = bSttBarDraw;
        m_dwSttBarDrawNum = dwSttBarDrawNum;
        m_dwSttBarDrawCount = 0;
    }
    void RedrawStatusBar();

protected:
    HWND    m_hParent;
private:
    Image   *m_pImgBk;

    BOOL    m_bSttBarDraw;              //状态条绘图
    u32     m_dwSttBarDrawNum;          //状态条分割总片数
    u32     m_dwSttBarDrawCount;        //状态条移动绘图计数
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDSTATIC_H__813CA1AF_B1AA_4705_9F84_28513FD8A46B__INCLUDED_)
