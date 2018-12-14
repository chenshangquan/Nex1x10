#ifndef _DATALISTCLASS_H_
#define _DATALISTCLASS_H_

#include <list>
#include "semaphoreclass.h"
using namespace std;
#include "quickshare.h"

typedef list<TUSBData> DATALIST;

class CDataListClass
{
public:
	CDataListClass();
	~CDataListClass();

	void AddDataTail(TUSBData& tUSBData);//�Ӻ����������
	void DeletDataFront();//��ǰ��ɾ��һ��Ԫ��
	TUSBData& GetDataFront();//��ǰ���ȡһ��Ԫ��
	void Clear();
	bool IsEmpty();
	u32  Size();
	u32  Max_Size();

private:
	DATALIST m_dataList;

	CSemaphoreClass m_tSemaphore;
};
#endif//_DATALISTCLASS_H_