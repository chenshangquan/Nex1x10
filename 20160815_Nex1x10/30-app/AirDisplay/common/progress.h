/**  
 *@ ���ܣ�������غ�����װ��
 *@ ����: wk
 *@ ʱ��: 2017-8-9
 */
#ifndef _PROGRESS_H_
#define _PROGRESS_H_

class CProgress
{
public:
	CProgress();
	~CProgress();

	/** 
	*����:�򿪽���
	*@param CString strPathName [in] ����·����exe�ļ���
	*@return bool �Ƿ�򿪳ɹ�
	*/
	static bool OpenProgress(CString strPathName);
	/** 
	*����:�رս���
	*param CString strName [in] exe�ļ���
	*@return ��
	*/
	static void CloseProgress(CString strName);
	/** 
	*����:��ȡ����id
	*@param CString strName [in] exe�ļ���
	*@return DWORD ���ؽ���id,����ֵ��Ϊ0����̴��ڣ�Ϊ0����̲�����
	*/
	static DWORD GetProcessidFromName(CString strName);
	/** 
	*����:�жϽ����Ƿ���������
	*@param CString strName [in] exe�ļ���
	*@return bool �Ƿ���������
	*/
	static bool IsProgressRunning(CString strName);

};

#endif//_PROGRESS_H_