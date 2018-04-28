/*
 * =====================================================================================
 *
 *       Filename:  EpollTest.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/31/2017 02:46:29 PM
 *  Last Modified:  08/31/2017 02:46:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <vector>

#include "Network.cpp"


int main ( int argc, char* argv[] )
{
  int i = 0;
  int fd = 0;
  int ret = -1;
  std::vector<int> fdvec;
  const int max_cnt = 50 * 1000;
  fdvec.reserve ( max_cnt );
  char buf[] = "test testssasdfasdfasdfsadfasdf";

  for ( i = 0; i < max_cnt; ++i )
  {
    do
    {
      #ifdef TEST2
      fd = Network::MakeTCPClient ( "127.0.0.1", 28000 );
      //fd = Network::MakeTCPClient ( "39.108.167.69", 28000 );
      #else
      sockaddr_in addr;
      memset ( &addr, 0, sizeof ( addr ) );
      fd = socket ( AF_INET, SOCK_STREAM, IPPROTO_TCP );

      addr.sin_addr.s_addr  = inet_addr ( "127.0.0.1" );
      //addr.sin_addr.s_addr  = inet_addr ( "39.108.167.69" );
      addr.sin_family     = AF_INET;
      addr.sin_port       =  htons ( 28000 );

      ret = connect ( fd, reinterpret_cast<struct sockaddr*> ( &addr ), sizeof ( addr ) );
      #endif
    }
    while ( ret < 0 );

    if ( fd > 0 )
    {
      fdvec.push_back ( fd );
      //Network::Sendn ( fd, buf, strlen ( buf ) );
    }

    printf ( "fd =%d\n", fd );
    //usleep ( 10 );
  }


  sleep ( 5 );

  for ( auto& ele : fdvec )
  {
    shutdown ( ele, SHUT_RDWR );
    close ( ele );
  }

  return 0;
}

