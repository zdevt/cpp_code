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
#include <memory>
#include <iostream>

#include "Network.cpp"

#define MAX_CNT   (2048)

typedef int ( *Fun ) ( int fd );

struct my_epoll_t
{
  my_epoll_t ( int _fd, Fun _pFun )
  {
    fd = _fd;
    pFun = _pFun;
  }
  ~my_epoll_t()
  {
    shutdown ( fd, SHUT_RDWR );
    close ( fd );
  }

  int fd;
  Fun pFun;
};

int F1 ( int fd )
{
  int ret = 0;
  char buffer[2048];
  ret = read ( fd, buffer, 2048 );
  //ret = Network::Recvn ( fd, buffer, 2048 );

  if ( ret > 0 )
    printf ( "fd=%d recv=%d %s\n", fd, ret, buffer );

  return ret;
}

int F2 ( int fd )
{
  char buffer[2048];
  return Network::Sendn ( fd, buffer, 2048 );
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

        ev.data.ptr = new my_epoll_t ( sk, F1 );

        ev.events = EPOLLIN | EPOLLET;
        ret = epoll_ctl ( epollfd, EPOLL_CTL_ADD, sk, &ev );

        printf ( "incomming connect %d %s ret=%d \n",
                 sk, inet_ntoa ( reinterpret_cast<sockaddr_in*> ( &saddr )->sin_addr ), ret );
      }
      else
      {
        my_epoll_t* p = reinterpret_cast< my_epoll_t*> ( events[i].data.ptr );
        ret = p->pFun ( p->fd );

        if ( ret <= 0 )
        {
          ev.data.fd = p->fd;
          ev.events = 0;
          epoll_ctl ( epollfd, EPOLL_CTL_DEL, p->fd, &ev );
          delete p;

          printf ( "line=%d del connect %d ret=%d\n",
                   __LINE__, ev.data.fd, ret );
        }
        else
        {
          //printf ( "line=%d ret=%d\n", __LINE__, ret );
        }
      }
    }
  }

  close ( epollfd );
  close ( listensock );

  return 0;
}


