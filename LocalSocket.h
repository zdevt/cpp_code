/*
 * =====================================================================================
 *
 *       Filename:  LocalSocket.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年08月26日 11时08分32秒
 *  Last Modified:  2017年08月26日 11时08分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef  LOCALSOCKET_INC
#define  LOCALSOCKET_INC

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <string>

class LocalSocket
{
  public:
    LocalSocket ( std::string lsSelf, std::string lsRemote );
    virtual ~LocalSocket();

  public:
    int Send ( const uint8_t* sendbuf, int size );
    int Recv ( uint8_t* recvbuf, int size );

  private:
    int Init();
    int DeInit();

  private:
    int m_sockfd_self;
    int m_sockfd_remote;

    std::string m_lsSelf;
    std::string m_lsRemote;

    sockaddr_un m_self_addr;
    sockaddr_un m_remote_addr;

    int m_selfaddrlen;
    int m_remoteaddrlen;
};


#endif   /* ----- #ifndef LocalSocket.h ----- */

