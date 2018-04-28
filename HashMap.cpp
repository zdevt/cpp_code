/*
 * =====================================================================================
 *
 *       Filename:  HashMap.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年12月09日 15时10分49秒
 *  Last Modified:  2018-01-25 17:10:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#include <ext/hash_map>

typedef __gnu_cxx::hash_map<int, int> hmapii_t;

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  //__gnu_cxx::hash_map<int, int> hmapii;
  hmapii_t hmapii;

  hmapii.insert ( std::pair<int, int> ( 1, 1 ) );
  hmapii.insert ( std::pair<int, int> ( 5, 3 ) );
  hmapii.insert ( std::pair<int, int> ( 7, 3 ) );
  hmapii.insert ( std::pair<int, int> ( 2, 8 ) );

  auto iter = hmapii.find ( 7 );
  printf ( "find=%d\n", iter->second );

  iter = hmapii.find ( 2 );
  printf ( "find=%d\n", iter->second );

  return 0;
}

