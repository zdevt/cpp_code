
/*
 * =========================================================================
 *
 *       FileName:  std_multimap.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-11 13:35:31
 *  Last Modified:  2018-01-13 10:44:32
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

  #if 1
  std::multimap<std::string, int> a;
  a.insert ( {"aaa", 1} );
  a.insert ( {"aaa", 2} );
  a.insert ( {"aaa", 1} );
  a.insert ( {"baa", 1} );
  a.insert ( {"baa", 3} );
  a.insert ( {"baa", 1} );
  #else
  std::map<std::string, int> a;
  a.insert ( {"aaa", 2} );
  a.insert ( {"baa", 1} );
  #endif

  //for ( auto& e : a )
  //std::cout << e.first << " " << e.second << std::endl;

  //for ( auto iter = a.lower_bound ( "aaa" ); iter != a.upper_bound ( "aaa" ); ++iter )
  //std::cout << iter->first << " " << iter->second << std::endl;

  //for_each ( a.lower_bound ( "aaa" ), a.upper_bound ( "aaa" ), [&] ( std::multimap<std::string, int>::value_type e )
  for_each ( a.lower_bound ( "aaa" ), a.upper_bound ( "aaa" ), [&] ( decltype ( a ) ::value_type e )
  {
    std::cout << e.first << " " << e.second << std::endl;
  } );

  return 0;
}

