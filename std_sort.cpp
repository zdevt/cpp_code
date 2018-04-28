/*
 * =====================================================================================
 *
 *       Filename:  sort.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月26日 17时14分19秒
 *  Last Modified:  2018-03-22 15:20:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  std::vector<int> veca;

  for ( int i = 0; i < 0x100; ++i )
    veca.push_back ( random() % 0xfff );

  for ( unsigned int i = 0; i < veca.size(); ++i )
  {
    if ( ( i != 0 ) && ( i % 0x10 == 0 ) )
      printf ( "\n" );

    printf ( "0x%04x ", veca[i] );
  }

  printf ( "\n" );
  printf ( "\n" );

  std::sort ( veca.begin(), veca.end() );

  for ( int i = 0; i < ( int ) veca.size(); ++i )
  {
    if ( ( i != 0 ) && ( i % 0x10 == 0 ) )
      printf ( "\n" );

    printf ( "0x%04x ", veca[i] );
  }

  printf ( "\n" );

  double avg = 0;

  for ( auto ele : veca )
    avg += ele;

  avg /= veca.size();
  printf ( "avg = %f\n", avg );

  return 0;
}

