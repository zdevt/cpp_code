
/*
 * =========================================================================
 *
 *       FileName:  std_pair.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-11-23 16:51:19
 *  Last Modified:  2018-11-23 16:52:49
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


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::pair<int, int> a ( 1, 10 );
  std::pair<int, int> b ( 2, 10 );

  std::cout << ( a == b );

  return 0;
}

