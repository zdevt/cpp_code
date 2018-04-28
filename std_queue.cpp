/*
 * =====================================================================================
 *
 *       Filename:  Queue.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年02月23日 16时44分49秒
 *  Last Modified:  2018-03-09 08:21:14
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

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  std::queue<int> myqueue;
  int myint;

  do
  {
    std::cin >> myint;
    myqueue.push ( myint );
  }
  while ( myint );

  while ( !myqueue.empty() )
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }


  return 0;
}

