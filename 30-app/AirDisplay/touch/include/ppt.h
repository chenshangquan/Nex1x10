/**  
 *@ ���ܣ�ppt��غ���
 *@ ����: wk
 *@ ʱ��: 2018-4-19
 */
#ifndef _PPT_H_
#define _PPT_H_

class CPpt
{
public:
	CPpt();
	~CPpt();

	static bool IsPptPlaying();                                       //�ж�ppt�Ƿ����ڲ���

	static void PPT_StopPlay();                                       //ֹͣ����
	static void PPT_NextPage();                                       //��һҳ
	static void PPT_PriviousPage();                                   //��һҳ

private:
	static BOOL IsFullScreenActive(DWORD &dwProcessID);               //�жϵ�ǰ������Ƿ�ȫ��  
	static BOOL ProcessIdToName(CString &strProcessName, DWORD dwPID);//�ɽ���ID��ȡ����
	static bool CheckSame(DWORD dwProcessID,int niX,int niY);         //�ж���Ļ�ϵ�һ��(niX,niY)������process id�Ƿ��dwProcessID��ͬ 
};

#endif//_PPT_H_
