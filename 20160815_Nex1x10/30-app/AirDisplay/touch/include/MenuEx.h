#pragma once

#include <string>
#include <vector>

using namespace std;


// ������
typedef enum _EnumItemType
{
	ITEMTYPE_STRING,		// �ַ�����
	ITEMTYPE_SEPARATOR,		// �ָ�����
	ITEMTYPE_SUBMENU,		// �Ӳ˵���
}EnumItemType;

// ˳������
typedef enum _EnumaOrderType
{
	ORDERTYPE_FIRST,		// ��һ��
	ORDERTYPE_CENTER,		// �м�
	ORDERTYPE_LAST,			// ���һ��
}EnumaOrderType;

// ����Ϣ
typedef struct StruItemInfo  
{  
	int				nFlags;
	int				nID;  
	HICON			hIcon;
	HICON			hIconCheckNormal;//ѡ�е�����ͼƬ
	HICON			hIconCheckHover; //ѡ�еľ���ͼƬ
	CString			strText;		// �ַ���
	CString			strShortcut;	// ��ݼ�˵��
	EnumItemType	eItemType;		// ������
	EnumaOrderType	eOrderType;		// ˳������
}StruItemInfo;

typedef vector<StruItemInfo*>	ItemInfoVec;
typedef ItemInfoVec::iterator	ItemInfoIter;


// CMenuEx �Ի���

class CMenuEx : public CMenu
{

public:
	CMenuEx();   // ��׼���캯��
	virtual ~CMenuEx();

private:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);

	// ��ȡϵͳĬ�������С
	int GetSysFontSize();
	// ��ȡϵͳĬ��������
	string GetSysFontFaceName();
	// ����˳������
	EnumaOrderType GenerateOrderType();
 
	HHOOK		m_hook;					// ���Ӿ��
	int			m_nFontSize;			// �����С
	int			m_nItemHeight;			// ��߶�
	string		m_strFontFaceName;		// ������
	int			m_nLeftWidth;			// ͼ��������
	int			m_nIconWidth;			// ͼ����
	int			m_nIconHeight;			// ͼ��߶�
	int			m_nIconCheckWidth;		// ѡ�е�ͼ����
	int			m_nIconCheckHeight;		// ѡ�е�ͼ��߶�
	int			m_nMenuWidth;			// �˵����
	int			m_nSeparatorHeight;		// �ָ����߶�
	bool		m_bHasIcon;				// �Ƿ���ͼ��
	COLORREF	m_clrBk;				// ����ɫ
	COLORREF	m_clrBkHover;			// ��������ɫ
	COLORREF	m_clrText;				// ������ɫ
	COLORREF	m_clrHoverText;			// ����������ɫ
	COLORREF	m_clrTextDisable;		// ��Ч������ɫ
	COLORREF	m_clrSeparator;			// �ָ�����ɫ
	COLORREF	m_clrBorder;			// �߿���ɫ
	
	ItemInfoVec m_ItemList;
public:
	// ����
	void InstallHook(HINSTANCE hInst);
	void UnInstallHook();

	// ���һ��
	void AppendItem(UINT nFlags, UINT nID, CString strText, CString strShortcut, UINT nIconID);
	// ���һ���Ӳ˵�
	void AppendSubMenu(UINT nFlags, UINT nID, CMenuEx* subMenu, CString strText, UINT nIconID);
	// ��ӷָ���
 	void AppendSeparator(UINT nFlags, UINT nID);

	//���һ��֧��ѡ�е���
	void AppendCheckItem(UINT nFlags, UINT nID, CString strText, CString strShortcut, UINT nIconCheckNormalID, UINT nIconCheckHoverID);

	void DestroyMenu();

	// ���������С
	void SetFontInfo(int nSize, const char* szFontFaceName=NULL);
	// ������߶�
	void SetItemHeight(int nItemHeight) { m_nItemHeight = nItemHeight; }
	// ���ò˵��Ŀ��
	void SetMenuWidth(int nWidth) { m_nMenuWidth = nWidth; }
	// ���ñ߿���ɫ
	void SetBorderColor(COLORREF clr) { m_clrBorder = clr; }


};
