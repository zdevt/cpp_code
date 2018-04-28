/*
 * =====================================================================================
 *
 *       Filename:  slectsleep.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07/04/2014 04:16:04 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (),
 *        Company:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int msSleep ( unsigned int ms )
{
  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = ms;
  return select ( 0, NULL, NULL, NULL, &tv );
}

int main ( int argc, char* argv[] )
{
  while ( 1 )
  {
    printf ( "test1\n" );
    msSleep ( 800 * 1000 );

    printf ( "test2\n" );
    msSleep ( 800 * 1000 );

    printf ( "test3\n" );
    msSleep ( 800 * 1000 );

    printf ( "test4\n" );
    msSleep ( 800 * 1000 );

  }

  return 0;
}


