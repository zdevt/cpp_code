
/*
 * =========================================================================
 *
 *       FileName:  class_recursion.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-11-08 15:51:49
 *  Last Modified:  2018-11-08 15:57:19
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
    int Febo ( int i );
};

int Test::Febo ( int i )
{
  if ( i < 2 )
    return 1;

  return i + Febo ( i - 1 );
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  Test a;

  printf ( "%d\n", a.Febo ( 10 ) );


  return 0;
}

