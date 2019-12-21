/*

Module Name:

    AudioCollect.h

Abstract:

    库接口文件

Author:

Revision History:

--*/
#include "stdafx.h"
#include "AVCollect.h"
#include "AudioCapture.h"
#include "DesktopCapture.h"


/*回调
******/
PAVCALLBACK      g_pAudioNetCB; //返回PCM数据
PAVCALLBACK      g_pVedioNetCB; //返回YUV数据

/*采集标志
******/
bool g_bIsInitAudio;
bool g_bIsInitVedio;

/*附加采纳数
******/
void* g_dwContext;
void* g_dwVContext;

bool g_bAuth = false;

/*采集数据类
******/
CAudioCapture g_cAudioCapture;
CDesktopCapture g_cVedioCapture;

CAudioCollect::CAudioCollect(void)
{
	g_bIsInitAudio=false;
	g_pAudioNetCB=NULL;
	g_dwContext=NULL;
}

CAudioCollect::~CAudioCollect(void)
{
	Destroy();
}


int CAudioCollect::StartAudCapture(bool bAudio)
{
	if ( !g_bAuth )
	{
		return 255;
	}
	if(bAudio && !g_bIsInitAudio)
	{
		return 10;
	}
	else
	{
		g_cAudioCapture.Start();
	}
	

	return 0;
}


int CAudioCollect::StopAudCapture(void)
{
	if ( !g_bAuth )
	{
		return 255;
	}
	g_cAudioCapture.Stop();
	
	return 0;
}


int CAudioCollect::InitAudCap()
{
	if ( !g_bAuth )
	{
		return 255;
	}
	g_cAudioCapture.Initialize();
	g_bIsInitAudio=true;
	

	return 0;
}


int CAudioCollect::Destroy(void)
{
	if ( !g_bAuth )
	{
		return 255;
	}
	g_cAudioCapture.Destroy();


	return 0;
}


bool CAudioCollect::SetAudioCallBack(PAVCALLBACK pAudioCallBack, 
		void* dwContext)
{
	if(!pAudioCallBack)
	{
		return false;
	}

	return g_cAudioCapture.SetAudioCallBack(pAudioCallBack,dwContext);

	//g_pAudioNetCB = pAudioCallBack;
	//g_dwContext=dwContext;

	//return true;
}


void CAudioCollect::GetCurrentVer(char*chVersion)
{
	if(chVersion==NULL)
	{
		return;
	}

	char chCompTime[200] = { 0 };
	sprintf_s(chCompTime, "%s %s", __DATE__, __TIME__);
	sprintf_s(chVersion, 200, "Current Version:%s,Version Compile time:%s,File Compile time:%s,Modify content:support for reporting error",
		AUDIO_VERSION_DESC, AUDIO_VERSION_COMPILE, chCompTime);

	/*sprintf_s(chVersion,200,"Current Version:%s,Compile time:%s,Modify content:support for sample rate change",
		AUDIO_VERSION_DESC,AUDIO_VERSION_COMPILE);*/

}




/************************************************************************/
//-------------------------视频采集---------------------------------------------

CVideoCollect::CVideoCollect(void)
{
	
	g_bIsInitVedio=false;
	g_pVedioNetCB=NULL;
	g_dwVContext=NULL;
}


CVideoCollect::~CVideoCollect(void)
{
	Destroy();
}


int CVideoCollect::StartVidCapture(bool bVedio)
{
	if ( !g_bAuth )
	{
		return 255;
	}
	
	if(bVedio && !g_bIsInitVedio)
	{
		return 11;
	}
	else
	{
		
		g_cVedioCapture.Create();
	}

	return 0;
}


int CVideoCollect::StopVidCapture(void)
{
	if ( !g_bAuth )
	{
		return 255;
	}
	
	g_cVedioCapture.Stop();
		
	
	return 0;
}


int CVideoCollect::SetFrameRate(int nVRate)
{
	if ( !g_bAuth )
	{
		return 255;
	}
	g_cVedioCapture.SetFrameRate(nVRate);
	return 0;
}


int CVideoCollect::InitVideoCap()
{
	if ( !g_bAuth )
	{
		return 255;
	}

	if(!g_bIsInitVedio)
	{
		g_cVedioCapture.InitAll(TRUE);
		g_bIsInitVedio=true;
	}

	return 0;
}


int CVideoCollect::Destroy(void)
{
	if ( !g_bAuth )
	{
		return 255;
	}

	g_cVedioCapture.Destroy();
	g_bIsInitVedio=false;
	return 0;
}


bool CVideoCollect::SetVideoCallBack(PAVCALLBACK pVedioCallBack, 
									void* dwContext)
{
	if(!pVedioCallBack)
	{
		return false;
	}

	g_cVedioCapture.SetVedioCallBack(pVedioCallBack,dwContext);
	return true;
}

void CVideoCollect::GetCurrentVer(char*chVersion)
{
	if(chVersion==NULL)
	{
		return;
	}

	char chCompTime[200] = { 0 };
	sprintf_s(chCompTime, "%s %s", __DATE__, __TIME__);
	sprintf_s(chVersion,200,"Current Version:%s,Version Compile time:%s,File Compile time:%s,Modify content: Resolution adjustment and reduce cpu",
		VEDIO_VERSION_DESC,VEDIO_VERSION_COMPILE, chCompTime);
}


int CVideoCollect::GetAllDisplay(TMonitorInfo* ptMonitor)
{
	return g_cVedioCapture.GetDisplayInfo(ptMonitor);
}

bool CVideoCollect::SelectCaptureScreen(int nNum)
{
	return g_cVedioCapture.SelectCaptureScreen(nNum);
}

#include "md5.h"

__declspec(dllexport) void AvMd5Encode(char* szOut, char* szIn)
{
	CMD5Encrypt cMd5;
	cMd5.GetEncrypted(szIn, szOut);
}

__declspec(dllexport) bool AvCheckAuth(char* pcBuf, int dwLen = Av_CheckAuth_MAX_LEN )
{
	if ( pcBuf == NULL || dwLen <= 0 || dwLen > Av_CheckAuth_MAX_LEN )
	{
		return false;
	}

	char szIn[Av_CheckAuth_MAX_LEN] = {0x01, 0x04, 0x08, 0x03, 0x01, 0x04, 0x08, 0x03, 0xff, 0x01, 0x04, 0x48, 0x04, 0x48, 0x04, 0x48, 
							 0x04, 0x48, 0xff, 0x01, 0x04, 0x48, 0x01, 0x04, 0x08, 0x03, 0xff, 0x01, 0x04, 0x48, 0x04, 0x00};

	char szIn2[Av_CheckAuth_MAX_LEN] = {0x01, 0x04, 0x08, 0x03, 0x01, 0x04, 0x08, 0x03, 0xff, 0x01, 0x04, 0x48, 0x04, 0x48, 0x04, 0x48, 
		0x04, 0x48, 0xff, 0x01, 0x04, 0x48, 0x01, 0x04, 0x08, 0x03, 0xff, 0x01, 0x04, 0x48, 0x06, 0x00};

	char szOut[Av_CheckAuth_MAX_LEN+1] = {0};
	CMD5Encrypt cMd5;
	cMd5.GetEncrypted(szIn, szOut);

	if ( memcmp(pcBuf, szOut, Av_CheckAuth_MAX_LEN) == 0 )
	{
		g_bAuth = true;
		return true;
	}

	memset( szOut, 0, sizeof(szOut) );
	cMd5.GetEncrypted(szIn2, szOut);
	if ( memcmp(pcBuf, szOut, Av_CheckAuth_MAX_LEN) == 0 )
	{
		g_bAuth = true;
		return true;
	}

	return false;
}

__declspec(dllexport) void SetVidPrtSwitchOn(bool bPrtSwitchOn)
{
	g_cVedioCapture.SetVidPrtSwitchOn(bPrtSwitchOn);
}

__declspec(dllexport) bool SetGrabMode(EmGrabMode emGrabMode)
{
	return g_cVedioCapture.SetGrabMode(emGrabMode);
}

__declspec(dllexport) EmGrabMode GetGrabMode()
{
	return g_cVedioCapture.GetGrabMode();
}