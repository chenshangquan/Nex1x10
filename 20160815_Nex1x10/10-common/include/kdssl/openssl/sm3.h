/*=================================================================================
  模块名    ：SM3 实现
  文件名    ：sm3.h
  相关文件  ：无
  实现功能  ：sm3 声明
  作者      ：王彦杰
  版权：<Copyright(c) 2016-2016 Suzhou Keda Technology Co.,Ltd.All rights reserved.>
  --------------------------------------------------------------------------------
  修改记录 :    日 期        版 本      修改人  走读人      修改记录
                2016/11/04   V1.0       王彦杰              新建
==================================================================================*/

#ifndef HEADER_SM3_H
# define HEADER_SM3_H

#define SM3_DIGEST_LENGTH       32
#define SM3_BLOCK_SIZE          64

#include <sys/types.h>
#include <stdint.h>
#include <string.h>

# ifdef __cplusplus
extern "C" {
# endif


typedef struct sm3_ctx_st {
    uint32_t digest[8];                  /** V(i) 中间计算结果 */
    int nblocks;                         /** 处理的块数, 最大处理数据约128G (2^^31 * 64) */
    unsigned char block[64];             /** 被处理块 */
    int num;                             /** 末段数据长度  n % 64 */
} sm3_ctx_t;

void sm3_init(sm3_ctx_t *ctx);
void sm3_update(sm3_ctx_t *ctx, const unsigned char* data, size_t data_len);
void sm3_final(sm3_ctx_t *ctx, unsigned char digest[SM3_DIGEST_LENGTH]);
void sm3(const unsigned char *data, size_t datalen, unsigned char digest[SM3_DIGEST_LENGTH]);


# ifdef __cplusplus
}
# endif
#endif /** HEADER_SM3_H */

