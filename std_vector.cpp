/*
 * =====================================================================================
 *
 *       Filename:  vec.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年04月01日 01时31分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>

typedef std::vector<char> vechar_t;

std::vector<int> Test()
{
  return { 0, 1, 3, 5, 7, 2,4,6,8 };
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  vechar_t vechar;
  //vechar.reserve ( 100 );

  //vechar.resize ( 30, 0 );
  //fprintf ( stderr, "size=%d capacity=%d\n",
  //( int ) vechar.size(), ( int ) vechar.capacity() );
  //vechar.clear();
  //fprintf ( stderr, "size=%d capacity=%d\n",
  //( int ) vechar.size(), ( int ) vechar.capacity() );

  vechar_t c { 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::remove_if ( c.begin(), c.end(), [] ( int x )
  {
    return x % 2 == 0;
  } );


  //for ( auto& e : c )
    //fprintf ( stderr, "%d ", e );

  //for( auto& e : Test())
    //std::cout<<e<<std::endl;

  std::vector< std::vector<int> > vv;
  vv.resize(10);
  for( auto& e: vv)
    std::cout<<"size="<<e.size()<<std::endl;

  //vechar.clear();

  //char buf[10];
  //char buf2[20];

  //vechar.insert ( vechar.end(), buf, buf + 10 );

  //vechar.insert ( vechar.end(), buf2, buf2 + 20 );


  //for ( int i = 0; i < vechar.size(); ++i )
  //printf ( "%02x ", vechar[i] );

  return 0;
}

