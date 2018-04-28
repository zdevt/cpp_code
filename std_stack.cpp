/*
 * =====================================================================================
 *
 *       Filename:  Stack.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年06月06日 15时06分25秒
 *  Last Modified:  2018-01-19 09:58:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>
#include <string>


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::stack<std::string> mystack;


  mystack.emplace ( "first" );
  mystack.emplace ( "second" );

  while ( !mystack.empty() )
  {
    std::cout << mystack.top() << std::endl;
    mystack.pop();
  }

  return 0;
}
