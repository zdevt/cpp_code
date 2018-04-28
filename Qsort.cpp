/*
 * =====================================================================================
 *
 *       Filename:  QsortZt.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年03月22日 10时51分49秒
 *  Last Modified:  2018-03-22 15:15:57
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


uint32_t testArray[] =
{

  66,  1, 333, 2,  4,   3,  7,
  616, 2, 333, 21, 41, 13, 17,
};


int compare ( const void* a, const void* b )
{
  return ( * ( uint32_t* ) a - * ( uint32_t* ) b );
}


#if 0
int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  int n = 14;
  qsort ( testArray, 14, sizeof ( uint32_t ), compare );

  for ( int i = 0; i < n; ++i )
    printf ( "%d ", testArray[i] );

  return 0;
}
#endif

