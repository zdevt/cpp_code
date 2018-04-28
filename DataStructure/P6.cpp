/*
 * =====================================================================================
 *
 *       Filename:  P6.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年03月30日 10时02分34秒
 *  Last Modified:  2016年03月30日 10时02分34秒
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
#include <algorithm>


/*  P6 -2  */
template<typename T2>
int Count ( T2& a )
{
  return ( sizeof ( a ) / sizeof ( a[0] ) ) ;
}

/*  P6-3 */
template<typename T3>
void Fill ( T3* a, int start, int end, T3 value )
{
  for ( int i = start; i < end; ++i )
    a[i] = value;
}

/*  P6-6 */
template<typename T6>
bool IsSorted ( T6& a )
{
  int cnt = Count ( a );

  if ( cnt < 3 )
    return true;

  if ( a[0] < a[cnt - 1 ] )
  {
    for ( int i = 0; i < cnt - 1; ++i )
    {
      if ( a[i] > a[i + 1] )
        return false;
    }

    return true;
  }
  else
  {
    for ( int i = 0; i < cnt - 1; ++i )
    {
      if ( a[i] < a[i + 1] )
        return false;
    }

    return true;
  }

  return false;
}

/*  使用std的临近查找算法，及lambda函数表达式 */
template<typename T62>
bool IsSorted2 ( std::vector<T62> a )
{
  int cnt = a.size();

  if ( a.front() <= a.back() )
  {
    auto iter = std::adjacent_find ( a.begin(),  a.end(),
                                     [] ( T62 lhs, T62 rhs )
    {
      return lhs > rhs;
    } );

    return  ( iter == a.end() );
  }
  else
  {
    auto iter = std::adjacent_find ( a.begin(), a.end(),
                                     [] ( T62 lhs, T62 rhs )
    {
      return lhs < rhs;
    } );

    return  ( iter == a.end() );
  }

  return false;
}


char a[] = { 1, 2, 3, 4, 5};
int b[] = { 1, 2, 7, 4, 5, 6};
int c[] = { 5, 1, 3 };

std::vector<int> d =  { 1, 1, 2, 3, 4, 5, 6, 7, 7};

int main ( int argc, char* argv[] )
{
  if ( IsSorted2 ( d ) )
    printf ( "yes\n" );
  else
    printf ( "no\n" );

  return 0;
}


