/*
 * =====================================================================================
 *
 *       Filename:  debug.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年06月09日 14时46分57秒
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

//  -DDEBUG

int main ( int argc, char* argv[] )
{
  printf ( "test\n" );

  #ifdef DEBUG
  printf ( "debug................\n" );
  #endif

  #ifdef VER_D
  printf ( "%s\n", VER_D );
  #endif

  return 0;
}
