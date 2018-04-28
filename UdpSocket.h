/*
 * =====================================================================================
 *
 *       Filename:  UdpSocket.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/26/2017 03:34:13 PM
 *  Last Modified:  08/26/2017 03:34:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef  UDPSOCKET_INC
#define  UDPSOCKET_INC

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/un.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <string>

class UdpSocket
{
  public:
    UdpSocket ( std::string lsSelf, std::string lsRemote );   /*  local socket */
    UdpSocket ( uint16_t localport, std::string remoteip, uint16_t remoteport );
    virtual ~UdpSocket();

  public:
    int Send ( const uint8_t* sendbuf, int size );
    int Recv ( uint8_t* recvbuf, int size );

  private:
    int InitLocalSocket();
    int Init();
    int DeInit();
    int SetNonBlock ( int sockfd );

  private:
    uint16_t m_port_local;
    uint16_t m_port_remote;
    std::string m_remoteip;

    sockaddr_in m_local_addr;
    sockaddr_in m_remote_addr;

    int m_sockfd_self;
    int m_sockfd_remote;

    std::string m_lsSelf;
    std::string m_lsRemote;

    sockaddr_un m_self_ls_addr;
    sockaddr_un m_remote_ls_addr;

    sockaddr* m_premotesockaddr;

    int m_selfaddrlen;
    int m_remoteaddrlen;
};


#endif   /* ----- #ifndef UdpSocket.h ----- */

