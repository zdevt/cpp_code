/*
 * =====================================================================================
 *
 *       Filename:  UdpSocket.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/26/2017 03:34:03 PM
 *  Last Modified:  2018-01-22 09:12:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include "UdpSocket.h"


UdpSocket::UdpSocket ( std::string lsSelf, std::string lsRemote )
  : m_lsSelf ( lsSelf ), m_lsRemote ( lsRemote ),
    m_sockfd_self ( -1 ), m_sockfd_remote ( -1 ),
    m_premotesockaddr ( NULL )
{
  InitLocalSocket();
}

UdpSocket::UdpSocket ( uint16_t localport, std::string remoteip, uint16_t remoteport )
  : m_port_local ( localport ), m_port_remote ( remoteport ), m_remoteip ( remoteip ),
    m_sockfd_self ( -1 ), m_sockfd_remote ( -1 ),
    m_premotesockaddr ( NULL )
{
  Init();
}

UdpSocket::~UdpSocket()
{
  DeInit();
}

int UdpSocket::Init()
{
  m_sockfd_self = socket ( PF_INET, SOCK_DGRAM, 0 );
  SetNonBlock ( m_sockfd_self );

  int loop = 1;
  setsockopt ( m_sockfd_self, SOL_SOCKET, SO_REUSEADDR,
               reinterpret_cast<char*> ( &loop ), sizeof ( loop ) );

  bzero ( &m_local_addr, sizeof ( m_local_addr ) );

  m_local_addr.sin_family      = AF_INET;
  m_local_addr.sin_addr.s_addr = htonl ( INADDR_ANY );
  m_local_addr.sin_port        = htons ( m_port_local );

  bind ( m_sockfd_self, reinterpret_cast<sockaddr*> ( &m_local_addr ), sizeof ( m_local_addr ) );

  m_sockfd_remote = socket ( PF_INET, SOCK_DGRAM, 0 );
  SetNonBlock ( m_sockfd_remote );

  bzero ( &m_remote_addr, sizeof ( m_remote_addr ) );

  m_remote_addr.sin_family    = AF_INET;
  m_remote_addr.sin_port      = htons ( m_port_remote );
  m_remote_addr.sin_addr.s_addr = inet_addr ( m_remoteip.c_str() );

  m_remoteaddrlen = sizeof ( m_remote_addr );
  m_premotesockaddr = reinterpret_cast<sockaddr*> ( &m_remote_addr );

  return 0;
}

int UdpSocket::InitLocalSocket()
{
  m_sockfd_self = socket ( AF_UNIX, SOCK_DGRAM, 0 );

  int loop = 1;
  setsockopt ( m_sockfd_self, SOL_SOCKET, SO_REUSEADDR,
               reinterpret_cast<char*> ( &loop ), sizeof ( loop ) );

  m_self_ls_addr.sun_family = AF_UNIX;
  strcpy ( m_self_ls_addr.sun_path, m_lsSelf.c_str() );
  m_self_ls_addr.sun_path[0] = 0;
  m_selfaddrlen = m_lsSelf.size() + offsetof ( sockaddr_un, sun_path );
  bind ( m_sockfd_self, reinterpret_cast<sockaddr*> ( &m_self_ls_addr ), m_selfaddrlen );

  m_sockfd_remote = socket ( AF_UNIX, SOCK_DGRAM, 0 );

  m_remote_ls_addr.sun_family = AF_UNIX;
  strcpy ( m_remote_ls_addr.sun_path, m_lsRemote.c_str() );
  m_remote_ls_addr.sun_path[0] = 0;
  m_remoteaddrlen = m_lsRemote.size() + offsetof ( sockaddr_un, sun_path );
  m_premotesockaddr = reinterpret_cast<sockaddr*> ( &m_remote_ls_addr );

  return 0;
}

int UdpSocket::DeInit()
{
  if ( m_sockfd_self > 0 )
    close ( m_sockfd_self );

  if ( m_sockfd_remote > 0 )
    close ( m_sockfd_remote );

  return 0;
}

int UdpSocket::Send ( const uint8_t* sendbuf, int size )
{
  if ( m_sockfd_remote < 0 )
    return -1;

  return sendto ( m_sockfd_remote, reinterpret_cast<const char*> ( sendbuf ), size,
                  0, m_premotesockaddr, m_remoteaddrlen );
}

int UdpSocket::Recv ( uint8_t* recvbuf, int size )
{
  if ( m_sockfd_self < 0 )
    return -1;

  sockaddr addr;
  socklen_t len = sizeof ( addr );

  return recvfrom ( m_sockfd_self, reinterpret_cast<char*> ( recvbuf ),
                    size, 0, &addr, &len );
}

int UdpSocket::SetNonBlock ( int sockfd )
{
  int flags;

  if ( ( flags = fcntl ( sockfd, F_GETFL, 0 ) ) < 0 )
    return -1;

  if ( fcntl ( sockfd, F_SETFL, flags | O_NONBLOCK ) < 0 )
    return -1;

  return 0;
}


#ifdef TEST
int main ( int argc, char* argv[] )
{
  #if TESTLS
  UdpSocket ls1 ( "@aaa", "@bbb" );
  UdpSocket ls2 ( "@bbb", "@aaa" );
  #else
  UdpSocket ls1 ( 32345, "127.0.0.1", 32346 );
  UdpSocket ls2 ( 32346, "127.0.0.1", 32345 );
  #endif

  uint8_t a[] = "test aaaaaa";
  uint8_t b[] = "test bbbbbb";

  uint8_t buf1[1024];
  uint8_t buf2[1024];

  while ( 1 )
  {
    ls1.Send ( a, 10 );
    memset ( buf1, 0, 1024 );
    ls2.Recv ( buf1, 10 );
    printf ( "ls2 recv ls1 %s\n", buf1 );

    ls2.Send ( b, 10 );
    memset ( buf2, 0, 1024 );
    ls1.Recv ( buf2, 10 );
    printf ( "ls1 recv ls2 %s\n", buf2 );

    sleep ( 1 );
  }

  return 0;
}
#endif

