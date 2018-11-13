/*
 * =====================================================================================
 *
 *       Filename:  Queue.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年02月23日 16时44分49秒
 *  Last Modified:  2018-11-12 16:50:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <string>

/* *************list*********** */
/* back -------------front */

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  const int n = 128;
  bool Temp[n];

  for ( int i = 0; i < n; ++i )
    Temp[i] = true;

  Temp[0] = false;
  Temp[1] = false;

  for ( int i = 2; i < n; ++i )
  {
    for ( int j = i * i; j < n; j = j + i )
    {
      if ( Temp[j] )
      {
        if ( j % i == 0 )
          Temp[j] = false;
      }
    }
  }

  for ( int i = 0; i < n ; ++i )
  {
    if ( Temp[i] )
      printf ( "%d ", i );
  }

  printf ( "\n" );


  #if 0

  std::list<int> temp;

  temp.push_back ( 2 );

  //for ( int i = 0; ( 2 * i + 1 ) < 499979; ++i )
  for ( int i = 1; ( 2 * i + 1 ) < 109; ++i )
    temp.push_back ( 2 * i + 1 );

  for ( auto& e : temp )
    printf ( "%d ", e );

  printf ( "\n" );

  for ( auto iter = temp.begin();  iter != temp.end(); ++iter )
  {
    auto i = iter;
    ++i;

    for ( ; i != temp.end(); )
    {
      if ( *i % *iter == 0 )
        i = temp.erase ( i );
      else
        ++i;
    }
  }


  for ( auto& e : temp )
    printf ( "%d ", e );

  printf ( "\n" );
  #endif

  #if 0
  std::list< std::vector<char> > container;

  std::vector<char> a ( 5, 'a' );
  std::vector<char> b ( 6, 'b' );
  std::vector<char> c ( 7, 'c' );

  container.push_back ( a );
  container.push_back ( b );
  container.push_back ( c );

  a.resize ( 10, 'A' );
  container.pop_front();
  container.push_front ( a );

  while ( !container.empty() )
  {
    std::cout << "size = " << container.front().size() << std::endl;
    container.pop_front();
  }

  #endif

  return 0;
}

