/*
 * =====================================================================================
 *
 *       Filename:  100_100.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/01/2017 03:26:47 PM
 *  Last Modified:  2018-01-25 16:45:13
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
#include <iostream>
#include <random>
#include <vector>


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  std::vector<int> vec ( 100, 100 );
  int cnt = 100000;
  int number = 0;

  std::default_random_engine generator;
  std::uniform_int_distribution<int> dist ( 0, 99 );

  for ( int i = 0; i < cnt; ++i )
  {
    for ( int j = 0; j < 100; ++j )
    {
      number = dist ( generator );

      if ( vec[j] > 0 )
      {
        vec[j] -= 1;
        vec[number] += 1;
      }
    }
  }

  for ( auto& ele : vec )
  {
    printf ( "%d \n", ele );
  }

  return 0;
}

