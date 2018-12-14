#if !defined(AFX_CONTROLBUTTON_H__651F14BF_BEBC_4595_90ED_CD4B920F1A0A__INCLUDED_)
#define AFX_CONTROLBUTTON_H__651F14BF_BEBC_4595_90ED_CD4B920F1A0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ControlButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CControlButton window
/**********************************************

************************************************/
#define TRIANGLEBTN_BASEMSG					10000
#define	WM_BTN_CLICKME						TRIANGLEBTN_BASEMSG + 1
#define	WM_BTN_CLICK_LEFT					TRIANGLEBTN_BASEMSG + 2
#define	WM_BTN_CLICK_RIGHT					TRIANGLEBTN_BASEMSG + 3


class CControlButton : public CButton
{
// Construction
public:
	CControlButton();
	enum SYTLE{ROUNDRECT,ELLIPSE,UPTRIANGLE,DOWNTRIANGLE}m_Style; // ��ť�������ʽ
	void SetRgnStyle(SYTLE nStyle); // ���ð�ť��Ч�������ʽ
	void SetBitmapId(int nOver,int nNormal,int nPressed,int nFocus); // �趨��ť����״̬��ͼƬID
	void SetTargetHwnd(HWND hwnd){ m_hTargetWnd = hwnd ;}
	// Attributes
protected:
	//��ť����߿�
	CPen m_BoundryPen;
	
	//���ָ�����ڰ�ť֮��ʱ��ť���ڱ߿�
	CPen m_InsideBoundryPenLeft;
	CPen m_InsideBoundryPenRight;
	CPen m_InsideBoundryPenTop;
	CPen m_InsideBoundryPenBottom;
	
	//��ť��ý���ʱ��ť���ڱ߿�
	CPen m_InsideBoundryPenLeftSel;
	CPen m_InsideBoundryPenRightSel;
	CPen m_InsideBoundryPenTopSel;
	CPen m_InsideBoundryPenBottomSel;
	
	//��ť�ĵ�ɫ��������Ч����Ч����״̬
	CBrush m_FillActive;
	CBrush m_FillInactive;
	
	//��ť��״̬
	BOOL m_bOver;	//���λ�ڰ�ť֮��ʱ��ֵΪtrue����֮Ϊflase
	BOOL m_bTracking;	//����갴��û���ͷ�ʱ��ֵΪtrue
	BOOL m_bSelected;	//��ť�������Ǹ�ֵΪtrue
	BOOL m_bFocus;	//��ťΪ��ǰ��������ʱ��ֵΪtrue


	CBitmap m_NormalBitmap;
	CBitmap m_PressedBitmap;
	CBitmap m_FocusBitmap;
	CBitmap m_OverBitmap;
    CBitmap m_MaskBitmap;
	CBitmap m_BackBitmap;

	HWND	m_hTargetWnd;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CControlButton();
    virtual void DoGradientFill(CDC *pDC, CRect* rect);
	virtual void DrawInsideBorder(CDC *pDC, CRect* rect);
	// Generated message map functions
protected:
	//{{AFX_MSG(CControlButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
	// �����ɰ�ͼƬ����ʾ������ͼƬ
	void SetMaskBitmapId(int mask, bool action);
	static HRGN BitmapToRegion(HBITMAP hBmp, COLORREF cTransparentColor, COLORREF cTolerance = RGB(0,0,0));//λͼת��������
	// �Ƿ�ʹ���ɰ�
	bool IsMask;
	bool IsMaskRgn;
	bool IsBackBmp;
	CRect BackRect;
	// ����λͼת����Ч����
	void SetRgnMask(int nMaskBmpId, bool nAction);
	void SetBackBmp(int nBgdBmpId,CRect rect);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLBUTTON_H__651F14BF_BEBC_4595_90ED_CD4B920F1A0A__INCLUDED_)
