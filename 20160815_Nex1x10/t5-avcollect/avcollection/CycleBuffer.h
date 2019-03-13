/*

Module Name:

    CycleBuffer.h

Abstract:

    ѭ������

Author:

Revision History:

--*/
#ifndef __test__CCycleBuffer__  
#define __test__CCycleBuffer__  
  
#pragma once

#include <iostream>  
#include <assert.h>  

class CCycleBuffer
{
public:
	CCycleBuffer(void);
    CCycleBuffer(int size); 
	~CCycleBuffer(void);
public:  
	/*�Ƿ���
	******/
    bool isFull(); 
	/*�Ƿ��
	******/
    bool isEmpty();
	/*��
	******/
    void Empty(); 
	/*���ݳ���
	******/
    int GetLength();  
 
	/*д����
	******/
    int Write(unsigned char* buf, int count);  
	/*������
	******/
    int Read(unsigned char* buf, int count);  
private:  
    bool m_bEmpty, m_bFull;  
    unsigned char * m_pBuf;  
	/*�����С
	******/
    int m_nBufSize;  
	/*��ָ��
	******/
    int m_nReadPos;  
	/*дָ��
	******/
    int m_nWritePos;  
      
public:  
	/*��ȡָ��λ��
	******/
    int GetReadPos() { return m_nReadPos; }  
    int GetWritePos() { return m_nWritePos; }
};


#endif /* defined(__test__CCycleBuffer__) */  