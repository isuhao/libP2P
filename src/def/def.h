#ifndef LIBP2P_DEF_H
#define LIBP2P_DEF_H

#include "basic/config.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ define ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define		P2P_OPT_ENABLE_SERVER	0x00000001

#define		P2P_ERROR	-1;
#define		P2P_OK		1;

#define		MASK_MACRO(DATA,MASK)	(DATA&MASK)


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//
typedef struct LLTask
{
	int		sid;
	int		round;
	P2P_clock_t	time_interval;

} LLTask_s;

#endif