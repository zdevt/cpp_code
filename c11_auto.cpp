/*
 * =====================================================================================
 *
 *       Filename:  auto.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月08日 11时40分02秒
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

int Test()
{
  printf ( " Test !\n" );
  return 0;
}

int Test2 ( int a )
{
  printf ( " Test %d!\n", a );
  return 0;
}

int main ( int argc, char* argv[] )
{
  auto p = Test;
  p();


  return 0;
}

