/*
 * Kedacom Hardware Abstract Level
 *
 * brd_oled.h
 *
 * Copyright (C) 2013-2020, Kedacom, Inc.
 *
 * History:
 *   2015/03/10 - [hewenwen] Create
 *
 */

#ifndef _BRD_OLED_H
#define _BRD_OLED_H



__BEGIN_DECLS
#include <drvlib_def.h>


/* oled device */
#define OLED_DEV_ONE				(0)
#define OLED_DEV_TWO				(1)
#define OLED_DEV_THREE				(2)
#define OLED_DEV_FOUR				(2)
/* position for charactors shows */
#define OLED_ROW_ONE				(1<<0)
#define OLED_ROW_TWO				(1<<1)
#define OLED_ROW_THREE				(1<<2)
#define OLED_ROW_MID_ONE_TWO		(1<<8)
#define OLED_ROW_MID_TWO_THREE		(1<<9)
#define OLED_COLUMN_CENTER			(1<<16)	/* default left, you can choose center by this flag */
/* oled capacity */
#define OLED_CAP_CHAR				(1<<0)  /* this oled can show charactors */
#define OLED_CAP_GRAPH			    (1<<1)  /* this oled can show pictures */
#define OLED_CAP_BOTH				(1<<2)  /* this oled can show charactors and pictures */

#define OLED_STATE_OFF				0
#define OLED_STATE_ON				1


typedef struct
{
	u32   No;               /* Input: 0 ~ oled_registed_num-1 */
	u32   Cab;		      	/* See : OLED_CAP_CHARACTOR */

	struct Char_info{
		u32 MaxRowNum;		/* oled can show max row num ,See */
		u32 MaxColumnChar;  /* oled can show max char num per line */
	}Chars;
	struct Graph_info{
		u32 GraphType;		/* oled can show high*weight type graph, from database */
	}Graph;

	char achName[DRVLIB_NAME_MAX_LEN]; /* device name, for user open */

}TOledInfo;

/**
 * BrdOledQueryInfo
 *
 * query oled info
 *
 * @param TOledInfo 
 * @return 0/code num
 */
int BrdOledQueryInfo(TOledInfo *info);

/**
 * BrdOledSetStatus
 *
 * set Oled status
 *
 * @param 
 *   	id : oled num
 *	    status : 0 / close 1 open
 * @return 0/code num
 */
int BrdOledSetStatus(u32 id, u32 status);

/**
 * BrdOledShowChars
 *
 * show string on Oled 
 *
 * @param 
 *   	id  : oled num
 *		pos : position
 *		string : string to show
 * @return 0/code num
 */
int BrdOledShowChars(u32 id, u32 pos,char *string);


__END_DECLS


#endif
