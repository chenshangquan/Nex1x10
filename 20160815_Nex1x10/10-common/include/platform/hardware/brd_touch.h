/*
 * Kedacom Hardware Abstract Level
 *
 * brd_misc.h
 *
 * Copyright (C) 2015, Kedacom, Inc.
 *
 * History:
 *   2017/04/28 - Create
 *
 */

#ifndef _BRD_MOUSE_H
#define _BRD_MOUSE_H

__BEGIN_DECLS
#include <drvlib_def.h>
/*
 * FXO Defines
 */

struct mouse_t{
	int x;
	int y;
	char button_state ;
};
/*
 * \brief :
 *      open socket fd ,befor BrdSendMouse must open socket fd
 * \param :
 *      null
 * \return :
 *      num > 0 -- socket fd
 *	 num < 0 -- error
 */
int BrdOpenTouch();
/*
 * \brief :
 *      send mouse state x y .
 * \param :
 *      @sockFd       : socket fd
 *      @buttonState : 0: button up ; 1: button down
 *      @x       :
 *      @y       :
 * \return :
 *      0 -- success
 *      -1 -- send fail
 */
int BrdSendMouse(int sockfd,char button_state,int x,int y);

/*
 * \brief :
 *      send prohibited area
 * \param :
 *      @sockFd       : socket fd
 *      @areaNum : 1~4 :support 1~4 areas
 *      @xStart	:
 *      @yStart	:
 *      @xEnd	:
 *      @yEnd	:
 * \return :
 *        0	: success
 *      -1 	: send fail
 */
int BrdSendProhibitedArea(int sockFd,int areaNum,int xStart,int yStart,int xEnd,int yEnd);

/*
 * \brief :
 *      send exit cmd to hid
 * \param :
 *      @sockFd       : socket fd
 * \return :
 *      0 -- success
 *      -1 -- send fail
 */
int BrdExitTouch(int sockFd);

/*
 * \brief :
 *      close/open mouse
 * \param :
 *      @mouse_switch       : 0:close   1:open
 * \return :
 *        0	: success
 *      -1 	: send fail
 */
int BrdMouseSwitch(int mouse_switch);
__END_DECLS

#endif
