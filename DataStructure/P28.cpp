/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年03月31日 15时40分08秒
 *  Last Modified:  2016年03月31日 15时40分08秒
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
#include <iterator>
#include <ostream>
#include <iostream>
#include <string>
#include <sstream>


/* 	19 */
int NStep ( int n )
{
  if ( 0 == n )
    return 1;

  int res = 1;

  for ( int i = 1; i <= n; ++i )
    res *= i;

  return res;
}

/* 20 */
int Fn ( int n )
{
  int a[30] = { 0 };
  int res = 0;
  a[0] = 1;
  a[1] = 1;

  if ( n == 0 || n == 1 )
    a[n];

  for ( int i = 2; i <= n; ++i )
    a[i] = a[i - 1] + a[i - 2];

  return a[n];
}

/*  21 */
int F21 ( int n )
{
  if ( n % 2 )
    return F21 ( 3 * n + 1 );
  else
    return n / 2;
}

int F21_2 ( int n )
{
  if ( n % 2 )
    return ( 3 * n + 1 ) / 2;
  else
    return n / 2;
}

/*  24 */
template<typename T>
bool F24 ( T array[], int start, int end, T x )
{
  if ( ( start == end ) && ( array[start] == x ) )
    return true;
  else
    return false;

  if ( array[start] == x )
    return true;
  else
    return F24 ( array, start + 1, end, x );
}

/*  25 */
void SubSetGen ( int n, int* flag, int cnt )
{
  if ( 0 == n )
  {
    for ( int i = 0; i < cnt; ++i )
    {
      if ( flag[i] )
        std::cout << 1;
      else
        std::cout << 0;
    }

    std::cout << std::endl;
    return ;
  }

  flag[n] = 1;
  SubSetGen ( n - 1, flag, cnt );

  flag[n] = 0;
  SubSetGen ( n - 1, flag, cnt );
}

void SubSetGen2 ( char* str, int* tag, int n, int cnt )
{
  if ( n == 0 )
  {
    std::cout << "{";

    for ( int i = 0; i < cnt; ++i )
    {
      if ( tag[i] == 1 )
        std::cout << str[i];
      else
        std::cout << ' ';
    }

    std::cout << "}" << std::endl;
    return;
  }

  tag[n] = 0;
  SubSetGen2 ( str, tag, n - 1, cnt );

  tag[n] = 1;
  SubSetGen2 ( str, tag, n - 1, cnt );
}

void SubSetGen3 ( char* str, int n, int cnt )
{
  char temp = 0;

  if ( n == 0 )
  {
    std::cout << "{";

    for ( int i = 0; i < cnt; ++i )
      std::cout << str[i];

    std::cout << "}" << std::endl;
    return;
  }

  temp = str[n];
  SubSetGen3 ( str, n - 1, cnt );

  str[n] = ' ';
  SubSetGen3 ( str, n - 1, cnt );
  str[n] = temp;
}


/*  26 */
void F26 ( int n )
{
  if ( 1 == n )
  {
    std::cout << 1 << ',';
    return ;
  }

  F26 ( n - 1 );
  std::cout << n << ',';
  F26 ( n - 1 );
}

std::string F262 ( int n )
{
  std::string temp;

  if ( 1 == n )
  {
    temp = "1 ";
    return temp;
  }

  temp += F262 ( n - 1 );

  std::stringstream ss;
  ss << n;
  temp += ss.str();
  temp += " ";

  temp += F262 ( n - 1 );
}


int a[] = { 1, 3, 5, 7, 2, 4, 6, 8};
char b[] = { 'a', 'b', 'c', 'd', 'e'};

int main ( int argc, char* argv[] )
{
  //printf ( "%d\n", NStep ( 5 ) );
  //printf ( "%d\n", Fn ( 5 ) );

  //printf ( "%d %d\n", F21 ( 211 ) , F21_2 ( 211 ) );
  #if 0
  if ( F24 ( a, 0, 7, 28 ) )
    printf ( "find!\n" );
  else
    printf ( "not find!\n" );

  #endif
  //int tag[5];
  //SubSetGen2 ( b, tag, 0, 5 );
  //int tag[5];
  //SubSetGen ( 3, tag, 3 );

  //SubSetGen3 ( b, 5, 5 );
  //F26 ( 4 );
  std::cout << F262 ( 4 );

  return 0;
}

