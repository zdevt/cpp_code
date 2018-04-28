/*
 * =====================================================================================
 *
 *       Filename:  a.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-15 15:35:10
 *  Last Modified:  2018-03-22 10:52:44
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
#include <strings.h>
#include <string.h>
#include <string>
#include <vector>

#if 0

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  //printf ( "%s\n", __VERSION__ );

  //for ( int i = 0; i < argc; ++i )
  //{
  //fprintf ( stderr, "%s ", argv[i] );
  //}

  //fprintf ( stderr, "\n" );
  std::string str = "12345";
  fprintf ( stderr, "size=%d %d\n", ( int ) str.size(), ( int ) strlen ( str.c_str() ) );
  std::vector<uint8_t> vec ( str.size() + 1, 0 );
  memcpy ( &vec[0], str.data(), str.size() );

  for ( auto& e : vec )
    fprintf ( stderr, "%02x ", e );


  fprintf ( stderr, "\n" );

  int i = 0;
  fprintf ( stderr, "%d\n", ++i );
  fprintf ( stderr, "%d\n", i );
  i = 0;
  fprintf ( stderr, "%d\n", i++ );
  fprintf ( stderr, "%d\n", i );


  return 0;
}

#endif
