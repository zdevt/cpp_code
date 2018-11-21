
/*
 * =========================================================================
 *
 *       FileName:  std_unordered_multiset.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-11-21 13:46:27
 *  Last Modified:  2018-11-21 13:49:37
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

using namespace std;

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  unordered_multiset<string> a = {"apple", "beaf", "egg"};
  unordered_multiset<string> b = {"beer", "apple", "beaf", "egg"};

  b.insert ( a.begin(), a.end() );

  for ( auto& e : b )
    cout << e << endl;

  return 0;
}

