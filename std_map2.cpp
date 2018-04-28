/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-05 08:50:47
 *  Last Modified:  2018-01-05 08:50:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include <iostream>
#include <map>
#include <vector>

typedef std::map<int, time_t> map_fd_time_t;

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  map_fd_time_t mymap;

  time_t a;

  time ( &a );
  mymap.insert ( map_fd_time_t::value_type ( 1, a ) );
  sleep ( 1 );

  time ( &a );
  mymap.insert ( map_fd_time_t::value_type ( 2, a ) );
  sleep ( 1 );

  time ( &a );
  mymap.insert ( map_fd_time_t::value_type ( 3, a ) );
  sleep ( 1 );

  auto iter = mymap.find ( 2 );
  iter->second = 12345;

  for ( auto& e : mymap )
  {
    std::cout << e.first << " " << e.second << std::endl;
  }


  return 0;
}

