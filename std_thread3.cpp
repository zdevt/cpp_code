
/*
 * =========================================================================
 *
 *       FileName:  std_thread3.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-09 09:43:20
 *  Last Modified:  2018-01-10 16:17:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt ()
 *   Organization:
 *
 * =========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <thread>


class A
{
  public:
    A()
    {
      std::thread ( &A::Task, this ).detach();
    }

    void Task()
    {
      while ( 1 )
      {
        sleep ( 1 );
        fprintf ( stderr, ".....\n" );
      }
    }
};


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  A a;

  while ( 1 )
  {
    sleep ( 1 );
  }

  return 0;
}

