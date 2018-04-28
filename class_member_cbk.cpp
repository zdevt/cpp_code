
/*
 * =========================================================================
 *
 *       FileName:  class_member_cbk.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-02-10 10:38:28
 *  Last Modified:  2018-02-10 10:45:01
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
#include <thread>
#include <mutex>
#include <map>
#include <list>
#include <string>
#include <functional>

class Test
{
  public:
    Test()
    {
    }
    ~Test()
    {
    }

  public:
    void Cbk ( int a )
    {
      fprintf ( stderr, "%s %d\n", __FUNCTION__, a );
    }
};


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  Test a;

  auto f = std::bind ( &Test::Cbk, &a, std::placeholders::_1 );
  f ( 1 );
  f ( 2 );

  return 0;
}

