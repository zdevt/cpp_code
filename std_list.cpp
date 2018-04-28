/*
 * =====================================================================================
 *
 *       Filename:  Queue.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年02月23日 16时44分49秒
 *  Last Modified:  2018-01-03 08:42:55
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

  return 0;
}

