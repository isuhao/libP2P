#ifndef LIBP2P_UUID_H
#define LIBP2P_UUID_H

#include "config.h"



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct	UUID
{
	uint8_t		uuid[16];
} UUID_s;



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void	P2P_uuid_generate( UUID_s *p_uuid ); 



#endif