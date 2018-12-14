/******************************************************************************
 * 模块名      : kprop
 * 文件名      : kprop.h
 * 相关文件    : 
 * 文件实现功能: 属性字典及配置文件操作定义。
 * 作者        : 谢志钢
 * 版本        : v1.0  Copyright(C) 2014-2015 KDC, All rights reserved.
 * ----------------------------------------------------------------------------
 * 修改记录:
 * 日期        版本  修改人  修改内容
 * 2015-01-05  1.0   谢志钢  创建
 ******************************************************************************/
#ifndef KPROP_H
#define KPROP_H

#include <stddef.h>

#include "kfile.h"

// {{{ 前置定义项
#include "kdvtype.h"

#ifndef KEXTERN
#  ifdef KPROP_DLL
#    ifdef KPROP_INTERNAL
#      define KEXTERN extern __declspec(dllexport)
#    else /* ! KPROP_INTERNAL */
#      define KEXTERN extern __declspec(dllimport)
#    endif /* KPROP_INTERNAL */
#  else /* ! KPROP_DLL */
#    define KEXTERN extern
#  endif /* KPROP_DLL */
#endif /* KEXTERN */

#ifndef HAVE_ERROR_TYPE
typedef s32 error_t;
#define HAVE_ERROR_TYPE
#endif // HAVE_ERROR_TYPE

#ifndef NO_ERROR
#define NO_ERROR  (error_t)0
#endif // NO_ERROR
// }}}

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief object to hold groupped properties.
 */
typedef struct tag_kprops TKProps;

/*!
 * \brief Initialize an object of kprops.
 *
 * \param pptProps   - object pointer returned after creation.
 *                     Before pass int in, be sure it holds NULL.
 * \param nSensitive - whether the group and key is case-sensitive or not.
 *
 * \return 0 if successful, otherwise non-zero.
 */
KEXTERN
error_t KPropsInit (TKProps **pptProps, s32 nSensitive);

/*!
 * \brief Destroyes an object of kprops.
 *        If pass NULL, or pointer of NULL, also ok.
 *        After an object is destroyed, the pointer will set NULL.
 */
KEXTERN
void KPropsDestroy (TKProps **pptProps);

/*!
 * \brief Loads properties from an ini-formated text file.
 *        One valid text file example:
 *
 *           # comments goes here.
 *           [group_name]
 *           key1 = value1 # from here it is commedted off.
 *           key2 = value2
 *
 *           ; a semi-colum also indicates a comment line.
 *           [group2]
 *           key_x = value_x
 * 
 * \note  The difference between load_file() and load_path() is that 
 *        the file object can hold the exclusive file lock after load
 *        properties.
 *
 * \param ptProps     - an properties object.
 * \param pszFilename - where (file path) to load properties from.
 *
 * \return 0 if successful, otherwise non-zero.
 */
KEXTERN
error_t KPropsLoadPath (TKProps *ptProps, const s8* pszFilename);

/*!
 * \brief Loads properties from an ini-formated text file.
 *        One valid text file example:
 *
 *           # comments goes here.
 *           [group_name]
 *           key1 = value1 # from here it is commedted off.
 *           key2 = value2
 *
 *           ; a semi-colum also indicates a comment line.
 *           [group2]
 *           key_x = value_x
 * 
 * \note  The difference between load_file() and load_path() is that 
 *        the kfile object holds the exclusive file lock after load
 *        properties.
 *
 * \param ptProps    - an properties object.
 * \param ptFile     - where (an kfile object) to load properties from.
 *
 * \return 0 if successful, otherwise non-zero.
 */
KEXTERN
error_t KPropsLoadFile (TKProps *ptProps, TKFile *ptFile);

/*!
 * \brief Saves properties into an ini-formated text file.
 * 
 * \note  difference between save_file() and save_path() is that 
 *        the kfile object holds the exclusive file lock.
 *
 * \param ptProps     - an properties object.
 * \param pszFilename - where (file path) to save properties to.
 *
 * \return 0 if successful, otherwise non-zero.
 */
KEXTERN
error_t KPropsSavePath (TKProps *ptProps, const s8* pszFilename);

/*!
 * \brief Saves properties into an ini-formated text file.
 * 
 * \note  difference between save_file() and save_path() is that 
 *        the kfile object holds the exclusive file lock.
 *
 * \param ptProps    - an properties object.
 * \param ptFile     - where (an kfile object) to save properties into.
 *
 * \return 0 if successful, otherwise non-zero.
 */
KEXTERN
error_t KPropsSaveFile (TKProps *ptProps, TKFile *ptFile);

/*!
 * \brief Gets integer value that associated with a key under a group.
 *
 * \param [in] ptProps     - properties instance.
 * \param [in] pszGroup    - section or group name.
 * \param [in] pszKey      - key name of the value.
 * \param [in] nDefValue   - default value if failed.
 * \param [out] pnValue    - the value retrieved.
 *
 * \return 0 if successful,
 *         1 if pszGroup not found,
 *         2 if key not found,
 *         other non-zero if error occurs.
 */
KEXTERN
error_t KPropsGetInt (TKProps *ptProps, const s8* pszGroup, const s8* pszKey,
        s32 nDefValue, s32 *pnValue);

/*!
 * \brief  Gets text that associated with a key under a group.
 *
 * \param [in] ptProps     - properties instance.
 * \param [in] pszGroup    - section or group name.
 * \param [in] pszKey      - key name of the value.
 * \param [in] pszDefValue - default value if failed.
 * \param [out] pBuf       - the value retrieved.
 * \param [in]  dwBufSize  - the size to accept the string.
 *
 * \return 0 if successful,
 *         1 if group not found,
 *         2 if key not found,
 *         other non-zero if error occurs.
 *
 * How to obtain the size of a key value?
 * Or, how to check existance of a key or a group?
 *   Provide NULL for both pBuff and pszDefValue, and check return value.
 * - If the key is found, the return value is negative, and negate it you
 *   will get the bytes of value in positive (including terminal nill).
 * - If the group is not found, it returns 1.
 * - If the key is not found, but the group is found, it returns 2.
 * - Other errors, it returns a positive FAR LARGER THAN 2.
 */
KEXTERN
error_t KPropsGetString(TKProps *ptProps,
        const s8* pszGroup, const s8* pszKey,
        const s8* pszDefValue, s8 *pBuf, u32 dwBufSize);

/*!
 * \brief  Sets integer (int32_t) that associated with a key under a group
 *
 * \param [in] ptProps   - properties instance.
 * \param [in] pszGroup  - section or group name.
 * \param [in] pszKey    - key name of the value.
 * \param [in] nValue    - integer value to set.
 *
 * \return 0 if successful, otherwise non-zero for error.
 */
KEXTERN
error_t KPropsSetInt(TKProps *ptProps,
        const s8*  pszGroup, const s8*  pszKey, s32 nValue);

/*!
 * \brief  Sets text that associated with a key under a group.
 *
 * \param [in] ptProps   - properties instance.
 * \param [in] pszGroup  - section or group name.
 * \param [in] pszKey    - key name of the value.
 * \param [in] pszValue  - text with nil terminated.
 *
 * \return 0 if successful, otherwise non-zero for error.
 */
KEXTERN
error_t KPropsSetString(TKProps *ptProps,
        const s8* pszGroup, const s8* pszKey, const s8* pszValue);

/*!
 * \brief  Removes a key from properties.
 *
 * \param [in] ptProps  - properties instance.
 * \param [in] pszGroup - section or group name.
 * \param [in] pszKey   - key name of the value.
 *
 * \return 0 if successful, otherwise non-zero for error.
 */
KEXTERN
error_t KPropsRemoveKey(TKProps *ptProps, const s8*  pszGroup, const s8*  pszKey);

/*!
 * \brief  Removes a group from properties.
 *
 * \param  [in] ptProps  - properties instance.
 * \param  [in] pszGroup - section or group name.
 *
 * \return 0 if successful, otherwise non-zero for error.
 */
KEXTERN
error_t KPropsRemoveGroup(TKProps *ptProps, const s8*  pszGroup);

/*!
 * \brief  Get count or number of groups.
 *
 * \param  [in] ptProps  - properties instance.
 * \param [out] pnCount  - the number of groups retrieved.
 *
 * \return 0 if successful, otherwise non-zero for error.
 */
KEXTERN
error_t KPropsGetGroupCount(TKProps *ptProps, s32* pnCount);

/*!
 * \brief  Get name of a group by index.
 *
 * \param  [in] ptProps   - properties instance.
 * \param  [in] nIndex    - index of group.
 * \param [out] pBuf      - the name of group retrieved.
 * \param  [in] dwBufSize - the size to accept the string.
 *
 * \return 0 if successful,
 *         1 if group not found,
 *         other non-zero if error occurs.
 *
 * How to obtain the size of a group name?
 *   Provide NULL for pBuff, and check return value.
 * - If the group is found, the return value is negative, and negate it you
 *   will get the bytes of name in positive (including terminal nill).
 * - If the group is not found, it returns 1.
 * - Other errors, it returns a positive FAR LARGER THAN 1.
 */
KEXTERN
error_t KPropsGetGroupName(TKProps *ptProps, s32 nIndex,
        s8* pBuf, u32 dwBufSize);

/*!
 * \brief  Get count or number of keys of a group.
 *
 * \param  [in] ptProps  - properties instance.
 * \param  [in] pszGroup - name of group to get the keys count.
 * \param [out] pnCount  - the number of keys retrieved.
 *
 * \return 0 if successful, otherwise non-zero for error.
 */
KEXTERN
error_t KPropsGetKeyCount(TKProps *ptProps, const s8* pszGroup,
        s32* pnCount);

/*!
 * \brief  Get name of a key by index in a group.
 *
 * \param  [in] ptProps   - properties instance.
 * \param  [in] pszGroup  - name of group for the key to be indexed.
 * \param  [in] nIndex    - index of key in this group.
 * \param [out] pBuf      - the name of key retrieved.
 * \param  [in] dwBufSize - the size to accept the string.
 *
 * \return 0 if successful,
 *         1 if group not found,
 *         2 if key not found,
 *         other non-zero if error occurs.
 *
 * How to obtain the size of a key name?
 *   Provide NULL for pBuff, and check return value.
 * - If the key is found, the return value is negative, and negate it you
 *   will get the bytes of name in positive (including terminal nill).
 * - If the group is not found, it returns 1.
 * - If the key is not found, but the group is found, it returns 2.
 * - Other errors, it returns a positive FAR LARGER THAN 2.
 */
KEXTERN
error_t KPropsGetKeyName(TKProps *ptProps, const s8* pszGroup, s32 nIndex,
        s8* pBuf, u32 dwBufSize);

/*!
 * \brief  Get comment of a group.
 *
 * \param  [in] ptProps   - properties instance.
 * \param  [in] pszGroup  - name of group for the comment to fetch.
 * \param [out] pBuf      - the comment of group fetched.
 * \param  [in] dwBufSize - the size to accept the string.
 *
 * \return 0 if successful,
 *         1 if group not found,
 *         other non-zero if error occurs.
 *
 * How to obtain the size of a group comment?
 *   Provide NULL for pBuff, and check return value.
 * - If the group is found, the return value is negative, and negate it you
 *   will get the bytes of comment in positive (including terminal nill).
 * - If the group is not found, it returns 1.
 * - Other errors, it returns a positive FAR LARGER THAN 1.
 */
KEXTERN
error_t KPropsGetGroupComment(TKProps *ptProps, const s8* pszGroup,
        s8* pBuf, u32 dwBufSize);

/*!
 * \brief  Append a comment for a group.
 *
 * \param  [in] ptProps   - properties instance.
 * \param  [in] pszGroup  - name of group for the comment to append.
 * \param  [in] pszComment- the comment to be appended.
 *
 * \return 0 if successful, otherwise non-zero for error.
 */
KEXTERN
error_t KPropsAddGroupComment(TKProps *ptProps, const s8* pszGroup,
        const s8* pszComment);

/*!
 * \brief  Clear all comments of a group.
 *
 * \param  [in] ptProps   - properties instance.
 * \param  [in] pszGroup  - name of group to clear comments.
 */
KEXTERN
void KPropsClearGroupComment(TKProps *ptProps, const s8* pszGroup);

/*!
 * \brief  Get comment of a key.
 *
 * \param  [in] ptProps   - properties instance.
 * \param  [in] pszGroup  - section or group name.
 * \param  [in] pszKey    - key name of the value.
 * \param [out] pBuf      - buffer to store the comment.
 * \param  [in] dwBufSize - the size to accept the string.
 *
 * How to obtain the size of a key comment?
 *   Provide NULL for pBuff, and check return value.
 * - If the key is found, the return value is negative, and negate it you
 *   will get the bytes of name in positive (including terminal nill).
 * - If the group is not found, it returns 1.
 * - If the key is not found, but the group is found, it returns 2.
 * - Other errors, it returns a positive FAR LARGER THAN 2.
 */
KEXTERN
error_t KPropsGetKeyComment(TKProps *ptProps, const s8* pszGroup,
        const s8* pszKey, s8* pBuf, u32 dwBufSize);

/*!
 * \brief  Clear all comments of a key.
 *
 * \param  [in] ptProps   - properties instance.
 * \param  [in] pszGroup  - section or group name.
 * \param  [in] pszKey    - key name of the value.
 */
KEXTERN
void KPropsClearKeyComment(TKProps *ptProps, const s8* pszGroup,
        const s8* pszKey);

/*!
 * \brief  Append a comment for a key.
 *
 * \param  [in] ptProps   - properties instance.
 * \param  [in] pszGroup  - section or group name.
 * \param  [in] pszKey    - key name of the value.
 * \param  [in] pszComment- the comment to be appended.
 *
 * \return 0 if successful, otherwise non-zero for error.
 */
KEXTERN
error_t KPropsAddKeyComment(TKProps *ptProps, const s8* pszGroup,
        const s8* pszKey, const s8* pszComment);
#ifdef __cplusplus
}
#endif

#endif // KPROP_H
/* vim:set foldmethod=marker: */
