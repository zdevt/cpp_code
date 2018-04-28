/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年03月31日 10时24分41秒
 *  Last Modified:  2016年03月31日 10时24分41秒
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


int abc ( int a, int b, int c )
{
  if ( a < 0 && b < 0 && c < 0 )
    throw 1;

  if ( a == 0 && b == 0 && c == 0 )
    throw 2;

  if ( a == 0 && b > 0 && c > 0 )
    throw "3333333";

  return a + b * c;
}


int main ( int argc, char* argv[] )
{

  try
  {
    printf ( "%d\n", abc ( 0, 0, 0 ) );
  }

  catch ( const char* e )
  {
    printf ( "%s\n", e );
  }

  catch ( int e )
  {
    printf ( "%d\n", e );
  }


  return 0;
}


