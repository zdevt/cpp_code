/*
 * =====================================================================================
 *
 *       Filename:  LocalSocket.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年08月26日 11时08分28秒
 *  Last Modified:  2017年08月26日 11时08分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include "LocalSocket.h"


LocalSocket::LocalSocket ( std::string lsSelf, std::string lsRemote )
  : m_lsSelf ( lsSelf ), m_lsRemote ( lsRemote ),
    m_sockfd_self ( -1 ), m_sockfd_remote ( -1 )
{
  Init();
}

LocalSocket::~LocalSocket()
{
  DeInit();
}

int LocalSocket::Init()
{
  m_sockfd_self = socket ( AF_UNIX, SOCK_DGRAM, 0 );

  int loop = 1;
  setsockopt ( m_sockfd_self, SOL_SOCKET, SO_REUSEADDR,
               reinterpret_cast<char*> ( &loop ), sizeof ( loop ) );

  m_self_addr.sun_family = AF_UNIX;
  strcpy ( m_self_addr.sun_path, m_lsSelf.c_str() );
  m_self_addr.sun_path[0] = 0;
  m_selfaddrlen = m_lsSelf.size() + offsetof ( sockaddr_un, sun_path );
  bind ( m_sockfd_self, reinterpret_cast<sockaddr*> ( &m_self_addr ), m_selfaddrlen );

  m_sockfd_remote = socket ( AF_UNIX, SOCK_DGRAM, 0 );

  m_remote_addr.sun_family = AF_UNIX;
  strcpy ( m_remote_addr.sun_path, m_lsRemote.c_str() );
  m_remote_addr.sun_path[0] = 0;
  m_remoteaddrlen = m_lsRemote.size() + offsetof ( sockaddr_un, sun_path );

  return 0;
}

int LocalSocket::DeInit()
{
  if ( m_sockfd_self > 0 )
    close ( m_sockfd_self );

  if ( m_sockfd_remote > 0 )
    close ( m_sockfd_remote );

  return 0;
}

int LocalSocket::Send ( const uint8_t* sendbuf, int size )
{
  if ( m_sockfd_remote < 0 )
    return -1;

  return sendto ( m_sockfd_remote, reinterpret_cast<const char*> ( sendbuf ), size,
                  MSG_NOSIGNAL,
                  reinterpret_cast<sockaddr*> ( &m_remote_addr ), m_remoteaddrlen );
}

int LocalSocket::Recv ( uint8_t* recvbuf, int size )
{
  if ( m_sockfd_self < 0 )
    return -1;

  sockaddr addr;
  socklen_t len = sizeof ( addr );

  return recvfrom ( m_sockfd_self, reinterpret_cast<char*> ( recvbuf ),
                    size, 0, &addr, &len );
}


#ifdef TEST
int main ( int argc, char* argv[] )
{
  LocalSocket ls1 ( "@aaa", "@bbb" );
  LocalSocket ls2 ( "@bbb", "@aaa" );

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

