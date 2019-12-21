
// tserviceDlg.h : ͷ�ļ�
//

#pragma once


// CtserviceDlg �Ի���
class CtserviceDlg : public CDialogEx
{
// ����
public:
	CtserviceDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TSERVICE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	//����Ĭ�ϵ���Ϣ������
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

public:
	bool UdiskIn();

	bool RegisterNotification(HWND hWnd, HDEVNOTIFY* diNotifyHandle); //ע��HID�豸֪ͨ
	bool UnRegisterNotification(HDEVNOTIFY* diNotifyHandle);          //ȡ��ע��HID�豸֪ͨ

	CString GetModuleFullPath(void); //��ȡ·��
	void WriteLog(  char * format,...  );//д��־

	void RebootSystem();//��������ϵͳ

protected:
	HICON m_hIcon;
private:
	bool m_bTimerRun;         //�����ж϶�ʱ���Ƿ�������(Ͷ��������ǰ�Ѿ��������)
	
	bool m_bCheckTouchTimerRun;   //�����жϼ��touch�Ķ�ʱ���Ƿ������У�Ͷ��������ʧ�������
	int m_nFailCount;             //ͳ��touch����ʧ�ܵĴ�����Ͷ��������ʧ�������

	HDEVNOTIFY m_hDevNotiy;   //�豸״̬�ı�֪ͨ
	
	CRITICAL_SECTION m_hSem;
	CString m_strLogFile;     //��־�ļ�
	CString m_strCurDir;      //����Ŀ¼
};