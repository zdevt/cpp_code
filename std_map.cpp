/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年03月01日 16时17分47秒
 *  Last Modified:  2018-01-13 13:38:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <map>


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  std::multimap<char, int> mymm;
  mymm.insert ( std::pair<char, int> ( 'x', 10 ) );
  mymm.insert ( std::pair<char, int> ( 'y', 20 ) );
  mymm.insert ( std::pair<char, int> ( 'z', 30 ) );
  mymm.insert ( std::pair<char, int> ( 'a', 20 ) );
  mymm.insert ( std::pair<char, int> ( 'b', 20 ) );
  mymm.insert ( std::pair<char, int> ( 'z', 33 ) );
  mymm.insert ( std::pair<char, int> ( 't', 50 ) );
  mymm.insert ( std::pair<char, int> ( 'z', 40 ) );

  auto iter = mymm.begin();

  for ( ; iter != mymm.end(); )
  {
    if ( iter->second == 20 )
      mymm.erase ( iter++ );
    else
      iter++;
  }

  for ( auto& e : mymm )
    std::cout << e.first << " " << e.second << std::endl;

  //std::multimap<char, int>::iterator it = mymm.find ( 'z' );

  //do
  //{
  //std::cout << it->first << " " << it->second << std::endl;
  //++it;
  //}
  //while ( it != mymm.end() );

  return 0;
}

