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
#include <time.h>

#include <iostream>
#include <algorithm>


template<typename T>
void insertionSort ( T a[], int n )
{
  for ( int i = 1; i < n; i++ )
  {
    T t = a[i];
    int j;

    for ( j = i - 1; j >= 0 && t < a[j]; --j )
      a[j + 1] = a[j];

    a[j + 1] = t;
  }
}

int compare ( const void* a , const void* b )
{
  return ( * ( int* ) a - * ( int* ) b );
}


int main ( int argc, char* argv[] )
{
  int a[10000] = { 0 };
  int step = 10;

  double clocksPerMillis = double ( CLOCKS_PER_SEC ) / 1000;

  std::cout << "...." << std::endl;

  for ( int n = 9000; n <= 9100; n += step )
  {
    for ( int i = 0; i < n; ++i )
      a[i] = n - i;

    clock_t startTime = clock();
    //insertionSort ( a, n );
    std::qsort ( a, n, 4 , compare );
    //std::sort ( a, a + n );

    double elapsedMillis = ( clock() - startTime ) / clocksPerMillis;

    std::cout << n << '\t' << elapsedMillis << std::endl;

    if ( n == 100 )
      step = 100;
  }


  return 0;
}


