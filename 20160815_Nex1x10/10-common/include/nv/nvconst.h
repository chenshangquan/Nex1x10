#ifndef _NVCONST_H_
#define _NVCONST_H_

#include "kdvtype.h"
#include "kdvdef.h"

//app id 定义
//划分给产品模块使用的范围
#define AID_PRODUCT_BGN     (u32)50
#define AID_PRODUCT_END     (u32)100

//组件模块app id定义
#define AID_NVSYSCTRL			(u32)(AID_NV_BGN + 1)     //系统控制
#define AID_NVMP				(u32)(AID_NV_BGN + 2)     //nvmp模块
#define AID_NVDISPATCH			(u32)(AID_NV_BGN + 3)     //消息调度模块
#define AID_NVACCESS			(u32)(AID_NV_BGN + 4)     //终端客户端接入模块
#define AID_NVAPI				(u32)(AID_NV_BGN + 5)     //NVAPI
#define AID_UPGRADE				(u32)(AID_NV_BGN + 6)    //升级子系统
#define AID_NVSERVICE			(u32)(AID_NV_BGN + 7)	  //nvservice模块
#define AID_CFGSRV				(u32)(AID_NV_BGN + 8)    //配置服务
#define AID_NV_PINGTEST			(u32)(AID_NV_BGN + 9)    //ping测试网络
#define AID_NV_TERINTERFACE	    (u32)(AID_NV_BGN + 10)    //X500终端接入模块
#define AID_NV_UPGRADESERVER	(u32)(AID_NV_BGN + 11)    //升级服务器
#define AID_NV_UPGRADAPI	    (u32)(AID_NV_BGN + 12)    //升级服务器api
#define AID_NV_QUICKSHARE	    (u32)(AID_NV_BGN + 13)    //无线共享设备
#define AID_NV_AUTOTESTCLIENT	(u32)(AID_NV_BGN + 14)    //终端硬件自动化终端应用ID 
#define AID_NV_AUTOTEST	        (u32)(AID_NV_BGN + 15)    //生产测试工具ID
#define AID_NV_QUICKSHAREAPI	(u32)(AID_NV_BGN + 16)    //无线投屏器api
#define AID_NVSUC               (u32)(AID_NV_BGN + 17)	  //升级服务器模块


// 子系统最大数量
#define NV_SYS_NUM_MAX		(u32)40

// 字符串长度
#define NV_STR_LEN_4		(u32)4
#define NV_STR_LEN_8		(u32)8
#define NV_STR_LEN_16		(u32)16
#define NV_STR_LEN_32		(u32)32
#define NV_STR_LEN_64		(u32)64
#define NV_STR_LEN_128		(u32)128
#define NV_STR_LEN_256		(u32)256
#define NV_STR_LEN_512		(u32)512
#define NV_STR_LEN_1024		(u32)1024
#define NV_STR_LEN_2048		(u32)2048
#define NV_STR_LEN_4096		(u32)4096
#define NV_STR_LEN_8192		(u32)8192
#define NV_STR_LEN_URI		    (u32)(128*1024)

#define NV_SIP_LEN_XML      (u32)10240

#define NV_MAX_NUM_5		(u32)5
#define NV_MAX_NUM_10		(u32)10
#define NV_MAX_NUM_15		(u32)15
#define NV_MAX_NUM_20		(u32)20
#define NV_MAX_NUM_25		(u32)25
#define NV_MAX_NUM_30		(u32)30
#define NV_MAX_NUM_40		(u32)40
#define NV_MAX_NUM_50		(u32)50
#define NV_MAX_NUM_100		(u32)100

#define NV_E164_LEN			(u32)13

#define NV_LEN_4K          (u32)(1 << 12)
#define NV_LEN_8K          (u32)(1 << 13)
#define NV_LEN_16K          (u32)(1 << 14)
#define NV_LEN_24K          (u32)(24 * 1024)
#define NV_LEN_32K          (u32)(1 << 15)

#ifndef NV_MAX_PATH
#define NV_MAX_PATH			(u16)256  /* 定义最大路径长度 */
#define IPNAME_CHAR_LEN      20
#endif

//无效值定义
#define INVALID_U8   (u8)(~0)
#define INVALID_U16  (u16)(~0)
#define INVALID_U32  (u32)(~0)
#define INVALID_S8   (s8)(~0)
#define INVALID_S16  (s16)(~0)
#define INVALID_S32  (s32)(~0)

//表示u32数字转换字符串最多占十个字节
#define NV_U32_MAX_LEN 10

//终端核心进程监听端口
#define NV_KERNEL_LISTEN_PORT (u16)60003

//终端内部RPC服务器监听端口
#define RPC_SERVER_PORT       (u16)8000

//升级服务器监听端口
#define NV_UPGRADESERVICE_LISTEN_PORT (u16)60005

#define NVPA_NAME "nvpa" //填在nvmsg的userdata字段，表示这个消息由nvpa模块处理，具体格式

//<数据共享服务器监听端口
#define DSS_PORT              (u16)12581

//g7221码率定义
#define   NV_G7221_RATE_24           (u8)0x01
#define   NV_G7221_RATE_32           (u8)0x02
#define   NV_G7221_RATE_48           (u8)0x04
#define   NV_G7221_RATE_NONE         (u8)0x00

#define   NV_AAC_RATE                96      //lc/ld码率

const u16 MAX_PORT_VALUE = (u16)0xFFFF;

#define  NV_IMIX_IFR_NAME					"eth0"
#define  NV_IMIX_PRODUCT_ID					"I-MIXTPS"
#define  NV_X500_PRODUCT_ID					"X500TPS"
#define  NV_PC_PRODUCT_ID					"PCTPS"
#define  NV_TOUCHMEETING_PAD_PRODUCT_ID		"TOUCHMEETINGPADTPS"
#define  NV_QK_PRODUCT_ID                   "QKTPS"
#define  NV_TARGET_DEVICE_NUM                10 //目标设备最大数目
#define  NV_WVS_DEVICE_NUM                   8  //无线投屏最大数目

#define DEV_CFG_MAX_CFG 4    //可以配置的升级设备数目
#define NV_MAX_FILESRV_FILENAME_LEN  32       //最大的文件名长度
#define NV_MAX_VERSION_INFO_LEN  1024       //最大的更新内容长度


#define MAX_DEVICEVER_LEN            38
#define MAX_DEVICE_NUM               20

#define RS_TV_TIMEOUT 100
#define MAX_TVVSSIG_LEN 6
#define MAX_POWERVSSIG_LEN 5
#define MAX_TVINPUT_LEN 6

#define VER_NVDF "nvdf-1.1.20161026" //设备发现版本号

#define IMIX_TEL_USRNAME  "admin"
#define IMIX_TEL_PWD      "KedaKdv123"

#define TER_PWD  "Pwd_Change"//终端密码

#define FREEZE_NO                             0 //解冻
#define FREEZE_RIMIX_RSCALER                  144 //冻结imix读，scaler读
#define FREEZE_RIMIX_RSCALER_WOPS             146 //冻结imix读，scaler读，ops写
#define FREEZE_RIMIX_RSCALER_ROPS             176 //冻结imix读，scaler读，ops读
#define FREEZE_RIMIX_RSCALER_WTER             148 //冻结imix读，scaler读，终端写
#define FREEZE_RIMIX_RSCALER_RTER             208 //冻结imix读，scaler读，终端读
#define FREEZE_WALL                           240 //冻结所有读
#define FREEZE_WRIMIX_RSCALER_WTER            149 //冻结imix读写，scaler读，终端写  
#endif