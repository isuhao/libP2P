#ifndef LIBP2P_SOCKET_H
#define LIBP2P_SOCKET_H

#include "config.h"


int		P2P_socket_init();
int		P2P_socket_free();
void	P2P_get_mac_addr( unsigned char mac[12] , P2P_in_addr_t dest_ip );
int		P2P_get_my_lan_ip( P2P_in_addr_t *p_my_lan_ip );

#ifdef _WIN32
int		P2P_winsock_init();
#endif


#endif