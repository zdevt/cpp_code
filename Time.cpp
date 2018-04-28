/*
 * =====================================================================================
 *
 *       Filename:  Time.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-15 15:37:25
 *  Last Modified:  2018-01-15 15:37:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  time_t ti, t2;
  time ( &ti );
  sleep ( 3 );
  time ( &t2 );

  printf ( "%f\n", difftime ( t2, ti ) );
  printf ( "%f\n", difftime ( ti, t2 ) );


  return 0;
}

