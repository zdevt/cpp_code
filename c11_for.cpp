/*
 * =====================================================================================
 *
 *       Filename:  for.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年06月19日 11时01分17秒
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
#include <vector>
#include <iostream>
#include <map>


using namespace std;

std::map<int, int> a =
{
  {1, 100},
  #if 0
  {2, 200},
  {3, 300},
  {4, 400},
  {9, 400},
  #endif
};


int arr[] =
{ 2, 1, 4, 5, 5, 6};

std::vector<int> vec = { 1, 2 };


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  auto iter2 = a.begin();

  for ( auto iter = a.begin(); iter != a.end(); )
  {
    printf ( "size=%ld ", a.size() );

    if ( iter->first == 1 )
      iter2 = a.erase ( iter++ );
    else
      ++iter;

    printf ( "size=%ld ", a.size() );
  }

  iter2 = a.begin();
  printf ( "second =%d \n", iter2->second );
  printf ( "second =%d \n", iter2->second );
  printf ( "second =%d \n", iter2->second );

  for ( auto ele : a )
  {
    printf ( "%d\n", ele.first );
  }

  #if 0

  for ( auto& ele : a )
  {
    printf ( "| %d %d | %ld\n", ele.first, ele.second, a.size() );

    if ( ele.first == 1 )
      a.erase ( ele.first );

    //a.insert ( std::pair<int, int> ( 9, 250 ) );
  }

  printf ( "\n" );
  #endif

  #if 0

  for ( auto ele : vec )
  {
    printf ( "%d\n", ele );
  }

  auto& b = a;

  for ( const auto& ele : b )
  {
    if ( ele.first == 3 )
      b.erase ( ele.first );

    printf ( "size=%ld\n", b.size() );
  }

  for ( const auto& ele : a )
  {
    printf ( "| %d %d | ", ele.first, ele.second );
  }

  printf ( "\n" );
  #endif
  #if 0

  for ( const auto& ele : a )
  {
    printf ( "| %d %d | ", ele.first, ele.second );
  }

  printf ( "\n" );

  for ( auto i : arr )
  {
    printf ( " %d ", i );
  }

  printf ( "\n" );
  #endif


  return 0;
}

