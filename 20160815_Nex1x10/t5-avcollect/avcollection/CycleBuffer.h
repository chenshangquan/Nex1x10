/*

Module Name:

    CycleBuffer.h

Abstract:

    循环缓存

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
	/*是否满
	******/
    bool isFull(); 
	/*是否空
	******/
    bool isEmpty();
	/*空
	******/
    void Empty(); 
	/*数据长度
	******/
    int GetLength();  
 
	/*写数据
	******/
    int Write(unsigned char* buf, int count);  
	/*读数据
	******/
    int Read(unsigned char* buf, int count);  
private:  
    bool m_bEmpty, m_bFull;  
    unsigned char * m_pBuf;  
	/*缓存大小
	******/
    int m_nBufSize;  
	/*读指针
	******/
    int m_nReadPos;  
	/*写指针
	******/
    int m_nWritePos;  
      
public:  
	/*获取指针位置
	******/
    int GetReadPos() { return m_nReadPos; }  
    int GetWritePos() { return m_nWritePos; }
};


#endif /* defined(__test__CCycleBuffer__) */  