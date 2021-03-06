#ifndef LIBP2P_SOCKET_H
#define LIBP2P_SOCKET_H

#include "basic/config.h"


#ifdef _WIN32
#   define P2P_SOCKET_ERROR     SOCKET_ERROR
#   define P2P_SKT_GET_ERR      WSAGetLastError()
#   define P2P_INVALID_SOCKET   INVALID_SOCKET
#else
#   define P2P_SOCKET_ERROR     -1
#   define P2P_SKT_GET_ERR      errno
#   define P2P_INVALID_SOCKET   -1
#endif


int		P2P_socket_init();
int		P2P_socket_free();
void	P2P_get_mac_addr( unsigned char mac[12] , P2P_in_addr_t dest_ip );
int		P2P_get_my_lan_ip( P2P_in_addr_t *p_my_lan_ip );

int		P2P_init_broadcast_socket();


#ifdef _WIN32
DWORD WINAPI	P2P_skt_recv( void* param );
#else
int             P2P_skt_recv( void* param );
#endif


#ifdef _WIN32
int		P2P_winsock_init();
#endif


#endif