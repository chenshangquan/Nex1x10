/**  
 *@ ���ܣ�����̨��ͼƬ
 *@ ����: wk
 *@ ʱ��: 2017-7-27
 */
#ifndef _LOGO_H_
#define _LOGO_H_

//logo��ֵ --1080p
#define TEXT_WIDTH			    700
#define LOGO_HEIGHT			    104
#define LOGO_POINTSIZE			60
#define LOGO_TEXT_COLOR         Color(255,201,14)
#define LOGO_LEFT			    80
#define TEXT_TOP			    45

#define TP_TEMPFILE_PATH       _T("temp\\")
#define LOGO_BMP_FILE          _T("logo.bmp")

class CLogo
{
public:
	CLogo();
	~CLogo();

	/**
	*����:��ȡģ�������ļ���ȫ·��, ��������\
	*@param[in] 
	*@return ����·��
    */
	static CString GetModuleFullPath(void);
	/**	 
	* ����: ������ʾ���ֵ�ͼƬ
	* @param    const LPCTSTR strCharacters     [in]     ��������
	* @param    const LPCTSTR strFontFamily     [in]     �����ʽ(���塢΢���źڵ�) 
	* @param    const FontStyle emFontStyle     [in]     ����ṹ(�Ӵ֡��»��ߵ�) 
	* @param    const Color clText				[in]     ������ɫ 
	* @param    const Color clBorder			[in]     ����߽���ɫ 
	* @param    const Color clBkGrd				[in]     ͼƬ������ɫ 
	* @param    const int nFontSizeByPx			[in]     ����Px 
	* @param    const int borderWidthByPx		[in]     ����߽�Px 
	* @param    const LPCTSTR strFileName		[in]     ͼƬ�洢·�� 
	* @return   bool
	* @remarks  
	*/
	static BOOL MakeImgByChar(const LPCTSTR strCharacters, const LPCTSTR strFontFamily,const FontStyle emFontStyle, const Color clText, const Color clBorder, 
		const Color clBkGrd, const int nFontSizeByPx,const int borderWidthByPx, const LPCTSTR strFileName, int nWidth = 0, int nHeight = 0 );
	
	/**	 
	* ����: ��ȡ��ʾ���ֵĴ�С
	* @param    const WCHAR * strCharacters     [in]     ��������
	* @param    Font*pFont				        [in]     ����������Ϣ
	* @param    CSize& cSize					[out]    ���ֵĴ�С
	* @return   
	* @remarks  
	*/
	static void GetCharExtent(IN const WCHAR * strCharacters, Gdiplus::Font*pFont, CSize& cSize);
	/**	 
	* ����: ����ͼƬ
	* @param    HBITMAP   hBitmap     [in]     ͼƬ���
	* @param    CString szfilename	  [in]     ���·��
	* @return   BOOL �Ƿ񱣴�ɹ�
	* @remarks  
	*/
	static BOOL SaveBitmapToFile(HBITMAP   hBitmap, CString szfilename);

};

#endif//_LOGO_H_