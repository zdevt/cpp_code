/*
 * =====================================================================================
 *
 *       Filename:  union.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年06月13日 17时27分53秒
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
#include <stdint.h>

typedef union
{
  struct
  {
    uint8_t a: 1;
    uint8_t b: 2;
    uint8_t c: 3;
    uint8_t d: 2;
  };
  uint8_t e;
} test_t;


int main ( int argc, char* argv[] )
{
  test_t a;

  * ( uint8_t* ) ( &a ) = 0x5;

  //a.e = 0x5;
  printf ( "%d %d %d %d %d\n", a.e, a.a, a.b, a.c, a.d );

  return 0;
}

