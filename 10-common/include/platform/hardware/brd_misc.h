/*
* Kedacom Hardware Abstract Level
*
* brd_misc.h
*
* Copyright (C) 2015, Kedacom, Inc.
*
* History:
*   2015/05/05 - Create
*
*/

#ifndef _BRD_MISC_H
#define _BRD_MISC_H

__BEGIN_DECLS
#include <drvlib_def.h>
/*
* FXO Defines
*/
#define FXO_SET_HANGUP           0x00
#define FXO_SET_PICKUP2CALL      0x01
#define FXO_SET_TALK             0x02
#define FXO_SET_RCV_RING         0x03
#define FXO_EN_REMOTE_SPEAK      0x04
#define FXO_DIS_REMOTE_SPEAK     0x05
#define FXO_EN_REMOTE_LISTEN     0x06
#define FXO_DIS_REMOTE_LISTEN    0x07
#define FXO_SET_RING_VOLUME_IN   0x09
#define FXO_SET_RING_VOLUME_OUT  0x0a
#define FXO_GET_STATE            0x80

#define FXO_STATE_RING     0x00
#define FXO_STATE_PICKUP   0x01
#define FXO_STATE_HANGUP   0x02

/* -------------------------------------------------------------------------- */
/*
* Switcher control defines
*/

/* cmd defines */
enum
{
	SW_SPK_ENABLE = 0,
	SW_SPK_DISABLE,
	SW_SDI_GET,
	SW_BRD_SHUTDOWN,
	SW_EXTERN_RESET,
	SW_GPS_ENABLE,
	SW_GPS_DISABLE,
};

#define BCTL_ID_SHIFT           24
#define BCTL_ID_MASK            0xff
#define BCTL_ID(v)              (((v) >> BCTL_ID_SHIFT) & BCTL_ID_MASK)

#define BCTL_VAL_SHIFT          0
#define BCTL_VAL_MASK           0xff
#define BCTL_VAL(v)             (((v) >> BCTL_VAL_SHIFT) & BCTL_VAL_MASK)

#define BCTL_ARG32(id, val) \
	(((id)  << BCTL_ID_SHIFT) | \
	 ((val) << BCTL_VAL_SHIFT))

/* common device register read/write macro defines */
#define PLD_DEV_ID(n)           BCTL_ARG32(0, n)
#define FPGA_DEV_ID(n)          BCTL_ARG32(1, n)

#define COM_REG_READ            0 /* read register */
#define COM_REG_WRITE           1 /* write register */

#define SPK_MODE_ON             1 /* buzzer on */
#define SPK_MODE_OFF            0 /* buzzer off */

/* common device register read/write struct */
typedef struct{
	u32 id;           /* device id, such as: PLD_DEV_ID(0) */
	u32 rw;           /* see also COM_REG_READ */
	u32 reg;          /* register offset address */
	u32 val;          /* register value */
}fpga_rw_param;

/* -------------------------------------------------------------------------- */
int BrdSetSpeakerMode(int nMode);
int BrdSwitcherCtrl(int nCmd);
int BrdFxoCtrl(int devid, int cmd, void *args);

/*
* \brief :
*      set gpio extend card work mode
* \param :
*      @dwNo : extend card id
*      @nDir : extend card gpio direction controls . 0 = input; 1 = output
*              Bit[31:0] = GPIO[31:0]
*      @nVal : set io default value . 1 = high ; 0 = low
* \return :
*      0 -- success
*/
int BrdGpioExtCardConfig(int dwNo, int nDir, int nVal);

/*
* \brief :
*      get gpio extend card input value .
* \param :
*      @dwNo      : extend card id
*      @nInputNum : want get input IO number
*      @nVal      : return input IO value
* \return :
*      0 -- success
*/
int BrdGpioExtCardGetInput(int dwNo, int nInputNum, int *nVal);
/*
* \brief :
*      set gpio extend card output value .
* \param :
*      @dwNo       : extend card id
*      @nOutputNum : want set output IO number
*      @nVal       : output IO value
* \return :
*      0 -- success
*/
int BrdGpioExtCardSetoutput(int dwNo, int nOutputNum, int nVal);

/*
* read/write IC(FPGA) register
*/
int BrdRwLogIC(fpga_rw_param *pParam);

/*
* BrdWpsCtrl
*
* set wps state
*
* @param
*             state 0: open  1:normal
* @return 0/-1
*/
int BrdWpsCtrl(int state);

int BrdSwitchConsole(unsigned int port);
__END_DECLS

#endif
