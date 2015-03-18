#include "libP2P.h"

#include "socket.h"
#include "log.h"


/***********************************************************
	P2P_init
************************************************************/
int P2P_init()
{
	LOG( "P2P_init" )

	// init log
	P2P_log_init();

	// init socket.
	P2P_socket_init();

	return 0;
}



/***********************************************************
	P2P_free
************************************************************/
int P2P_free()
{
	return 0;
}