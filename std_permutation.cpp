
/*
 * =========================================================================
 *
 *       FileName:  std_permutation.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-11-09 14:01:37
 *  Last Modified:  2018-11-09 14:18:13
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


//std::vector<int> test = { 1, 3, 5, 7, 2, 4, 6, 8};
std::vector<int> test = { 1, 5, 3};

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  for ( auto& e : test )
    std::cout << e << " ";

  std::cout << std::endl;

  while ( next_permutation ( test.begin(), test.end() ) )
  {
    for ( auto& e : test )
      std::cout << e << " ";

    std::cout << std::endl;
  }

  return 0;
}

