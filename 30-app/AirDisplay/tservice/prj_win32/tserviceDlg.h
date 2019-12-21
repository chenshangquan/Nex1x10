
// tserviceDlg.h : 头文件
//

#pragma once


// CtserviceDlg 对话框
class CtserviceDlg : public CDialogEx
{
// 构造
public:
	CtserviceDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TSERVICE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	//重载默认的消息处理函数
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

public:
	bool UdiskIn();

	bool RegisterNotification(HWND hWnd, HDEVNOTIFY* diNotifyHandle); //注册HID设备通知
	bool UnRegisterNotification(HDEVNOTIFY* diNotifyHandle);          //取消注册HID设备通知

	CString GetModuleFullPath(void); //获取路径
	void WriteLog(  char * format,...  );//写日志

	void RebootSystem();//重启操作系统

protected:
	HICON m_hIcon;
private:
	bool m_bTimerRun;         //用于判断定时器是否在运行(投屏器重启前已经插入情况)
	
	bool m_bCheckTouchTimerRun;   //用于判断检测touch的定时器是否在运行（投屏器启动失败情况）
	int m_nFailCount;             //统计touch启动失败的次数（投屏器启动失败情况）

	HDEVNOTIFY m_hDevNotiy;   //设备状态改变通知
	
	CRITICAL_SECTION m_hSem;
	CString m_strLogFile;     //日志文件
	CString m_strCurDir;      //程序目录
};