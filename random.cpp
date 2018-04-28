/*
 * =====================================================================================
 *
 *       Filename:  random.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年06月23日 11时01分21秒
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
#include <time.h>


int main ( int argc, char* argv[] )
{
  srand ( time ( NULL ) );
  int a = random() % 10;

  //for ( int i = 0; i < 7 * 10; ++i )
  for ( int i = 0; i < 7; ++i )
  {
    if ( ( i % 0x7 == 0 ) && ( i != 0 ) )
      printf ( "\n" );

    a = random() % 10;
    printf ( "%02d ", a );
  }

  printf ( "\n" );

  return 0;
}

