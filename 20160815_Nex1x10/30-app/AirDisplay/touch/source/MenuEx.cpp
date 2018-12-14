// MenuEx.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MenuEx.h"



CMenuEx::CMenuEx()
{
	m_hook = NULL;
	m_nItemHeight = ::GetSystemMetrics(SM_CYMENU);
	m_nFontSize = GetSysFontSize();
	m_strFontFaceName = GetSysFontFaceName();
	m_nLeftWidth = 30;
	m_nIconWidth = 16;
	m_nIconHeight = 16;
	m_nIconCheckWidth = 10;
	m_nIconCheckHeight = 10;
	m_clrBk = RGB(255,255,255);
	m_clrBkHover = RGB(30,148,248);
	m_clrText = RGB(76,76,76);
    m_clrHoverText = RGB(255,255,255);
	m_clrSeparator = RGB(230,230,230);
	m_clrTextDisable = RGB(180,180,180);
	m_clrBorder = RGB(85,85,85);
	m_nMenuWidth = 124;
	m_bHasIcon = false;
	m_nSeparatorHeight = 7;
	
}

CMenuEx::~CMenuEx()
{
}

void CMenuEx::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  ������Ĵ����Ի���ָ����

 	CString strText;   
 	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC); //��ȡ�˵�����豸���   
 	StruItemInfo *pStruItemInfo =(StruItemInfo*)lpDrawItemStruct->itemData;  
 	if(pStruItemInfo == NULL)
 	{
 		return;
 	}
 
 	CRect rect(lpDrawItemStruct->rcItem);  
 
 	if(pStruItemInfo->eItemType == ITEMTYPE_SEPARATOR)		//�ָ���  
 	{  
		// ������
 		pDC->FillSolidRect(rect, m_clrBk);  

		// ����
 		CRect rcSeparator(rect);  
 		rcSeparator.top = rcSeparator.top + rcSeparator.Height() / 2;  
 		rcSeparator.bottom = rcSeparator.top + 1; 
		rcSeparator.left += 5;
 		rcSeparator.right -= 5;  
 		pDC->Draw3dRect(rcSeparator, m_clrSeparator, m_clrSeparator);
 
 	}
	else
	{
		// ������
		if(lpDrawItemStruct->itemState & ODS_GRAYED)	// ��Ч���
		{  
			pDC->FillSolidRect(rect, m_clrBk);  
			pDC->SetTextColor(m_clrTextDisable);  
		}      
		else if(lpDrawItemStruct->itemState & ODS_SELECTED )	// ����
		{   
			//�ڲ˵������Ի���ο�ı�����ɫ   
			pDC->FillSolidRect(rect, m_clrBkHover);  
			//���ò˵�������ɫ  
			pDC->SetTextColor(m_clrHoverText);  
		}   
		else  
		{  
			pDC->FillSolidRect(rect, m_clrBk);  
			pDC->SetTextColor(m_clrText);  
		}

		pDC->SetBkMode(TRANSPARENT); 

		/*if (lpDrawItemStruct->itemState & ODS_CHECKED)
		{
		CRect rctmp(rect);
		rctmp.left = rect.left + 15;
		rctmp.right = rctmp.left + 8;
		pDC->DrawText(_T("��"),&rctmp,DT_EXPANDTABS|DT_VCENTER|DT_SINGLELINE);
		}*/

		CRect rcIcon(rect);
		rcIcon.left += (m_nLeftWidth - m_nIconWidth) / 2;
		rcIcon.right = rcIcon.left + m_nIconWidth;
		rcIcon.top += (rcIcon.Height() - m_nIconHeight) / 2;

		if(pStruItemInfo->hIcon != NULL)  
		{  
			DrawIconEx(pDC->m_hDC, rcIcon.left, rcIcon.top, pStruItemInfo->hIcon, m_nIconWidth, m_nIconHeight, 0, NULL, DI_NORMAL);  
		}   

		//��ѡ�е�ͼ��
		CRect rcCheckIcon(rect);
		rcCheckIcon.left += (m_nLeftWidth - m_nIconCheckWidth) / 2;
		rcCheckIcon.right = rcCheckIcon.left + m_nIconCheckWidth;
		rcCheckIcon.top += (rcCheckIcon.Height() - m_nIconCheckHeight) / 2;

		if (pStruItemInfo->hIconCheckNormal != NULL && pStruItemInfo->hIconCheckHover != NULL)
		{
			if (lpDrawItemStruct->itemState & ODS_CHECKED)
			{
				//����
				if (lpDrawItemStruct->itemState & ODS_SELECTED )
				{
					DrawIconEx(pDC->m_hDC, rcCheckIcon.left, rcCheckIcon.top, pStruItemInfo->hIconCheckHover, m_nIconCheckWidth, m_nIconCheckHeight, 0, NULL, DI_NORMAL);  
				}
				else
				{
					DrawIconEx(pDC->m_hDC, rcCheckIcon.left, rcCheckIcon.top, pStruItemInfo->hIconCheckNormal, m_nIconCheckWidth, m_nIconCheckHeight, 0, NULL, DI_NORMAL);  
				}
			}
			
		}

		// ����������ֺ�����  
		LOGFONT fontInfo;  
		pDC->GetCurrentFont()->GetLogFont(&fontInfo);  

		fontInfo.lfHeight = m_nFontSize;
		lstrcpy(fontInfo.lfFaceName, CA2W(m_strFontFaceName.c_str())); 
		CFont fontCh;  
		fontCh.CreateFontIndirect(&fontInfo);  
		pDC->SelectObject(&fontCh);  

		CRect rcText(rect);
		if (m_bHasIcon)
		{
			rcText.left += m_nLeftWidth;
		}
		else
		{
			rcText.left += 35;
		}
		rcText.top += (rcText.Height() - m_nFontSize) / 2;
		rcText.bottom = rcText.top + m_nFontSize;

		//�Ӳ˵���
		if(pStruItemInfo->eItemType == ITEMTYPE_SUBMENU)	
		{  
			pDC->TextOut(rcText.left, rcText.top, pStruItemInfo->strText, pStruItemInfo->strText.GetLength()); 
			// �����Զ���С��ͷ
			//::ExcludeClipRect(pDC->m_hDC,rect.right-15,rect.top,rect.right,rect.bottom);  
			//DrawIconEx(pDC->m_hDC,rect.right-40,rect.top+7,AfxGetApp()->LoadIconA(IDI_ICON1),32,32,1,NULL,DI_NORMAL);          
		}  
		else if (pStruItemInfo->eItemType == ITEMTYPE_STRING)		
		{  
			// �ַ�����
			pDC->TextOut(rcText.left, rcText.top, pStruItemInfo->strText, pStruItemInfo->strText.GetLength());  
			//fontInfo.lfHeight = 16;  
			//CFont fontEn;  
			//lstrcpy(fontInfo.lfFaceName, _T("Arial"));  
			//fontEn.CreateFontIndirect(&fontInfo);  
			//pDC->SelectObject(&fontEn);  
			pDC->TextOut(rcText.left, rcText.top, pStruItemInfo->strShortcut, pStruItemInfo->strShortcut.GetLength());  
		}    
	
	}
 
	// ���߿�
	CPen penBorder(PS_SOLID, 1, m_clrBorder);
	CPen *pOldPen = pDC->SelectObject(&penBorder);
	pDC->MoveTo(rect.left, rect.top);
	pDC->LineTo(rect.left, rect.bottom);
	pDC->MoveTo(rect.right-1, rect.top);
	pDC->LineTo(rect.right-1, rect.bottom);

	if (m_ItemList.size() == 1)
	{
		// ���ֻ��һ��Ļ������±߶���
		pDC->MoveTo(rect.left, rect.top);
		pDC->LineTo(rect.right-1, rect.top);
		pDC->MoveTo(rect.left, rect.bottom-1);
		pDC->LineTo(rect.right-1, rect.bottom-1);
	}
	else
	{
		// �ж���Ļ�����һ��ϱߣ����һ��±�
		if (pStruItemInfo->eOrderType == ORDERTYPE_FIRST)
		{
			pDC->MoveTo(rect.left, rect.top);
			pDC->LineTo(rect.right-1, rect.top);
		} 
		else if (pStruItemInfo->eOrderType == ORDERTYPE_LAST)
		{
			pDC->MoveTo(rect.left, rect.bottom-1);
			pDC->LineTo(rect.right-1, rect.bottom-1);
		}
	}
	pDC->SelectObject(pOldPen);

}

void CMenuEx::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{

	// TODO:  ������Ĵ�����ȷ��ָ����Ĵ�С

	StruItemInfo *pStruItemInfo =(StruItemInfo*)lpMeasureItemStruct->itemData;  
	if (pStruItemInfo->eItemType == ITEMTYPE_SEPARATOR)
	{
		// ���÷ָ�����߶�
		lpMeasureItemStruct->itemHeight = m_nSeparatorHeight;
	}
	else
	{
		lpMeasureItemStruct->itemHeight = m_nItemHeight;
	}

	// ��������
	lpMeasureItemStruct->itemWidth = m_nMenuWidth;

}

void CMenuEx::AppendSeparator(UINT nFlags, UINT nID)  
{  
	StruItemInfo *pStruItemInfo = new StruItemInfo;
	pStruItemInfo->nID = nID;
	pStruItemInfo->hIcon = NULL;
	pStruItemInfo->hIconCheckNormal = NULL;  
	pStruItemInfo->hIconCheckHover = NULL;  
	pStruItemInfo->strText = "";
	pStruItemInfo->strShortcut = "";
	pStruItemInfo->eItemType = ITEMTYPE_SEPARATOR;
	nFlags |= MF_SEPARATOR|MF_OWNERDRAW;
	pStruItemInfo->nFlags = nFlags;
	pStruItemInfo->eOrderType = GenerateOrderType();

	m_ItemList.push_back(pStruItemInfo);

	CMenu::AppendMenu(nFlags, 0, (LPCTSTR)pStruItemInfo);  
}  

void CMenuEx::AppendSubMenu(UINT nFlags, UINT nID, CMenuEx* subMenu, CString strText,UINT nIconID)   
{  
	StruItemInfo *pStruItemInfo = new StruItemInfo;  
	pStruItemInfo->nID = nID;  
	if(nIconID == 0)  
	{  
		pStruItemInfo->hIcon = NULL;  
	}  
	else  
	{  
		pStruItemInfo->hIcon = (HICON)::LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(nIconID),IMAGE_ICON, m_nIconWidth, m_nIconHeight, 0);
		if (pStruItemInfo->hIcon != NULL)
		{
			m_bHasIcon = true;
		}
	}  

	pStruItemInfo->hIconCheckNormal = NULL;  
	pStruItemInfo->hIconCheckHover = NULL;  
	pStruItemInfo->strText = strText;  
	pStruItemInfo->strShortcut = "";  
	pStruItemInfo->eItemType = ITEMTYPE_SUBMENU;      
	nFlags |= MF_POPUP|MF_OWNERDRAW;  
	pStruItemInfo->nFlags = nFlags;  
	pStruItemInfo->eOrderType = GenerateOrderType();

	m_ItemList.push_back(pStruItemInfo);

	CMenu::AppendMenu(nFlags, (UINT)subMenu->GetSafeHmenu(), (LPCTSTR)pStruItemInfo);      
} 

void CMenuEx::AppendItem(UINT nFlags, UINT nID, CString strText, CString strShortcut, UINT nIconID)   
{  
	StruItemInfo *pStruItemInfo = new StruItemInfo;  
	pStruItemInfo->nID = nID;  
	if(nIconID == 0)  
	{  
		pStruItemInfo->hIcon = NULL;  
	}  
	else  
	{  

		pStruItemInfo->hIcon = (HICON)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(nIconID), IMAGE_ICON, m_nIconWidth, m_nIconHeight, 0);  
		//pStruItemInfo->hIcon = AfxGetApp()->LoadIcon(nIconID) ;  

		if (pStruItemInfo->hIcon != NULL)
		{
			m_bHasIcon = true;
		}
	}  

	pStruItemInfo->hIconCheckNormal = NULL;  
	pStruItemInfo->hIconCheckHover = NULL;  
	pStruItemInfo->strText = strText;  
	pStruItemInfo->strShortcut = strShortcut;  
	pStruItemInfo->eItemType = ITEMTYPE_STRING;  
	nFlags |= MF_OWNERDRAW;  
	pStruItemInfo->nFlags = nFlags;  
	pStruItemInfo->eOrderType = GenerateOrderType();

	m_ItemList.push_back(pStruItemInfo);

	CMenu::AppendMenu(nFlags, pStruItemInfo->nID, (LPCTSTR)pStruItemInfo);      
}  

void CMenuEx::AppendCheckItem(UINT nFlags, UINT nID, CString strText, CString strShortcut, UINT nIconCheckNormalID, UINT nIconCheckHoverID)
{
	StruItemInfo *pStruItemInfo = new StruItemInfo;  
	pStruItemInfo->nID = nID;  
	if(nIconCheckNormalID == 0)  
	{  
		pStruItemInfo->hIconCheckNormal = NULL;  
	}  
	else  
	{  

		pStruItemInfo->hIconCheckNormal = (HICON)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(nIconCheckNormalID), IMAGE_ICON, m_nIconCheckWidth, m_nIconCheckHeight, 0);  
		//pStruItemInfo->hIcon = AfxGetApp()->LoadIcon(nIconID) ;  

		if (pStruItemInfo->hIconCheckNormal != NULL)
		{
			m_bHasIcon = true;
		}
	}  

	if(nIconCheckHoverID == 0)  
	{  
		pStruItemInfo->hIconCheckHover = NULL;  
	}  
	else  
	{  

		pStruItemInfo->hIconCheckHover = (HICON)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(nIconCheckHoverID), IMAGE_ICON, m_nIconCheckWidth, m_nIconCheckHeight, 0);  
		//pStruItemInfo->hIcon = AfxGetApp()->LoadIcon(nIconID) ;  

		if (pStruItemInfo->hIconCheckHover != NULL)
		{
			m_bHasIcon = true;
		}
	}  

	pStruItemInfo->hIcon = NULL;
	pStruItemInfo->strText = strText;  
	pStruItemInfo->strShortcut = strShortcut;  
	pStruItemInfo->eItemType = ITEMTYPE_STRING;  
	nFlags |= MF_OWNERDRAW;  
	pStruItemInfo->nFlags = nFlags;  
	pStruItemInfo->eOrderType = GenerateOrderType();

	m_ItemList.push_back(pStruItemInfo);

	CMenu::AppendMenu(nFlags, pStruItemInfo->nID, (LPCTSTR)pStruItemInfo);      
}

static LRESULT WINAPI CallWndProc(int, WPARAM, LPARAM);				// ��װ�Ĺ��ӵĴ��ڹ���  
static LRESULT WINAPI MenuWndProc(HWND, UINT, WPARAM, LPARAM);		// ��������˵��Ĵ��ڹ���  
WNDPROC oldWndProc = NULL;											// �������汻�滻�Ĵ��ڹ���  

LRESULT WINAPI CallWndProc(int code, WPARAM wParam, LPARAM lParam)  
{  
	CWPSTRUCT* pStruct =(CWPSTRUCT*)lParam;  
	while(code == HC_ACTION)//HC_ACTION Ϊ���봦��  
	{  
		HWND hWnd = pStruct->hwnd;  
		// ��׽������ϢWM_CREATE������ɸѡΪ�Ƿ��ǲ˵��Ĵ���  
		if( pStruct->message != WM_CREATE)  
			break;  
		TCHAR sClassName[10];  
		int Count = ::GetClassName(hWnd, sClassName, sizeof(sClassName)/sizeof(sClassName[0]));  
		// ����Ƿ�˵����ڣ�#32768Ϊ�˵�����  
		if( Count != 6 || _tcscmp(sClassName, _T("#32768")) != 0 )   
			break;  

		WNDPROC lastWndProc =(WNDPROC)GetWindowLong(hWnd, GWL_WNDPROC); //���ָ�����ڵ���Ϣ GWL_WNDPROC�õ����ڻص������ĵ�ַ����  
		//��ȡ��������д��ڵĴ��ڹ��̣�������ڹ������ڽ��պʹ���ϵͳ�򴰿ڷ��͵���Ϣ  
		if(lastWndProc != MenuWndProc)   
		{   
			// �滻�˵����ڹ���   
			SetWindowLong(hWnd, GWL_WNDPROC, (long)MenuWndProc);   
			// ����ԭ�еĴ��ڹ���   
			oldWndProc = lastWndProc;   
		}  
		break;   
	}  


	//ÿһ�����Ӻ����ڽ��д���ʱ��Ҫ�����Ƿ���Ҫ���¼����ݸ���һ�����Ӵ������������Ҫ���ݣ���Ҫ���ú���CallNestHookEx������  
	//��ʵ��ʹ��ʱ����ǿ�ҽ��������Ƿ���Ҫ�����¼����ݶ�Ҫ�ڹ��̵�������һ��CallNextHookEx( )�����򽫻�����һЩ�޷�Ԥ֪��ϵͳ��Ϊ����ϵͳ������  
	return CallNextHookEx((HHOOK)WH_CALLWNDPROC, code, wParam, lParam);   
}  

// ����˵��Ĵ��ڹ���  
LRESULT WINAPI MenuWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  
{  
	LRESULT lResult;  
	switch(message)   
	{   
	case WM_CREATE://�Ƿ��ǲ˵��Ĵ���  
		{   
			// ����Ҫȥ���˵����ڵ�һЩ��չ���  
			// ������WS_BORDER��WS_EX_DLGMODALFRAME��WS_EX_WINDOWEDGE  
			lResult = CallWindowProc(oldWndProc, hWnd, message, wParam, lParam);   
			DWORD dwStyle = ::GetWindowLong(hWnd, GWL_STYLE);   
			DWORD dwNewStyle =(dwStyle & ~WS_BORDER);  
			::SetWindowLong(hWnd, GWL_STYLE, dwNewStyle);   
			DWORD dwExStyle = ::GetWindowLong(hWnd, GWL_EXSTYLE);  
			DWORD dwNewExStyle =(dwExStyle & ~(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE));   
			::SetWindowLong(hWnd, GWL_EXSTYLE, dwNewExStyle);   
			return lResult;   
		}   
	case WM_PRINT: // �˴���ֹ�ǿͻ����ػ���  
		return CallWindowProc( oldWndProc, hWnd, WM_PRINTCLIENT, wParam, lParam);  

	case WM_WINDOWPOSCHANGING:   
		{   
			// ���,����������MeasureItem��ָ���˲˵���С����ϵͳ���Զ���˵��ӱ߿�  
			// ��˱���ȥ���˲��ֶ���سߴ磬���˵���С��С  
			LPWINDOWPOS lpPos =(LPWINDOWPOS)lParam;   
			lpPos->cx -= 2*GetSystemMetrics(SM_CXBORDER)+4;   
			lpPos->cy -= 2*GetSystemMetrics(SM_CYBORDER)+4;  
			lResult = CallWindowProc(oldWndProc, hWnd, message, wParam, lParam);   
			return 0;  
		}   
	case WM_GETICON:  
		return 0;   
	default:   
		return CallWindowProc( oldWndProc, hWnd, message, wParam, lParam);   
	}   
}  

void CMenuEx::InstallHook(HINSTANCE hInst)  
{  
	// ��Ҫ�Ƴ��߿�ʱ��Ҫ��װ����  
	if(m_hook == NULL)  
	{  
		DWORD id = ::GetCurrentThreadId(); // ��ȡ��ǰ�̵߳�ID          
		m_hook = SetWindowsHookEx(WH_CALLWNDPROC,CallWndProc,hInst,id);//���𽫻ص����������ڹ�������Ŀ�ʼλ�á�  

		//HHOOK SetWindowsHookEx(int idHook;HOOKPROC lpfn;HINSTANCE hMod;DWORD dwThreadId);  
		//idHook ָ���˹��ӵ����ͣ�WH_CALLWNDPROC ϵͳ����Ϣ���͵�ָ������֮ǰ�ġ����ӡ�   
		//����lpfnΪָ���Ӻ�����ָ�룬Ҳ���ص��������׵�ַ��  
		//����hMod��ʶ�˹��Ӵ���������ģ��ľ����  
		//����dwThreadId ָ�������ӵ��̣߳������ȷָ����ĳ���̵߳�ID��ֻ���Ӹ��̣߳���ʱ�Ĺ��Ӽ�Ϊ�̹߳��ӣ�  
		//����ò���������Ϊ0�����ʾ�˹���Ϊ����ϵͳ�����̵߳�ȫ�ֹ��ӡ�  
		//�˺�����ִ����󽫷���һ�����Ӿ����  
	}  
}  

void CMenuEx::UnInstallHook()  
{  
	if(m_hook != NULL)  
	{  
		UnhookWindowsHookEx(m_hook);  
		m_hook = NULL;  
	}  
} 

int CMenuEx::GetSysFontSize()
{
	HFONT hFont = (HFONT)::GetStockObject(DEFAULT_GUI_FONT);
	if (hFont == NULL)
	{
		return 12;
	}

	LOGFONT lf;
	GetObject(hFont, sizeof(LOGFONT), &lf);

	return abs(lf.lfHeight);
}

string CMenuEx::GetSysFontFaceName()
{
	HFONT hFont = (HFONT)::GetStockObject(DEFAULT_GUI_FONT);
	if (hFont == NULL)
	{
		return "";
	}

	LOGFONT lf;
	GetObject(hFont, sizeof(LOGFONT), &lf);

	string strName(CW2A(lf.lfFaceName));
	return strName;
}



void CMenuEx::SetFontInfo(int nSize, const char* szFontFaceName/*=NULL*/)
{
	m_nFontSize = nSize;

	if (szFontFaceName != NULL)
	{
		m_strFontFaceName = szFontFaceName;
	}
}

void CMenuEx::DestroyMenu()
{
	ItemInfoIter it = m_ItemList.begin();
	for ( ; it != m_ItemList.end(); it++)
	{
		StruItemInfo* pStruItemInfo = (StruItemInfo*)*it;
		if (pStruItemInfo != NULL)
		{
			delete pStruItemInfo;
			pStruItemInfo = NULL;
		}
	}

	CMenu::DestroyMenu();
}

EnumaOrderType CMenuEx::GenerateOrderType()
{
	int nSize = m_ItemList.size();
	if (nSize == 0)
	{
		return ORDERTYPE_FIRST;
	} 
	else
	{
		ItemInfoIter it = m_ItemList.begin();
		for ( ; it != m_ItemList.end(); it++)
		{
			if ((*it)->eOrderType == ORDERTYPE_LAST)
			{
				(*it)->eOrderType = ORDERTYPE_CENTER;
				break;
			}
		}

		return ORDERTYPE_LAST;
	}
}