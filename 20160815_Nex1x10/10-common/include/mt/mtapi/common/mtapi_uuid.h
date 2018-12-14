/**===========================================================================
 * @file    $Id$
 * @brief   提供mtapi所有MT_UUID结构定义实现(windows guid和linux uuid)
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note   linux获取命令 uuidgen
============================================================================*/

#ifndef _MTAPI_UUID_H_
#define _MTAPI_UUID_H_

#include "kdvtype.h"
#include <string.h> //linux中包含memcmp 
#include <string>
 


/** 自定义 GUID/UUID (LINUX uuidgen) */
typedef struct _MT_UUID {
	u32 Data1;
	u16 Data2;
	u16 Data3;
	u8  Data4[ 8 ];

}MT_UUID;

#define IsEqualMT_UUID(ID1, ID2) (!memcmp(&ID1, &ID2, sizeof(MT_UUID)))

__inline s32 operator==(MT_UUID ID1, MT_UUID ID2)
{
	return !memcmp(&ID1, &ID2, sizeof(MT_UUID));
}

/************************************************************************/
/*                     Common  IID                                      */
/************************************************************************/
/** IID_MTAPI_INTERFACE  = {28175898-4447-4453-8259-1e22ef9e8832}  */
static const MT_UUID IID_MTAPI_INTERFACE = 
{ 0x28175898, 0x4447, 0x4453, { 0x82, 0x59, 0x1e, 0x22, 0xef, 0x9e, 0x88, 0x32 } };

/** IID_MTAPI_MTAPI = {F6E0184C-800B-4B93-8119-7544EFC9FF54}  */
static const MT_UUID IID_MTAPI_MTAPI = 
{ 0xf6e0184c, 0x800b, 0x4b93, { 0x81, 0x19, 0x75, 0x44, 0xef, 0xc9, 0xff, 0x54 } };

/** IID_MTAPI_MTFSET = {5CF43261-0CA4-4EF5-B7A0-827AF3B15973}  */
static const MT_UUID IID_MTAPI_MTFSET = 
{ 0x5cf43261, 0xca4, 0x4ef5, { 0xb7, 0xa0, 0x82, 0x7a, 0xf3, 0xb1, 0x59, 0x73 } };




/************************************************************************/
/*               C1. MtBaseApi(mtbaseapi) CID                           */
/************************************************************************/
/** CID_MTAPI_MTBASEAPI = {8c22471b-3d90-49af-93cd-a03a2419b912}  */
static const MT_UUID CID_MTAPI_MTBASEAPI = 
{ 0x8c22471b, 0x3d90, 0x49af, { 0x93, 0xcd, 0xa0, 0x3a, 0x24, 0x19, 0xb9, 0x12 } };

/** CID_MTAPI_MTBASEFSET = {6066eecb-f5c4-47ad-bcf0-57e73a52f2e1}  */
static const MT_UUID CID_MTAPI_MTBASEFSET = 
{ 0x6066eecb, 0xf5c4, 0x47ad, { 0xbc, 0xf0, 0x57, 0xe7, 0x3a, 0x52, 0xf2, 0xe1 } };

/** CID_MTAPI_MTENTITY = {14b6a9be-5b20-4f22-90b9-9bb9961ac8b2}  */
static const MT_UUID CID_MTAPI_MTENTITY = 
{ 0x14b6a9be, 0x5b20, 0x4f22, { 0x90, 0xb9, 0x9b, 0xb9, 0x96, 0x1a, 0xc8, 0xb2 } };

/** CID_MTAPI_MTUSER = {ec936d50-e330-4ba9-8696-bb1872d36e7e}  */
static const MT_UUID CID_MTAPI_MTUSER = 
{ 0xec936d50, 0xe330, 0x4ba9, { 0x86, 0x96, 0xbb, 0x18, 0x72, 0xd3, 0x6e, 0x7e } };

/** CID_MTAPI_REMOTE_MTDATASHARE = {ab1b98d4-b0d5-4133-a377-4e57b2bd8040}  */
static const MT_UUID CID_MTAPI_REMOTE_MTDATASHARE = 
{ 0xab1b98d4, 0xb0d5, 0x4133, { 0xa3, 0x77, 0x4e, 0x57, 0xb2, 0xbd, 0x80, 0x40 } };

/** CID_MTAPI_LOCAL_MTDATASHARE = {d460f247-385e-484d-854a-da1454a67c3a}  */
static const MT_UUID CID_MTAPI_LOCAL_MTDATASHARE = 
{ 0xd460f247, 0x385e, 0x484d, { 0x85, 0x4a, 0xda, 0x14, 0x54, 0xa6, 0x7c, 0x3a } };

/** CID_MTAPI_MTDETECT = {F6687C2F-6AFE-462B-A8C8-A9E8A0C5935D}  */
static const MT_UUID CID_MTAPI_MTDETECT = 
{ 0xf6687c2f, 0x6afe, 0x462b, { 0xa8, 0xc8, 0xa9, 0xe8, 0xa0, 0xc5, 0x93, 0x5d } };

/** CID_MTAPI_MTSTATIS = {177AB96E-8D6C-458F-827A-CC249A601841}  */
static const MT_UUID CID_MTAPI_MTSTATIS = 
{ 0x177ab96e, 0x8d6c, 0x458f, { 0x82, 0x7a, 0xcc, 0x24, 0x9a, 0x60, 0x18, 0x41 } };

/** CID_MTAPI_MTSERVICECTRL =  {53E85A7A-7D8B-4C5F-A20B-E59DD1859CEC}  */
static const MT_UUID CID_MTAPI_MTSERVICECTRL = 
{ 0x53e85a7a, 0x7d8b, 0x4c5f, { 0xa2, 0xb, 0xe5, 0x9d, 0xd1, 0x85, 0x9c, 0xec } };
 
/** CID_MTAPI_MTSERVERLOGIN =  {62C037B1-915E-4BA2-A6A2-A8E5EB2BBC7F}  */
static const MT_UUID CID_MTAPI_MTSERVERLOGIN = 
{ 0x62c037b1, 0x915e, 0x4ba2, { 0xa6, 0xa2, 0xa8, 0xe5, 0xeb, 0x2b, 0xbc, 0x7f } };

// {5E36291C-FE6C-4203-B4BF-5CB4E5100F3D}
static const MT_UUID CID_MTAPI_MTNETWORK = 
{ 0x5e36291c, 0xfe6c, 0x4203, { 0xb4, 0xbf, 0x5c, 0xb4, 0xe5, 0x10, 0xf, 0x3d } };

// {95EC784C-C9BD-4034-A992-1D7459DA6D10}
static const MT_UUID CID_MTAPI_MTCOMMON = 
{ 0x95ec784c, 0xc9bd, 0x4034, { 0xa9, 0x92, 0x1d, 0x74, 0x59, 0xda, 0x6d, 0x10 } };

// {506B8FA3-C335-48F4-85C7-79014AE42549}
static const MT_UUID CID_MTAPI_MTAGENT = 
{ 0x506b8fa3, 0xc335, 0x48f4, { 0x85, 0xc7, 0x79, 0x1, 0x4a, 0xe4, 0x25, 0x49 } };


/************************************************************************/
/*               I1. MtBaseApi(mtbaseapi) IID                           */
/************************************************************************/
/** IID_MTAPI_MTBASEAPI = {db99bdf3-8a41-46e1-9741-356a8d15272a}  */
static const MT_UUID IID_MTAPI_MTBASEAPI = 
{ 0xdb99bdf3, 0x8a41, 0x46e1, { 0x97, 0x41, 0x35, 0x6a, 0x8d, 0x15, 0x27, 0x2a } };


/** IID_MTAPI_MTBASEFSET = {ea006618-fbd1-4985-8b45-652106119098}  */
static const MT_UUID IID_MTAPI_MTBASEFSET = 
{ 0xea006618, 0xfbd1, 0x4985, { 0x8b, 0x45, 0x65, 0x21, 0x06, 0x11, 0x90, 0x98 } };


/** IID_MTAPI_MTENTITY = {9c2f66b3-0227-4234-9bfd-526d84c63ab2}  */
static const MT_UUID IID_MTAPI_MTENTITY = 
{ 0x9c2f66b3, 0x0227, 0x4234, { 0x9b, 0xfd, 0x52, 0x6d, 0x84, 0xc6, 0x3a, 0xb2 } };

/** IID_MTAPI_MTUSER = {242ae735-340b-454e-a0db-c713af5c226d}  */
static const MT_UUID IID_MTAPI_MTUSER = 
{ 0x242ae735, 0x340b, 0x454e, { 0xa0, 0xdb, 0xc7, 0x13, 0xaf, 0x5c, 0x22, 0x6d } };


/** IID_MTAPI_DATASHARE = {e92d17a4-947e-4297-9476-1b898fa26a95}  */
static const MT_UUID IID_MTAPI_MTDATASHARE = 
{ 0xe92d17a4, 0x947e, 0x4297, { 0x94, 0x76, 0x1b, 0x89, 0x8f, 0xa2, 0xba, 0x95 } };


/** IID_MTAPI_MTDETECT = {88d44735-d580-42fd-bf62-7324a2d8544d}  */
static const MT_UUID IID_MTAPI_MTDETECT = 
{ 0x88d44735, 0xd580, 0x42fd, { 0xbf, 0x62, 0x73, 0x24, 0xa2, 0xd8, 0x54, 0x4d } };

/** IID_MTAPI_MTSTATIS = {bdbfd931-8037-46a0-b73d-81dd9cfbcb6c}  */
static const MT_UUID IID_MTAPI_MTSTATIS = 
{ 0xbdbfd931, 0x8037, 0x46a0, { 0xb7, 0x3d, 0x81, 0xdd, 0x9c, 0xfb, 0xcb, 0x6c } };

/** IID_MTAPI_MTRMTDATASHARE = {938baac3-d5ef-4eca-ad47-7fed0556969d}  */
static const MT_UUID IID_MTAPI_MTRMTDATASHARE = 
{ 0x938baac3, 0xd5ef, 0x4eca, { 0xad, 0x47, 0x7f, 0xed, 0x05, 0x56, 0x96, 0x9d } };


/** IID_MTAPI_MTSERVICECTRL = {AB95E420-FB0F-491B-890C-4CF290AEFCE7}  */
static const MT_UUID IID_MTAPI_MTSERVICECTRL = 
{ 0xab95e420, 0xfb0f, 0x491b, { 0x89, 0xc, 0x4c, 0xf2, 0x90, 0xae, 0xfc, 0xe7 } };


/** IID_MTAPI_MTSERVERLOGIN {26EAF336-A0DF-41CB-9EE1-4FC77D122AD3}   */
static const MT_UUID IID_MTAPI_MTSERVERLOGIN = 
{ 0x26eaf336, 0xa0df, 0x41cb, { 0x9e, 0xe1, 0x4f, 0xc7, 0x7d, 0x12, 0x2a, 0xd3 } };

// {5B17F1CF-EA02-477F-BCF9-3D8023405811}
static const MT_UUID IID_MTAPI_MTCOMMON = 
{ 0x5b17f1cf, 0xea02, 0x477f, { 0xbc, 0xf9, 0x3d, 0x80, 0x23, 0x40, 0x58, 0x11 } };

// {DC934FCE-0DA3-44C3-93F5-E606C40F4774}
static const MT_UUID IID_MTAPI_MTNETWORK = 
{ 0xdc934fce, 0xda3, 0x44c3, { 0x93, 0xf5, 0xe6, 0x6, 0xc4, 0xf, 0x47, 0x74 } };

// {1B5A657A-796E-4405-8A08-B9613A8F1C89}
static const MT_UUID IID_MTAPI_MTAGENT = 
{ 0x1b5a657a, 0x796e, 0x4405, { 0x8a, 0x8, 0xb9, 0x61, 0x3a, 0x8f, 0x1c, 0x89 } };

/************************************************************************/
/*               C2. MtVcApi(mtvideoconfapi) CID                        */
/************************************************************************/
/** CID_MTAPI_MTVCAPI = {1e2dcee7-3e91-4f91-91f4-54b09018c21b}  */
static const MT_UUID CID_MTAPI_MTVCAPI = 
{ 0x1e2dcee7, 0x3e91, 0x4f91, { 0x91, 0xf4, 0x54, 0xb0, 0x90, 0x18, 0xc2, 0x1b } };

/** CID_MTAPI_MTVCFSET = {ccca270c-ebd5-4ee6-abcb-b2c49c58791d}  */
static const MT_UUID CID_MTAPI_MTVCFSET = 
{ 0xccca270c, 0xebd5, 0x4ee6, { 0xab, 0xcb, 0xb2, 0xc4, 0x9c, 0x58, 0x79, 0x1d } };

/** CID_MTAPI_MTCAMERA = {d7d8cec5-0be7-4874-bb37-4683e92d2a9c}  */
static const MT_UUID CID_MTAPI_MTCAMERA = 
{ 0xd7d8cec5, 0x0be7, 0x4874, { 0xbb, 0x37, 0x46, 0x83, 0xe9, 0x2d, 0x2a, 0x9c } };

/** CID_MTAPI_MTMONITOR = {35c7a5f9-1ef5-4ca3-8c87-1e62770e3620}  */
static const MT_UUID CID_MTAPI_MTMONITOR = 
{ 0x35c7a5f9, 0x1ef5, 0x4ca3, { 0x8c, 0x87, 0x1e, 0x62, 0x77, 0x0e, 0x36, 0x20 } };
 
/** CID_MTAPI_MTCONF = {7ae84aad-ef26-4b40-9edc-8c4a205706a8}  */
static const MT_UUID CID_MTAPI_MTCONF = 
{ 0x7ae84aad, 0xef26, 0x4b40, { 0x9e, 0xdc, 0x8c, 0x4a, 0x20, 0x57, 0x06, 0xa8 } };


/** CID_MTAPI_MTREMOTECTRL = {e222463f-ed36-4439-92c4-75a6bfc69098}  */
static const MT_UUID CID_MTAPI_MTREMOTECTRL = 
{ 0xe222463f, 0xed36, 0x4439, { 0x92, 0xc4, 0x75, 0xa6, 0xbf, 0xc6, 0x90, 0x98 } };

/** CID_MTAPI_MTAUDIO = {3061dc77-3930-4c48-9f48-bf9760966ed4}  */
static const MT_UUID CID_MTAPI_MTAUDIO = 
{ 0x3061dc77, 0x3930, 0x4c48, { 0x9f, 0x48, 0xbf, 0x97, 0x60, 0x96, 0x6e, 0xd4 } };


/** CID_MTAPI_MTVOD = {4C5857F7-1C04-4FF0-85CB-ACD5C29988BA}  */
static const MT_UUID CID_MTAPI_MTVOD = 
{ 0x4c5857f7, 0x1c04, 0x4ff0, { 0x85, 0xcb, 0xac, 0xd5, 0xc2, 0x99, 0x88, 0xba } };


/** CID_MTAPI_MTMC = {855C7F76-F717-4BAD-AE7E-EED1591FAFBD}  */
static const MT_UUID CID_MTAPI_MTMC = 
{ 0x855c7f76, 0xf717, 0x4bad, { 0xae, 0x7e, 0xee, 0xd1, 0x59, 0x1f, 0xaf, 0xbd } };


/** CID_MTAPI_MTSNAPSHOT = {8E1DF17E-A2EE-4B51-8E40-185F2075C9FF}  */
static const MT_UUID CID_MTAPI_MTSNAPSHOT = 
{ 0x8e1df17e, 0xa2ee, 0x4b51, { 0x8e, 0x40, 0x18, 0x5f, 0x20, 0x75, 0xc9, 0xff } };


/************************************************************************/
/*               I2. MtVcApi(mtvideoconfapi) IID                        */
/************************************************************************/

/** IID_MTAPI_MTCAMERA = {a8839b65-e333-455f-95f3-0ed99f7392d9}  */
static const MT_UUID IID_MTAPI_MTCAMERA = 
{ 0xa8839b65, 0xe333, 0x455f, { 0x95, 0xf3, 0x0e, 0xd9, 0x9f, 0x73, 0x92, 0xd9 } };


/** IID_MTAPI_MTMONITOR = {847f45b7-96db-49fe-b466-3f6e4dc87775}  */
static const MT_UUID IID_MTAPI_MTMONITOR = 
{ 0x847f45b7, 0x96db, 0x49fe, { 0xb4, 0x66, 0x3f, 0x6e, 0x4d, 0xc8, 0x77, 0x75 } };


/** IID_MTAPI_MTCONF = {83b0e538-c08e-4bf5-97f0-376e6a0d858e}  */
static const MT_UUID IID_MTAPI_MTCONF = 
{ 0x83b0e538, 0xc08e, 0x4bf5, { 0x97, 0xf0, 0x37, 0x6e, 0x6a, 0x0d, 0x85, 0x8e } };


/** IID_MTAPI_MTREMOTECTRL = {317c50cc-30ec-4392-ae8f-da93879f8c76}  */
static const MT_UUID IID_MTAPI_MTREMOTECTRL = 
{ 0x317c50cc, 0x30ec, 0x4392, { 0xae, 0x8f, 0xda, 0x93, 0x87, 0x9f, 0x8c, 0x76 } };

/** IID_MTAPI_MTAUDIO = {bd925922-f546-4137-aa39-2ea105487b9c}  */
static const MT_UUID IID_MTAPI_MTAUDIO = 
{ 0xbd925922, 0xf546, 0x4137, { 0xaa, 0x39, 0x2e, 0xa1, 0x05, 0x48, 0x7b, 0x9c } };


/** IID_MTAPI_MTVOD = {2ADADCE5-5508-4BE4-840A-2960C79EA0B5}  */
static const MT_UUID IID_MTAPI_MTVOD = 
{ 0x2adadce5, 0x5508, 0x4be4, { 0x84, 0xa, 0x29, 0x60, 0xc7, 0x9e, 0xa0, 0xb5 } };
 
/** IID_MTAPI_MTMC = {3572FDAF-8F1D-4825-9B50-8718E6F930D8}  */
static const MT_UUID IID_MTAPI_MTMC = 
{ 0x3572fdaf, 0x8f1d, 0x4825, { 0x9b, 0x50, 0x87, 0x18, 0xe6, 0xf9, 0x30, 0xd8 } };


/** IID_MTAPI_MTSNAPSHOT = {692101F9-9D5D-41CA-B342-AE2F14C99C64} */
static const MT_UUID IID_MTAPI_MTSNAPSHOT = 
{ 0x692101f9, 0x9d5d, 0x41ca, { 0xb3, 0x42, 0xae, 0x2f, 0x14, 0xc9, 0x9c, 0x64 } };



/************************************************************************/
/*                  C3. MtVncApi(mtvncapi) CID                          */
/************************************************************************/
/** CID_MTAPI_MTVNCAPI = {689AFDAE-CD88-4DD0-9E62-1F9E6C485B7B}  */
static const MT_UUID CID_MTAPI_MTVNCAPI = 
{ 0x689afdae, 0xcd88, 0x4dd0, { 0x9e, 0x62, 0x1f, 0x9e, 0x6c, 0x48, 0x5b, 0x7b } };

/** CID_MTAPI_MTVNCFSET = {E67FF61A-6349-4DA0-8EBE-EEE463F1E0FA}  */
static const MT_UUID CID_MTAPI_MTVNCFSET = 
{ 0xe67ff61a, 0x6349, 0x4da0, { 0x8e, 0xbe, 0xee, 0xe4, 0x63, 0xf1, 0xe0, 0xfa } };

/** CID_MTAPI_MTVNCCFG = {919FC06C-F6F1-4004-8BC2-479981064536}  */
static const MT_UUID CID_MTAPI_MTVNCCFG = 
{ 0x919fc06c, 0xf6f1, 0x4004, { 0x8b, 0xc2, 0x47, 0x99, 0x81, 0x6, 0x45, 0x36 } };


// CID_MTAPI_MTVNCVIDENCODE = {1B3B3022-B4D4-4033-82A4-DF58810F375B}
static const MT_UUID CID_MTAPI_MTVNCVIDENCODE = 
{ 0x1b3b3022, 0xb4d4, 0x4033, { 0x82, 0xa4, 0xdf, 0x58, 0x81, 0xf, 0x37, 0x5b } };


/************************************************************************/
/*                  I3. MtVncApi(mtvncapi) IID                          */
/************************************************************************/
/** IID_MTAPI_MTVNCCFG = {9FEAAFB6-0817-4FA2-B6F6-B97E071028A2}  */
static const MT_UUID IID_MTAPI_MTVNCCFG = 
{ 0x9feaafb6, 0x817, 0x4fa2, { 0xb6, 0xf6, 0xb9, 0x7e, 0x7, 0x10, 0x28, 0xa2 } };

 
// IID_MTAPI_MTVNCVIDENCODE = {107B4778-50DA-4527-A489-5C252681B438}
static const MT_UUID IID_MTAPI_MTVNCVIDENCODE = 
{ 0x107b4778, 0x50da, 0x4527, { 0xa4, 0x89, 0x5c, 0x25, 0x26, 0x81, 0xb4, 0x38 } };


/************************************************************************/
/*                  C4. MtMgApi(mtmeetingmgrapi) CID                    */
/************************************************************************/
/** CID_MTAPI_MTMGAPI = {56560D5A-C239-4383-BEF0-91C62200A13D}  */
static const MT_UUID CID_MTAPI_MTMGAPI = 
{ 0x56560d5a, 0xc239, 0x4383, { 0xbe, 0xf0, 0x91, 0xc6, 0x22, 0x0, 0xa1, 0x3d } };

/** CID_MTAPI_MTMGFSET = {CE192EFA-4E8F-4452-ABC4-6A07B5A3ECED}  */
static const MT_UUID CID_MTAPI_MTMGFSET = 
{ 0xce192efa, 0x4e8f, 0x4452, { 0xab, 0xc4, 0x6a, 0x7, 0xb5, 0xa3, 0xec, 0xed } };

/** CID_MTAPI_MTMEETINGCTRL = {616DD671-BC5C-48A6-8D94-BD90FBEFF76C}  */
static const MT_UUID CID_MTAPI_MTMEETINGCTRL = 
{ 0x616dd671, 0xbc5c, 0x48a6, { 0x8d, 0x94, 0xbd, 0x90, 0xfb, 0xef, 0xf7, 0x6c } };



/************************************************************************/
/*                  I4. MtMgApi(mtmeetingmgrapi) IID                   */
/************************************************************************/
/** IID_MTAPI_MTMEETINGCTRL = {DF651724-31FA-4B1B-9C20-3C0BFFF7551D}  */
static const MT_UUID IID_MTAPI_MTMEETINGCTRL = 
{ 0xdf651724, 0x31fa, 0x4b1b, { 0x9c, 0x20, 0x3c, 0xb, 0xff, 0xf7, 0x55, 0x1d } };
 
 


/************************************************************************/
/*                  C5. MtImApi(mtimapi) CID                            */
/************************************************************************/
/** CID_MTAPI_MTIMAPI = {e9529d9f-ead0-4373-b3cc-519ea7b6a98f}  */
static const MT_UUID CID_MTAPI_MTIMAPI = 
{ 0xe9529d9f, 0xead0, 0x4373, { 0xb3, 0xcc, 0x51, 0x9e, 0xa7, 0xb6, 0xa9, 0x8f } };

/** CID_MTAPI_MTFSET = {86d427e7-adaf-4c00-a7c3-c87515b8a0f7}  */
static const MT_UUID CID_MTAPI_MTFSET = 
{ 0x86d427e7, 0xadaf, 0x4c00, { 0xa7, 0xc3, 0xc8, 0x75, 0x15, 0xb8, 0xa0, 0xf7 } };

/** CID_MTAPI_MTCHAT = {F190A154-C529-48D2-95DE-BC58DD5A1319}  */
static const MT_UUID CID_MTAPI_MTCHAT = 
{ 0xf190a154, 0xc529, 0x48d2, { 0x95, 0xde, 0xbc, 0x58, 0xdd, 0x5a, 0x13, 0x19 } };

/** CID_MTAPI_MTFILETRANSFER = {31B28DF4-BE03-4C8E-808A-A81C56F635E0}  */
static const MT_UUID CID_MTAPI_MTFILETRANSFER = 
{ 0x31b28df4, 0xbe03, 0x4c8e, { 0x80, 0x8a, 0xa8, 0x1c, 0x56, 0xf6, 0x35, 0xe0 } };



/************************************************************************/
/*                  I5. MtImApi(mtimapi) IID                            */
/************************************************************************/
/** IID_MTAPI_MTCHAT = {23396CD7-D185-4620-B270-07C953863A4D}  */
static const MT_UUID IID_MTAPI_MTCHAT = 
{ 0x23396cd7, 0xd185, 0x4620, { 0xb2, 0x70, 0x7, 0xc9, 0x53, 0x86, 0x3a, 0x4d } };

/** IID_MTAPI_MTFILETRANSFER = {FE0477B4-0AB1-4AA0-80D1-A6AD3A4405E4}  */
static const MT_UUID IID_MTAPI_MTFILETRANSFER = 
{ 0xfe0477b4, 0xab1, 0x4aa0, { 0x80, 0xd1, 0xa6, 0xad, 0x3a, 0x44, 0x5, 0xe4 } };





/************************************************************************/
/*                  C6. MtDcApi(mtdataconfapi) CID                      */
/************************************************************************/
/** CID_MTAPI_MTDCAPI = {979e81f9-e452-4d14-a299-09a668d03382}  */
static const MT_UUID CID_MTAPI_MTDCAPI = 
{ 0x979e81f9, 0xe452, 0x4d14, { 0xa2, 0x99, 0x09, 0xa6, 0x68, 0xd0, 0x33, 0x82 } };

/** CID_MTAPI_MTDCFSET = {472f654a-c9e2-4711-94eb-481715ebb2a4}  */
static const MT_UUID CID_MTAPI_MTDCFSET = 
{ 0x472f654a, 0xc9e2, 0x4711, { 0x94, 0xeb, 0x48, 0x17, 0x15, 0xeb, 0xb2, 0xa4 } };



/************************************************************************/
/*                  I6. MtDcApi(mtdataconfapi) IID                      */
/************************************************************************/




/************************************************************************/
/*                  C7. MtDgApi(mtdataconfapi) CID                      */
/************************************************************************/
/** CID_MTAPI_MTDGAPI = {d10c562b-1eb1-48d2-a6e0-92837be6c287}  */
static const MT_UUID CID_MTAPI_MTDGAPI = 
{ 0xd10c562b, 0x1eb1, 0x48d2, { 0xa6, 0xe0, 0x92, 0x83, 0x7b, 0xe6, 0xc2, 0x87 } };

/** CID_MTAPI_MTDGFSET = {600ce7fe-c7c4-4123-8ea8-3db7bae53c8e}  */
static const MT_UUID CID_MTAPI_MTDGFSET = 
{ 0x600ce7fe, 0xc7c4, 0x4123, { 0x8e, 0xa8, 0x3d, 0xb7, 0xba, 0xe5, 0x3c, 0x8e } };







/************************************************************************/
/*                  I7. MtDiagnoseApi(mtdiagnoseapi) CID                      */
/************************************************************************/
// {1743DD81-8884-4806-9B0C-79D34F935BAA}
static const MT_UUID CID_MTAPI_MTDIAGNOSEAPI = 
{ 0x1743dd81, 0x8884, 0x4806, { 0x9b, 0xc, 0x79, 0xd3, 0x4f, 0x93, 0x5b, 0xaa } };

// {F734F71C-77DC-4D18-8111-21EF72EFA369}
static const MT_UUID CID_MTAPI_MTDIAGNOSEFSET = 
{ 0xf734f71c, 0x77dc, 0x4d18, { 0x81, 0x11, 0x21, 0xef, 0x72, 0xef, 0xa3, 0x69 } };

// {E498554A-653A-405D-B10C-67EE8944B656}
static const MT_UUID CID_MTAPI_MTDIAGNOSE_CALL = 
{ 0xe498554a, 0x653a, 0x405d, { 0xb1, 0xc, 0x67, 0xee, 0x89, 0x44, 0xb6, 0x56 } };

// {21C2C6C0-2DDF-4323-9FE5-637EEA0CE146}
static const MT_UUID CID_MTAPI_MTDIAGNOSE_DEVICE = 
{ 0x21c2c6c0, 0x2ddf, 0x4323, { 0x9f, 0xe5, 0x63, 0x7e, 0xea, 0xc, 0xe1, 0x46 } };

// {FC28A6DC-AAC7-4F62-B0A1-8940E6B29267}
static const MT_UUID CID_MTAPI_MTDIAGNOSE_TERMINAL = 
{ 0xfc28a6dc, 0xaac7, 0x4f62, { 0xb0, 0xa1, 0x89, 0x40, 0xe6, 0xb2, 0x92, 0x67 } };

// {AA4EEFB2-0BF9-4380-B356-8AC12C8EE569}
static const MT_UUID CID_MTAPI_MTDIAGNOSE_SERVER = 
{ 0xaa4eefb2, 0xbf9, 0x4380, { 0xb3, 0x56, 0x8a, 0xc1, 0x2c, 0x8e, 0xe5, 0x69 } };


/************************************************************************/
/*                  I7. MtDiagnoseApi(mtdiagnoseapi) IID                      */
/************************************************************************/
// {4EF14FB1-D791-41DB-A486-FC7BABEF9E4E}
static const MT_UUID IID_MTAPI_MTDIAGNOSE_CALL = 
{ 0x4ef14fb1, 0xd791, 0x41db, { 0xa4, 0x86, 0xfc, 0x7b, 0xab, 0xef, 0x9e, 0x4e } };

// {770DA0A5-0D9C-4093-AC5C-12AC6B37E2A1}
static const MT_UUID IID_MTAPI_MTDIAGNOSE_DEVICE = 
{ 0x770da0a5, 0xd9c, 0x4093, { 0xac, 0x5c, 0x12, 0xac, 0x6b, 0x37, 0xe2, 0xa1 } };

// {3D9E00FD-82A4-4B7B-BBE7-EB466489E6E1}
static const MT_UUID IID_MTAPI_MTDIAGNOSE_TERMINAL = 
{ 0x3d9e00fd, 0x82a4, 0x4b7b, { 0xbb, 0xe7, 0xeb, 0x46, 0x64, 0x89, 0xe6, 0xe1 } };

// {7F33777F-FB06-4839-AC9B-3AFFDB7ECD91}
static const MT_UUID IID_MTAPI_MTDIAGNOSE_SERVER = 
{ 0x7f33777f, 0xfb06, 0x4839, { 0xac, 0x9b, 0x3a, 0xff, 0xdb, 0x7e, 0xcd, 0x91 } };


/************************************************************************/
/*                  C8. MtCaApi(mtcontactmgrapi) CID                     */
/************************************************************************/
/** CID_MTAPI_MTCMAPI = {4fa0cb63-e570-4703-9d8a-c68f8f80885f}  */
static const MT_UUID CID_MTAPI_MTCMAPI = 
{ 0x4fa0cb63, 0xe570, 0x4703, { 0x9d, 0x8a, 0xc6, 0x8f, 0x8f, 0x80, 0x88, 0x5f } };

/** CID_MTAPI_MTCMFSET = {3e7a6e42-4681-498e-9099-b1b766718bd9}  */
static const MT_UUID CID_MTAPI_MTCMFSET = 
{ 0x3e7a6e42, 0x4681, 0x498e, { 0x90, 0x99, 0xb1, 0xb7, 0x66, 0x71, 0x8b, 0xd9 } };

/** CID_MTAPI_MTLOCALCONTACT = {9FF6D778-4EB4-44CC-BCE9-C6668A0C79D6}  */
static const MT_UUID CID_MTAPI_MTLOCALCONTACT = 
{ 0x9ff6d778, 0x4eb4, 0x44cc, { 0xbc, 0xe9, 0xc6, 0x66, 0x8a, 0xc, 0x79, 0xd6 } };

//**CID_MTAPI_MTCALLRECORD = {2978880B-F703-41BB-B7DC-00A92B1C4172}
static const MT_UUID CID_MTAPI_MTCALLRECORD = 
{ 0x2978880b, 0xf703, 0x41bb, { 0xb7, 0xdc, 0x0, 0xa9, 0x2b, 0x1c, 0x41, 0x72 } };

// {0F6D92EE-BAC8-4285-B9A8-5B6746399733}
static const MT_UUID CID_MTAPI_MTORGANIZATION = 
{ 0xf6d92ee, 0xbac8, 0x4285, { 0xb9, 0xa8, 0x5b, 0x67, 0x46, 0x39, 0x97, 0x33 } };

// {CC634BB6-D757-4876-AD0F-3CB8FAC272A8}
static const MT_UUID CID_MTAPI_MTORGANIZITION = 
{ 0xcc634bb6, 0xd757, 0x4876, { 0xad, 0xf, 0x3c, 0xb8, 0xfa, 0xc2, 0x72, 0xa8 } };

// {888635E6-1949-42B5-8EC3-41DCEE8E96E5}
static const MT_UUID CID_MTAPI_MTOTHERCONTACT = 
{ 0x888635e6, 0x1949, 0x42b5, { 0x8e, 0xc3, 0x41, 0xdc, 0xee, 0x8e, 0x96, 0xe5 } };


/************************************************************************/
/*                  I8. MtCaApi(mtcontactmgrapi) IID                     */
/************************************************************************/
/** IID_MTAPI_MTLOCALCONTACT = {13CAAB30-B600-44D9-91C4-B4719CA253EA}  */
static const MT_UUID IID_MTAPI_MTLOCALCONTACT = 
{ 0x13caab30, 0xb600, 0x44d9, { 0x91, 0xc4, 0xb4, 0x71, 0x9c, 0xa2, 0x53, 0xea } };

//**IID_MTAPI_MTCALLRECORD = {0E1AFB34-C172-4EC3-96E9-E49F4A222500}
static const MT_UUID IID_MTAPI_MTCALLRECORD = 
{ 0xe1afb34, 0xc172, 0x4ec3, { 0x96, 0xe9, 0xe4, 0x9f, 0x4a, 0x22, 0x25, 0x0 } };

// {1B4777AD-62FE-46C4-AC34-24978E083953}
static const MT_UUID IID_MTAPI_MTORGANIZATION = 
{ 0x1b4777ad, 0x62fe, 0x46c4, { 0xac, 0x34, 0x24, 0x97, 0x8e, 0x8, 0x39, 0x53 } };

// {9D483A2A-3CA5-42AB-A248-0F954BC1E29C}
static const MT_UUID IID_MTAPI_MTOTHERCONTACT = 
{ 0x9d483a2a, 0x3ca5, 0x42ab, { 0xa2, 0x48, 0xf, 0x95, 0x4b, 0xc1, 0xe2, 0x9c } };


/************************************************************************/
/*                  C9. MtMgApi(mtdcsapi) CID                    */
/************************************************************************/
// {6DF3A26F-4CFF-46F2-8E14-78A3991B7918}
static const MT_UUID CID_MTAPI_MTDCSAPI = 
{ 0x6df3a26f, 0x4cff, 0x46f2, { 0x8e, 0x14, 0x78, 0xa3, 0x99, 0x1b, 0x79, 0x18 } };

// {7051723F-B9F0-4BFD-B013-08B2665CA986}
static const MT_UUID CID_MTAPI_MTDCSFSET = 
{ 0x7051723f, 0xb9f0, 0x4bfd, { 0xb0, 0x13, 0x8, 0xb2, 0x66, 0x5c, 0xa9, 0x86 } };

// {1CDA1D09-1B06-4F6E-9FB4-A124B2465073}
static const MT_UUID CID_MTAPI_MTDCSCTRL = 
{ 0x1cda1d09, 0x1b06, 0x4f6e, { 0x9f, 0xb4, 0xa1, 0x24, 0xb2, 0x46, 0x50, 0x73 } };


/************************************************************************/
/*                  I9. MtMgApi(mtdcsapi) IID                   */
/************************************************************************/
// {A055CF50-0250-4FE7-8AAB-5AFEB72C910E}
static const MT_UUID IID_MTAPI_MTDCSCTRL = 
{ 0xa055cf50, 0x250, 0x4fe7, { 0x8a, 0xab, 0x5a, 0xfe, 0xb7, 0x2c, 0x91, 0xe } };



#endif //_MTAPI_UUID_H_