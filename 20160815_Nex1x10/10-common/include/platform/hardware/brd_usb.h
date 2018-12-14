/*
 * Kedacom Hardware Abstract Level
 *
 * brd_usb.h
 *
 * Copyright (C) 2013-2020, Kedacom, Inc.
 *
 * History:
 *   2017/03/20 - [quxuetong] Create
 *
 */

#ifndef _BRD_USB_H
#define _BRD_USB_H

#include <drvlib_def.h>

#ifdef __cplusplus
extern "C" {
#endif

/*usb device id*/
#define USB_MAX_NUM		8
#define USB_DEV_ONE		0
#define USB_DEV_TWO		1
#define USB_DEV_THREE	2
#define USB_DEV_FOUR	3
#define USB_DEV_FIVE	4
#define USB_DEV_SIX		5
#define USB_DEV_SEVEN   6
#define USB_DEV_EIGHT   7
#define USB_MAX_PART	8
#define USB_MAX_SEARCH	32
/* usb status */
#define USB_NO_RW		"rwprotect"

/**
 * BrdUsbCheck
 *
 * check usb status
 *
 * @param 
 *		id    : pass usb id  0/1/2
 *		path : current usb path save here, maybe usb device has more than 1 partition
 * @return 0/-1
 */
int BrdUsbCheck(char id , char (*path)[32]);
/**
 * BrdUsbTest
 *
 * test usb func
 *
 * @param : dev_path 
 		eg /dev/sda1 /dev/sda2 ...
 * @return 0/-1
 */
int BrdUsbTest(char *dev_path);
/*
* BrdUsbSel
*
* select which usb is run
*
* @param
*             sel 0: terninal  1:ops
* @return 0/-1
*/
int BrdUsbSel(int sel);

#ifdef __cplusplus
}
#endif

#endif
