
/*
 * =========================================================================
 *
 *       FileName:  std_unordered_set.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-11-07 13:44:33
 *  Last Modified:  2018-11-21 13:46:11
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

#include <unordered_set>

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::unordered_set<std::string> myset =
  {"water", "sand", "ice", "foam"};

  std::unordered_set<std::string> myset2 =
  {"water", "apple", "orange", "beaf"};

  myset2.insert ( myset.begin(), myset.end() );

  for ( auto& e : myset2 )
    std::cout << e << std::endl;

  return 0;
}

