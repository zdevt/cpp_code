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
#include <map>

#include "Network.cpp"

#define MAX_CNT   (2048)

typedef int ( *Fun ) ( void* );
std::map<int, Fun> map_fd_pFun;

int F1 ( void* p )
{
  int fd = *reinterpret_cast<int*> ( p );
  int ret = 0;
  char buffer[2048];
  ret = Network::Recvn ( fd, buffer, 2048 );

  return ret;
}

int main ( int argc, char* argv[] )
{
  int listensock = Network::MakeTCPServer ( 12345 );
  int ret = -1;

  epoll_event ev;
  epoll_event events[MAX_CNT];

  int epollfd = epoll_create1 ( 0 );

  ev.data.fd = listensock;
  ev.events = EPOLLIN;
  ret = epoll_ctl ( epollfd, EPOLL_CTL_ADD, listensock, &ev );
  printf ( "epoll_ctl, add listensock ret %d\n", ret );

  int nfd = 0;

  while ( 1 )
  {
    nfd = epoll_wait ( epollfd, events, MAX_CNT, 1000 );

    for ( int i = 0; i < nfd; ++i )
    {
      if ( events[i].data.fd == listensock )
      {
        sockaddr saddr;
        int sk = Network::MakeAccept ( listensock, &saddr );
        Network::SetNonBlock ( sk );

        ev.data.fd = sk;
        ev.events = EPOLLIN | EPOLLET;
        ret = epoll_ctl ( epollfd, EPOLL_CTL_ADD, sk, &ev );

        map_fd_pFun.insert ( std::pair<int, Fun> ( sk, F1 ) );

        printf ( "incomming connect %d %s ret=%d \n",
                 sk, inet_ntoa ( reinterpret_cast<sockaddr_in*> ( &saddr )->sin_addr ), ret );
      }
      else
      {
        auto iter = map_fd_pFun.find ( events[i].data.fd );

        if ( iter != map_fd_pFun.end() )
        {
          ret = ( iter->second ) ( & ( events[i].data.fd ) );

          if ( ret < 0 )
          {
            #if 0
            map_fd_pFun.erase ( iter );

            shutdown ( events[i].data.fd, SHUT_RDWR );
            close ( events[i].data.fd );

            ev.data.fd = events[i].data.fd;
            ev.events = 0;
            epoll_ctl ( epollfd, EPOLL_CTL_DEL, ev.data.fd, &ev );

            printf ( "line=%d del connect %d ret=%d\n",
                     __LINE__, ev.data.fd, ret );
            #endif
          }
        }
      }
    }
  }

  close ( epollfd );
  close ( listensock );

  return 0;
}


