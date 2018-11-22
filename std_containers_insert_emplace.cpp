
/*
 * =========================================================================
 *
 *       FileName:  std_containers_insert_emplace.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-11-22 13:44:24
 *  Last Modified:  2018-11-22 13:45:04
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

using namespace std;

struct Foo
{
  Foo ( int n, double x );
};


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::vector<Foo> v;
  auto someIterator = v.begin();
  v.emplace ( someIterator, 42, 3.1416 );
  v.insert ( someIterator, Foo ( 42, 3.1416 ) );

  return 0;
}

