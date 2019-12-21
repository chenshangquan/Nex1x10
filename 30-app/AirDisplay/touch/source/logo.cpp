#include "stdafx.h"
#include "logo.h"



CLogo::CLogo()
{

}

CLogo::~CLogo()
{
	
}

CString CLogo::GetModuleFullPath( void )
{
	TCHAR achDllName[32768] = _T("");
	CString csPath = _T("");

	//AfxGetInstanceHandle()���ܻ�ȡʧ��
	// 	GetModuleFileName( AfxGetInstanceHandle(), achDllName, MAX_PATH);

	MEMORY_BASIC_INFORMATION mbi;   
	static int dummy; 
	u32 dwLength = sizeof(mbi); 
	if ( dwLength == VirtualQuery( &dummy, &mbi, dwLength ) )
	{
		GetModuleFileName( reinterpret_cast<HMODULE>(mbi.AllocationBase), achDllName, _countof(achDllName) ); 
		size_t nBuffLen = GetLongPathName( achDllName, 0, 0 );
		if ( nBuffLen == _tcslen( achDllName ) )
		{
			csPath = achDllName;
		}
		else
		{
			TCHAR* pChar = new TCHAR[nBuffLen + 1];
			ZeroMemory( pChar, sizeof(TCHAR) * ( nBuffLen + 1 ) );
			GetLongPathName( achDllName, pChar, nBuffLen );
			csPath = pChar;
			delete[] pChar;
		}		
	}

	csPath = csPath.Left( csPath.ReverseFind(_T('\\')) + 1 );

	return csPath;
}

BOOL CLogo::MakeImgByChar(const LPCTSTR strCharacters, const LPCTSTR strFontFamily,const FontStyle emFontStyle, 
	const Color clText, const Color clBorder, const Color clBkGrd, const int nFontSizeByPx,const int borderWidthByPx, const LPCTSTR strFileName, int nWidth, int nHeight)
{
	HDC hDc = ::GetDC( NULL );
	HDC hDcMem =  CreateCompatibleDC( hDc); 

	Gdiplus::Font *pFont = new Gdiplus::Font(strFontFamily,nFontSizeByPx*72/72,emFontStyle);//DPI��96 ����px�� *72/96 

	CString txt(strCharacters);
	BSTR bstrText = txt.AllocSysString();

	// ���㵱ǰ���ֵĳ��ȣ���ȷ��ͼƬ�ĳ��Ϳ�
	CSize cSize(0,0);
	GetCharExtent( bstrText,pFont,cSize);
	cSize.cx += borderWidthByPx;
	cSize.cy += borderWidthByPx;
	while ( cSize.cx % 4 != 0 )
	{
		cSize.cx++;
	}

	if (nWidth>0)
	{
		cSize.cx = nWidth;
	}

	if (nHeight>0)
	{
		cSize.cy = nHeight;
	}

	while ( cSize.cy % 4 != 0 )
	{
		cSize.cy++;
	}


	BITMAPINFOHEADER stBmpInfoHeader = { 0 };   
	int nBytesPerLine = cSize.cx;//((cSize.cx * 32 + 31) & (~31)) >> 3;
	if (cSize.cx%4 != 0)
	{
		nBytesPerLine = cSize.cx + 4;
	}
	stBmpInfoHeader.biSize = sizeof(BITMAPINFOHEADER);   
	stBmpInfoHeader.biWidth = cSize.cx;   
	stBmpInfoHeader.biHeight = cSize.cy;   
	stBmpInfoHeader.biPlanes = 1;
	stBmpInfoHeader.biBitCount = 32;   
	stBmpInfoHeader.biCompression = BI_RGB;   
	stBmpInfoHeader.biClrUsed = 0;   
	stBmpInfoHeader.biSizeImage = nBytesPerLine * cSize.cy;	

	PUINT32 pvBits = NULL;   
	HBITMAP hBtMap = ::CreateDIBSection(NULL, (PBITMAPINFO)&stBmpInfoHeader, DIB_RGB_COLORS, (LPVOID*)&pvBits, NULL, 0);
	if (hBtMap)   
	{   
		::SelectObject(  hDcMem, hBtMap); 
	}


	Graphics graph(hDcMem); 
	graph.Clear( clBkGrd ); 

	if ( strFontFamily != _T("����"))
	{
		graph.SetSmoothingMode(SmoothingModeAntiAlias);     
		graph.SetInterpolationMode(InterpolationModeHighQualityBicubic); 
		// 		graph.SetSmoothingMode( SmoothingModeHighQuality );
		graph.SetTextRenderingHint(TextRenderingHint(TextRenderingHintAntiAlias));
	}
	else
	{
		//graph.SetSmoothingMode(SmoothingModeHighQuality); 

		// 		ARGB argb = clText.GetValue(); 
		// 		argb = (argb & 0x00FFFFFF) | ( 0xFE << 24 );
		// 		(const_cast<Color &>(clText)).SetValue ( argb );
		// 				
		// 		argb = clBorder.GetValue(); 
		// 		argb = (argb & 0x00FFFFFF) | ( 0xFE << 24 );
		//         (const_cast<Color &>(clBorder)).SetValue( argb );
	} 	

	StringFormat  cStringFormat ;
	cStringFormat.SetAlignment( StringAlignmentNear );//StringAlignmentNear  ��Ϊ����
	cStringFormat.SetLineAlignment(StringAlignmentNear);
	cStringFormat.SetFormatFlags( StringFormatFlagsNoWrap | StringFormatFlagsMeasureTrailingSpaces );
	cStringFormat.SetTrimming(StringTrimmingEllipsisCharacter); 

	GraphicsPath txtPath(FillModeWinding);
	FontFamily fm;
	pFont->GetFamily(&fm); 

	txtPath.AddString(bstrText, -1 ,&fm, emFontStyle , nFontSizeByPx /**72/96*/ /* + borderWidthByPx*/ , RectF(0, 0, TEXT_WIDTH/*cSize.cx*/ , cSize.cy ),&cStringFormat); 


	SolidBrush brush( clText );  
	Pen borderPen( clBorder, borderWidthByPx *2 ); 
	borderPen.SetLineJoin(LineJoinRound);


	graph.DrawPath(&borderPen,&txtPath);
	graph.FillPath(&brush,&txtPath); 

	SysFreeString( bstrText ); 
	BOOL bSuccess = SaveBitmapToFile(hBtMap,strFileName);
	DeleteObject(hBtMap);
	DeleteObject(hDcMem);
	::ReleaseDC(NULL, hDc );
	delete pFont;
	pFont = NULL;
	return bSuccess;
}

void CLogo::GetCharExtent( IN const WCHAR * strCharacters, Gdiplus::Font*pFont, CSize& cSize )
{
	HDC hDc = ::GetDC( NULL ); 
	Graphics graph(hDc);
	RectF rcf;
	graph.MeasureString(strCharacters,-1,pFont,PointF(0,0),&rcf); 

	cSize.cx = rcf.Width;
	cSize.cy =  rcf.Height;

	if ( rcf.Width > cSize.cx )
	{
		cSize.cx += 1;
	}

	if ( rcf.Height > cSize.cy )
	{
		cSize.cy += 1;
	}

	::ReleaseDC(NULL, hDc ); 
}

BOOL CLogo::SaveBitmapToFile(HBITMAP   hBitmap, CString szfilename)
{
	HDC hDC; //   �豸������    
	int iBits; //   ��ǰ��ʾ�ֱ�����ÿ��������ռ�ֽ��� 
	WORD wBitCount; //   λͼ��ÿ��������ռ�ֽ���   
	DWORD dwPaletteSize = 0   ; //   �����ɫ���С��  λͼ�������ֽڴ�С  �� 
	//   λͼ�ļ���С  ��  д���ļ��ֽ���

	DWORD dwBmBitsSize   ;  
	DWORD dwDIBSize, dwWritten   ;  
	BITMAP Bitmap;      
	BITMAPFILEHEADER bmfHdr; //λͼ���Խṹ 
	BITMAPINFOHEADER bi; //λͼ�ļ�ͷ�ṹ  
	LPBITMAPINFOHEADER lpbi;   //λͼ��Ϣͷ�ṹ   
	HANDLE fh,   hDib,   hPal,hOldPal = NULL   ; //ָ��λͼ��Ϣͷ�ṹ,�����ļ��������ڴ�������ɫ����

	//����λͼ�ļ�ÿ��������ռ�ֽ��� 
	// 	hDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL); 
	// 	iBits = GetDeviceCaps(hDC, BITSPIXEL) * GetDeviceCaps(hDC, PLANES)  ;  
	// 	DeleteDC(hDC)   ;  
	// 	if (iBits <= 1)
	// 	{
	// 		wBitCount = 1;
	// 	}
	// 	else if (iBits <= 4)
	// 	{
	// 		wBitCount = 4;
	// 	}
	// 	else if (iBits <= 8)
	// 	{
	// 		wBitCount = 8;
	// 	}
	// 	else if (iBits <= 24)
	// 	{
	// 		wBitCount = 24;
	// 	}
	// 	else if (iBits <= 32)
	// 	{
	// 		wBitCount = 32;
	// 	}  
	wBitCount = 32;
	//�����ɫ���С 

	if (wBitCount <= 8)
	{
		dwPaletteSize = (1 << wBitCount) * sizeof(RGBQUAD)   ;
	} 

	//����λͼ��Ϣͷ�ṹ 

	GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&Bitmap)   ;  
	bi.biSize = sizeof(BITMAPINFOHEADER);  
	bi.biWidth = Bitmap.bmWidth;  
	bi.biHeight = Bitmap.bmHeight;   
	bi.biPlanes = 1;  
	bi.biBitCount = wBitCount;     
	bi.biCompression = BI_RGB;  
	bi.biSizeImage = 0;  
	bi.biXPelsPerMeter = 0;  
	bi.biYPelsPerMeter = 0;  
	bi.biClrUsed = 0;  
	bi.biClrImportant = 0;   
	dwBmBitsSize = ((Bitmap.bmWidth * wBitCount + 31) / 32) * 4 * Bitmap.bmHeight   ;
	//Ϊλͼ���ݷ����ڴ� 
	hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER))   ;   
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib)   ;
	*lpbi = bi;  
	//   �����ɫ��  
	hPal = GetStockObject(DEFAULT_PALETTE);  
	if (hPal)
	{
		hDC = ::GetDC(NULL);  
		hOldPal = SelectPalette(hDC, (HPALETTE)hPal, FALSE)   ;  
		RealizePalette(hDC)   ;
	} 

	//   ��ȡ�õ�ɫ�����µ�����ֵ 
	GetDIBits(hDC, hBitmap, 0, (UINT)Bitmap.bmHeight, (LPSTR)lpbi + sizeof(BITMAPINFOHEADER) + dwPaletteSize, (LPBITMAPINFO)lpbi, DIB_RGB_COLORS);   

	//�ָ���ɫ��   
	if (hOldPal)
	{
		SelectPalette(hDC, (HPALETTE)hOldPal, TRUE); 
		RealizePalette(hDC)   ;   
		::ReleaseDC(NULL, hDC)   ;
	} 
	//����λͼ�ļ�
	fh = CreateFile(szfilename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL)   ; 
	if (fh == INVALID_HANDLE_VALUE)
	{
		return   false;
	}    

	//   ����λͼ�ļ�ͷ 

	bmfHdr.bfType = 0x4D42;  //   "BM" 
	dwDIBSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dwPaletteSize + dwBmBitsSize;    
	bmfHdr.bfSize = dwDIBSize;  
	bmfHdr.bfReserved1 = 0;  
	bmfHdr.bfReserved2 = 0;  
	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER) + dwPaletteSize;  
	//   д��λͼ�ļ�ͷ 
	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);  
	//   д��λͼ�ļ��������� 
	WriteFile(fh, (LPSTR)lpbi, dwDIBSize, &dwWritten, NULL);  
	//�����ڴ����     
	GlobalUnlock(hDib);   
	GlobalFree(hDib);  
	CloseHandle(fh);  
	return   true;
}


