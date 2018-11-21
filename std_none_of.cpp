
/*
 * =========================================================================
 *
 *       FileName:  std_none_of.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-11-21 14:06:27
 *  Last Modified:  2018-11-21 14:09:15
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

  std::vector<int> a = { 1, 2, 3, 4, 5, 6, 7};

  auto f = [] ( int i )
  {
    return i < 1 ;
  };

  if ( std::none_of ( a.begin(), a.end(), f ) )
    std::cout << "none_of i < 1" << std::endl;

  return 0;
}

