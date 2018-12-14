#pragma once

#ifndef ATLASSERT
#define ATLASSERT	ASSERT
#endif

#include <map>
#include "MMSYSTEM.H"

#include <GdiPlus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")


//typedef map<UINT, Image*> CImageMap;
typedef std::map<UINT, Image*> CImageMap;

class CUtility
{
public:
	static CString GetModulePath(HMODULE hModule = NULL);

	static BOOL IsFileExist(LPCTSTR lpszFilePath);

	static BOOL ExtractResourceToFile( LPCTSTR lpszType
									, UINT nResID
									, LPCTSTR lpszFilename
									, HMODULE hModule
									);

	static Image * LoadImage( UINT nID, LPCTSTR lpszType, HINSTANCE hInstance = NULL);
	

	static u16	GetItemGrpId(s32 nIndex)
	{
		return (nIndex>>12) & 0x000FF;
	}
	static u16	GetItemIndexId(s32 nIndex)
	{
		return nIndex & 0x00FFF;
	}

	static u32	MakeItemData(u16 wGrpId, u16 nItemIndex)
	{
		return ( (wGrpId<<12) & 0xFF000 ) | (nItemIndex & 0xFFF);
	}


	static void GetUpperDir(CString &strDir)
	{
		strDir = strDir.Left( strDir.GetLength() - 1 );
		strDir = strDir.Left( strDir.ReverseFind('\\') + 1 );
	}

	//----------------------------------------------------------
	//�� �� ��: GetImage
	//��    �ܣ�����ID���ͼƬָ�룬�����ͷ��κλ�õ�ͼƬָ�룬��ϵͳͳһ�ͷ�
	//����˵��:
	//�� �� ֵ��ͼƬָ��
	//�޸ļ�¼:
	//����		�汾		�޸���		�޸ļ�¼
	//2010/4/19	V1.0		muxingmao	����
	//----------------------------------------------------------
	static Image*		GetImage( UINT nID, LPCTSTR lpszType, HINSTANCE hInstance = NULL );
	static CImageMap	m_smapImage;

	//
	// GetDebugPriv
	// �� Windows NT/2000/XP �п�����Ȩ�޲����������Ϻ���ʧ��
	// ���ԡ�System Ȩ�����е�ϵͳ���̣��������
	// �ñ�����ȡ�á�debug Ȩ�޼���
	//
	static BOOL32	GetDebugPriv();

	// ��ȡ��ǰ��Ļ�ֱ��������1680*1050�ķֱ��ʵ����ű���
	static double   GetScreenScale();
	
	// �������ű����������
	static u32      GetScreenScaleWidth( u32 dwWidth );
	
	// �������ű��������߶�
	static u32      GetScreenScaleHeight( u32 dwHeight );
	
	// �������ű�������X����
	static u32      GetScreenScalePosX( u32 dwPosX );
	
	// �������ű�������Y����
	static u32      GetScreenScalePosY( u32 dwPosY );

	static void		GetScreenScaleRect( CRect& rect );

	static Image*	ScaleBitmap(Image * pBitmap ,s32 nWidth ,s32 nHeight );	
};





